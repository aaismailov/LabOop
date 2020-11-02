#ifndef NONSTANDARDAMINOACID_H
#define NONSTANDARDAMINOACID_H

#include <iostream>
#include "ProteinogenicAminoAcid.h"

using namespace std;

class NonstandardAminoAcid: public ProteinogenicAminoAcid
{
public:
    NonstandardAminoAcid();
    NonstandardAminoAcid(string name);
    NonstandardAminoAcid(const NonstandardAminoAcid& naa);
};

#endif // NONSTANDARDAMINOACID_H
