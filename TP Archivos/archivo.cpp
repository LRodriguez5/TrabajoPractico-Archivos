#include <iostream> // Librería estándar de c++ (permite usar cout y cin, entre otros)
#include <fstream> // Librería para manejar flujos de entrada y salida de datos hacia/desde archivos. (ifstream, ofstream, etc)
#include <locale.h> // Librería para los acentos y carácteres especiales
#include <string> // Permite manipular cadenas de texto.
#include <windows.h> // Librería para colores, borrar pantalla, pausar la consola, etc.
#include "logo.h" // Libreria propia (se incluye con comillas)
#include <conio.h> // Librería para getch()
#include <cctype> // Permite pasar caracteres a mayúscula
#include <stdlib.h> // Gestión de memoria dinamica, funcion "cls" y determinar el tamaño de la consola al iniciar
#define color SetConsoleTextAttribute // Macro para cambiar de color la consola sin escribir SetConsoleTextAttribute

using namespace std;

struct Contacto {
    int id;
    string nombre;
    string apellido;
    string telefono;
};

//Prototipos de función
void linea();
int generarID();
void agregarContacto(const Contacto& contacto);
void mostrarContactos();
void modificarContacto(int idBuscado);
void eliminarContacto(int idBuscado);
void vaciarContactos();

int main() {
    int opcion;
    char op, op_mayus;
    system("mode con: cols=115 lines=30"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 125 COLUMNAS Y 30 FILAS
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); // Permite cambiar el color de la consola
    setlocale(LC_ALL,"spanish"); // Establece el idioma de la consola a español permitiendo mostrar carácteres como acentos, ñ, etc.
    do {
    	system("cls");
    	color(hConsole, 5); // Púrpura
        logoAgenda(); //Membrete de mi librería
        color(hConsole, 6); // Dorado
        cout << "\n\n\t\t\t\t\t    1. Agregar contacto" << endl;
        cout << "\t\t\t\t\t    2. Modificar teléfono de contacto" << endl;
        cout << "\t\t\t\t\t    3. Eliminar contacto" << endl;
        cout << "\t\t\t\t\t    4. Mostrar contactos" << endl;
        cout << "\t\t\t\t\t    5. Vaciar lista de contactos" << endl;
        cout << "\t\t\t\t\t    6. Salir\n" << endl;
        color(hConsole, 15); // Blanco brillante
        cout << "\t\t\t\t\t    == Seleccione una opcion: ";
        color(hConsole, 7); // Reset color
        cin >> opcion;
		system("cls");
        switch (opcion) {
            case 1: {
                Contacto nuevoContacto;
                nuevoContacto.id = generarID();
                cout << "\n", linea();
                cout << "\t\t\t\t    * Ingrese el nombre: ";
                cin >> nuevoContacto.nombre;
                linea();
                cout << "\t\t\t\t    * Ingrese el apellido: ";
                cin >> nuevoContacto.apellido;
                linea();
                cout << "\t\t\t\t    * Ingrese el telefono: ";
                cin >> nuevoContacto.telefono;
                linea();
                agregarContacto(nuevoContacto);
                break;
            }
            case 2: {
                int id;
                cout << "\n", linea();
                cout << "\t\t\t\t    Ingrese el ID del contacto a modificar: ";
                cin >> id;
                linea();
                modificarContacto(id);
                break;
            }
            case 3: {
                int id;
                cout << "\n", linea();
                cout << "\t\t\t\t    Ingrese el ID del contacto a eliminar: ";
                cin >> id;
                linea();
                cout << "\t\t\t\t ¿Seguro que desea eliminar el contacto? (S/N): ";
                cin >> op;
                op_mayus = toupper(op);
                if (op_mayus == 'S'){
		        	eliminarContacto(id);
				} else if (op_mayus == 'N'){
					color(hConsole, 12); // Rosa 
		        	cout << "\n\t\t\t        * El contacto no se eliminará, volviendo al menú..." << endl;
		        	getch();
				} else {
					color(hConsole, 4); // Rojo
		        	cout << "\n\t\t\t    == La opción ingresada no existe. Regresando al menú... ==" << endl;
		        	getch();
				}
                
                break;
            }
            case 4: {
                mostrarContactos();
                break;
            }
            case 5: {
                vaciarContactos();
                break;
            }
            case 6: {
            	color(hConsole, 6); // Dorado
                cout << "\n\t\t\t\t       *** Saliendo del programa ***" << endl;
                color(hConsole, 7); // Reset color
                homeroFin(); // Membrete de mi librería .h
                break;
            }
            default:
            	color(hConsole, 4); // Rojo
                cout << "\n\t\t\t\t   Opcion no valida. Intente nuevamente." << endl;
                getch();
                color(hConsole, 7); // Reset color
                break;
        }
    } while (opcion != 6);
    getch();
    return 0;
}

void linea(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 11); // Aqua
	cout << "\t\t\t\t    ==========================================" << endl;
	color(hConsole, 7); // Reset color
}

// Función para generar el ID del siguiente contacto
int generarID() {
    ifstream archivo("agenda.txt");
    string linea;
    int ultimoID = 0;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            ultimoID++;
        }
        archivo.close();
    }
    return ultimoID + 1; // El siguiente ID es el último ID + 1
}

// Función para agregar un contacto
void agregarContacto(const Contacto& contacto) {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	setlocale(LC_ALL,"spanish");
    ofstream archivo("agenda.txt", ios::app);
    if (archivo.is_open()) {
        archivo << contacto.id << " " << contacto.nombre << " " << contacto.apellido << " " << contacto.telefono << endl;
        archivo.close();
        color(hConsole, 10); // verde claro
        cout << "\n\t\t\t\t       -- Contacto agregado con éxito! --" << endl;
    } else {
    	color(hConsole, 4); // Rojo
        cout << "\n\t\t\t\t       -- Error al abrir el archivo. --" << endl;
    }
    color(hConsole, 7); // Reset color
    getch();
}

// Función para mostrar todos los contactos
void mostrarContactos() {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	setlocale(LC_ALL,"spanish");
    ifstream archivo("agenda.txt");
    int id;
    string nombre, apellido, telefono;

    if (archivo.is_open()) {
    	color(hConsole, 9); // Celeste
        cout << "Lista de contactos:\n" << endl;
        color(hConsole, 7); // Reset color
        while (archivo >> id >> nombre >> apellido >> telefono) {
            cout << "ID: " << id << ", Nombre: " << nombre << ", Apellido: " << apellido << ", Teléfono: " << telefono << endl;
        }
        archivo.close();
    } else {
    	color(hConsole, 4); // Rojo
        cout << "\n\t\t\t\t       * Error al abrir el archivo." << endl;
    }
    color(hConsole, 7); // Reset color
    getch();
}

// Función para modificar un contacto por ID
void modificarContacto(int idBuscado) {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	setlocale(LC_ALL,"spanish");
    ifstream archivo("agenda.txt");
    ofstream archivoTemporal("agenda_temp.txt");
    int id;
    string nombre, apellido, telefono;
    bool encontrado = false;

    if (archivo.is_open() && archivoTemporal.is_open()) {
        while (archivo >> id >> nombre >> apellido >> telefono) {
            if (id == idBuscado) {
                encontrado = true;
                color(hConsole, 1); // Azul
                cout << "\t\t\t\t     == Cambiando teléfono de " << nombre << " " << apellido << " ==" << endl;
                cout << "\n\t\t\t\t    * Ingrese el nuevo teléfono: ";
                color(hConsole, 7); // Reset color
                cin >> telefono;
                linea();
            }
            archivoTemporal << id << " " << nombre << " " << apellido << " " << telefono << endl;
        }
        archivo.close();
        archivoTemporal.close();

        remove("agenda.txt");
        rename("agenda_temp.txt", "agenda.txt");

        if (encontrado) {
        	color(hConsole, 10); // Verde claro
            cout << "\n\t\t\t\t       == Contacto modificado con éxito! ==" << endl;
        } else {
        	color(hConsole, 4); // Rojo
            cout << "\n\t\t\t\t           == Contacto no encontrado ==" << endl;
        }
    } else {
    	color(hConsole, 4); // Rojo
        cout << "\n\t\t\t\t       * Error al abrir el archivo." << endl;
    }
    color(hConsole, 7); // Reset color
    getch();
}

// Función para eliminar un contacto por ID
void eliminarContacto(int idBuscado) {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    ifstream archivo("agenda.txt");
    ofstream archivoTemporal("agenda_temp.txt");
    int id;
    string nombre, apellido, telefono;
    bool eliminado = false;

    if (archivo.is_open() && archivoTemporal.is_open()) {
        while (archivo >> id >> nombre >> apellido >> telefono) {
            if (id == idBuscado) {
                eliminado = true;
            } else {
                archivoTemporal << id << " " << nombre << " " << apellido << " " << telefono << endl;
            }
        }
        archivo.close();
        archivoTemporal.close();

        remove("agenda.txt");
        rename("agenda_temp.txt", "agenda.txt");

        if (eliminado) {
        	color(hConsole, 10); // Verde claro
            cout << "\n\t\t\t\t       == Contacto eliminado con éxito! ==" << endl;
        } else {
        	color(hConsole, 4); // Rojo
            cout << "\n\t\t\t\t           == Contacto no encontrado ==" << endl;
        }
    } else {
    	color(hConsole, 4); // Rojo
        cout << "\n\t\t\t\t       * Error al abrir el archivo." << endl;
    }
    color(hConsole, 7); // Reset color
    getch();
}

// Función para vaciar la lista de contactos
void vaciarContactos() {
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	char op, op_mayus;
    ifstream archivo("agenda.txt");
    if (archivo.is_open()) {
    	color(hConsole, 4); // Rojo
    	cout << "\n\t\t\t\t       == LA LISTA COMPLETA SE VACIARÁ ==" << endl;
        cout << "\n\t\t\t\t            ¿Desea continuar? (S/N): ";
        color(hConsole, 7); // Reset color
        cin >> op;
        op_mayus = toupper(op); // Pasa el caracter ingresado a mayúscula
        if (op_mayus == 'S'){
        	ofstream archivo("agenda.txt", ios::trunc);
        	archivo.close();
        	color(hConsole, 10); // Verde claro
        	cout << "\n\t\t\t           == La lista de contactos ha sido vaciada ==" << endl;
		} else if (op_mayus == 'N'){
			archivo.close();
			color(hConsole, 12); // Rosa 
        	cout << "\n\t\t\t         == La lista de contactos no se vaciará ==" << endl;
		} else {
			archivo.close();
			color(hConsole, 4); // Rojo
        	cout << "\n\t\t        == La opción ingresada no existe. La lista no se vaciará ==" << endl;
		}
    } else {
    	color(hConsole, 4); // Rojo
        cout << "\n\t\t\t\t       * Error al abrir el archivo." << endl;
    }
    color(hConsole, 7); // Reset color
    getch();
}
