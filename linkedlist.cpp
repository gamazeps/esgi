#include <iostream>

using namespace std;

class Node {
  private:
    int data;
    Node* next;

  public:
    Node(int data, Node* next) : data(data), next(next) {}
    ~Node() {
        cout << "destroyed nide with data: " << this->data << endl;
        if (this->next) {
            delete this->next;
        }
    }
};

class LinkedList {
  private:
    Node* start;

  public:
    LinkedList(int data) {
        this->start = new Node(data, NULL);
    }
    ~LinkedList() {
        cout << "Starting to destroy the linked list" << endl;
        delete this->start;
    }

    LinkedList* push(int data) {
        Node* tmp = new Node(data, this->start);
        this->start = tmp;
        return this;
    }
};

int main() {
    LinkedList ll = LinkedList(1);
    ll.push(2)->push(3)->push(4);
}


Mutex i = Mutex(0);

void increment() {
    for (int j(0); j<1000; j++) {
        Lock l = Mutex.lock();
        int i = lock->get();
        lock->set(i+1);
    }
}
