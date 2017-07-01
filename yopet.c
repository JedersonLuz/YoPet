/*
 *Autores: Hélio Rocha, Jederson Luz, Myllena Caetano
 *Emails: junior0helio15@gmail.com, jedersonalpha@gmail.com, myllenah2o@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 255//Constante para classificar o tamanho total dos vetores no programa

//struct para criação de produtos no sistema
struct produtos {
  int id, quantidade;
  char nome[MAX];
  float preco;
};

struct produtos produto[MAX];//istância da struct de produtos em formato de vetor
int contProd = 0;//váriavel para auxiliar no controle do vetor de produtos
int chamaId = 0;

//Função para auxiliar outras na incerção de valores de ponto flutuante em váriaveis com segurança utilizando atof
int inputFloat(char mensagem[MAX]) {
  float valor;
  char novaMensagem[MAX];

  valor = atof(mensagem);

  do {
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      scanf("%s", novaMensagem);
      valor = atof(novaMensagem);
    }
  } while(valor == 0);

  return valor;
}

//Função para auxiliar outras na incerção de valores inteiros em variáveis com segurança utilizando atoi
int inputInt(char mensagem[MAX]) {
  int valor;
  char novaMensagem[MAX];

  valor = atoi(mensagem);

  do {
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      scanf("%s", novaMensagem);
      valor = atoi(novaMensagem);
    }
  } while(valor == 0);

  return valor;
}

void idGerador(){
    if(chamaId==1)
        produto[contProd].id=contProd+1000;
    else{}if(chamaId==2)
        servico[contServ].id=contServ+5000;
}

//Função para cadastro de produtos vendidos pelo pet shop
void cadastrarProduto () {
  char mensagem[255];
  float test;
  char opcao;

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|   Cadastrar produto   |\n");
  printf("+-----------------------+\n");

  do {
    //idGenerator();

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
    chamaId=1;
    idGerador();
    system("cls||clear");
    printf("Confira se esta correto\n\n");
    printf("ID gerado: %d\n", produto[contProd].id);
    printf("Nome: %s\n", produto[contProd].nome);
    printf("Preco: %.2f\n", produto[contProd].preco);
    printf("Quantidade: %d\n", produto[contProd].quantidade);
    printf("\nDeseja confirmar o cadastro?\n[1]-Sim\n[2]-Não\n");
    setbuf(stdin, NULL);
    scanf("%c", &opcao);

    if (opcao == '1') {
      contProd++;
    }

  } while(opcao != '1');
}

void listarProdutos(){
	int i, op;
	do{
		system("cls||clear");
		printf("+-----------------------+\n");
  	printf("|   Lista de produtos   |\n");
  	printf("+-----------------------+\n");
		for ( i = 0 ; i < contProd; i++){
		    printf("ID: %d\n", produto[i].id);
    		printf("Nome do produto: %s\n", produto[i].nome);
    		printf("Preco: %.2f\n", produto[i].preco);
    		printf("Quantidade em estoque: %d\n", produto[i].quantidade);
    		printf("\n");
		}
		printf("Deseja alterar dados? \n [1]-Sim\n [2]-N�o");
		scanf("%d",&op);
		if (op == 1 ){
		    //atualizarProduto();
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
		}
	}while(op != 2);
}

void buscarProduto(){
    int i,idProd,existe=0,locProd,op;
    printf("Digite o numero do ID: ");
    setbuf(stdin, NULL);
    scanf("%d",&idProd);
    for(i=0;i<=contProd;i++){
        if(idProd==produto[i].id){
            existe=1;
            locProd=i;
        }
    }
    if(existe==1){
        printf("Nome do produto: %s\n", produto[locProd].nome);
        printf("Preco: %.2f\n", produto[locProd].preco);
        printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
        printf("Deseja alterar dados? \n [1]-Sim\n [2]-N�o\n");
        setbuf(stdin, NULL);
		scanf("%d",&op);
		if (op == 1 ){
			//atualizarProduto();
			printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        	setbuf(stdin, NULL);
        	getchar();
		}else{}if(op==2){
            menuAdministrativo();
		}
    }else{
        printf("ID inegistente!!!\n");
        getchar();
        menuAdministrativo();
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
    printf("|4 - Deletar Produto    |\n");
    printf("|5 - Atualizar Produto  |\n");
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
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //deletarProduto();
        break;
      case 5:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //atualizarProduto();
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
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //buscarProdutos();
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
