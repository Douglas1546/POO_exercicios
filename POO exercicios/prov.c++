#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class cliente {
    long cpf;
    int idade;
public:
    cliente(long c, int i):cpf(c), idade(i) {
        cout << "Cliente " << cpf << " criado!" << endl;
    }
    void set_cpf(long c) {
        cpf = c;
    }
    long get_cpf() {
        return cpf;
    }
    void set_idade(int i) {
        idade = i;
    }
    int get_idade() {
        return idade;
    }
    void print_info() {
        cout << "Cliente(" << cpf << ", " << idade << ")" << endl;
    }
};

class veiculo {
    int qtd_passageiros;
    float valor_diaria;
public:
    veiculo(int q, float v):qtd_passageiros(q), valor_diaria(v) {
        cout << "Veiculo (" << qtd_passageiros << ", " << valor_diaria << ") criado!" << endl;
    }
    void set_qtd_passageiros(int q) {
        qtd_passageiros = q;
    }
    int get_qtd_passageiros() {
        return qtd_passageiros;
    }
    void set_valor_diaria(float v) {
        valor_diaria = v;
    }
    float get_valor_diaria() {
        return valor_diaria;
    }
    void print_info() {
        cout << "Veiculo(" << qtd_passageiros << ", " << valor_diaria << ")" << endl;
    }
};

class carro: public veiculo {
    int qtd_portas;
    float tam_motor;
    bool ar_cond;
public:
    carro(float v, int qpa, int qpo, float tm, bool ar):
        veiculo(v, qpa), qtd_portas(qpo), tam_motor(tm),ar_cond(ar) {
            cout << "Carro (" << qtd_portas << ", " << tam_motor << ", " << ar_cond;
            cout << ") criado!" << endl;
        }
/* gets e sets */
};

class moto: public veiculo {
    int qtd_cilindradas;
    bool kit_seguranca;
public:
    moto(float v, int qpa, int qc, bool ks):
        veiculo(v, qpa), qtd_cilindradas(qc), kit_seguranca(ks) {
            cout << "Moto (" << qtd_cilindradas << ", " << kit_seguranca;
            cout << ") criada!" << endl;
        }
/* gets e sets */
};

class picape: public veiculo {
    int qtd_eixos;
    float tam_motor;
    float cap_carga;
public:
    picape(float v, int qpa, int qe, float tm, float cc):
        veiculo(v, qpa), qtd_eixos(qe), tam_motor(tm),cap_carga(cc) {
            cout << "Picape (" << qtd_eixos << ", " << tam_motor << ", " << cap_carga;
            cout << ") criada!" << endl;
        }
/* gets e sets */
};

class aluguel {
    int qtd_dias;
    cliente *cliente_aluguel;
    veiculo *veiculo_aluguel;
public:
    aluguel(int q, cliente* c, veiculo* v):
        qtd_dias(q), cliente_aluguel(c), veiculo_aluguel(v) {
            cout << "Aluguel (" << qtd_dias << ") " << endl;
            cliente_aluguel->print_info();
            veiculo_aluguel->print_info();
    }

    ~aluguel() {
        delete cliente_aluguel;
        delete veiculo_aluguel;
    }
    
};

int main(void) {
    cliente *cli1, *cli2, *cli3;
    carro *car1;
    moto *mot1;
    picape *pic1;
    aluguel *alu1, *alu2, *alu3;
    long _cpf;
    int _idade, _qtd_pass, _qtd_dias;
    float _valor_d;

    //aluguel 1
	//a) carros: quantidade de portas (int), tam. motor (float), ar condicionado (bool) 
    int _qtd_pc;
    float _tam_mc;
    bool _ar_con;
    cout << "Digite o cpf do cliente 1: ";
    cin >> _cpf; 
    cout << "Digite a idade do cliente 1: ";
    cin >> _idade;
    cout << "Digite a quantidade de passageiros do veiculo: ";
    cin >> _qtd_pass;
    cout << "Digite o valor da diaria do veiculo: ";
    cin >> _valor_d;
    cout << "Digite a quantidade de portas do carro: ";
    cin >> _qtd_pc;
    cout << "Digite o tamanho do motor do carro: ";
    cin >> _tam_mc;
    cout << "Digite se o carro possui ar condicionado: ";
    cin >> _ar_con;
    cout << "Digite a quantidade de dias do aluguel: ";
    cin >> _qtd_dias;

    cli1 = new cliente(_cpf, _idade);
    car1 = new carro(_valor_d, _qtd_pass, _qtd_pc, _tam_mc, _ar_con);
    alu1 = new aluguel(_qtd_dias, cli1, car1);

    //aluguel 2
    //b) motos: quantidade de cilindradas (int), kit segurança (bool)
    int _qtd_ci;
    bool _kit_s;
    cout << "Digite o cpf do cliente 2: ";
    cin >> _cpf; 
    cout << "Digite a idade do cliente 2: ";
    cin >> _idade;
    cout << "Digite a quantidade de passageiros do veiculo: ";
    cin >> _qtd_pass;
    cout << "Digite o valor da diaria do veiculo: ";
    cin >> _valor_d;
    cout << "Digite a quantidade de dias do aluguel: ";
    cin >> _qtd_dias;
    cout << "Digite a quantidade de cilindradas da moto: ";
    cin >> _qtd_ci;
    cout << "Digite se a moto possui kit de seguranca: ";
    cin >> _kit_s;

    cli2 = new cliente(_cpf, _idade);
    mot1 = new moto(_valor_d, _qtd_pass, _qtd_ci, _kit_s);
    alu2 = new aluguel(_qtd_dias, cli2, mot1);

    //aluguel 3
	//c) picapes: tam. motor (float), quantidade eixos (int), capacidade de carga (float)   
    float _tam_mp;
    int _qtd_eix;
    float _cap_cp;
    cout << "Digite o cpf do cliente 3: ";
    cin >> _cpf; 
    cout << "Digite a idade do cliente 3: ";
    cin >> _idade;
    cout << "Digite a quantidade de passageiros do veiculo: ";
    cin >> _qtd_pass;
    cout << "Digite o valor da diaria do veiculo: ";
    cin >> _valor_d;
    cout << "Digite a quantidade de dias do aluguel: ";
    cin >> _qtd_dias;
    cout << "Digite o tamanho do motor da picape: ";
    cin >> _tam_mp;
    cout << "Digite a quantidade de eixos da picape: ";
    cin >> _qtd_eix;
    cout << "Digite a capacidade de carga da picape: ";
    cin >> _cap_cp;

    cli3 = new cliente(_cpf, _idade);
    pic1 = new picape(_valor_d, _qtd_pass, _qtd_eix, _tam_mp, _cap_cp);
    alu3 = new aluguel(_qtd_dias, cli2, pic1);


    delete alu1;
    delete alu2;
    delete alu3;

}
