#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class AccountController;
class EmailController;
class Emailstorage;

class MainController {
public:
	void start();
};

class AccountController {
private:
	map<string, string> IDPW;
	map<string, EmailController> data;
public:
	void SignUp();
	void ShowIDs();
	EmailController& Login();
	bool sending(string ID, Emailstorage mail);
};

class Emailstorage {
public:
	string To;
	string From;
	string Title;
	string Contents;
};
class EmailController {
private:
	string ID;
	vector<Emailstorage> sendMail;
	vector<Emailstorage> receiveMail;
public:
	EmailController();
	EmailController(string ID);
	void Send(AccountController& acclist);
	void Receive(Emailstorage mail);
	void ShowSend();
	void ShowReceive();

};