#pragma once
#include <random>
#include <ctime>

class Rand{
    std::mt19937 _mt;
    std::uniform_int_distribution<int> _dist;

public:

    void init(int low, int high){
        _mt.seed(time(NULL));
        _dist = std::uniform_int_distribution<int>(low, high);
    }

    int get(){
        return _dist(_mt);
    }
};

class Rand255{
    static std::mt19937 _mt;
    static std::uniform_int_distribution<int> _dist;

public:
    static void init(){
        _mt.seed(time(NULL));
        _dist = std::uniform_int_distribution<int>(0, 255);
    }

    static int get(){
        return _dist(_mt);
    }
};


std::mt19937 Rand255::_mt = std::mt19937();
std::uniform_int_distribution<int> Rand255::_dist = std::uniform_int_distribution<int>(0, 255);
