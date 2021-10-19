#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char **argv){
	
	int elementos = 0;
	char c = 0;
	
	
	//Aqui manejamos las opciones.
	//El argumento -p tiene un argumento, que es 
	//el numero de elementos a pedir (por eso el :)
	while ((c = getopt (argc, argv, "p:")) != -1){
		switch(c){
			case 'p':
				elementos = atoi(optarg);
				break;
			default:
				printf("Argumento invalido\n");
				exit(1);
		}
	}

	//Los resultados de sus calculos van en estas variables.
	//Puede declarar más variables si lo necesita.
	float sum = 0.0f;
	float max_imc = 0.0f;
	
	float peso = 0.0f;
	float altura = 0.0f;
       	float imcTemp = 0.0f;
	int i = 0;
	
	if(elementos <=0){
		printf("Argumento invalido \n");
		exit(1);
	}
	
	while(i<elementos){
		i=i+1;

		printf("Peso: ");
		scanf("%f", &peso);
		if(peso<0){
			printf("Numero Invalido \n");
			exit(1);
		}

		printf("Altura: ");
		scanf("%f", &altura);
		if(altura<0){
			printf("Numero Invalido \n");
			exit(1);
		}

		imcTemp= peso/(altura *altura);
		sum=sum+imcTemp;
		if( max_imc<imcTemp){
			max_imc=imcTemp;
		}
	}
	sum=sum/elementos;
	
	//No modifique estas lineas
	//Guarde los resultados en las 
	//variables sum y max_imc
	printf("\npromedio IMC: %.1f\n", sum);
	printf("maximo IMC: %.1f\n", max_imc);
}
