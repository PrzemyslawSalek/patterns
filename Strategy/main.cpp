#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Format{
public:
    virtual void wypisz(string) = 0;
    virtual ~Format() {}
};

class DuzeLitery : public Format {
public:
    void wypisz(string str) {
        transform(str.begin(), str.end(),str.begin(), ::toupper);
        cout << str << endl;
    }
};

class MaleLitery : public Format {
public:
    void wypisz(string str) {
        transform(str.begin(), str.end(),str.begin(), ::tolower);
        cout << str << endl;
    }
};

class Napis {
    Format *format;
    string str;
public:
    Napis(string str) : str(str), format(nullptr) {}

    void ustawStrategie(Format *f) {
        if(format)
            delete format;

        format = f;
    }

    void wypisz() {
        format->wypisz(str);
    }

    ~Napis() {
        delete format;
    }

};

int main() {

    Napis napis("Ala ma kota");

    napis.ustawStrategie(new DuzeLitery);
    napis.wypisz();

    napis.ustawStrategie(new MaleLitery);
    napis.wypisz();

    return 0;
}
