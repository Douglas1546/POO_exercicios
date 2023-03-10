#include <iostream>
#include <string.h>

using namespace std;
#define MAXIMO 10

class mae{
    int x;
public:
    mae(int xx = 0):x(xx){

    }
    ~mae(){

    }
    int get_x(){
        return x;
    }
    void set_x(int xx){
        x = xx;
    }
    virtual void print_info() = 0;
};

class filha : public mae{
    int y;
public:
    filha(int yy = 0):y(yy){

    }
    ~filha(){

    }
    int get_y(){
        return y;
    }
    void set_y(int yy){
        y = yy;
    }
    virtual void print_info(){
        cout << "Print_info da classe filha" << endl;
    }
};

class irmao : public mae{
    int i;
    
    
public:
    irmao(int ii = 0):i(ii){
        
    }
    ~irmao(){

    }
    int get_y(){
        return i;
    }
    void set_y(int ii){
        i = ii;
    }
    virtual void print_info(){
        cout << "Print_info da classe irmao" << endl;
    }
};

class print:public mae{
    mae *prints[MAXIMO];
    int count;
public:
    print(){
        count = 0;
    }

    void add_poligono(mae* p) {
		prints[count] = p;
		count++;
	}
    void print_info(){
        for (int i = 0; i < count; i++)
        {
            prints[i]->print_info();
        }
        cout << "Print_info da classe print" << endl;
    }
};


int main(){
    mae *m;
    print p;
    
    irmao* i = new irmao(8);
    p.add_poligono(i);
    filha* f = new filha(5);
    p.add_poligono(f);

    //m = &p; // funciona assim tbm
    //m->print_info(); // funciona assim tbm

    p.print_info();
}