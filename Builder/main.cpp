#include <iostream>

using namespace std;

class Przeciwnik {
    string nazwa;
    int sila;
    int zycie;
public:
    void setN(string n) {
        nazwa = n;
    }

    void setS(int s) {
        sila = s;
    }

    void setZ(int z) {
        zycie = z;
    }

    void pokaz() {
        cout << "Nazwa: " << nazwa << endl;
        cout << "Sila: " << sila << endl;
        cout << "Zycie: " << zycie << endl;
    }
};

class PrzeciwnikBuilder {
public:
    virtual void ustawNazwe() = 0;
    virtual void ustawSile() = 0;
    virtual void ustawZycie() = 0;
    virtual Przeciwnik* zwroc() = 0;
    virtual ~PrzeciwnikBuilder() {}
};

class Strzyga : public PrzeciwnikBuilder {
    Przeciwnik* p;
public:
    Strzyga() {
        p = new Przeciwnik;
    }

    void ustawNazwe() {
        p->setN("Strzyga");
    }

    void ustawSile() {
        p->setS(50);
    }

    void ustawZycie() {
        p->setZ(500);
    }

    Przeciwnik* zwroc() {
        return p;
    }

    ~Strzyga() {
        delete p;
    }
};

class PrzeciwnikDirector {
public:
    void stworz(PrzeciwnikBuilder *p) {
        p->ustawSile();
        p->ustawNazwe();
        p->ustawZycie();
    }
};

int main() {

    PrzeciwnikDirector *pd = new PrzeciwnikDirector;
    PrzeciwnikBuilder *pb = new Strzyga;

    pd->stworz(pb);

    Przeciwnik *p = pb->zwroc();
    p->pokaz();

    delete pd;
    delete pb;
    delete p;

    return 0;
}
