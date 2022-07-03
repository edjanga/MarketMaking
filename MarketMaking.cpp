#include "MarketMaking.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

MarketMaking::MarketMaking(){
    cout << "Welcome to this market making simulation." << endl << endl;
}
void MarketMaking::setRandomNumber(const float& rn){
    this->random_number = rn;
}
void MarketMaking::setMaxSpread(const float& spread){
    this->max_spread = spread;
}
void MarketMaking::setUpper(const int& upperbound){
    this->upper = upperbound;
}
void MarketMaking::setAmountOfRounds(const int& rounds){
    this->amount_of_rounds = rounds;
}
float MarketMaking::getRandomNumber(){
    return this->random_number;
}
int MarketMaking::getAmountOfRounds(){
    return this->amount_of_rounds;
}
float MarketMaking::getMaxSpread(){
    return this->max_spread;
}
float MarketMaking::getUpper(){
    return this->upper;
}
void MarketMaking::setGame(){
    float spread;
    unsigned int rounds;
    unsigned int upperbound;
    cout << "Enter the maximum spread allowed, the number of rounds you want the simulation to last and the upperbound for the random number." << endl;
    cin >> spread >> rounds >> upperbound;
    this->setMaxSpread(spread);
    this->setAmountOfRounds(rounds);
    this->setUpper(upperbound);
    float value = .01+static_cast<float> (rand()) / (static_cast<float> (RAND_MAX/(this->getUpper()-.01)));
    this->setRandomNumber(value);
    cout << "The game has started." << endl;
}
float MarketMaking::getBid(){
    return this->bid;
}
float MarketMaking::getAsk(){
    return this->ask;
}
void MarketMaking::setBid(const float& b){
    this->bid = b;
}
void MarketMaking::setAsk(const float& a){
    this->ask = a;
}
void MarketMaking::requestForQuote(){
    float b, a;
    cout << "Make me a market: " << endl;
    bool isValidMarket;
    do{
        cin >> b >> a;
        isValidMarket = (b<a)?true:false;
    }
    while(!isValidMarket);
    this->setBid(b);
    this->setAsk(a);
    cout << "Your bid is: " << this->getBid() << endl;
    cout << "Your ask is: " << this->getAsk() << endl;
}
bool MarketMaking::isBetween(const float& b,const float& value,const float& a){
    return ((bid<=value)&&(value<=a))?true:false;
}
float MarketMaking::getSpread(){
    return this->getAsk()-this->getBid();
}

void MarketMaking::run(){
    unsigned int attempts = 0;
    this->setGame();
    bool willingToTrade;
    bool attempts_condition;
    bool between_condition;
    bool distance_condition;
    bool spot_on_condition;
    do{
        cout << "Round " << attempts+1 << ": " << endl;
        this->requestForQuote(); 
        between_condition = isBetween(this->getBid(),this->getRandomNumber(),this->getAsk());
        distance_condition = abs(.5*this->getSpread())<=this->getMaxSpread()?true:false;
        spot_on_condition = between_condition&&distance_condition;
        if(spot_on_condition){
            cout << "You are at the right price - I will no longer trade with you." << endl;
            willingToTrade = false;
        }
        else{
            if(this->getAsk()<this->getRandomNumber()){
                cout << "I will buy." << endl;
            }
            else if(this->getBid()>this->getRandomNumber()){
                cout << "I will sell." << endl;
            }
            attempts++;
            attempts_condition = attempts<this->getAmountOfRounds()?true:false;
            willingToTrade = attempts_condition&&!spot_on_condition;
        }
    }
    while(willingToTrade);
    cout << "The random number was: " << this->getRandomNumber() << endl;
    
}
MarketMaking::~MarketMaking(){
}