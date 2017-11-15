# Cours de C++ -- Partie 2

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
