#include<stdio.h>
#include<string.h>
struct reservas {
	char nombre[30];
	char telf[15];
	char email[30];
	int d,m,a;
	int  hora;
	int status;
	int turn;

}persona[20],*apuntador_i,*apuntador_k;

int main(){

	int i=0,last=0,k=0,band=0,x=0,horaglobal=0,diaglobal=0,mesglobal=0;
	int a=0,b=0,c=0,flag=0,y=0,z=0,turno=0,day,mon,year,hora;
	int contador=0;
	//reservas *apuntador_i,*apuntador_k;
	//char *apuntador_i2;
	char opc,numero[15];
	char nombre[30];
	apuntador_i=persona;
	//telf=persona;
	apuntador_k=persona;
	//apuntador_i2=&reservas
	char mail[30];
	//printf("%d\n",*apuntador_i);
//	printf("%d\n",*apuntador_k);
	do{

		printf("\n\n\n\t\t\t\tPROGRAMA QUE EMULA LAS RESERVACIONES DE UN RESTAURANTE USANDO REGISTROS\n\n");
		printf("\n\t<-------------------------------->\n");
		printf("\n\tA>Alta de reservacion\n");
		printf("\n\tB>Baja de reservacion\n");
		printf("\n\tC>Consulta de reservacion\n");
		printf("\n\tV>Vigencia de reservaciones\n");
		printf("\n\tR>Reservas totales\n");
		printf("\n\tS>Salir\n");
		printf("\n\t<-------------------------------->\n");
		printf("\n\tIngrese su opcion: ");

		opc=getchar();
		getchar();
		switch(opc)
			{
			case 'A':
			case 'a':


				  for(i=last;i<20;apuntador_i++)
					{
				      printf("\n\n");
				      printf("\n\t---Digite la fecha (DD-MM-AAAA)---");
				      printf("\n\tDia : ");
				      scanf("%d",&day);
							getchar();
							//*apuntador_i->d=day;
							apuntador_i->d=day;
				      printf("\tMes : ");
				      scanf("%d",&mon);
							getchar();
							//*apuntador_i->m=mon;
							apuntador_i->m=mon;
				      printf("\tA%co : ",164);
				      scanf("%d",&year);
							getchar();
							//*apuntador_i->a=year;
							apuntador_i->a=year;
					  printf("\n\tDigite la hora (formato 24 hrs): ");
				      scanf("%d",&hora);
							apuntador_i->hora=hora;
					  getchar();
						//printf("\n%d\n",apuntador_i->hora);
					  	if(apuntador_i->hora>=8&&apuntador_i->hora<=12){
							apuntador_i->turn=1;
							//printf("turno:%d\n",apuntador_i->turn);
						}
						else if(apuntador_i->hora>12&&apuntador_i->hora<=16){
							apuntador_i->turn=2;
							//printf("turno%d\n",apuntador_i->turn);
						}
						else{
							apuntador_i->turn=3;
							//printf("turno:%d\n",apuntador_i->turn);
						}
					  printf("\n\tDigite su telefono: ");
				      gets(numero);
							strcpy(apuntador_i->telf, numero);

							//printf("apuntador_i->telf:%s",apuntador_i->telf );
						//	gets();
			  	      flag=0;
					  		a=0;
					   		b=0;
					   		c=0;
						 		if(i!=0){

								 for(apuntador_k=persona;apuntador_k<apuntador_i;apuntador_k++){
								  if(apuntador_k->d==apuntador_i->d&&apuntador_k->m==apuntador_i->m)
									a=1;

								if(apuntador_i->turn==apuntador_k->turn)
									b=1;

								c=strcmp(apuntador_k->telf,apuntador_i->telf);
							  	}

							   if(a==1&&b==1&&c==0)
								  flag=1;
							   }

					    if(flag==0&&apuntador_i->status!=1)
							{
					       printf("\n\tDigite su nombre: ");
				      	   gets(nombre);
									 strcpy(apuntador_i->nombre,nombre);
				      	   printf("\n\tDigite su e-mail: ");
				      	   gets(mail);
				      	   apuntador_i->status=0;
									 strcpy(apuntador_i->email,mail);
				  		   //printf("\n\t A= %d ",a);
				  		  // printf("\n\t B= %d ",b);
				  		   //printf("\n\t C= %d ",c);
				  		   //printf("\n\t flag= %d ",flag);
						   //printf("\n\t turno= %d ",persona[i].turn);
						    //apuntador_i++;
			          		//last=apuntador_i;
			          		band=1;
										//printf("\nbandera :%d\n",band );
										//printf("\napuntador_i:%d\n",apuntador_i);
										//printf("\ni:%d\n",i);
										i++;
										last=i;
										apuntador_i++;
										//printf("\napuntador_i%d\n",apuntador_i);
										//printf("\ni:%d\n",i);
				      		break;

								}else
						    printf("\n\tEsta informacion ya esta asociada a una reservacion !!");
					  		printf("\n\t A= %d ",a);
				  			printf("\n\t B= %d ",b);
				  			printf("\n\t C= %d ",c);
				  			printf("\n\t flag= %d ",flag);
						    printf("\n\t turno= %d ",apuntador_i->turn);
			          break;
				      //getchar();
				      }
			break;
			case 'B':
			case 'b':
				 if(band==1){
						/*printf("\n\t<----------------------------------------------------------->");
					   printf("\n\tSi no conoce la informacion de la reservacion digite 0");
					   printf("\n\tPuede consultarlo en el apartado de:");
					   //printf("\n\n\t...C>Consulta de reservacion...");
					   printf("\n\n\t...R>Reservaciones totales...");
					   printf("\n\t<----------------------------------------------------------->");
					   printf("\n\n\tIngrese el numero de reservacion a dar de baja: ");
					   scanf("%d",&x);
					   getchar();*/
					   printf("\n\n");
				       printf("\n\t--Digite fecha de la reserva a dar de baja (DD-MM): ");
				       printf("\n\tDia : ");
				       scanf("%d",&diaglobal);
				       printf("\tMes : ");
				       scanf("%d",&mesglobal);
				       //printf("\tA%co : ",164);
				       //scanf("%d",&persona[i].a);
					   printf("\n\t--Digite hora de la reserva a dar de baja (formato 24 hrs): ");
				       scanf("%d",&horaglobal);
					   getchar();
					   printf("\n\t--Digite numero de telefono asociado a la reserva a dar de baja: ");
				      	gets(numero);
							y=0;
							k=0;
					   	apuntador_k=persona;
					   while(apuntador_k<apuntador_i){
					   			z=strcmp(apuntador_k->telf,numero);

								if( (apuntador_k->hora==horaglobal) && (apuntador_k->d==diaglobal) && (apuntador_k->m==mesglobal)&&z==0){

								   	apuntador_k->status=1;
								   	printf("\n\t---Reserva %d dada de baja---",k+1);
								   	//y=k;
									y=1;
									break;
								}else
									apuntador_k++;
									k++;
					   		}
					   		if(y!=1)
							   printf("\n\tNo hay reservas que coincidan con esta informacion");
				  }else
				      printf("\n\tAun no hay reservaciones!!!\n");

			break;
			case 'C':
			case 'c':
				if(band==1){

				       printf("\n\tIngrese la fecha de la reserva a consultar (DD-MM): ");
					   printf("\n\tDia : ");
				       scanf("%d",&diaglobal);
				       printf("\tMes : ");
				       scanf("%d",&mesglobal);
					   printf("\n\tDigite hora de la reserva a consultar (formato 24 hrs): ");
				       scanf("%d",&horaglobal);
				       getchar();
					   printf("\n\tIngrese el numero telefonico de la persona que reservo: ");
					   gets(numero);


								k=0;
								apuntador_k=persona;
					      while(apuntador_k<apuntador_i){
						    a=strcmp(numero,apuntador_k->telf);
						    if(a==0 && (apuntador_k->status==0) && (apuntador_k->hora==horaglobal) && (apuntador_k->d==diaglobal) && (apuntador_k->m==mesglobal)){

								printf("\n");
				        	    printf("\n\tReservacion: %d",k+1);
				        	    printf("\n\tTelefono : %s",apuntador_k->telf);
						        printf("\n\tHora : %d hrs.",apuntador_k->hora);
						        printf("\n\tNombre : %s",apuntador_k->nombre);
						        printf("\n\tFecha : %d-%d-%d",apuntador_k->d,apuntador_k->m,apuntador_k->a);
				        	    printf("\n\tE-mail : %s",apuntador_k->email);
						       	if(apuntador_k->hora<=12)
				           	    	printf("\n\tTurno Matutino");
				        	    else if(apuntador_k->hora<=16)
					   	            printf("\n\tTurno Vespertino");
				         	    else
						           printf("\n\tTurno Nocturno");
				        	    printf("\n\n");

							break;
							getchar();

						    }else
								printf("\n\tLos datos no coinciden con ninguna reserva!!");
								//if(persona[k].status==1&&a==0)
									//printf("\n\tEstado <Baja> ");

							if(apuntador_k<apuntador_i)
								apuntador_k++;

								k++;
						}

				}else
				     printf("\n\tAun no hay reservaciones!!!\n");

			break;

			case 'V':
			case 'v':
				if(band==1){
					    printf("\n\tIngrese la hora actual(formato 24 hrs): ");
					    scanf("%d",&horaglobal);
					    printf("\n\tIngrese numero de dia actual: ");
						scanf("%d",&diaglobal);
						printf("\n\tIngrese numero de mes actual: ");
						scanf("%d",&mesglobal);
						getchar();

						if(horaglobal>=8&&horaglobal<=12)
							turno=1;
						else if(horaglobal>12&&horaglobal<=16)
							turno=2;
						else
							turno=3;
						for(apuntador_k=persona;apuntador_k<apuntador_i;apuntador_k++){
							if(apuntador_k->turn<turno&&apuntador_k->d<=diaglobal&&apuntador_k->m<=mesglobal)
						   		apuntador_k->status=1;

							/*else if(persona[k].turn<turno&&persona[k].d<=diaglobal&&persona[k].m<=mesglobal)
								persona[k].status=1;*/
							}
				  		printf("\n\tReservas actualizadas, conforme al turno y fecha actual");

				  }else
				      printf("\n\tAun no hay reservaciones!!!\n");

			break;
			case 'R':
			case 'r':
				if(band==1){
				    printf("\n\n\tEstas son las reservas actuales:");
						k=0;
				    for(apuntador_k=persona;apuntador_k<apuntador_i;apuntador_k++){
				       if(apuntador_k->status==0){
							printf("\n");
				        	printf("\n\tReservacion: %d",k+1);
				        	printf("\n\tNombre : %s",apuntador_k->nombre);
				        	printf("\n\tTelefono : %s",apuntador_k->telf);
							printf("\n\tE-mail : %s",apuntador_k->email);
				       	 	printf("\n\tFecha : %d-%d-%d",apuntador_k->d,apuntador_k->m,apuntador_k->a);
				        	printf("\n\tHora : %d hrs.",apuntador_k->hora);
				        	//printf("\n\tstatus : %d",persona[k].status);
				        	if(apuntador_k->hora<=12)
				            	printf("\n\tTurno Matutino");
				        	else if(apuntador_k->hora<=16)
					   	    	printf("\n\tTurno Vespertino");
				         	else
						    	printf("\n\tTurno Nocturno");
				        	printf("\n\n");
					       }else{
						     printf("\n\n\tReserva: %d",k+1);
						     printf("\n\tDada de Baja");
						     printf("\n\n");
						     }
								 k++;
					      }

				}else
				     printf("\n\tAun no hay reservaciones!!!\n");
			break;


			case 'S':
			case 's':
				printf("\n\tHasta Pronto.\n\n\n");
			break;

			default:
				printf("\n\tOpcion invalida!!\n");
			break;
			}
	  }while(opc!='S'&&opc!='s');

return 0;
}
