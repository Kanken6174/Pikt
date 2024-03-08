#include <vector>
#include <iostream>
#include "glout.hpp"
#include "gloutGP.hpp"

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new GlOut()); //add all processors from this plugin here
        dv.push_back(new GlOutGP());
        return dv;
    }
}