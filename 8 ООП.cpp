#include <iostream>
#include "time.h"
#include <string>
#include "windows.h"
using namespace std;

class Comp {
protected:
	int price;
	string name;
public:
	Comp()
	{
		name = "";
		price = 0;
	}
	Comp(int price, string name)
	{
		this->price = price;
		this->name = name;
	}
	virtual void read()
	{
		cout << "������������:";
		cin >> name;
		cout << "����:";
		cin >> price;
	}
	virtual void print()
	{
		cout << "������������:" << name << endl;
		cout << "����:" << price << endl;
	}
	string getName() { return name; }
	int getPrice() { return price; }
};
class MotherBoard : public Comp {
protected:
	string socket;
	int NumOfRam;
public:
	MotherBoard() : Comp(price, name)
	{
		socket = "";
		NumOfRam = 0;
	}
	MotherBoard(int price, string name, string socket, int NumOfRam) : Comp(price, name)
	{
		this->socket = socket;
		this->NumOfRam = NumOfRam;
	}
	virtual void read()
	{
		cout << "�����:";
		cin >> socket;
		cout << "���������� ������ ��� ����������� ������:";
		cin >> NumOfRam;
	}
	virtual void print()
	{
		cout << "������������:" << name << endl;
		cout << "����:" << price << endl;
		cout << "�����:" << socket << endl;
		cout << "���������� ������ ��� ����������� ������:" << NumOfRam << endl;
	}
	string getSocket() { return socket; }
	int getNumOfRam() { return NumOfRam; }
};
class PowerSupply : public Comp {
protected:
	int power;
	string CertificateAvail;
public:
	PowerSupply(int price, string name, string CertificateAvail, int power) : Comp(price, name)
	{
		this->power = power;
		this->CertificateAvail = CertificateAvail;
	}
	PowerSupply() : Comp(price, name)
	{
		CertificateAvail = "";
		power = 0;
	}
	virtual void read()
	{
		cout << "������� �����������:";
		cin >> CertificateAvail;
		cout << "��������:";
		cin >> power;
	}
	virtual void print()
	{
		cout << "������������:" << name << endl;
		cout << "����:" << price << endl;
		cout << "������� �����������:" << CertificateAvail << endl;
		cout << "��������:" << power << endl;
	}
	string getSocket() { return CertificateAvail; }
	int getNumOfRam() { return power; }
};

int main()
{
	setlocale(LC_ALL, "ru");

	MotherBoard a(5890, "Asus as-7980", "LGA1155", 3);
	Comp* first = &a;
	first->print();
	cout << endl << endl;
	PowerSupply b(1999, "AeroCool VX-650", "�����������", 650);
	first = &b;
	first->print();
	cout << endl;
	system("pause");
	return 0;
}