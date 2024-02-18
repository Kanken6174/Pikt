#include "plugin.hpp"
#include <dlfcn.h>
#include <exception>

typedef std::vector<ImgProcessor*> (*GenerateProcessors)();

Plugin::Plugin(fs::directory_entry sharedLibraryToLoad){
    libHandle = dlopen(sharedLibraryToLoad.path().string().c_str(), RTLD_LAZY);
    if(!libHandle) throw std::runtime_error(std::string(dlerror()) + std::string(" \nCould not open .so library at path: ")+std::string(sharedLibraryToLoad.path()));

    loadProcessors = (GenerateProcessors)dlsym(libHandle, "generateProcessors");

    if(loadProcessors == NULL)
        throw std::invalid_argument((std::string("loadProcessor function could not be loaded from plugin: ")+sharedLibraryToLoad.path().string()).c_str());
}

Plugin::~Plugin(){
    dlclose(libHandle);
}