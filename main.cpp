#include <iostream>
#include <cmath>
#include "util.hpp"

using namespace std;

int main()
{
    const int x = 9, y = 118, p = 17;


    cout<< "1: "<< x<< " puissance "<< y<< " mod "<< p<< " = "<< puissance(x, y, p)<< endl;
    cout<< "2: "<< x<< " puissance "<< y<< " mod "<< p<< " = "<< int(pow(x, y))%p<< endl;

    return 0;
}
