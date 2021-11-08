#include "owner.h"

owner::owner::owner(std::string FirstName, std::string LastName, std::string cpf) :
    FirstName(FirstName),
    LastName(LastName),
    cpf(cpf)
{
}

owner::owner::owner()
{
    this->FirstName = "";
    this->LastName = "";
    this->cpf = "";
}

owner::owner::~owner()
{
}

std::string owner::owner::getFirstName(void) const
{
    return this->FirstName;
}

std::string owner::owner::getLastName(void) const
{
    return this->LastName;
}

std::string owner::owner::getCpf(void) const
{
    return this->cpf;
}