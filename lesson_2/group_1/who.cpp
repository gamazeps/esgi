#include <iostream>

using namespace std;

int main() {
    string name;
    cout << "who are you" << endl;
    cin >> name;
    cout << "You are " << name << endl;

    return 0;
}

string read_from_file(string fname) {
    string tmp;
    File f = File(fname);
    f.open();
    f >> tmp;
    return tmp;
}

class Toto {
  public:
    Toto * set_foo(int foo) {
        this.foo = foo;
        return this;
    }

    Toto * set_bar(int bar) {
        this.bar = bar;
        return this;
    }

    Toto * set_baz(int baz) {
        this.baz = baz;
        return this;
    }
}

Toto toto;

toto.set_foo(1).set_bar(2).set_baz(3);
