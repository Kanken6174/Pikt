#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>

class CImgLoader: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool CImgLoader::processImg(Image &img, std::vector<std::string> &arguments)
{
    std::cout << "Loading image from " << arguments.front() << std::endl;
    img = Image(arguments.at(0).c_str());
    arguments.erase(arguments.begin());
    return !img.is_empty();
}

std::string CImgLoader::getMainArg(){ return "load";}

std::vector<std::string> CImgLoader::getSubArgs(){ return {"path"};}