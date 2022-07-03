#include <iostream>
#include <cstdlib>
#include "MarketMaking.h"
#include "MarketMaking.cpp"

int main(){

    srand(time(NULL));
    MarketMaking Game;
    Game.run();
    return 0;
}