#include "NonstandardAminoAcid.h"

using namespace std;

NonstandardAminoAcid::NonstandardAminoAcid(string name) {
    this->name = name;
}

NonstandardAminoAcid::NonstandardAminoAcid(const NonstandardAminoAcid& naa) {
    this->name = naa.name;
}

NonstandardAminoAcid::NonstandardAminoAcid() {
    this->name = "";
}

string NonstandardAminoAcid::getName() {
    return this->name;
}

void NonstandardAminoAcid::setName(string newName) {
    this->name = newName;
}

