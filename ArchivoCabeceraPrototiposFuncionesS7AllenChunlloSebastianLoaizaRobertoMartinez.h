// INTEGRANTES: ALLEN CHUNLLO, SEBASTIÁN LOAIZA, ROBERTO MARTÍNEZ
// CARRERA: INGENIERÍA EN INTELIGENCIA ARTIFICIAL
// CURSO: PROGRAMACIÓN I
// TEMA: S7 - EJERCICIO DE PROGRAMACION
// DOCENTE: BYRON RODRIGUEZ UTRERAS
// FECHA: 11 - 11 - 2026
// NRC: 2325

//OBJETIVOS: 
//Aplicar los conocimientos adquiridos en la materia de Programación 1 para diseñar una solución tecnológica (sistema computacional), 
//que se establezca como una herramienta viable para solventar un problema propuesto. 

//Realizar un análisis integral del problema, identificando sus principales variables y restricciones; para plantear varias alternativas de solución y 
//evaluarlas para seleccionar aquella que resuelva de manera integral el problema identificado. 

//DESARROLLO DE PROTOTIPOS

//EVITO QUE ESTOS PROTOTIPOS SE INCLUYAN DOS VECES EN EL MISMO ARCHIVO.
#ifndef FUNCIONES_S7_H
//MARCO QUE YA INCLUÍ ESTA CABECERA.
#define FUNCIONES_S7_H

//MUESTRO EL MENÚ PRINCIPAL CON LAS OPCIONES DE REGISTRAR Y SALIR.
void mostrarMenu(void);

//LEO LA OPCIÓN DEL MENÚ; DEVUELVO 1, 2 O 0 SI SE ACABA LA ENTRADA.
int leerOpcionMenu(void);

//DEVUELVO EL TIEMPO DISPONIBLE; USO -1.0 PARA AVISAR EL FIN DE LA ENTRADA.
float leerTiempoDisponible(void);

//DEVUELVO LOS RECURSOS DISPONIBLES O -1 SI NO PUDE LEERLOS.
int leerRecursosDisponibles(void);

//GUARDO EL NOMBRE EN EL ARREGLO QUE RECIBO; DEVUELVO 1 SI LO LEÍ O -1 SI SE ACABÓ LA ENTRADA.
int leerNombreProducto(char nombre[20]);

//DEVUELVO LA DEMANDA LEÍDA O -1 SI SE ACABA LA ENTRADA.
int leerDemanda(void);

//DEVUELVO EL TIEMPO POSITIVO POR UNIDAD O -1.0 SI SE ACABA LA ENTRADA.
float leerTiempoUnitario(void);

//DEVUELVO LOS RECURSOS POR UNIDAD O -1 SI SE ACABA LA ENTRADA.
int leerRecursosUnitarios(void);

//SUMO EL TIEMPO DE FABRICACIÓN DE TODOS LOS PRODUCTOS DEL PEDIDO.
float calcularTiempoTotal(const int demanda[], const float tiempoUnitario[], int productosRegistrados);

//SUMO LOS RECURSOS QUE CONSUMIRÁN TODOS LOS PRODUCTOS DEL PEDIDO.
int calcularRecursosTotales(const int demanda[], const int recursosUnitarios[], int productosRegistrados);

//MUESTRO LOS TOTALES Y AVISO SI ALCANZAN EL TIEMPO Y LOS RECURSOS DISPONIBLES.
void mostrarResultadoPedido(float tiempoTotal, int recursosTotales, float tiempoDisponible, int recursosDisponibles);

//BUSCO EL NOMBRE Y DEVUELVO EL PRIMER ÍNDICE QUE COINCIDE, O -1 SI NO LO ENCUENTRO.
int buscarProducto(char nombresProductos[][20], int productosRegistrados, const char nombreBuscado[]);

//ELIMINO EL PRODUCTO DE LA POSICIÓN INDICADA Y DEVUELVO CUÁNTOS QUEDAN.
int eliminarProducto(char nombresProductos[][20], int demanda[], float tiempoUnitario[], int recursosUnitarios[], int productosRegistrados, int posicionEliminar);

//LEO 1 PARA ELIMINAR O 0 PARA CONTINUAR; DEVUELVO -1 SI SE ACABA LA ENTRADA.
int leerOpcionEliminar(void);

//CAMBIO LA DEMANDA EN LA CASILLA CUYA DIRECCIÓN RECIBO.
void cambiarCantidad(int *p, int nueva);

//CAMBIO EL TIEMPO POR UNIDAD EN LA CASILLA CUYA DIRECCIÓN RECIBO.
void cambiarTiempo(float *p, float nueva);

//CAMBIO LOS RECURSOS POR UNIDAD EN LA CASILLA CUYA DIRECCIÓN RECIBO.
void cambiarCantidadRecursos(int *p, int nueva);

//CIERRO LA PROTECCIÓN DE LA CABECERA.
#endif

