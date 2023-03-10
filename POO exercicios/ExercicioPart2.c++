#include <iostream>
#include <string.h>

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
};
//========================================================================================================================================================//
class gerente : public funcionario{

public:
    gerente(){

    }
    ~gerente(){

    }
   
};
//========================================================================================================================================================//
class analista : public funcionario{

public:
    analista(){

    }
    ~analista(){

    }
 
};
//========================================================================================================================================================//
class tecnico : public funcionario{

public:
    tecnico(){
        
    }
    ~tecnico(){

    }
};
//========================================================================================================================================================//
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
    empresa *emp;
    gerente *gerent;
    int qtd_func;
    int idade, departamento;
    long cpf, cnpj;
    float salario;
    char cargo[10][10];
    char grt[8] = {"gerente"};

    cout << "========== Cadastrar Empresa ==========" << endl << endl;
    cout << "Digite o CNPJ da empresa: ";
    cin >> cnpj;
    emp = new empresa(cnpj);

//=======================================================================//
    printf("\n");
    cout << "========== Cadastrar Funcionarios Da Empresa ==========" << endl << endl;
    cout << "Digite quantos funcionarios deseja cadastrar: ";
    cin >> qtd_func;

    func = new funcionario[qtd_func];

    for (int i = 0; i < qtd_func; i++)
    {
        cout << "Digite o cargo do funcionario: ";
        cin >> cargo[i];
        cout << "Digite o CPF do funcionario [" << i + 1 << "]: ";
        cin >> cpf;
        cout << "Digite o salario do funcionario [" << i + 1 << "]: ";
        cin >> salario;
        cout << "Digite o idade do funcionario [" << i + 1 << "]: ";
        cin >> idade;
        cout << "Digite o departamento do funcionario [" << i + 1 << "]: ";
        cin >> departamento;
        
        if (strcmp(cargo[i], grt) == 0) // verifica se a palavra digitada é "gerente", se for, acrescenta 15% de salario
        {
            salario += (salario * 0.15);
        }

        if (departamento == 1)
        {
            salario += (salario * 0.1); // dando 10% para quem for do departamento 1
        }
        
        func[i].set_cpf(cpf);
        func[i].set_salario(salario);
        func[i].set_idade(idade);
        func[i].set_dapartamento(departamento);
    }

    printf("\n");
//=================================================================================================//
    system("cls");

    cout << "CNPJ Da Empresa: " << emp->get_cnpj() << endl << endl;
    cout << "====== Funcionarios ======" << endl;

    
    for (int i = 0; i < qtd_func; i++)
    {
    printf("\n");
    cout << "O cargo do funcionaro[" << i + 1 << "]: " << cargo[i] << endl;
    cout << "cpf do funcionario[" << i + 1 << "]: " << func[i].get_cpf() << endl;
    cout <<"salario do funcionario["<< i + 1 << "]: " << func[i].get_salario()<< endl;
    cout <<"idade do funcionario["<< i + 1 << "]: " << func[i].get_idade()<< endl;
    cout <<"departamento do funcionario["<< i + 1 << "]: " << func[i].get_departamento()<< endl;
    
    }


}