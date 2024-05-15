#ifndef enterolargo_h
#define enterolargo_h
#include "listaenlazada.h"
#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EnteroLargo {
  int signo;              // 1 y -1
  int cantidad_digitos;   // Numero de Digitos
  struct Numero *digitos; // Digitos del Numero
} EnteroLargo;

EnteroLargo *creaEnteroLargoDesdeStr(char *str) {
  EnteroLargo *nuevo_entero_largo = (EnteroLargo *)malloc(sizeof(EnteroLargo));
  // Crear una nueva instancia de EnteroLargo en memoria dinámica

  nuevo_entero_largo->signo = (str[0] == '-') ? -1 : 1;
  // Determinar el signo del número: -1 para negativo, 1 para positivo

  nuevo_entero_largo->cantidad_digitos =
      strlen(str) - (nuevo_entero_largo->signo == -1);
  // Calcular la cantidad de dígitos, restando 1 si es negativo (por el signo
  // '-')

  nuevo_entero_largo->digitos = NULL;
  // Inicializar el puntero de la lista de dígitos como NULL

  int indice_inicio = (nuevo_entero_largo->signo == -1) ? 1 : 0;
  // Determinar el índice de inicio para recorrer la cadena, omitiendo el signo
  // '-' si es negativo

  for (int i = strlen(str) - 1; i >= indice_inicio; i--) {
    agregar_elemento(&(nuevo_entero_largo->digitos), str[i] - '0');
  }
  // Recorrer la cadena en orden inverso y agregar cada dígito a la lista de
  // dígitos

  return nuevo_entero_largo;
  // Retornar la nueva instancia de EnteroLargo creada
}

char *creaStrDesdeEnteroLargo(EnteroLargo *numero);
int copiaEnteroLargo(EnteroLargo *destino, EnteroLargo *fuente);
int eliminaEnteroLargo(EnteroLargo *numero);
EnteroLargo *leeEnteroLargo(char *nombreArchivo);
int escribeEnteroLargo(char *nombreArchivo, EnteroLargo *numero);
int igualEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *restaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *multiplicaEnteroLargo(EnteroLargo *multiplicando,
                                   EnteroLargo *multiplicador);
EnteroLargo *divideEnteroLargo(EnteroLargo *dividendo, EnteroLargo *divisor);
// EnteroLargo *CreaEnteroLargoDesteStr("123")
// char *creaStrDesdeEnteroLargo(numero)
// int copiaEnteroLargo(destino, fuente)
// int eliminaEnteroLargo(numero);
// EnteroLargo *leeEnteroLargo(nombreArchivo);
// int escribeEnteroLargo(nombreArchivo, numero);
// int igualEnteroLargo(numero1, numero2);
// EnteroLargo *sumaEnteroLargo(numero1, numero2);
// EnteroLargo *restaEnteroLargo(numero1, numero2);
// EnteroLargo *multiplicaEnteroLargo(multiplicando, multiplicador);

/*
EnteroLargo *divideEnteroLargo(dividendo, divisor);

Retornar una referencia a un nuevo EnteroLargo con el valor de la division
entera de los numeros referencidos por dividendo y divisor (ambos de tipo
EnteroLargo)

*/

////////////////////////////////////////////////////////////////////////////CHIBI//////////////////////////////////////////////////////////////////////////

/*
EnteroLargo *divideEnteroLargo(dividendo, divisor);

Retornar una referencia a un nuevo EnteroLargo con el valor de la division
entera de los numeros referencidos por dividendo y divisor (ambos de tipo
EnteroLargo)

ENTRADA: EnteroLargo dividendo;
ENTRADA: EnteroLargo divisor;

SALIDA: EnteroLargo resultado;

*/

///////////////////////////////////////////////////////////////////////CHIBI///////////////////////////////////////////////////////////////////////////////
#endif
