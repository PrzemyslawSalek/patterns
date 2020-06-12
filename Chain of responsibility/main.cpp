#include <iostream>

using namespace std;

class Handler {
protected:
    Handler* next;
public:
    Handler() : next(nullptr) {}

    virtual void handle(string) = 0;

    void setNext(Handler* h) {
        if(!next)
            next = h;
        else
            next->setNext(h);
    }

    virtual ~Handler() {
        delete next;
    }
};

class Clutch : public Handler {
public:
    void handle(string req) {
        if(req == "Clutch")
            cout << "I press the clutch pedal." << endl;
        else
            if(next) next->handle(req);
    }
};

class Engine : public Handler {
public:
    void handle(string req) {
        if(req == "Engine")
            cout << "I start the engine." << endl;
        else
            if(next) next->handle(req);
    }
};

class Gear : public Handler {
public:
    void handle(string req) {
        if(req == "Gear")
            cout << "Gear change." << endl;
        else
            if(next) next->handle(req);
    }
};


int main() {

    Handler *clutch = new Clutch;
    Handler *engine = new Engine;
    Handler *gear = new Gear;

    clutch->setNext(engine);
    clutch->setNext(gear);

    clutch->handle("Gear");

    return 0;
}
