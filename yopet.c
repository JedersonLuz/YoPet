/*
 *Autores: Hélio Rocha, Jederson Luz, Myllena Caetano
 *Emails: junior0helio15@gmail.com, jedersonalpha@gmail.com, myllenah2o@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255//Constante para classificar o tamanho total dos vetores no programa

//struct para criação de produtos no sistema
struct produtos {
  int id, quantidade;
  char nome[MAX];
  float preco;
};

struct produtos produto[MAX];//istância da struct de produtos em formato de vetor
int contProd = 0;//váriavel para auxiliar no controle do vetor de produtos

//Função para auxiliar outras na incerção de valores de ponto flutuante em váriaveis com segurança utilizando atof
int inputFloat(char mensagem[MAX]) {
  float valor;

  valor = atof(mensagem);

  do {
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      valor = atof(mensagem);
    }
  } while(valor == 0);

  return valor;
}

//Função para auxiliar outras na incerção de valores inteiros em variáveis com segurança utilizando atoi
int inputInt(char mensagem[MAX]) {
  int valor;

  valor = atoi(mensagem);

  do {
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      valor = atoi(mensagem);
    }
  } while(valor == 0);

  return valor;
}

void idGerador(){
  produto[contProd].id=contProd+1000;
}

//O buscador serve para ajudar outras funções a acharem o produto que precisam para realizar seus objetivos
int buscador () {
  int idFinded;//idFinded guardará o índice onde se encontra o produto procurado
  int idSearch;//idSearch guardará o id do produto que se quer encontrar
  char mensagem[MAX];//várialvel para ser usada na blindagem de dados
  int encontrado = 0;//váriavel que diz se o produto foi encontrado ou não

  printf("Digite o ID do produto: \n");
  setbuf(stdin, NULL);//limpa o buff do teclado
  scanf("%s", mensagem);
  idSearch = inputInt(mensagem);

  //Este for irá procurar o produto comparando os ids dos mesmos
  for(int i = 0; i <= contProd; i++){
      //Quando for encontrado o índice do produto ele será guardado em idFinded
      if(idSearch == produto[i].id){
          idFinded = i;
          encontrado = 1;
          break;
      }
  }

  if (encontrado == 0) {
    printf("Produto não encontrado. Digite enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
    return -1;//este retorno significa que o produto não foi encontrado
  } else {
    return idFinded;
  }
}

void deletarProduto () {
  int locProd, opcao;
  char mensagem[MAX];

  locProd = buscador();

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|    Deletar produto    |\n");
  printf("+-----------------------+\n");
  //Se locProd for diferente de -1 então o produto foi achado
  if(locProd != -1) {
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("Deseja realmente deletar os dados?\n[1]-Sim\n[2]-Nao\n");
    setbuf(stdin, NULL);
	  scanf("%s", mensagem);
    opcao = inputInt(mensagem);

	  if (opcao == 1) {
		    for (int i = locProd; i < contProd; i++) {
          if (produto[i].nome == "\0");
          produto[i].id = produto[i+1].id;
          strcpy(produto[i].nome, produto[i+1].nome);
          produto[i].preco = produto[i+1].preco;
          produto[i].quantidade = produto[i+1].quantidade;
		    }
        contProd--;
	  }
  }
}

void atualizarProduto () {
  int locProd, opcao;
  char mensagem[MAX];

  locProd = buscador();

  do {
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|   Atualizar produto   |\n");
    printf("+-----------------------+\n");
    //Se locProd for diferente de -1 então o produto foi achado
    if(locProd != -1){
      printf("Nome do produto: %s\n", produto[locProd].nome);
      printf("Preco: %.2f\n", produto[locProd].preco);
      printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
      printf("Deseja realmente alterar dados?\n[1]-Sim\n[2]-Nao\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      opcao = inputInt(mensagem);

      if (opcao == 1){
        printf("Digite o nome do produto: \n");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", produto[locProd].nome);
        setbuf(stdin, NULL);

        printf("Digite o preco do produto: \n");
        setbuf(stdin, NULL);
        scanf("%s", mensagem);
        produto[locProd].preco = inputFloat(mensagem);

        printf("Digite a quantidade do produto: \n");
        setbuf(stdin, NULL);
        scanf("%s", mensagem);
        produto[locProd].quantidade = inputInt(mensagem);

        system("cls||clear");
        printf("Confira se esta correto\n\n");
        printf("ID gerado: %d\n", produto[locProd].id);
        printf("Nome: %s\n", produto[locProd].nome);
        printf("Preco: %.2f\n", produto[locProd].preco);
        printf("Quantidade: %d\n", produto[locProd].quantidade);
        printf("\nDeseja confirmar o cadastro?\n[1]-Sim\n[2]-Não\n");
        setbuf(stdin, NULL);
        scanf("%s", mensagem);
        opcao = inputInt(mensagem);
      } else if (opcao == 2) {
        break;
      }
    }
  } while(opcao != 1);
}

//Função para cadastro de produtos vendidos pelo pet shop
void cadastrarProduto () {
  char mensagem[MAX];
  float test;
  int opcao;

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|   Cadastrar produto   |\n");
  printf("+-----------------------+\n");
  printf("Digite o nome do produto: \n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", produto[contProd].nome);
  setbuf(stdin, NULL);

  printf("Digite o preco do produto: \n");
  setbuf(stdin, NULL);
  scanf("%s", mensagem);
  produto[contProd].preco = inputFloat(mensagem);

  printf("Digite a quantidade do produto: \n");
  setbuf(stdin, NULL);
  scanf("%s", mensagem);
  produto[contProd].quantidade = inputInt(mensagem);

  idGerador();

  system("cls||clear");
  printf("Confira se esta correto\n\n");
  printf("ID gerado: %d\n", produto[contProd].id);
  printf("Nome: %s\n", produto[contProd].nome);
  printf("Preco: %.2f\n", produto[contProd].preco);
  printf("Quantidade: %d\n", produto[contProd].quantidade);
  printf("\nDeseja confirmar o cadastro?\n[1]-Sim\n[2]-Não\n");
  setbuf(stdin, NULL);
  scanf("%s", mensagem);
  opcao = inputInt(mensagem);

  if (opcao == 1) {
    contProd++;
  } else {
    cadastrarProduto();
  }
}

void listarProdutos(){
	int opcao;
  char mensagem[MAX];

	do{
		system("cls||clear");
		printf("+-----------------------+\n");
  	printf("|   Lista de produtos   |\n");
  	printf("+-----------------------+\n");

    for(int i = 0 ; i < contProd; i++){
		    printf("ID: %d\n", produto[i].id);
    		printf("Nome do produto: %s\n", produto[i].nome);
    		printf("Preco: %.2f\n", produto[i].preco);
    		printf("Quantidade em estoque: %d\n", produto[i].quantidade);
    		printf("\n");
		}
    printf("Digite enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
	}while(opcao != 2);
}

void buscarProduto(){
  int locProd, opcao;
  char mensagem[MAX];

  locProd = buscador();

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|     Buscar produto    |\n");
  printf("+-----------------------+\n");
  //Se locProd for diferente de -1 então o produto foi achado
  if(locProd != -1){
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("\nDigite enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
  }
}

void comprarProduto(){
  /* code */
}

void menuAdministrativo(){
  int opcao;
  char mensagem[MAX];

  do {
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|          YoPet        |\n");
    printf("|-----------------------|\n");
    printf("|  Menu Administrativo  |\n");
    printf("|-----------------------|\n");
    printf("|Digtie a opcao desejada|\n");
    printf("|-----------------------|\n");
    printf("|1 - Cadastrar Produto  |\n");
    printf("|2 - Listar produtos    |\n");
    printf("|3 - Buscar Produto     |\n");
    printf("|4 - Atualizar Produto  |\n");
    printf("|5 - Deletar Produto    |\n");
    printf("|6 - Caixa              |\n");
    printf("|7 - Voltar             |\n");
    printf("+-----------------------+\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    switch(opcao){
      case 1:
        cadastrarProduto();
        break;
      case 2:
        listarProdutos();
        break;
      case 3:
        buscarProduto();
        break;
      case 4:
        atualizarProduto();
        break;
      case 5:
        deletarProduto();
        break;
      case 6:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //caixa();
        break;
      case 7:
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  } while(opcao != 7);
}

void menuLoja(){
  int opcao;
  char mensagem[MAX];

  do {
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|         YoPet         |\n");
    printf("|-----------------------|\n");
    printf("|       Menu Loja       |\n");
    printf("|-----------------------|\n");
    printf("|Digtie a opcao desejada|\n");
    printf("|-----------------------|\n");
    printf("|1 - Comprar produto    |\n");
    printf("|2 - Listar de Produtos |\n");
    printf("|3 - Buscar Produto     |\n");
    printf("|4 - Voltar             |\n");
    printf("+-----------------------+\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    switch (opcao) {
      case 1:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //comprarProduto();
        break;
      case 2:
        listarProdutos();
        break;
      case 3:
        buscarProduto();
        break;
      case 4:
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  } while(opcao != 4);
}

int main(int argc, char const *argv[]) {
  int opcao;
  char mensagem[MAX];

  do {
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|          YoPet        |\n");
    printf("|-----------------------|\n");
    printf("|     Menu Principal    |\n");
    printf("|-----------------------|\n");
    printf("|Digtie a opcao desejada|\n");
    printf("|-----------------------|\n");
    printf("|1 - Menu Administrativo|\n");
    printf("|2 - Menu da Loja       |\n");
    printf("|3 - Sair do programa   |\n");
    printf("+-----------------------+\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    switch (opcao) {
      case 1:
        menuAdministrativo();
        break;
      case 2:
        menuLoja();
        break;
      case 3:
        printf("Obrigado por utilizar nosso programa.\n");
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  }while(opcao != 3);

  return 0;
}
