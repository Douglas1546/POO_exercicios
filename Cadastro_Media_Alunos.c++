#include <iostream>
#include <stdlib.h>
#define TAM_TURMA 4
using namespace std;

class aluno
{
    // char nome[30];
    int matricula;
    float *notas;
    int qtd_notas;

    void create_notas(int qtd)
    {
        notas = (float *)malloc(sizeof(float) * qtd_notas);
    }

public:
    aluno(int mat, int qtd = 1)
    { // metodo construtor
        matricula = mat;
        if (qtd_notas <= 0)
        {
            qtd = 1;
        }
        qtd_notas = qtd;

        create_notas(qtd);
        cout << "aluno " << matricula << " criado!" << endl;
    }

    ~aluno()
    {
        if (qtd_notas > 0)
        {
            free(notas);
        }
        cout << "Aluno " << matricula << " liberado!" << endl;
    }

    int get_qtd_notas()
    {
        return qtd_notas;
    }

    bool set_notas(float nota, int idx)
    {
        if (qtd_notas > 0)
        {
            notas[idx] = nota;
            return true;
        }
        return false;
    }

    float get_nota(int idx)
    {
        if ((qtd_notas > 0) && (idx < qtd_notas))
        {
            return notas[idx];
        }
        return -1;
    }

    void set_matricula(int mat)
    {
        matricula = mat;
    }

    int get_matricula()
    {
        return matricula;
    }

    float media()
    {
        float soma = 0;
        if (qtd_notas > 0)
        {
            for (int i = 0; i < qtd_notas; i++)
            {
                soma += notas[i];
            }
            return soma / qtd_notas;
        }
        else
        {
            return -1;
        }
    }
};

int main(void)
{
    system("cls");
    int mat, qtd;
    float nota;

    for (int i = 1; i < TAM_TURMA; i++)
    {
        cout << "Digite a matricula do aluno " << i << ": ";
        cin >> mat;

        cout << "Digite a quantidade de notas que o aluno " << i << " tem: ";
        cin >> qtd;

        aluno *a1 = new aluno(mat, qtd);

        for (int i = 0; i < a1->get_qtd_notas(); i++)
        {
            cout << "Digite a nota[" << i << "]: ";
            cin >> nota;
            a1->set_notas(nota, i);
        }
        cout << "media do aluno: " << a1->media() << endl;
        delete a1;
    }
    return 0;
}