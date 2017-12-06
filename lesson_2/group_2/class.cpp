#include  <iostream>
#include "stdlib.h"

using namespace std;

class Car {
  protected:
    string name;
    int value;

  public:
    Car(string name_argument) : name(name_argument) {}

    virtual void noise() = 0;
};

class SportsCar : public Car {
  public:
    SportsCar(string name) : Car(name) { } 

    ~SportsCar() {}

    void noise() {
        cout << "VROUUUUUUUM" << endl;
    }
};


void what_noise(Car* c) {
    c->noise();
}

void * malloc(size_t size);

int main() {

    SportsCar sc = SportsCar("ferari");

    Car c = new Car("Fiat");

    return 0;
}
