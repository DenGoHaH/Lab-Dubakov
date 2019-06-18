#include <string>
using namespace std;

class PRICE
{
public:
	string Product() const { return a_product; }
	string Shop() const { return a_shop; }
	int Price() const { return a_price; }
	friend istream& operator >>(istream&, PRICE&);
	friend ostream& operator <<(ostream&, const PRICE&);
private:
	string a_product; // товар
	string a_shop; // магазин
	int a_price; // цена
};

std::istream& operator >>(std::istream& in, PRICE& obj)
{
	in >> obj.a_product;
	in >> obj.a_shop;
	in >> obj.a_price;
	return in;
}

std::ostream& operator <<(std::ostream& out, const PRICE& obj)
{
	out << obj.a_product << ' ';
	out << obj.a_shop << ' ';
	out << obj.a_price << ' ';
	return out;
}