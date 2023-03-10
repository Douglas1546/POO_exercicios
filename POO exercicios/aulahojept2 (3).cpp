#include <iostream>
using namespace std;
//

class complexo
{
    double real;
    double imaginario;

public:
    friend complexo operator*(const complexo &, const complexo &);
    complexo(double r = 0, double i = 0) : real(r), imaginario(i) {}

    complexo operator+(const complexo &b) const
    {
        complexo real;
        real.real += b.real;
        real.imaginario += b.imaginario;
        return real;
    }
    complexo &operator++() // pre fixado
    { 
        real += 1;
        imaginario += 1;
        return *this;
    }

    complexo operator++(int) // pos fixado
    { 
        this->real += 1;
        this->imaginario += 1;

        return *this;
    }

    double get_real() const
    {
        return real;
    }
    double get_imaginario() const
    {
        return imaginario;
    }
};

complexo operator*(const complexo &a, const complexo &b)
{
    complexo aux;
    aux.real = a.real * b.real;
    aux.imaginario = a.imaginario * b.imaginario;
    return aux;
}

int main()
{
    complexo a(1.5, 2.2);
    complexo b(1.6, 2.5);
    complexo c;

    c = a * b;
    

    cout << " real de c " << c.get_real() << endl;
    cout << "imaginario de b " << b.get_imaginario() << endl;

    return 1;
}