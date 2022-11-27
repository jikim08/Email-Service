#pragma once
#include <iostream>
#include <map>
#include <vector>

class Email_storage {			//메일 1개만 관리
private:
	std::string To;
	std::string From;
	std::string Title;
	std::string Contents;
public:
	void Get_email();		//멤버변수에 값을 받기위한 함수
	void Get_From(std::string ID);
};

class MainController {
public:
	void start();			//사실상 메인함수
};

class EmailController {			//ID한 개 관리
private:
	std::vector<Email_storage> send_mail;
	std::vector<Email_storage> receive_mail;
public:
	
	void Send();			//메일 보내기
	void show_send();		//보낸 메일함
	void show_receive();	//받은 메일함
};

class AccountController {		//모든 계정 관리
private:
	std::map<std::string, std::string> ID_PW;
	std::map<std::string, EmailController> users;
public:
	void Get_ID_PW();			//회원가입
	void login();
	void logout();
};