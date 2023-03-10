#include <iostream>
#include "Classes.c++"
using namespace std;



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
            delete[] pessoas;
            delete[] alunos;
            
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
            delete[] professores;
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
            delete[] turmas;
            
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