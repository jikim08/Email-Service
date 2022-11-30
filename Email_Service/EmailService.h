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
	map<string, string> IDPW;				//ID ��й�ȣ ����
	map<string, EmailController> data;		//ID�� ���� ���ϸ�� ����
public:
	void SignUp();							//ȸ������
	void ShowIDs();							//ID�� ����
	EmailController& Login();				//�α����ϱ�
	bool sending(string ID, Emailstorage mail);	//���� ���� �߰�����(data�� �� Ŭ������ �����Ƿ� data�� �����ϱ� ���� �뵵)
};

class Emailstorage {						//���� �Ѱ��� ������ ������ �� �ִ� ����ü
public:
	string To;
	string From;
	string Title;
	string Contents;
};

class EmailController {
private:
	string ID;								//�ش� ��ü�� ID
	vector<Emailstorage> sendMail;			//���� ����
	vector<Emailstorage> receiveMail;		//���� ����
public:
	EmailController();						//����Ʈ	������
	EmailController(string ID);				//ID�� �������ִ� ������
	void Send(AccountController& acclist);	//������(���� �Է� �� ������)
	void Receive(Emailstorage mail);		//�ޱ�(AccountEmailŬ�������� receivemail�� �����ϱ� ���� �Լ�)
	void ShowSend();
	void ShowReceive();

};