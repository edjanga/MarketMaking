#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){

    cout << "=======================================================================================================================" << endl;
    cout << "====================================== Welcome to the market making interface. ========================================" << endl;
    cout << "=======================================================================================================================" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "You will have five attempts to make a market on a randomly chosen number." << endl;
    int upperbound;
    int spread;
    cout << "Please enter an upper bound: " << endl;
    cin >> upperbound;
    cout << "Please enter the maximum size of the spread: " << endl;
    cin >> spread;
    cout << "You have chosen " << upperbound << " as upper bound." << endl;
    srand(time(NULL));
    int fair_value = rand()%upperbound;
    int count,bid,ask = 0;
    do {
        cout << "Make a market for the random number" << endl;
        cout << "Enter a bid: " << endl;
        cin >> bid;
        cout << "Enter an ask: " << endl;
        cin >> ask;
        cout << "Your current market is : " << endl;
        int col_width = 20;
        cout << left;
        cout << setfill('-');
        cout << setw(col_width) << "Bid " << " Ask" << endl;
        col_width = 18;
        cout << setw(col_width) << "  " << bid << ask << endl;
        if(bid>fair_value){
            cout << "I will sell." << endl;
            cout << "Make me another market." << endl;
        }
        else if(ask<fair_value)
        {
            cout << "I will buy." << endl;
            cout << "Make me another market." << endl;
        }
        else if((abs(ask-fair_value)<=spread)&&(abs(bid-fair_value)<=spread)){
            cout << "I will not trade with you." << endl;
            break;
        }
        count += 1;   
    }
    while(((abs(ask-fair_value)>spread)&&(abs(bid-fair_value)>spread))||(count<5));
    cout << "Fair value was " << fair_value << endl;
    return 0;
}