#ifndef INCLUDE_PERSON_H
#define INCLUDE_PERSON_H

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------*/
// Class Declaration
/*-------------------------------------------------------------------------------*/
class person{
    
    private:
        std::string FirstName;
        std::string LastName;
        std::string cpf;

    public:
        person(
            std::string FirstName,
            std::string LastName,
            std::string cpf
        );
        ~person();
        std::string getFistName( void );
        std::string getLastName( void );
        std::string getCpf( void );
};

#endif // INCLUDE_PERSON_H