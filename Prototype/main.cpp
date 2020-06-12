#include <iostream>

using namespace std;

class Prototype {
public:
    virtual Prototype* clone() const= 0;
    virtual ~Prototype() {}
};

class Falcon9 : public Prototype {
    string engine;
    float cost;
public:
    Falcon9(string engine, float cost) {
        this->engine = engine;
        this->cost = cost;
    }

    Falcon9(const Falcon9 &copy) {
        this->engine = copy.engine;
        this->cost = copy.cost;
    }

    Falcon9* clone() const {
        return new Falcon9(*this);
    }

    void show() {
        cout << "Engine: " << engine << " Cost:" << cost << endl;
    }
};

int main() {

    Falcon9 *f9v1 = new Falcon9("Merlin 1D+", 62000000);
    Falcon9 *f9v2 = f9v1->clone();

    f9v1->show();
    delete f9v1;
    f9v2->show();
    delete f9v1;

    return 0;
}
