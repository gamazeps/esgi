#include <iostream>

using namespace std;

template <class T>
class SharedPointer {
  private:
    int* cnt;
    T* ptr;

  public:
    SharedPointer(T* ptr) {
        this->ptr = ptr;
        this->cnt = new int;
        *(this->cnt) = 1;
    }

    ~SharedPointer() {
        *(this->cnt)--;
        cout << *(this->cnt) << endl;
        if (this->cnt && *(this->cnt) == 0) {
            delete this->ptr;
            delete this->cnt;
            this->ptr = NULL;
        }
    }

    SharedPointer<T>& operator= (const SharedPointer<T>& other) {
        this->ptr = other.ptr;
        this->cnt = other.cnt;
        *(this->cnt)++;
        cout << "use_count: " << *(this->cnt) << endl;
        return *this;
    }

    void exist() const {
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
    SharedPointer<Dummy> p3 = p;
    SharedPointer<Dummy> p4 = p;
    SharedPointer<Dummy> p5 = p;
    p2.exist();

    p.exist();

    return 0;
}
