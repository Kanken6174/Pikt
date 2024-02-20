#include <vector>
#include <iostream>
#include "border.hpp"

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new Border()); //add all processors from this plugin here
        return dv;
    }
}