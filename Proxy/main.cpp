#include <iostream>

using namespace std;

class Big {
public:
    virtual void show() = 0;
    virtual ~Big() {}
};

class BigClass : public Big {
public:
    BigClass() {
        cout << "Powstalo BigClass!" << endl;
    }

    void createSth() {
        cout << "Tworze cos w BigClass!" << endl;
    }

    void show() {
        cout << "Pokazuje co mam ~ BigClass" << endl;
    }
};

class BigProxy : public Big {
    BigClass *big;
public:
    BigProxy() : big(nullptr) {
        cout << "Powstalo BigProxy!" << endl;
    }

    void show() {
        if(!big) {
            big = new BigClass;
            big->createSth();
            big->show();
        } else {
            big->show();
        }
    }

    ~BigProxy() {
        delete big;
    }
};

int main() {

    Big *b = new BigProxy;

    b->show();

    delete b;

    return 0;
}
