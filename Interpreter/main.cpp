#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Wyrazenie {
public:
    virtual void interpretuj(stack<int>*) = 0;
    virtual ~Wyrazenie() {}
};

class Liczba : public Wyrazenie {
    int liczba;
public:
    Liczba(int num) {
        liczba = num;
    }

    void interpretuj(stack<int> *s) {
        s->push(liczba);
    }
};

class Plus : public Wyrazenie {
public:
    void interpretuj(stack<int> *s) {
        int n1 = s->top(); s->pop();
        int n2 = s->top(); s->pop();
        cout << n1 << "+" << n2 << endl;
        s->push(n1 + n2);
    }
};

class Minus : public Wyrazenie {
public:
    void interpretuj(stack<int> *s) {
        int n1 = s->top(); s->pop();
        int n2 = s->top(); s->pop();
        cout << n1 << "-" << n2 << endl;
        s->push(n1 - n2);
    }
};

class Parser {
    list<Wyrazenie*> *lista;
public:
    Parser(string s) {
        lista = new list<Wyrazenie*>;
        for(auto x : s) {
            cout << x << " ";
            if(x == '+') lista->push_back(new Plus);
            else if(x == '-') lista->push_back(new Minus);
            else lista->push_back(new Liczba(int(x)-48));
        }
        cout << endl;
    }

    int oblicz() {
        stack<int> *s = new stack<int>;
        for(auto x : *lista) x->interpretuj(s);
        return s->top();
    }

    ~Parser() {
        delete lista;
    }
};

int main() {

    Parser *p = new Parser("834+-");
    cout << p->oblicz() << endl;

    delete p;

    return 0;
}
