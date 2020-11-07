#ifndef PROTEINOGENIC_AMINO_ACID_H
#define PROTEINOGENIC_AMINO_ACID_H
#include <iostream>

using namespace std;

class ProteinogenicAminoAcid {
public:
    ProteinogenicAminoAcid();
    ProteinogenicAminoAcid(const string &name, const char &symbol);
    ProteinogenicAminoAcid(const ProteinogenicAminoAcid& paa);

    const string& getName() const;
    void setName(const string &name);

    const char& getSymbol() const;
    void setSymbol(const char &symbol);

    virtual string getData(const string& type) const;
private:
    string name;
    char symbol;
};

#endif // PROTEINOGENICAMINOACID_H
