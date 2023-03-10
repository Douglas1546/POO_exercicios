#include <iostream>
#include <math.h>

#define MAX_POLIGONOS 10
#define PI 3.14

using std::cout;
using std::cin;
using std::endl;

class poligono {
	int x;
	int y;
	int z_index;
	int cor;
	static int contador;
public:
	poligono(int xx, int yy, int zz, int c) {
		contador++;
		x = xx;
		y = yy;
		z_index = zz;
		cor = c;
	}

	~poligono() {
		contador--;
	}
	
	int get_x() {
		return x;
	}
	
	void set_x(int xx) {
		x = xx;
	}
	
	int get_y() {
		return y;
	}
	
	void set_y(int yy) {
		y = yy;
	}
	
	int get_z_index() {
		return z_index;
	}
	
	void set_z_index(int z) {
		z_index = z;
	}
	
	int get_cor() {
		return cor;
	}
	
	void set_cor(int c) {
		cor = c;
	}
	
	virtual float area() = 0;

	virtual float perimetro() = 0;

	virtual void print_info() {
		cout << "Coordenadas: (" << x << ", " << y;
		cout << ", " << z_index << ") " << endl;
		cout << "Cor: " << cor << endl;
	}
	
	static int get_contador() {
		return contador;
	}
};

int poligono::contador = 0;

class retangulo : public poligono {
	int base;
	int altura;
public:	
	retangulo(int b, int a, int x, int y, int z, int c):poligono(x,y,z,c) { 
		base = b;
		altura = a;
	}

	int get_base() { 
		return base;
	}

	void set_base(int b) { 
		base = b;
	}

	int get_altura() { 
		return altura;
	}

	void set_altura(int a) {
		altura = a;
	}

	float area() {
		return (float)(base*altura);
	}

	float perimetro() {
		return (float)(2*base)+(2*altura);
	}

	virtual void print_info() {
		cout << "Retangulo " << endl;
		poligono::print_info();
		cout << "Dimensoes: (" << base << ", ";
		cout << altura << ") " << endl;
		cout << "Area: " << area() << endl;
		cout << "Perimetro: " << perimetro() << endl;
	}
};

class circulo : public poligono {
	int raio;
public:
	circulo(int r, int x, int y, int z, int c):poligono(x,y,z,c) {
		raio = r;
	}

	int get_raio() {
		return raio;
	}

	void set_raio(int r) { 
		raio = r;
	}

	float area() {
		return (float)(PI*(float)(raio*raio));
	}

	float perimetro() { 
		return (float)(2*PI*raio);
	}

       virtual void print_info() {
                cout << "Circulo " << endl;
                poligono::print_info();
                cout << "Raio: " << raio << endl;
                cout << "Area: " << area() << endl;
                cout << "Perimetro: " << perimetro() << endl;
        }

};

class triangulo : public poligono { 
	int lado_a;
	int lado_b;
	int lado_c;
public:
	triangulo(int la, int lb, int lc, int x, int y, int z, int c):
		poligono(x,y,z,c) {
			lado_a = la;
			lado_b = lb;
			lado_c = lc;
	}

	int get_lado_a() {
		return lado_a;
	}

	void set_base(int la) {
		lado_a = la;
	}

	int get_lado_b() {
		return lado_b;
	}

	void set_lado_b(int lb) {
		lado_b = lb;
	}

	int get_lado_c() { 
		return lado_c;
	}

	void set_lado_c(int lc) {
		lado_c = lc;
	}

	float area() { 
		return (float)sqrt(
				((perimetro()/2)*((perimetro()/2)-lado_a)*
				 	     ((perimetro()/2)-lado_b)*
					     ((perimetro()/2)-lado_c)
				));
	}

	float perimetro() {
		return (lado_a + lado_b + lado_c);
		
	}

        virtual void print_info() {
                cout << "Triangulo " << endl;
                poligono::print_info();
                cout << "Dimensoes: (" << lado_a << ", ";
                cout << lado_b << ", " << lado_c;
		cout << ") " << endl;
                cout << "Area: " << area() << endl;
                cout << "Perimetro: " << perimetro() << endl;
        }

};

class canvas {
	int largura;
	int altura;
	poligono* desenho[MAX_POLIGONOS]; //composicao
	int poli_count;
public:
	canvas(int l = 0, int a = 0):altura(a), largura(l) {
		poli_count = 0;
	}
	int get_largura() {
		return largura;
	}
	void set_largura(int l) { 
		largura = l;
	}
	int get_altura() {
		return altura;
	}
	void set_altura(int a) {
		altura = a;
	}
	void add_poligono(poligono* p) {
		desenho[poli_count] = p;
		poli_count++;
	}
	void print_info() {
		cout << "Canvas" << endl;
		cout << "Quantidade de poligonos: ";
		cout << poligono::get_contador() << endl;
		cout << "Tamanho do canvas: (" << altura << ", ";
		cout << largura << ") " << endl;
		for (int i = 0; i < poli_count; i++) {
			desenho[i]->print_info();
		}
	}
};

void item_a(canvas& c) {
	c.print_info();	
}

void item_b(canvas& c) {
	int b, a;
	int xx, yy, zz, cc;

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
	retangulo* r = new retangulo(b, a, xx, yy, zz, cc);
	c.add_poligono(r);
}

void item_c(canvas& c) {
        int r;
        int xx, yy, zz, cc;

        cout << "Digite o raio do circulo: "; 
        cin >> r;
        cout << "Digite a coordenada x do circulo: ";
        cin >> xx;
        cout << "Digite a coordenada y do circulo: ";
        cin >> yy;
        cout << "Digite a coordenada z do circulo: ";
        cin >> zz;
        cout << "Digite a cor do circulo: ";
        cin >> cc;
        circulo* ci = new circulo(r, xx, yy, zz, cc);
        c.add_poligono(ci);
}

void item_d(canvas& c) {
        int la, lb, lc;
        int xx, yy, zz, cc;

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
        triangulo* t = new triangulo(la, lb, lc, xx, yy, zz, cc);
        c.add_poligono(t);
}

int main() {
	canvas tela(640, 480);

	item_b(tela);
	item_c(tela);
	item_d(tela);
	item_a(tela);

	return 0;
}
