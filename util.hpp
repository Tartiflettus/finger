#ifndef DEF_UTIL_HPP
#define DEF_UTIL_HPP


/*
(x * y) mod p
*/
int multiply(int x, int y, int p);



/*
x puissance k mod p

Principe: x^n = x^(n/2) * x^(n/2)
On ne calcule ainsi (environ) que la moitié de ce qui est à calculer
*/
int puissance(int x, int k, int p);



/*
Indique si p est pseudo premier (2^(p-1)mod p =1)
*/
bool pseudoprime(int p);


/*
Renvoie un nombre entier entre 2 et 2^23 - 1
*/
int nextprime();



#endif // DEF_UTIL_HPP
