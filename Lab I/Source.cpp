#include <iostream>
using namespace std;
#include <math.h>

class Krug
{
	double cx, cy, r;
public:
	void Vvod1();
	void Vivod1();
	void Perem1();
	void Izm_raz1();
};
class Kvadrat
{
	double ax, ay, cx, cy;
public:
	void Vvod2();
	void Vivod2();
	void Perem2();
	void Izm_raz2();
	void Vrash2();
};
class Priam
{
	double ax, ay, cx, cy;
public:
	void Vvod3();
	void Vivod3();
	void Perem3();
	void Izm_raz3();
	void Vrash3();
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Krug a;
	Kvadrat b;
	Priam c;
	int vibor;
a:
	cout << "Выбор фигур. 1)Круг; 2)Квадрат; 3)Прямоугольник;" << endl;
	cin >> vibor;
	switch (vibor)
	{
	case 1:
		a.Vvod1();
		a.Vivod1();
		a.Perem1();
		a.Vivod1();
		a.Izm_raz1();
		a.Vivod1();
		break;
	case 2:
		b.Vvod2();
		b.Vivod2();
		b.Perem2();
		b.Vivod2();
		b.Izm_raz2();
		b.Vivod2();
		b.Vrash2();
		b.Vivod2();
		break;
	case 3:
		c.Vvod3();
		c.Vivod3();
		c.Perem3();
		c.Vivod3();
		c.Izm_raz3();
		c.Vivod3();
		c.Vrash3();
		c.Vivod3();
		break;
	default:
		cout << "Сказано же из трех, дурак." << endl;
		goto a;
	}
	system("pause");
}

void Krug::Vvod1()
{
	cout << endl;
	cout << "Ввод параметров круга";
	cout << endl;
	cout << " cx=";
	cin >> cx;
	cout << " cy=";
	cin >> cy;
	cout << " r=";
	cin >> r;
	cout << endl;
}
void Kvadrat::Vvod2()
{
	cout << endl;
	cout << "Ввод параметров квадрата";
	cout << endl;
	cout << "Координаты центра";
	cout << endl;
	cout << " cx=";
	cin >> cx;
	cout << " cy=";
	cin >> cy;
	cout << "Вектор от центра до вершин";
	cout << endl;
	cout << " ax=";
	cin >> ax;
	cout << " ay=";
	cin >> ay;
}

void Priam::Vvod3()
{
	cout << endl;
	cout << "Ввод параметров прямоугольника";
	cout << endl;
	cout << "Координаты центра";
	cout << endl;
	cout << " cx=";
	cin >> cx;
	cout << " cy=";
	cin >> cy;
	cout << "Вектор от центра до вершины";
	cout << endl;
	cout << " ax=";
	cin >> ax;
	cout << " ay=";
	cin >> ay;
}

void Krug::Vivod1()
{
	cout << "Параметры фигуры";
	cout << endl;
	cout << "cx=" << cx << " cy=" << cy << " r=" << r;
	cout << endl;
}

void Kvadrat::Vivod2()
{
	cout << "Параметры фигуры";
	cout << endl;
	cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
	cout << endl;
}

void Priam::Vivod3()
{
	cout << "Параметры фигуры";
	cout << endl;
	cout << "cx=" << cx << " cy=" << cy << " ax=" << ax << " ay=" << ay;
	cout << endl;
}


void Krug::Perem1()
{
	int sx, sy, ax, ay;
	cout << "Введите координаты смещения фигуры ";
	cout << endl;
	cout << "Смещение по X= ";
	cin >> sx;
	cout << "Смещение по Y= ";
	cin >> sy;
	cx = cx + sx; cy = cy + sy;
}

void Kvadrat::Perem2()
{
	int sx, sy;
	cout << "Введите координаты смещения фигуры ";
	cout << endl;
	cout << "Смещение по X= ";
	cin >> sx;
	cout << "Смещение по Y= ";
	cin >> sy;
	cx = cx + sx; cy = cy + sy;
	ax = ax + sx; ay = ay + sy;
}
void Priam::Perem3()
{
	int sx, sy;
	cout << "Введите координаты смещения фигуры ";
	cout << endl;
	cout << "Смещение по X= ";
	cin >> sx;
	cout << "Смещение по Y= ";
	cin >> sy;
	cx = cx + sx; cy = cy + sy;
	ax = ax + sx; ay = ay + sy;
}

void Krug::Izm_raz1()
{
	double k;
	cout << "Коэффициент изменения радиуса круга= ";
	cout << endl;
	cin >> k;
	r = r * k;
}

void Kvadrat::Izm_raz2()
{
	double k;
	cout << "Коэффициент изменения расстояния до вершины квадрата= ";
	cout << endl;
	cin >> k;
	ax = ax - cx;
	ay = ay - cy;
	ax = ax * k;
	ay = ay * k;
	ax = ax + cx;
	ay = ay + cy;
}

void Priam::Izm_raz3()
{
	double k;
	cout << "Коэффициент изменения расстояния до вершины прямоугольника= ";
	cout << endl;
	cin >> k;
	ax = ax - cx;
	ay = ay - cy;
	ax = ax * k;
	ay = ay * k;
	ax = ax + cx;
	ay = ay + cy;
}

void Kvadrat::Vrash2()
{
	double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
	cout << "Угол поворота фигуры ";
	cin >> f;
	const double M_PI = 3.14;
	f = f * M_PI / 180;
	ax = ax - cx;
	ay = ay - cy;
	co = cos(f);
	si = sin(f);
	axn1 = ax * co;
	axn2 = ay * si;
	axn = axn1 - axn2;
	ayn1 = ax * si;
	ayn2 = ay * co;
	ayn = ayn1 + ayn2;
	ax = axn + cx;
	ay = ayn + cy;
}
void Priam::Vrash3()
{
	double f, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;
	cout << "Угол поворота фигуры ";
	cin >> f;
	const double M_PI = 3.14;
	f = f * M_PI / 180;
	ax = ax - cx;
	ay = ay - cy;
	co = cos(f);
	si = sin(f);
	axn1 = ax * co;
	axn2 = ay * si;
	axn = axn1 - axn2;
	ayn1 = ax * si;
	ayn2 = ay * co;
	ayn = ayn1 + ayn2;
	ax = axn + cx;
	ay = ayn + cy;
}