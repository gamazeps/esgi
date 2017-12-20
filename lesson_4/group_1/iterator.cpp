#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;

template <class T>
void dump(vector<T> vec) {
    for (const auto& e : vec) {
        cout << e << " ";
    }
    cout << endl;
}


int main() {
    vector<int> vec({7, 2, 3});
    set<int> s({7, 2, 3});

    dump(vec);
    sort(vec.begin(), vec.end());
    dump(vec);

    auto m = min_element(s.begin(), s.end());
    cout << *m << endl;

    return 0;
}
