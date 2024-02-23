#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <omp.h>

class Border: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool Border::processImg(Image &img, std::vector<std::string> &arguments)
{
    
    //cimg unsigned char to float
    

    cimg_library::CImg<float> kimg = img;//.get_normalize(0, 1);
    cimg_library::CImg<float> zimg = img;//.get_normalize(0, 1);

    //kernel (gaussian Border)
    float kernel1[3][3] = {{-1.0f,-1.0f,-1.0f,},{0.0f,0.0f,0.0f},{1.0f,1.0f,1.0f}};
    float kernel2[3][3] = {{-1.0f,0.0f,1.0f},{-1.0f,0.0f,1.0f},{-1.0f,0.0f,1.0f}};

    //convolution (3 color channels, output to another color image)

    #pragma omp parallel for
    for (int c = 0; c < img.spectrum(); c++) {
        for (int x = 1; x < img.width() - 1; x++) {
            for (int y = 1; y < img.height() - 1; y++) {
                float sum1 = 0;
                float sum2 = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        sum1 += kernel1[i + 1][j + 1] * img(x + i, y + j, 0, c);
                        sum2 += kernel2[i + 1][j + 1] * img(x + i, y + j, 0, c);
                    }
                }
                sum1 = std::min(std::max(sum1, 0.0f), 255.0f);
                sum2 = std::min(std::max(sum2, 0.0f), 255.0f);
                kimg(x, y, 0, c) = sum1;
                zimg(x, y, 0, c) = sum2;
            }
        }
    }

    img = kimg + zimg;

    return true;
}

std::string Border::getMainArg(){ return "border";}

std::vector<std::string> Border::getSubArgs(){ return {"none"};}