#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <list>

using namespace std;

//******************************************
enum tipoDisp {  // enums literales para identificar dispositivos
	bombillo,
	sensorHumo,
	sensorPuertas,
	camara,
};

enum TareasDisponibles {  // nombres de acciones de dispositivos de mentirilla
	Encender_bombillo,
	Apagar_bombillo,
	Subir_intensidad,
	Bajar_intensidad,
	etc,
};

struct parameter // struct que permite definir qué debe llevar un elemento del array parameters[] de más abajo
{
	string Llave;
	string Valor;
};


typedef struct TDispositivos
{
	string Nombre;			// nombre de un dispositivo
	tipoDisp Tipo;			// tipo del dispositivo
	int Habitacion;			// numero de habitacion en el que se ubica
	
	list<string> Acciones;                 // lista de las acciones que puede incluir el dispositivo
	list<parameter> Parametros;  		   // lista de los parametros que poseera el dispositivo
	
	
	TDispositivos* SiguienteDispositivo;		// Puntero el cual apuntara a la direccion de momoria de del siguiente dispositivo

}*PtrTDispositivos;  			//Puntero para poder acceder al struct de TDispositivos

typedef struct Tareas // struct que define que aspectos debe contener una tarea
{
	string NombreTarea;					
	//string AccionesARealizar[6];
	list<string> AccionesARealizar;
	tipoDisp Tipo;

	Tareas* SiguienteTarea;		//

}*PtrTareas;

PtrTDispositivos ListaDispositivos;  // lista global en la que se guarda los dispositivos registrados
PtrTareas ListaDeTareas;             // lista global de las tareas de dispositivos


//------------------------------------------FUNCIONES--------------------------------------------------------------


void InicializarDispositivosYTareas(PtrTDispositivos& Lista, PtrTareas& ListaTareas)
{
	Lista = NULL;
	ListaTareas = NULL;
};

PtrTDispositivos CrearDispositivo(string pnombre, tipoDisp pTipoDispositivo, int pNumHabitacion)
{
	PtrTDispositivos Dispositivo = new(TDispositivos);
	Dispositivo->Nombre = pnombre;
	Dispositivo->Tipo = pTipoDispositivo;
	Dispositivo->Habitacion = pNumHabitacion;

	//while de la acciones que podria realizar el dispositivo
	Dispositivo->Acciones.push_back();
	
	//while de los parametros que podria realizar el dispositivo
	Dispositivo->Parametros.push_back(); // agrega parametros para dispositivo a la lista Parametros
	Dispositivo->SiguienteDispositivo = NULL;

	return Dispositivo;		
};

PtrTareas CrearNuevaTarea()
{
	PtrTareas TareasRealizar = new (Tareas);
	
	cout<<"Ingrese el nombre de la tarea";
	string NombreDeLaTarea;
	cin >> NombreDeLaTarea;

	TareasRealizar->NombreTarea = NombreDeLaTarea;

	//Se solicita el dispostivo al cual se le quieren asignar las tareas y se muestras las acciones que este puede realizar
	//para posteriormente incluirlas en la lista de tareas.

	TareasRealizar->AccionesARealizar.push_back(); // dentro de la lista de acciones de dispositivos que forman parte de la tarea a crear, busca indices y apunta hacia los metodos de dispositivos y las ofrece al usuario para agregar a la Nueva Tarea
	
	TareasRealizar->SiguienteTarea = NULL;
	
	return TareasRealizar;
};

PtrTareas AgregarTareasADispositivos(PtrTDispositivos& ListaDiapositivos, PtrTareas& ListaTareas, PtrTareas& NuevaTerea) // Agrega acciones de la lista 
{
	//Se recorreria la lista de dispositivos para poder asignar y ejecutar las tarea que se requiere 

	//Ademas se agregaria la tarea a la lista de tareas

	NuevaTerea->SiguienteTarea = NULL;
	ListaTareas = NuevaTerea;
};

void AgregarAListasDispositivos(PtrTDispositivos& Lista, PtrTDispositivos& Nuevo) // crea un punto de inicio en la lista para comenzar a enlazar elementos
{
	Nuevo->SiguienteDispositivo = Lista;
	Lista = Nuevo;
};

void EliminarDispositivo(PtrTDispositivos& Lista, string pNombre)
{
	/*
		Busca en toda la lista por el dispositivo con nombre pNombre.
		Luego hace que su pointer sea nulo o su direccion original de memoria sea NULL
		para liberar espacio en la lista enlazada.
	*/
};

//-----------------------------------------------MAIN---------------------------------------------------

void main(int argc, char* argv[])
{
	PtrTDispositivos Nuevo;
	PtrTareas NuevaTarea;
	
	//************************************************************************	
	InicializarDispositivosYTareas(ListaDispositivos, ListaDeTareas);         //Se inicializa las lista enlazadas que contengran los dispositivos y tareas
	Nuevo = CrearDispositivo("nuevo dispositivo", bombillo, 4); 			// agarra un literal tipoDisp del enum
	AgregarAListasDispositivos(ListaDispositivos, Nuevo);        			//Se pasa la lista de dipositivos y se agrega el nuevo dispositivo.
	EliminarDispositivo(ListaDispositivos, "Bombillo");					//Se envia la lista con los dispositivos y el dispositivo que sera eliminado.


	NuevaTarea = CrearNuevaTarea(); //Se crea la tarea a relizar con su accion a relizar ademas a que dispositivo y que habitacion 
	AgregarTareasADispositivos(ListaDispositivos, ListaDeTareas, NuevaTarea);	// Se envia las listas de tareas con los dispositivos y la nueva tarea
};
