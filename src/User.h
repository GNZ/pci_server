
#ifndef USER_H_
#define USER_H_

// Includes
#include "Date.h"
#include "Datetime.h"
#include <string>

class User {

public:
	Date *birth_date;
	std::string email;
	std::string first_name;
	std::string genre;
	std::string last_name;
	std::string location;
	Datetime *sign_up_datetime;
	std::string user_name;
	User();
	virtual ~User();
};

#endif /* USER_H_ */
