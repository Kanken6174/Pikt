#include <iostream>
#include "./extendables/pluginManager.hpp"

int main(char* argv[], int argc) {
    
    PluginManager p;
    std::map<std::string, std::shared_ptr<Plugin>> plugins = p.getPlugins();
    std::vector<ImgProcessor*> processors;
    for(auto& pl : plugins){
        processors = pl.second.get()->loadProcessors();
    }
    
    return 0;
}