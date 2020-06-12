#include <iostream>
#include <vector>

using namespace std;

class Rakieta {
protected:
    string nazwa;
    string silniki;
public:
    virtual void wyswietl() = 0;
    virtual void start() = 0;
    virtual void dodaj(Rakieta*) {}

    virtual ~Rakieta() {}
};

class Falcon9 : public Rakieta {
public:
    Falcon9() {
        this->nazwa = "Falcon 9";
        this->silniki = "9xMerlin 1D";
    }

    void wyswietl() {
        cout << "Nazwa: " << nazwa << " Silniki: " << silniki << endl;
    }

    void start() {
        cout << nazwa << " startuje." << endl;
    }

};

class FalconHeavy : public Rakieta {
public:
    FalconHeavy() {
        nazwa = "Falcon Heavy";
        silniki = "3x9xMerlin 1D";
    }

    void wyswietl() {
        cout << "Nazwa: " << nazwa << " Silniki: " << silniki << endl;
    }

    void start() {
        cout << nazwa << " startuje." << endl;
    }
};

class Kompozyt : public Rakieta {
    vector<Rakieta*> kontener;
public:
    Kompozyt() {}

    void wyswietl() {
        for(auto x : kontener) x->wyswietl();
    }

    void start() {
        for(auto x : kontener) x->start();
    }

    void dodaj(Rakieta *r) {
        kontener.push_back(r);
    }

    ~Kompozyt() {
        for(auto x : kontener) delete x;
    }
};


int main() {

    Rakieta *comp = new Kompozyt;

    for(int i = 0; i < 6; i++) {
        comp->dodaj(new Falcon9);
        comp->dodaj(new FalconHeavy);
    }

    cout << "Wywolanie metody wyswietl() na kompozycie: " << endl;
    comp->wyswietl();
    cout << endl;

    cout << "Wywolanie metody start() na kompozycie: " << endl;
    comp->start();

    delete comp;

    return 0;
}
