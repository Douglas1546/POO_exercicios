#include <iostream>
using namespace std;

class mae{
    int nome_mae;
public:
    mae(int m = 1): nome_mae(m){

    }
    ~mae(){

    }
    int get_nome_mae(){
        return nome_mae;
    }
    void set_nome_mae(int m){
        nome_mae = m;
    }

    virtual void print_info(){
        cout << get_nome_mae() << endl;
    }
};




class filha1 : public mae{
    int pessoa1;
public:
    filha1(int p1 = 2): pessoa1(p1){

    }
    ~filha1(){

    }
    int get_pessoa1(){
        return pessoa1;
    }
    void set_pessoa1(int p1){
        pessoa1 = p1;
    }

    virtual void print_info(){
        cout << get_pessoa1() << endl;
    }

};

class filha2 : public mae{

    int pessoa2;

public:
    filha2(int p2 = 3): pessoa2(p2){

    }
    ~filha2(){

    }
    int get_pessoa2(){
        return pessoa2;
    }
    void set_pessoa2(int p2){
        pessoa2 = p2;
    }


    virtual void print_info(){
        cout << get_pessoa2() << endl;
    }
};

int main(){

mae *m1;
filha1 f1;
filha2 f2;

m1 = &f1;

m1 = &f2;

m1->print_info();


}