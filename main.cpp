#include <iostream>
#include <cmath>
#include <cassert>
#include "util.hpp"
#include "finger.hpp"


using namespace std;


int main_q10()
{
    const int premier = nextprime();
    const int petitf = fingerprint(premier, "petitmonfichier.txt");
    if(petitf == ECHEC) return -1;

    if(containsfingerprints(premier, "monfichier.txt", 8, petitf)){
        std::cout<< "Le petit fichier est contenu dans le grand"<< std::endl;
    }
    else
    {
        std::cout<< "Nope"<< std::endl;
    }

    return 0;
}


/**
Q7
*/
int main_test2()
{
    constexpr int nbtests = 250;
    int nb0 = 0;
    for(int i=0; i < nbtests; i++)
    {
        const int p = nextprime();
        const int f = fingerprint(p, "test2");
        if(f == ECHEC) return -1;
        if(f == 0) nb0++;
    }

    cout<< "Ratio nombre de 0 / nombre de tests: "<< nb0 << "/"<< nbtests<< " = "<< float(nb0)/float(nbtests)<< endl;

    return 0;
}



/**
Q6
*/
int main_test3_4()
{
    constexpr int nbtests = 100;
    int nbdifferents = 0;
    for(int i=0; i < nbtests; i++)
    {
        const int p = nextprime();
        const int f1 = fingerprint(p, "test3.xpm");
        const int f2 = fingerprint(p, "test4");
        if(f1 == ECHEC || f2 == ECHEC) return -1;
        if(f1 != f2) nbdifferents++;
    }

    cout<< "Ratio différents / nombre de tests: "<< nbdifferents<< "/"<< nbtests<<
    " = "<< float(nbdifferents)/float(nbtests)<< endl;

    return 0;
}


/**
Q5
*/
int main_plusieurs_fichiers()
{
    constexpr int nbtests = 100'000;
    int nbdifferents = 0;
    for(int i=0; i < nbtests; i++)
    {
        const int p = nextprime();
        const int f1 = fingerprint(p, "monfichier.txt");
        const int f2 = fingerprint(p, "monautrefichier.txt");
        if(f1 == ECHEC || f2 == ECHEC) return -1;
        if(f1 != f2) nbdifferents++;
    }

    cout<< "Ratio différents / nombre de tests: "<< nbdifferents<< "/"<< nbtests<<
    " = "<< float(nbdifferents)/float(nbtests)<< endl;

    return 0;
}



int main_divers()
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}


int main()
{
    return main_q10();
}
