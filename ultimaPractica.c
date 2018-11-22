#include<stdio.h>

int funcion_cuantosElementos(){
	int numeroDeElementos;
	scanf("%d",&numeroDeElementos);	
	
	return numeroDeElementos;
}
void funcion_ingresaValores(int numero[50],int numeroDeElementos){
	int i=0;

	
		for(i=0;i<numeroDeElementos;i++){
					 
			scanf("%d",&numero[i]);
		}
}
void funcion_imprimelista(int numeroDeElementos, int numero[50]){
	int i=0;
	printf("los numeros se han ordenado:\n");
	for(i=0;i<numeroDeElementos;i++){
		printf("%d\n", numero[i]);		
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
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	// a = Lectura y escritura, 
	int numeroElementos, arreglo[50];
	numeroElementos = funcion_cuantosElementos();
	funcion_ingresaValores(arreglo,numeroElementos);
	funcion_imprimelista(numeroElementos,arreglo);
	funcion_ordenalista(arreglo, numeroElementos);
	funcion_imprimelista(numeroElementos,arreglo);
	



	
			
			
	}


//NOTA:cuando se usa el void en un programa no debo usar el return 0
