#include "owner.h"

owner::owner::owner(std::string FirstName, std::string LastName, std::string cpf, std::string password) :
    person::person(
        FirstName,
        LastName,
        cpf
    ),
    authenticable(password)
{
}

owner::owner::~owner()
{
}
