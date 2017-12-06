# Cours de C++ -- Partie 2

## Plan du cours

Classes et propriétés (constructeurs, destructeurs, sémantique de copie et du move, séparation
méthodes et définition), héritage et polymorphisme (fonctions virtuelles et virtuelles pures, bonnes
pratiques), 

## Ressources utiles

[cppreference](http://en.cppreference.com/w/)
[cplusplus](http://www.cplusplus.com/)

Pour approfondir des concepts de C/C++ les [slides de deep
c/c++](https://www.slideshare.net/olvemaudal/deep-c) peuvent être intéressants.

Pour gdb [guide de survie](https://sen.enst.fr/se203/guide-de-survie-gdb)

[c++ style guide](https://google.github.io/styleguide/cppguide.html)

Liste de ressources générales ["Google guide to technical
development"](https://github.com/ECB-Bikaner/google-guide-to-technical-development)

## Rappels du précédent cours

### Afficher un message

```c++
#include <iostream>

void my_println(string txt) {
    std::cout << txt << std::endl;
}    
```


### Définir une classe

```c++
class Hello {
    public:
        Hello() {
            std::cout << "Hello";
        }

        ~Helo() {
            std::cout << " World !" << std::endl;
        }
};
```

### Instancier un objet

```c++
void foo() {
    Hello  hello_1 = Hello(); // Créé sur la stack, détruit au moment de quiter le scope.
    Hello *hello_2 = new Hello(); // Créé dans le heap, à libérer avec delete, initialisé avec le
                                  // constructeur donné.
    Hello *hello_3 = malloc(Hello); // Créé sur le heap, à libérer avec free, non initialisé.

}
```

## Généricité

```c++
template <class T>
T identity(T arg) {
    return arg;
}
```

```c++
template <class T>
class Pair {
  public:
    Pair(T a, T b) : a(a), b(b) {}
    T a;
    T b;
};
```

Exemple utile de généricité

```c++
template <class T>
class Mutex {
  private:
    T data;
    std::mutex mut;
  public:
    Mutex(T data) : data(data), mut(new mutex) {}
    ~Mutex() {
        delete this.mut;
    }

    T lock() {
        this.mut.lock();
        return this.data;
    }

    void unlock() {
        this.mut.unlock();
    }
};
```
