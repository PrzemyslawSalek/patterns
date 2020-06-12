#include <iostream>

using namespace std;

class Charger {
public:
    virtual void work() = 0;
    virtual ~Charger() {}
};

class USBTypeC : public Charger {
public:
    virtual void work() {
       cout << "The charger USBTypeC works." << endl;
    }
};

class Lightning : public Charger {
public:
    virtual void work() {
       cout << "The charger Lightning works." << endl;
    }
};

class Smartphone {
protected:
    Charger* charger;
public:
    virtual void setCharger(Charger*) = 0;
    virtual void show() = 0;
    virtual ~Smartphone() {
        cout << "The charger deleted." << endl;
        delete charger;
    }
};

class Xiaomi : public Smartphone {
public:
    Xiaomi() {
        charger = nullptr;
    }

    void setCharger(Charger* ch) {
        charger = ch;
    }

    void show() {
        if(charger)
            charger->work();
        else
            cout << "No charger connected to the device." << endl;
    }
};

class iPhone : public Smartphone {
public:
    iPhone() {
        charger = nullptr;
    }

    void setCharger(Charger* ch) {
        charger = ch;
    }

    void show() {
        if(charger)
            charger->work();
        else
            cout << "No charger connected to the device." << endl;
    }
};

int main() {
    Smartphone *s = new iPhone;
    s->show();

    Charger *ch = new Lightning;
    s->setCharger(ch);
    s->show();

    delete s;

    return 0;
}
