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
	Train() {} // конструктор по-умолчанию
	// аргументированные конструкторы, используют список инициализации
	Train(int number, const string& station, const string& time) :
		number_(number), station_(station), time_(time) {}
	// для поиска по значению number
	Train(int number) : number_(number) {}

	// get-методы. модификатор const после функции указывает, что она не
	// изменяет состояние класса (все свойства остаются теми же)
	int    getNumber()  const { return number_; }
	string getStation() const { return station_; }
	string getTime()    const { return time_; }

private:
	int number_; // поля класса
	string station_;
	string time_;
};

// определяем оператор сравнения двух объектов класса. Необходимо для
// использования объектов в контейнере set (ключ сортировки будет number)
bool operator < (const Train& t1, const Train& t2)
{
	return t1.getNumber() < t2.getNumber(); // если t1.number_ меньше, то истина
}

// перегружаем оператор вывода в поток, чтобы научить выводить объекты класса
ostream& operator << (ostream& out, const Train& t)
{
	out << "Номер поезда: " << t.getNumber() << endl // формируем поток
		<< "Станция назначения: " << t.getStation() << endl
		<< "Время прибытия: " << t.getTime() << endl;
	return out; // возвращаем ссылку на сформированный поток
}


int main()
{
	setlocale(LC_ALL, ""); // настраиваем консоль на ввод/вывод русских символов
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<Train> tset; // Создаем set-контейнер объектов класса Train
	char choise = '1'; // выбор в меню
	while (choise != '0')
	{
		system("cls"); // очистка экрана
		cout << "Что желаете сделать?\n"
			<< "1. Ввести новый элемент\n"
			<< "2. Вывести все элементы\n"
			<< "3. Поиск по номеру поезда\n"
			<< "4. Поиск по названию станции назначения\n"
			<< "0. Выход\n\n"
			<< "Ваш выбор: ";
		cin >> choise;
		switch (choise)
		{
		case '1':
		{// фигурные скобки чтобы переменные объявленные тут были локальными
			int number;
			string station, time;
			system("cls"); // очистка экрана
			cout << "Введите номер поезда: ";
			cin >> number;
			cout << "Введите станцию назначения: ";
			cin >> station;
			cout << "Введите время прибытия: ";
			cin >> time;
			// добавляем новый объект класса Train вызывая аргументированный
			// конструктор и передавая ему параметры
			tset.insert(Train(number, station, time));
			break;
		}

		case '2':
			system("cls");
			if (tset.empty()) // если контейнер пуст
			{
				cout << "БД пуста, добавьте для начала элементы";
				system("pause");
				break;
			}
			// пробегаемся по всему контейнеру от начала до конца
			// it - итератор (грубо говоря указатель) на объект класса Train
			for (set<Train>::iterator it = tset.begin();
				it != tset.end(); ++it)
				cout << *it << endl; // уже умеет выводить объект на экран
			system("pause");
			break;

		case '3':
		{
			system("cls");
			if (tset.empty()) // если контейнер пуст
			{
				cout << "БД пуста, добавьте для начала элементы";
				system("pause");
				break;
			}
			int number;
			cout << "Введите номер поезда: ";
			cin >> number;
			// метод контейнера find вернет итератор на искомый объект, если
			// совпадений нет, то станет равным концу контейнера (set.end())
			// Происходит поиск по уникальному ключу
			set<Train>::iterator it = tset.find(number);
			if (it == tset.end())
				cout << "Нет сопадений";
			else
				cout << *it;
			system("pause");
			break;
		}

		case '4':
		{
			system("cls");
			if (tset.empty()) // если контейнер пуст
			{
				cout << "БД пуста, добавьте для начала элементы";
				system("pause");
				break;
			}
			string station;
			cout << "Введите станцию назначения: ";
			cin >> station;
			// поиск с помощью метода find не сработает, т.к. string station
			// не является ключом контейнера (элементом, по которому идет
			// сравнение при добавлении. Вдобавок, объектов со схожим полем
			// может быть несколько, поэтому просто перебираем весь
			// контейнер и при совпадении выводим на экран
			for (set<Train>::iterator it = tset.begin();
				it != tset.end(); ++it)
				if (it->getStation() == station) // если совпадение
					cout << *it << endl;
			system("pause");
			break;
		}

		case '0':
			break;

		default:
			cout << "Неверный ввод, повторите попытку";
			system("pause");
			break;
		} // конец switch (choise)
	} // конец цикла while (choise != '0')

	cout << "\n\nДо свидания!\n";

	return 0; // завершилось без ошибок
}