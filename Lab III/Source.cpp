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
		cout << "1) ������ ��� ���� String" << endl;
		cout << "2) ������ ��� ���� int" << endl;
		cout << "3) ������ ��� ���� double" << endl;
		cout << "0) �����" << endl;
		cin >> t;
		if (t == 0) break;
		switch (t)
		{
		case 1:
		{
			cout << "���������� ������ ��� ���� string" << endl;
			List<string> mylist("0");
			while (true)
			{
				system("cls");
				int r;
				cout << "1) �������� �������" << endl;
				cout << "2) ������� ������� �� ��������" << endl;
				cout << "3) �������� ������" << endl;
				cout << "0) �����" << endl;
				cin >> r;
				if (r == 0) { break; }
				switch (r)
				{
				case 1:
				{
					string st;
					cout << "������� �������" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					string st;
					cout << "������� �������� ��������" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<string>::Empty)
					{
						cout << "������ ������� �������� �� ������� ������" << endl;
					}
					catch (List<string>::NotElement)
					{
						cout << "���������� �������� �� ����������" << endl;
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
						cout << "������ ����" << endl;
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
			cout << "���������� ������ ��� ���� int" << endl;
			List<int> mylist(0);
			while (true)
			{
				system("cls");
				int r;
				cout << "1) �������� �������" << endl;
				cout << "2) ������� ������� �� ��������" << endl;
				cout << "3) �������� ������" << endl;
				cout << "0) �����" << endl;
				cin >> r;
				if (r == 0) { mylist.~List(); break; }
				switch (r)
				{
				case 1:
				{
					int st;
					cout << "������� �������" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					int st;
					cout << "������� �������� ��������" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<int>::Empty)
					{
						cout << "������ ������� �������� �� ������� ������" << endl;
					}
					catch (List<int>::NotElement)
					{
						cout << "���������� �������� �� ����������" << endl;
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
						cout << "������ ����" << endl;
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
			cout << "���������� ������ ��� ���� double" << endl;
			List<double> mylist(0.0);
			while (true)
			{
				system("cls");
				int r;
				cout << "1) �������� �������" << endl;
				cout << "2) ������� ������� �� ��������" << endl;
				cout << "3) �������� ������" << endl;
				cout << "0) �����" << endl;
				cin >> r;
				if (r == 0) { mylist.~List(); break; }
				switch (r)
				{
				case 1:
				{
					double st;
					cout << "������� �������" << endl;
					cin >> st;
					mylist.add(st);
					system("pause");
					continue;
				}
				case 2:
				{
					double st;
					cout << "������� �������� ��������" << endl;
					cin >> st;
					try
					{
						mylist.remove(st);
					}
					catch (List<double>::Empty)
					{
						cout << "������ ������� �������� �� ������� ������" << endl;
					}
					catch (List<double>::NotElement)
					{
						cout << "���������� �������� �� ����������" << endl;
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
						cout << "������ ����" << endl;
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