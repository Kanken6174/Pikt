#include "pluginManager.hpp"
#include <iostream>

PluginManager::PluginManager(){
    // Path to the folder
    fs::path folder_path = "./plugins";

    // Check if the folder exists
    if (fs::exists(folder_path) && fs::is_directory(folder_path)) {
        std::cout << "Folder exists\n";

        // Iterate over the files in the folder
        for (const auto& file : fs::directory_iterator(folder_path)) {
            // Check if the file is a regular file and a dynamic shared object file
            if (fs::is_regular_file(file.path()) && file.path().filename().string().substr(file.path().filename().string().size() - 3) == ".so") {
                std::cout << "Found a valid plugin at: " << file.path() << std::endl;
                std::shared_ptr<Plugin> pl = std::make_shared<Plugin>(file);
                plugins.emplace(file.path().filename(),pl);
            }
        }
        std::cout <<"finished importing plugins" << std::endl;
    }
    else {
        std::cout << "Folder does not exist\n";
    }
}

PluginManager::~PluginManager()
{
    plugins.clear();
}

std::map<std::string, std::shared_ptr<Plugin>> PluginManager::getPlugins()
{
    return plugins;
}
