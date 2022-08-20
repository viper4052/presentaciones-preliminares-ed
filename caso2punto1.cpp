#include <string>
int maxDispositivos = 12;   // es la cantidad MAXIMA de dispositivos. 
int maxHabitaciones = 4;    // es la cantidad MAXIMA de habitaciones.

using namespace std;

// int tamanoListaDisp = 8; // define un tamaño inicial para la lista de dispositivos
// int tamanoListaParam = 4; // define un tamaño inicial para la lista de parametros

enum tipoDisp{  // distintos enums literales para que luego en clase pueda saberse cual metodo usarse, como ejemplo
    bombillo,
    sensorHumo,
    sensorPuertas,
    camara
};


struct parameter // struct que permite definir qué debe llevar un elemento del array parameters[] de más abajo
{
    string llave;
    string valor;
};


// clase principal llamada dispositivo
class Dispositivo{
    public:                    // define atributos privados
        string nombre;          // nombre de un dispositivo
        tipoDisp tipo;          // tipo del dispositivo
        int habitacion;         // numero de habitacion en el que se ubica
        string acciones[];      // arreglo que contiene
        parameter parameters[]; // arreglo que contiene parametros editables del dispositivo propio  
        
    public:
        acciones(){}; // metodo que retorna las acciones que el usuario puede escoger llamar del dispositivo propio
        /*
        // metodo que expone lo que puede editarse para cada dispositivo
        init(){
            parameters[0] = {"intensidad", "3"};         // parametro aplicable para un bombillo por ejemplo para su funcion de intensidad
            parameters[1] = {"color", "[120, 25, 90]"};  // parametro aplicable para un bombillo por ejemplo, para su funcion de color
        }

        // metodo que retorna el array de parametros de objeto para así poder configurar los parámetros a voluntad
        parameter getParams(){
            return parameters;  // retorna, en este caso, intensidad y color
        }
        */

};


int agregarDispositivo(int habitacion, Dispositivo listaDispositivos[]){
    // ¿existe la habitación indicada?
        // no - retorna y tira error que no existe la habitación.
    // ¿hay espacio en el array para agregar un nuevo dispositivo?
        // no - entonces hace que listaDispositivos[] ahora tenga un tamaño doble al original
        // busca la ultima posicion posible en la habitacion de parametro para agregar dispositivo
        // añade dispositivo al array
    return 0;
}

int creaTareas(string nombreTarea, parameter parameters[], string acciones[], Dispositivo listaDispositivos[]){
    // de la listaDispositivos[], se consigue los dispositivos que se quiere tener en conjunto para la tarea.
    // de cada dispositivo, hace un get de los métodos posibles de los dispositivos y añade el nombre a acciones[].
    // dependiendo de lo que se quiera hacer en la tarea, el usuario define los parámetros de los objetos y se le asigna nombreTarea como nombre para distinguir.
}


int main(){
    
    Dispositivo listaDispositivos[maxHabitaciones][maxDispositivos]; // crea el arreglo que almacenará dispositivos en habitaciones
    // llama al resto del programa que resuelva el problema planteado
    return 0;
}
