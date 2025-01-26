#include <iostream>
#include <string>
using namespace std;


class People
{
protected:
	string name;
	string egn;
public:

	People(string name, string egn) :name(name), egn(egn) {};
	~People() {};
	string getName() const { return name; }
	string getEgn() const { return egn; }

};
class Student :public People
{
protected:
	int facnom;
	double uspeh;
public:
	Student(string name, string egn, int nomer, double rating)
		:People(name, egn), facnom(nomer), uspeh(rating) {};
	~Student() {};

	int getFnumer()const { return facnom; };
	double getUspeh()const { return uspeh; };
};
class PStudent :public Student
{
public:
	PStudent(string name, string egn, int nomer, double rating)
		:Student(name, egn, nomer, rating) {};
	void PayForm() const {
		if (uspeh > 4.5)
			cout << "ima stipendiq" << endl;
		else
			cout << "Platena forma na obuchenie" << endl;
	}
};

int main()
{
	PStudent student1("Steve", "123483", 888, 5);
	cout << "Ime: " << student1.getName() << endl;
	cout << "EGN: " << student1.getEgn() << endl;
	cout << "FacNom: " << student1.getFnumer() << endl;
	cout << "Uspeh: " << student1.getUspeh() << endl;
	student1.PayForm();
	cout << endl;
	return 0;
}