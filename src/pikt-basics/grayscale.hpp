#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class Grayscale: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Grayscale::processImg(Image &img, std::vector<std::string> &arguments)
{
    std::cout << "Grayscaling image" << std::endl;
    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            img(i, j, 0, 0) = img(i, j, 0, 1) = img(i, j, 0, 2) = img(i, j, 0, 0) * 0.299 + img(i, j, 0, 1) * 0.587 + img(i, j, 0, 2) * 0.114;
        }
    }
    return true;
}

std::string Grayscale::getMainArg(){ return "grayscale";}

std::vector<std::string> Grayscale::getSubArgs(){ return {"path"};}