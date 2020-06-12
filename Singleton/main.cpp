#include <iostream>

using namespace std;

class Dziennik {
public:
    static Dziennik& instancja() {
         static Dziennik singleton;
         return  singleton;
    }

    void ustawLog(string log) {
        this->log = log;
    }

    string zwrocLog() {
        return log;
    }

private:
    string log;

    Dziennik() : log("Brak!") {}
    Dziennik(const Dziennik&) {}
    ~Dziennik() {}
};

class Programista {
public:
    Programista() {
        Dziennik::instancja().zwrocLog();
    }

    void ustawianie(string str) {
        Dziennik::instancja().ustawLog(str);
    }

    string logi() {
        return Dziennik::instancja().zwrocLog();
    }
};


int main() {

    Dziennik::instancja().zwrocLog();

    Dziennik& dziennik = Dziennik::instancja();
    dziennik.ustawLog("Pierwszy!");
    dziennik.zwrocLog();

    Programista Przemek;
    Przemek.ustawianie("Drugi!");
    Przemek.logi();


    return 0;
}
