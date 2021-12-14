#include <iostream>
#include <string>

using namespace std;

struct Materia{
    string nombre;
    float examen[3];
    float proyecto;
    int faltas;
    float promedio = 0;
};

struct Alumno{
    string nombre;
    string carrera;
    char grupo;
    int ID;
    Materia clase[3];
};

Alumno A;

int capturar_calif(int rango);
void cabecera();
void capturar_datos ();
void obtener_promedio ();
void mostrar_datos ();
void aprobado_reprobado(int calif);

int main(){
    system("color B");
    cabecera();
    capturar_datos();
    obtener_promedio();
    mostrar_datos ();
	return 0;
}

int capturar_calif(int rango){
    bool pass=false;
    int calif;
    do {
        cin >> calif;
        if ((calif<0)||(calif>rango)){
            cout << endl;
            cout << "/// ERROR: numero fuera de rango (0-" << rango << "). Intentalo de nuevo." << endl;
            cout << endl;
            cout << ">>> ";
        } else { pass=true; }
    } while (pass==false);
    return calif;
}

void cabecera(){
    cout << "******************************** BASE DE DATOS DEL ALUMNO ********************************" << endl;
    cout << "******************************************************************************************" << endl;
    cout << endl;
}
void capturar_datos (){
    int i, j;
    cout << "Presiona 'Enter' para capturar los datos del alumno:" << endl;
    cin.ignore();  // flushes the input buffer
    cout << "Introduce el nombre del alumno: " << endl;
    cout << ">>> ";
    getline(cin, A.nombre);  // gets the line using cin
    cout << endl;
    cout << "Introduce la carrera del alumno: " << endl;
    cout << ">>> ";
    getline(cin, A.carrera);
    cout << endl;
    cout << "Introduce el grupo del alumno: " << endl;
    cout << ">>> ";
    cin >> A.grupo;
    cout << endl;
    cout << "Introduce el ID del alumno: " << endl;
    cout << ">>> ";
    cin >> A.ID;
    cout << endl;
    for (i=0; i<3; i++){
        system("pause");
        system("cls");
        cabecera();
        cout << "Introduce el nombre de la clase " << i+1 << " del alumno: " << endl;
        cout << ">>> ";
        cin >> A.clase[i].nombre;
        cout << endl;
        for (j=0; j<3; j++){
            cout << "Introduce la calificacion de la clase " << A.clase[i].nombre << " en el examen " << j+1 << ": " << endl;
            cout << ">>> ";
            A.clase[i].examen[j] = capturar_calif(10);
            cout << endl;
        }
        cout << "Introduce la calificacion del proyecto de la clase " << A.clase[i].nombre << " del alumno: " << endl;
        cout << ">>> ";
        A.clase[i].proyecto = capturar_calif(10);
        cout << endl;
        cout << "Introduce el numero de faltas de la clase " << A.clase[i].nombre << " del alumno: " << endl;
        cout << ">>> ";
        cin >> A.clase[i].faltas;
        cout << endl;
    }
}

void obtener_promedio (){
    int i, j, suma_calif;
    for (i=0; i<3; i++){
        if (A.clase[i].faltas > 20){
            A.clase[i].promedio = 0;
        } else {
            A.clase[i].promedio += 0.4*A.clase[i].proyecto;
            for (j=0; j<3; j++){
                A.clase[i].promedio += 0.2*A.clase[i].examen[j];
            }
        }
    }
}

void mostrar_datos (){
    int i, j;
    system("pause");
    system("cls");
    cabecera();
    cout << "Nombre del alumno: " << A.nombre << endl;
    cout << "Carrera del alumno: " << A.carrera << endl;
    cout << "Grupo del alumno: " << A.grupo << endl;
    cout << "ID del alumno: " << A.ID << endl;
    cout << endl;
    cout << "******************************************************************************************" << endl;
    cout << endl;
    cout << "PROMEDIO FINAL: " << (A.clase[0].promedio+A.clase[1].promedio+A.clase[2].promedio)/3 << endl;
    cout << endl;
    for (i=0; i<3; i++){
        cout << "******************************************************************************************" << endl;
        cout << endl;
        cout << "Clase " << i+1 << " del alumno: " << A.clase[i].nombre << endl;
        cout << endl;
        for (j=0; j<3; j++){
            cout << "Calificacion de la clase " << i+1 << " del examen " << j+1 << ": " << A.clase[i].examen[j] << endl;
        }
        cout << "Calificacion del proyecto de la clase " << A.clase[i].nombre << " del alumno: " << A.clase[i].proyecto << endl;
        cout << "Numero de faltas de la clase " << A.clase[i].nombre << " del alumno: " << A.clase[i].faltas << endl;
        cout << endl;
        cout << "Promedio de la clase " << A.clase[i].nombre << " del alumno: " << A.clase[i].promedio ;
        aprobado_reprobado(A.clase[i].promedio);
        cout << endl;
    }
}

void aprobado_reprobado(int calif){
    if(calif>=6){
        cout << " ( APROBADO ) " << endl;
    } else {
        cout << " ( REPROBADO ) " << endl;
    }
}
