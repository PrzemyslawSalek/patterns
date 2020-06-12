#include <iostream>

using namespace std;

class Drzwi{
public:
    virtual ~Drzwi() {}
    virtual void zamknij() {}
    virtual void otworz() {}
    virtual void zablokuj() {}
    virtual void odblokuj() {}
};

class Okna{
public:
    virtual ~Okna() {}
    virtual void otworz() {}
    virtual void zamknij() {}
};

class Swiatlo{
public:
    virtual ~Swiatlo() {}
    virtual void zapal() {}
    virtual void zgas() {}
};

class Drzwi_front : public Drzwi {
public:
    void zamknij() {
        cout << "Zamykam drzwi frontowe." << endl;
    }
    void otworz() {
        cout << "Otwieram drzwi frontowe." << endl;
    }
    void zablokuj() {
        cout << "Drzwi frontowe zablokowane." << endl;
    }
    void odblokuj() {
        cout << "Drzwi frontowe odblokowane." << endl;
    }
};

class Drzwi_garaz : public Drzwi {
public:
    void zamknij() {
        cout << "Zamykam drzwi garazowe." << endl;
    }
    void otworz() {
        cout << "Otwieram drzwi garazowe." << endl;
    }
    void zablokuj() {
        cout << "Drzwi garazowe zablokowane." << endl;
    }
    void odblokuj() {
        cout << "Drzwi garazowe odblokowane." << endl;
    }
};

class Okna_salon : public Okna{
public:
    void otworz() {
        cout << "Otwieram okna w salonie." << endl;
    }
    void zamknij() {
        cout << "Zamykam okna w salonie." << endl;
    }
};

class Swiatlo_jadalnia : public Swiatlo {
public:
    void zapal() {
        cout << "Zapalam swiatlo w jadalni." << endl;
    }
    void zgas() {
        cout << "Gasze swiatlo z jadalni." << endl;
    }
};

class Obsuluga_domu {
private:
    Drzwi *d_front = new Drzwi_front;
    Drzwi *d_gar = new Drzwi_garaz;
    Okna *o_salon = new Okna_salon;
    Swiatlo *s_jadalnia = new Swiatlo_jadalnia;
public:
    void zamknij_dom() {
        cout << "Zamykanie domu." << endl;
        d_front->zablokuj();
        d_gar->zablokuj();
        o_salon->zamknij();
    }
    void otworz_dom() {
        cout << "Otwieranie domu." << endl;
        d_front->otworz();
        d_gar->otworz();
    }
    void zapal_swiatla() {
        cout << "Zapalanie swiatla." << endl;
        s_jadalnia->zapal();
    }
    void zgas_swiatla() {
        cout << "Zgaszanie swiatla." << endl;
        s_jadalnia->zgas();
    }
    void zamknij_okna() {
        o_salon->zamknij();
    }
};

int main() {

    Obsuluga_domu o_dom;

    o_dom.otworz_dom();
    cout << endl;
    o_dom.zamknij_dom();
    cout << endl;
    o_dom.zamknij_okna();
    cout << endl;
    o_dom.zgas_swiatla();
    cout << endl;
    o_dom.zapal_swiatla();

    return 0;
}
