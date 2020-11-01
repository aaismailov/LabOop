#ifndef PROTEINOGENIC_AMINO_ACID_H
#define PROTEINOGENIC_AMINO_ACID_H

#include <iostream>

using namespace std;

class ProteinogenicAminoAcid
{
public:
    ProteinogenicAminoAcid(string name, char symbol);
    ProteinogenicAminoAcid(const ProteinogenicAminoAcid& paa);
    ProteinogenicAminoAcid();

    string getName();
    void setName(string name);

    char getSymbol();
    void setSymbol(char symbol);

private:
    string name;
    char symbol;
};

#endif // PROTEINOGENICAMINOACID_H
