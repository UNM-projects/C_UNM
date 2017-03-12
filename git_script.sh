#Author:	Lucas Gimenez
#Date:		11/03/2017
#Version:	v1.0

#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.

#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.

#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.


#! /bin/bash

########################################################################################################################
#Script para poder subir de forma automática archivos a un repositorio remoto en GitHub utilizando los comandos de Git.#
########################################################################################################################


#Lo primero es ingresar la ruta donde se encuentran los archivos que vamos a seguir con Git, y que luego serán cargados en nuestro repositorio remoto.

tput setaf 12
echo ""
echo "**********************************************************************************************************************************************"
echo -e  "\n \t INGRESE LA RUTA DONDE SE ENCUENTRAN LOS ARCHIVOS QUE SERÁN SUBIDOS AL REPOSITORIO REMOTO (ejemplo: /home/lucas/repo/LPC1769_UNM):\n"
echo "**********************************************************************************************************************************************"
tput sgr0

read ruta 

cd $ruta

#Iniciamos o re-inicializamos git.

git init

#Vemos el estado de nuestro repositorio local, en este preciso momento.

tput setaf 12
echo ""
echo "********************************"
echo -e "\n \t ESTADO DEL WORKSPACE \n"
echo "********************************"
tput sgr0

git status

#Agregamos los archivos modificados, de nuestro espacio de trabajo, que están listos para confirmar.

git add -A

#Volvemos a ver el estado de nuestro repo local. En este punto deberíamos ver en "verde" lo que anteriormente estaba en "rojo".

tput setaf 12
echo ""
echo "********************************"
echo -e "\n \t ESTADO DEL WORKSPACE \n"
echo "********************************"
tput sgr0

git status

#Confirmamos los archivos, enviando un mensaje de commit al repositorio.

git commit -m "Uploaded with the script"

#Creamos una variable donde guardaremos la 'url' del repositorio remoto que ingrese el usuario por stdin(teclado).

tput setaf 12
echo ""
echo "***************************************************"
echo -e "\n \t INGRESE LA 'URL' DEL REPOSITORIO REMOTO:\n" 
echo "***************************************************"
tput sgr0

read url

#Nos conectamos (linkeamos) al repositorio remoto ingresado, donde vamos a subir nuestros archivos.
git remote remove origin
git remote add origin $url

#Para actualizar nuestro repositorio local, respecto al remoto, se ejecutan las siguientes líneas para evitar errores a la hora de subir los archivos.

git fetch origin
git merge remotes/origin/master -m "Merge branchs"

#Vemos por pantalla si la conexión fue satisfactoria.

tput setaf 12
echo ""
echo "***************************************************************************"
echo -e "\n \t REPOSITORIO LOCAL LINKEADO CON EL SIGUIENTE REPOSITORIO REMOTO \n"
echo "******** ******************************************************************"
tput sgr0

git remote -v

#Si todo está en orden, procedemos a subir los archivos.

tput setaf 12
echo ""
echo "****************************************************************************"
echo -e "\n \t SUBIENDO ARCHIVOS AL REPOSITORIO REMOTO \n" #Mostramos por pantalla que la carga de los archivos se inició.
echo "****************************************************************************"
tput sgr0

tput setaf 12
echo ""
echo "****************************************************************************"
echo -e "\n \t INGRESAR USUARIO Y CONTRASEÑA DE TU CUENTA DE GitHub \n" #Necesario para Git.
echo "****************************************************************************"
tput sgr0

git push origin master

tput setaf 12
echo ""
echo "****************************************************************************"
echo -e "\n \t CARGA TERMINADA \n" #Mostramos por pantalla que la carga de los archivos finalizó.
echo "****************************************************************************"
tput sgr0

