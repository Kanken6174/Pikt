#include <vector>
#include <iostream>
#include "grayscale.hpp"
#include "sepia.hpp"
#include "channelswap.hpp"
#include "channelprod.hpp"
#include "huerot.hpp"
#include "blur.hpp"


extern "C" {
    std::vector<ImgProcessor*> generateProcessors(){
        std::cout << "pikt-basics factory called" << std::endl;
        std::vector<ImgProcessor*> dv;  
        dv.push_back(new Grayscale()); //add all processors from this plugin here
        dv.push_back(new Sepia());
        dv.push_back(new ChannelSwap());
        dv.push_back(new ChannelProd());
        dv.push_back(new Huerot());
        dv.push_back(new Blur());
        return dv;
    }
}