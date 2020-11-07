#include "ProteinogenicAminoAcid.h"

using namespace std;

ProteinogenicAminoAcid::ProteinogenicAminoAcid() {
    this->name = "";
    this->symbol = '\0';
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid(const string &name, const char &symbol) {
    this->name = name;
    if((symbol>64)&&(symbol<91)) this->symbol = symbol;
    else this->symbol = '\0';
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid(const ProteinogenicAminoAcid& paa) {
    this->name = paa.name;
    this->symbol = paa.symbol;
}

const string& ProteinogenicAminoAcid::getName() const {
    return this->name;
}

void ProteinogenicAminoAcid::setName(const string &newName) {
    this->name = newName;
}

const char& ProteinogenicAminoAcid::getSymbol() const {
    return this->symbol;
}

void ProteinogenicAminoAcid::setSymbol(const char &newSymbol) {
    if((newSymbol>64)&&(newSymbol<91)) this->symbol = newSymbol;
    else this->symbol = '\0';
}

string ProteinogenicAminoAcid::getData(const string &type) const{
    if (type == "name")
        return this->getName();
    if (type == "symbol")
        return std::string(1, this->getSymbol());
    return " ";
}
