/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo;
	char caracter;
	
	archivo = fopen("salida.txt","r");
	
	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            printf("\nEl contenido del archivo de prueba es \n\n");
            while((caracter = fgetc(archivo)) != EOF)
	    {
		printf("%c",caracter);
	    }
        }
        fclose(archivo);
	return 0;
}*/
/*
#include <stdio.h>
 
int main ( int argc, char **argv )
{
 	FILE *fp;
 	
 	char caracter;
 		
 	fp = fopen ( "salida.txt", "a+t" ); //parametro para escritura al final y para file tipo texto
 	
 	printf("\nIntroduce un texto al fichero: ");
 	
 	while((caracter = getchar()) != '\n')
 	{
 		printf("%c", fputc(caracter, fp));
 	}
 	
 	fclose ( fp );
 	
 	return 0;
}*/



#include <stdio.h>
 
int main ( int argc, char **argv )
{
 	FILE *fp;
 	
 	char cadena[20] = "karely.\n";
 	char cadena2[20] = "yona.\n";
 	char cadena3[20] = "tati.\n";
 	
 	fp = fopen ( "salida.txt", "r+" );
 	
 	fputs( cadena3, fp );//1
 	fputs( cadena2, fp );//2
 	fputs( cadena, fp );//3
 	fputs( cadena, fp );//3
 	
 	
 	fclose ( fp );
 	
 	return 0;
}
