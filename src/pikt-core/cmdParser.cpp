#include "cmdParser.hpp"

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
    Image img;  //image is initially voided, it will need to be loaded by the first plugin
    for(auto& p : _processors){
        if(p.first == args.at(0)){
            p.second->processImg(img,args.at(0));   //pass and "take" arguments
            args.erase(args.begin());
        }
    }
}
