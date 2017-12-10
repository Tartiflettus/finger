#ifndef DEF_UTIL_HPP
#define DEF_UTIL_HPP


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




/*
x puissance k mod p

Principe: x^n = x^(n/2) * x^(n/2)
On ne calcule ainsi (environ) que la moitié de ce qui est à calculer
*/
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


#endif // DEF_UTIL_HPP
