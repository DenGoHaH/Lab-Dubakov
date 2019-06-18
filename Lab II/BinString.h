// HexString.h
#include <string>
#include "AString.h"

const std::string alph = "01";
bool IsBinStrVal(std::string);
class BinString : public AString {
public:
	BinString(std::string _name) : name(_name) {};
	BinString(std::string, std::string);
	const std::string& GetName() const { return name; };
	const std::string& GetVal() const { return val; };
	int GetSize() const { return val.size(); };
private:
	std::string name;
	std::string val;
};