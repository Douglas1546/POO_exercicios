#include <iostream>
using namespace std;
//

class complexo {
  double real;
  double imaginario;
  
public:

complexo(double r = 0, double i = 0) : real(r), imaginario(i) {}

complexo operator+(const complexo& b) const{
    complexo soma;
    soma.real = real + b.real;
    soma.imaginario = imaginario + b.imaginario;
    return soma;
    
    
}
complexo& operator++(){  // pre fixado
    real += 1;
    imaginario += 1;
    return *this;
}

complexo operator ++(int) { // pos fixado
    this -> real += 1;
    this -> imaginario += 1;
    
    return *this;
    }
    
double get_real() const {
     return real; 
    }
double get_imaginario() const {
    return imaginario;
    } 

};

int main()
{
    complexo a(2, 3);
    complexo b(7, 8);
    complexo c;
    
    c = a + b;
    
    cout << "real de c " << c.get_real() << endl;
    cout << "imaginario de c " << c.get_imaginario() << endl << endl;
    
    ++c;
    cout << "real de c " << c.get_real() << endl;
    cout << "imaginario de c " << c.get_imaginario() << endl << endl;
    
    c++;
    cout << "real de c " << c.get_real() << endl;
    cout << "imaginario de c " << c.get_imaginario() << endl << endl;
    
    return 0;
}