#include <iostream>

class Toto {
  public:
    Toto foo(int tutu) {
        // ....
        return *this;
    }
    Toto * bar(int tutu) {
        // ....
        return this;
    }

}

int main() {
    Toto toto = new Toto();
    
    toto->foo(1)->bar(2);
}
