#include "../pikt-core/extendables/imgProcessor.hpp"

class CImgLoader: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool CImgLoader::processImg(Image &img, std::vector<std::string> &arguments)
{
    img = Image(arguments.at(0).c_str());
    arguments.erase(arguments.begin()); //erase used argument
    return !img.is_empty();
}

std::string CImgLoader::getMainArg(){ return "load";}

std::vector<std::string> CImgLoader::getSubArgs(){ return {"path"};}