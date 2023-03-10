#include <iostream>

using namespace std;

class funcionario{
    long cpf;
    float salario;
    int idade;
    int departamento;
public:
    funcionario(long c = 0, float s = 0, int i = 0, int d = 0): cpf(c), salario(s), idade(i), departamento(d){

    }
    ~funcionario(){

    }

    long get_cpf(){
        return cpf;
    }
    void set_cpf(long c){
        cpf = c;
    }
    float get_salario(){
        return salario;
    }
    void set_salario(float s){
        salario = s;
    }
    int get_idade(){
        return idade;
    }
    void set_idade(int i){
        idade = i;
    }
    int get_departamento(){
        return departamento;
    }
    void set_dapartamento(int d){
        departamento = d;
    }
    void print_info(){
        printf("\n");
        system("cls");

    for (int i = 0; i < 2; i++)
    {
    printf("\n");
    cout << "cpf do funcionario[" << i + 1 << "]: " << get_cpf() << endl;
    cout <<"salario do funcionario["<< i + 1 << "]: " << get_salario()<< endl;
    cout <<"idade do funcionario["<< i + 1 << "]: " << get_idade()<< endl;
    cout <<"departamento do funcionario["<< i + 1 << "]: " << get_departamento()<< endl;
    }

    }
};

class empresa{
    long cnpj;

public:
    empresa(long c): cnpj(c){

    }
    ~empresa(){

    }
    long get_cnpj(){
        return cnpj;
    }
    void set_cnpj(long c){
        cnpj = c;
    }
};

void print_info(){
    
}

int main(){
    system("cls");
    funcionario *func;
    int qtd_func;
    int idade, departamento;
    long cpf;
    float salario;
    
    cout << "Digite quantos funcionarios deseja cadastrar: ";
    cin >> qtd_func;

    func = new funcionario[qtd_func];

    for (int i = 0; i < qtd_func; i++)
    {
        cout << "Digite o CPF do funcionario [" << i + 1 << "]: ";
        cin >> cpf;
        cout << "Digite o salario do funcionario [" << i + 1 << "]: ";
        cin >> salario;
        cout << "Digite o idade do funcionario [" << i + 1 << "]: ";
        cin >> idade;
        cout << "Digite o departamento do funcionario [" << i + 1 << "]: ";
        cin >> departamento;

        func[i].set_cpf(cpf);
        func[i].set_salario(salario);
        func[i].set_idade(idade);
        func[i].set_dapartamento(departamento);

        //cout << func[i].get_cpf();
        //cout << func[i].get_salario();
        //cout << func[i].get_idade();
        //cout << func[i].get_departamento();
    }

    for (int i = 0; i < qtd_func; i++)
    {
        func[i].print_info();
    }
    
    


}