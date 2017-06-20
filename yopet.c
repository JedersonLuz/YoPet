/*
 *Autores: HÃ©lio Rocha, Jederson Luz, Myllena Caetano
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
}

int main(int argc, char const *argv[]) {

  struct produtos produto[255];
  struct sevicos servico[255];
  int opcao;

  do {
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
        //menuAdministrativo();
        break;
      case 2:
        //menuLoja();
        break;
      case 3:
        printf("Obrigado por utilizar nosso programa.\n", );
        break;
      default:
        printf("Opcao invalidaS\n");
    }
  } while(opcao != 3);

  return 0;
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
    	printf("|2 - Cadastrar Serviço  |\n");
    	printf("|3 - Listar produtos    |\n");
    	printf("|4 - Listar Serviços    |\n");
    	printf("|5 - Buscar Produtos    |\n");
    	printf("|6 - Buscar Serviços    |\n");
    	printf("|7 - Deletar Produto    |\n");
    	printf("|8 - Deletar Serviços   |\n");
    	printf("|9 - Atualizar Produtos |\n");
    	printf("|10 - Atualizar Serviços|\n");
    	printf("|11 - Caixa             |\n");
    	printf("|12 - Voltar            |\n");
    	printf("+-----------------------+\n");
    	scanf("%d",&opcao_ADM);
    	
    	switch(opcao_ADM){
    		case 1:
    			printf("Informe o nome do produto:\n ");
    			scanf("%s",&produtos.nome);
    			printf("Informe preco do produto:\n ");
    			scanf("%f",&produtos.preco);
    			break;
    		case 2:
    			printf("Informe o nome do serviço:\n ");
    			scanf("%s",&servicos.nomeServico);
    			printf("Informe o valor do servico:\n ");
    			scanf("%f",&servicos.preco);
				break;
			case 3:
				printf("%s : %.2f\n", produtos.nome, produtos.preco);
				break;
			case 4:
				printf("%s : %.2f\n", servicos.nomeServico, servicos.preco);
				break;
			case 5:
				printf("Nome do produto:\n ");
				Scanf("%s",&buscarProduto);
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
