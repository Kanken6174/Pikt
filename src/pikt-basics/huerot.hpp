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

    img = img.RGBtoHSL();
    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            img(i, j, 0, 0) = img(i, j, 0, 0) + c1;
        }
    }

    img = img.HSLtoRGB();

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string Huerot::getMainArg(){ return "huerot";}

std::vector<std::string> Huerot::getSubArgs(){ return {"ch1 *", "ch2 *" , "ch3 *"};}