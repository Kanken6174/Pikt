#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <thread>
#include <mutex>

class CheckersWorker{
protected:
    int _pixSize = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    void fill(Image& img, int x, int y);
public:
    Image& work(Image& img, int x, int y, int pixSize, std::mutex& imgMutex);
};