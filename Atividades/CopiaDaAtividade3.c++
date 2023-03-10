#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#define TAM_MAX 3
#define N_DISCIPLINAS 10

using namespace std;

class pessoa{
    string nome;
    int idade;
    float altura;
public:
    pessoa(string n, int i, float a):nome(n),idade(i),altura(a){

    }
    string get_nome(){
        return nome;
    }
    void set_nome(string n){
        nome = n;
    }
    int get_idade(){
        return idade;
    }
    void set_idade(int i){
        idade = i;
    }
    float get_altura(){
        return altura;
    }  
    void set_altura(float a){
        altura = a;
    }
    
};
//=================================================================================================================================//
class aluno : public pessoa{
    int matricula;
    float CRA;
    string *disciplinas[N_DISCIPLINAS];
public:
    aluno(string n = 0, int i = 0, float a = 0, int m = 0, float cr = 0): pessoa(n,i,a), matricula(m), CRA(cr){
        cout << "\nAluno cadastrado com sucesso!\n";
    }
    int get_matricula(){
        return matricula;
    }
    void set_matricula(int m){
        matricula = m;
    }
    float get_CRA(){
        return CRA;
    }
    void set_CRA(float cr){
        CRA = cr;
    }
    int add_disciplina(int pos, string *disc){
        if (pos >= N_DISCIPLINAS)
        {
            printf("Posicao invalida!");
            return -1;
        }
        else{
            disciplinas[pos] = disc;
        }
        return pos;
        
    }
    void print_info(){
        for (int i = 0; i < 2; i++)
        {
            //cout << disciplinas[i]->get_nome() << endl;
        }
        
    }
};
//=================================================================================================================================//
class professor : public pessoa{
    int cod_prof;
    int ano_titul;
    int carga_hr;
    professor *disciplinas[N_DISCIPLINAS];
public:
    professor(string n, int i, float a, int cp, int at, int ch):pessoa(n,i,a), cod_prof(cp), ano_titul(at), carga_hr(ch){
        cout << "\nProfessor cadastrado com sucesso!\n";
    }
    int get_cod_prof(){
        return cod_prof;
    }
    void set_cod_prof(int cp){
        cod_prof = cp;
    }
    int get_ano_titul(){
        return ano_titul;
    }
    void set_ano_titul(int at){
        ano_titul = at;
    }
    int get_carga_hr(){
        return carga_hr;
    }
    void set_carga_hr(int ch){
        carga_hr = ch;
    }
    int add_disciplina(int pos, professor *disc){
        if (pos >= N_DISCIPLINAS)
        {
            printf("Posicao invalida!");
            return -1;
        }
        else{
            disciplinas[pos] = disc;
        }
        return pos;
        
    }
    void print_info(){
        for (int i = 0; i < 2; i++)
        {
            cout << disciplinas[i]->get_nome() << endl;
        }
        
    }
};
//=================================================================================================================================//
class disciplina{
    string nome;
    int codigo;
    int c_horaria;
public:
    disciplina(string n, int c, int ch): nome(n), codigo(c), c_horaria(ch){
        cout << "\nDisciplina cadastrada com sucesso!\n";
    }
    string get_nome(){
        return nome;
    }
    void set_nome(string n){
        nome = n;
    }
    int get_codigo(){
        return codigo;
    }
    void set_codigo(int c){
        codigo = c;
    }
    int get_c_horaria(){
        return c_horaria;
    }
    void set_c_horaria(int ch){
        c_horaria = ch;
    }
};
//=================================================================================================================================//
vector<professor> p;
int cadastrarProfessores(){
    string nome;
    int idade, cod_prof, ano_titul, carga_hr;
    float altura;

    printf("Digite o nome do professor: ");
    cin >> nome;
    printf("Digite a idade do professor: ");
    cin >> idade;
    printf("Digite a altura do professor: ");
    cin >> altura;
    printf("Digite o codigo do professor: ");
    cin >> cod_prof;
    printf("Digite a ano de titulacao do professor: ");
    cin >> ano_titul;
    printf("Digite a carga horaria semanal do professor: ");
    cin >> carga_hr;
    professor profe(nome,idade,altura, cod_prof, ano_titul, carga_hr);
    p.push_back(profe);
}
//=================================================================================================================================//
vector<disciplina> d;
int cadastrarDisciplina(){
    string nome;
    int codigo;
    int c_horaria;

    printf("Digite o nome da disciplina: ");
    cin >> nome;
    printf("Digite o codigo da disciplina: ");
    cin >> codigo;
    printf("Digite a carga horaria da disciplina: ");
    cin >> c_horaria;
    
    disciplina disc(nome, codigo, c_horaria);
    d.push_back(disc);
}
//=================================================================================================================================//
vector<aluno> alunos;
int cadastrarAluno(){
    string nome;
    int idade, matricula;
    float altura, CRA;

    printf("Digite o nome do aluno: ");
    cin >> nome;
    printf("Digite a idade do aluno: ");
    cin >> idade;
    printf("Digite a altura do aluno: ");
    cin >> altura;
    printf("Digite a matricula do aluno: ");
    cin >> matricula;
    printf("Digite o CRA do aluno: ");
    cin >> CRA;
    aluno a1(nome,idade,altura,matricula,CRA);
    alunos.push_back(a1);
}
//=================================================================================================================================//
int vincularDisciplinaAluno(){
    int idx_aluno;
    string nome_aluno;
    string nome_disc;
    int index;

    printf("\n=====Alunos Disponiveis=====\n");
    for (int i = 0; i < alunos.size(); i++){
            cout << "Nome["<< i << "]: " << alunos[i].get_nome() << endl << endl;
    }
    printf("\n============================\n");
    printf("\nDigite o aluno que voce deseja vincular a uma disciplina: ");
    cin >> nome_aluno;
    printf("\nAgora digite o indice do aluno para confirmar: ");
    cin >> idx_aluno;
    
    for (int i = 0; i < alunos.size(); i++)
    {
        if (nome_aluno == alunos[idx_aluno].get_nome())
        {
            printf("\n=====Disciplinas disponiveis=====\n");
            for (int i = 0; i < d.size(); i++){
                cout << "Nome["<< i << "]: "<< d[i].get_nome() << endl << endl;
            }
            printf("\n=================================\n");
            printf("\nDigite o numero do indice da disciplina que deseja vincular ao aluno escolhido: ");
            cin >> index;

            nome_disc = d[index].get_nome();

            alunos[index].add_disciplina(0, &nome_disc);
            cout << "disciplina ["  << nome_disc << "] vinculada ao aluno: "<< alunos[index].get_nome() << endl;
        }
        else{
            printf("\nEste aluno nao esta cadastrado no sistema!\n");
            vincularDisciplinaAluno(); // Fiz uma recursão para não ter q botar dentro de um loop.
        }
    }

    
}

int main(){
    int op;
     do
    {
        printf("\n========Cadastro Geral========\n");
        printf("\n 1 - Cadastrar Professor\n 2 - Cadastrar Disciplina\n 3 - Cadastrar Aluno\n 4 - Exibir Professores\n 5 - Exibir Alunos");
        printf("\n 6 - Exibir Disciplinas\n 7 - Vincular Aluno a Disciplina \n 0 - Sair");
        printf("\n\n Digite a opcao desejada: ");
        scanf("%d", &op);
        
        switch (op)
        {
        case 1:
            system("cls");
            cadastrarProfessores();
            break;
        case 2:
            system("cls");
            cadastrarDisciplina();
            break;
        case 3:
            system("cls");
            cadastrarAluno();
            break;
        case 4:
            system("cls");
            printf("========Professores========\n\n");
            for (int i = 0; i < p.size(); i++){
            cout << "Nome: " << p[i].get_nome() << endl;
            cout << "Idade: " << p[i].get_idade() << endl;
            cout << "Altura: " << p[i].get_altura() << endl;
            cout << "Codigo do professor: " << p[i].get_cod_prof() << endl;
            cout << "Ano de titulacao: " << p[i].get_ano_titul() << endl;
            cout << "Carga horaria semanal: " << p[i].get_carga_hr() << endl << endl;
            }
            printf("============================\n");
            break;
        case 5:
            system("cls");
            printf("========Alunos========\n\n");
            for (int i = 0; i < alunos.size(); i++){
            cout << "Nome: " << alunos[i].get_nome() << endl;
            cout << "Idade: " << alunos[i].get_idade() << endl;
            cout << "Altura: " << alunos[i].get_altura() << endl;
            cout << "Matricula: " << alunos[i].get_matricula() << endl;
            cout << "CRA: " << alunos[i].get_CRA() << endl << endl;
            }
            printf("======================\n");
            break;
        case 6:
            system("cls");
            printf("========Disciplinas========\n\n");
            for (int i = 0; i < d.size(); i++)
            {
                cout << "Nome: " << d[i].get_nome() << endl;
                cout << "Codigo: " << d[i].get_codigo() << endl;
                cout << "Carga horaria: " << d[i].get_c_horaria() << endl << endl;
            }
            printf("============================\n");
            break;
        case 7:
            system("cls");
            vincularDisciplinaAluno();
            break;
        default:
            break;
        }
    } while (op!=0);
    


}