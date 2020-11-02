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

   // string getName();
  //  void setName(string name);
};

#endif // NONSTANDARDAMINOACID_H
