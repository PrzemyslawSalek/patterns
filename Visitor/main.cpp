#include <iostream>

using namespace std;

class Strzyga;
class Utopiec;
class Przeciwnik;
class Atak;

class Przeciwnik {
protected:
    string nazwa;
public:
    virtual void accept(Atak*) = 0;
    virtual void pokaz() = 0;
    virtual ~Przeciwnik() {}
};

class Atak {
public:
    virtual void visit(Strzyga*) = 0;
    virtual void visit(Utopiec*) = 0;
    virtual ~Atak() {}
};

class Strzyga : public Przeciwnik {
    int poziom;
public:
    Strzyga() {
        nazwa = "Strzyga";
        poziom = 68;
    }

    void accept(Atak* a) {
        a->visit(this);
    }

    void pokaz() {
        cout << "Nazwa: " << nazwa << " Poziom: " << poziom << endl;
    }
};

class Utopiec : public Przeciwnik {
    int wiek;
public:
    Utopiec() {
        nazwa = "Utopiec";
        wiek = 50;
    }

    void accept(Atak* a) {
        a->visit(this);
    }

    void pokaz() {
        cout << "Nazwa: " << nazwa << " Wiek: " << wiek << endl;
    }
};

class CichyAtak : public Atak {
public:
    void visit(Strzyga *s) {
        cout << "Smierc sie zbliza..." << endl;
        s->pokaz();
    }

    void visit(Utopiec* u) {
        cout << "Slyszales ten szmer?" << endl;
        u->pokaz();
    }
};

class GlosnyAtak : public Atak {
public:
    void visit(Strzyga *s) {
        cout << "Uwazaj! To..." << endl;
        s->pokaz();
    }

    void visit(Utopiec* u) {
        cout << "Bij! Zabij!" << endl;
        u->pokaz();
    }
};

int main() {
    Przeciwnik* p1 = new Strzyga;
    Przeciwnik *p2 = new Utopiec;

    Atak *ca = new CichyAtak;
    p1->accept(ca);
    p2->accept(ca);

    cout << endl;

    Atak *ga = new GlosnyAtak;
    p1->accept(ga);
    p2->accept(ga);

    delete p1;
    delete p2;
    delete ca;
    delete ga;

    return 0;
}
