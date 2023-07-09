#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include"C:\ESCOM\2 semestre\Algoritmos\Backgammon\ElemCirc.h"
#include"C:\ESCOM\2 semestre\Algoritmos\Backgammon\Circular.h"

void inicializa(Circular q);
void ImpTablero(Circular q);
int da2();
Circular playNegro(Circular q);
Circular playNegroall(Circular q, int w);
Circular playRojo(Circular q);
Circular playRojoall(Circular q, int w);

int pr,pa, roj, neg, restoR=0, restoN=0;

int main(){
     
    Circular d=nuevaC();
    puts("\nNegras son positivas y Rojas negativas");
    inicializa(d);    
    ImpTablero(d);
    
    do{
    d = playNegroall(d,da2());
    puts("\nNegras son positivas y Rojas negativas");
    ImpTablero(d);
    d = playRojoall(d,da2());
	system("cls");   	
    puts("\nNegras son positivas y Rojas negativas");
    ImpTablero(d); 
	}while((roj != 15) || (neg != 15));
	return 0;
}


void inicializa(Circular q){
	// Negras son positivas y Rojas negativas
	int num[] = {2,0,0,0,0,-5,0,-3,0,0,0,5,-5,0,0,0,3,0,5,0,0,0,0,-2};
	
	for(int i=0;i<24;i++){
		q = formarC(q,num[i]);
	}
}

void ImpTablero(Circular q){
	
	int num2[12];
    for(int i=0;i<12;i++){
    	num2[i] = primeroC(q);
      	q=rotaIzq(q);
    }	
    puts("\n");
    for(int i=12;i>=1;i--){
    	printf("|%d| ",i);
	}
	puts("\n__________________________________________________________");
	for(int i=11;i>=0;i--){
    	printf("|%d| ",num2[i]);
	}
    printf("            rojas:[%d]",roj);
    printf("\n\n  Resto de rojas: %d           Resto de negras: %d    ",restoR,restoN);
	printf("\n\n");
    for(int i=12;i<24;i++){
      	ImpElem(primeroC(q));
      	q=rotaIzq(q);
    }
    printf("            negras:[%d]",neg);
	puts("\n__________________________________________________________");
    for(int i=13;i<=24;i++){
    	printf("|%d|",i);
	}
	puts("\n");
}

int da2(){
	int n,g;
	srand(time(NULL));
	n = 1+rand()%6;
	printf("\n\tD1 = %d",n);
    g = 1+rand()%6;
    printf("         D2 = %d\n\n",g);
    if(g == n){
    	printf("El resultado de los dados fue igual\n");
    	return (g+n)*2;
	}
	else{
		return g+n;	
	}
}

Circular playNegro(Circular q){
	Circular d=nuevaC();
	int n,g,sum = 0;
	int num2[24];

	puts("Ingresa la casilla de tu ficha y cuanto se movera: ");
	scanf("%d",&n);
	scanf("%d",&g);
	pr = n;
	pa = g;
	
	for(int i=0;i<24;i++){
    	num2[i] = primeroC(q);
      	q=rotaIzq(q);
    }    
    if(num2[g-1] == -1){
    	num2[n-1] = num2[n-1]-1;
    	num2[g-1] = 1;
    	restoR++;
	}
	else if(n == 0){
		restoN--;
		num2[g-1] = num2[g-1]+1;
	}
		else if(g > 24){
			neg++;
			num2[n-1] = num2[n-1]-1;
		}
			else{
			    num2[n-1] = num2[n-1]-1;
				num2[g-1] = num2[g-1]+1;	
			}
	for(int i=0;i<24;i++){
		d = formarC(d,num2[i]);
	}
	return d;
}

Circular playNegroall(Circular q, int w){
	int sum=0;
	puts("Turno de el jugador con las fichas NEGRAS: \n");
	while(w != sum){
		q = playNegro(q);
		sum = sum + (pa-pr);
	}	
	return q; 
}

Circular playRojo(Circular q){
	int n,g,sum =0;
	int num2[24];
	Circular d=nuevaC();
	int ab;
	
	puts("Ingresa la casilla de tu ficha y cuanto se movera: ");
	scanf("%d",&n);
	scanf("%d",&g);
	pr = n;
	pa = g;
	for(int i=0;i<24;i++){
    	num2[i] = primeroC(q);
      	q=rotaIzq(q);
    } 
	if(num2[g-1] == 1){
		num2[n-1] = num2[n-1]+1;
    	num2[g-1] = -1;
    	restoN++;
	} 
	else if(n == 25){
		restoR--;
		num2[g-1] = num2[g-1]-1;
	}
		else if(g < 1){
				roj++;
				num2[n-1] = num2[n-1]+1;
			}
			else{
		    num2[n-1] = num2[n-1]+1;
			num2[g-1] = num2[g-1]-1;
			}
	for(int i=0;i<24;i++){
		d = formarC(d,num2[i]);
	}
	return d;
}

Circular playRojoall(Circular q, int w){
	int sum=0;
	puts("Turno de el jugador con las fichas ROJAS: \n");
	while(w != sum){
		q = playRojo(q);
		sum = sum + (pr-pa);
	}	
	return q; 
}