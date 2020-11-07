#pragma once
#include <string>
#include "ProteinogenicAminoAcid.h"
#include "NonstandardAminoAcid.h"

struct listaa {
    ProteinogenicAminoAcid field; // поле данных
    struct listaa *next; // указатель на следующий элемент
    struct listaa *prev; // указатель на предыдущий элемент
};

class Protein {
public:
    Protein();
    Protein(const Protein& p);

    int addElem(ProteinogenicAminoAcid &paa, const int &number);
    int addHead(ProteinogenicAminoAcid &paa);
    int addTail(ProteinogenicAminoAcid &paa);

    int remove(const int &index);
    int clean();

    int getSize();

    void setIteratorIndex(int index);
    void setIteratorValue(ProteinogenicAminoAcid paa);
    int getIteratorIndex();
    ProteinogenicAminoAcid getIteratorValue();

    int fromFile(const string &name);
    int toFile(const string &name);

    Protein operator + (const Protein&);
    bool operator == (const Protein&);
private:
    pair<int,ProteinogenicAminoAcid> iterator;
    listaa *list_;
    listaa *Head, *Tail; //Начало и конец списка
    int size;
};
