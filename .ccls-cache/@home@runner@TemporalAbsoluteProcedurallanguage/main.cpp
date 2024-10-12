/*
Titulo: Manipulação de Struct
Autor: Guilherme Gonçalves
Data: 11/10/2024
*/

// Espaço reservado para declaração de bibliotecas
#include <iostream>
#include <limits>
#include <iomanip>  
#include <string>
#include <algorithm>

using namespace std;

// Espaço reservado para construção de struct
struct Pessoa {
  int codigo;
  string nome;
  float altura;
};

// Espaço reservado para prototipação de funções
int menu();
int lerCodigoValido(const string &mensagem);
void limparBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(Pessoa array[], int tamanho);
void esperarEnter();
void zerarArray(Pessoa array[], int tamanho);
void preencherArray(Pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);
void editarArray(Pessoa array[], int tamanho);
void verificarArray(Pessoa array[], int tamanho);
void ordernarArray(Pessoa array[], int tamanho);

// Função principal
int main() {
  const int TAMANHO = 2; // Define o tamanho da array de pessoas
  Pessoa array[TAMANHO];
  int opcao;

  do {
    opcao = menu();
    switch(opcao) {
      case 1: mostrarArray(array, TAMANHO); break;
      case 2: zerarArray(array, TAMANHO); break;
      case 3: preencherArray(array, TAMANHO); break;
      case 4: editarArray(array, TAMANHO); break;
      case 5: verificarArray(array, TAMANHO); break;
      case 6: ordernarArray(array, TAMANHO); break;
      case 0: cout << "Sair" << endl; break;
      default: exibirMsgErro("Opção inválida! Escolha uma opção válida"); break;
    }
  } while (opcao != 0);
  return 0;
}

int menu() {
  cout << "\nEscolha uma opção: \n";
  cout << "\n1 - Mostrar array de pessoas";
  cout << "\n2 - Zerar array de pessoas";
  cout << "\n3 - Preencher array de pessoas";
  cout << "\n4 - Editar array de pessoas";
  cout << "\n5 - Verificar array de pessoas";
  cout << "\n6 - Ordenar array de pessoas por código";
  cout << "\n0 - Sair\n";
  return lerCodigoValido("\nDigite uma opção válida: ");  
}

// Função para ler um número inteiro válido
int lerCodigoValido(const string &mensagem) {
  int numero;
  while (true) {
    cout << mensagem;
    cin >> numero;
    if (cin.fail()) {
      limparBuffer();
      exibirMsgErro("Entrada inválida. Digite um número inteiro válido.");
    } else {
      limparBuffer();
      return numero;
    }
  }
}

// Função para limpar o buffer do teclado
void limparBuffer() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  
}

// Função para exibir uma mensagem de erro
void exibirMsgErro(const string &mensagem) {
  cout << mensagem << endl;
}

// Função para mostrar array de pessoas
void mostrarArray(Pessoa array[], int tamanho) {
  cout << left << setw(10) << "Código" << "\t"
       << left << setw(20) << "Nome" << "\t"
       << left << setw(10) << "Altura" << endl;
  cout << string(50, '-') << endl;  
  for (int i = 0; i < tamanho; i++) {
    cout << left << setw(10) << array[i].codigo << "\t"
         << left << setw(20) << array[i].nome << "\t"
         << left << setw(10) << array[i].altura << endl;
  }
  esperarEnter();
}

// Função para esperar o usuário apertar Enter
void esperarEnter() {
  cout << "\nPressione Enter para continuar...";
  cin.get();
}

// Função para zerar array de pessoas
void zerarArray(Pessoa array[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    array[i].codigo = 0;
    array[i].nome = "";
    array[i].altura = 0.0;
  }
  cout << "Array de pessoas zerado.";
  esperarEnter();
}

// Função para preencher array de pessoas
void preencherArray(Pessoa array[], int tamanho) {  
  for (int i = 0; i < tamanho; i++) {
    array[i].codigo = lerCodigoValido("Digite o código da pessoa [" + to_string(i) + "]: ");
    array[i].nome = lerStringValida("Digite o nome da pessoa [" + to_string(i) + "]: ");
    array[i].altura = lerAlturaValida("Digite a altura da pessoa [" + to_string(i) + "]: ");
  }
  cout << "Array de pessoas preenchido com sucesso.";
  esperarEnter();
}

// Função para ler uma string válida
string lerStringValida(const string &mensagem) {
  string entrada;
  cout << mensagem;
  getline(cin, entrada);
  return entrada;
}

// Função para ler uma altura válida
float lerAlturaValida(const string &mensagem) {
  float altura;
  while (true) {
    cout << mensagem;
    cin >> altura;
    if (cin.fail() || altura <= 0) {
      limparBuffer();
      exibirMsgErro("Entrada inválida. Digite um número válido.");
    } else {
      limparBuffer();
      return altura;
    }
  }
}


void verificarArray(Pessoa array[], int tamanho) {
    int codigo = lerCodigoValido("Digite o código da pessoa que deseja verificar: ");
    bool encontrado = false;

    // Verifica se o código está no array
    for (int i = 0; i < tamanho; i++) {
        if (array[i].codigo == codigo) {
            cout << "Pessoa com código '" << codigo << "' encontrada: Nome: " << array[i].nome << ", Altura: " << array[i].altura << "m" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Pessoa com código '" << codigo << "' não encontrada." << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

void ordernarArray(Pessoa array[], int tamanho) {
    sort(array, array + tamanho, [](Pessoa a, Pessoa b) {
        return a.codigo < b.codigo;
    });
    cout << "Array de pessoas ordenado por código!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

void editarArray(Pessoa array[], int tamanho) {
    int posicao = lerCodigoValido("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): ");

    // Garante que a posição esteja dentro dos limites do array
    while (posicao < 0 || posicao >= tamanho) {
        exibirMsgErro("Posição inválida! Tente novamente.");
        posicao = lerCodigoValido("Digite uma posição válida: ");
    }

    array[posicao].codigo = lerCodigoValido("Digite o novo código para a posição [" + to_string(posicao) + "]: ");
    limparBuffer();  // Limpa o buffer antes de capturar a string
    array[posicao].nome = lerStringValida("Digite o novo nome para a posição [" + to_string(posicao) + "]: ");
    array[posicao].altura = lerAlturaValida("Digite a nova altura para a posição [" + to_string(posicao) + "] (em metros): ");
    cout << "Pessoa editada com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}