#include "NonstandardAminoAcid.h"
#include "ProteinogenicAminoAcid.h"

using namespace std;

NonstandardAminoAcid::NonstandardAminoAcid() {
    //this->setName("");
}

NonstandardAminoAcid::NonstandardAminoAcid(string name): ProteinogenicAminoAcid(name, '\0') {
}

NonstandardAminoAcid::NonstandardAminoAcid(const NonstandardAminoAcid& naa): ProteinogenicAminoAcid(naa) {
    // this->name = naa.name;
}
/*
string NonstandardAminoAcid::getName() {
    return this->getName();
}

void NonstandardAminoAcid::setName(string newName) {
    this->setName(newName);
}
*/
