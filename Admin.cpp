#include"Classes.h"
#include"Header.h"

bool Admin::isLoginCorrect(string Log) {
		ifstream file;
		file.open("Admin.txt", ios_base::in);
		bool check = true;
		string login, password, name, surname, email;
		while (!file.eof())
		{
			file >> login;
			file >> password;
			file >> name;
			file >> surname;
			file >> email;
			if (login != Log)
			{
				check = false;
			}
		}
		file.close();
		return check;
	}
bool Admin::isPasswordCorrect(string Pass) {
		ifstream file;
		file.open("Admin.txt", ios_base::in);
		bool check = true;
		string login, password;

		while (!file.eof())
		{
			file >> login;
			file >> password;
			if (password != Pass)
			{
				check = false;
			}
		}

		file.close();
		return check;
	}
bool Admin::authorization()
{
	string Login = scanfLogin();
	cout << endl;
	shifr(Login);
	while (Admin::isLoginCorrect(Login)==false)
	{
		cout << endl << "Неверный логин! Повторите попытку!" << endl;
		Login = scanfLogin();
		cout << endl;
		shifr(Login);
	}
	deshifr(Login);
	this->login = Login;
	string Pass;
	scanfPassword(Pass);
	shifr(Pass);
	while ((Admin::isPasswordCorrect(Pass))==false)
	{
		cout << endl << "Неверный пароль";
		scanfPassword(Pass);
		cout << endl;
		shifr(Pass);
	}
	deshifr(Pass);
	this->password = Pass;
	return true;
}
void Admin::addTester() {
	Tester test;
	system("cls");
	cout << "Введите логин:" << endl;
	string Log = scanfLogin();
	cout << endl;
	shifr(Log);
	while ((test.isLoginCorrect(Log)) == true)
	{
		cout << "\nТакой логин уже существует, придумайте новый\n";
		cout << "\nВведите логин:\n";
		Log = scanfLogin();
		cout << endl;
		shifr(Log);
	}
	test.setLogin(Log);

	string pas;
	scanfPassword(pas);
	shifr(pas);
	test.setPassword(pas);
	cout << endl;
	test.setTesterData();
	test.writeTesterToFile();
	system("cls");
}
void Admin::addProgremmer() {
	Programmer prog;
	system("cls");
	cout << endl;
	string Log = scanfLogin();
	cout << endl;
	shifr(Log);
	while ((prog.isLoginCorrect(Log)) == true)
	{
		cout << "\nТакой логин уже существует, придумайте новый\n";
		cout << "\nВведите логин:\n";
		Log = scanfLogin();
		cout << endl;
		shifr(Log);
	}
	prog.setLogin(Log);

	string pas;
	scanfPassword(pas);
	shifr(pas);
	prog.setPassword(pas);
	cout << endl;
	prog.setProgrammerData();
	prog.writeProgrammerToFile();
	system("cls");
}
void Admin::readTestersFile(vector<Tester>& vec_t)
{
	ifstream file;
	file.open("Testers.txt", ios_base::in);
	string log, pass, name , surname, email;
	
	while (!file.eof())
	{
		file >> log;
		file >> pass;
		file >> name;
		file >> surname;
		file >> email;

		Tester test(log, pass, name, surname, email);
		vec_t.push_back(test);
	}
	file.close();
}
void Admin::showTesters()
{
	system("cls");
	cout << endl << "Информация о тестировщиках" << endl;
	vector<Tester> vec_t;
	Admin::readTestersFile(vec_t);
	    cout << "========================================================================================================" << endl;
	    cout << "|  №  |   Логин   |   Пароль  |         Имя        |       Фамилия        |     Электронная почта      |" << endl;
	    cout << "========================================================================================================" << endl;
	for (int i = 0; i < vec_t.size(); i++)
	{
		cout << "|" << setw(5) << (i + 1) << "|" << setw(11) << vec_t[i].login << "|" << setw(11) << vec_t[i].password << "|" << setw(20) << vec_t[i].t_name << "|"
			<< setw(22) << vec_t[i].t_surname << "|" << setw(28) << vec_t[i].t_email<< "|" << endl;
		cout << "========================================================================================================" << endl;
	}
	system("pause");
	system("cls");
			
}
void Admin::readProgrammersFile(vector<Programmer>& vec_p)
{
	ifstream file;
	file.open("Programmers.txt", ios_base::in);
	string log, pass, name, surname, email;
	string A = "BACK_END";
	string B = "FRONT_END";
	string temp;
	int spec = -1;

	while (!file.eof())
	{
		file >> log;
		file >> pass;
		file >> name;
		file >> surname;
		file >> email;
		file >> temp;
		if (temp == A) { spec = 0; }
		else if (temp == B) { spec = 1; }
			Programmer pr(log, pass, name, surname, email, spec);
		vec_p.push_back(pr);
	}
	file.close();
}
void Admin::showProgrammers()
{
	system("cls");
	cout << endl << "Информация о программистах" << endl;
	vector<Programmer> vec_p;
	Admin::readProgrammersFile(vec_p);
	cout << "========================================================================================================================" << endl;
	cout << "|  №  |   Логин   |   Пароль  |         Имя        |       Фамилия        |     Электронная почта      | Специализация |" << endl;
	cout << "========================================================================================================================" << endl;

	for (int i = 0; i < vec_p.size(); i++)
	{
		cout << "|" << setw(5) << (i + 1) << "|" << setw(11) << vec_p[i].login << "|" << setw(11) << vec_p[i].password << "|" << setw(20) << vec_p[i].p_name << "|"
			<< setw(22) << vec_p[i].p_surname << "|" << setw(28) << vec_p[i].p_email << "|" << setw(15) ;
			if (vec_p[i].role_p == 0) {
				cout << "BACK_END" <<"|"<< endl;
			} 
			else { cout << "FRONT_END" <<"|"<< endl;}
		cout << "========================================================================================================================\n";
	}
	system("pause");
	system("cls");
}
void Admin::deleteTester() {
	int num_to_del = 0;
	Admin::showTesters();
	vector<Tester> vect;
	Admin::readTestersFile(vect);
	cout << endl << "Введите номер сотрудника для удаления:" << endl;
	cin >> num_to_del;
	ofstream file1;
	file1.open("Testers.txt", ofstream::out | ofstream::trunc/*ios_base::trunc*/);
	file1.close();
	for (int i = 0; i < vect.size(); i++)
	{
		if (i != (num_to_del-1))
		{
			vect[i].writeTesterToFile();
		}
	}
}   
void Admin::deleteProgrammer() {
	int num_to_del = 0;
	Admin::showProgrammers();
	vector<Programmer> vect;
	Admin::readProgrammersFile(vect);
	cout << endl << "Введите номер сотрудника для удаления:" << endl;
	cin >> num_to_del;
	ofstream file1;
	file1.open("Programmers.txt", ofstream::out | ofstream::trunc/*ios_base::trunc*/);
	file1.close();
	for (int i = 0; i < vect.size(); i++)
	{
		if (i != (num_to_del - 1))
		{
			vect[i].writeProgrammerToFile();
		}
	}
} 
void Admin::showOpenTesterData() {

	system("cls");
	cout << "                       Контактная информация о тестировщиках                    " << endl;
	vector<Tester> vec_t;
	Admin::readTestersFile(vec_t);
	cout << "======|=========================================================================" << endl;
	cout << "|  №  |         Имя        |       Фамилия        |     Электронная почта      |" << endl;
	cout << "======|=========================================================================" << endl;
	for (int i = 0; i < vec_t.size(); i++)
	{
		cout << "|" << setw(5) << (i + 1) << "|"  << setw(20) << vec_t[i].t_name << "|"<< setw(22) << vec_t[i].t_surname << "|" << setw(28) << vec_t[i].t_email << "|" << endl;
		cout << "========================================================================================================" << endl;
	}
	system("pause");
	system("cls");
}
void Admin::showOpenProgrammerData() {
	system("cls");
	cout << "                              Контактная информация о программистах                             " << endl;
	vector<Programmer> vec_p;
	Admin::readProgrammersFile(vec_p);
	cout << "================================================================================================" << endl;
	cout << "|  №  |         Имя        |       Фамилия        |     Электронная почта      | Специализация |" << endl;
	cout << "================================================================================================" << endl;

	for (int i = 0; i < vec_p.size(); i++)
	{
		cout << "|" << setw(5) << (i + 1) << "|"  << setw(20) << vec_p[i].p_name << "|"	<< setw(22) << vec_p[i].p_surname << "|" << setw(28) << vec_p[i].p_email << "|" << setw(15);
		if (vec_p[i].role_p == 0) {
			cout << "BACK_END" << "|" << endl;
		}
		else { cout << "FRONT_END" << "|" << endl; }
		cout << "================================================================================================\n";
	}
	system("pause");
	system("cls");
}
/*
#pragma once
#include "stdafx.h"
#include "fstream"
using namespace std;

class  mFile
{
protected:
	char file_name[30];
	fstream f;
public:
	mFile(char *FILE_NAME){
		strcpy(file_name, FILE_NAME);
	};
	~mFile(){
		f.close();
	};
	void Remote_file(int flag){
		if (flag)
		{
			f.seekg(0, ios::beg);
			f.seekp(0, ios::beg);
		}
		else
		{
			f.seekg(0, ios::end);
			f.seekp(0, ios::end);
		}
	}
};

 class File_txt : public mFile{
	public:
		File_txt(char *FILE_NAME): mFile(FILE_NAME){}
		~File_txt(){}
		int open_file(){

			f.open(file_name , ios::in | ios::out);
			if (!f)
			{
				f.open(file_name, ios::in | ios::out | ios::trunc);
			}
			return 0;
		}
		template <class A>
		void write_file(A& obj)
		{
			f << obj << endl;
		}
		template <class A>
		int read_file(A& obj){
			if (!f.eof() && f >> obj)
			{
				return 1;
			}
			return 0;
		}


 };

*/