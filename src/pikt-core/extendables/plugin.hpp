#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "imgProcessor.hpp"
namespace fs = std::filesystem;

class Plugin{
    protected:
        fs::directory_entry pluginFile;
        void* libHandle;
    public:

        Plugin(fs::directory_entry sharedLibraryToLoad);
        ~Plugin();
        std::function<std::vector<ImgProcessor*>()> loadProcessors = NULL;
};