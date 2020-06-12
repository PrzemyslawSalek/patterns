#include <iostream>
#include <map>

using namespace std;

class Mediator {
public:
    virtual void wyslij(int, string) = 0;
    virtual ~Mediator() {}
};

class Uzytkownik {
    int identyfikator;
    Mediator *mediator;
public:
    Uzytkownik(int id) {
        identyfikator = id;
        mediator = nullptr;
    }

    void wyslij(int id, string tresc) {
        mediator->wyslij(id, tresc);
    }

    int getId() {
        return identyfikator;
    }

    void odbierz(string tresc) {
        cout << "Odebrano wiadomosc: " << tresc << endl;
    }

    void dodajMediatora(Mediator *m) {
        mediator = m;
    }

    ~Uzytkownik() {
        delete mediator;
    }
};

class Messenger : public Mediator {
    map<int, Uzytkownik*> uzytkownicy;
public:
    void dodajUzytkownika(Uzytkownik *u) {
        uzytkownicy[u->getId()] = u;
        u->dodajMediatora(this);
    }

    void wyslij(int id, string tresc) {
        uzytkownicy[id]->odbierz(tresc);
    }
};

int main() {

    Mediator *m = new Messenger;

    Uzytkownik *Tomek = new Uzytkownik(0);
    Uzytkownik *Marcin = new Uzytkownik(1);
    Uzytkownik *Julka = new Uzytkownik(2);

    Tomek->dodajMediatora(m);
    Marcin->dodajMediatora(m);
    Julka->dodajMediatora(m);

    Tomek->wyslij(2, "KC");
    Marcin->wyslij(0, "Nie pytaja cie o imie walcza z ostrym cieniem mgly");

    delete m;
    delete Tomek;
    delete Marcin;
    delete Julka;

    return 0;
}
