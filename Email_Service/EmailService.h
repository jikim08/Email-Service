#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class AccountController;

class Emailstorage {
private:
	string To;
	string From;
	string Title;
	string contents;
public:
	void GetEmail();
	void GetFrom(string name);
	string ReturnTo();
	void ShowMail();
};

class MainController {
	void start();
};

class EmailController {
private:
	string ID;
	vector<Emailstorage> SendMail;
	vector<Emailstorage> ReceiveMail;
public:
	void GetID(string ID);
	string returnID();
	void Send(AccountController& acclist);
	void Receive(Emailstorage& mail);
	void ShowSendMail();
	void ShowReceiveMail();
};

class AccountController {
private:
	map<string, string> IDPW;
	map<string, EmailController> data;
public:
	void addID();
	void ReceiveMail(Emailstorage& mail);
	bool login(EmailController &loginID);
};