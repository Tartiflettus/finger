#ifndef FINGER_HPP_INCLUDED
#define FINGER_HPP_INCLUDED

#include <string>

constexpr int ECHEC = -1;

/*
Renvoie le fingerprint de fn, ou ECHEC si échec
*/
int fingerprint(int p, const std::string& fn);


#endif // FINGER_HPP_INCLUDED
