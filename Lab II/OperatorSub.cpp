// ShowDec.cpp
#include <iostream>
#include "SymbString.h"
#include "OperatorSub.h"
#include <string>
using namespace std;

long inDec(long dest1) {
	int a;
	int b = 0;
	int result = 0;
	while (dest1 != 0) {
		a = dest1 % 10;
		dest1 = dest1 / 10;
		if (b == 0)
			b = 1;
		if (b != 0)
			a *= b;
		result += a;
		b *= 2;
	}
	return result;
}

string inBin(long dest1) {
	long copy, a = 0;
	string str, result;
	while (dest1 != 0) {
		copy = dest1;
		copy = copy / 2;
		a = dest1 % 2;
		dest1 = copy;
		str += to_string(a);
	}
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i];
	}
	return result;
}

void OperatorSub::Operate(AString* pObj) {
	string Value1 = pObj->GetVal(); // ��������� ����������� ������� ���������
	string Value2 = pObj->SubObjValue; // ��������� ����������� ������������ �������� ����������� �������
	cout << Value1 << " - " << Value2 << " = "; // ������� ����������� ��������

	if ((dynamic_cast<SymbString*>(pObj))) { // ���� ��� �������� SymbString
		size_t pos; // ���������� ��� �������� ������� ������� ��������� str2 � str1
		while ((pos = Value1.find(Value2)) != string::npos) { // ���� str2 ������������ � str1
			string before = Value1.substr(0, pos); // "��������" ������ ����
			string after = Value1.substr(pos + Value2.length()); // "��������" ������ ����
			Value1 = before + after; // ����� ������� �������� ����� �� � ����� ��������� str2 � str1
		}
		cout << Value1 << "\n"; // ������� ��������� ���������
	}
	else { // ���� ��� �������� HexString
		long dest1, dest2;
		sscanf(Value1.c_str(), "%dec", &dest1); // ��������� ����������� ������� ������� � �������� ��� (long dest1)
		sscanf(Value2.c_str(), "%dec", &dest2); // ��������� ����������� ������� ������� � �������� ��� (long dest2)
		long k = inDec(dest1);
		long k2 = inDec(dest2);
		long p = k - k2;
		string pa = inBin(p);
		long pi = p - p - p;
		string pa2 = inBin(pi);
		if (k > k2)
			cout << pa << endl; // ������� ��������� ��������� � �������� ������� �������
		else
			cout << "-" << pa2 << endl; // ������� ��������� ��������� � �������� ������� �������
	}
}

OperatorSub operator_sub;