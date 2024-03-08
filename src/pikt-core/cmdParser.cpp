#include "cmdParser.hpp"
#include <iostream>
#include <chrono>

CmdParser::CmdParser(std::vector<ImgProcessor *> &processors)
{
    for(auto& p : processors){
        _processors.emplace(p->getMainArg(), p);
    }
}

CmdParser::~CmdParser()
{
    for(auto& p : _processors){
        delete p.second;
    }
    _processors.clear();
}

//args should be one command per cell
void CmdParser::parse(std::vector<std::string> args)
{
    using Time = std::chrono::steady_clock;
    using ms = std::chrono::milliseconds;

    std::cout << "parsing with " << args.size() << " arguments" << std::endl;
    std::cout << "and " << _processors.size() << " processors" << std::endl;
    Image img;  //image is initially nulled, it will need to be loaded by the first plugin
    int it = 0;
    int argscount = args.size();
    while(!args.empty()){
        argscount = args.size();
        for(auto& p : _processors){
            if(p.first == args.front()){
                auto start = Time::now();
                args.erase(args.begin());  //remove the command from the list
                p.second->processImg(img,args);   //pass and "take" arguments
                std::cout << "---------------------------iteration " << it << std::endl;
                it++;
                auto end = Time::now();

                std::cout << "Time elapsed: " << std::chrono::duration_cast<ms>(end - start).count() << "ms" << std::endl;
                break;
            }
            if(args.front() == "help"){
                std::cout << "---------------------------------\n" <<"Available commands:" << std::endl;
                for(auto& p : _processors){
                    std::cout << p.first << "\n\t" << p.second->getSubArgs().size() << " Argument(s): ";
                    for(auto& s : p.second->getSubArgs()){
                        std::cout << s << " ";
                    }
                    std::cout << std::endl;
                }
                args.erase(args.begin());
                break;
            }
        }
        if(argscount == args.size()){
            std::cout << "Invalid command: '" << args.front() << "' call pikt help for available commands"<<std::endl;
            args.erase(args.begin());
        }
    }
}
