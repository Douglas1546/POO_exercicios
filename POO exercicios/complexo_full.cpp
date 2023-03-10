#include <iostream>

using std::cout;
using std::cin;
	using std::endl;

class complexo {
	double real;
	double imag;
public:
	complexo(double r = 0, double i = 0):real(r),imag(i){}

	double get_real() { return real; }
	void set_real(double r) { real = r; }
	double get_imag() { return imag; }
	void set_imag(double i) { imag = i; } 

	complexo operator+(const complexo&) const;
	complexo operator-(const complexo&) const;
        friend complexo operator*(const complexo&,
                                  const complexo&); //friend
	friend complexo operator/(const complexo&,
				  const complexo&); //friend	
	complexo& operator++(); //pre
	complexo operator++(int); //pos
	friend complexo& operator--(complexo&); //pre friend
	complexo operator--(int); //pos membro

};

complexo complexo::operator+(const complexo& b) const {
	complexo aux;
	aux.real = real + b.real;
	aux.imag = imag + b.imag;
	return aux;
}

complexo complexo::operator-(const complexo& b) const {
	complexo aux;
	aux.real = real - b.real;
	aux.imag = imag - b.imag;
	return aux;

}

complexo operator*(const complexo& a, const complexo& b) {
        complexo aux;
        aux.real = a.real * b.real;
        aux.imag = a.imag * b.imag;
        return aux;
}

complexo operator/(const complexo& a, const complexo& b) {
        complexo aux;
        aux.real = a.real / b.real;
        aux.imag = a.imag / b.imag;
        return aux;
}


complexo& complexo::operator++() { //prefixado
	this->real += 1;
	this->imag += 1;
	return *this;
}

complexo complexo::operator++(int) { //pos-fixado
	this->real += 1;
	this->imag += 1;
	return *this;
}

complexo& operator--(complexo& a) { //prefixado
	a.real -= 1;
	a.imag -= 1;
	return a;
}

complexo complexo::operator--(int) { //pos-fixado
	this->real -= 1;
	this->imag -= 1;
	return *this;
}

int main(void) {
	complexo a(1.5, 2.2);
	complexo b(1.6, 2.5);
	complexo c;
	complexo d;

	cout << "a = (1.5, 2.2), b = (1.6, 2.5)";
        cout << endl;

	c = a + b;
	cout << "c = a + b" << endl;

	cout << "c.real = " << c.get_real();
	cout << " c.imag = " << c.get_imag() << endl;

	cout << "c--" << endl;

        c--;

        cout << "c.real = " << c.get_real();
        cout << " c.imag = " << c.get_imag() << endl;

	cout << "d = (++c) - a " << endl;

	d = (++c) - a;

	cout << "d.real = " << d.get_real();
	cout << " d.imag = " << d.get_imag() << endl;

	c = a * b;
	//operator*(a, b);

	cout << "c = a * b" << endl;
	cout << "c.real = " << c.get_real();
	cout << " c.imag = " << c.get_imag() << endl;
	d = a / b;
        //operator/(a, b);

        cout << "d = a / b" << endl;
        cout << "d.real = " << d.get_real();
        cout << " d.imag = " << d.get_imag() << endl;

	return 0;
}

