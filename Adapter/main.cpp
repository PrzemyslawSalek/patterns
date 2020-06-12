#include <iostream>

using namespace std;

class Usluga {
public:
    virtual void a() = 0;
    virtual void b() = 0;
};

class Klient : public Usluga {
public:
    void a() {
        cout << "Metoda a() klienta" << endl;
    }

    void b() {
        cout << "Metoda b() klienta" << endl;
    }
};

class Niekompatybilna {
public:
    void d() {
        cout << "Metoda d() niekompatybilnej" << endl;
    }

    void e() {
        cout << "Metoda e(0 niekompatybilnej" << endl;
    }
};

class Adapter : public Usluga, public Niekompatybilna {
public:
    void a() {
        d();
    }

    void b() {
        e();
    }
};

int main() {

    Usluga *k = new Klient;
    Usluga *n = new Adapter;

    n->a();
    k->a();

    return 0;
}
