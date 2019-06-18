// Action.cpp
#include <iostream>
#include "Action.h"
#include "BinString.h"
using namespace std;

long Action::GetDecimal(AString* pObj) const {
	if (dynamic_cast<BinString*>(pObj)) {
		long dest;
		string source = pObj->GetVal();
		sscanf(source.c_str(), "%dec", &dest);
		return dest;
	}
	else {
		cout << "Action not supported." << endl;
		return -1;
	}
}