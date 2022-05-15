#include "manager.h"

manager::manager(
    std::string inputFirstName,
    std::string inputLastName,
    std::string inputCpf,
    std::string password
):
    person(
        inputFirstName,
        inputLastName,
        inputCpf
    ),
    authenticable(password)
{
};

manager::~manager()
{
};