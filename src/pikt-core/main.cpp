#include <iostream>
#include "./extendables/pluginManager.hpp"
#include "cmdParser.hpp"
int main(int argc, char* argv[]) {
    
    PluginManager p;
    std::map<std::string, std::shared_ptr<Plugin>> plugins = p.getPlugins();
    std::vector<ImgProcessor*> processors;
    std::cout << "loading processors..." << std::endl;
    for(auto& pl : plugins){
        processors = pl.second.get()->loadProcessors();
    }
    std::cout << "processor loading done" << std::endl;
    CmdParser parser(processors);

    std::vector<std::string> all_args;

    if (argc > 1) {
        all_args.assign(argv + 1, argv + argc);
        parser.parse(all_args);
    }

    return 0;
}