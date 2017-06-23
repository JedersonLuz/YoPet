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

//struct para criação de serviços no sistema
struct sevicos {
  int id;
  char nomeServico[MAX];
  float preco;
};

struct produtos produto[MAX];//istância da struct de produtos em formato de vetor
struct sevicos servico[MAX];//istância da struct de serviços em formato de vetor
int contProd = 0;//váriavel para auxiliar no controle do vetor de produtos
int contServ = 0;//váriavel para auxiliar no controle do vetor de serviços

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

    int idn,i,testa,testlocal;
    idn=(1000+rand()%1000);//gerar id entre 1000 e 1999
    testlocal=0;
    testa=0;
    do{
        if(idn!=produto[testlocal].id){
            produto[contProd].id=idn;
            testa=1;
        }else{
            testlocal++;
            testa=0;
        }
    }while(testa==0);

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

//Função para cadastro de serviços disponibilizados pelo pet shop
void cadastrarServico () {
  char mensagem[255];
  float test;
  char opcao;

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|   Cadastrar servico   |\n");
  printf("+-----------------------+\n");

  do {
    //idGenerator();

    printf("Digite o nome do servico: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", servico[contServ].nomeServico);
    setbuf(stdin, NULL);

    printf("Digite o preco do servico: \n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    servico[contServ].preco = inputFloat(mensagem);

    system("cls||clear");
    printf("Confira se esta correto\n\n");
    printf("ID gerado: %d\n", servico[contServ].id);
    printf("Nome do servico: %s\n", servico[contServ].nomeServico);
    printf("Preco: %.2f\n", servico[contServ].preco);
    printf("\nDeseja confirmar o cadastro?\n[1]-Sim\n[2]-Não\n");
    setbuf(stdin, NULL);
    scanf("%c", &opcao);

    if (opcao == '1') {
      contServ++;
    }

  } while(opcao != '1');
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
    printf("|2 - Cadastrar Servico  |\n");
    printf("|3 - Listar produtos    |\n");
    printf("|4 - Listar Servicos    |\n");
    printf("|5 - Buscar Produto     |\n");
    printf("|6 - Buscar Servico     |\n");
    printf("|7 - Deletar Produto    |\n");
    printf("|8 - Deletar Servico    |\n");
    printf("|9 - Atualizar Produto  |\n");
    printf("|10 - Atualizar Servico |\n");
    printf("|11 - Caixa             |\n");
    printf("|12 - Voltar            |\n");
    printf("+-----------------------+\n");
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    switch(opcao){
      case 1:
        cadastrarProduto();
        break;
      case 2:
        cadastrarServico();
        break;
      case 3:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //listarProdutos();
        break;
      case 4:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //listarServicos();
        break;
      case 5:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //buscarProduto();
        break;
      case 6:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //buscarServico();
        break;
      case 7:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //deletarProduto();
        break;
      case 8:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //deletarServico();
        break;
      case 9:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //atualizarProduto();
        break;
      case 10:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //atualizarServico();
        break;
      case 11:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //caixa();
        break;
      case 12:
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  } while(opcao != 12);
}

void menuLoja(){
  char opcao;

  do {
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|         YoPet         |\n");
    printf("|-----------------------|\n");
    printf("|       Menu Loja       |\n");
    printf("|-----------------------|\n");
    printf("|Digtie a opcao desejada|\n");
    printf("|-----------------------|\n");
    printf("|1 - Contratar Serviço  |\n");
    printf("|2 - Comprar produto    |\n");
    printf("|3 - Lista de Produto   |\n");
    printf("|4 - Lista de Serviço   |\n");
    printf("|5 - Buscar Produto     |\n");
    printf("|6 - Buscar Serviço     |\n");
    printf("|7 - Voltar             |\n");
    printf("+-----------------------+\n");
    scanf("%c", &opcao);

    switch (opcao) {
      case 1:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //contratarServico();
      break;
      case 2:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //comprarProduto();
      break;
      case 3:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //listarProdutos();
      break;
      case 4:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //listarServicos();
      break;
      case 5:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //buscarProdutos();
        break;
      case 6:
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //buscarServicos();
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

int main(int argc, char const *argv[]) {
  char opcao;

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
    scanf("%c", &opcao);

    switch (opcao) {
      case '1':
        menuAdministrativo();
        break;
      case '2':
        printf("Opcao em desenvolvimento. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        //menuLoja();
        break;
      case '3':
        printf("Obrigado por utilizar nosso programa.\n");
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  }while(opcao != '3');

  return 0;
}
