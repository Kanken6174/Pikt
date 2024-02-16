#pragma once
#include "../dependencies/cimg.h"
#include <string>
#include <vector>

class ImgProcessor{
public:
    ImgProcessor();
    virtual ~ImgProcessor();

    //this function will directly edit the input image and arguments for the next one to receive.
    virtual bool processImg(Image& img, std::string& arguments) = 0;

    //argument to call this processor
    virtual std::string getMainArg() = 0;
    //additionnal arguments that can be given to this processor after its main call
    virtual std::vector<std::string> getSubArgs() = 0;
};