#include <vector>
#include <iostream>
#include "border.hpp"
#include "checkers.hpp"
#include "pix.hpp"

extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new Border()); //add all processors from this plugin here
        dv.push_back(new Checker());
        dv.push_back(new Pix());
        return dv;
    }
}