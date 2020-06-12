#include <iostream>
#include <list>

using namespace std;

class Obserwator {
public:
    virtual void powiadomienie() = 0;
};

class Obserwowany {
    list <Obserwator*> obserwatorzy;
public:
    void dodaj(Obserwator *o) {
        obserwatorzy.push_back(o);
    }

    void usun(Obserwator *o) {
        obserwatorzy.remove(o);
    }

    void zglos_obserwatorom() {
        for(list<Obserwator*>::iterator it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) {
            (*it)->powiadomienie();
        }
    }
};

class YouTube : public Obserwowany {
    string film;
public:
    void opublikujFilm(string tytul) {
        film = tytul;
        zglos_obserwatorom();
    }

    string nowyFilm() {
        return film;
    }

};

class Subskrybent : public Obserwator {
    YouTube *yt;
    string film;
public:
    Subskrybent(YouTube *y) {
        yt = y;
    }

    void powiadomienie() {
        film = yt->nowyFilm();
        cout << "Juz jest! Nowy film: " << film << endl;
    }
};


int main() {

    YouTube *yt = new YouTube;
    Obserwator *Maciek = new Subskrybent(yt);
    Obserwator *Kuba = new Subskrybent(yt);

    yt->dodaj(Maciek);
    yt->dodaj(Kuba);
    yt->opublikujFilm("Przygody wesolego jutubera");

    delete yt;
    delete Maciek;
    delete Kuba;

    return 0;
}
