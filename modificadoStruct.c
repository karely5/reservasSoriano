#include <stdio.h>
#include <string.h>
#include<stdlib.h>
	
	struct reservacion
		  {
		   char nombre[50];
		   char correo[50];
		   char telefono[15];
		   char fecha[15];
		   char turno[15];
		   int hora;
			int vigente;
		   };
   int main()
   {
	  
	   
	   struct reservacion *reservaciones;
	   reservaciones=malloc(sizeof(struct reservacion)*10);
	    struct reservacion *p_reservaciones;
	    //p_reservaciones=reservaciones;
	   int cantidadReservaciones=0;
	   char opcion;
	   
		char nombre[30];
	char correo[30];
	char telefono[20];
	char fecha[30];
	int hora;
	char turno[20];
	int i;
	int banderaReservacion = 0; //Si vale 0 no tiene reservacion, si vale 1 ya existe con los mismos datos
	int banderaConsulta = 0;
		
	do{
	
	printf("-------MENU DE OPCIONES-------:\n");
	printf("A> Alta de reservacion:\n");
	printf("B> Para dar de baja de reservacion:\n");
	printf("C> Para consulta de reservacion:\n");
	printf("V> Para checar vigencia de reservacion:\n");
	printf("S> Para salir:\n");
	//printf("F> Para ver todas las reservaciones:\n");
	//printf("E> para dar de baja reservaciones anteriores:\n");
	printf("\n");
	
	opcion=getchar();
	getchar();
	opcion=toupper(opcion);
	
	switch (opcion) {
		case 'A':	
			if(cantidadReservaciones==0)
			{//aqui se hace la primera reservacion
									printf("esta es la primera reservacion:\n");
									printf("alta de reservacion\n:");
									printf("deme el nombre de cliente:\n");
									gets(nombre);
									/* getchad(); */
									printf("ingrese correo:\n");
									gets(correo);
									/* getchad(); */
								    printf("ingrese la hora de su reservacion :\n");
									scanf("%d", &hora);
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
									printf("ingrese su numero de telefono:\n");
									gets(telefono);
									/* getchad(); */
									printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
									gets(fecha);
									/* printf("\n\"%s\"\n",fecha);*/
									/* getchad(); */
									p_reservaciones++;
									cantidadReservaciones++;
											
			}
			else
			{
			printf("esta es la segunda reservacion en adelante:\n");		
			
			printf("alta de reservacion\n:");
			printf("deme el nombre de cliente:\n");
			gets(nombre);
			/* getchad(); */
			printf("ingrese fecha:\n");
			gets(fecha);
			/* getchad(); */
		    printf("ingrese la hora de su reservacion :\n");
			scanf("%d", &hora);
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
			
		//	if(cantidadReservaciones > 0){
				p_reservaciones = reservaciones;
				for( i = 0; i < cantidadReservaciones; i++){
					
					if(strcmp(nombre,p_reservaciones->nombre) ==0){
						if(strcmp(fecha, p_reservaciones->fecha) == 0){
							if(strcmp(turno,p_reservaciones->turno)==0){
								printf("Este turno ya ha sido apartado por este cliente\n");
								banderaReservacion = 1;
								
							}
							else
							{
								printf("ingrese su numero de telefono:\n");
								gets(telefono);
								/* getchad(); */
								printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
								gets(fecha);
								/* printf("\n\"%s\"\n",fecha);*/
								/* getchad(); */
								p_reservaciones++;	
							}
						}
					}
					//else if(strcmp(fecha, p_reservaciones->fecha) == 0)
					//{
						
					//}
					
				}
			//}
			
			if(banderaReservacion == 0){
				
				strcpy(reservaciones[cantidadReservaciones].nombre,nombre);
				strcpy(reservaciones[cantidadReservaciones].correo,correo);
				strcpy(reservaciones[cantidadReservaciones].turno,turno);
				
				strcpy(reservaciones[cantidadReservaciones].telefono,telefono);
				strcpy(reservaciones[cantidadReservaciones].fecha,fecha);
				reservaciones[cantidadReservaciones].vigente = 1;
				cantidadReservaciones++;
				printf("su reservacion ha sido agendada.\n\n");
				cantidadReservaciones++;
			}
	}//aqui cierro el else de reservacion vacia
			break;
		case 'B':
		
			strcpy(telefono,"\0");
			strcpy(fecha,"\0");
			hora = 0;
			strcpy(turno,"");
			i = 0;
			int banderaBaja = 0; 
			printf("Baja de reservacion. \n");
			printf("ingrese su numero de telefono:\n");
			gets(telefono);
			/* getchad(); */
			printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
			gets(fecha);
			/* getchad(); */
			printf("ingrese la hora de su reservacion (Sin minutos):\n");
			scanf("%d", &hora);
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
			
			if(cantidadReservaciones > 0){
				for( i = 0; i < cantidadReservaciones; i++){
					
					if(strcmp(telefono,reservaciones[i].telefono) == 0){
						if(strcmp(fecha, reservaciones[i].fecha) == 0){
							if(strcmp(turno,reservaciones[i].turno)==0){
								printf("La reservacion ha sido dada de baja exitosamente\n");
								banderaBaja = 1;
								reservaciones[i].vigente = 0;
								break;
							}
						}
					}
				}
			}
			else {
				printf("No hay reservaciones para dar de baja\n");
			}
			if(banderaBaja == 0){
				printf("No se ha encontrado la reservación con los datos dados.\n");
			}
			break;
		case 'C':
			
			
			do{
			
				printf("1.-Consultar  2.- ver total de reservaciones 3.- algo extra�o\n ");
				opcion=getchar();
				getchar();
				
				switch (toupper(opcion)) {
					
					
					
									case '1':
										strcpy(telefono,"");
										strcpy(fecha,"");
										hora = 0;
										strcpy(turno,"");
										i = 0;
										banderaConsulta = 0; 
										printf("Consulta de reservacion. \n");
										printf("ingrese su numero de telefono:\n");
										gets(telefono);
										/* getchad(); */
										printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
										gets(fecha);
										/* getchad(); */
										printf("ingrese la hora de su reservacion :\n");
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
										printf("\n");
										if(cantidadReservaciones > 0){
											for( i = 0; i < cantidadReservaciones; i++){
												
												if(strcmp(telefono,reservaciones[i].telefono) == 0){
													if(strcmp(fecha, reservaciones[i].fecha) == 0){
														if(strcmp(turno,reservaciones[i].turno)==0){
															printf("La reservacion ha sido encontrada. Datos:\n");
															printf("Nombre: %s\n",reservaciones[i].nombre);
															printf("Telefono: %s\n",reservaciones[i].telefono);
															printf("Correo: %s\n",reservaciones[i].correo);
															printf("Fecha: %s\n",reservaciones[i].fecha);
															printf("Hora: %d\n",reservaciones[i].hora);
															banderaConsulta = 1;
															break;
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
									case '2':
			
										printf("Reservaciones existentes\n");
										if(cantidadReservaciones > 0) {
											for(i = 0; i < cantidadReservaciones; i++) {
												printf("Reservacion %d: \n", i+1);
												printf("Nombre: %s\n",reservaciones[i].nombre);
												printf("Correo: %s\n",reservaciones[i].correo);
												printf("Telefono: %s\n",reservaciones[i].telefono);
												printf("Fecha: %s\n",reservaciones[i].fecha);
												printf("Hora: %d\n",reservaciones[i].hora);
												printf("Turno: %s\n",reservaciones[i].turno);
												if(reservaciones[i].vigente == 1)
													printf("La reservación está vigente\n\n");
												else 
													printf("La reservación no está vigente\n\n");
											}
										}
										else {
											printf("NO HAY RESERVACIONES EXISTENTES\n\n");
										}
										break;
									case '3':
										printf("ELIMINAR OPCIONES CADUCADAS:\n");
										printf("Ingrese la hora actual:\n");
										scanf("%d",&hora);
										getchar();
										if(hora<8 || hora>20)
											printf("CERRADO:\n");
										if( hora >= 8 && hora <= 12){
											strcpy(turno, "matutino");
										}
										if( hora >= 13 && hora <= 16){
											strcpy(turno, "vespertino");
										}
										if( hora >= 17 && hora <= 20){
											strcpy(turno, "nocturno");
										}
										for(i=0;i<cantidadReservaciones;i++)
										{
											if(strcmp(turno,reservaciones[i].turno)==0){
												if(reservaciones[i].vigente == 1){
													reservaciones[i].vigente = 0;
												}
											}                                                                                                         
										}
										printf("Reservaciones canceladas.\n\n");		
												
										break;		
		}//STICH 2
		}while(opcion!='s');
			break;
		case 'V':
			
			printf("vigencia de reservacion.");
			strcpy(telefono,"");
			strcpy(fecha,"");
			hora = 0;
			strcpy(turno,"");
			i = 0;
			banderaConsulta = 0; 
			printf("Consulta de reservacion. \n");
			printf("ingrese su numero de telefono:\n");
			gets(telefono);
			/* getchad(); */
			printf("ingrese la fecha de su reservacion (DD-MM-AAAA):\n");
			gets(fecha);
			/* getchad(); */
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
			printf("\n");
			if(cantidadReservaciones > 0){
				for( i = 0; i < cantidadReservaciones; i++){
					
					if(strcmp(telefono,reservaciones[i].telefono) == 0){
						if(strcmp(fecha, reservaciones[i].fecha) == 0){
							if(strcmp(turno,reservaciones[i].turno)==0){
								printf("La reservacion ha sido encontrada.\n");
								if(reservaciones[i].vigente == 1)
									printf("La reservación está vigente\n\n");
								else 
									printf("La reservación no está vigente\n\n");
								banderaConsulta = 1;
								break;
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
		
		
	//	default:
	//	 printf("OPCION NO VALIDA:\n");
	//	 break;
		}
		}while( opcion != 'S'&&opcion != 's');
		
		//aqui ya salio del menu
		
		printf("cantida de reservaciones %d",cantidadReservaciones);
				printf("salio del ciclo:\n");
	for( i = 0; i <= cantidadReservaciones; i++){
			printf("entro el for\n");									
			
						printf("La reservacion ha sido encontrada. Datos:\n");
						printf("Nombre: %s\n",reservaciones[i].nombre);
						printf("Telefono: %s\n",reservaciones[i].telefono);
						printf("Correo: %s\n",reservaciones[i].correo);
						printf("Fecha: %s\n",reservaciones[i].fecha);
						printf("Hora: %d\n",reservaciones[i].hora);
						banderaConsulta = 1;
						break;
       				}
							
				
		   
											

	return 0;
}
