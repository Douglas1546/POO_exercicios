#include <stdio.h>
#include <iostream>

// Classes

class Pessoa // Superclasse
{
private:
    int cpf, idade;
    float altura;
    static int contador_pessoas;

public:
    // Metodos construtor e destrutor

    Pessoa(int c, int i, float h)
    {
        set_cpf(c);
        set_idade(i);
        set_altura(h);
        contador_pessoas++;
        printf("\nPessoa criada!");
    }
    ~Pessoa()
    {
        printf("\nPessoa eliminada!");
    }
    // Metodos getter's e setter's
    void set_cpf(int c)
    {
        cpf = c;
    }
    void set_idade(int i)
    {
        idade = i;
    }
    void set_altura(int h)
    {
        altura = h;
    }
    int get_cpf()
    {
        return cpf;
    }
    int get_idade()
    {
        return idade;
    }
    float get_altura()
    {
        return altura;
    }
    static int get_contador_pessoas()
    {
        return contador_pessoas;
    }
    // Demais Metodos
};

int Pessoa::contador_pessoas = 0;

class Professor : public Pessoa // Estende da classe Pessoa
{
private:
    int matricula_professor, ano_admissao, titulacao;

public:
    // Metodos construtor e destrutor
    Professor(int c, int i, float h, int m, int ad, int tl) : Pessoa(c, i, h)
    { // Ao criar instancia professor cria instancia pessoa
        set_matricula_professor(m);
        set_ano_admissao(ad);
        set_titulacao(tl);
        printf("\nProfessor criado");
    }
    ~Professor()
    {
        printf("\nProfessor Eliminado!");
    }
    // Metodos getter's e setter's
    void set_matricula_professor(int m)
    {
        matricula_professor = m;
    }
    void set_ano_admissao(int ad)
    {
        ano_admissao = ad;
    }
    void set_titulacao(int tl)
    {
        titulacao = tl;
    }
    int get_matriculacao_professor()
    {
        return matricula_professor;
    }
    int get_ano_admissao()
    {
        return ano_admissao;
    }
    int get_titulacao()
    {
        return titulacao;
    }
};

class Aluno : public Pessoa // Estende da classe Pessoa
{
private:
    int matricula_aluno;
    float cra;

public:
    // Metodos construtor e destrutor
    Aluno(int c, int i, float h, int m, float n) : Pessoa(c, i, h)
    {
        set_matricula_aluno(m);
        set_cra(n);
        printf("\nAluno criado com sucesso!");
    }
    ~Aluno()
    {
        printf("\nAluno eliminado com sucesso!");
    }
    // Metodos getter's e setter's
    void set_matricula_aluno(int m)
    {
        matricula_aluno = m;
    }
    void set_cra(float n)
    {
        cra = n;
    }
    int get_matricula_aluno()
    {
        return matricula_aluno;
    }
    float get_cra()
    {
        return cra;
    }
};

class Turma
{
private:
    Professor *professor_responsavel;
    Aluno *conjunto_alunos;
    int codigo_turma;

public:
    // Metodos construtor e destrutor
    Turma(int cod, Professor *prof)
    {
        professor_responsavel = prof;
        set_codigo_turma(cod);
        printf("\nTurma criada!");
    }
    ~Turma()
    {
        printf("\nTurma eliminada!");
    }
    // Metodos getter's e setter's
    void set_codigo_turma(int cod)
    {
        codigo_turma = cod;
    }
    int get_codigo_turma()
    {
        return codigo_turma;
    }
    // Demais Metodos
    void adicionar_aluno(Aluno *a, int i)
    {
        conjunto_alunos[i] = *a;
    }
};

int main(void)
{

    printf("\n>> Main <<\n");

    Aluno *alunos_cadastrados, *a1, *a2, *a3, *a4, *a5, *a6;

    a1 = new Aluno(987653, 20, 1.70, 4321, 8.5);
    a2 = new Aluno(654321, 22, 1.75, 4445, 8.7);
    a3 = new Aluno(567890, 23, 1.70, 4321, 7.5);
    a4 = new Aluno(987654, 26, 1.75, 4445, 9.7);
    a5 = new Aluno(456789, 20, 1.70, 4321, 7.5);
    a6 = new Aluno(123494, 19, 1.75, 4445, 7.7);

    Professor *p1, *p2;

    p1 = new Professor(900012, 46, 1.80, 909090, 1999, 7778);
    p2 = new Professor(800012, 38, 1.78, 908765, 2007, 5553);

    Turma t1 = Turma(173, p2);
    Turma t2 = Turma(472, p1);

    t1.adicionar_aluno(a1, 0);
    t1.adicionar_aluno(a2, 1);
    t1.adicionar_aluno(a3, 2);
    t2.adicionar_aluno(a3, 0);
    t2.adicionar_aluno(a4, 1);
    t2.adicionar_aluno(a5, 2);

    printf("\n____INFORMACOES_____");
    printf("\nQuantidade de pessoas cadastradas no sistema: %d ", Pessoa::get_contador_pessoas());

    return 0;
}