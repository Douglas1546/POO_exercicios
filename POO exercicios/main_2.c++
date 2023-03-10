#include <iostream>
#include "Classes.c++"
using namespace std;

int main(){

    system("cls");
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

            cout << "Digite o cpf do aluno: ";
            cin >> cpf;

            cout << "Digite o telefone do aluno: ";
            cin >> telefone;

            cout << "Digite a matricula do aluno: ";
            cin >> matricula;

            cout << "Digite o CRA do aluno: ";
            cin >> CRA;

            aluno alunos(cpf,telefone,matricula,CRA);
            cout << alunos.get_cpf() << endl;
            cout << alunos.get_telefone() << endl;
            cout << alunos.get_matricula() << endl;
            cout << alunos.get_CRA() << endl;


   
}