#include <iostream>

using namespace std;

class Tablica {
protected:
    int *arr;
    int size;
    int curr;
public:
    Tablica(int n) : size(n), curr(0) {
        arr = new int[n];
    }

    void dodaj(int val) {
        if(curr < size) {
            arr[curr] = val;
            curr++;
        } else {
            cout << "Za duzo elementow!" << endl;
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    virtual void sortowanie() = 0;

    ~Tablica() {
        delete [] arr;
    }
};


class TablicaM : public Tablica {
public:
    TablicaM(int n) : Tablica(n) {}

    void sortowanie() {
        for(int i = 0; i < size; i++) {
            for(int j = 1; j < size-i; j++) {
                if(arr[j-1] < arr[j])
                    swap(arr[j-1], arr[j]);
            }
        }
    }
};

class TablicaR : public Tablica {
public:
    TablicaR(int n) : Tablica(n) {}

    void sortowanie() {
        for(int i = 0; i < size; i++) {
            for(int j = 1; j < size-i; j++) {
                if(arr[j-1] > arr[j])
                    swap(arr[j-1], arr[j]);
            }
        }
    }
};

int main() {

    Tablica *t1 = new TablicaM(3);

    t1->dodaj(3);
    t1->dodaj(5);
    t1->dodaj(1);

    t1->sortowanie();
    t1->print();

    Tablica *t2 = new TablicaR(3);

    t2->dodaj(3);
    t2->dodaj(5);
    t2->dodaj(1);

    t2->sortowanie();
    t2->print();

    delete t1;
    delete t2;

    return 0;
}
