#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <omp.h>

class Checker: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Checker::processImg(Image &img, std::vector<std::string> &arguments)
{
    //generate a checkerboard pattern of the size of the image
    int height = img.height();
    int width = img.width();
    int checkerSize = 10;

    try{
        checkerSize = std::stoi(arguments[0]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for Checker" << std::endl;
        return false;
    }

    #pragma parallel for
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if ((x / checkerSize + y / checkerSize) % 2 == 0) {
                img(x, y, 0, 0) = 255;
                img(x, y, 0, 1) = 255;
                img(x, y, 0, 2) = 255;
            } else {
                img(x, y, 0, 0) = 0;
                img(x, y, 0, 1) = 0;
                img(x, y, 0, 2) = 0;
            }
        }
    }

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string Checker::getMainArg(){ return "checker";}

std::vector<std::string> Checker::getSubArgs(){ return {"strength"};}