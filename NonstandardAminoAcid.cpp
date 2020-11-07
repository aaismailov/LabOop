#include "NonstandardAminoAcid.h"
#include "ProteinogenicAminoAcid.h"

using namespace std;

NonstandardAminoAcid::NonstandardAminoAcid() {}
NonstandardAminoAcid::NonstandardAminoAcid(const string &name): ProteinogenicAminoAcid(name, '\0') {}
NonstandardAminoAcid::NonstandardAminoAcid(const NonstandardAminoAcid& naa): ProteinogenicAminoAcid(naa) {}

string NonstandardAminoAcid::getData(const string &type) const {
    if (type == "name")
        return this->getName();
    return " ";
}
