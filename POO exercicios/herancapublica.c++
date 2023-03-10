#include <iostream>

using std::cout;
using std::endl;

class animal { 
    int idade;
public:
    animal(int i = 0):idade(i){}
    int get_idade() {
        return idade;
    }
    void set_idade(int i) {
        idade = i;
    }
    virtual void acordar() {
        cout << "animal::acordar() - idade(" << idade << ")" << endl;
    }
    virtual void comer() {
        cout << "animal::comer() - idade(" << idade << ")" << endl;
    }
    virtual void dormir() {
        cout << "animal::dormir() - idade(" << idade << ")" << endl;
    }
};

class ave: public animal {
public:
    void voar() {
        cout << "ave::voar()" << " idade da ave: " << get_idade() << endl;
    }
    void comer() {
        cout << "ave::comer()" << " idade da ave: " << get_idade() << endl;
    }
    void dormir() {
        cout << "ave::dormir()" << "idade da ave: " << get_idade() << endl;
    }    
};

void invoca_comer(animal &a) {
    a.comer();
}

int main(void) {
    animal an1(10);
    ave av1;    

    invoca_comer(av1); //ave::comer (upcasting)
    invoca_comer(an1); //animal::comer (ok!)
    animal *r_an = &av1;

    r_an->acordar(); //animal::acordar
    r_an->comer(); //ave::comer
    r_an->dormir(); //ave::dormir



}