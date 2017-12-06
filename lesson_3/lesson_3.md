# Lesson 3: STL part 1

In this lesson we will discover the Standard Template Library (STL).

Disclaimer: we will not dive any deeper in the use of template programming that basic genericity
mostly because it is extremely complex and because it is usually advised against and c++
styleguides, see [Google's
one](https://google.github.io/styleguide/cppguide.html#Template_metaprogramming).
 
## Need for template

`LinkedList` for `int`

```c++
class IntNode {
  private:
    int data;
    IntNode* next;

  public:
    IntNode(int data, IntNode* next) : data(data), next(next) {}
    ~IntNode() {
        if (this->next) {
            delete this->next;
        }
    }
};

class IntLinkedList {
  private:
    IntNode* start;

  public:
    LinkedList(int data) {
        this->start = new IntNode(data, NULL);
    }
    ~LinkedList() {
        delete this->start;
    }

    LinkedList* push(int data) {
        IntNode* tmp = new IntNode(data, this->start);
        this->start = tmp;
        return this;
    }
};
```

What if we want a `LinkedList` for `char`s

```c++
class CharNode {
  private:
    char data;
    CharNode* next;

  public:
    CharNode(char data, CharNode* next) : data(data), next(next) {}
    ~CharNode() {
        if (this->next) {
            delete this->next;
        }
    }
};

class CharLinkedList {
  private:
    CharNode* start;

  public:
    LinkedList(char data) {
        this->start = new CharNode(data, NULL);
    }
    ~LinkedList() {
        delete this->start;
    }

    LinkedList* push(char data) {
        CharNode* tmp = new CharNode(data, this->start);
        this->start = tmp;
        return this;
    }
};
```

The diff between the two is minimal and this leads to poorly maintainable code.

What if we could have a class where a TYPE is a VARIABLE ? This is what genericity does.

```c++
template <class T>
class Node {
  private:
    T data;
    Node* next;

  public:
    Node(T data, Node* next) : data(data), next(next) {}
    ~Node() {
        if (this->next) {
            delete this->next;
        }
    }
};

template <class T>
class LinkedList {
  private:
    Node<T>* start;

  public:
    LinkedList(T data) {
        this->start = new Node(data, NULL);
    }
    ~LinkedList() {
        delete this->start;
    }

    LinkedList* push(T data) {
        Node<T>* tmp = new Node(data, this->start);
        this->start = tmp;
        return this;
    }
};
```

We can then use it this way:

```c++
LinkedList<int> int_ll(1);
int_ll.push(2);
int_ll.push(3);
int_ll.push(4);

LinkedList<char> char_ll('h');
int_ll.push('e');
int_ll.push('l');
int_ll.push('l');
int_ll.push('o');
int_ll.push('\n');
```

Other simple example:

```c++
template <class T>
T GetMax (T a, T b) {
    return (a>b?a:b);
}
```
