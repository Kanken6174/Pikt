#include "pluginManager.hpp"
#include <iostream>
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

PluginManager::PluginManager(){

    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        throw std::runtime_error("unable to get the app's absolute path");
    }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; 

    // Path to the folder
    fs::path folder_path = (std::string(cCurrentPath)+std::string("/plugins")).c_str();

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
        std::cout << "loaded " << plugins.size() << " plugins" << std::endl;
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
