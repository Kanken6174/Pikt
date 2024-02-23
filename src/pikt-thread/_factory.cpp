#include <vector>
#include <iostream>
#include "checkersth.hpp"

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new CheckerTh()); //add all processors from this plugin here
        return dv;
    }
}