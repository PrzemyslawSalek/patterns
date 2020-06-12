#include <iostream>
#include <map>

using namespace std;

class Opponent {
protected:
    string name;
    int life;
public:
    virtual void show() = 0;
    virtual void attack() = 0;
    virtual ~Opponent() {}
};

class Wizard : public Opponent {
    string magic_type;
public:
    Wizard() : magic_type("Fire") {
        name = "Wizard";
        life = 500;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Type of magic: " << magic_type << endl;
        cout << "Life: " << life << endl;
    }

    void attack() {
        cout << "Fire ball!" << endl;
    }
};

class Orc : public Opponent {
    int stupidity;
public:
    Orc() : stupidity(200) {
        name = "Orc";
        life = 2000;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Value of stupidity: " << stupidity << endl;
        cout << "Life: " << life << endl;
    }

    void attack() {
        cout << "Flying hammer!" << endl;
    }
};

class OpponentFactory {
    map<string, Opponent*> opponents;
public:
    Opponent* provide(string name) {
        if(opponents[name] == nullptr) {
            cout << "New opponent created." << endl;
            if(name == "Orc") {                             //narusz to chyba Open–closed principle
                opponents[name] = new Orc;                  //ale nie za bardzo wiem jak to zastapic
            } else if(name == "Wizard") {                   //w tym przykladzie
                opponents[name] = new Wizard;
            }
        }
        return opponents[name];
    }

    ~OpponentFactory() {
        for(auto x : opponents) {
            cout << "Opponent deleted." << endl;
            delete x.second;
        }
    }
};

int main() {

    OpponentFactory *factory = new OpponentFactory;

    Opponent *o1 = factory->provide("Orc");
    Opponent *o2 = factory->provide("Wizard");

    o1->show();
    o2->attack();

    Opponent *o3 = factory->provide("Orc");
    o3->show();

    delete factory;

    return 0;
}
