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

struct produtos produto[MAX];//istância da struct de produtos em formato de vetor para armazenar vários produtos
int contProd = 0;//váriavel para auxiliar no controle do vetor de produtos, ela quem indica quantas produtos exitem
float caixa = 0;//armazena o valor guardado no caixa

//Função para auxiliar outras na incerção de valores de ponto flutuante em váriaveis com segurança utilizando atof
int inputFloat(char mensagem[MAX]) {
  float valor;//Váriavel que irá receber o valor float após a verificação de segurança

  valor = atof(mensagem);//Converção de string para float

  //Força o usuário a digitar um valor válido, não permitindo a saída a não ser que o faça
  do {
    //Se o valor for inválido pede que o usuário digite novamente
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      valor = atof(mensagem);
    }
  } while(valor == 0);

  return valor;//retorna um valor válido para a outra função
}

//Função para auxiliar outras na incerção de valores inteiros em variáveis com segurança utilizando atoi
int inputInt(char mensagem[MAX]) {
  int valor;//Váriavel que irá receber o valor int após a verificação de segurança

  valor = atoi(mensagem);//Converção de string para int

  //Força o usuário a digitar um valor válido, não permitindo a saída a não ser que o faça
  do {
    //Se o valor for inválido pede que o usuário digite novamente
    if (valor == 0) {
      printf("Entrada invalida, por favor digite novamente.\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      valor = atoi(mensagem);
    }
  } while(valor == 0);

  return valor;//retorna um valor válido para a outra função
}

//Cria o id dos produtos
void idGerador(){
  //Se não houver produtos cadastrados, então o id será 1, senão o id será igual o id do produto anterior mais 1
  if (contProd == 0) {
    produto[contProd].id = 1;
  } else {
    produto[contProd].id = (produto[contProd-1].id) + 1;
  }
}

//O buscador serve para ajudar outras funções a acharem o produto que precisam para realizar seus objetivos
int buscador () {
  int idFinded, i;//idFinded guardará o índice onde se encontra o produto procurado
  int idSearch;//idSearch guardará o id do produto que se quer encontrar
  char mensagem[MAX];//várialvel para ser usada na blindagem de dados
  int encontrado = 0;//váriavel que diz se o produto foi encontrado ou não

  printf("Digite o ID do produto: \n");
  setbuf(stdin, NULL);//limpa o buff do teclado
  scanf("%s", mensagem);//recebe o valor digitado como string
  idSearch = inputInt(mensagem);//faz com que a váriavel receba um valor válido após verificar a string acima

  //Este for irá procurar o produto comparando os ids dos mesmos
  for(i = 0; i <= contProd; i++){
      //Quando for encontrado o índice do produto ele será guardado em idFinded
      if(idSearch == produto[i].id){
          idFinded = i;//Recebe a posição em que se encontra o produto procurado
          encontrado = 1;
          break;
      }
  }

  //Caso não seja encontrado o produto ixibe a mensagem a seguir
  if (encontrado == 0) {
    printf("Produto não encontrado. Digite enter para continuar...\n");
    setbuf(stdin, NULL);//Limpa o buff do teclado
    getchar();//Pausa a execução e aguarda que o usuário tecle algo para continuar
    return -1;//este retorno significa que o produto não foi encontrado
  } else {
    return idFinded;//este retorno informa a posição do produto que se deseja encontrar
  }
}

void deletarProduto () {
  int locProd, opcao, i;//locProd receberá a posição do produto que se quer deletar
  char mensagem[MAX];


  system("cls||clear");//Limpa tela
  printf("+-----------------------+\n");
  printf("|    Deletar produto    |\n");
  printf("+-----------------------+\n");

  locProd = buscador();//o buscador irá informar a locProd a posição do produto

  //Se locProd for diferente de -1 então o produto foi achado e será exibido
  if(locProd != -1) {
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("Deseja realmente deletar os dados?\n[1]-Sim\n[2]-Nao\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    //Se opcao for 1, então será feita a realocação dos dados a seguir, removendo da lista o que foi deletado
	  if (opcao == 1) {
        for (i = locProd; i < contProd; i++) {
          if (produto[i].nome == "\0");
          produto[i].id = produto[i+1].id;
          strcpy(produto[i].nome, produto[i+1].nome);
          produto[i].preco = produto[i+1].preco;
          produto[i].quantidade = produto[i+1].quantidade;
        }
        contProd--;//Infoma que há um produto a menos cadastrado
	  }
  }
}

void atualizarProduto () {
  int locProd, opcao;//locProd receberá a posição do produto que se quer modificar
  char mensagem[MAX];


  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|   Atualizar produto   |\n");
  printf("+-----------------------+\n");

  locProd = buscador();//o buscador irá informar a locProd a posição do produto

  //Se locProd for diferente de -1 então o produto foi achado
  if(locProd != -1){
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("Deseja realmente alterar dados?\n[1]-Sim\n[2]-Nao\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    //Repetirá a ação de atualizar até que o usuário confirme ter cadastrado como quer
    do {
      //Se opcao for 1, então os dados na posição locProd serão alterados
      if (opcao == 1){
        printf("Digite o novo nome do produto: \n");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", produto[locProd].nome);
        setbuf(stdin, NULL);

        printf("Digite o novo preco do produto: \n");
        setbuf(stdin, NULL);
        scanf("%s", mensagem);
        produto[locProd].preco = inputFloat(mensagem);

        printf("Digite a nova quantidade do produto: \n");
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
      }
    } while(opcao != 1);
  }
}

//Função para cadastro de produtos vendidos pelo pet shop
void cadastrarProduto () {
  char mensagem[MAX];
  int opcao;

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|   Cadastrar produto   |\n");
  printf("+-----------------------+\n");
  printf("Digite o nome do produto: \n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", produto[contProd].nome);//produto na posição contProd recebe um nome digitado
  setbuf(stdin, NULL);

  printf("Digite o preco do produto: \n");
  setbuf(stdin, NULL);
  scanf("%s", mensagem);//mensagem recebe um valor digitado, para depois ser verificado
  produto[contProd].preco = inputFloat(mensagem);//produto na posição contProd recebe um preco válido, ou seja, já verificado

  printf("Digite a quantidade do produto: \n");
  setbuf(stdin, NULL);
  scanf("%s", mensagem);//mensagem recebe um valor digitado, para depois ser verificado
  produto[contProd].quantidade = inputInt(mensagem);//produto na posição contProd recebe uma quantidade válida, ou seja, já verificada

  idGerador();//Cria um id para o produto na posição contProd

  //Pede para o usuário verificar se está tudo correto
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

  //Se for confirmado, então contProd é incrementado, caso contrário a função de cadastrar é chamada novamente
  if (opcao == 1) {
    contProd++;
  } else {
    cadastrarProduto();
  }
}

void listarProdutos(){
    int opcao, i;
    char mensagem[MAX];

	system("cls||clear");
	printf("+-----------------------+\n");
    printf("|   Lista de produtos   |\n");
    printf("+-----------------------+\n");

  for(i = 0 ; i < contProd; i++){
	    printf("ID: %d\n", produto[i].id);
  		printf("Nome do produto: %s\n", produto[i].nome);
  		printf("Preco: %.2f\n", produto[i].preco);
  		printf("Quantidade em estoque: %d\n", produto[i].quantidade);
  		printf("\n");
	}
  printf("Digite enter para continuar...\n");
  setbuf(stdin, NULL);
  getchar();
}

void buscarProduto(){
  int locProd;//locProd receberá a posição do produto que se quer buscar
  char mensagem[MAX];


  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|     Buscar produto    |\n");
  printf("+-----------------------+\n");
  locProd = buscador();//o buscador irá informar a locProd a posição do produto
  //Se locProd for diferente de -1 então o produto foi achado, portanto é exibido a seguir
  if(locProd != -1){
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("\nDigite enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
  }
}

//Está função exibe o valor já depositado no caixa da loja
void verCaixa () {
  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|         Caixa         |\n");
  printf("+-----------------------+\n");
  printf("Caixa: R$%.2f\n", caixa);
  printf("\nDigite enter para continuar...\n");
  setbuf(stdin, NULL);
  getchar();
}

//Está função efetua a venda dos produtos
void venderProduto () {
  int locProd, opcao, qtdVendida;//locProd receberá a posição do produto que se quer buscar
  char mensagem[MAX];

  system("cls||clear");
  printf("+-----------------------+\n");
  printf("|         Vendas        |\n");
  printf("+-----------------------+\n");

  locProd = buscador();//o buscador irá informar a locProd a posição do produto

  //Se locProd for diferente de -1 então o produto foi achado, portanto é exibido a seguir
  if(locProd != -1){
    printf("Nome do produto: %s\n", produto[locProd].nome);
    printf("Preco: %.2f\n", produto[locProd].preco);
    printf("Quantidade em estoque: %d\n", produto[locProd].quantidade);
    printf("\nDeseja vender este produto?\n[1]-Sim\n[2]-Não\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    if (opcao == 1) {
      printf("Quantos deseja vender?\n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      qtdVendida = inputInt(mensagem);
      produto[locProd].quantidade -= qtdVendida;
      caixa += (produto[locProd].preco * qtdVendida);
      printf("Vendido com sucesso! Lucro de %.2f\n", (produto[locProd].preco * qtdVendida));
      printf("\nDigite enter para continuar...\n");
      setbuf(stdin, NULL);
      getchar();
    }
  }
}

//Esta função exibe o menu administrativo
void menuAdministrativo () {
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
    printf("|6 - Ver Caixa          |\n");
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
        verCaixa();
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

//Esta função exibe o menu da loja
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
    printf("|1 - Vender Produto     |\n");
    printf("|2 - Listar de Produtos |\n");
    printf("|3 - Buscar Produto     |\n");
    printf("|4 - Ver Caixa          |\n");
    printf("|5 - Voltar             |\n");
    printf("+-----------------------+\n");
    setbuf(stdin, NULL);
    scanf("%s", mensagem);
    opcao = inputInt(mensagem);

    switch (opcao) {
      case 1:
        venderProduto();
        break;
      case 2:
        listarProdutos();
        break;
      case 3:
        buscarProduto();
        break;
      case 4:
        verCaixa();
        break;
      case 5:
        break;
      default:
        printf("Opcao invalida. Digite enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
  } while(opcao != 5);
}

//Esta função exibe o menu principal
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
