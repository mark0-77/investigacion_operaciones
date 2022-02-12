#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

float mini_ratio,min_cj_zj,min_ratio[10],max_cj_zj;
float pre_res,key_element,dv[10],res[10],cb[10];
int slack[10],art[5],k,flag,i,j,key_col,key_row,tot_dv,tot_cons,var_num;
char cas[5],sym[10],ch[5],var[10][3],number[5],bv[10][3];
float cons[10][10],zj[10],cj_zj[10],sum,key_rows[10],fixed_element;

void erase_screen();
void end();
void display();
void iteration_fun();
void display_final_result();

int main()
{
   char resp='n';

   	flag=0;
 		int driver=DETECT,mode;
		initgraph(&driver,&mode,"bgi");

		clrscr();
		cleardevice();
 		int x,y;
   	int col=0;

   	for(int i=0;i<200;++i)
   	{
   		putpixel(random(640),random(480),col);
      	++col;
      	if(col==15)
      	{
      		col=0;
      	}
   	}
		settextstyle(1, 0, 12);
		setcolor(LIGHTGREEN);
		outtextxy(110,20,"METODO");
		settextstyle(1, 0, 12);
		setcolor(YELLOW);
		outtextxy(80,160,"SIMPLEX");
		settextstyle(1, 0, 5);
		setcolor(RED);
		outtextxy(150,320,"Hecho por : mARkO ");
   	settextstyle(4, 0, 5);
		setcolor(CYAN);
		outtextxy(270,400,"6301");
		getch();
     do
     {
		clrscr();
		cleardevice();
  		col=0;

   	for(i=0;i<200;++i)
   	{
      	putpixel(random(640),random(480),col);
      	++col;
      	if(col==15){col=0;}
   	}
   	gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
   	gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
  		gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");

   	printf("\n\n Escriba el Caso (MAX/MIN): ");
		fflush(stdin);
		scanf("%s",&cas);
		strupr(cas);
		printf("\n Introduzca el numero de Variables: ");
		scanf("%d",&tot_dv);
		printf("\n Introduzca los coeficientes de la Funcion Objetivo (Z): ");

   	for(j=0;j<tot_dv;++j)
   	{
   		printf("\n\t X%d= ",j+1);
      	scanf("%f",&dv[j]);
   	}
   	clrscr();
   	cleardevice();

   	for(i=0;i<200;++i)
   	{
      	putpixel(random(640),random(480),col);
      	++col;
      	if(col==15){col=0;}
   	}
		printf("\n\n Introduzca el numero de Restricciones: ");
		scanf("%d",&tot_cons);
		printf("\n");

		for(i=0;i<tot_cons;++i)
   	{
			for(j=0;j<tot_dv;++j)
			{
				printf(" Restriccion %d (X%d): ",i+1,j+1);
				scanf("%f",&cons[i][j]);
			}
			printf(" Digite el simbolo ( >,=,< ): ");
			fflush(stdin);
			scanf("%s",&sym[i]);
			printf(" Igualdad %d: ",i+1);
			scanf("%f",&res[i]);
			printf("\n\n");
		}
		clrscr();
		cleardevice();

   	for(i=0;i<200;++i)
	   {
   	   putpixel(random(640),random(480),col);
      	++col;
      	if(col==15){col=0;}
	   }

		for(i=0;i<tot_dv;++i)
		{
			strcpy(var[i],"X");
			itoa(i+1,number,10);
			strcat(var[i],number);
		}
   	gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
   	gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
  		gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");
   	printf("\n\n El problema de P.L es: \n");
		display();

		for(i=0;i<tot_cons;++i)
		{
			if(res[i]<0)
			{
				flag=1;
				res[i]*=-1;
				if(sym[i]=='>')
					sym[i]='<';
				else
					sym[i]='>';

				for(j=0;j<tot_dv;++j)
				{
					cons[i][j]*=-1;
				}
	      }
		}
		if(flag==1)
		{
			printf("\n\n Ahora el Problema de P.L es: \n");
			display();
		}
   	k=tot_dv;
		var_num=1;

   	for(i=0;i<tot_cons;++i)
		{
			if(sym[i]=='>')
			{
				cons[i][k]=-1;
				dv[k]=0;
				strcpy(var[k],"S");
				itoa(i+1,number,10);
				strcat(var[k],number);
	         ++k;
	         		cons[i][k]=1;
				if(strcmp(cas,"MAX")==0)
					cb[i]=dv[k]=-100000;
				else
					cb[i]=dv[k]=100000;
				sym[i]='=';
   	      strcpy(var[k],"A");
				itoa(var_num,number,10);
				strcat(var[k],number);
				strcpy(bv[i],var[k]);
				++var_num;
			}
			else if(sym[i]=='<')
			{
				cons[i][k]=1;
				cb[i]=dv[k]=0;
				sym[i]='=';
			   strcpy(var[k],"S");
			   itoa(i+1,number,10);
			   strcat(var[k],number);
			   strcpy(bv[i],var[k]);
			}
			else
			{
				cons[i][k]=1;
				if(strcmp(cas,"MAX")==0)
					cb[i]=dv[k]=-100000;
				else
					cb[i]=dv[k]=100000;
				strcpy(var[k],"A");
				itoa(var_num,number,10);
				strcat(var[k],number);
				strcpy(bv[i],var[k]);
				++var_num;
			}
			++k;
	   }
   	printf("\n\n La Forma Estandar del problema de P.L es: \n");
		printf("\t %s Z= ",cas);

   	for(i=0;i<k;++i)
		{
			if(i!=0)
				printf("+ %g%s ",dv[i],var[i]);
			else
				printf(" %g%s ",dv[i],var[i]);
		}
   	printf("\n\n Sujeto a: ");

		for(i=0;i<tot_cons;++i)
		{
			printf("\n\t");

			for(j=0;j<k;++j)
         {
				if(cons[i][j]!=0)
				{
					if(j!=0)
						printf("+ %g%s ",cons[i][j],var[j]);
					else
						printf(" %g%s ",cons[i][j],var[j]);
				}
   	   }
			printf("%c",sym[i]);
			printf(" %g",res[i]);
	   }
		printf("\n\t");

   	for(j=0;j<k;++j)
		{
			printf(" %s ",var[j]);
		}
		printf(" > 0");
   	printf("\n\n\n\t\t Presione cualquier tecla para continuar . . .");
		getch();
		clrscr();
		cleardevice();
		label:
      	for(i=0;i<200;++i)
	   	{
   	   	putpixel(random(640),random(480),col);
      		++col;
      		if(col==15){col=0;}
	   	}
   	   gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
   		gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
  			gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");
      	printf("\n\n");
			printf("----------------------------------------------------------------------------");
			printf("\t\t Cj \t");

   	for(i=0;i<k;++i)
			printf(" %g \t",dv[i]);
   	printf("\n----------------------------------------------------------------------------\n");
   	printf("\n Cb \t Bv \t Sv ");

      	for(i=0;i<k;++i)
				printf("\t %s ",var[i]);
      	printf("\n----------------------------------------------------------------------------\n");

      	for(i=0;i<tot_cons;++i)
			{
				printf(" %g \t",cb[i]);
				printf(" %s \t",bv[i]);
				printf(" %g \t",res[i]);

				for(j=0;j<k;++j)
				{
					printf(" %g \t",cons[i][j]);
				}
         	printf("\n");
			}
   	   printf("\n----------------------------------------------------------------------------\n");
			printf("    Zj = \t\t");

			for(j=0;j<k;++j)
			{
				sum=0;

				for(i=0;i<tot_cons;++i)
				{
					sum=sum+(cb[i]*cons[i][j]);
				}
				zj[j]=sum;
				printf(" %g \t",zj[j]);
         	cj_zj[j]=dv[j]-zj[j];
			}
   	   printf("\n----------------------------------------------------------------------------\n");
			printf(" Cj - Zj = \t\t");
      	key_col=0;
			if(strcmp(cas,"MAX")==0)
			{
				max_cj_zj=cj_zj[0];

				for(i=0;i<k;++i)
				{
					printf(" %g \t",cj_zj[i]);
					if(max_cj_zj<=cj_zj[i+1])
					{
						max_cj_zj=cj_zj[i+1];
						key_col=i+1;
					}
				}
				if(max_cj_zj>0)
				{
					iteration_fun();
					goto label;
				}
				else
				{
	   			display_final_result();
				}
			}
			else
			{
				min_cj_zj=cj_zj[0];

				for(i=0;i<k;++i)
				{
					printf(" %g \t",cj_zj[i]);
					if(min_cj_zj>=cj_zj[i+1])
					{
						min_cj_zj=cj_zj[i+1];
						key_col=i+1;
					}
				}
				if(min_cj_zj<0)
				{
					iteration_fun();
					goto label;
				}
				else
				{
					display_final_result();
				}
      	}
         clrscr();
         cleardevice();

         for(i=0;i<200;++i)
         {
   	  		putpixel(random(640),random(480),col);
      		++col;
      		if(col==15){col=0;}
 	 	 	}
         gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
   		gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
  			gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");
         printf("\n\n\n\t\t Desea realizar otro calculo (S/N) ? ");
         scanf("%s",&resp);
      }
	while(resp=='S' || resp=='s');
   clrscr();
	end();
	erase_screen();
}
//------------------------- F U N C I O N E S --------------------------------//
void display_final_result()
{
   int i,col;

	printf("\n\n\n\t\t ! ! ! Solucion Terminada ! ! !");
	printf("\n\n\n\t\t\t Presione una tecla para ver el Resultado Final . . .\n");
	getch();
   clrscr();
   cleardevice();

   for(i=0;i<200;++i)
  	{
   	putpixel(random(640),random(480),col);
   	++col;
      if(col==15){col=0;}
   }
   gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
  	gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
	gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");
   printf("\n\t\t ----------------------------\n");
	printf("\n\t\t Cb\tBv\tSv\n");
	printf("\n\t\t ----------------------------\n\t\t");

	for(i=0;i<tot_cons;i++)
	{
		printf(" %g \t",cb[i]);
		printf(" %s \t",bv[i]);
		printf(" %g \t",res[i]);
		printf("\n\t\t");
	}
	printf("\n\t\t ----------------------------\n");
//Calculate & print the value of Zj
	printf("\t\t    Z = \t");
	sum=0;

	for(i=0;i<tot_cons;i++)
		sum+=(cb[i]*res[i]);
	printf(" %g \t",sum);
	getch();
}

void display()
{
printf("\t %s Z= ",cas);

for(i=0;i<tot_dv;++i)
{
	if(i!=0)
		printf("+ %g%s ",dv[i],var[i]);
	else
		printf(" %g%s ",dv[i],var[i]);
}
printf("\n\n Sujeto a: ");

for(i=0;i<tot_cons;++i)
{
		printf("\n\t");

		for(j=0;j<tot_dv;++j)
		{
			if(cons[i][j]!=0)
			{
				if(j!=0)
					printf("+ %g%s ",cons[i][j],var[j]);
				else
					printf(" %g%s ",cons[i][j],var[j]);
			}
      }
		printf("%c",sym[i]);
		printf(" %g",res[i]);
}
printf("\n\t");

for(j=0;j<tot_dv;++j)
{
	printf(" %s ",var[j]);
}
printf(" > 0");
}

void iteration_fun()
{
   int col;

	printf("\n\n La Solucion NO es optima. Tenemos que optimizar");
	printf("\n\n\n\t\t Prsione una tecla para continuar . . .");
	getch();
   clrscr();
   cleardevice();

   for(i=0;i<200;++i)
   {
      	putpixel(random(640),random(480),col);
      	++col;
      	if(col==15){col=0;}
   }
   gotoxy(17,1);printf("ษอออออออออออออออออออออออออออออออออออออป");
   gotoxy(17,2);printf("บ            METODO SIMPLEX           บ");
   gotoxy(17,3);printf("ศอออออออออออออออออออออออออออออออออออออผ");
	mini_ratio = 40000;
	printf("\n\n -------------------------------------------------");
	printf("\n\n Radio Minimo");
	printf("\n\n -------------------------------------------------\n");

	for(i=0;i<tot_cons;++i)
	{
		if(cons[i][key_col]<=0)
		{
			min_ratio[i]=40000;
			printf("\n\n No se puede divir entre cero, por lo tanto el radio es: ");
		}
		else
		{
			min_ratio[i]=res[i]/cons[i][key_col];
		}
		printf(" %g \n",min_ratio[i]);
		if(mini_ratio>min_ratio[i])
		{
			mini_ratio=min_ratio[i];
			key_row=i;
		 }
	}
   printf("\n\n-------------------------------------------------------------\n\n");
	printf("\t Columna Clave: %s",var[key_col]);
	printf("\n\t Fila Clave: %s",bv[key_row]);
	key_element=cons[key_row][key_col];
	printf("\n\t Elemento Clave: %g",key_element);
   printf("\n\t Variable Entera: %s",var[key_col]);
	printf("\n\t Variable Holgura: %s",bv[key_row]);
	strcpy(bv[key_row],var[key_col]);
   pre_res=res[key_row];

	for(i=0;i<k;++i)
		key_rows[i]=cons[key_row][i];
   cb[key_row]=dv[key_col];
	res[key_row]/=key_element;

	for(i=0;i<k;++i)
	{
		if(cons[key_row][i]!=0)
			cons[key_row][i]/=key_element;
	}

	for(i=0;i<tot_cons;++i)
	{
      if(i!=key_row)
		{
         fixed_element=cons[i][key_col]/key_element;
			res[i]-=(pre_res * fixed_element);

			for(j=0;j<k;++j)
			{
				cons[i][j]=cons[i][j]-(key_rows[j]*fixed_element);
			}
		}
	}
   printf("\n\n\n\t\t Presione una tecla para continuar . . .");
	getch();
   clrscr();
   cleardevice();
}

void end()
   {
     cleardevice();
     int x,y;
     int col=0;

     for(int i=0;i<200;++i)
     {
         putpixel(random(640),random(480),col);
      	++col;
      	if(col==15){col=0;}
     }
     gotoxy(4,6);printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
     gotoxy(4,7);printf("บ                                                                         บ");
     gotoxy(4,8);printf("บ                            METODO SIMPLEX                               บ");
     gotoxy(4,9);printf("บ                                            v 1.0                        บ");
     gotoxy(4,10);printf("บ                                                                         บ");
     gotoxy(4,11);printf("บ                    Programado por :                                     บ");
     gotoxy(4,12);printf("บ                              Marco Antonio Zamudio Martinez             บ");
     gotoxy(4,13);printf("บ                                                                         บ");
     gotoxy(4,14);printf("บ                    E-mail :                                             บ");
     gotoxy(4,15);printf("บ                            < dark_count @ hotmail.com >                 บ");
     gotoxy(4,16);printf("บ                                                                         บ");
  	  gotoxy( 4,17);printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	  printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  Presione una tecla para Salir . . . " );
     getch();
   }
void erase_screen()
{
 int x1=0,y1=0,x2=639,y2=479;
 setcolor(0);
  for(;x1<x2;)
  {
  delay(10);
  rectangle(x1,y1,x2,y2);
  x1++;y1++;x2--;y2--;
  }
  cleardevice();
}
