#include <iostream>
#include <cmath>
#include <cassert>
#include "util.hpp"
#include "finger.hpp"


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


    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
    Code de finger de fichier
    */

    int f = fingerprint(5407, "test1");
    if(f == ECHEC)
    {
        cerr<< "Impossible de lire le fichier"<< endl;
        return -1;
    }
    cout<< endl<< "fingerprint(5407, \"test1\"): "<< f<< endl;

    /*int f = fingerprint(17, "monfichier.txt");
    if(f == ECHEC)
    {
        cerr<< "Impossible de lire le fichier"<< endl;
        return -1;
    }
    cout<< endl<< "fingerprint(17, \"monfichier.txt\"): "<< f<< endl;*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
