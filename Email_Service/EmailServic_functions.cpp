#include <iostream>
#include "EmailService.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

void MainController::start() {
	AccountController acclist;
	int cmd;

	while (true) {
		cin >> cmd;
		EmailController loginID;
		bool loginflag;
		switch (cmd) {
		case 0:
			return;
		case 1:
			acclist.addID();
			break;
		case 2:
			loginflag = acclist.login(loginID);
			if (loginflag) {
				cout << loginID.returnID() << "환영합니다" << endl;
			}
			break;
		default:
			cout << "잘못된 메뉴" << endl;
			break;
		}



	}
}

void Emailstorage::GetEmail() {
	cout << "To: ";
	cin >> To;
	cout << "Title: ";
	getline(cin, Title);
	cout << "Contents: ";
	getline(cin, contents);
}
void Emailstorage::GetFrom(string name) {
	From = name;
}
void Emailstorage::ShowMail() {
	cout << "To: " << To << endl;
	cout << "From: " << From << endl;
	cout << "Title: " << Title << endl;
	cout << "Contents: " << contents << endl << endl;
}

string Emailstorage::ReturnTo(){
	return To;
}

void EmailController::Receive(Emailstorage& mail) {
	ReceiveMail.push_back(mail);
}

void EmailController::ShowSendMail() {
	for (auto i = 0; i<SendMail.size(); i++) {
		SendMail[i].ShowMail();
	}
}

void EmailController::ShowReceiveMail() {
	for (auto i = 0; i < ReceiveMail.size(); i++) {
		ReceiveMail[i].ShowMail();
	}
}

void AccountController::addID() {
	string ID, PW;
	cout << "ID: ";
	cin >> ID;
	cout << "PW: ";
	cin >> PW;
	IDPW.insert({ ID,PW });
	data.insert({ ID, EmailController() });
}

void AccountController::ReceiveMail(Emailstorage& mail) {
	auto Receiver = data.find(mail.ReturnTo());
	Receiver->second.Receive(mail);
}

void EmailController::Send(AccountController& acclist) {
	Emailstorage mail;
	mail.GetEmail();
	mail.GetFrom(ID);
	SendMail.push_back(mail);
	acclist.ReceiveMail(mail);
}

void EmailController::GetID(string ID) {
	this->ID = ID;
}
string EmailController::returnID() {
	return ID;
}

bool AccountController::login(EmailController &loginID) {		//로그인 방법 수정하기
	string ID, PW;
	cout << "ID: ";
	cin >> ID;
	if (IDPW.find(ID) == IDPW.end()) {
		return false;
	}
	cout << "PW: ";
	cin >> PW;
	if (IDPW.find(ID)->second != PW) {
		return false;
	}
	else {
		loginID.GetID(ID);
		return true;
	}

}