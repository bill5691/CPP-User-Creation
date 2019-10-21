//Name       :   Bill Skiles
//Source File:   User_Creation.cpp
//Description:   This program accepts user input for their first and last name, creating a username. The user then inputs a password until it meets
//               validation requirements. The program creates a login string using the username and password, then stores the data in a vector object.
//Date       :   May 2, 2016

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Validate.h"

int main()
{
	vector<string> users;
	string firstName,
		   lastName,
		   userName,
		   login,
		   password;
	bool validateLen = true,
		 validateSpc = true,
		 validateUpp = true,
		 validateDig = true;

	cout << "\n   Enter First Name(0 to stop): ";
	getline(cin,firstName);

	while (firstName != "0")
	{
		cout << "   Enter Last Name            : ";
		getline(cin, lastName);

		userName = firstName[0] + lastName.substr(0, 5);

		do
		{
			cout << "   Enter a password           : ";
			getline(cin, password);

			Validate pw(password);
			
			validateLen = pw.checkLength();
			validateSpc = pw.checkSpaces();
			validateUpp = pw.checkUpper();
			validateDig = pw.checkDigit();
			
		} while (validateLen || validateSpc || validateUpp || validateDig);

		login = userName + ", " + password;
		users.push_back(login);

		cout << "\n   Enter First Name(0 to stop): ";
		getline(cin, firstName);
	}

	cout << endl;

	for (unsigned int i = 0; i < users.size(); i++)
	{
		cout << "   " << users[i] << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}