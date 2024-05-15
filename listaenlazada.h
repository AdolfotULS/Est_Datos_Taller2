#ifndef listaenlazada_h
#define listaenlazada_h
#include "enterolargo.h"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef struct Numero {
  struct Numero *digito_ant;
  float valor_digito;
  // int decimal; // 0 - 1
  struct Numero *digito_sgte;
} Numero;

void agregar_elemento(struct Numero **numero, int nuevo_digito) {
  struct Numero *nuevoNum = (struct Numero *)malloc(sizeof(struct Numero));
  nuevoNum->valor_digito = nuevo_digito;
  nuevoNum->digito_sgte = NULL;
  if (*numero == NULL) {
    nuevoNum->digito_ant = NULL;
    *numero = nuevoNum;
  } else {
    struct Numero *ultimo = *numero;
    while (ultimo->digito_sgte != NULL) {
      ultimo = ultimo->digito_sgte;
    }
    ultimo->digito_sgte = nuevoNum;
    nuevoNum->digito_ant = ultimo;
  }
}

void invertir_lista(struct Numero **cabeza_numero) {
  struct Numero *digito_previo = NULL;
  struct Numero *digito_actual = *cabeza_numero;
  struct Numero *digito_siguiente = NULL;

  while (digito_actual != NULL) {
    digito_siguiente = digito_actual->digito_sgte;
    digito_actual->digito_sgte = digito_previo;
    digito_previo = digito_actual;
    digito_actual = digito_siguiente;
  }
  *cabeza_numero = digito_previo;
}

void imprimir_numero(struct Numero *cabeza_numero) {
  if (cabeza_numero == NULL) {
    printf("0");
    return;
  }

  struct Numero *nodo_digito = cabeza_numero;
  while (nodo_digito != NULL) {
    printf("%.0f", nodo_digito->valor_digito);
    nodo_digito = nodo_digito->digito_sgte;
  }
  printf("\n");
}

/*
EXAMPLE

int main() {

  struct Numero *listaEnlazada = NULL;
  agregar_elemento(&listaEnlazada, 8);
  agregar_elemento(&listaEnlazada, 3);
  agregar_elemento(&listaEnlazada, 4);

  printf("Lista Original: ");
  imprimir_numero(listaEnlazada);

  invertir_lista(&listaEnlazada);
  printf("Lista Invertida ");
  imprimir_numero(listaEnlazada);
}
*/

#endif