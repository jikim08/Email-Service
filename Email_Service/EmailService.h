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
	map<string, string> IDPW;				//ID 비밀번호 저장
	map<string, EmailController> data;		//ID에 따른 메일목록 저장
public:
	void SignUp();							//회원가입
	void ShowIDs();							//ID들 보기
	EmailController& Login();				//로그인하기
	bool sending(string ID, Emailstorage mail);	//메일 전송 중간과정(data가 이 클래스에 있으므로 data에 접근하기 위한 용도)
};

class Emailstorage {						//메일 한개의 정보를 저장할 수 있는 구조체
public:
	string To;
	string From;
	string Title;
	string Contents;
};

class EmailController {
private:
	string ID;								//해당 객체의 ID
	vector<Emailstorage> sendMail;			//보낸 메일
	vector<Emailstorage> receiveMail;		//받은 메일
public:
	EmailController();						//디폴트	생성자
	EmailController(string ID);				//ID를 저장해주는 생성자
	void Send(AccountController& acclist);	//보내기(메일 입력 및 보내기)
	void Receive(Emailstorage mail);		//받기(AccountEmail클래스에서 receivemail에 접근하기 위한 함수)
	void ShowSend();
	void ShowReceive();

};