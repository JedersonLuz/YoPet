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
