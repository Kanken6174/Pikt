#include <iostream>
#include "./extendables/pluginManager.hpp"
#include "cmdParser.hpp"
int main(char* argv[], int argc) {
    
    PluginManager p;
    std::map<std::string, std::shared_ptr<Plugin>> plugins = p.getPlugins();
    std::vector<ImgProcessor*> processors;
    for(auto& pl : plugins){
        processors = pl.second.get()->loadProcessors();
    }
    CmdParser parser(processors);

    std::vector<std::string> all_args;

    if (argc > 1) {
        all_args.assign(argv + 1, argv + argc);
    }

    return 0;
}