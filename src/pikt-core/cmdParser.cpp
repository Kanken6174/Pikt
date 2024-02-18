#include "cmdParser.hpp"
#include <iostream>

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
    std::cout << "parsing with " << args.size() << " arguments" << std::endl;
    std::cout << "and " << _processors.size() << " processors" << std::endl;
    Image img;  //image is initially nulled, it will need to be loaded by the first plugin
    int it = 0;
    while(!args.empty()){
        for(auto& p : _processors){
            if(p.first == args.front()){
                args.erase(args.begin());  //remove the command from the list
                p.second->processImg(img,args);   //pass and "take" arguments
                std::cout << "---------------------------iteration " << it << std::endl;
                it++;
                break;
            }
        }
    }
}
