# Plan for the lesson

- Questions and reviews (you come here).
- Let's implement `vector` and `unordered_map`
- Some thoughts on iterators
- Some `c++11` syntactic sugar
- Presentation of the project (complete subject will come in Thursday).

# Iterators

[<algorithms>](http://www.cplusplus.com/reference/algorithm/)
[<iterator>](http://www.cplusplus.com/reference/iterator/)

# Syntactic sugar

```c++
auto e = container.begin();
```

```c++
vector<T> l;

for (int i(0); i < l.size(); i++) {
    cout << " " << l[i];
}
//...

for (const auto& elem : container) {}
```

# Project

Chat server, must allow multiple connections

Bonus points:

- Multiple threads (not an ugly monothreaded implementation)
- History (when I connect I can get the history of conversation up to a certain point)
- How much history I want
- Authentification (each user has an id), what happens when two people connect with the same id ?
- Anything irc does


gamaz3ps@gmail.com










