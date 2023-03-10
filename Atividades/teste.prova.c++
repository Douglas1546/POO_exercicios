#include <iostream>
#define TAM_TURMA 3

using namespace std;

class pessoa{
    int cpf;
    int idade;
    float altura;
    static int contador;
public:
    pessoa(int c, int i, float a):cpf(c), idade(i), altura(a){
        contador++;
        cout << "Nova pessoa: " << cpf << endl;
    }
    ~pessoa(){
        contador--;
    }
    int get_cpf(){
        return cpf;
    }
    void set_cpf(int c){
        cpf = c;
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
    static int get_contador(){
        return contador;
    }
};

int pessoa::contador = 0;

class professor : public pessoa{
    int matricula;
    int titulacao;
    int ano_admissao;
public:
    professor(int c, int i, float a, int m, int t, int aa): pessoa(c,i,a), matricula(m),titulacao(t), ano_admissao(aa){
        cout << "Novo professor: " << matricula << endl;
    }
};

class aluno : public pessoa{
    int matricula;
    float cra;
public:
    aluno(int c, int i, int a, int m, float cr):pessoa(c,i,a),matricula(m), cra(cr){
        cout << "Novo aluno: " << matricula << endl;
    }
    float get_cra(){
        return cra;
    }
    void set_cra(float cr){
        cra = cr;
    }
};

class turma{
    int codigo;
    professor *prof_responsavel;
    aluno *matriculados[TAM_TURMA];
public:
    turma(int c, professor *prof):codigo(c),prof_responsavel(prof){
        cout << "Nova turma: " << codigo << endl;
    }
    int get_codigo(){
        return codigo;
    }
    void set_codigo(int c){
        codigo = c;
    }
    int add_aluno(int pos, aluno *a){
        if (pos >= TAM_TURMA)
        {
            printf("Posicao invalida! a turma so pode conter 3 alunos!");
            return -1;
        }
        else{
            matriculados[pos] = a;
        }
        return pos;
        
    }
    int get_alunos(){
        for (int i = 0; i < TAM_TURMA; i++)
        {
            cout << "cpf do aluno [" << i << "]: " << matriculados[i]->get_cpf() << endl;
            cout << "idade do aluno [" << i << "]: " << matriculados[i]->get_idade() << endl;
            cout << "altura do aluno [" << i << "]: " << matriculados[i]->get_altura() << endl;
            cout << "cra do aluno [" << i << "]: " << matriculados[i]->get_cra() << endl;
            printf("\n");
        }
        
    }
};

int main(){
    aluno a1(111111, 18, 1.60, 15461, 7.5);
    aluno a2(222222, 19, 1.70, 15462, 8.5);
    aluno a3(333333, 20, 1.80, 15463, 9.5);

    professor p1(44444, 30, 1.90, 15466, 121212, 1990);
    professor p2(55555, 31, 1.92, 15467, 121213, 1991);

    turma t1(99999, &p1);
    turma t2(98989, &p2);
    

    t1.add_aluno(0, &a1);
    t1.add_aluno(1, &a2);
    t1.add_aluno(2, &a3);
    
    t2.add_aluno(0, &a1);
    t2.add_aluno(1, &a2);
    t2.add_aluno(2, &a3);

    cout << "Pessoas cadastradas: " << pessoa::get_contador() << endl << endl;
    
    cout << "Lista de Alunos: " << t2.get_alunos() << endl;
    
}