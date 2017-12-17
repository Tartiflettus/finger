#ifndef FINGER_HPP_INCLUDED
#define FINGER_HPP_INCLUDED

#include <string>
#include <vector>

constexpr int ECHEC = -1;

/*
Renvoie le fingerprint de fn, ou ECHEC si échec
*/
int fingerprint(int p, const std::string& fn);

/*
Renvoie le fingerprint de bytes, un fichier déjà lu, ou ECHEC si échec
*/
int fingerprint(int p, const std::vector<char>& bytes);


#endif // FINGER_HPP_INCLUDED
