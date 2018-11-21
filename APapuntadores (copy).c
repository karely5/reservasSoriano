#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct reservacion{
 
	char nombre[50];
	char telefono[25];
	
	char correo[25];
	char turno[50];
	int vigente;
	int hora;
	char fecha[25];
	};
	int main(){
		
	struct reservacion *reservaciones;
	reservaciones=malloc(sizeof(struct reservacion)*10);
	struct reservacion *p_reservaciones;
	p_reservaciones=reservaciones;
	char nombre[30];
	char telefono[25];
	char correo[25];
	char fecha[20];
	char opcion;
	char turno[50];
	int hora,i;
	
	int cantidadReservaciones;
	int banderaReservacion=0,banderaConsulta=0;
	do
	{
		
		printf("----------MENU DE OPCIONES---------");
		printf("ELIGE UNA OPCION:\n");
		printf("A>ALTA DE RESERVACION:\n");
		printf("B>BAJA DE RESERVACION:\n");
		printf("C>CONSULTA DE RESERVACIONES :\n");
		printf("V>VERIFICAR VIGENCIAS DE RESERVACIONES:\n");
		printf("S> PARA SALIR:\n");
		opcion=getchar();
		getchar();	
	switch (opcion) 
	{
		case 'A':
			 printf("ALTA DE RESERVACION:\n");
			 printf("INGRESA TU NUMERO DE TELEFONO:\n");
			 gets(telefono);
			 printf("INGRESA FECHA DE TU RESERVACION:\n");
			 gets(fecha);
			 printf("INGRESA LA HORA DE TU RESERVACION:\n");
			 scanf("%d", &hora);
			 getchar();
	
			  if(hora>=8 && hora <= 12){
			  strcpy(turno,"MATUTINO:\n");
				if(hora>=13 && hora<=16){
				 strcpy(turno,"VESPERTINO:\n");
					if(hora>=17 && hora<=23){
			         strcpy(turno,"NOCTURNO:\n");
			  
						if(cantidadReservaciones>0){
							for(i=0;i<cantidadReservaciones;i++){
								if(strcmp(telefono,reservaciones[i].telefono)==0){
									if(strcmp(fecha,reservaciones[i].fecha)==0){
										if(strcmp(turno,reservaciones[i].turno)==0){
											printf("este turno ya ha sido apartado por este cliente:\n");
											 banderaReservacion=1;
											  break;
										}
									}
								}
								p_reservaciones++;
							}
						}
						  if(banderaReservacion==0){
						   printf("este cliente no ha reservado,continue la reservacion:\n");
						   printf("INGRESA TU NOMBRE:\n");
						   gets(nombre);
						   printf("ingrese correo:\n");
						   gets(correo);
						    (strcpy(p_reservaciones[cantidadReservaciones].nombre,nombre));
							  (strcpy(p_reservaciones[cantidadReservaciones].correo,correo));
								(strcpy(p_reservaciones[cantidadReservaciones].telefono,telefono));
								  p_reservaciones[cantidadReservaciones].hora = hora;
								   (strcpy(p_reservaciones[cantidadReservaciones].turno,turno));
									 if(p_reservaciones[cantidadReservaciones].vigente==1){
									  cantidadReservaciones++;
									   printf("SU RESERVACION A SIDO AGENDADA");
									}
						} 	   
	   case 'B':
	   printf("BAJA DE RESERVACION:\n");
	   strcpy(telefono,"\0");
	   strcpy(fecha,"\0");
	   strcpy(turno,"\0");
	   hora=0;
	   i=0;
	   int banderaBaja=0;
	   printf("deme su telefono:\n");
	   gets(telefono);
	   printf("fecha de su reservacion:\n");
	   gets("fecha");
	   printf("deme la hora de su reservacion:\n");
	   scanf("%d",&hora);
	   getchar();
	        if( hora >= 8 && hora <= 12){
			 strcpy(turno, "matutino");
			}
				if( hora >= 13 && hora <= 16){
				 strcpy(turno, "vespertino");
			}
					if( hora >= 17 && hora <= 23){
					 strcpy(turno, "nocturno");
			}
	   
	   if(cantidadReservaciones>0){
	   p_reservaciones=reservaciones;
	   for(i=0;i<cantidadReservaciones;i++){
	   if(strcmp(p_reservaciones[cantidadReservaciones].telefono,telefono)==0){;
	   if(strcmp(p_reservaciones[cantidadReservaciones].fecha,fecha)==0){;
	   if(strcmp(p_reservaciones[cantidadReservaciones].turno,turno)==0){;
	   printf("LA RESERVACION SE HA DADO DE BAJA EXITOSAMENTE:\n");
	   banderaBaja=1;
	   p_reservaciones[cantidadReservaciones].vigente=0;
	   break;
		}
		}
		}
		p_reservaciones++;
		}
		}
		if(banderaBaja==0){
		printf("LA RESERVACION NO SE HA ENCONTRADO:\n");	
	
		}
		case 'C':
		printf ("EN ESTA SECCION PODRA HACER CONSULTAS:\n");
		do{
			printf("----------MENU DE OPCIONES---------");
			printf("ELIGE UNA OPCION:\n");
			printf("X>CONSULTA DE RESERVACION:\n");
			printf("Y>RESERVACIONES EXISTENTES:\n");
			printf("Z>SALIR AL MENU PRINCIPAL:\n");
			opcion=getchar();
			getchar();
			switch(opcion)
			case 'X':
			printf("CONSULTAR UNA RESERVACION:\n");
			printf("ingrese telefono:\n");
			gets(telefono);
			printf("ingrese la hora de su reservacion:\n");
			scanf("%d",&hora);
			if( hora >= 8 && hora <= 12){
				strcpy(turno, "matutino");
			}
			if( hora >= 13 && hora <= 16){
				strcpy(turno, "vespertino");
			}
			if( hora >= 17 && hora <= 20){
				strcpy(turno, "nocturno");
			}
			if(cantidadReservaciones>0){
			p_reservaciones=reservaciones;
			for(i=0;i<cantidadReservaciones;i++){
			if(strcmp(p_reservaciones[cantidadReservaciones].telefono,telefono)==0){
				 if(strcmp(turno,p_reservaciones->turno)==0){
					 printf("la reservacion a sido encontrada:\n");
					  printf("Nombre: %s\n",p_reservaciones->nombre);
		    			printf("Telefono: %s\n",p_reservaciones->telefono);
						 printf("Correo: %s\n",p_reservaciones->correo);
				    	  printf("Fecha: %s\n",p_reservaciones->fecha);
						   printf("Hora: %d\n",p_reservaciones->hora);
							banderaConsulta = 1;
						   	 break;
						 }
					 }
		 
				 }
			 }
			 else
			 {
				 printf("no hay reservaciones para consultar:\n");
			 }
			 if(banderaConsulta==0)
			 {
			 printf("no existe la reservacion con los datos dados:\n");
		     }
		     break;
		     case 'Y':
		     printf("CONSULTA DE RESERVACIONES EXISTENTES:\n");
		     p_reservaciones=reservaciones;
		     if(cantidadReservaciones>0){
		     for(i=0;i<cantidadReservaciones;i++){
				 if(p_reservaciones->vigente==1){
				 printf("RESERVACIONES EXISTENTES:\n");
		     }
		 }
		     case 'Z':
		     printf("SALIR AL MENU PRINCIPAL:\n");
		     break;
		 }while(opcion=='X'||opcion=='Y'||opcion=='Z');
		 break;
		     case 'V':
		     printf("verificar vigencia de reservacion:\n");
		     
			printf("vigencia de reservacion.");
			strcpy(telefono,"");
			strcpy(fecha,"");
			hora = 0;
			strcpy(turno,"");
			i = 0;
			banderaConsulta = 0; 
			
			printf("ingrese su numero de telefono:\n");
			gets(telefono);
			 
			printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
			gets(fecha);
			 
			printf("ingrese la hora de su reservacion:\n");
			scanf("%d", &hora);
			getchar();
			if( hora >= 8 && hora <= 12){
				strcpy(turno, "matutino");
			}
			if( hora >= 13 && hora <= 16){
				strcpy(turno, "vespertino");
			}
			if( hora >= 17 && hora <= 20){
				strcpy(turno, "nocturno");
			}
			
			if(cantidadReservaciones > 0){
				p_reservaciones=reservaciones;
				for( i = 0; i < cantidadReservaciones; i++){
					
					if(strcmp(telefono,p_reservaciones->telefono) == 0){
						if(strcmp(fecha, p_reservaciones->fecha) == 0){
							if(strcmp(turno,p_reservaciones->turno)==0){
								printf("La reservacion ha sido encontrada.\n");
								if(p_reservaciones->vigente == 1)
								{
									printf("La reservación está vigente\n\n");
								}
								else 
								{
									printf("La reservación no está vigente\n\n");
									banderaConsulta = 1;
									break;
								}
							}
						}
					}
				}
			}
			else {
				printf("No hay reservaciones para consultar\n");
			}
			if(banderaConsulta == 0){
				printf("No se ha encontrado la reservación con los datos dados.\n");
			}
			break;
		 }
	}
	
	 
 }
}
}while(opcion='A'|| opcion='B'||opcion='C'||opcion='V'||opcion='S');
}
return 0;
}
}




	 
 
	 
		
	
	

	







	

