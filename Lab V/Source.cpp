#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	ifstream ifs("in.txt");
	if (ifs.is_open())
	{
		string sword, slongest;
		size_t counter;
		char c;
		for (counter = 0; ifs; )
		{
			ifs.get(c);
			if (isalpha(c) && ifs)
				sword += c;
			else
			{
				if (sword.size() > slongest.size())
				{
					slongest = sword;
					counter = 1;
				}
				else if (sword == slongest)
					++counter;
				sword.clear();
			}
		}
		cout << slongest << " - " << counter << endl;
		ifs.close();
	}
	else
		cerr << "Нет Файла Ввода" << endl;
	system("pause");
	return 0;
}