#include "employee.h"

employee::employee::employee(std::string FirstName, std::string LastName, std::string cpf, float wage) :
    person::person(
        FirstName,
        LastName,
        cpf
    ),
    wage(wage)
{
}

employee::employee::~employee()
{
}