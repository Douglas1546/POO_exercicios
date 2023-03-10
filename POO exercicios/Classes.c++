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
