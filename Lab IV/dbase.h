#include "price.h"
using namespace std;

class dbase
{
public:
	dbase(int);
	~dbase();
	void Vvod();
	void Vivod();
	void Poisk(const string poisk);
private:
	PRICE* a_price;
	int Col;
};

dbase::dbase(int number) 
	: a_price(new PRICE[number]) 
	, Col(number) 
{}
dbase::~dbase() 
{ 
	if (a_price) delete[] a_price; 
}

void dbase::Vvod()
{
	cout << "Enter the product name, shop, price" << endl;
	for (int i = 0; i < Col; ++i)
	{
		cout << (i + 1) << ". ";
		cin >> a_price[i];
	}

	for (int i = 0; i < Col - 1; ++i)
	{
		for (auto j = 0; j < Col - i - 1; ++j)
		{
			if (a_price[j].Product() > a_price[j + 1].Product())
			{
				PRICE temp = a_price[j];
				a_price[j] = a_price[j + 1];
				a_price[j + 1] = temp;
			}
		}
	}
}

void dbase::Vivod()
{
	cout << "\nInfo:" << endl;
	for (auto i = 0; i < Col; ++i)
	{
		cout << (i + 1) << ". " << a_price[i] << endl;
	}
}

void dbase::Poisk(const string poisk)
{
	int a = 0;
	for (int i = 0; i < Col; ++i)
	{
		if (a_price[i].Product() == poisk)
		{
			cout << a_price[i].Product() << " " << a_price[i].Shop() << " " << a_price[i].Price() << endl;
			a++;
		}
	}

	if (a == 0)
	{
		cout << "No found" << endl;
	}
}