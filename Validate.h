class Validate
{
public:
	Validate(string);
	bool checkLength();
	bool checkSpaces();
	bool checkUpper();
	bool checkDigit();
private:
	string password;
	const int LEN = 5;
};

Validate::Validate(string pw)
{
	password = pw;
}

bool Validate::checkLength()
{
	if (password.length() < LEN)
	{
		cout << "   Error: Password must contain at least " << LEN << " characters." << endl;

		return true;
	}
	else
	{
		return false;
	}
}

bool Validate::checkSpaces()
{
	int ctr = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if (isspace(password[i]))
		{
			ctr++;
		}
	}

	if (ctr > 0)
	{
		cout << "   Error: Password cannot contain spaces." << endl;

		return true;
	}
	else
	{
		return false;
	}
}

bool Validate::checkUpper()
{
	int ctr = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(password[i]))
		{
			ctr++;
		}
	}

	if (ctr < 1)
	{
		cout << "   Error: Password must contain at least one upper case letter." << endl;

		return true;
	}
	else
	{
		return false;
	}
}

bool Validate::checkDigit()
{
	int ctr = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i]))
		{
			ctr++;
		}
	}

	if (ctr < 1)
	{
		cout << "   Error: Password must contain at least one number." << endl;

		return true;
	}
	else
	{
		return false;
	}
}