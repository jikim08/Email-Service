#include <iostream>
#include "EmailService.h"
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

void MainController::start() {
	AccountController IDlist;							//계정 저장소
	int cmd;								//메뉴 입력용

	while (true) {
		system("cls");
		cout << "종료 0\n";
		cout << "회원가입 1\n";
		cout << "로그인 2\n";
		cout << "ID목록 보기 3\n";
		cin >> cmd;
		
		if(cmd == 0)
			return;

		else if (cmd == 1) {
			IDlist.SignUp();			//회원가입
		}

		else if (cmd == 2) {
			EmailController& loginID = IDlist.Login();		//현재 로그인한 계정
			while (true) {
				system("cls");
				cout << "로그아웃 0\n";
				cout << "메일 쓰기 1\n";
				cout << "보낸 메일 보기 2\n";
				cout << "받은 메일 보기 3\n";
				cin >> cmd;
				if (cmd == 0) {
					break;
				}
				else if (cmd == 1) {
					loginID.Send(IDlist);					//메일 보내기
					cout << "전송완료\n";
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
				else {
					cout << "잘못된 메뉴입니다\n";
					Sleep(1000);
				}
			}
		}

		else if (cmd == 3) {
			IDlist.ShowIDs();
		}
		else{
			cout << "잘못된 메뉴입니다." << endl;
			Sleep(1000);
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

		if (IDPW.find(ID) != IDPW.end()) {				//ID가 이미 있는 경우
			cout << "이미 있는 ID입니다" << endl;
			Sleep(2000);
		}
		else {
			IDPW.insert({ ID,PW });						//ID와 PW를 맵에 저장
			data.insert({ ID,EmailController(ID) });	//ID와 해당 계정 정보를 맵에 저장
			cout << ID << "님, 가입이 완료되었습니다\n" << endl;
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
			cout << "존재하지 않는 ID입니다\n\n";
			Sleep(1500);
			continue;
		}
		if (IDPW.find(ID)->second != PW) {
			cout << "비밀번호가 일치하지 않습니다\n\n";
			Sleep(1500);
			continue;
		}
		else {
			cout << ID << "님, 환영합니다\n\n";
			Sleep(1500);
			return data.find(ID)->second;					//로그인 한 계정(참조값)을 리턴

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
		cin.ignore();				//엔터 무시
		getline(cin, mail.Title);
		cout << "Contents: ";
		getline(cin, mail.Contents);

		mail.From = ID;
		
		bool flag = acclist.sending(mail.To, mail);			//수신자 유무 리턴, 수신자가 있으면 수신자 받은 메일함에 메일 저장
		
		if (!flag) {			//수신자 ID가 존재하지 않는 경우
			continue;
		}
		

		sendMail.push_back(mail);
		break;
	}
	
	
}
void EmailController::Receive(Emailstorage mail) {			//receiveMail에 접근하기 위한 함수
	receiveMail.push_back(mail);
}

bool AccountController::sending(string ID, Emailstorage mail) {		//수신자 유무 리턴, 수신자가 있으면 수신자 받은 메일함에 메일 저장
	if (data.find(ID) == data.end()) {
		cout << "수신자가 존재하지 않습니다\n";
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