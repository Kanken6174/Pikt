#pragma once
#include "checkersthWorker.hpp"

class CheckerTh: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool CheckerTh::processImg(Image &img, std::vector<std::string> &arguments)
{
    //generate a checkerthboard pattern of the size of the image
    int height = img.height();
    int width = img.width();
    int checkerthSize = 10;

    try{
        checkerthSize = std::stoi(arguments[0]);
    }catch(std::exception e){
        std::cout << "Invalid arguments for CheckerTh" << std::endl;
        return false;
    }

    std::vector<std::thread> workers;

    for(int i = 0; i < 40; i++){
        workers.push_back(std::thread([i, &img, checkerthSize, width, height](){
            CheckersWorker worker;
            for(int x = i % 2 * checkerthSize; x < width; x += 2 * checkerthSize){
                for(int y = i / 2 * checkerthSize; y < height; y += 2 * checkerthSize){
                    worker.work(img, x, y, checkerthSize);
                }
            }
        }));
    }

    for(auto& worker: workers){
        worker.join();
    }

    arguments.erase(arguments.begin(), arguments.begin() + 1);

    return true;
}

std::string CheckerTh::getMainArg(){ return "checkerth";}

std::vector<std::string> CheckerTh::getSubArgs(){ return {"checkerth_size (integer)"};}