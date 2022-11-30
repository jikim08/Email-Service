#include <iostream>
#include "EmailService.h"
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

void MainController::start() {
	AccountController IDlist;
	int cmd;

	while (true) {
		system("cls");
		cout << "���� 0\n";
		cout << "ȸ������ 1\n";
		cout << "�α��� 2\n";
		cout << "ID��� ���� 3\n";
		cin >> cmd;
		
		if(cmd == 0)
			return;

		else if (cmd == 1) {
			IDlist.SignUp();
		}

		else if (cmd == 2) {
			EmailController& loginID = IDlist.Login();
			while (true) {
				system("cls");
				cout << "�α׾ƿ� 0\n";
				cout << "���� ���� 1\n";
				cout << "���� ���� ���� 2\n";
				cout << "���� ���� ���� 3\n";
				cin >> cmd;
				if (cmd == 0) {
					break;
				}
				else if (cmd == 1) {
					loginID.Send(IDlist);
					cout << "���ۿϷ�\n";
					Sleep(1000);
				}
				else if (cmd == 2) {
					system("cls");
					loginID.ShowSend();
					system("pause");
				}
				else if (cmd == 3) {
					system("cls");
					loginID.ShowReceive();
					system("pause");
				}
			}
		}

		else if (cmd == 3) {
			IDlist.ShowIDs();
		}
		else{
			cout << "�߸��� �޴��Դϴ�." << endl;
			Sleep(2000);
		}

	}
}

void AccountController::SignUp() {
	string ID, PW;
	while (1) {
		system("cls");
		cout << "ID: ";
		cin >> ID;
		cout << "PW: ";
		cin >> PW;

		if (IDPW.find(ID) != IDPW.end()) {
			cout << "�̹� �ִ� ID�Դϴ�" << endl;
			Sleep(2000);
		}
		else {
			IDPW.insert({ ID,PW });
			data.insert({ ID,EmailController(ID) });
			cout << ID << "��, ������ �Ϸ�Ǿ����ϴ�\n" << endl;
			Sleep(2000);
			break;
		}
	}
	
}

void AccountController::ShowIDs() {
	system("cls");
	for (auto i = IDPW.begin(); i != IDPW.end(); i++) {
		cout << i->first << endl;
	}
	cout << endl;
	system("pause");
}

EmailController& AccountController::Login() {
	string ID, PW;
	while (true) {
		system("cls");
		cout << "ID: ";
		cin >> ID;
		cout << "PW: ";
		cin >> PW;

		if (IDPW.find(ID) == IDPW.end()) {
			cout << "�������� �ʴ� ID�Դϴ�\n\n";
			Sleep(1500);
			continue;
		}
		if (IDPW.find(ID)->second != PW) {
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�\n\n";
			Sleep(1500);
			continue;
		}
		else {
			cout << ID << "��, ȯ���մϴ�\n\n";
			Sleep(1500);
			return data.find(ID)->second;

		}

	}
	
}
void EmailController::Send(AccountController& acclist) {
	Emailstorage mail;

	while (true) {
		system("cls");
		cout << "To: ";
		cin >> mail.To;
		cout << "Title: ";
		cin >> mail.Title;
		cout << "Contents: ";
		cin >> mail.Contents;

		mail.From = ID;
		
		bool flag = acclist.sending(mail.To, mail);
		
		if (!flag) {
			continue;
		}
		

		sendMail.push_back(mail);
		break;
	}
	
	
}
void EmailController::Receive(Emailstorage mail) {
	receiveMail.push_back(mail);
}

bool AccountController::sending(string ID, Emailstorage mail) {
	if (data.find(ID) == data.end()) {
		cout << "�����ڰ� �������� �ʽ��ϴ�\n";
		Sleep(1000);
		return false;
	}
	data.find(ID)->second.Receive(mail);
	return true;
}
EmailController::EmailController(){}
EmailController::EmailController(string ID) :ID(ID){}

void EmailController::ShowSend() {
	for (auto i = sendMail.begin(); i != sendMail.end(); i++) {
		cout << "To: " << i->To << endl;
		cout << "From: " << i->From << endl;
		cout << "Title: " << i->Title << endl;
		cout << "Contents: " << i->Contents << endl;
		cout << "\n";
	}
}

void EmailController::ShowReceive() {
	for (auto i = receiveMail.begin(); i != receiveMail.end(); i++) {
		cout << "To: " << i->To << endl;
		cout << "From: " << i->From << endl;
		cout << "Title: " << i->Title << endl;
		cout << "Contents: " << i->Contents << endl;
		cout << "\n";
	}
}