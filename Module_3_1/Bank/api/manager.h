#ifndef INCLUDE_MANAGER_H
#define INCLUDE_MANAGER_H

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include "person.h"
#include "authenticable.h"

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------*/
// Class Declaration
/*-------------------------------------------------------------------------------*/
class manager : public person, public authenticable
{
    private:
    
    public:
        manager(
            std::string inputFirstName,
            std::string inputLastName,
            std::string inputCpf,
            std::string password
        );
        ~manager();
};

#endif // INCLUDE_MANAGER_H