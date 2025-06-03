#ifndef BST_H
#define BST_H

typedef int t_elem;

typedef struct no {
  t_elem valor;
  struct no * esq;
  struct no * dir;
} no;

typedef no * arvore;

arvore inserir(arvore raiz, t_elem valor);
void in_order(arvore raiz);
void pos_order(arvore raiz);
void pre_order(arvore raiz);
void reverso(arvore raiz);
int qtdeFolhas(arvore raiz);
t_elem sucessor(int n, arvore raiz);
arvore encontrarMinimo(arvore raiz);
arvore encontrarNo(int n, arvore raiz); 
t_elem encontraPai(int n, arvore raiz);
arvore limpar(arvore raiz);
int multiplicaPor(int n, arvore raiz);

#endif
