#include <iostream>

#define TAM_TURMA 3
#define TIT_MSC 2
#define TIT_DSC 3

using std::cout;
using std::endl;

class pessoa {
    int cpf;
    int idade;
    float altura;
    static int contador;
public:
    pessoa(int c, int i, float a):cpf(c), idade(i), altura(a) {
        contador++;
        cout << "Nova pessoa: " << cpf << endl;
    }
    ~pessoa() {
        contador--;
    }
    /* gets e sets */
    int get_cpf() {
        return cpf;
    }
    void set_cpf(int c) {
        cpf = c;
    }    
    float get_altura() {
        return altura;
    }
    void set_altura(float a) {
        altura = a;
    }
    static int get_contador() {
        return contador;
    }
};

int pessoa::contador = 0;

class professor : public pessoa {
    int matricula;
    int titulacao;
    int ano_admissao;
public:
    professor(int c, int i, float a, int m, int t, int aa):
                pessoa(c, i, a), matricula(m), titulacao(t), ano_admissao(aa) {
        cout << "Novo professor: " << matricula << endl;
    }
    /* gets e sets */
};

class aluno : public pessoa {
    int matricula;
    float cra;
public:
    aluno(int c, int i, float a, int m, float cr):
                pessoa(c, i, a), matricula(m), cra(cr) {
        cout << "Novo aluno: " << matricula << endl;
    }
    float get_cra() {
        return cra;
    }
    void set_cra(float c) {
        cra = c;
    }
    /* gets e sets */
};

class turma {
    int codigo;
    professor *prof_responsavel;
    aluno *matriculados[TAM_TURMA];
public:
    turma(int c, professor *prof): codigo(c), prof_responsavel(prof) {
        cout << "Nova turma: " << codigo << endl;
    }
    int get_codigo() {
        return codigo;
    }
    void set_codigo(int c) {
        codigo = c;
    }
    int add_aluno(int pos, aluno *a) {
        if (pos >= TAM_TURMA) 
            return -1;
        else {
            matriculados[pos] = a;
        }
        return pos;
    }
    float media() {
        float soma = 0;
        for (int i = 0; i < TAM_TURMA; i++) {
            soma += matriculados[i]->get_cra();
        }
        return (float)(soma / TAM_TURMA);
    }
    /* gets e sets */    
};

int main(void) {
/*
Faça o programa cadastrar duas turmas com um professor diferente em cada e
três alunos e diferentes disciplinas. Depois use os métodos criados e exiba:
a) Quantidade de pessoas cadastradas no sistema
b) Média das notas dos alunos de cada uma das turmas
c) Média da altura das pessoas cadastradas no sistema
d) Média de idade dos professores e média de idade dos alunos
*/
    pessoa *grupo[2+(TAM_TURMA*2)];

    professor p1(1011, 35, 1.8, 9001, TIT_DSC, 2014);
    professor p2(1100, 39, 1.72, 9004, TIT_MSC, 2009);
    grupo[0] = &p1;
    grupo[1] = &p2;

    turma t1(1000, &p1);
    turma t2(2000, &p2);

    aluno a1(9871, 19, 1.67, 4872, 7.2);
    aluno a2(9150, 29, 1.87, 4072, 5.2);
    aluno a3(9321, 17, 1.7, 4172, 4.5);

    grupo[2] = &a1;
    grupo[3] = &a2;
    grupo[4] = &a3; 

    aluno a4(3871, 18, 1.57, 4151, 8.2);
    aluno a5(3150, 23, 1.67, 4273, 5.2);
    aluno a6(2321, 27, 1.77, 4371, 5.5);

    grupo[5] = &a4;
    grupo[6] = &a5;
    grupo[7] = &a6; 

    t1.add_aluno(0, &a1);
    t1.add_aluno(1, &a2);
    t1.add_aluno(2, &a3);

    t2.add_aluno(0, &a4);
    t2.add_aluno(1, &a5);
    t2.add_aluno(2, &a6);

    /* a) */
    cout << "Pessoas cadastradas: " << pessoa::get_contador() << endl;
    /* b) */
    cout << "Media turma 1 (" << t1.get_codigo() << "): " << t1.media() << endl;
    cout << "Media turma 2 (" << t2.get_codigo() << "): " << t2.media() << endl;
    /* c) */
    float soma_al = 0;
    for (int i = 0; i < (2+(TAM_TURMA*2)); i++) {
        soma_al += grupo[i]->get_altura();
    }
    cout << "Media de altura das pessoas: " << (soma_al / (2+(TAM_TURMA*2))) << endl;
    /* d) */


}