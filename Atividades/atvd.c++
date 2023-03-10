#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <string.h>
#define TAM_MAX 3
#define DISCIPLINAS 3

using namespace std;

class pessoa{
    string nome;
    int idade;
    float altura;
public:
    pessoa(string n, int i, float a):nome(n),idade(i),altura(a){}
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

class aluno : public pessoa{
    int matricula;
    float CRA;
    string disciplinas[DISCIPLINAS];
public:
    aluno(string n = 0, int i = 0, float a = 0, int m = 0, float cr = 0): pessoa(n,i,a), matricula(m), CRA(cr){}
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
    int add_disciplinas(int pos, string disc){
        if (pos >= DISCIPLINAS)
        {
            printf("Posicao invalida!");
            return -1;
        }
        else{
            disciplinas[pos] = disc;
        }
        return pos;
        
    }
    void *get_disciplinas(){
        return disciplinas;
    }
    void print_info(){
        for (int i = 0; i < DISCIPLINAS; i++)
        {
           cout << disciplinas[i] << endl;
        }
        
    }
};

class professor : public pessoa{
    int cod_prof;
    int ano_titul;
    int carga_hr;
    string disciplinas[DISCIPLINAS];
public:
    professor(string n, int i, float a, int cp, int at, int ch):pessoa(n,i,a), cod_prof(cp), ano_titul(at), carga_hr(ch){}
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
    int add_disciplinas(int pos, string disc){
        if (pos >= DISCIPLINAS)
        {
            printf("Posicao invalida!");
            return -1;
        }
        else{
            disciplinas[pos] = disc;
        }
        return pos;
        
    }
    void *get_disciplinas(){
        return disciplinas;
    }
    void print_info(){
        for (int i = 0; i < DISCIPLINAS; i++)
        {
            cout << disciplinas[i] << endl;
        }
        
    }
};

class disciplina{
    string nome;
    int codigo;
    int c_horaria;
    vector<disciplina> di;
public:
    disciplina(string n, int c, int ch): nome(n), codigo(c), c_horaria(ch){}
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

int AssociarDisciplinaAluno(){
    system("cls");
    int idx_aluno;
    char nome_aluno[1][10];
    string nome_disc;
    int index, idx_disciplinas;
    char convert_array[1][10];

    printf("\nAlunos Disponiveis\n\n");
    for (int i = 0; i < alunos.size(); i++){
            cout << "Nome["<< i << "]: " << alunos[i].get_nome() << endl << endl;
    }
    printf("\nDigite o nome aluno que voce deseja vincular a uma disciplina: ");
    cin >> nome_aluno[1];
    printf("\nAgora digite o indice do aluno para confirmar: ");
    cin >> idx_aluno;
    
    strcpy(convert_array[1], alunos[idx_aluno].get_nome().c_str());

    for (int i = 0; i < alunos.size(); i++)
    {
        if (strcmp(nome_aluno[1], convert_array[1]))
        {
            printf("\nDisciplinas disponiveis\n");
            for (int i = 0; i < d.size(); i++){
                cout << "Nome["<< i << "]: "<< d[i].get_nome() << endl << endl;
            }
            printf("\nDigite o numero do indice da disciplina que deseja vincular ao aluno escolhido: ");
            cin >> index;
            printf("O aluno pode possuir ate [%d] disciplinas, digite uma posicao para inserir: ", DISCIPLINAS);
            cin >> idx_disciplinas;

            nome_disc = d[index].get_nome();

            alunos[idx_aluno].add_disciplinas(idx_disciplinas, nome_disc);
            cout << "Disciplina ["  << nome_disc << "] vinculada ao aluno: "<< alunos[idx_aluno].get_nome() << endl;
            
        }
        else{
            printf("\nEste aluno nao esta cadastrado no sistema!\n");
            AssociarDisciplinaAluno();
        }
    }
}

int AssociarDisciplinaProfessor(){
    system("cls");
    int idx_professor;
    char nome_professor[1][10];
    string nome_disc;
    int index, idx_disciplinas;
    char convert_array[1][10];

    for (int i = 0; i < p.size(); i++){
            cout << "Nome["<< i << "]: " << p[i].get_nome() << endl << endl;
    }
    printf("\nDigite o nome professor que voce deseja vincular a uma disciplina: ");
    cin >> nome_professor[1];
    printf("\nAgora digite o indice do professor para confirmar: ");
    cin >> idx_professor;
    
    strcpy(convert_array[1], p[idx_professor].get_nome().c_str()); 

    for (int i = 0; i < p.size(); i++)
    {
        if (strcmp(nome_professor[1], convert_array[1]))
        {
            for (int i = 0; i < d.size(); i++){
                cout << "Nome["<< i << "]: "<< d[i].get_nome() << endl << endl;
            }
            printf("\nDigite o numero do indice da disciplina que deseja vincular ao professor escolhido: ");
            cin >> index;
            printf("O professor pode possuir ate [%d] disciplinas, digite uma posicao para inserir: ", DISCIPLINAS);
            cin >> idx_disciplinas;

            nome_disc = d[index].get_nome();

            p[idx_professor].add_disciplinas(idx_disciplinas, nome_disc);
            cout << "Disciplina ["  << nome_disc << "] vinculada ao professor: "<< p[idx_professor].get_nome() << endl;
            
        }
        else{
            printf("\nEste professor nao esta cadastrado no sistema!\n");
            AssociarDisciplinaProfessor();
        }
    }
}


int main(){
    int op;
     do
    {
        printf("\n 1 - Cadastrar Professor\n 2 - Cadastrar Disciplina\n 3 - Cadastrar Aluno\n 4 - Exibir Professores\n 5 - Exibir Alunos");
        printf("\n 6 - Exibir Disciplinas\n 7 - Associar Aluno a Disciplina \n 8 - Associar Professor a Disciplina\n 9 - Listar disciplinas de aluno por matricula");
        printf("\n 10 - Listar disciplinas de professor\n 0 -  Sair");
        printf("\n\n  Digite uma opcao: ");
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
            printf("Professores\n\n");
            for (int i = 0; i < p.size(); i++){
            cout << "Nome: " << p[i].get_nome() << endl;
            cout << "Idade: " << p[i].get_idade() << endl;
            cout << "Altura: " << p[i].get_altura() << endl;
            cout << "Codigo do professor: " << p[i].get_cod_prof() << endl;
            cout << "Ano de titulacao: " << p[i].get_ano_titul() << endl;
            cout << "Carga horaria semanal: " << p[i].get_carga_hr() << endl << endl;
            }
            break;
        case 5:
            system("cls");
            printf("Alunos\n\n");
            for (int i = 0; i < alunos.size(); i++){
            cout << "Nome: " << alunos[i].get_nome() << endl;
            cout << "Idade: " << alunos[i].get_idade() << endl;
            cout << "Altura: " << alunos[i].get_altura() << endl;
            cout << "Matricula: " << alunos[i].get_matricula() << endl;
            cout << "CRA: " << alunos[i].get_CRA() << endl << endl;
            }
            break;
        case 6:
            system("cls");
            printf("Disciplinas\n\n");
            for (int i = 0; i < d.size(); i++)
            {
                cout << "Nome: " << d[i].get_nome() << endl;
                cout << "Codigo: " << d[i].get_codigo() << endl;
                cout << "Carga horaria: " << d[i].get_c_horaria() << endl << endl;
            }
            break;
        case 7:
            system("cls");
            AssociarDisciplinaAluno();
            break;
        case 8:
            AssociarDisciplinaProfessor();
            break;
        case 9:
            system("cls");
            int alt;
            for (int i = 0; i < alunos.size(); i++){
                cout << "["<< i << "] Matricula: |" << alunos[i].get_matricula() << "|, Nome do aluno: |"<< alunos[i].get_nome() << "|." << endl;
            }
            printf("\nDigite o indice do aluno desejado para ver suas disciplinas vinculadas: ");
            cin >> alt;
            cout << "Disciplinas de ["<< alunos[alt].get_nome() << "]: " << endl << endl;
            alunos[alt].print_info();
            break;
        case 10:
            system("cls");
            int opc;
            for (int i = 0; i < p.size(); i++){
                cout << "["<< i << "] Codigo Do Professor: |" << p[i].get_cod_prof() << "|, Nome do professor: |"<< p[i].get_nome() << "|." << endl;
            }
            printf("\nDigite o indice do professor desejado para ver suas disciplinas vinculadas: ");
            cin >> opc;
            cout << "Disciplinas de ["<< p[opc].get_nome() << "]: " << endl << endl;
            p[opc].print_info();
            break;
        default:
            break;
        }
    } while (op!=0);
    


}