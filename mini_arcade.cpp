#include <iostream>   // librería estandar para el input/output stream
#include <stdio.h>    // librería estandar para input/output stream
#include <string.h>   // librería con funciones para manipular strings y arreglos
#include <ctime>      // librería con funciones manipular fecha y tiempo
#include <list>       // librería con funciones para manipular listas
#include <fstream>    // librería leer y escribir archivos

using namespace std;

bool repetir_programa = true;

struct Ahorcado {
    char letra;
	string display_ahorcado[7];
	string checar_validez;
	string letras_usadas = "";
	int numero_de_intentos=6;
	bool continuar;
};

int comparar_letra_usuario (string personaje, string &personaje_oculto, char letra);  // El operador (&) indica un paso de parámetro por referencia
// la función itera cada caracter para regresar el número total de coincidencias, mostrando la letra si es que coincide
void display_tableros (string entrada_pamostrar[]);  // itera y muestra un vector, obviando que se trata de un arreglo de seis elementos solamente
void mostrar_corazones();
void construye_tu_poema();
int funcion_repetir_programa ();  // pregunta al usuario y regresa un entero (1 o 0)
void batalla_naval ();
void juego_ahorcado ();

int main(){

    do {
        system("cls");      // en caso de que repetir_programa == true
        system("color 7");  // cambia el color a blanco
        char opcion_de_juego;

        cout << "****************************************************************" << endl;
        cout << "********************** MINI-JUEGOS EN C++ **********************" << endl;
        cout << endl;
        cout << "    A => Ahorcado (de Disney)           ............... " << endl;
        cout << "    B => Batalla naval                  A que no puedes " << endl;
        cout << "    C => Construye tu poema             jugar solo uno! " << endl;
        cout << "                                        ............... " << endl;
        cout << "    X => Salir" << endl;
        cout << endl;
        cout << "****************************************************************" << endl;
        cout << endl;
        cout << "Introduce la opcion de juego deseada: " << endl;
        cout << ">>> " ;
        cin >> opcion_de_juego;
        cout << endl;

        switch (opcion_de_juego)
        {
            case 'a':
            case 'A':
                {
                system("cls");
                system("color E");  // cambia el color a amarillo clarito
                juego_ahorcado();
                repetir_programa = funcion_repetir_programa();
                break;
                }

            case 'b':
            case 'B':
                {
                system("cls");
                system("color B");   // cambia el color a azul clarito
                batalla_naval ();
                repetir_programa = funcion_repetir_programa();
                break;
                }

            case 'c':
            case 'C':
                {                     // system("cls") está dentro de la función así que no es necesario
                system("color C");    // cambia el color a rojo
                construye_tu_poema ();
                repetir_programa = funcion_repetir_programa ();
                break;
                }

            case 'X':
            case 'x':
                system("cls");
                cout << "****************************************************************" << endl;
                cout << "************** Gracias por jugar, vuelve pronto! ***************" << endl;
                cout << endl;
                cout << "     Creado por: Harim Hidalgo" << endl;
                cout << endl;
                repetir_programa = false;  //
                break;

            default:
                cout << "/// ERROR: Caracter invalido. Vuelve a intentarlo." << endl;
                cout << endl;
                system("pause");
                break;

        }

    } while (repetir_programa==true);

	return 0;
}


void display_tableros (string entrada_pamostrar[]){
// itera y muestra un vector, obviando que se trata de un arreglo de seis elementos solamente
    int i;
    for (i=0; i<=5; i++){
        cout << "   " << entrada_pamostrar[i] << endl;
    }
    cout << endl;
}

void construye_tu_poema (){

    string primer_linea, segunda_linea, tercer_linea, ultima_linea;

    primer_linea = "Las rosas son rojas," ;
    segunda_linea = "el cielo es azul," ;
    tercer_linea =  "  _________________," ;
    ultima_linea = "  _________________." ;

    system("cls");

    cout << "****************************************************************" << endl;
    cout << "********************** CONSTRUYE TU POEMA **********************" <<  endl;
    cout << endl;
    cout << "  " << primer_linea << endl;
    cout << "  " << segunda_linea << endl;
    cout << tercer_linea << endl;
    cout << ultima_linea << endl;
    cout << endl;

    cout << "Inventa la primer linea faltante: " << endl;
    cout << ">>> " ;
    cin.ignore();     // el método ignore() descartar el salto de línea que se guarda en el buffer de entrada
    getline(cin, tercer_linea);   // así cuando usamos la función getline podemos leer la línea completa
    cout << endl;

    cout << "Inventa la segunda linea faltante: " << endl;
    cout << ">>> " ;
    getline(cin, ultima_linea);
    cout << endl;

    cout << "Presiona 'Enter' para mostrar el poema!" << endl;
    cin.ignore();   // sustituye al system("pause") para poder realizar la personalización del mensaje

    system("cls");
    cout << "****************************************************************" << endl;
    cout << "********************** CONSTRUYE TU POEMA **********************" <<  endl;
    cout << endl;

    if (tercer_linea.back() != ',') {   // el método back() nos permite accesar el último elemento de un vector
        tercer_linea += ',';
    } else {}

    if (ultima_linea.back() != '.') {
        ultima_linea += '!';
    } else {}

    mostrar_corazones();

    cout << "   " << primer_linea + '\n' << "   " << segunda_linea + '\n' << "   " << tercer_linea + '\n' << "   " << ultima_linea << endl;  // '\n' equivale a un salto de línea
    cout << endl;
    cout << "Puedes volver a ver tu poema en el archivo 'poema.txt'" << endl;
    cout << endl;

    ofstream archivo;
    archivo.open("poema.txt");   // aquí abrimos el arhivo usando el metodo open(), pasando como parámetro el nombre del archivo
    archivo << primer_linea + '\n' + segunda_linea + '\n' + tercer_linea + '\n' + ultima_linea;
    archivo.close();   // aquí cerramos el archivo para liberarlo
}

void mostrar_corazones (){

    cout << "             ,;;;,   ,;;;, " << endl;
    cout << "            ;;;;;;;,;;;;;;;" << endl;
    cout << "   .:::.   .::::;;;;;;;;;;;" << endl;
    cout << "  :::::::.:::::::;;;;;;;;;'" << endl;
    cout << "  :::::::::::::::;;;;;;;'  " << endl;
    cout << "  ':::::::::::::';;;;;'    " << endl;
    cout << "    ':::::::::'   ';'      " << endl;
    cout << "      ':::::'              " << endl;
    cout << "        ':'                " << endl;
    cout << endl;

}

int comparar_letra_usuario (string personaje, string &personaje_oculto, char letra){
// la función itera cada caracter (de personaje) para regresar el número total de coincidencias (con letra), mostrando la letra (en personaje_oculto) si es que coincide

	int i, numero_letras, coincidencias=0;

    numero_letras = personaje.length();   // el método length() nos regresa el numero total de caracteres de un string

	for (i=0; i<numero_letras; i++){
		if (letra == personaje[i]){
			personaje_oculto[i] = letra;  // como se pasó la variable por referencia se modifica directamente
			coincidencias++;
		}
	}

	return coincidencias;
}

void juego_ahorcado (){

    Ahorcado A;
    int numero1;
	string personaje;

    A.display_ahorcado[0] = "  _____  ";
    A.display_ahorcado[1] = "  |   o  ";
    A.display_ahorcado[2] = "  |  (|) ";
    A.display_ahorcado[3] = "  |  ( ) ";
    A.display_ahorcado[4] = "  |      ";
    A.display_ahorcado[5] = "=========";

    string personajes_disney[] = {"kronk", "bella", "mickey", "buzz", "woody", "stitch",   // arreglo tipo string con todos los nombres posibles
    "dumbo", "mulan", "mushu", "hercules", "hades", "lilo", "pluto", "minnie", "andy",
    "cenicienta", "elsa", "ralph", "olaf", "goofy", "campanita", "malefica", "pinocho",
    "simba", "mufasa", "aladino", "ariel", "aurora", "baloo", "bambi", "bestia", "blancanieves",
    "boo", "dory", "igor", "jafar", "merida", "nala", "nemo", "piglet", "pocahontas",
    "quasimodo", "pumba", "rapunzel", "tarzan", "timon", "tiana", "tiger", "urzula", "zazu"};     // total de 50 personajes

	srand(time(0));   // la función srand() devuelve un número entero pseudo-aleatorio a partir de una semilla
                      // la semilla de srand() viende dada por la función time() determina el tiempo en formato condensado
                      // pasandole como parámetro un valor nulo (NULL o 0) para que sea ignorado y no tener que pasar un objeto time_t
	numero1 = rand()%50;    // la función rand() regresa un entero pseudo-aleatorio entre 0 y  2147483647 (RAND_MAX)
	personaje = personajes_disney[numero1];

	string personaje_oculto(personaje.length(),'_');   // inicializamos la variable con un constructor tipo fill (size n, char c)

    cout << "****************************************************************" << endl;
    cout << "********************* AHORCADO (de Disney) *********************" << endl;
    display_tableros(A.display_ahorcado);
    cout << "Generalidades --> Las palabras para adivinar son nombres de per-" << endl;
    cout << "sonajes de Disney, tienes 6 intentos para adivinar todas las le-" << endl;
    cout << "tras o... terminaras como el tipo de alla arriba, ups, suerte!!!" << endl;
    cout << endl;
    cout << "Nombre del personaje para hacer trampita: " << personaje << endl;
    cout << endl;

    system("pause");
    system("cls");

    while (A.numero_de_intentos>0){

        cout << "****************************************************************" << endl;
        cout << "********************* AHORCADO (de Disney) *********************" << endl;
        cout << endl;

        switch (A.numero_de_intentos){
            case 6:
                A.display_ahorcado[1][6] = ' ';
                A.display_ahorcado[2][6] = ' ';
                A.display_ahorcado[2][5] = ' ';
                A.display_ahorcado[2][7] = ' ';
                A.display_ahorcado[3][7] = ' ';
                A.display_ahorcado[3][5] = ' ';
                break;
            case 5:
                A.display_ahorcado[1][6] = 'o';
                break;
            case 4:
                A.display_ahorcado[2][6] = '|';
                break;
            case 3:
                A.display_ahorcado[2][5] = '(';
                break;
            case 2:
                A.display_ahorcado[2][7] = ')';
                break;
            case 1:
                A.display_ahorcado[3][5] = '(';
                break;
        }

        display_tableros(A.display_ahorcado);
        cout << "    " << personaje_oculto << "             Letras quemadas: " << A.letras_usadas << endl;
        cout << endl;

        do {
            A.continuar=false;
            cout << "Introduce una letra: " << endl;
            cout << ">>> " ;
            cin >> A.letra;
            cout << endl;
            A.checar_validez = A.letra; // A.checar_validez es un string que toma el char A.letra como valor
            if (isdigit(A.checar_validez.at(0))){   // la función isdigit() regresa 1 o 0 dependiendo si un caracter es numérico
                                                    // o no, mientras que el método at() regresa el elemento dentro del arreglo en
                                                    // la posición dada como parámetro
                cout << "/// Error: No se permiten caracteres numericos. Intentalo de nuevo." << endl;
                cout << endl;
            } else if (A.letras_usadas.find(A.letra) != A.letras_usadas.npos) { // el método find() regresa la posición del primer
                                                    // caracter que haga match con el char que pasamos como parámetro (en caso que no haya
                                                    // coincidencia, el método regresa string.npos, que es igual a -1 y viene de  "no position")
                cout << "/// Error: Caracter introducido previamente. Intentalo de nuevo." << endl;
                cout << endl;
            } else {
                A.letra = tolower(A.letra);   // la función tolower() convierte los caracteres en minúsculas
                A.continuar = true;  // una vez que se pasan los requisitos de los if statements se puede salir del ciclo do-while
                A.letras_usadas += A.letra;
            }
        } while (A.continuar == false);

		if (comparar_letra_usuario(personaje, personaje_oculto, A.letra)==0){  // la función regresa el # coincidencias
			cout << "Caray, estuviste cerca! Pero la letra '" << A.letra << "' no esta en el nombre :(" << endl;
			A.numero_de_intentos--;  // decrementamos el numero de intentos disponibles para adivinar
            cout << "Intentos restantes: " << A.numero_de_intentos << endl;
            cout << endl;
            system("pause");
            system("cls");
		} else {
			cout << "Bien hecho! Walt Disney dice que la letra '" << A.letra << "' es correcta ;)" << endl;
            cout << "Intentos restantes: " << A.numero_de_intentos << endl;
            cout << endl;
            system("pause");
            system("cls");
		}

		if (personaje==personaje_oculto){  // caso en el que se gana la partido
            system("cls");
            cout << "****************************************************************" << endl;
            cout << "*************************** AHORCADO ***************************" <<  endl;
            cout << endl;
            display_tableros(A.display_ahorcado);
            cout << "    " << personaje_oculto << endl;
            cout << endl;
			cout << "GANASTE, FELICIDADES!!! El personaje era " << personaje << "!!" <<endl;
			cout << endl;
			break; // literalmente "rompe" el ciclo
		} else {}
	}

	if(A.numero_de_intentos == 0){  // caso en el que se pierde la partida
        system("cls");
        cout << "****************************************************************" << endl;
        cout << "*************************** AHORCADO ***************************" <<  endl;
        cout << endl;
        A.display_ahorcado[3][7]= ')';
        display_tableros(A.display_ahorcado);
        cout << "    " << personaje_oculto << endl;
        cout << endl;
		cout << "Alguien enveneno el abrevadero, vaquero, y creo que fuiste tu..." << endl;
		cout << "Que le corten la cabezaaa!!! A LA HORCA!! x.X" << endl;
		cout << endl;
		cout << "Perdiste, el personaje era: " << personaje << endl;
		cout << endl;
	}
}

int funcion_repetir_programa () {   // pregunta al usuario y regresa un entero (1 o 0)

    int repetir, pass=0; // pass es una bandera para salir del ciclo en caso de que el numero esté fuera de rango

    do {
        cout << "****************************************************************" << endl;
        cout << endl;
        cout << "Quieres seleccionar otro juego? ( si=1 , no/salir=0 )" << endl;
        cout << ">>> " ;
        cin >> repetir;
        if (repetir==0) {
            system("color 7");  // cambia el color a blanco
            system("cls");
            cout << "****************************************************************" << endl;
            cout << "************** Gracias por jugar, vuelve pronto! ***************" << endl;
            cout << endl;
            cout << "       Creado por: Harim Hidalgo" << endl;
            cout << endl;
            pass++;
        } else if (repetir==1) {
            cout << endl;
            pass++;
        } else {
            cout << endl;
            cout << "/// Error: Opcion invalida, vuelve a intentarlo." << endl;
            cout << endl;
        }

    } while (pass==0);

    return repetir;
}

void batalla_naval (){

    string nombre_jugador, tablero[6];

    tablero[0] = " # 1 2 3 4 5";
    tablero[1] = " a . . . . .";
    tablero[2] = " b . . . . .";
    tablero[3] = " c . . . . .";
    tablero[4] = " d . . . . .";
    tablero[5] = " e . . . . .";

    char letra;
    int fila, columna, i, numero_botes=3, fila_bote[3], columna_bote[3], intentos_b=0;
    bool siguiente;

    cout << "****************************************************************" << endl;
    cout << "************************ BATALLA NAVAL *************************" <<  endl;
    cout << endl;
    cout << "   " << tablero[0] << "                   ______          " << endl;
    cout << "   " << tablero[1] << "            __    /   [//]    ____ " << endl;
    cout << "   " << tablero[2] << "           |==|__[]______|___/   / " << endl;
    cout << "   " << tablero[3] << "           |                    /  " << endl;
    cout << "   " << tablero[4] << "        ~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   " << tablero[5] << endl;
    cout << endl;
    cout << "Generalidades --> El juego consiste en destruir los barcos enemi-" << endl;
    cout << "gos en el tablero. Hay un total de 3 barcos de 1x1 que se asignan" << endl;
    cout << "de manera aleatoria y secreta... Ajoy, capitan!! Destruyelos!!!" << endl;
    cout << endl;
    cout << "Introduce tu nombre:" << endl;
    cout << ">>> Capitan " ;
    cin.ignore();  // el método ignore() descartar el salto de línea que se guarda en el buffer de entrada
    getline(cin, nombre_jugador);  // así cuando usamos la función getline podemos leer la línea completa
    cout << endl;

    do { // en este do-while nos aseguramos que la posición de los botes no sólo sea aleatoria, sino que también
         // sea diferente para cada bote comparándola con la de los otros dos
        srand(time(0));   // la función srand() devuelve un número entero pseudo-aleatorio a partir de una semilla
                          // la semilla de srand() viende dada por la función time() determina el tiempo en formato condensado
                          // pasandole como parámetro un valor nulo (NULL o 0) para que sea ignorado y no tener que pasar un objeto time_t
        for (i=0; i<=2; i++){
            fila_bote[i] = (rand()%5)+1;
            columna_bote[i] = (rand()%5)+1;
            }
        if ((fila_bote[0] == fila_bote[1]) && (columna_bote[0]==columna_bote[1])){
            siguiente=false;
        } else if ((fila_bote[0] == fila_bote[2]) && (columna_bote[0]==columna_bote[2])){
            siguiente = false;
            } else if ((fila_bote[1] == fila_bote[2]) && (columna_bote[1]==columna_bote[2])){
                siguiente = false;
            } else {
                siguiente = true;
            }
    } while (siguiente==false);

    cout << "Ubicaciones para hacer trampa:" << endl;

    for (i=0; i<=2; i++) {
        cout << "Fila/Columna: " << fila_bote[i] << "/" << columna_bote[i] << endl;
    }
    cout << endl;

    do {

        system("pause");
        system("cls");
        cout << "****************************************************************" << endl;
        cout << "************************ BATALLA NAVAL *************************" <<  endl;
        cout << endl;

        display_tableros (tablero);

        siguiente = false;
        do {
            cout << "Introduce la fila (a, b, c, d, e): " << endl;
            cout << ">>> " ;
            cin >> letra;
            letra = tolower(letra);  // la función tolower() convierte los caracteres en minúsculas
            if (letra=='a'){
                fila = 1;
                siguiente = true;
            } else if (letra=='b'){
                fila = 2;
                siguiente = true;
            } else if (letra=='c'){
                fila = 3;
                siguiente = true;
            } else if (letra=='d'){
                fila = 4;
                siguiente = true;
            } else if (letra=='e'){
                fila = 5;
                siguiente = true;
            } else {
                cout << endl;
                cout << "/// Error: Caracter invalido, vuelve a intentarlo." << endl;
                cout << endl;
            }
        } while (siguiente==false);
        cout << endl;

        siguiente = false;
        do {
            cout << "Introduce la columna (1, 2, 3, 4, 5): " << endl;
            cout << ">>> " ;
            cin >> columna;
            if (columna>=1 && columna<=5) {
                siguiente = true;
            } else {
                cout << endl;
                cout << "/// Error: Numero fuera de rango, vuelve a intentarlo." << endl;
                cout << endl;
            }
        } while (siguiente==false);
        cout << endl;

        if (tablero[fila][columna*2+1] == ' '){  // la expresión columna*2+1 nos permite generalizar la comparación
            cout << "/// Error: casilla ya descubierta, intentalo de nuevo." << endl;
        } else if (tablero[fila][columna*2+1] == 'x'){
            cout << "/// Error: casilla ya descubierta, intentalo de nuevo." << endl;
        } else if ((fila==fila_bote[0])&&(columna==columna_bote[0])) {
            numero_botes = numero_botes -1;
            cout << "Ajoy!! Felicidades Capitan " << nombre_jugador << "!!" << endl;
            cout << "Ha destruido un bote (restantes " << numero_botes << "/3)" << endl;
            columna = columna*2 + 1;
            tablero[fila][columna] = 'x';
            intentos_b++;
        } else if ((fila==fila_bote[1])&&(columna==columna_bote[1])) {
            numero_botes = numero_botes -1;
            cout << "Ajoy!! Felicidades Capitan " << nombre_jugador << "!!" << endl;
            cout << "Ha destruido un bote (restantes " << numero_botes << "/3)" << endl;
            columna = columna*2 + 1;
            tablero[fila][columna] = 'x';
            intentos_b++;
        } else if ((fila==fila_bote[2])&&(columna==columna_bote[2])) {
            numero_botes = numero_botes -1;
            cout << "Ajoy!! Felicidades Capitan " << nombre_jugador << "!!" << endl;
            cout << "Ha destruido un bote (restantes " << numero_botes << "/3)" << endl;
            columna = columna*2 + 1;
            tablero[fila][columna] = 'x';
            intentos_b++;
        } else {
            cout << "Vientos huracanados! Mas salado que el mar imposible!" << endl;
            cout << "Siga intentando capitan " << nombre_jugador << "... " << endl;
            columna = columna*2 + 1;
            tablero[fila][columna] = ' ';
            intentos_b++;
        }
        cout << endl;

    } while (numero_botes>0);

    system("pause");
    system("cls");
    cout << "****************************************************************" << endl;
    cout << "************************ BATALLA NAVAL *************************" <<  endl;
    cout << endl;

    display_tableros (tablero);

    cout << "Por los siete mares... Por las barbas de mi abuelooo!!" << endl;
    cout << "Capitan " << nombre_jugador << ", HA GANADO LA BATALLA en " << intentos_b << " intentos!!" << endl;
    cout << endl;
}
