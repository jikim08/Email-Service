#include <iostream>
#include <string>
#include "EmailService.h"
using namespace std;

void MainController::start() {
	AccountController storage;
	int cmd;

	while(true) {
		cout << "���� 0" << endl;
		cout << "ȸ������ 1" << endl;
		cout << "�α��� 2" << endl;
		cin >> cmd;

		switch (cmd) {
		case 0:
			return;
		case 1:
			storage.Get_ID_PW();
			break;
		case 2:
			storage.login();
			break;
		default:
			cout << "���� �޴��Դϴ�" << endl;
		}

	}
}

void Email_storage::Get_email() {
	cout << "To: ";
	cin >> To;
	cout << "Title: ";
	getline(cin, Title);
	cout << "Contents: ";
	getline(cin, Contents);
}
void Email_storage::Get_From(string ID) {
	From = ID;
}


void EmailController::Send() {
	send_mail.end()->Get_email();
}

void AccountController::Get_ID_PW() {
	string ID;
	string PW;
	cout << "ID: ";
	cin >> ID;
	cout << "PW: ";
	cin >> PW;

	ID_PW.insert({ ID, PW });
	users.insert({ ID, EmailController() });
}