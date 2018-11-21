#include<stdio.h>

int funcion_cuantosElementos(){
	int numeroDeElementos;
	printf("de cuantos elementos sera tu lista?\n");
	scanf("%d",&numeroDeElementos);	
	
	return numeroDeElementos;
}
void funcion_ingresaValores(int numero[50],int numeroDeElementos){
	int i=0;
	
	printf("ingrese los numeros de la lista\n");
	
		for(i=0;i<numeroDeElementos;i++){
			printf("Digite dato %d:",i+1);			 
			scanf("%d",&numero[i]);
		}
}
void funcion_imprimelista(int numeroDeElementos, int numero[50]){
	int i=0;
	printf("Numeros ingresados son:\n");
	for(i=0;i<numeroDeElementos;i++){
		printf("      %d", numero[i]);		
	}		
}
void funcion_ordenalista(int numero[50], int numeroDeElementos){
	int i,j,comodin=0;
		for(i=0;i<numeroDeElementos;i++){
			for(j=0;j<numeroDeElementos;j++){
				if(numero[i]<numero[j]){
					comodin=numero[i];
					numero[i]=numero[j];
					numero[j]=comodin;
						}
				}
			}
}
int  main(){
	freopen("entrada.txt","w",stdin);
	freopen("salida.txt","w",stdout);
	int numeroElementos, arreglo[50];
	numeroElementos = funcion_cuantosElementos();
	funcion_ingresaValores(arreglo,numeroElementos);
	funcion_imprimelista(numeroElementos,arreglo);
	funcion_ordenalista(arreglo, numeroElementos);
	funcion_imprimelista(numeroElementos,arreglo);
	



	
		printf("\n");
			
			
	}


//NOTA:cuando se usa el void en un programa no debo usar el return 0
