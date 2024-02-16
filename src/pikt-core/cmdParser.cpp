#include "cmdParser.hpp"

CmdParser::CmdParser(std::vector<ImgProcessor *> &processors)
{
    for(auto& p : processors){
        _processors.emplace(p->getMainArg(), p);
    }
}