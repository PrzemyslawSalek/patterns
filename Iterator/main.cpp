#include <iostream>

using namespace std;

class Vec{
private:
    int* arr;
    int place;
    int size;
public:

    class Iterator {
    private:
        int *val;
    public:
        Iterator(int *val) : val(val) {}

        Iterator next() {
            val = val+1;
            return Iterator(val);
        }

        int operator*() {
            return *val;
        }

    };

    Vec(int size) : size(size) {
        arr = new int[size];
        place = 0;
    }

    ~Vec() {
        delete[] arr;
    }

    void push_back(int value) {
        if(place != size) arr[place++] = value;
        else cout << "Blad! Wyszedles poza tablice." << endl;
    }

    int* begin() {
        return arr;
    }

    int sizee() {
        return size;
    }

};


int main() {
    Vec vec(5);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(4);

    Vec::Iterator it(vec.begin());
    int m = vec.sizee();

    while(m--) {
        cout << *it << " ";
        it = it.next();
    }

}
