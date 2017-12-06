#include <iostream>

using namespace std;

template <class T>
class SharedPointer {
  private:
    int cnt;
    T* ptr;

  public:
    SharedPointer(T* ptr) {
        this->ptr = ptr;
        cnt = 1;
    }

    ~SharedPointer() {
        delete this->ptr;
        this->ptr = NULL;
        this->cnt = 0;
    }

    SharedPointer<T>& operator= (const SharedPointer<T>& other) {
        this->ptr = other.ptr;
        this->cnt = other.cnt;
        this->cnt++;
        return *this;
    }

    void exist() {
        cout << "I exist" << endl;
    }
};

class Dummy {
  private:
    int tutu;

  public:
    Dummy(int tutu) {
        this->tutu = tutu;
    }

    ~Dummy() {
        cout << this->tutu << endl;
    }
};    

int main() {
    Dummy* dp = new Dummy(42);
    SharedPointer<Dummy> p(dp); 

    SharedPointer<Dummy> p2 = p;
    p2.exist();

    p.exist();

    return 0;
}
