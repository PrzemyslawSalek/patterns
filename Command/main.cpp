#include <iostream>
#include <map>

using namespace std;

class Paladyn {
public:
    void uderz() {
        cout << "Uderzenie z miecza!" << endl;
    }

    void skok() {
        cout << "Skok przed siebie!" << endl;
    }

    void czar() {
        cout << "Kula ognia!" << endl;
    }
};

class Command {
public:
    virtual void wykonaj() = 0;
};

class C_Uderz : public Command {
    Paladyn *p;
public:
    C_Uderz(Paladyn *p) : p(p) {}

    void wykonaj() {
        if(p) p->uderz();
    }

};

class C_Skok : public Command {
    Paladyn *p;
public:
    C_Skok(Paladyn *p) : p(p) {}

    void wykonaj() {
        if(p) p->skok();
    }
};

class C_Czar : public Command {
    Paladyn *p;
public:
    C_Czar(Paladyn *p) : p(p) {}

    void wykonaj() {
        if(p) p->czar();
    }
};

int main() {

    Paladyn *paladyn = new Paladyn;

    map<char, Command*> mapa;
    mapa['a'] = new C_Uderz(paladyn);
    mapa['s'] = new C_Skok(paladyn);
    mapa['d'] = new C_Czar(paladyn);

    char key;

    cout << "Dostepne przyciski:" << endl;
    cout << "'a' - uderzenie" << endl << "'s' - skok" << endl;
    cout << "'d' - czar" << endl << "'f' - wyjscie" << endl;

    while(true) {
        cin >> key;
        if(key == 'f') break;
        mapa[key]->wykonaj();
    }

    delete paladyn;

    return 0;
}
