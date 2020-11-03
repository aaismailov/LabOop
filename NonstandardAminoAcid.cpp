#include "NonstandardAminoAcid.h"
#include "ProteinogenicAminoAcid.h"

using namespace std;

NonstandardAminoAcid::NonstandardAminoAcid() {}
NonstandardAminoAcid::NonstandardAminoAcid(string name): ProteinogenicAminoAcid(name, '\0') {}
NonstandardAminoAcid::NonstandardAminoAcid(const NonstandardAminoAcid& naa): ProteinogenicAminoAcid(naa) {}
