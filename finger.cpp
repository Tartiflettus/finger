#include "finger.hpp"
#include "util.hpp"
#include <fstream>


//TODO
int fingerprint(int p, const std::string& fn)
{
    std::ifstream file;
    file.open(fn, std::ios::binary);
    if(!file.is_open())
    {
        return ECHEC;
    }


    int somme = 0;
    int puismodp = 1; //puissance de 256 jusque n, le nombre d'octets du fichier
    unsigned char buffer;
    while(file.good()) //lire tout le fichier
    {
        file.read((char*)(&buffer), 1);
        buffer = ((buffer % p) * puismodp) % p;
        somme = (somme + buffer) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; //* 256^n mod p
    }


    file.close();

    return somme;
}
