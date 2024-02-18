#include "cimgLoader.hpp"

class CImgSaver: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool CImgSaver::processImg(Image &img, std::vector<std::string> &arguments)
{
    img.save(arguments.at(0).c_str());
    arguments.erase(arguments.begin());
    return true;
}

std::string CImgSaver::getMainArg(){ return "save";}

std::vector<std::string> CImgSaver::getSubArgs(){ return {"path"};}