#include "bprogram.h"
#include <iostream>
#include <windows.h>
#include <string.h>
#include <time.h>
using namespace std;

/** +++++++++++++++++++++++++++ Crear Jugador +++++++++++++++++++++++ */

status CrearJ()
{
status player=new Stats;
	
if(player)
	{player->dinero=0;
	player->nivel=0;
	player->comp=0;
	strcpy(player->estado," % Completado");
	strcpy(player->items," ");
	return player;}
	
return NULL;
}

/** +++++++++++++++++++++++++++ Lineas +++++++++++++++++++++++ */

void lineas()
{
int cont2=0;

for(cont2=0;cont2<80;cont2++) cout<<"|X|";

cout<<endl;
}

/** +++++++++++++++++++++++++++ Bienvenido +++++++++++++++++++++++ */

void bienvenido()
{
int cont1=0,cont; 
	
while (cont1<50) /* Teletransportacion */
	{
	for(cont=0;cont<=50;cont++) 
		{cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";}  
	cont1++;		
	}

lineas();
cout<<"Mensaje de uknown.world32.15a:"<<endl<<" BIENVENIDO HUMANO"<<endl
<<" Te hemos teletransportado a nuestro concurso de preguntas y respuestas"<<endl              
<<" Estamos probando un nuevo sistema de tecnologia intergalactica"<<endl
<<" Te hemos asignado el avatar de KANDY : las respuestas pueden verse alteradas "<<endl
<<" Si consigues el 100% se borrara tu memoria antes del concurso y seras llevado a un sustituto planeta Tierra"<<endl
<<" Si consigues ser fiel a tu humano asignado y mantener su anhelada felicidad positivamente obtendras: "<<endl<<endl
<<"  ---------------<<[1x Life Extension Pass - World r81£1¦]>>--------------- "<<endl<<endl	
<<" Recuerda, al fin y al cabo, es todo cuestion de instinto. Have Fun :) "<<endl<<endl;	
lineas();
}

/** +++++++++++++++++++++++++++ Menu +++++++++++++++++++++++ */

int menu(status player)
{
cout<<" ---------------------------------------------------------------"<<endl;
if(player->comp!=100) cout<<" -|- Items Activos -|- ";  // Si tiene la medalla, no mostrar para mostrar creditos
puts(player->items);
cout<<" ---------------------------------------------------------------"<<endl<<" Dinero $  "<<player->dinero<<"\t Estado del concurso: "<<player->comp;puts(player->estado);
cout<<endl<<" --------------------------- M E N U ---------------------------"<<endl;
cout<<endl<<" 1) Iniciar Juego \n 2) Mercado \n 3) Salir \n \n";

return 1;
}

/** +++++++++++++++++++++++++++ NIVEL 1: AVISTAMIENTO +++++++++++++++++++++++ */

int nivel1()
{
srand (time(NULL));
int op=rand()%5+1;

lineas();
cout<<"\t NIVEL 1 - AVISTAMIENTO :";
switch (op)
	{
	case 1: cout<<" Una mosca vuela fugazmente ante tus ojos "<<endl<<endl;op=3;break;
	case 2: cout<<" Un gato te esta mirando muy atentamente desde lejos "<<endl<<endl;op=4;break;    /* Preguntas y respuestas predeterminadas */ 
	case 3: cout<<" Un gato comienza a correr a toda velocidad"<<endl<<endl;op=2;break;
	case 4: cout<<" Algo se mueve en un arbol, parece un ave "<<endl<<endl;op=2;break;
	case 5: cout<<" Un gato se esta acercando, parece amigable"<<endl<<endl;op=1;break;
	default: break;
	}
cout<<" Que harias?:\n \n 1) No hacer nada \t 2) Perseguir ferozmente \t 3) Matar \t 4) Inspeccionar \n \n 5) Salir \n \n";

return op; /* Devuelve la opcion correcta para compararla directamente */
}

/** +++++++++++++++++++++++++++ NIVEL 2: PASEO POR LA CIUDAD +++++++++++++++++++++++ */

int nivel2()
{
srand (time(NULL));
int op=rand()%5+1;
	
cout<<"\t NIVEL 2 - PASEO POR LA CIUDAD :";
switch (op)
	{
	case 1: cout<<" Un perro te ladra ferozmente desde atras de una reja cercana"<<endl<<endl;op=2;break;
	case 2: cout<<" Escuchas fuegos artificiales "<<endl<<endl;op=4;break;    /* Preguntas y respuestas predeterminadas */
	case 3: cout<<" Escuchas una explosion muy fuerte"<<endl<<endl;op=4;break;
	case 4: cout<<" Tu partner quiere ir a un lugar que te da mucho miedo "<<endl<<endl;op=3;break;
	case 5: cout<<" Tu partner quiere jugar a la pelota contigo "<<endl<<endl;op=1;break;
	default: break;
	}	
cout<<" Que harias?:\n \n 1) Ignorar \t 2) Olfatear \t 3) Ir al humano \t 4) Huir  \n \n 5) Salir \n \n";
return op; /* Devuelve la opcion correcta para compararla directamente */
}

/** +++++++++++++++++++++++++++ NIVEL 3: UN DIA NORMAL EN CASA +++++++++++++++++++++++ */

int nivel3()
{
srand (time(NULL));
int op=rand()%5+1;
	
cout<<"\t NIVEL 3 - UN DIA NORMAL EN CASA :";
switch (op)
	{
	case 1: cout<<" Tu partner acaba de irse y hay mucha comida al alcance "<<endl<<endl;op=1;break;
	case 2: cout<<" El repositorio de comida o bebida esta vacio "<<endl<<endl;op=3;break;    /* Preguntas y respuestas predeterminadas */
	case 3: cout<<" Escuchas un ruido raro cerca de la casa"<<endl<<endl;op=3;break;
	case 4: cout<<" Tu partner esta sentado en el ordenador "<<endl<<endl;op=4;break;
	case 5: cout<<" En tus mayores momentos de ocio "<<endl<<endl;op=1;break;
	default: break;
	}	
cout<<" Que harias?:\n \n 1) No hacer nada \t 2) Checkear \t 3) Ladrar/Murmurar \t 4) Dormir \n \n 5) Salir \n \n";
return op; /* Devuelve la opcion correcta para compararla directamente */
}

/** +++++++++++++++++++++++++++ NIVEL 4: COMIDAS Y BEBIDAS +++++++++++++++++++++++ */

int nivel4()
{
srand (time(NULL));
int op=rand()%5+1;
	
cout<<"\t NIVEL 4 - COMIDA/BEBIDA :";
switch (op)
	{
	case 1: cout<<" Si tu partner te obsequia un pedazo de pan "<<endl<<endl;op=4;break;
	case 2: cout<<" Un dia paseando te da mucha sed y ves un pozo con agua cerca "<<endl<<endl;op=3;break;    /* Preguntas y respuestas predeterminadas */
	case 3: cout<<" En las afueras encuentras un pedazo de carne cruda"<<endl<<endl;op=4;break;
	case 4: cout<<" En tu hogar encuentras muchas galletas tiradas en el suelo "<<endl<<endl;op=1;break;
	case 5: cout<<" Un desconocido o cualquier NPC te ofrece dulces "<<endl<<endl;op=2;break;
	default: break;
	}	
cout<<" Que harias?:\n \n 1) Ignorar \t 2) Consumir \t 3)Inspeccionar \t 4) Conservar \n \n 5) Salir \n \n";
return op; /* Devuelve la opcion correcta para compararla directamente */
}

/** +++++++++++++++++++++++++++ NIVEL 5: HUMOR +++++++++++++++++++++++ */

int nivel5()
{
srand (time(NULL));
int op=rand()%5+1;
	
cout<<"\t NIVEL 5 - HUMOR :";
switch (op)
	{
	case 1: cout<<" Si tu partner utiliza correa "<<endl<<endl;op=4;break;
	case 2: cout<<" En caso de comunicacion muy limitada con tu partner "<<endl<<endl;op=3;break;    /* Preguntas y respuestas predeterminadas */
	case 3: cout<<" Si tu partner esta alimentandose"<<endl<<endl;op=2;break;
	case 4: cout<<" Si tu partner adopta una nueva mascota "<<endl<<endl;op=4;break;
	case 5: cout<<" Estás en el paseo rutinario de siempre"<<endl<<endl;op=2;break;
	default: break;
	}	
cout<<" Como te sentirias?:\n \n 1) Neutral \t 2) Alegre \t 3) Triste \t 4) Intrigado\n \n 5) Salir \n \n";
return op; /* Devuelve la opcion correcta para compararla directamente */
}










