#include <iostream>

using namespace std;

class Stan {
public:
    virtual void rysuj() = 0;
    virtual ~Stan() {}
};

class Dlugopis : public Stan {
public:
    void rysuj() {
        cout << "Rysuje dlugopisem!" << endl;
    }
};

class Linia : public Stan {
public:
    void rysuj() {
        cout << "Rysuje linie!" << endl;
    }
};

class Kanwa {
    Stan *s;
public:
    Kanwa() {
        s = nullptr;
    }

    void uzyjDlugopisu() {
        s = new Dlugopis;
    }

    void uzyjLini() {
        s = new Linia;
    }

    void rysuj() {
        s->rysuj();
    }

    ~Kanwa() {
        delete s;
    }
};

int main() {

    Kanwa *k = new Kanwa;

    k->uzyjLini();
    k->rysuj();

    k->uzyjDlugopisu();
    k->rysuj();

    delete k;

    return 0;
}
