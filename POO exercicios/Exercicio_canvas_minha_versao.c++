#include <iostream>
#include <math.h>
using namespace std;
#define MAX_POLIGONOS 10
#define PI 3.14

class poligono{
    int x;
    int y;
    int z_index;
    int cor;
    static int contador;
public:
    poligono(int xx, int yy, int z, int c): x(xx),y(yy),z_index(z),cor(c){
        contador++;
    }
    ~poligono(){
        contador--;
    }
    int get_x(){
        return x;
    }
    void set_x(int xx){
        x = xx;
    }
    int get_y(){
        return y;
    }
    void set_y(int yy){
        y = yy;
    }
    int get_z_index(){
        return z_index;
    }
    void set_z_index(int z){
        z_index = z;
    }
    virtual float area() = 0;

    virtual float perimetro() = 0;

    virtual void print_info(){
        cout << "Coordenadas: (" << x << ", " << y << z_index << ") " << endl;
        cout << "Cor: " << cor << endl;
    }
    static int get_contador(){
        return contador;
    }
};

int poligono::contador = 0; 

class retangulo : public poligono{
    int base;
    int altura;
public:
    retangulo(int b, int a, int x, int y, int z, int c):poligono(x,y,z,c){
        base = b;
        altura = a;
    }
    int get_base(){
        return base;
    }
    void set_base(int b){
        base = b;
    }
    int get_altura(){
        return altura;
    }
    void set_altura(int a){
        altura = a;
    }
    float area(){
        return (float)(base*altura);
    }
    float perimetro(){
        return (float)(2*base)+(2*altura);
    }
    virtual void print_info(){
        cout << "=======================================================" << endl;
        cout << "Retangulo " << endl;
        poligono::print_info();
        cout << "Dimensoes: (" << base << ", " << altura << ") " << endl;
        cout << "Area " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
        cout << "=======================================================" << endl;
    }
};

class circulo : public poligono{
    int raio;
public:
    circulo(int r, int x, int y, int z, int c):poligono(x,y,z,c){
        raio = r;
    }
    int get_raio(){
        return raio;
    }
    void set_raio(int r){
        raio = r;
    }
    float area(){
        return (float)(PI*(float)(raio*raio));
    }
    float perimetro(){
        return (float)(2*PI*raio);
    }

    virtual void print_info(){
        cout << "=======================================================" << endl;
        cout << "Circulo " << endl;
        poligono::print_info();
        cout << "Raio: " << raio << endl;
        cout << "Area " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
        cout << "=======================================================" << endl;
    }
};

class triangulo : public poligono{
    int lado_a;
    int lado_b;
    int lado_c;
public:
    triangulo(int la, int lb, int lc, int x, int y, int z, int c):poligono(x,y,z,c){
        lado_a = la;
        lado_b = lb;
        lado_c = lc;
    }
    int get_lado_a(){
        return lado_a;
    }
    void set_lado_a(int la){
        lado_a = la;
    }
    int get_lado_b(){
        return lado_b;
    }
    void set_lado_b(int lb){
        lado_b = lb;
    }
    int get_lado_c(){
        return lado_c;
    }
    void set_lado_c(int lc){
        lado_c = lc;
    }
    float area(){
        return (float)sqrt(((perimetro()/2)*((perimetro()/2)-lado_a)*((perimetro()/2)-lado_b)*((perimetro()/2)-lado_c)));
    }
    float perimetro(){
        return (lado_a + lado_b + lado_c);
    }

    virtual void print_info(){
        cout << "=======================================================" << endl;
        cout << "Triangulo " << endl;
        poligono::print_info();
        cout << "Dimensoes: (" << lado_a << ", " << lado_b << ", " << lado_c << ") " << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
        cout << "=======================================================" << endl;
    }
};

class canvas{
    int altura;
    int largura;
    poligono* desenho[MAX_POLIGONOS];
    int poli_count;
public:
    canvas(int l = 0, int a = 0): altura(a), largura(l){
        poli_count = 0;
    }
    int get_altura(){
        return altura;
    }
    void set_altura(int a){
        altura = a;
    }
    int get_largura(){
        return largura;
    }
    void set_largura(int l){
        largura = l;
    }
    void add_poligono(poligono* p){
        desenho[poli_count] = p;
        poli_count++;

    }
    void print_info_canvas(){
        cout << "Canvas" << endl;
        cout << "Quantidade de poligonos: " << poligono::get_contador() << endl;
        cout << "Tamanho do canvas: (" << largura << ", " << altura << ") " << endl;
    }
    
    void print_info(){
        if (poli_count == 0)
        {
            printf("==================================\n");
            printf("A lista de poligonos esta vazia!!!\n");
            printf("==================================\n");
        }
        else{
            for (int i = 0; i < poli_count; i++)
            {
                desenho[i]->print_info();
            }
        }
    }
    
};

int main(){
    canvas tela;
    canvas c;
    retangulo* r;
    circulo* ci;
    triangulo* t;
    int op;

    int larg, alt;
    int b,a;
    int xx,yy,zz,cc;
    int raio;
    int la, lb, lc;

    do
    {
        printf("\n 1 - Inserir tamanho do canvas \n 2 - Exibir informacoes do canvas \n 3 - Inserir Retangulo \n 4 - Inserir Circulo \n 5 - Inserir Triangulo");
        printf("\n 6 - Exibir poligonos na tela \n 0 - Sair");
        printf("\n\n Digite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf("Digite a largura: ");
            scanf("%d", &larg);
            c.set_largura(larg);
            printf("Digite a altura: ");
            scanf("%d", &alt);
            c.set_altura(alt);
            break;
        case 2:
            system("cls");
            c.print_info_canvas();
            break;
        case 3:
            system("cls");
            cout << "Digite a base do retangulo: ";
	        cin >> b;
	        cout << "Digite a altura do retangulo: ";
	        cin >> a;
	        cout << "Digite a coordenada x do retangulo: ";
	        cin >> xx;
	        cout << "Digite a coordenada y do retangulo: ";
            cin >> yy;
            cout << "Digite a coordenada z do retangulo: ";
            cin >> zz;
	        cout << "Digite a cor do retangulo: ";
	        cin >> cc;
	        r = new retangulo(b, a, xx, yy, zz, cc);
	        c.add_poligono(r);
            break;
        case 4:
            system("cls");
            cout << "Digite o raio do circulo: "; 
            cin >> raio;
            cout << "Digite a coordenada x do circulo: ";
            cin >> xx;
            cout << "Digite a coordenada y do circulo: ";
            cin >> yy;
            cout << "Digite a coordenada z do circulo: ";
            cin >> zz;
            cout << "Digite a cor do circulo: ";
            cin >> cc;
            ci = new circulo(raio, xx, yy, zz, cc);
            c.add_poligono(ci);
            break;
        case 5:
            system("cls");
            cout << "Digite o lado a do triangulo: "; 
            cin >> la;
            cout << "Digite o lado b do triangulo: ";
            cin >> lb;
            cout << "Digite o lado c do triangulo: ";
            cin >> lc;
		    cout << "Digite a coordenada x do triangulo: ";
		    cin >> xx;
            cout << "Digite a coordenada y do triangulo: ";
            cin >> yy;
            cout << "Digite a coordenada z do triangulo: ";
            cin >> zz;
            cout << "Digite a cor do triangulo: ";
            cin >> cc;
            t = new triangulo(la, lb, lc, xx, yy, zz, cc);
            c.add_poligono(t);
            break;
        case 6:
            system("cls");
            c.print_info();
            break;
        default:
            break;
        }
    } while (op!=0);
    
}