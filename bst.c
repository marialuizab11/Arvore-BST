#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

arvore inserir(arvore raiz, t_elem valor){
  //caso base
  if(raiz == NULL){
    //raiz nula = alocação de memoria pra criar uma nova raiz
    arvore nova_raiz = (arvore) malloc(sizeof(no));    
    
    nova_raiz->valor = valor;
    nova_raiz->esq = NULL;
    nova_raiz->dir = NULL;
    return nova_raiz;
  }
  
  //se o programa continuar, significa que temos raiz. verificamos entao se o numero eh maior ou menor que a raiz relativa
  if(valor > raiz->valor){
    //elemento maior que a raiz, insere na direta
    raiz->dir = inserir(raiz->dir, valor);
  } else{
    //elemento menor ou igual que a raiz, insere na esquerda
    raiz->esq = inserir(raiz->esq, valor);
  }
  
  return raiz;
}

void in_order(arvore raiz){
    if(raiz == NULL){
      return;
    }
    in_order(raiz->esq);
    printf("[%d]", raiz->valor);
    in_order(raiz->dir);
}

void pre_order(arvore raiz){
    if(raiz == NULL){
      return;
    }
    printf("[%d]", raiz->valor);
    pre_order(raiz->esq);
    pre_order(raiz->dir);
}

void pos_order(arvore raiz){
    if(raiz == NULL){
      return;
    }
    pos_order(raiz->esq);
    pre_order(raiz->dir);
    printf("[%d]", raiz->valor);
}

void reverso(arvore raiz){
  if(raiz == NULL){
      return;
  }
  reverso(raiz->dir);
  printf("[%d]", raiz->valor);
  reverso(raiz->esq);
}

int qtdeFolhas(arvore raiz){
  if(raiz == NULL){
    return 0;
  }
  
  if(raiz->esq == NULL && raiz->dir == NULL){
    return 1;
  }
  
  return qtdeFolhas(raiz->esq) + qtdeFolhas(raiz->dir);
}

t_elem sucessor(int n, arvore raiz){
  if(raiz == NULL){
    return -1;
  }
  
  if(raiz->valor == n){
    if(raiz->esq != NULL){
      return raiz->esq->valor;
    } else{
      //nao ha sucessor
      return -1;
    }
  } else if(n > raiz->valor){
    sucessor(n, raiz->esq);
  } else {
    sucessor(n, raiz->dir);
  }
}
