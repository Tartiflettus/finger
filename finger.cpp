#include "finger.hpp"
#include "util.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>


int fingerprint(int p, const std::string& fn)
{
    std::ifstream file;
    file.open(fn, std::ios::binary);
    if(!file.is_open()) return ECHEC;

    file.seekg(0, file.end);
    const int taille = file.tellg();
    file.seekg(0, file.beg);

    std::vector<char> buffer;
    buffer.reserve(taille);
    while(true)
    {
        const char c = file.get();
        if(file.eof()) break; //quitter la boucle si on a fini de lire le fichier
        buffer.push_back(c);
    }

    int somme = 0;
    int puismodp = 1;
    for(int i = buffer.size()-1; i >= 0; i--)
    {
        //const char c = buffer[i];
        int byte = *((unsigned char*)(void*)&buffer[i]);
        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
    }

    file.close();
    return somme;
}


/*int fingerprint(int p, const std::string& fn)
{
    std::ifstream file;
    file.open(fn, std::ios::binary);
    if(!file.is_open())
    {
        return ECHEC;
    }
    file.seekg(-1, file.end); //lire depuis la fin
    if(!file.good()) return ECHEC;


    int somme = 0;
    int puismodp = 1; //puissance de 256 jusque n, le nombre d'octets du fichier
    int byte;
    while(file.tellg() >= 0) //lire tout le fichier
    {
        char c = file.get();
        byte = *((unsigned char*)(void*)&c);
        if(file.bad())
        {
            return ECHEC;
        }
        //std::cout<< buffer;

        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
        file.seekg(-2, file.cur); //reculer de 2
    }


    file.close();

    return somme;
}*/
