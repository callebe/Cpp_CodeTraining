#ifndef INCLUDE_AUTHENTICABLE_H
#define INCLUDE_AUTHENTICABLE_H

#include <string>

class authenticable
{
    private:
        std::string password;

    public:
        authenticable(std::string password);
        ~authenticable();
        bool authentic (std::string checkPass) const;
};

#endif // INCLUDE_AUTHENTICABLE_H