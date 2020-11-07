#include "Protein.h"
#include <fstream>
#include <sstream>

Protein::Protein() {
    this->list_ = new listaa;
    this->Head = NULL;
    this->Tail = NULL;
    this->size = 0;

    this->iterator.first = 0;
    this->iterator.second = this->list_->field;
}


Protein::Protein(const Protein& p) {
    this->Head = NULL;
    this->Tail = NULL;

    listaa *temp = p.Head;
    while(temp != 0) {
        addTail(temp->field);
        temp = temp->next;
    }

    this->iterator = p.iterator;
    this->size = p.size;
}


int Protein::addElem(ProteinogenicAminoAcid &paa, const int &pos) {
    if (!(paa.getName()=="")) {
        if(pos == this->size+1) { // Добавление в конец списка
            addTail(paa);

            return 0;
        } else if(pos == 1) { // Добавление в начало списка
            addHead(paa);

            return 0;
        }
        // Добавление в произвольное место, кроме начало и конца списка
        int i = 1;
        listaa * Ins = Head;
        while(i < pos) { Ins = Ins->next; i++;}

        listaa * PrevIns = Ins->prev;
        listaa * temp = new listaa;
        temp->field = paa;

        if(PrevIns != 0 && this->size != 1)
            PrevIns->next = temp;

        temp->next = Ins;
        temp->prev = PrevIns;
        Ins->prev = temp;

        iterator.first++;
        this->iterator.second = paa;
        this->size++;
        return 0;
    }
    return 1;
}

int Protein::addHead(ProteinogenicAminoAcid &paa) {
    if (!(paa.getName()=="")) {
        listaa * temp = new listaa;
        temp->prev = 0;
        temp->field = paa;
        temp->next = Head;
        if(Head != 0) Head->prev = temp;

        // Если элемент первый, то он одновременно и голова и хвост
        if(this->size == 0) Head = Tail = temp;
        else Head = temp; // иначе новый элемент - головной

        iterator.first++;
        this->iterator.second = paa;
        this->size++;

        return 0;
    }
    return 1;
}

int Protein::addTail(ProteinogenicAminoAcid &paa) {
    if (!(paa.getName()=="")) {
        listaa *temp = new listaa;
        temp->next = NULL;
        temp->field = paa;

        if (this->Head != NULL) {
            temp->prev = this->Tail;
            this->Tail->next = temp;
            this->Tail = temp;
        } else {
            temp->prev = NULL;
            this->Head = this->Tail = temp;
        }

        iterator.first++;
        this->iterator.second = paa;
        this->size++;
        return 0;
    }
    return 1;
}

int Protein::remove(const int &index) {
    if ((index == 1) and (this->Head->next)) { //Если удаляем первый, но есть и другие
        listaa *temp = this->Head;
        this->Head = this->Head->next;
        this->Head->prev = NULL;
        delete temp;
        this->size--;
        return 0;
    } else if ((index == 1) and (this->Head == this->Tail)) { //Если удаляем первый, но в списке только 1 элемент
        this->Head->next = NULL;
        this->Head = NULL;
        delete this->Head;
        this->size = 0;
        return 0;
    }

    //Также может быть, что удаляемый элемент является последним элементом списка
    if (index==this->size){
        listaa *temp = this->Tail;
        this->Tail = this->Tail->prev;
        this->Tail->next = NULL;
        delete temp;
        this->size--;
        return 0;
    }

    //Если же удаляемый элемент лежит где-то в середине списка, то тогда его можно удалить
    listaa *temp = this->Head, *temp2; //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные
    for (int i=0; i<index-1; i++) temp = temp->next;
    temp2 = temp;
    temp2->prev->next = temp->next;
    temp2->next->prev = temp->prev;
    delete temp;

    if (this->iterator.first >= this->size)
                this->iterator.first = this->size - 1;
    for (int i=0; i<this->iterator.first-1; i++) this->list_ = this->list_->next;
    this->iterator.second = this->list_->field;
    this->size--;
    return 0;
}

int Protein::clean() {
    while (this->Head) {
        this->Tail=this->Head->next;
        delete this->Head;
        this->Head=this->Tail;
    }
    this->list_ = new listaa;
    this->Head = NULL;
    this->Tail = NULL;
    this->size = 0;
    return 0;
}

int Protein::getSize() {
    return this->size;
}

void Protein::setIteratorIndex(int index) {
    if (this->iterator.first != index && index < this->size+1 && index >= 0){
        this->iterator.first = index;

        int i=0;
        listaa * temp = Head;
        while(i != index-1) { temp = temp->next; i++;}

        this->iterator.second = temp->field;
    }
}

void Protein::setIteratorValue(ProteinogenicAminoAcid paa) {
    if ((typeid(paa).name()=="20NonstandardAminoAcid")||((paa.getSymbol()>64)&&(paa.getSymbol()<91))) {
        int i=0;
        listaa * temp = Head;
        while(i != getIteratorIndex()-1) { temp = temp->next; i++;}
        temp->field = paa;
        this->iterator.second = paa;
    }
}

int Protein::getIteratorIndex() {
    return this->iterator.first;
}

ProteinogenicAminoAcid Protein::getIteratorValue() {
    return this->iterator.second;
}

int Protein::fromFile(const string &fname) {
    ifstream file(fname);

    if(this->size>0) {
        this->clean();
        this->iterator.first=0;
    }

    if (file.is_open()) {
        string line;
        while(getline(file, line)) {
            istringstream iss(line);
            string name = "";
            char symbol = '\0';
            string token;
            int i = 0;
            while (getline(iss, token, ' ')){
                if (i == 0) name = token;
                if (i == 1) symbol = char(token.c_str()[0]);
                i++;
            }
            if (symbol == '\0'){
                NonstandardAminoAcid naa(name);
                this->addTail(naa);
            } else {
                ProteinogenicAminoAcid paa(name, symbol);
                if (!(paa.getName() == "" && paa.getSymbol() == '\0') && (paa.getSymbol()>64)&&(paa.getSymbol()<91)) this->addTail(paa);
            }
        }
        file.close();
    }
    return 0;
}

int Protein::toFile(const string &fname) {
    ofstream fout(fname);

    for (int i = 1; i < int(this->size+1); i++){
        this->setIteratorIndex(i);
        fout <<this->getIteratorValue().getName() << " " << this->getIteratorValue().getData("symbol")<< endl;
    }
    fout.close();
    return 0;
}

// сложение двух белков с пересечением
Protein Protein::operator + (const Protein& p2) { //p2 - второй белок, начало которого пересекаем с концом this белка
   Protein Result(*this); // List Result = *this;

   listaa * tempR = Result.Head;
   listaa * tempL = p2.Head;

   while(tempR != 0) {
       if (tempR->field.getName()==tempL->field.getName() && tempR->field.getSymbol()==tempL->field.getSymbol()) {
           listaa * tempR2 = tempR;
           listaa * tempL2 = tempL;

           while(tempR2 != 0 && tempL2 != 0 && tempR2->field.getName()==tempL2->field.getName()&&tempR2->field.getSymbol()==tempL2->field.getSymbol()) {
               tempR2 = tempR2->next;
               tempL2 = tempL2->next;

           }

           if (tempR2 == 0 && tempL2 != 0) {
               tempL = tempL2;
               while(tempL!=0) {
                   Result.addTail(tempL->field);
                   tempL = tempL->next;
               }
               return Result;
           } else if (tempR2 == 0 && tempL2 == 0) return Result;
           else tempR = tempR2;
       } else tempR = tempR->next;
   }

   // Добавляем во временный список оставшиеся элементы второго списка (после пересечения)
   while(tempL != 0) {
      Result.addTail(tempL->field);
      tempL = tempL->next;
   }

   return Result;
}

bool Protein::operator == (const Protein& L) {
   // Сравнение по количеству
   if(this->size != L.size)
      return false;

   listaa *t1, *t2;
   t1 = Head;
   t2 = L.Head;

   // Сравнение по содержанию
   while(t1 != 0) {
      // Сверяем данные, которые находятся на одинаковых позициях
      if(t1->field.getName() != t2->field.getName() && t1->field.getSymbol()!=t2->field.getSymbol())
          return false;

      t1 = t1->next;
      t2 = t2->next;
   }

   return true;
}
