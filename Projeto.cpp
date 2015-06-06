#include<iostream>
#include<stdlib.h>
#include<cstdio>

using namespace std;

FILE *arquivo = NULL; // Manipulador


struct  dados {
        
       int status, cod;
       char nomeLivro[100], nomeEditora[100], nomeAutor[100];
       int anoLancamento, numEdic;       
       float preco; 
        
};

dados livro;

void Cadastrar()
{
	
    int i;

     i=i+1;

     system("cls");
     cout << "**Cadastrar Livro**"  << endl;
     cin.ignore();
     cout << "Código do produto " << i << endl;
     cout << "Entre com o nome do livro " << endl;
     cin.getline(livro.nomeLivro,100);
     cout << "Entre com o ano de Lancamento " << endl;
     cin >> livro.anoLancamento;
     cin.ignore();
     cout << "Entre com o nome da Editora:" << endl;
       cin.ignore();
     cin.getline(livro.nomeEditora,100);
     cout << "Entre com o nome do autor : " << endl;
     cin.getline(livro.nomeAutor,100);
     cout << "Entre com o preco:" << endl;
     cin >> livro.preco;
     cout << "Entre com o código do produto" << endl;
     	
    livro.status =1;
    
    fseek(arquivo, sizeof(dados), SEEK_END);
    // SEEK_END para cadastrar no fim do arquivo
    // fwrite (&oque, tamanho_em_bytes, quant, aonde):
    fwrite (&livro, sizeof(dados) , 1, arquivo);
    //gtavo todas as variaves do aluno no arquivo
    
    cout << endl;
    cout << "Cadastrado com sucesso" << endl;
    cout << endl;
    
          
}
void Editar()
{
}

void Pesquisar()
{}

void Listar()
{
     system("cls");
     cout << "Listar livros" << endl;
     fseek(arquivo, 0, SEEK_SET);
     //SEEK_SET inicio do arquivo
     fseek(arquivo, sizeof(dados), SEEK_CUR);
     fread(&livro, sizeof(dados), 1, arquivo);
     system("pause"); 

     while(!feof(arquivo)) //enquanto nao for o fim do arquivo
     {
       cout << "Nome do Livro : " << livro.nomeLivro << endl;
       cout << "Ano de lançamento : " << livro.anoLancamento << endl;
       cout << "Nome do Autor : " << livro.nomeAutor << endl;
       cout << "Nome da Editora : " << livro.nomeEditora << endl;
       cout << "Preço: " << livro.preco << endl;
       
                          
       fseek(arquivo, sizeof(dados), SEEK_CUR);
       fwrite (&livro, sizeof(dados) , 1, arquivo); 
           
     }
     
     }

void Excluir()
{}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("color F5");

    int op=-1;
    
     arquivo= fopen("dadosprojeto.txt","r+");
    
    if(arquivo==NULL)
    {
     arquivo= fopen("dadosprojeto.txt","w+");                  
    } 
    
    while(op!=0)
    {           
                cout << " ____________" << endl;
                cout << "|****MENU****|"<< endl;
                cout << "|1-Cadastrar |" << endl;
                cout << "|2-Editar    |" << endl;
                cout << "|3-Pesquisar |" << endl;
                cout << "|4-Listar    |" << endl;
                cout << "|5-Excluir   |" << endl;
                cout << "|0-Para sair |" << endl;
                cout << "|____________| "<< endl;
                do{
                     cout << "Entre com a opcao desejada : "  << endl;
                     cin >> op;
                   }while (op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=0);
                   
                switch(op)
                {
                  case 1:
                       Cadastrar();
                       break;
                  case 2:
                       Editar();
                       break;
                  case 3:
                       Pesquisar();
                       break;
                  case 4:
                       Listar();
                       break;
                  case 5:
                       Excluir();
                       break;
                  }
                
                
    }
    
    
    fclose(arquivo);
    
    system("pause");
    return 0;

}


