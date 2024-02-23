#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class Sepia: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Sepia::processImg(Image &img, std::vector<std::string> &arguments)
{
    std::cout << "Sepia image" << std::endl;
    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            img(i, j, 0, 0) = img(i, j, 0, 0) * 0.393 + img(i, j, 0, 1) * 0.769 + img(i, j, 0, 2) * 0.189;
            img(i, j, 0, 1) = img(i, j, 0, 0) * 0.349 + img(i, j, 0, 1) * 0.686 + img(i, j, 0, 2) * 0.168;
            img(i, j, 0, 2) = img(i, j, 0, 0) * 0.272 + img(i, j, 0, 1) * 0.534 + img(i, j, 0, 2) * 0.131;
        }
    }
    return true;
}

std::string Sepia::getMainArg(){ return "old";}

std::vector<std::string> Sepia::getSubArgs(){ return {"none"};}