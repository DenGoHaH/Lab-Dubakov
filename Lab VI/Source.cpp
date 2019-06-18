#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
#include <clocale>
#include <conio.h>
#include <Windows.h>
using namespace std;


class Train
{
public:
	Train() {} // ����������� ��-���������
	// ����������������� ������������, ���������� ������ �������������
	Train(int number, const string& station, const string& time) :
		number_(number), station_(station), time_(time) {}
	// ��� ������ �� �������� number
	Train(int number) : number_(number) {}

	// get-������. ����������� const ����� ������� ���������, ��� ��� ��
	// �������� ��������� ������ (��� �������� �������� ���� ��)
	int    getNumber()  const { return number_; }
	string getStation() const { return station_; }
	string getTime()    const { return time_; }

private:
	int number_; // ���� ������
	string station_;
	string time_;
};

// ���������� �������� ��������� ���� �������� ������. ���������� ���
// ������������� �������� � ���������� set (���� ���������� ����� number)
bool operator < (const Train& t1, const Train& t2)
{
	return t1.getNumber() < t2.getNumber(); // ���� t1.number_ ������, �� ������
}

// ����������� �������� ������ � �����, ����� ������� �������� ������� ������
ostream& operator << (ostream& out, const Train& t)
{
	out << "����� ������: " << t.getNumber() << endl // ��������� �����
		<< "������� ����������: " << t.getStation() << endl
		<< "����� ��������: " << t.getTime() << endl;
	return out; // ���������� ������ �� �������������� �����
}


int main()
{
	setlocale(LC_ALL, ""); // ����������� ������� �� ����/����� ������� ��������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<Train> tset; // ������� set-��������� �������� ������ Train
	char choise = '1'; // ����� � ����
	while (choise != '0')
	{
		system("cls"); // ������� ������
		cout << "��� ������� �������?\n"
			<< "1. ������ ����� �������\n"
			<< "2. ������� ��� ��������\n"
			<< "3. ����� �� ������ ������\n"
			<< "4. ����� �� �������� ������� ����������\n"
			<< "0. �����\n\n"
			<< "��� �����: ";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{// �������� ������ ����� ���������� ����������� ��� ���� ����������
			int number;
			string station, time;
			system("cls"); // ������� ������
			cout << "������� ����� ������: ";
			cin >> number;
			cout << "������� ������� ����������: ";
			cin >> station;
			cout << "������� ����� ��������: ";
			cin >> time;
			// ��������� ����� ������ ������ Train ������� �����������������
			// ����������� � ��������� ��� ���������
			tset.insert(Train(number, station, time));
			break;
		}

		case '2':
			system("cls");
			if (tset.empty()) // ���� ��������� ����
			{
				cout << "�� �����, �������� ��� ������ ��������";
				system("pause");
				break;
			}
			// ����������� �� ����� ���������� �� ������ �� �����
			// it - �������� (����� ������ ���������) �� ������ ������ Train
			for (set<Train>::iterator it = tset.begin();
				it != tset.end(); ++it)
				cout << *it << endl; // ��� ����� �������� ������ �� �����
			system("pause");
			break;

		case '3':
		{
			system("cls");
			if (tset.empty()) // ���� ��������� ����
			{
				cout << "�� �����, �������� ��� ������ ��������";
				system("pause");
				break;
			}
			int number;
			cout << "������� ����� ������: ";
			cin >> number;
			// ����� ���������� find ������ �������� �� ������� ������, ����
			// ���������� ���, �� ������ ������ ����� ���������� (set.end())
			// ���������� ����� �� ����������� �����
			set<Train>::iterator it = tset.find(number);
			if (it == tset.end())
				cout << "��� ���������";
			else
				cout << *it;
			system("pause");
			break;
		}

		case '4':
		{
			system("cls");
			if (tset.empty()) // ���� ��������� ����
			{
				cout << "�� �����, �������� ��� ������ ��������";
				system("pause");
				break;
			}
			string station;
			cout << "������� ������� ����������: ";
			cin >> station;
			// ����� � ������� ������ find �� ���������, �.�. string station
			// �� �������� ������ ���������� (���������, �� �������� ����
			// ��������� ��� ����������. ��������, �������� �� ������ �����
			// ����� ���� ���������, ������� ������ ���������� ����
			// ��������� � ��� ���������� ������� �� �����
			for (set<Train>::iterator it = tset.begin();
				it != tset.end(); ++it)
				if (it->getStation() == station) // ���� ����������
					cout << *it << endl;
			system("pause");
			break;
		}

		case '0':
			break;

		default:
			cout << "�������� ����, ��������� �������";
			system("pause");
			break;
		} // ����� switch (choise)
	} // ����� ����� while (choise != '0')

	cout << "\n\n�� ��������!\n";

	return 0; // ����������� ��� ������
}