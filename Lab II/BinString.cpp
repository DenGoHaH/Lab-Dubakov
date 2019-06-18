// HexString.cpp
#include <iostream>
#include "BinString.h"
using namespace std;

bool IsBinStrVal(string str) {
	for (int i = 0; i < str.size(); ++i)
		if (-1 == alph.find_first_of(str[i]))
			return false;
	return true;
}

BinString::BinString(string _name, string _val) :
	name(_name) {
	if (IsBinStrVal(_val))
		val = _val;
}