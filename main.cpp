/*
Titulo: Manipulação de Struct
Autor:Guilherme Gonçalves
Data:11/10/2024
*/

//Espaço reservado para daclaracao de bibliotecas
#include <iostream>
#include <limits>
#include <iomanip>  

using namespace std;

//Espaço reservado para construção de struct
  struct Pessoa{
  int codigo;
  string nome;
  float altura;
};

// Espaço reservado para prototipação de funções
int menu();
int LerCodigoValido(const string &mensagem);
void limparBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(Pessoa array[], int tamanho);


//Função principal
int main(){
  const int TAMANHO = 5; //Define o tamanho da array de pessoas
  Pessoa array[TAMANHO];
  int opcao;

  do{
  opcao = menu();
  switch(opcao){
    case 1:mostrarArray(array, TAMANHO);break;
    case 2:cout<<"Zerar array";break;
    case 3:cout<<"Preencher array";break;
    case 4:cout<<"Editar array";break;
    case 5:cout<<"Verificar array";break;
    case 6:cout<<"Ordernar array";break;
    case 0:cout<<"Sair"<<endl;break;
    default: exibirMsgErro("Opção invalida! Escolha uma opção valida");break;
  }
}while(opcao!=0);
return 0;
}
  

int menu(){
  cout << "\nEscolha uma opção: \n";
  cout << "\n1 - Mostrar array de pessoas";
  cout << "\n2 - Zerar array de pessoas";
  cout << "\n3 - Preencher array de pessoas";
  cout << "\n4 - Editar array de pessoas";
  cout << "\n5 - Verificar array de pessoas";
  cout << "\n6 - Ordernar array de pessoas por codigo";
  cout << "\n0 - Sair\n";
  return LerCodigoValido("\nDigite uma opção válida: ");  
}

//Função parar ler um numero inteiro valido
int LerCodigoValido(const string &mensagem){
  int numero;
  while(true){
    cout<<mensagem;
    cin>>numero;
    if (cin.fail()){
      limparBuffer();
      exibirMsgErro("Entrada invalida. Digite um numero inteiro valido.");
    }else{
      limparBuffer();
      return numero;
    }
  }
}

//Função para limpar o buffer do teclado
void limparBuffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  
}


//Função para exibir uma mensagem de erro
void exibirMsgErro(const string &mensagem){
  cout<<mensagem<<endl;
}

//Funcao para mostrar array de pessoas
void mostrarArray(Pessoa array[], int tamanho){
  cout<<left<<setw(10)<<"Codigo"<<"\t"
      <<left<<setw(20)<<"Nome"<<"\t"
      <<left<<setw(10)<<"Altura"<<endl;
  cout<<string(50,'-')<<endl;  
  for(int i=0; i<tamanho; i++){
  cout<<left<<setw(10)<<array[i].codigo<<"\t"<<
        left<<setw(20)<<array[i].nome<<"\t"<<
        left<<setw(10)<<array[i].altura<<endl;
  }
}