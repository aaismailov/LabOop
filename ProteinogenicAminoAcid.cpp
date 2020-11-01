#include "ProteinogenicAminoAcid.h"

using namespace std;

ProteinogenicAminoAcid::ProteinogenicAminoAcid(string name, char symbol) {
    this->name = name;
    if((symbol>64)&&(symbol<91)) this->symbol = symbol;
    else this->symbol = '\0';
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid(const ProteinogenicAminoAcid& paa) {
    this->name = paa.name;
    this->symbol = paa.symbol;
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid() {
    this->name = "";
    this->symbol = '\0';
}

string ProteinogenicAminoAcid::getName() {
    return this->name;
}

void ProteinogenicAminoAcid::setName(string newName) {
    this->name = newName;
}

char ProteinogenicAminoAcid::getSymbol() {
    return this->symbol;
}

void ProteinogenicAminoAcid::setSymbol(char newSymbol) {
    if((newSymbol>64)&&(newSymbol<91)) this->symbol = newSymbol;
    else this->symbol = '\0';
}

