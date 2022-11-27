/*	Autor: Paula Martins de Sousa		Fecha de creación: 27/11/2022 */

/*
**	ENUNCIADO DEL PROGRAMA
**	Se desea crear un programa en C que pueda almacenar nombre completo de 10
alumnos.
Definiremos:
MAXALUMNOS 10 y MAXCADENA 20
El array de cadenas se llamará vNombreCompleto[MAXALUMNOS][MAXCADENA]
El programa tendrá las opciones que se ven continuación, mostrando un menú a través
d’un procedimiento llamado: “pintaMenu”. El valor que escoja el usuario, debe estar
controlado entre 0 y 3 con la función: pideNumEntreRango
 1.Insertar un alumno: Esta opción va a añadir al final del array, el nombre
completo de un alumno. Entendemos que un alumno está en un array si
coinciden la cadena completa. No hace falta controlar si hay 2 nombres iguales.
El nombre del procedimiento será: “nuevoAlumno”
 2.Listar alumnos: Esta opción mostrará un listado con todos los nombres del
array de cadenas. En caso de que no haya ninguno, debe indicar que no hay
alumnos en el array de cadenas. El nombre del procedimiento se debe llamar:
listarAlumnos.
 3.Modificar nombre de un alumno (*opcional): Se mostrarán todos los alumnos
que hay introducidos y se pedirá el nombre completo de un alumno que se
quiera modificar. En caso de que exista, se sobrescribirá al mencionado. En
caso contrario, se debe mostrar un mensaje: El alumno no está dentro de la
base de datos. Si hay alumnos con el mismo nombre, se modificará el primero
que se encuentre. El nombre del procedimiento será: modificarAlumno.
 0.Salir: El programa finalizará.
*Opcional: Si se realiza este apartado, se suman 0,5 puntos directamente a la nota de
la actividad.

**
*/

#include <stdio.h>
#define MAXALUMNOS 10
#define MAXCADENA 20
void pintaMenu();
int pideNumEntreRango(int, int, int *);
void nuevoAlumno(char[MAXALUMNOS][MAXCADENA], int *);
// void listarAlumnos(char[][], int *);

int main()
{
	int num;
	char vNombreCompleto[MAXALUMNOS][MAXCADENA];
	int numE = 0;

	// do
	// {

		printf("BIENVENIDOS AL PROGRAMA GESTION NOMBRE ALUMNOS:\n");

		pintaMenu();
		int option = pideNumEntreRango(0, 3, &num);
		
		

		switch (option)
		{
		case 1:
			nuevoAlumno(vNombreCompleto, &numE);
			break;
			// case 2:
			// 	void listarAlumnos(vNombreCompleto, &numE);
			// 	break;
			// case 3:
			// 	void listarAlumnos(vNombreCompleto, &numE);
			// 	modificarAlumno(vNombreCompleto, numE);
			// }
			if (option != 0)
			{
				getch();
				system("cls");
			}
		}

	// } while (option != 0);
	// {
	// 	system("cls");
	// 	printf("Has salido del programa.\n");
	// 	system("pause");
	// }
	// 

	getch();
	return 0;
}

void pintaMenu()
{
	printf("\n0.Salir.\n1.Insertar un alumno.\n2.Listar alumnos.\n3.Modificar nombre de un alumno.\n");
}
int pideNumEntreRango(int min, int max, int *num)
{

	do
	{
		printf("\nSeleccione una opcion (0-3): \n");
		scanf("%d", &*num);
	} while (*num < min || *num > max);

	return *num;
}
void nuevoAlumno(char v[MAXALUMNOS][MAXCADENA], int *numE)
{

	for (int i = 0; i < 10; i++)
	{
		printf("Introduce el nombre de un alumno: ");
		fflush(stdin);
		fgets(v[i], MAXCADENA, stdin);
		*numE++;
	}
}
void listarAlumnos(char vNombreCompleto[MAXALUMNOS][MAXCADENA], int *numE)
{
	for (int i = 0; i <= *numE; i++)
	{
		if (*numE == 0)
		{
			printf("\nNo hay alumnos en la lista.");
		}
		else
		{
			printf("%d. %s\n", i, vNombreCompleto[i], MAXCADENA, stdin);
		}
	}
}
