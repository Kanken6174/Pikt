#include "checkersthWorker.hpp"

void CheckersWorker::fill(Image &img, int x, int y)
{
    bool even = (x / _pixSize + y / _pixSize) % 2 == 0;
    for(int i = 0; i < _pixSize; i++){
        for(int j = 0; j < _pixSize; j++){
            if(x+i > img.width() || y+j > img.height()) continue;
            img(x+i, x+j, 0, 0) = even ? 0 : r;
            img(x+i, x+j, 0, 1) = even ? 0 : g;
            img(x+i, x+j, 0, 2) = even ? 0 : b;
        }
    }
}

Image &CheckersWorker::work(Image &img, int x, int y, int pixSize, std::mutex& imgMutex)
{

    int iadd = pixSize;
    int jdd = pixSize;

    r = abs(rand() % 255);
    g = abs(rand() % 255);
    b = abs(rand() % 255);

    _pixSize = pixSize;

    if(rand() % 2 == 0){
        iadd *= -1;
    }
    
    if(rand() % 2 == 0){
        jdd *= -1;
    }
    
    for(int ttl = 1200; ttl > 0; ttl--){
        x += iadd;
        y += jdd;

        //bounce logic
        if(x + pixSize > img.width() || x < 0){
            iadd *= -1;
            x += iadd;
        }

        if(y + pixSize > img.height() || y < 0){
            jdd *= -1;
            y += jdd;
        }
        imgMutex.lock();
        fill(img, x, y);
        imgMutex.unlock();
    }
    return img;
}