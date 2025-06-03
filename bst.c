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

arvore encontrarNo(int n, arvore raiz){
  if(raiz == NULL || raiz->valor == n){
    return raiz;
  }
  
  if(n < raiz->valor){
    return encontrarNo(n, raiz->esq);
  } else {
    return encontrarNo(n, raiz->dir);
  }
}

arvore encontrarMinimo(arvore raiz){
  while(raiz != NULL && raiz->esq != NULL){
    raiz = raiz->esq;
  }
  return raiz;
}

t_elem sucessor(int n, arvore raiz){
  arvore noProcurado = encontrarNo(n, raiz);
  if(noProcurado == NULL){
    return -1;
  }
  
  if(noProcurado->dir != NULL){
    arvore sucessor = encontrarMinimo(noProcurado->dir);
    return sucessor->valor;
  }
  
  arvore sucessor = NULL;
  arvore ancestral = raiz;
  
  while(ancestral != NULL){
    if(n < ancestral->valor){
      sucessor = ancestral;
      ancestral = ancestral->esq;
    } else if(n > ancestral->valor){
      ancestral = ancestral->dir;
    } else{
      break;
    }
  }
  
  if(sucessor != NULL){
    return sucessor->valor;
  }
  return -1;
}

t_elem encontraPai(int n, arvore raiz){
  if(raiz == NULL || raiz->valor == n){
    return -1;
  }
  
  arvore pai = raiz;
  
  if(pai->esq != NULL && pai->esq->valor == n){
    return pai->valor;
  } else if(pai->dir != NULL && pai->dir->valor == n){
    return pai->valor;
  } else {
    if(n < pai->valor){
      return encontraPai(n, pai->esq);
    } else{
      return encontraPai(n, pai->dir);
    }
  }
  return -1;
}

arvore limpar(arvore raiz){
  if(raiz == NULL){
    return NULL;
  }
  raiz->esq = limpar(raiz->esq);
  raiz->dir = limpar(raiz->dir);
  
  free(raiz);
  return NULL;
}

