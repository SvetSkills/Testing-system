#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
#include "Employee.h"
#include"Header.h"
#include<string>
#include<vector>
using namespace std;
class Tester : public Employee
{
	string t_name;
	string t_surname;
	string t_email;
public:
	Tester() {}
	Tester(string n, string s, string e) {
		this->t_name = n;
		this->t_surname = s;
		this->t_email = e;
	}
	Tester(string n, string s, string e, string a, string b) {
		this->login = n;
		this->password = s;
		this->t_name = e;
		this->t_surname = a;
		this->t_email = b;
	}
	Tester(const Tester& obj){
		this->login = obj.login;
		this->password = obj.password;
		this->t_name = obj.t_name;
		this->t_surname = obj.t_surname;
		this->t_email = obj.t_email;
	};
	bool isLoginCorrect(string Log)override;
	bool isPasswordCorrect(string Pass)override;
	bool isPasswordCorrect(string Pass, string Login);
	bool authorization()override;
	friend class Admin;
	string getLogin();
	string getPassw();
	string getSurname() {
		return this->t_surname;
	}
	void setLogin(string L);
	void setPassword(string P);
	void setTesterData();
	void writeTesterToFile();
	friend ostream& operator << (ostream& out, const Tester& obj);
};
class Programmer :public Employee
{
	string p_name;
	string p_surname;
	string p_email;
	int role_p;
	int num_of_tasks;
public:
	Programmer() { this->num_of_tasks = 0; }
	Programmer(string log, string pas, string n, string s, string e, int t) {
		this->login = log;
		this->password = pas;
		this->p_name = n;
		this->p_surname = s;
		this->p_email = e;
		this->role_p = t;
		this->num_of_tasks = 0;
	}
	Programmer(const Programmer& obj) {
		this->p_name = obj.p_name;
		this->p_surname = obj.p_surname;
		this->p_email = obj.p_email;
		this->role_p = obj.role_p;
		this->num_of_tasks = obj.num_of_tasks;
	};
	bool isLoginCorrect(string Log)override;
	bool isPasswordCorrect(string Pass,string Login);
	bool isPasswordCorrect(string Pass)override;
	bool authorization()override;
	friend class Admin;
	string getLogin();
	string getPassw();
	string getSurn() {
		return this->p_surname;
	}
	int getNumOfTasks() {
		return this->num_of_tasks;
	}
	void setLogin(string L);
	void setPassword(string P);
	void addOneTask() {
		this->num_of_tasks++;
	}
	void setProgrammerData();
	void writeProgrammerToFile();
	friend ostream& operator << (ostream& out, const Programmer& prog);
};
template <class T>
class Date {
private:
	T day;
	T month;
	T year;
public:
	Date() {
		day = month = year = 0;
	}
	Date(T day, T month, T year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void print_date() {
		cout << day << "." << month << "." << year << endl;
	}
	int getDay(void) {
		return this->day;
	}
	int getMonth(void) {
		return this->month;
	}
	int getYear(void) {
		return this->year;
	}
	void setDate() {
		cout << "Введите день:" << endl;
		this->day = scanfInt();
		while ((this->day <= 0) || (this->day >= 32)) {
			cout << "День введен неверно! Повторите попытку." << endl;
			this->day = scanfInt();
		}
		cout << endl << "Введите месяц:" << endl;
		this->month = scanfInt();
		while ((this->month <= 0) || (this->month >= 13)) {
			cout << "Месяц введен неверно! Повторите попытку." << endl;
			this->month = scanfInt();
		}
		cout << endl << "Введите год:" << endl;
		this->year = scanfInt();
		while ((this->year <= 2019) || (this->year >= 2090)) {
			cout << "Год введен неверно! Повторите попытку." << endl;
			this->year = scanfInt();
		}
		cout << endl;
	}
	string showDateStr() {
		string date;
		date = to_string(this->day) + "." + to_string(this->month) + "." + to_string(this->year);
		return date;
	}
	T DaysCount(int yearBegin, int monthBegin, int dayBegin, int yearCurrent);
};
template <class T>
T Date<T>::DaysCount(int yearBegin, int monthBegin, int dayBegin, int yearCurrent) {
	int y, m, e, d, a, b, c, res = 0;
	a = yearCurrent - yearBegin;	// Разница в годах
	b = a / 4;						// Кол-во високосных
	c = a - b;						// Кол-во невысокосных
	d = b * 366 + c * 365;			// Предварительное кол-во дней до начала года
	d -= (yearCurrent % 4) ? 1 : 0;	// +1 день, если год високосный

	//месяцы
	for (e = 1; e < monthBegin; e++) {
		// Если февраль и високосный:
		if (e == 2) d -= (yearCurrent % 4) ? 28 : 29;
		// Если по 30 дней
		else if (e == 4 || e == 6 || e == 9 || e == 11) d -= 30;
		else // Если 31 день в месяце
			d -= 31;
	}
	if (monthBegin != 12 && a == 1) return dayBegin + d;
	else return d - dayBegin;
}

class Project {
	string project_name;
	string start_date;
	string release_date;
	Date<int>  start, release;
public:
	Project() {};
	Project(const Project& obj) {};
	void writeCommentsToFile();
	void setProject();
	void deleteProjectInf();
	void writeProjectToFile();
	void writeProjectToFile(string new_name);
	void editProject();
	void editProjectName();
	void editProjectDates();
	void editProjectDates(int t);
	void showProject();
	void showComments();
};

class Admin:public Employee
{
public:
	Admin() {};
	Admin(const Admin& obj) :Employee(obj){
	};
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
	void showOpenTesterData();
	void showOpenProgrammerData();
	void sortTestersSurname();
	void sortProgrammersSurname();
	void sortProgrammersNumOfTasks(vector<Programmer>& vec_p);
	void searchProgrammer();
	void searchTester();
	void assignTasks();
	void resultOfAssign();
	void report();
	void filtr();
};

class Task {
	string task_name;
	string bug_spec;
	string status;
	string priority;
public:
	Task() {};
	Task(string name, string spec, string status, string priority);
	Task(const Task& obj) {
		this->task_name = obj.task_name;
		this->bug_spec = obj.bug_spec;
		this->status = obj.status;
		this->priority = obj.priority;
	};
	void setTask();
	void writeTaskToFile();
	void writeTaskToFile(vector<Task>& vec_task);
	void readTasksFromFile(vector<Task>& vec_task);
	void showTasks();
	void changeTaskStatusToReady();
	friend class Admin;
};
