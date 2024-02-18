#include "cimgLoader.hpp"
#include <iostream>

class Grayscale: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Grayscale::processImg(Image &img, std::vector<std::string> &arguments)
{
    std::cout << "Saving image to " << arguments.front() << std::endl;
    img.save(arguments.front().c_str());
    arguments.erase(arguments.begin());
    return true;
}

std::string Grayscale::getMainArg(){ return "save";}

std::vector<std::string> Grayscale::getSubArgs(){ return {"path"};}