#pragma once
#include <string>
using namespace std;

class Employee
{
protected:
	string login;
	string password;
public:
	virtual bool isLoginCorrect(string Log) = 0;
	virtual bool isPasswordCorrect(string Pass) = 0;
	virtual bool authorization() = 0;
};

