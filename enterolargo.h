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
EnteroLargo *sumaEnteroLargo(numero1, numero2){//pruebas del algoritmo para sumar listas
    //Definicion listas de prueba
    int lista[MAX]={3,2,5,4,9};
    int lista2[MAX]={1,2,3,4,5};
  
    int num1,total=0,num2,aux,aux1,aux2,extra=0;
    //For que recorre la lista desde atras hacia adelante para la suma manual
    for (int i = 4; i >=0 ; i--)
    {
        //rescatamos el digito de la lista(Futura lista enlazada)
        num1=lista[i];
        num2=lista2[i];

        //verificamos si hay un numero sobrante de la suma anterior
        if(extra!=0){
            aux=num1+num2+extra;
            extra=0;
        }
        else{
            aux=num1+num2;
        }
        //si la suma es mayor que 10 separamos los digitos
        if(aux>10){
            aux1=aux/10;
            aux2=aux%10;
            //el sobrante lo guardamos para sumarlo en la proxima vuelta
            extra=aux1;
            //agregamos el digito a la izquierda
            total=agregar_al_inicio(total,aux2);
            //reiniciamos variables
            num1=0;aux=0;num2=0;aux1=0;aux2=0;
        }
        else{
            //agregamos el digito a la izquierda
            total=agregar_al_inicio(total,aux);
            num1=0;
            num2=0;
            aux=0;
        }
    }
  //Verificacion de que el algoritmo esta funcionando 
    printf("El resultado de la suma es: %d",total);
  
}
//va moviendo los numeros para ir agregandolos a la izquierda de la variable(Solo para la prueba)
int agregar_al_inicio(int variable, int n) {
    int temp = variable;
    while (temp > 0) {
        n *= 10;
        temp /= 10;
    }
    return n + variable;
} 
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
