#include <iostream>

using namespace std;

class Memento {
    int status;
public:
    Memento(int status) {
        this->status = status;
    }

    int getStatus() {
        return status;
    }

    void setStatus(int status) {
        this->status = status;
    }
};

class Czarodziej {
    int status;
public:
    Czarodziej(int status) {
        this->status = status;
    }

    Memento* createMemento() {
        return new Memento(status);
    }

    void restoreMemento(Memento *m) {
        status = m->getStatus();
    }

    void set(int s) {
        status = s;
    }

    void print() {
        cout << "Aktualny status: " << status << endl;
    }
};

int main() {

    Czarodziej *c = new Czarodziej(15);
    Memento *m = c->createMemento();
    c->print();

    c->set(5);
    c->print();

    c->restoreMemento(m);
    c->print();

    delete c;
    delete m;


    return 0;
}
