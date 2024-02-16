#include "./extendables/pluginManager.hpp"

class CmdParser{
protected:
    std::map<std::string,ImgProcessor*> _processors;
public:
    CmdParser(std::vector<ImgProcessor*> &processors);
    ~CmdParser();

    void parse(std::vector<std::string> args);
};