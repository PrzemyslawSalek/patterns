#include <iostream>

using namespace std;

class Pizza {
protected:
    string rodzaj;
    float cena;
public:

    Pizza() : rodzaj("Ciasto bez skladnikow"), cena(6.99) {}

    virtual string jaka() {
        return rodzaj;
    }

    virtual float cena_pizzy() {
        return cena;
    }
};

class Dekorator : public Pizza {
public:

    string jaka() {
        return "Skladniki: ";
    }
};

class Margarita : public Pizza {
public:

    Margarita() : Pizza() {
        rodzaj = "Margarita";
        cena = 10.50;
    }
};

class Boczek : public Dekorator {
    Pizza *pizza;

public:
    Boczek(Pizza* pizza) : Dekorator() {
        this->pizza = pizza;
    }

    string jaka() {
        return pizza->jaka() + " " + "boczus";
    }

    float cena_pizzy() {
        return pizza->cena_pizzy() + 2.50;
    }
};

class Pieczarki : public Dekorator {
    Pizza *pizza;

public:
    Pieczarki(Pizza *pizza) : Dekorator() {
        this->pizza = pizza;
    }

    string jaka() {
        return pizza->jaka() + " " + "pieczarki";
    }

    float cena_pizzy() {
        return  pizza->cena_pizzy() + 2.0;
    }
};

int main() {

    Pizza *p1 = new Margarita;

    cout << "Pizza na start: " << endl;
    cout << p1->jaka() << " " << p1->cena_pizzy() << endl;

    p1 = new Pieczarki(p1);

    cout << "Pizza z pieczarkami: " << endl;
    cout << p1->jaka() << " " << p1->cena_pizzy() << endl;

    p1 = new Boczek(p1);

    cout << "Pizza z pieczarkami i boczkiem: " << endl;
    cout << p1->jaka() << " " << p1->cena_pizzy() << endl;

    Pizza *p2 = new Boczek(new Pieczarki(new Margarita));
    cout << "Pizza full wypas na start dla najlepszego klienta: " << endl;
    cout << p1->jaka() << " " << p1->cena_pizzy() << endl;

    return 0;
}
