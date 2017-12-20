template <class T>
class shared_ptr {
  private:
    T* ptr;
    int* cnt;

  public:
    shared_ptr(T* t) {
        this->ptr = t;
        this->cnt = malloc(sizeof(int));
        *(this->cnt) = 1;
    }

    shared_ptr<T> operator=(shared_ptr<T>& other) {
        this->ptr = other.ptr;
        this->cnt = other.cnt;
        *(this->cnt)++;
        return *this;
    }

    ~shared_ptr() {
        *(this->cnt)--;
        if (*(this->cnt) == 0) {
            delete this->ptr;
        }
    }

};

p1
p2 = p1
p3 = p1
