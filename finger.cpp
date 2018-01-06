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
    std::reverse(bytes.begin(), bytes.end());
}


int fingerprint(int p, const std::vector<char>& bytes)
{
    int somme = 0;
    int puismodp = 1;
    for(unsigned i = 0; i < bytes.size(); i++)
    {
        int byte = chartounsigned(bytes[i]); //assimiler byte comme la représentation non signée de byte[i]
        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
    }

    return somme;
}



int fingerprint(int p, const std::vector<char>& F, int k)
{
    if(unsigned(k) > F.size()) throw fingerexception();

    int somme = 0;
    int puismodp = 1;
    for(int i=0; i < k; i++)
    {
        int byte = chartounsigned(F[i]); //assimiler byte comme la représentation non signée de byte[i]
        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
    }
    return somme;
}



int fingerprintpos(int p, const std::vector<char>& F, int k, int pos)
{
    if(unsigned(pos+k) > F.size()) throw fingerexception();

    int somme = 0;
    int puismodp = 1;
    for(int i=pos; i < pos+k; i++)
    {
        int byte = chartounsigned(F[i]); //assimiler byte comme la représentation non signée de byte[i]
        byte = ((byte % p) * puismodp) % p;
        somme = (somme + byte) % p; // somme et buffer sont déjà en modulo p
        puismodp = (puismodp << 8) % p; // * 256^n mod p
    }
    return somme;
}




bool containsfingerprints(int p, const std::vector<char>& F, int k, int other_fingerprint)
{
    const int puis256k = puissance(256, k-1, p);
    int finger = fingerprint(p, F, k);
    if(finger == other_fingerprint) return true;

    for(unsigned i=0; i < F.size()-k; i++)
    {
        const int byte = chartounsigned(F[i]); //assimiler byte comme la représentation non signée de byte[i]
        finger  = ( pmod(finger - (byte%p), p) / (256%p) ) % p;
        const int byte_end = chartounsigned(F[i+k]);
        finger = ( finger + ( ((byte_end%p) * puis256k)%p ) ) % p;

        //std::cout<< "finger : "<< finger<< "\nother: "<< other_fingerprint<< std::endl;

        if(finger == other_fingerprint) return true;
    }

    return false;

    /*for(unsigned i = 0; i < F.size()-k; i++)
    {
        const int finger = fingerprintpos(p, F, k, i);
        if(finger == other_fingerprint) return true;
    }
    return false;*/
}


bool containsfingerprints(int p, const std::string& fichier, int k, int other_fingerprint)
{
    std::ifstream f(fichier, std::ios::binary);
    if(!f.is_open())
        return false;

    std::vector<char> bytes;
    loadBytes(f, bytes); //lire le fichier pour la première fois

    return containsfingerprints(p, bytes, k, other_fingerprint);
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
    if(!file.is_open()) throw fingerexception();
    std::vector<char> bytes;
    loadBytes(file, bytes); //lire le fichier pour la première fois

    const int somme = fingerprint(p, bytes);
    filemap[fn] = bytes; //enregistrer le contenu du fichier dans la table

    return somme;
}


