#include "cimgSaver.hpp"
#include <vector>
#include <iostream>

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-io factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new CImgLoader()); //add all processors from this plugin here
        dv.push_back(new CImgSaver());
        return dv;
    }
}