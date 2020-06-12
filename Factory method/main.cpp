#include <iostream>

using namespace std;

class Samochod {
public:
    virtual void jedz() {
        cout << "Samochod robi brrrum" << endl;
    }
    virtual ~Samochod() {}
};

class Fabryka {
    virtual Samochod* zbuduj() = 0;
public:
    void malowanie() {
        cout << "Czas na malowanko! Pssss ss" << endl;
    }
};

class AudiA4 : public Samochod {
public:
    void model() {
        cout << "To Audi A4" << endl;
    }
};

class AudiB5 : public Samochod {
public:
    void pojemnosc() {
        cout << "Lepiej zebys nie wiedzial" << endl;
    }
};

class FabrykaAudiA4 : public Fabryka {
public:
    Samochod* zbuduj() {
        return new AudiA4;
    }
};

class FabrykaAudiB5 : public Fabryka {
public:
    Samochod* zbuduj() {
        return new AudiB5;
    }
};

int main() {

    FabrykaAudiA4 faudi4;
    FabrykaAudiB5 faudi5;

    string model;
    cout << "Podaj model (A4 / B5):" << endl;
    cin >> model;
    if(model == "A4") {
        Samochod* s1 = faudi4.zbuduj();
        s1->jedz();
    } else {
        Samochod* s2 = faudi5.zbuduj();
        s2->jedz();
    }

    return 0;
}
