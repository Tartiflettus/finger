#ifndef FINGEREXCEPTION_HPP_INCLUDED
#define FINGEREXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

class fingerexception : std::exception
{
private:
    std::string m_str;

public:
    fingerexception(const std::string& str = "fingerexception");
    virtual const char * what() const noexcept;
};


#endif // FINGEREXCEPTION_HPP_INCLUDED
