#include "finger.hpp"
#include "util.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>


void loadBytes(std::ifstream& file, std::vector<char>& bytes)
{
    file.seekg(0, file.end);
    const int taille = file.tellg();
    file.seekg(0, file.beg);

    bytes.reserve(taille);
    while(true)
    {
        const char c = file.get();
        if(file.eof()) break; //quitter la boucle si on a fini de lire le fichier
        bytes.push_back(c);
    }
}


int fingerprint(int p, const std::vector<char>& bytes)
{
    int somme = 0;
    int puismodp = 1;
    for(int i = bytes.size()-1; i >= 0; i--)
    {
        //const char c = bytes[i];
        int byte = *((unsigned char*)(void*)&bytes[i]); //assimiler byte comme la représentation non signée de byte[i]
        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
    }

    return somme;
}


int fingerprint(int p, const std::string& fn)
{
    //maintenir une table des fichiers lus
    static std::map<std::string, std::vector<char>> filemap;
    if(filemap.count(fn) > 0)
    {
        return fingerprint(p, filemap.at(fn)); //ne pas relire le fichier
    }

    std::ifstream file(fn, std::ios::binary);
    if(!file.is_open()) return ECHEC;
    std::vector<char> bytes;
    loadBytes(file, bytes); //lire le fichier pour la première fois

    const int somme = fingerprint(p, bytes);
    if(somme != ECHEC) filemap[fn] = bytes; //enregistrer le contenu du fichier dans la table

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
