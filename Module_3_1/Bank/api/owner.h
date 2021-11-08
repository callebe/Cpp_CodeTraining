#pragma once

/*-------------------------------------------------------------------------------*/
// Includes
/*-------------------------------------------------------------------------------*/
#include <string>
#include <iostream>

/*-------------------------------------------------------------------------------*/
// Defines
/*-------------------------------------------------------------------------------*/


namespace owner
{
	/*-------------------------------------------------------------------------------*/
	// Class Declaration
	/*-------------------------------------------------------------------------------*/
	class owner {

		private:
			std::string FirstName;
			std::string LastName;
			std::string cpf;

		public:
			owner(
				std::string inputFirstName,
				std::string inputLastName,
				std::string inputCpf
			);
			owner();
			~owner();
			std::string getFirstName(void) const;
			std::string getLastName(void) const;
			std::string getCpf(void) const;
	};


	/*-------------------------------------------------------------------------------*/
	// Function Declaration
	/*-------------------------------------------------------------------------------*/


}