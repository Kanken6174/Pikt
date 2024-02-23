#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <omp.h>

class Pix: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Pix::processImg(Image &img, std::vector<std::string> &arguments)
{
    //pixellize the image
    int pixSize = 10;

    try{
        pixSize = std::stoi(arguments[0]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for Pix" << std::endl;
        return false;
    }

    //take one pixel in a square of size and fill the square with that color
    #pragma omp parallel for
    for(int i = 0; i < img.width(); i+=pixSize){
        for(int j = 0; j < img.height(); j+=pixSize){
            if(i >= img.width() || j >= img.height()) continue;
            int r = 0, g = 0, b = 0;
            r = img(i, j, 0, 0);
            g = img(i, j, 0, 1);
            b = img(i, j, 0, 2);

            for(int k = 0; k < pixSize; k++){
                for(int l = 0; l < pixSize; l++){
                    if(i+k >= img.width() || j+l >= img.height() || i+k < 0 || j+l < 0) continue;
                    img(i+k, j+l, 0, 0) = r;
                    img(i+k, j+l, 0, 1) = g;
                    img(i+k, j+l, 0, 2) = b;
                }
            }
        }
    }


    
    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string Pix::getMainArg(){ return "pix";}

std::vector<std::string> Pix::getSubArgs(){ return {"strength"};}