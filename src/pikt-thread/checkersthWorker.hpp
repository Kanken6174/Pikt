#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <thread>

class CheckersWorker{
public:

    Image& work(Image& img, int x, int y, int pixSize);
};