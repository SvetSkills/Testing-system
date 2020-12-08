#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Employee.h"
#include<vector>
using namespace std;
class Tester : public Employee
{
	string t_name;
	string t_surname;
	string t_email;
public:
	const int role_t = 1;
	Tester() {}
	Tester(string n, string s, string e) {
		this->t_name = n;
		this->t_surname = s;
		this->t_email = e;
	}
	Tester(string log, string pas, string n, string s, string e) {
		this->login = log;
		this->password = pas;
		this->t_name = n;
		this->t_surname = s;
		this->t_email = e;
	}
	bool isLoginCorrect(string Log)override;
	bool isPasswordCorrect(string Pass)override;
	bool authorization()override;
	friend class Admin;
	string getLogin();
	string getPassw();
	void setLogin(string L);
	void setPassword(string P);
	void setTesterData();
	void writeTesterToFile();
	friend ostream& operator << (ostream& out, const Tester& obj);
	friend void showOpenTesterData();
	friend vector<Tester> readTestersInfFile();
};
enum specialization {
	BACK_END,
	FRONT_END
};
class Programmer :public Employee
{
	string p_name;
	string p_surname;
	string p_email;
	specialization p_spec;
public:
	const int role_p = 2;
	Programmer() {}
	Programmer(string log, string pas, string n, string s, string e, int t) {
		this->login = log;
		this->password = pas;
		this->p_name = n;
		this->p_surname = s;
		this->p_email = e;
		if (t == 0) { this->p_spec = BACK_END; }
		else if (t == 1) { this->p_spec = FRONT_END; }
	}
	bool isLoginCorrect(string Log)override;
	bool isPasswordCorrect(string Pass) override;
	bool authorization()override;
	friend class Admin;
	string getLogin();
	string getPassw();
	void setLogin(string L);
	void setPassword(string P);
	void setProgrammerData();
	void writeProgrammerToFile();
	friend ostream& operator << (ostream& out, const Programmer& prog);
	friend void showOpenProgrammerData();
};

class Admin:public Employee
{
	//static int amount_of_testers;
	//static int amount_of_progr;
	//void getTestersOutOfFile(vector<Tester>&vecT);
	//vector<Tester>vec_t;
	//vector<Programmer>vec_p;

	//void readTestersFile(vector<Tester>& vec_t);
	//void readProgrammersFile(vector<Programmer>& vec_p);
public:
	bool isLoginCorrect(string Log) override;
	bool isPasswordCorrect(string Pass) override;
	bool authorization() override;
	void addTester();
	void addProgremmer();
	void readTestersFile(vector<Tester>& vec_t);
	void showTesters();
	void readProgrammersFile(vector<Programmer>& vec_p);
	void showProgrammers();
	void deleteTester();
	void deleteProgrammer();
	//friend vector<Tester> readTestersInfFile();
	//void readProgrammersInfFile();
	void showOpenTesterData();
	void showOpenProgrammerData();
};
class Project {

};