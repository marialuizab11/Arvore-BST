#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int agrc, char * argv[]){
  //inicializacao
  arvore bst = NULL;
  int op;
  t_elem valor;
  
  while(1){
    scanf("%d", &op);
    switch(op){
      case 1:
        scanf("%d", &valor);
        bst = inserir(bst, valor);
        break;
      case 2:
        pre_order(bst);
        printf("\n");
        break;
      case 3:
        in_order(bst);
        printf("\n");
        break;
      case 4:
        pos_order(bst);
        printf("\n");
        break;
      case 5:
        reverso(bst);
        printf("\n");
        break;
      case 6:
        printf("%d\n", qtdeFolhas(bst));
        break;
      case 7:
        scanf("%d", &valor);
        printf("%d\n", sucessor(valor, bst));
        break;
      case 8:
        scanf("%d", &valor);
        printf("%d\n", encontraPai(valor, bst));
        break;
        
      case 11:
        bst = limpar(bst);
        break;
      case 99:
        return 0;
    }
  }
}
