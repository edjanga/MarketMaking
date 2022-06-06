#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>

using namespace std;

int main(){

    cout << "======================================================================" << endl;
    cout << "=========== Welcome to the market making interface. ==================" << endl;
    cout << "======================================================================" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    int fixed_seed;
    int upperbound;
    cout << "Please enter a seed: " << endl;
    cin >> fixed_seed;
    cout << "Please enter an upper bound: " << endl;
    cin >> upperbound;
    cout << "You have chosen " << fixed_seed << " as seed and " << upperbound << " as upper bound." << endl;
    return 0;
}