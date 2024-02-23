#include "checkersthWorker.hpp"

Image& CheckersWorker::work(Image &img, int x, int y, int pixSize)
{
    bool even = (x / pixSize + y / pixSize) % 2 == 0;
    for(int i = 0; i < pixSize; i++){
        for(int j = 0; j < pixSize; j++){
            if(x+i > img.width() || y+j > img.height()) continue;
            img(x+i, x+j, 0, 0) = even ? 0 : 255;
        }
    }
    return img;
}