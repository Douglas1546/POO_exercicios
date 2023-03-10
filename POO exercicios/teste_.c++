#include <iostream>
using namespace std;

class estoque{
    estoque *nome;
    int qtd;
public:
    estoque(estoque *n = 0, int q = 0){
        nome = n;
        qtd = q;
    }
    ~estoque(){

    }
    estoque *get_nome(){
        return nome;
    }
    void set_nome(estoque *n){
        nome = n;
    }
    int get_qtd(){
        return qtd;
    }
    void set_qtd(int q){
        qtd = q;
    }

    void print_info(){
        cout << get_nome() << endl;
    }
};



int main(){
    estoque *produtos;
    int op;
    int qtd_produtos;
    char nome[20][20];
    int qtd;
    do
    {
        printf("\n 1 - Cadastrar Produtos \n 2 - Exibir Produtos Cadastrados \n 0 - Sair");
        printf("\n\n Digite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cout << "Quantos diferentes tipos de produtos deseja cadastrar: ";
            cin >> qtd_produtos;
            produtos = new estoque[qtd_produtos];
            for (int i = 0; i < qtd_produtos; i++)
            {
                cout << "Digite o nome do produto [" << i + 1 << "]: ";
                cin >> nome[i];

                cout << "Digite a quantidade total do produto[" << nome[i] << "]: ";
                cin >> qtd;

                produtos[i].set_qtd(qtd);
                produtos[i].set_nome((estoque*)nome[i]);
            }
            break;
        case 2:
            cout << "\n\n================Produtos cadastrados================\n\n";
            produtos->print_info();
            for (int i = 0; i < qtd_produtos; i++)
            {
                
                cout << "Quantidade do produto [" << nome[i] << "] disponivel: " << produtos[i].get_qtd() << endl;
            }
                
            
            break;
        default:
            break;
        }
    } while (op!=0);
    
}