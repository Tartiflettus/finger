#include "util.hpp"
#include <random>
#include <functional> //bind
#include <chrono> //clock for random seed



int multiply(int x, int y, int p)
{
    int result = 0;
    while(y)
    {
    if(y & 1) result = (result + x) % p;
    y >>= 1;
    x = (2*x)%p;
    }
    return result;
}


int puissance(int x, int k, int p)
{
    if(k == 0)
    {
        return 1;
    }
    if(k == 1)
    {
        return x;
    }
    // diviser le problème en 2 sous problèmes égaux
    const int moitieK = k/2; // une seule opération DIV de x86 ? :D
    const int reste = k%2;
    const int moitieRes = puissance(x, moitieK, p);

    //ne pas oublier l'éventuelle mutliplication supplémentaire si k n'est pas divisible par 2
    return (multiply(moitieRes, moitieRes, p) * (reste == 1 ? x%p : 1))%p;
}



bool pseudoprime(int p)
{
    return puissance(2, p-1, p) == 1;
}



int nextprime()
{
    static std::default_random_engine generateur(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> distribution(2, (1<<23) - 1);

    static auto lancer = std::bind ( distribution, generateur );

    int res;
    while(!pseudoprime(res = lancer())) ;

    return res;
}



int buffer32toint(const char buffer[4])
{
    const void* ptrvoid = static_cast<const void*>(buffer);
    const uint32_t* ptrunint32 = static_cast<const uint32_t*>(ptrvoid);
    return *ptrunint32;
}


