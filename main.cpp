#include "basewindow.h"
#include "firstwindow.h"
#include <iostream>
#include <ProteinogenicAminoAcid.h>
#include <NonstandardAminoAcid.h>
#include <Protein.h>
#include <cassert>


#include <QApplication>

using namespace std;

int toScreen(Protein p) {
    for (int i = 1; i < int(p.getSize()+1); i++) {
        p.setIteratorIndex(i);
        cout << i << ") Name: " << p.getIteratorValue().getName() << " Symbol: " << p.getIteratorValue().getSymbol()<< endl;
    }
    cout<<"\n"<<endl;
    return 0; // для проверки через assert
}
int main(int argc, char *argv[])
{
    cout<<"DTGUID_________________________________"<<endl;
    // Test ProteinogenicAminoAcid
    ProteinogenicAminoAcid paa1;
    assert(paa1.getName()=="");
    assert(paa1.getSymbol()=='\0');

    ProteinogenicAminoAcid paa2("Glycine", 'G');
    assert(paa2.getName()=="Glycine");
    assert(paa2.getSymbol()=='G');

    ProteinogenicAminoAcid paa3(paa2);
    assert(paa3.getName()==paa2.getName());
    assert(paa3.getSymbol()==paa2.getSymbol());

    paa1.setName("Alanine");
    assert(paa1.getName()=="Alanine");
    paa1.setSymbol('A');
    assert(paa1.getSymbol()=='A');

    // Test collection Protein

    // Тестирование конструктора по умолчанию
    Protein pDefault;
    assert(pDefault.getIteratorIndex()==0);
    assert(pDefault.getIteratorValue().getName()=="" && pDefault.getIteratorValue().getSymbol()=='\0');
    assert(pDefault.getSize()==0);

    // Тестирование конструктора копирования
    ProteinogenicAminoAcid paa4("Valine", 'V');
    pDefault.addElem(paa4, 1);
    Protein pCopy(pDefault);
    assert(pCopy == pDefault); //Проверка двух коллекций на равенство
    assert(pCopy.getIteratorIndex()==pDefault.getIteratorIndex());
    assert(pCopy.getIteratorValue().getName()==pDefault.getIteratorValue().getName() && pCopy.getIteratorValue().getSymbol()==pDefault.getIteratorValue().getSymbol());
    assert(pCopy.getSize()==pDefault.getSize());

    // Тестирование методов добавления и удаления объектов
    ProteinogenicAminoAcid paa5("Leucine", 'L');
    pDefault.addElem(paa5, 2);
    assert(pDefault.getIteratorValue().getName()=="Leucine" && pDefault.getIteratorValue().getSymbol()=='L');
    assert(pDefault.getSize() == 2);
    pDefault.remove(2);
    pDefault.setIteratorIndex(1);
    assert(pDefault.getIteratorValue().getName()=="Valine" && pDefault.getIteratorValue().getSymbol()=='V');
    assert(pDefault.getSize() == 1);
    pDefault.addElem(paa2, 1);
    assert(pDefault.getIteratorValue().getName()=="Glycine" && pDefault.getIteratorValue().getSymbol()=='G');
    assert(pDefault.getSize() == 2);
    pDefault.remove(1);
    pDefault.remove(1);
    assert(pDefault.getSize() == 0);

    // Тестирование метода доступа к элементу: вывода на экран всех хранимых объектов
    pDefault.addElem(paa5, 1);
    pDefault.addElem(paa4, 1);
    pDefault.addElem(paa2, 1);
    assert(toScreen(pDefault)==0);

    // Тестирование метода удаления всех хранимых объектов
    pDefault.clean();
    assert(pDefault.getSize() == 0);

    // Тестирование методов записи в файл и чтения файла
    ProteinogenicAminoAcid paa6("Proline",'P');
    ProteinogenicAminoAcid paa7("Serine", 'S');
    Protein pToFile;
    pToFile.addElem(paa6, 1);
    pToFile.addElem(paa7, 2);
    assert(pToFile.toFile("C:\\Qt\\Projects\\oop1\\BaseWindow\\to.txt")==0);
    toScreen(pToFile);
    Protein pFromFile;
    assert(pFromFile.fromFile("C:\\Qt\\Projects\\oop1\\BaseWindow\\to.txt")==0);
    toScreen(pFromFile);
    assert(pFromFile == pToFile); //Проверка на равенство записанной в файл и полученной из файла коллекций

    // Тестирование операции сложения, возвращающей результат сложения (с пересечением) двух белков (условие задачи)
    ProteinogenicAminoAcid paa8("Isoleucine",'I');
    NonstandardAminoAcid naa4("Citrulline");
    ProteinogenicAminoAcid paa9("Methionine", 'M');
    ProteinogenicAminoAcid paa10("Threonine", 'T');
    ProteinogenicAminoAcid paa11("Cysteine", 'C');
    Protein pFirst; // IMT
    pFirst.addElem(paa8, 1);
    toScreen(pFirst);
    pFirst.addElem(paa9, 2);
    toScreen(pFirst);
    pFirst.addTail(naa4);
    cout<<"-------"<<paa9.getName()<<endl;
    //pFirst.setIteratorIndex(1);
    cout<<pFirst.getIteratorValue().getName()<<endl;
    toScreen(pFirst);
    cout<<pFirst.getIteratorValue().getName()<<endl;
    Protein pSecond; // MTC
    pSecond.addElem(paa9, 1);
    cout<<pSecond.getIteratorValue().getName()<<endl;
    // pSecond.addElem(naa4, 2);
    pSecond.addElem(paa11, 2);
    cout<<pSecond.getIteratorValue().getName()<<endl;
    Protein pThird; // CT
    pThird.addElem(paa11, 1);
    // pThird.addElem(naa4, 2);
    // toScreen(pFirst);
    toScreen(pSecond);
    toScreen(pThird);
    assert(toScreen(pFirst+pSecond)==0); // pFirst+pSecond = IMT+MTC = IMTC
    assert(toScreen(pSecond+pThird)==0); // pSecond+pThird = MTC+CT = MTCT
    assert(toScreen(pThird+pFirst)==0); // pThird+pFirst = CT+IMT = CTIMT

    // Test NonstandardAminoAcid
    NonstandardAminoAcid naa1;
    assert(naa1.getName()=="");

    NonstandardAminoAcid naa2("Citrulline");
    assert(naa2.getName()=="Citrulline");

    NonstandardAminoAcid naa3(naa2);
    assert(naa3.getName()==naa2.getName());

    naa1.setName("Desmosine");
    assert(naa1.getName()=="Desmosine");
    cout<<"All tests are passed"<<endl;

    QApplication a(argc, argv);
    BaseWindow w;
    w.show();
    return a.exec();
}
