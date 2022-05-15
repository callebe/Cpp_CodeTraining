#include "person.h"


person::person::person(std::string FirstName, std::string LastName, std::string cpf):
    FirstName(FirstName),
    LastName(LastName),
    cpf(cpf)
{
    
}

person::person::~person(){

}

std::string person::person::getFistName(void) 
{
    return this->FirstName;
}

std::string person::person::getLastName(void) 
{
    return this->LastName;
}

std::string person::person::getCpf(void) 
{
    return this->cpf;
}
