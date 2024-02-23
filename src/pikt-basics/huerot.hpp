#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class Huerot: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Huerot::processImg(Image &img, std::vector<std::string> &arguments)
{
    int c1 = 0;

    //get the first 3 args as float values
    try{
        c1 = std::stoi(arguments[0]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for Huerot" << std::endl;
        return false;
    }

    c1 = c1 % 360;
    if (c1 < 0)
        c1 += 360;

    std::cout << "Huerot: " << c1 << std::endl;
    
    //cimg unsigned char to float
    

    cimg_library::CImg<float> kimg = img.get_normalize(0, 1);
    kimg = kimg.RGBtoHSL();
    for (int i = 0; i < kimg.width(); i++)
    {
        for (int j = 0; j < kimg.height(); j++)
        {
            kimg(i, j, 0) = (kimg(i, j, 0) + c1);
            //std::cout << (float)kimg(i, j, 0) << " " << (float)kimg(i, j, 1) << " " << (float)kimg(i, j, 2) << std::endl;
        }
    }

    img = kimg.HSLtoRGB().get_normalize(0, 255);

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string Huerot::getMainArg(){ return "huerot";}

std::vector<std::string> Huerot::getSubArgs(){ return {"hue_angle (integer)"};}