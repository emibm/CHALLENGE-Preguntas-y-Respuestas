#ifndef BPROGRAM_H
#define BPROGRAM_H

const int TAM=60;

struct Stats { /* Datos del jugador */
int dinero;
int nivel; // Nivel maximo superado
int comp;
char estado[TAM];
char items[TAM];
}; typedef Stats* status;

status CrearJ(); /* Procedimiento que crea el nodo con datos del jugador */ 

void bienvenido(); /* Teletransportacion y mensaje de bienvenida */
int menu(status ); /* Dibuja el menu y muestra las stats */
void lineas(); /* Dibuja las lineas */

int nivel1(); /* PREGUNTAS NIVEL 1  */
int nivel2(); /* PREGUNTAS NIVEL 2  */
int nivel3(); /* PREGUNTAS NIVEL 3  */
int nivel4(); /* PREGUNTAS NIVEL 4  */
int nivel5(); /* PREGUNTAS NIVEL 5  */

#endif

