#include "plugin.hpp"
#include <dlfcn.h>

Plugin::Plugin(fs::directory_entry sharedLibraryToLoad){
    libHandle = dlopen(sharedLibraryToLoad.path().string().c_str(), RTLD_LAZY);
    if(!libHandle) return;

    typedef std::vector<ImgProcessor*> (*GenerateProcessors)();

    loadProcessors = (GenerateProcessors)dlsym(libHandle, "generateProcessors");
}

Plugin::~Plugin(){
    dlclose(libHandle);
}