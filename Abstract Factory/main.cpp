#include <iostream>

using namespace std;

class Jedzenie {
public:
    Jedzenie() {}
};

class Skrzydelka : public Jedzenie {
public:
    Skrzydelka() : Jedzenie() {}
};

class Frytki : public Jedzenie {
public:
    Frytki() : Jedzenie() {}
};

class Napoje {
public:
    Napoje() {}
};

class CocaCola : public Napoje {
public:
    CocaCola() : Napoje() {}
};

class Sok : public Napoje {
public:
    Sok() : Napoje() {}
};

class FabrykaZestaw {
public:
    virtual Jedzenie* zrobJezenie() = 0;
    virtual Napoje* zrobNapoj() = 0;
};

class FrytkiCoca : public FabrykaZestaw {
public:
    Jedzenie* zrobJedzenie() {
        return new Frytki;
    }

    Napoje* zrobNapoj() {
        return new CocaCola;
    }
};

class SkrzydelkaSok : public FabrykaZestaw {
public:
    Jedzenie* zrobJezenie() {
        return new Skrzydelka;
    }

    Napoje* zrobNapoj() {
        return new Sok;
    }
};

class Zestaw {
    FabrykaZestaw *z;
public:
    Zestaw(FabrykaZestaw *z) {
        this->z = z;
    }

    void wydajZestaw() {
        cout << "Zestaw gotowy!" << endl;
    }
};



int main() {

    Zestaw *z1 = new Zestaw(new SkrzydelkaSok);
    z1->wydajZestaw();

    return 0;
}
