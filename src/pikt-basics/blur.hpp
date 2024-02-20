#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <omp.h>

class Blur: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Blur::processImg(Image &img, std::vector<std::string> &arguments)
{
    float c1 = 0;

    //get the first 3 args as float values
    try{
        c1 = std::stof(arguments[0]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for Blur" << std::endl;
        return false;
    }

    if(c1 < 0 || c1 > 5000){
        std::cout << "Invalid arguments for Blur" << std::endl;
        return false;
    }

    std::cout << "Blur: " << c1 << std::endl;
    
    //cimg unsigned char to float
    

    cimg_library::CImg<float> kimg = img.get_normalize(0, 1);

    //kernel (gaussian blur)

    kimg = kimg.blur(c1, true, true);

    img = kimg.get_normalize(0, 255);

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string Blur::getMainArg(){ return "blur";}

std::vector<std::string> Blur::getSubArgs(){ return {"strength"};}