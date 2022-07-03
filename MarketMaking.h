#ifndef MARKETMAKING_H
#define MARKETMAKING_H

#pragma once

class MarketMaking
{
    public:

        MarketMaking();
        ~MarketMaking();
        float getRandomNumber();
        float getMaxSpread();
        int getAmountOfRounds();
        float getUpper();
        float getBid();
        float getAsk();
        float getSpread();
        bool isBetween(const float& b,const float& value,const float& a);
        void setRandomNumber(const float& rn);
        void setMaxSpread(const float& spread);
        void setAmountOfRounds(const int& rounds);
        void setUpper(const int& upperbound);
        void setGame();
        void setBid(const float& b);
        void setAsk(const float& a);
        void requestForQuote();
        void run();

    private:

        float max_spread;
        float bid;
        float ask;
        unsigned int amount_of_rounds;
        unsigned int upper;
        float random_number;

};

#endif