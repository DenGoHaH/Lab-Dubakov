#include <string>
#include <iostream>

using namespace std;
template <class T>
class List
{
private:
	struct node
	{
		T item;
		node* next;
		node* prev;
		node(T x, node* p)
		{
			item = x;
			next = 0;
			prev = p;
		}
	}typedef node, *link;
	link head;
	link end;
public:
	class Empty
	{
	};
	class NotElement
	{
	};
	List(T s)
	{
		head = new node(s, 0);
		end = new node(s, head);
		head->next = end;
	}
	void add(T it)
	{
		link newnode = new node(it, 0);
		end->prev->next = newnode;
		newnode->prev = end->prev;
		end->prev = newnode;
		newnode->next = end;
	}
	void remove(T it)
	{
		if (head->next == end && end->prev == head) throw Empty();
		bool p = false;
		for (link l = head->next; l != end; l = l->next)
		{
			if (l->item == it)
			{
				l->prev->next = l->next;
				l->next->prev = l->prev;
				p = true;
			}
		}
		if (!p) throw NotElement();
	}
	void show()
	{
		if (head->next == end && end->prev == head) throw Empty();
		for (link l = head->next; l != end; l = l->next)
			cout << l->item << " ";
		cout << endl;
	}

};
int main()
{
	setlocale(0, "Rus");
	while (true)
	{
		int t;
		system("cls");
		cout << "1) Список для типа String" << endl;
		cout << "2) Список для типа int" << endl;
		cout << "3) Список для типа double" << endl;
		cout << "0) Выход" << endl;
		cin >> t;
		if (t == 0) break;
		switch (t)
		{
		case 1:
		{
			cout << "Реализация списка для типа string" << endl;
			List<string> mylist("0");
			while (true)
			{
				system("cls");
				int r;
				cout << "1) Добавить элемент" << endl;
				cout << "2) Удалить элемент по значению" << endl;
				cout << "3) Показать список" << endl;
				cout << "0) Выход" << endl;
				cin >> r;
				if (r == 0) { break; }
				switch (r)
				{
				case 1:
				{
					string st;
					cout << "Введите элемент" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					string st;
					cout << "Введите значение элемента" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<string>::Empty)
					{
						cout << "Ошибка попытка удаления из пустого списка" << endl;
					}
					catch (List<string>::NotElement)
					{
						cout << "Удаляемого элемента не существует" << endl;
					}
					system("pause");
					continue;
				}
				case 3:
				{
					try
					{
						mylist.show();
					}
					catch (List<string>::Empty)
					{
						cout << "Список пуст" << endl;
					}
					system("pause");
					continue;
				}
				}
			}
			continue;
		}
		case 2:
		{
			cout << "Реализация списка для типа int" << endl;
			List<int> mylist(0);
			while (true)
			{
				system("cls");
				int r;
				cout << "1) Добавить элемент" << endl;
				cout << "2) Удалить элемент по значению" << endl;
				cout << "3) Показать список" << endl;
				cout << "0) Выход" << endl;
				cin >> r;
				if (r == 0) { mylist.~List(); break; }
				switch (r)
				{
				case 1:
				{
					int st;
					cout << "Введите элемент" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					int st;
					cout << "Введите значение элемента" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<int>::Empty)
					{
						cout << "Ошибка попытка удаления из пустого списка" << endl;
					}
					catch (List<int>::NotElement)
					{
						cout << "Удаляемого элемента не существует" << endl;
					}
					system("pause");
					continue;
				}
				case 3:
				{
					try
					{
						mylist.show();
					}
					catch (List<int>::Empty)
					{
						cout << "Список пуст" << endl;
					}
					system("pause");
					continue;
				}
				}
			}
			continue;
		}
		case 3:
		{
			cout << "Реализация списка для типа double" << endl;
			List<double> mylist(0.0);
			while (true)
			{
				system("cls");
				int r;
				cout << "1) Добавить элемент" << endl;
				cout << "2) Удалить элемент по значению" << endl;
				cout << "3) Показать список" << endl;
				cout << "0) Выход" << endl;
				cin >> r;
				if (r == 0) { mylist.~List(); break; }
				switch (r)
				{
				case 1:
				{
					double st;
					cout << "Введите элемент" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					double st;
					cout << "Введите значение элемента" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<double>::Empty)
					{
						cout << "Ошибка попытка удаления из пустого списка" << endl;
					}
					catch (List<double>::NotElement)
					{
						cout << "Удаляемого элемента не существует" << endl;
					}
					system("pause");
					continue;
				}
				case 3:
				{
					try
					{
						mylist.show();
					}
					catch (List<double>::Empty)
					{
						cout << "Список пуст" << endl;
					}
					system("pause");
					continue;
				}
				}
			}
			continue;
		}

		}
	}
	return 0;
}