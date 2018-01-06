#include "fingerexception.hpp"


fingerexception::fingerexception(const std::string& str)
: m_str(str)
{
}


const char * fingerexception::what() const noexcept
{
    return m_str.c_str();
}

