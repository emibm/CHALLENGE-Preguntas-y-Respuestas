#include "bprogram.h"
#include <cstdio>
#include <windows.h>
#include <iostream>
#include <string.h>
using namespace std;

int main (int argc, char *argv[]) {
int salir=0,opc,correcto, acumulado=0,bonus=0, incorrecto=0, lentes=0, collar=0;
status player=NULL;

player=CrearJ(); /* Creamos nuevo jugador */
bienvenido(); /* Teletransportacion y mensaje */

// player->comp=100; // % DE JUEGO COMPLETO PARA PRUEBAS // 
// player->dinero=1000; // DINERO DE PRUEBA // 

while (salir==0 && player)
{
if(player->comp==100) 
	{cout<<"**************************************************************** \n "  // SI HAY MEDALLA DE JUEGO COMPLETO, MOSTRAR
	<<" |COMPLETADO| OBTENIDO <<[1x Boleto a Tierra.k22.1]>> "<<endl;
	strcpy(player->items,"-||- TODOS LOS ITEMS OBTENIDOS -||- By.Emiliano Borches"); // mostrar creditos
	}
menu(player);
cout<<" Ingrese opcion deseada: ";
cin>>opc;
cout<<endl;

switch(opc)
	{
	case 1:                                                            /* COMIENZA EL JUEGO */
		if(!lentes)  // Si tiene item Lentes de Sol, saltear nivel 1
			{
			correcto=nivel1();   // NIVEL 1
			cout<<" ($10) Ingrese opcion deseada: ";
			cin>>opc;
			if(opc==5) {lineas(); cout<<" Te has retirado conservando el dinero acumulado de $ "<<acumulado+bonus<<endl<<endl;break;} // Salir si el jugador lo desea
			}
		else opc=correcto;
		if(opc==correcto) // Pasa al NIVEL 2 
			{
			if(!lentes)  // Si no tiene lentes damos el bonus para evitar farm de dinero infinito
				{acumulado=acumulado+10;  // Aumentamos el acumulado y el bonus
				bonus=bonus+5;}
			lineas();
			cout<<endl<<" |  +++++++++++ CORRECTO +++++++++++  | Dinero acumulado: $ "<<acumulado<<" Bonus de racha  $ "<<bonus<<endl<<endl;
			if(player->nivel==0) 
				{player->comp=player->comp+12; player->nivel=1;}	// Aumenta el % de Juego Completado si no lo ha completado antes. Fin NIVEL 1
			
			correcto=nivel2();     // NIVEL 2
			cout<<" ($10) Ingrese opcion deseada: ";  
			cin>>opc;	
			if(opc==5) {lineas(); cout<<" Te has retirado conservando el dinero acumulado de $ "<<acumulado+bonus<<endl<<endl;break;}
			
			if(opc==correcto)         // NIVEL 2
				{
				acumulado=acumulado+10;
				bonus=bonus+5;
				lineas();
				cout<<endl<<" |  +++++++++++ CORRECTO +++++++++++  | Dinero acumulado: $ "<<acumulado<<" Bonus de racha $ "<<bonus<<endl<<endl;				
				if(player->nivel==1) 
					{player->comp=player->comp+12; player->nivel=2;} 	// Aumenta el % de Juego Completado si no lo ha completado antes. Fin NIVEL 2
			
				correcto=nivel3();         // NIVEL 3
				cout<<" ($15) Ingrese opcion deseada: ";
				cin>>opc;
				if(opc==5) {lineas();cout<<" Te has retirado conservando el dinero acumulado de $ "<<acumulado+bonus<<endl<<endl;break;}
				
				if(opc==correcto)         // NIVEL 3
					{
					acumulado=acumulado+15;
					bonus=bonus+5;
					lineas();
					cout<<endl<<" |  +++++++++++ CORRECTO +++++++++++  | Dinero acumulado: $ "<<acumulado<<" Bonus de racha $ "<<bonus<<endl<<endl;				
					if(player->nivel==2) 
					{player->comp=player->comp+12; player->nivel=3;} // FIN NIVEL 3
					
					correcto=nivel4();    // NIVEL 4
					cout<<" ($20) Ingrese opcion deseada: ";
					cin>>opc;
					if(opc==5) {lineas();cout<<" Te has retirado conservando el dinero acumulado de $ "<<acumulado+bonus<<endl<<endl;break;}
					
					if(opc==correcto)         // NIVEL 4
						{
						acumulado=acumulado+20;
						bonus=bonus+5;
						lineas();
						cout<<endl<<" |  +++++++++++ CORRECTO +++++++++++  | Dinero acumulado: $ "<<acumulado<<" Bonus de racha $ "<<bonus<<endl<<endl;				
						if(player->nivel==3) 
						{player->comp=player->comp+12; player->nivel=4;}  // FIN NIVEL 4
						
						correcto=nivel5();    // NIVEL 5
						cout<<" ($30 + Bonus X2 ) Ingrese opcion deseada: ";
						cin>>opc;
						if(opc==5) {lineas(); cout<<" Te has retirado conservando el dinero acumulado de $ "<<acumulado+bonus<<endl<<endl;break;}
						
						if(opc==correcto)         // NIVEL 5
							{
							acumulado=acumulado+30;
							bonus=bonus*2;
							if(collar==1) {acumulado=acumulado*2; bonus=bonus*2;}  // Si tiene item Collar, multiplicar dinero
							lineas();
							cout<<endl<<" |  +++++++++++ HAS SUPERADO TODOS LOS NIVELES +++++++++++  | Dinero acumulado: $ "<<acumulado<<" Bonus de racha $ "<<bonus<<endl<<endl;				
							if(player->nivel==4) 
							{player->comp=player->comp+12; player->nivel=5;}
							}                                                          // FIN NIVEL 5
						else incorrecto=1;
						}
					else incorrecto=1;
					}
				else incorrecto=1;
				}
			else incorrecto=1;
			}
		else
		   incorrecto=1;			
		
		if(incorrecto==1)
		   {
			lineas();
			cout<<endl<<" <<< Opcion incorrecta >>> DINERO ACUMULADO PERDIDO: $ "<<acumulado+bonus<<endl<<endl;
			acumulado=0; bonus=0;                   /* Pierde el dinero acumulado */			
			}
		
		break;	
	
	case 2:	                  // M E R C A D O //
		lineas();
		cout<<" XXXXXXXXXXXXXXXXXXX M E R C A D O XXXXXXXXXXXXXXXXXXX"<<endl<<endl;
		cout<<" Dinero : $ "<<player->dinero<<endl<<endl;
		cout<<" ++++++++++ Comprar Mejoras ++++++++++"<<endl<<endl;
		cout<<" 1) $ 390 | Lentes de Sol | i:Empieza siempre desde el nivel 2 \n 2) $ 850 | Collar Antipulgas | i:Obtienes el doble de dinero al ganar el nivel 5 \n \n 0) Salir \n \n";
		cout<<" Comprar item Nro: ";
		cin>>opc;
		cout<<endl;
		
		if(opc==1)  // Compra de Lentes de Sol
			{
			if(lentes==1) {cout<<" ******* ERROR : El item ya ha sido obtenido *******"<<endl<<endl; break;} // Si el item ya esta posesion, no comprar
			if(player->dinero-390 >= 0)
				{
				player->dinero=player->dinero-390;   // Gastamos el dinero y aumentamos el % Completado del juego
				player->comp=player->comp+20;
				cout<<" | COMPRA EXITOSA | Dinero -390"<<endl;
				strcat(player->items,"(~)_(~ ) Lentes ");
				lentes=1;				
				}
			else cout<<" --$$-- ERROR : Dinero Insuficiente --$$--"<<endl;
			}		
		if(opc==2)   // Compra de Collar
			{
			if(collar==1) {cout<<" ******* ERROR : El item ya ha sido obtenido *******"<<endl<<endl; break;} // Si el item ya esta posesion, no comprar
			if(player->dinero-850 >= 0)
				{
				player->dinero=player->dinero-850;    			// Gastamos el dinero y aumentamos el % Completado del juego
				player->comp=player->comp+20;
				cout<<" | COMPRA EXITOSA | Dinero -850"<<endl;
				strcat(player->items," [[(   )]] Collar ");
				collar=1;
				}
			else cout<<" --$$-- ERROR : Dinero Insuficiente --$$--"<<endl;
			}
		break;
		
	case 3: cout<<endl<<" >>>>>>>>>> SALIENDO DEL CONCURSO >>>>>>>>>>"<<endl; salir=1; break;		
		
	default: cout<<" *** ERROR:  Opcion invalida ***"<<endl<<endl; break;		
	}

player->dinero=player->dinero+acumulado+bonus; // Gana el dinero acumulado

incorrecto=0; // Reset de variables utilizadas 
acumulado=0;
bonus=0;
} /* Fin del While */
if(player) delete(player); /* Liberar memoria al salir del programa */ 
return 0;
}

