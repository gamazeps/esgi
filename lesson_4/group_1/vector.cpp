#include <cstdlib>
#include <errno.h>
#include <iostream>

using namespace std;

#define INIT_SIZE 2

template <class T>
class Vector {
  private:
    size_t max_size;
    T* table;
    size_t curr_size;

  public:
    Vector() : Vector(INIT_SIZE) {}

    Vector(size_t size) {
        this->max_size = size;
        this->table = (T*) malloc(this->max_size * sizeof(T));
        this->curr_size = 0;
    }

    Vector& operator=(const Vector& v) {
        *this = Vector(v.max_size);
        this->curr_size = v.curr_size;
        for (size_t i(0); i < this->curr_size; i++) {
            this->table[i] = v.table[i];
        }
    }

    ~Vector() {
        for (size_t i(0); i < this->curr_size; i++) {
            this->table[i].~T(); // FIXME: probably wrong.
        }
        free(this->table);
    }
    
    size_t size() {
        return this->curr_size;
    }

    T* at(size_t n) {
        if (n < this->curr_size) {
            return &(this->table[n]);
        }

        return nullptr;
    }

    void pop_back() {
        if (this->curr_size == 0) {
            return;
        }
        this->table[this->curr_size - 1].~T();
        this->curr_size--;
    }

    int push_back(T elem) {
        if (this->curr_size == this->max_size) {
            this->max_size *= 2;
            cout << "My new size is " << this->max_size << endl;
            T* tmp = (T*) realloc(this->table, this->max_size);
            if (tmp == nullptr) {
                return ENOMEM;
            }
            this->table = tmp;
        }
        this->table[this->curr_size] = elem;
        this->curr_size++;
        return 0;
    }

    int set(int n, T value) {
        if (n < this->curr_size) {
            this->table[n] = value;
            return 0;
        } else {
            return 1;
        }
    }
};

class Dummy {
  public:
    Dummy() {}
    ~Dummy() {
        cout << "Destroyed" << endl;
    }
};

int main() {
    Vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    cout << *test.at(2) << endl;
    test.set(2, 42);
    cout << *test.at(2) << endl;

    cout << test.set(42, 42) << endl;

    Vector<Dummy> d_test;
    d_test.push_back(Dummy());
    d_test.push_back(Dummy());
    // ^ double size
    d_test.push_back(Dummy());
    d_test.pop_back();
    
    return 0;
}





