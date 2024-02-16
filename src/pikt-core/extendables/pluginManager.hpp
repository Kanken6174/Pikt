#include "plugin.hpp"
#include <map>
#include <memory>

class PluginManager{
    std::map<std::string, std::shared_ptr<Plugin>> plugins;
    public:
    PluginManager();    //will load the plugins immediately
    ~PluginManager();

    std::map<std::string, std::shared_ptr<Plugin>> getPlugins();
};