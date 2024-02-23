#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class ChannelProd: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool ChannelProd::processImg(Image &img, std::vector<std::string> &arguments)
{
    float c1 = 0.0f;
    float c2 = 0.0f;
    float c3 = 0.0f;

    //get the first 3 args as float values
    try{
        c1 = std::stof(arguments[0]);
        c2 = std::stof(arguments[1]);
        c3 = std::stof(arguments[2]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for channelprod" << std::endl;
        return false;
    }

    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            img(i, j, 0, 0) = img(i, j, 0, 0) * c1;
            img(i, j, 0, 1) = img(i, j, 0, 1) * c2;
            img(i, j, 0, 2) = img(i, j, 0, 2) * c3;
        }
    }

    arguments.erase(arguments.begin(), arguments.begin() + 3);

    return true;
}

std::string ChannelProd::getMainArg(){ return "channels";}

std::vector<std::string> ChannelProd::getSubArgs(){ return {"red_factor", "green_factor" , "blue_factor"};}