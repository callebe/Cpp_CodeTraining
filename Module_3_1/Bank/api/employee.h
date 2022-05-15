#ifndef INCLUDE_EMPLOYEE_H
#define INCLUDE_EMPLOYEE_H

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include <iostream>
#include "person.h"

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/


namespace employee
{
	/*-------------------------------------------------------------------------------*/
	// Class Declaration
	/*-------------------------------------------------------------------------------*/
    class employee: public person::person
    {
        
        private:
            float wage;

        public:
            employee(
                std::string FirstName,
                std::string LastName,
                std::string cpf,
                float wage
            );
            ~employee();
    };
    
}

#endif //INCLUDE_EMPLOYEE_H