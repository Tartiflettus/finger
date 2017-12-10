#include <iostream>
#include <cmath>
#include "util.hpp"

using namespace std;

int main()
{
    const int x = 9, y = 118;
    int p = 17;


    cout<< "1: "<< x<< " puissance "<< y<< " mod "<< p<< " = "<< puissance(x, y, p)<< endl;
    cout<< "2: "<< x<< " puissance "<< y<< " mod "<< p<< " = "<< int(pow(x, y))%p<< endl;


    cout<< endl;
    cout<< "1 : "<< p<< (pseudoprime(p) ? " est pseudo-premier" : " n'est pas pseudo-premier")<< endl;
    p = 2;
    cout<< "1 : "<< p<< (pseudoprime(p) ? " est pseudo-premier" : " n'est pas pseudo-premier")<< endl;


    for(int i=0; i < 5; ++i)
    {
        cout<< "nextprime: ";
        p = nextprime();
        cout<< p<< " ; pseudo-premier ? "<< pseudoprime(p)<< endl;
    }

    return 0;
}
