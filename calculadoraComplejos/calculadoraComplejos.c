/*
#Autor Pablo Toledo
#fecha junio 2014


#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#
#

Calculadora de Números Complejos en su forma binómica 
suma,resta,producto y división
Versión para SO Linux, en caso de utilizar windows se deben modificar ciertos parametros indicados
*/




#include <stdio.h>
#include <stdlib.h>

struct leer //ESTRUCTURA QUE ALMACENA LOS DATOS INGRESADOS POR TECLADO
{
float a;
float b;
float c;
float d;
};

struct mostrar // ESTRUCTURA QUE ALMACENA LOS RESULTADOS
{
 float real;
 float imag;
};

struct mostrar2 // ESTRUCTURA QUE ALMACENA LOS RESULTADOS DE LA DIVISION
{
 float real;
 float imag;
 float deno;
};

//DECLARACIÓN DE PROTOTIPOS DE FUNCIONES
struct leer leer_datos(void);
void mostrar_datos(struct leer, struct mostrar,char);
void mostrar_datos2(struct leer, struct mostrar2);
void menu (void);
struct mostrar suma(struct leer);
struct mostrar resta(struct leer);
struct mostrar producto(struct leer);
struct mostrar2 division(struct leer);

//FUNCIÓN MAIN
int main (void)
{
 char opcion,op;
 int i;
 char opcion_menu,o='0';
 struct leer R;
 struct mostrar M;
 struct mostrar2 M2;
 
system ("clear"); // en el caso de utilizar Windows el parámetro es "cls"
for(i=1;i<=40;i++)
  printf("@");
printf("\n");
 printf("            BIENVENIDO\n");
 printf("Este programa opera con numeros complejos\n");
 printf("PULSE >>>'I' para ingresar al menu) \n");
 printf("PULSE >>>'S' (para SALIR)\n");
for(i=1;i<=40;i++)
 printf("@");
printf("\n");
printf("Opcion:\t");
 scanf("%c",&opcion);
 while(opcion != 's')
 {
  menu();
  getchar();
  scanf("%c",&op);
 switch(op)
 { 


			//Suma 
  case '1':system("clear"); // en el caso de utilizar Windows el parámetro es "cls"
           o='1';                                           
           printf("Pulse 'c' para continuar\n");
           getchar();
           scanf("%c",&opcion_menu);
           while (opcion_menu != 'n')
           {
            printf("*****SUMA DE COMPLEJOS*****\n");                   
            R = leer_datos();//Lectura de datos
            M =suma(R);
            mostrar_datos(R,M,o);
            printf("Desea sumar otros numeros complejos? S/N\t");
            getchar();
            scanf("%c",&opcion_menu);
            }
           break;

			//resta
  case '2': system("clear"); // en el caso de utilizar Windows el parámetro es "cls"
            o='2';                                          
           printf("Pulse 'c' para continuar\n");
           getchar();
           scanf("%c",&opcion_menu);
           while (opcion_menu != 'n')
           {
            printf("*****RESTA DE COMPLEJOS*****\n");
            R = leer_datos();//Lectura de datos
            M = resta(R);
            mostrar_datos(R,M,o);
            printf("Desea restar otros numeros complejos? S/N\t");
            getchar();
            scanf("%c",&opcion_menu);
            }
           break;

				// producto
  case '3': system("clear");// en el caso de utilizar Windows el parámetro es "cls"
            o='3';					        
           printf("Pulse 'c' para continuar\n");
           getchar();
           scanf("%c",&opcion_menu);
           while (opcion_menu != 'n')
           {
            printf("*****PRODUCTO DE COMPLEJOS*****\n");
            R = leer_datos();//Lectura de datos
            M = producto(R);
            mostrar_datos(R,M,o);
            printf("Desea multiplicar otros numeros complejos? S/N\t");
            getchar();
            scanf("%c",&opcion_menu);
            }
           break;

				// division
  case '4': system("clear");// en el caso de utilizar Windows el parámetro es "cls"				        
           printf("Pulse 'c' para continuar\n");
           getchar();
           scanf("%c",&opcion_menu);
           while (opcion_menu != 'n')
           {
            printf("*****DIVISION DE COMPLEJOS*****\n");
            R = leer_datos();//Lectura de datos
            M2 = division(R);
            mostrar_datos2(R,M2);
            printf("Desea dividir otros numeros complejos? S/N\t");
            getchar();
            scanf("%c",&opcion_menu);
            }
           break;
  case '0': break;
  }
 system("clear");
 printf("          ATENCION!!!\n");
 printf("Pulse 'v' (para volver al menu)\n");
 printf("PULSE 's' ( Para SALIR)\n");
 getchar();
 scanf("%c",&opcion);
 }
 return 0;
}
//****** FUNCIÓN QUE MUESTRA EL MENU********

void menu(void)
{
 system("clear"); // en el caso de utilizar Windows el parámetro es "cls"
 printf("             *****MENU*****\n");
 printf("                 1- SUMA\n");
 printf("                 2- RESTA\n");
 printf("                 3- PRODUCTO\n");
 printf("                 4- DIVISION\n");
 printf("                 0- SALIR\n");
 printf("Opcion:");
}
//****** FUNCIÓN QUE SUMA NÚMEROS COMPLEJOS********

struct mostrar suma (struct leer R)
{
 struct mostrar M;
   //operacion
   M.real= R.a + R.c;
   M.imag= R.b + R.d;
   return(M);
}

//****** FUNCIÓN QUE RESTA NÚMEROS COMPLEJOS********

struct mostrar resta (struct leer R)
{
 struct mostrar M;
   //operacion
   M.real= R.a - R.c;
   M.imag= R.b - R.d;
   return(M);
}

//****** FUNCIÓN QUE MULTIPLICA NÚMEROS COMPLEJOS********
struct mostrar producto (struct leer R)
{
 float R1,R2,I1,I2;
 struct mostrar M;
   //operacion
   R1= (R.a * R.c);
   I1= (R.a * R.d);
   I2= (R.b * R.c);
   R2= (R.b * R.d)* -1;
   M.real= R1 + R2;
   M.imag= I1 + I2;
  return (M);
}
//****** FUNCIÓN QUE DIVIDE NÚMEROS COMPLEJOS********
struct mostrar2 division (struct leer R)
{
 float R1,R2,I1,I2,deno;
 struct mostrar2 M;
   //operacion
   R1= (R.a * R.c);
   I1= (R.a * (R.d * -1));
   I2= (R.b * R.c);
   R2= (R.b * (R.d * -1))* -1;
   deno= (R.c * R.c) + (R.d * R.d);

   M.real= R1 + R2;
   M.imag= I1 + I2;
   M.deno= deno;
   return (M);
}

//*****FUNCION QUE LEE LOS DATOS DEL TECLADO Y LOS ALMACENA EN UNA ESTRUCTURA*****

struct leer leer_datos(void)
{
struct leer datos;
float a,b,c,d;
//1° N°
   printf("1er Numero\n");
   printf("ingrese la parte real del Nro\t");
   scanf("%f",&a);
   datos.a= a;
   printf("ingrese la parte imaginaria del Nro\t");
   scanf("%f",&b);
   datos.b= b;
   //2° N°
   printf("2do Numero\n");
   printf("ingrese la parte real del Nro\t");
   scanf("%f",&c);
   datos.c= c;
   printf("ingrese la parte imaginaria del Nro\t");
   scanf("%f",&d);
   datos.d= d;
return (datos);
}

 //***** FUNCION QUE MUESTRA LOS DATOS********

void mostrar_datos( struct leer R, struct mostrar M, char o)
{
 printf("RESULTADO\n"); //muestra los datos según la operacion que se realize
   switch(o)
  {
   case'1':
      printf("(%.0f + %.0f i) + (%.0f + %.0f i) = (%.0f + %.0f i)\n",R.a,R.b,R.c,R.d,M.real,M.imag);break;
   case'2':
      printf("(%.0f + %.0f i) - (%.0f + %.0f i) = (%.0f + %.0f i)\n",R.a,R.b,R.c,R.d,M.real,M.imag);break;
   case'3':
      printf("(%.0f + %.0f i) X (%.0f + %.0f i) = (%.0f + %.0f i)\n",R.a,R.b,R.c,R.d,M.real,M.imag);break;
   printf("\n\n");
  }
}

//***** FUNCION QUE MUESTRA LOS DATOS DE LA DIVISION********

void mostrar_datos2( struct leer R, struct mostrar2 M)
{
 printf("RESULTADO\n");
   printf("(%.0f + %.0f i) / (%.0f + %.0f i) = (%.0f/%.0f + %.0f/%.0f i)\n",R.a,R.b,R.c,R.d,M.real,M.deno,M.imag,M.deno);
   printf("\n\n");
}
