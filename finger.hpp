#ifndef FINGER_HPP_INCLUDED
#define FINGER_HPP_INCLUDED

#include <string>
#include <vector>

constexpr int ECHEC = -1;

/*
Renvoie le fingerprint de fn, ou ECHEC si échec
*/
int fingerprint(int p, const std::string& fn);


/**
Renvoie le fingerprint du sous ensemble de taille k de F, ou ECHEC si échec,
*/
int fingerprint(int p, const std::vector<char>& F, int k);


/**
Indique si other_fingerprint est contenu dans F
*/
bool containsfingerprints(int p, const std::vector<char>& F, int k, int other_fingerprint);

/**
Indique si other_fingerprint est contenu dans F
*/
bool containsfingerprints(int p, const std::string& fichier, int k, int other_fingerprint);


/*
Renvoie le fingerprint de bytes, un fichier déjà lu, ou ECHEC si échec
*/
int fingerprint(int p, const std::vector<char>& bytes);


#endif // FINGER_HPP_INCLUDED
