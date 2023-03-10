#include <iostream>
#include "Classes.c++"
using namespace std;

aluno alunos;
professor professores;

void imprimir_professores(){
    system("cls");

    cout << "CPF do professor: " << professores.get_cpf() << endl;
    cout << "Telefone do professor: " << professores.get_telefone() << endl;
    cout << "Matricula do professor: " << professores.get_codigo_professor() << endl;

}

void imprimir_alunos(int quantidade){
    system("cls");

    cout << "CPF do aluno: " << alunos.get_cpf() << endl;
    cout << "Telefone do aluno: " << alunos.get_telefone() << endl;
    cout << "Matricula do aluno: " << alunos.get_matricula() << endl;
    cout << "CRA do aluno: " << alunos.get_CRA() << endl;

}

int main(){

    system("cls");
    int op;
    int quantidade;

    long cpf[quantidade];
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
        
        printf("\n 1 - Cadastrar Alunos \n 2 - Cadastrar professores \n 3 - Imprimir lista alunos \n 4 - Imprimir lista professores \n 0 - Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        
        switch (op)
        {
        case 1:
            printf("Digite quantos alunos deseja cadastrar: ");
            scanf("%d", &quantidade);

            for (int i = 0; i < quantidade; i++)
            {
            printf("\n");
            cout << "Digite o cpf do aluno [" << i << "]: ";
            cin >> cpf[i];

            cout << "Digite o telefone do aluno [" << i << "]: ";
            cin >> telefone;

            cout << "Digite a matricula do aluno [" << i << "]: ";
            cin >> matricula;

            cout << "Digite o CRA do aluno [" << i << "]: ";
            cin >> CRA;
            
            
            aluno(cpf[i],telefone,matricula,CRA);

            alunos.set_cpf(cpf[i]);
            alunos.set_telefone(telefone);
            alunos.set_matricula(matricula);
            alunos.set_CRA(CRA);
            }
            break;
        case 2:
            /*cout << "Digite o cpf do professor: ";
            cin >> cpf;

            cout << "Digite o telefone do professor: ";
            cin >> telefone;

            cout << "Digite o codigo do professor da turma: ";
            cin >> codigo_professor;

            professor(cpf, telefone, codigo_professor);

            professores.set_cpf(cpf);
            professores.set_telefone(telefone);
            professores.set_codigo_professor(codigo_professor);
            break;*/
        case 3:
            imprimir_alunos(quantidade);
            break;
        case 4:
            imprimir_professores();
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

























class aluno : public pessoa{
    int matricula;
    float CRA;
    pessoa *pessoas;
    aluno *alunos;
public:
    
    aluno(int m, float c, aluno *a, pessoa *p): matricula(m), CRA(c){
        //pessoas = new pessoa(p->get_cpf(), p->get_telefone());
        alunos = a;
        pessoas = p;
    }

    ~aluno(){
        delete[] pessoas;
        delete[] alunos;
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