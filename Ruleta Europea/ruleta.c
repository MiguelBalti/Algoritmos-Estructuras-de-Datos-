    
//Ruleta Europea  números del 1 al 36 (rojo o negro) y 0 (verde)
//Miguel Angel Baltazar Coyotl
     
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include" \ElemCirc.h"
#include" \Circular.h"


void iniciar();
Circular ruleta(Circular c);
int girar(Circular c);
void girando();
void apuesporNum();
int color(int n);
int EstaEn(int n, int num[]);
void colorN(int n);
void apuesporCol();
int parOim(int n);
void apuesporPar();
int Mom(int n);
void apuesporMom();

int allmoney = 0, money = 0, n, again = 1, apuesta, play;

int main(){
	
	puts("Ingresa tu dinero: \n");
	puts("Solo cantidades exactas\n");
	scanf("%d",&allmoney);
		
	do{
		if(allmoney == 0){
			puts("NO tienes el dinero suficiente.");
			again = 0;
		}
		else{	
			iniciar();	
			switch(play){
				case 1:
					apuesporNum();
					break;
				case 2:
					apuesporCol();
					break;
				case 3:
					apuesporPar();
					break;
				case 4:
					apuesporMom();
					break;
				default:
					puts("Ingresa de nuevo tu opcion: ");
					break;
			}
			puts("\n\nEscribe 1 para jugar de nuevo/ 0 para salir \n");
			scanf("%d",&again);		
			system("cls");
		}
	}while(again != 0);
	
	return 0;
}

Circular ruleta(Circular c){
	int i=0;	
	int num[] = {0,32,15,19,4,21,2,25,17,34,6,27,13,36,11,30,8,23,
				10,5,24,16,33,1,20,14,31,9,22,18,29,7,28,12,35,3,26};
	for(i=0;i<37;i++){
		c=formarC(c,num[i]);		
	}  
	return c;		
}

int girar(Circular c){
	int n;
	srand(time(NULL));
	n = rand()%37;
	for(int i=0;i<n;i++){
        c=rotar(c);
    }
    return primeroC(c);
}

void girando(){
	printf("\tGirando ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(".");
	Sleep(1000);
}

void apuesporNum(){
	puts("Escribe un numero entre 0-36: ");
	scanf("%d",&apuesta);
	Circular c = nuevaC();
	n = girar(ruleta(c));
	puts("\n");
	girando();
	printf("\n\n\t-> |%d| <-\n",n);
	printf("\nTu numero fue %d\n",apuesta);
	printf("El numero que salio fue %d\n",n);
	if(n == apuesta){
		money = money*36;
		printf("\n\tFelicidades\n");
		printf("Ganaste %d",money);
		allmoney = allmoney+money;
		printf("\nEl total del dinero es: %d ",allmoney);
		}
	else{
		printf("Suerte para la proxima!");
		printf("\nTienes $ %d",allmoney);
	}
}

int EstaEn(int n, int num[]){
	int x = 0;
	for(int i=0;i<18;i++){
		if(n == num[i]){
			x = 1;
		}
	}
	return x;
}

int color(int n){
	int negro[] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
	int rojo[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	if(EstaEn(n,negro)){
		return 1;
	}
	else if(EstaEn(n,rojo)){
		return 2;
	}
	else{
		return 3;
	}
}

void colorN(int n){
	if(n == 1){
		puts("\t   Negro");
	}
	else if(n == 2){
		puts("\t   Rojo");
	}
	else{
		puts("\t   Verde");
	}
}

void apuesporCol(){
	puts("Ingresa 1.- Negro / 2.- Rojo / 3.- Verde");
	scanf("%d",&apuesta);
	Circular c = nuevaC();
	n = girar(ruleta(c));
	puts("\n");
	girando();
	printf("\n\n\t-> |%d| <-\n",n);
	colorN(color(n));				
	if((color(n) == apuesta) && (n == 0)){
		money = money*36;
		printf("\n\tFelicidades\n");
		printf("Ganaste %d",money);
		allmoney = allmoney+money;
		printf("\nEl total del dinero es: %d ",allmoney);
		}
	else if(color(n) == apuesta){
		money = money*2;
		printf("\n\tFelicidades\n");
		printf("Ganaste %d",money);
		allmoney = allmoney+money;
		printf("\nEl total del dinero es: %d ",allmoney);
		}
		else{
			printf("\nSuerte para la proxima!");
			printf("\nTienes $ %d",allmoney);
		}
}

int parOim(int n){
	int x;
	if((n%2) == 0){
		x = 1;
	}
	else{
		x = 2;
	}
	return x;
}

void apuesporPar(){
	puts("Ingresa 1.- Par / 2.- Impar");
	scanf("%d",&apuesta);
	Circular c = nuevaC();
	n = girar(ruleta(c));
	puts("\n");
	girando();
	printf("\n\n\t-> |%d| <-\n\n",n);
	if(parOim(n) == apuesta){
		money = money*2;
		printf("\n\tFelicidades\n");
		printf("Ganaste %d",money);
		allmoney = allmoney+money;
		printf("\nEl total del dinero es: %d ",allmoney);
	}
	else{
		printf("Suerte para la proxima!");
		printf("\nTienes $ %d",allmoney);
	}
}

int Mom(int n){
	if(n ==0){
		return 0;
	}
	else if(n >= 19){
		return 2;				
	}
	else{
		return 1;
	}
}

void apuesporMom(){
	puts("Ingresa 1.- 1-18 / 2.- 18-36");
	scanf("%d",&apuesta);
	Circular c = nuevaC();
	n = girar(ruleta(c));
	puts("\n");
	girando();
	printf("\n\n\t-> |%d| <-\n\n",n);
	if(Mom(n) == apuesta){
		money = money*2;
		printf("\n\tFelicidades\n");
		printf("Ganaste %d",money);
		allmoney = allmoney+money;
		printf("\nEl total del dinero es: %d ",allmoney);
	}
	else{
		printf("Suerte para la proxima!");
		printf("\nTienes $ %d",allmoney);
	}
	
}

void iniciar(){
	printf("\nTienes $ %d",allmoney);
	puts("\nIngresa el dinero a apostar: ");
	scanf("%d",&money);
	allmoney = allmoney - money;
	puts("Ingresa tu forma de apuesta : ");
	puts("1.- Apuesta por numero:");
	puts("2.- Apuesta por color: ");
	puts("3.- Apuesta por par o impar");
	puts("4.- Apuesta del 1-18 o 19-36");
	scanf("%d",&play);
}