#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class ChannelSwap: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool ChannelSwap::processImg(Image &img, std::vector<std::string> &arguments)
{

    char c1 = arguments[0][0];
    char c2 = arguments[0][1];
    char c3 = arguments[0][2];

    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            img(i, j, 0, 0) = img(i, j, 0, c1 == 'r' ? 0 : c1 == 'g' ? 1 : 2);
            img(i, j, 0, 1) = img(i, j, 0, c2 == 'r' ? 0 : c2 == 'g' ? 1 : 2);
            img(i, j, 0, 2) = img(i, j, 0, c3 == 'r' ? 0 : c3 == 'g' ? 1 : 2);
        }
    }

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string ChannelSwap::getMainArg(){ return "channelswap";}

std::vector<std::string> ChannelSwap::getSubArgs(){ return {"rgb"};}