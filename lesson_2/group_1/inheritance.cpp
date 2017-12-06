#include <iostream>

using namespace std;

class Car {
  protected:
    string name;
  public:
    Car() {
        //cout << "default constructor of Car used here" << endl;
    }

    Car(string name) : name(name) {
        //cout << "Non default constructor of Car used here" << endl;
    }

    virtual void noise() {
        cout << "vroum" << endl;
    };
};

class SportsCar : public Car {
  public:
    SportsCar(string name) : Car(name) { }

    void noise() {
        cout << "VROUM" << endl;
    }

};

void what_noise(Car* c) {
    c->noise();
}

int main() {
    SportsCar sc = SportsCar("ferari");
    Car car = Car("fiat");

    ((Car* ) &sc)->noise();

    return 0;
}
