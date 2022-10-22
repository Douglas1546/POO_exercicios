#include <iostream>
using namespace std;

class pessoa{

    long cpf;
    int telefone;
    

public:

    pessoa(long cp = 0, int t = 0): cpf(cp), telefone(t){
        //cout << "pessoa criada!!!" << endl;
    }

    ~pessoa(){
        cout << "pessoa deletada!!!";
    }

    long get_cpf(){
        return cpf;
    }
    void set_cpf(long c){
        cpf = c;
    }
    int get_telefone(){
        return telefone;
    }
    void set_telefone(int t){
        telefone = t;
    }

};

//==========================================================================================================================================================//

class aluno : public pessoa{
    int matricula;
    float CRA;
    pessoa *pessoas;
    aluno *alunos;
public:
    
    aluno(int m = 0, float c = 0, aluno *a = 0, pessoa *p = 0): matricula(m), CRA(c){
        //pessoas = new pessoa(p->get_cpf(), p->get_telefone());
        alunos = a;
        pessoas = p;
    }

    ~aluno(){
        delete[] pessoas;
        delete[] alunos;
        cout << "pessoas e alunos deletados!" << endl;
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
    void set_CRA(float c){
        CRA = c;
    }
    pessoa *get_pessoas(){
        return pessoas;
    }
    void set_pessoas(pessoa *p){
        pessoas = p;
    }
    aluno *get_alunos(){
        return alunos;
    }
    void set_alunos(aluno *a){
        alunos = a;
    }
};

//==========================================================================================================================================================//

class professor : public pessoa{
    long codigo_professor;
    professor *professores;

public:
    professor(long c = 0, professor *p = 0): codigo_professor(c){
        professores = p;
        cout << "professor criado!!!";
    }

    ~professor(){
        delete[] professores;
        cout << "professor deletado!!!";
    }

    long get_codigo_professor(){
        return codigo_professor;
    }
    void set_codigo_professor(long c){
        codigo_professor = c;
    }
    professor *get_codigo_professores(){
        return professores;
    }
    void set_codigo_professor(professor *p){
        professores = p;
    }

};

//==========================================================================================================================================================//

class turma{
    
    int codigo_disciplina;
    int codigo_turma;
    int qtd_alunos;
    turma *turmas;
    
public:
    turma(int cd = 0, int ct = 0, int qtd = 0, turma *t = 0): codigo_disciplina(cd), codigo_turma(ct), qtd_alunos(qtd){
        turmas = t;
        cout << "Turma criada!!!";
    }
    ~turma(){
        delete[] turmas;
        cout << "Turma deletada!!!";
    }
    int get_codigo_disciplina(){
        return codigo_disciplina;
    }
    void set_codigo_disciplina(int cd){
        codigo_disciplina = cd;
    }
    int get_codigo_turma(){
        return codigo_turma;
    }
    void set_codigo_turma(int ct){
        codigo_turma = ct;
    }
    int get_qtd_alunos(){
        return qtd_alunos;
    }
    void set_qtd_alunos(int qtd){
        qtd_alunos = qtd;
    }
    turma *get_turmas(){
        return turmas;
    }
    void set_turmas(turma *t){
        turmas = t;
    }

};

int main(){

    system("cls");

    professor *professores;
    aluno *alunos;
    pessoa *pessoas;
    turma *turmas;

    int op;

    long cpf;
    int telefone;

    int matricula;
    float CRA;

    int codigo_disciplina;
    int codigo_turma;
    int qtd_alunos;

    long codigo_professor;

    //==================================================================//
    do
    {
        
        printf("\n\n 1 - Cadastrar Alunos \n 2 - Cadastrar professores \n 3 - Cadastrar turmas \n 4 - Imprimir lista alunos \n 5 - Imprimir lista professores \n 6 - Imprimir a lista de turmas \n 0 - Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        
        switch (op)
        {
        case 1:
            system("cls");
            int qtd_alunos;

            printf("Digite quantos alunos deseja cadastrar: ");
            scanf("%d", &qtd_alunos);
            pessoas = new pessoa[qtd_alunos];
            alunos = new aluno[qtd_alunos];

            for (int i = 0; i < qtd_alunos; i++)
            {
                printf("\n");
                cout << "Digite o cpf do aluno [" << i + 1 << "]: ";
                cin >> cpf;

                cout << "Digite o telefone do aluno [" << i + 1 << "]: ";
                cin >> telefone;

                cout << "Digite a matricula do aluno [" << i + 1 << "]: ";
                cin >> matricula;

                cout << "Digite o CRA do aluno [" << i + 1 << "]: ";
                cin >> CRA;

                pessoas[i].set_cpf(cpf);
                pessoas[i].set_telefone(telefone);
                alunos[i].set_matricula(matricula);
                alunos[i].set_CRA(CRA);
            
            }
            //delete pessoas;
            //delete alunos;
            
            break;
        case 2:
            system("cls");
            int qtd_professores;
            printf("Digite quantos professores deseja cadastrar: ");
            scanf("%d", &qtd_professores);

            professores = new professor[qtd_professores];

            for (int i = 0; i < qtd_professores; i++)
            {
                cout << "Digite o cpf do professor [" << i + 1 << "]: ";
                cin >> cpf;

                cout << "Digite o telefone do professor [" << i + 1 << "]: ";
                cin >> telefone;

                cout << "Digite o codigo do professor da turma [" << i + 1 << "]: ";
                cin >> codigo_professor;

                professores[i].set_cpf(cpf);
                professores[i].set_telefone(telefone);
                professores[i].set_codigo_professor(codigo_professor);
            }
            //delete professores;
            break;
        case 3:
            system("cls");
            int qtd_turmas;
            printf("Digite quantidade de turmas que deseja cadastrar: ");
            scanf("%d", &qtd_turmas);

            turmas = new turma[qtd_turmas];

            for (int i = 0; i < qtd_turmas; i++)
            {
                cout << "Digite o codigo da disciplina da turma [" << i + 1<< "]: ";
                cin >> codigo_disciplina;

                cout << "Digite o codigo da turma [" << i + 1<< "]: ";
                cin >> codigo_turma;

                cout << "Digite a quantidade de alunos da turma [" << i + 1<< "]: ";
                cin >> qtd_alunos;

                turmas[i].set_codigo_disciplina(codigo_disciplina);
                turmas[i].set_codigo_turma(codigo_turma);
                turmas[i].set_qtd_alunos(qtd_alunos);
            }
           //delete turmas;
            
            break;
        case 4:
            system("cls");
            for (int i = 0; i < qtd_alunos; i++)
            {
                printf("\n");
                cout << "CPF do aluno: " << pessoas[i].get_cpf() << endl;
                cout << "Telefone do aluno: " << pessoas[i].get_telefone() << endl;
                cout << "Matricula do aluno: " << alunos[i].get_matricula() << endl;
                cout << "CRA do aluno: " << alunos[i].get_CRA() << endl;
            }
            break;

        case 5:
            system("cls");
            for (int i = 0; i < qtd_professores; i++)
            {
                printf("\n");
                cout << "CPF do professor: " << professores[i].get_cpf() << endl;
                cout << "Telefone do professor: " << professores[i].get_telefone() << endl;
                cout << "Matricula do professor: " << professores[i].get_codigo_professor() << endl;
            }
            break;
        case 6:
            system("cls");
            for (int i = 0; i < qtd_turmas; i++)
            {
                printf("\n");
                cout << "Codigo da disciplina da turma: " << turmas[i].get_codigo_disciplina() << endl;
                cout << "Codigo da turma: " << turmas[i].get_codigo_turma() << endl;
                cout << "Quantidade de alunos na turma: " << turmas[i].get_qtd_alunos() << endl;
            }
            
            break;
        default:
            if (op != 0)
            {
                printf("\nOpcao invalida!\n");
            }

            break;
        }

    } while (op != 0);

 

   
}