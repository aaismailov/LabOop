#ifndef NONSTANDARDAMINOACID_H
#define NONSTANDARDAMINOACID_H

#include <iostream>
#include "ProteinogenicAminoAcid.h"

using namespace std;

class NonstandardAminoAcid: public ProteinogenicAminoAcid
{
public:
    NonstandardAminoAcid();
    NonstandardAminoAcid(const string &name);
    NonstandardAminoAcid(const NonstandardAminoAcid& naa);

    string getData(const string &type) const override;
};

#endif // NONSTANDARDAMINOACID_H
