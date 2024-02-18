#include "grayscale.hpp"
#include <vector>
#include <iostream>

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new Grayscale()); //add all processors from this plugin here
        return dv;
    }
}