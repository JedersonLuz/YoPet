/*
 *Autores: Hélio Rocha, Jederson Luz, Myllena Caetano
 *Emails: junior0helio15@gmail.com, jedersonalpha@gmail.com, myllenah2o@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>

struct produtos {
  int id, quantidade;
  char nome[255];
  float preco;
};

struct sevicos {
  int id;
  char nomeServico[255], nomeAnimal[255], nomeDono[255];
  float preco;
};

struct produtos produto[255];
struct sevicos servico[255];
int contProd = 0;

void cadastrarProduto () {
  char mensagem[255];
  int test;
  char opcao;

  do {
    //idGenerator();
    printf("Digite o nome do produto: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", produto[contProd].nome);
    setbuf(stdin, NULL);
    do {
      printf("Digite o preco do produto: \n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      test = atof(mensagem);
      if (test == 0) {
        printf("Entrada invalida.\n");
      } else {
        produto[contProd].preco = test;
      }
    } while(test == 0);
    do {
      printf("Digite a quantidade do produto: \n");
      setbuf(stdin, NULL);
      scanf("%s", mensagem);
      test = atoi(mensagem);
      if (test == 0) {
        printf("Entrada invalida.\n");
      } else {
        produto[contProd].quantidade = test;
      }
    } while(test == 0);

    printf("\nNome: %s\n", produto[contProd].nome);
    printf("Preco: %f\n", produto[contProd].preco);
    printf("Quantidade: %d\n", produto[contProd].quantidade);
    printf("Deseja confirmar o cadastro? 1 - Sim/2 - Nao\n");
    setbuf(stdin, NULL);
    scanf("%c", &opcao);
    if (opcao == '1') {
      printf("Cadastro conclido.\n");
      contProd++;
    }
  } while(opcao != '1');
}

void menuAdministrativo(int opcao_ADM){
		char buscarProduto[255], buscarServico[255];
		printf("+-----------------------+\n");
   		printf("|          YoPet        |\n");
    	printf("|-----------------------|\n");
    	printf("|  Menu Administrativo  |\n");
    	printf("|-----------------------|\n");
    	printf("|Digtie a opcao desejada|\n");
    	printf("|-----------------------|\n");
    	printf("|1 - Cadastrar Produto  |\n");
    	printf("|2 - Cadastrar Servi�o  |\n");
    	printf("|3 - Listar produtos    |\n");
    	printf("|4 - Listar Servi�os    |\n");
    	printf("|5 - Buscar Produtos    |\n");
    	printf("|6 - Buscar Servi�os    |\n");
    	printf("|7 - Deletar Produto    |\n");
    	printf("|8 - Deletar Servi�os   |\n");
    	printf("|9 - Atualizar Produtos |\n");
    	printf("|10 - Atualizar Servi�os|\n");
    	printf("|11 - Caixa             |\n");
    	printf("|12 - Voltar            |\n");
    	printf("+-----------------------+\n");

    	scanf("%d",&opcao_ADM);

    	switch(opcao_ADM){
    		case 1:

    			break;
    		case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
    			break;
    		case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;

		}
}

int main(int argc, char const *argv[]){
  int opcao;

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
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        cadastrarProduto();
        //menuAdministrativo();
        break;
      case 2:
        //menuLoja();
        break;
      case 3:
        printf("Obrigado por utilizar nosso programa.\n");
        break;
      default:
        printf("Opcao invalidas\n");
    }
  } while(opcao != 3);

  return 0;
}
