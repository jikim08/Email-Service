#pragma once
#include <iostream>
#include <map>
#include <vector>

class Email_storage {			//���� 1���� ����
private:
	std::string To;
	std::string From;
	std::string Title;
	std::string Contents;
public:
	void Get_email();		//��������� ���� �ޱ����� �Լ�
	void Get_From(std::string ID);
};

class MainController {
public:
	void start();			//��ǻ� �����Լ�
};

class EmailController {			//ID�� �� ����
private:
	std::vector<Email_storage> send_mail;
	std::vector<Email_storage> receive_mail;
public:
	
	void Send();			//���� ������
	void show_send();		//���� ������
	void show_receive();	//���� ������
};

class AccountController {		//��� ���� ����
private:
	std::map<std::string, std::string> ID_PW;
	std::map<std::string, EmailController> users;
public:
	void Get_ID_PW();			//ȸ������
	void login();
	void logout();
};