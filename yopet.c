/*
 *Autores: Hélio Rocha, Jederson Luz, Myllena Caetano
 *Emails: junior0helio15@gmail.com, jedersonalpha@gmail.com, myllenah2o@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 255

struct produtos {
  int id, quantidade;
  char nome[MAX];
  float preco;
};

struct sevicos {
  int id;
  char nomeServico[MAX], nomeAnimal[MAX], nomeDono[MAX];
  float preco;
};

struct produtos produto[MAX];
struct sevicos servico[MAX];
int contProd = 0;

/*void idGerador(){
    int idn,i;
    idn=(1000+rand()%1000);
    contProd--;
    if(idn!=produto[contProd].id){
        produto[contProd].id=idn;
    }
};*/


void cadastrarProduto () {
  char mensagem[255];
  float test;
  char opcao,opcao1;
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
    int idn,i,testa=0;//gerar id
    idn=(1000+rand()%1000);
    do{
    if(idn!=produto[contProd].id){
        produto[contProd].id=idn;
        testa=1;
    }
    }while(testa==0);
    system("cls||clear");
    printf("Confira se esta correto\n");
    printf("ID gerado: %d\n", produto[contProd].id);
    printf("Nome: %s\n", produto[contProd].nome);
    printf("Preco: %.2f\n", produto[contProd].preco);
    printf("Quantidade: %d\n", produto[contProd].quantidade);
    printf("Deseja confirmar o cadastro?\n[1]-Sim\n[2]-Não\n");
    setbuf(stdin, NULL);
    scanf("%c", &opcao);
    if (opcao == '1') {
      printf("Cadastro conclido.\n");
      //idGerador();
      contProd++;

    }
  } while(opcao != '1');
    menuAdministrativo();
}

void menuAdministrativo(){
    int opcao_ADM;
    system("cls||clear");
    printf("+-----------------------+\n");
    printf("|         YoPet         |\n");
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
                cadastrarProduto();
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

void menuLoja(){
    system("cls||clear");
    int opcao_Cliente;
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
    printf("+-----------------------+\n");
    //scanf("%d",&opcao_Cliente);

}

int main(int argc, char const *argv[]){
  int opcao;

  do {
    //system("cls||clear");
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
        menuAdministrativo();//Teste
        //menuAdministrativo();
        break;
      case 2:
          menuLoja();
        //menuCliente();
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
