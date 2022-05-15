#include "authenticable.h"

authenticable::authenticable(std::string password):password(password)
{
}

authenticable::~authenticable()
{
}

bool authenticable::authentic(std::string checkPass) const
{
    return checkPass == this->password;
}