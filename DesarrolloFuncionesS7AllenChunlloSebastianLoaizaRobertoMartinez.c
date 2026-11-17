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

//DESARROLLO DE FUNCIONES

//INCLUYO stdio.h PARA UTILIZAR printf Y scanf y getchar.
#include <stdio.h>
//INCLUYO string.h PARA DISPONER DE FUNCIONES QUE TRABAJAN CON TEXTOS Y COMPARAR CADENAS DE CARACTERES CON strcmp Y COPIARLOS CON strcpy
#include <string.h>
//INCLUYO LOS PROTOTIPOS PARA COMPROBAR QUE COINCIDAN CON LAS FUNCIONES QUE DEFINO AQUÍ.
#include "ArchivoCabeceraPrototiposFuncionesS7AllenChunlloSebastianLoaizaRobertoMartinez.h"

//MUESTRO EL MENÚ PRINCIPAL. LEO LA RESPUESTA APARTE, EN leerOpcionMenu.
void mostrarMenu(void){
    //ABRO EL RECUADRO DEL MENÚ.
    printf("\n=============================================================================\n");
    //MUESTRO EL TÍTULO DEL SISTEMA DE LA FÁBRICA.
    printf("       SISTEMA DE OPTIMIZACION DE FABRICA DE COMPONENTES ELECTRONICOS         \n");
    //SEPARO EL TÍTULO DE LAS OPCIONES.
    printf("=============================================================================\n");
    //MUESTRO LA OPCIÓN PARA REGISTRAR UN PEDIDO.
    printf("1. REGISTRAR INFORMACION EN EL SISTEMA\n");
    //MUESTRO LA OPCIÓN PARA SALIR DEL SISTEMA.
    printf("2. ABANDONAR EL SISTEMA\n");
    //CIERRO EL RECUADRO DEL MENÚ.
    printf("=============================================================================\n");
}

//LEO 1 PARA REGISTRAR UN PEDIDO O 2 PARA SALIR.
//DEVUELVO 0 SI scanf INDICA EOF ANTES DE LEER UNA OPCIÓN.
int leerOpcionMenu(void){
    //GUARDO EL NÚMERO ELEGIDO POR EL USUARIO.
    int seleccionUsuario = 0;
    //GUARDO CUÁNTOS DATOS PUDO LEER scanf; ESPERO UNO.
    int lectura = 0;
    //USO int PARA GUARDAR UN CARÁCTER O EL VALOR ESPECIAL EOF.
    int caracter;
    //HAGO AL MENOS UN INTENTO Y REPITO MIENTRAS LA OPCIÓN SEA INVÁLIDA.
    do
    {
        //PIDO AL USUARIO QUE ESCRIBA UNA OPCIÓN DEL MENÚ.
        printf("INGRESE UNA OPCION PARA CONTINUAR\n");
        //LEO UN ENTERO Y PASO SU DIRECCIÓN PARA QUE scanf LO PUEDA GUARDAR.
        lectura = scanf("%d", &seleccionUsuario);
        //COMPRUEBO SI SE ACABÓ LA ENTRADA O HUBO UN ERROR ANTES DE LEER LA OPCIÓN.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER UNA OPCIÓN.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO 0 COMO AVISO PARA main; LAS OPCIONES VÁLIDAS SON 1 Y 2.
            return 0;
        }
        //COMPRUEBO SI scanf NO PUDO CONVERTIR LA ENTRADA EN UN ENTERO.
        else if (lectura != 1)
        {
            //INDICO CUÁLES SON LAS OPCIONES PERMITIDAS.
            printf("OPCION INVALIDADA, INGRESE UNA OPCION VALIDA 1 O 2 PARA CONTINUAR\n");
            //DESCARTO EL TEXTO INVÁLIDO HASTA EL SALTO DE LÍNEA O EOF.
            while ((caracter = getchar()) != '\n' && caracter != EOF)
            {
                //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
            }
        }
        //COMPRUEBO SI EL ENTERO QUE LEÍ QUEDA FUERA DEL RANGO DE 1 A 2.
        else if (seleccionUsuario < 1 || seleccionUsuario > 2)
        {
            //PIDO QUE INTENTE DE NUEVO CON UNA OPCIÓN DEL MENÚ.
            printf("OPCION INVALIDADA, INTENTE DE NUEVO\n");
        }
        //REPITO SI FALLÓ LA CONVERSIÓN O SI EL NÚMERO NO ES 1 NI 2.
    } while (lectura != 1 || seleccionUsuario < 1 || seleccionUsuario > 2);
    //DEVUELVO LA OPCIÓN VÁLIDA PARA QUE main DECIDA QUÉ HACER.
    return seleccionUsuario;
}

//LEO EL TIEMPO DISPONIBLE DE LA FÁBRICA.
//DEVUELVO -1.0 SI scanf INDICA EOF ANTES DE LEER EL DATO.
float leerTiempoDisponible(void){
    //RESERVO UNA VARIABLE PARA GUARDAR EL TIEMPO DISPONIBLE.
    float tiempoLeido = 0.0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //PIDO EL TIEMPO DISPONIBLE ANTES DE CADA INTENTO.
        printf("INGRESE EL TIEMPO DISPONIBLE DE LA FABRICA DE COMPONENTES ELECTRONICOS DISPONIBLE\n");
        //INTENTO LEER UN NÚMERO QUE PUEDE TENER DECIMALES Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%f", &tiempoLeido);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1.0 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1.0;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI EL TIEMPO ES NEGATIVO.
        if (lectura != 1 || tiempoLeido < 0)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("DATOS DE TIEMPO INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI EL TIEMPO ES NEGATIVO.
    } while (lectura != 1 || tiempoLeido < 0);
    //DEVUELVO EL TIEMPO DISPONIBLE ACEPTADO.
    return tiempoLeido;
}

//LEO LOS RECURSOS DISPONIBLES DE LA FÁBRICA.
//DEVUELVO -1 SI scanf INDICA EOF ANTES DE LEER EL DATO.
int leerRecursosDisponibles(void){
    //RESERVO UNA VARIABLE PARA GUARDAR LOS RECURSOS DISPONIBLES.
    int recursosLeidos = 0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //PIDO LOS RECURSOS DISPONIBLES ANTES DE CADA INTENTO.
        printf("INGRESE LOS RECURSOS DISPONIBLES DE LA FABRICA DE COMPONENTES ELECTRONICOS DISPONIBLE\n");
        //INTENTO LEER UN NÚMERO ENTERO Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%d", &recursosLeidos);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI LA CANTIDAD ES NEGATIVA.
        if (lectura != 1 || recursosLeidos < 0)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("DATOS DE RECURSOS DISPONIBLES INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI LA CANTIDAD ES NEGATIVA.
    } while (lectura != 1 || recursosLeidos < 0);
    //DEVUELVO LA CANTIDAD DE RECURSOS DISPONIBLES.
    return recursosLeidos;
}

//RECIBO LA DIRECCIÓN DEL ARREGLO DONDE DEBO GUARDAR EL NOMBRE.
//DEVUELVO 1 SI LEÍ UNA PALABRA O -1 SI scanf DEVUELVE EOF.
int leerNombreProducto(char nombre[20]){
    //GUARDO EL RESULTADO DE scanf PARA SABER SI LEYÓ LA PALABRA.
    int lectura = 0;
    //USO int PORQUE getchar PUEDE DEVOLVER UN CARÁCTER O EOF.
    int caracter = 0;
    //INTENTO LEER EL NOMBRE Y REPITO SI LA CONVERSIÓN FALLA.
    do
    {
        //LEO HASTA 19 CARACTERES DE UNA PALABRA Y DEJO ESPACIO PARA EL FINAL DEL TEXTO.
        //scanf ESCRIBE DIRECTAMENTE EN EL ARREGLO RECIBIDO; nombre YA APUNTA A ESE ESPACIO.
        lectura = scanf("%19s", nombre);
        //COMPRUEBO SI NO PUDE LEER EL NOMBRE PORQUE scanf DEVOLVIÓ EOF.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL NOMBRE.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1 PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA PARA QUE NO PASE A LA SIGUIENTE PREGUNTA.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //COMPRUEBO SI scanf NO PUDO GUARDAR UNA PALABRA.
        if (lectura != 1)
        {
            //AVISO QUE HAY QUE VOLVER A INTENTAR LA LECTURA.
            printf("DATOS DE NOMBRES DE PRODUCTOS INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO MIENTRAS scanf NO HAYA LEÍDO UNA PALABRA.
    } while (lectura != 1);
    //DEVUELVO 1 PARA CONFIRMAR LA LECTURA; EL TEXTO YA QUEDÓ EN EL ARREGLO RECIBIDO.
    return 1;
}

//LEO CUÁNTAS UNIDADES SE PIDEN DE UN PRODUCTO.
//DEVUELVO -1 SI scanf INDICA EOF ANTES DE LEER EL DATO.
int leerDemanda(void){
    //RESERVO UNA VARIABLE PARA GUARDAR LA DEMANDA DEL PRODUCTO.
    int demandaLeida = 0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //INTENTO LEER UN NÚMERO ENTERO Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%d", &demandaLeida);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI LA DEMANDA ES NEGATIVA.
        if (lectura != 1 || demandaLeida < 0)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("DATOS DE DEMANDA DE PRODUCTOS INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI LA DEMANDA ES NEGATIVA.
    } while (lectura != 1 || demandaLeida < 0);
    //DEVUELVO LA DEMANDA ACEPTADA.
    return demandaLeida;
}

//LEO EL TIEMPO NECESARIO PARA FABRICAR UNA UNIDAD.
//DEVUELVO -1.0 SI scanf INDICA EOF ANTES DE LEER EL DATO.
float leerTiempoUnitario(void){
    //RESERVO UNA VARIABLE PARA GUARDAR EL TIEMPO POR UNIDAD.
    float tiempoUnitarioLeido = 0.0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //INTENTO LEER UN NÚMERO QUE PUEDE TENER DECIMALES Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%f", &tiempoUnitarioLeido);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1.0 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI EL TIEMPO ES CERO O NEGATIVO.
        if (lectura != 1 || tiempoUnitarioLeido <= 0)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("DATOS DE TIEMPO UNITARIO INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI EL TIEMPO ES CERO O NEGATIVO.
    } while (lectura != 1 || tiempoUnitarioLeido <= 0);
    //DEVUELVO EL TIEMPO POR UNIDAD ACEPTADO.
    return tiempoUnitarioLeido;
}

//LEO CUÁNTOS RECURSOS USA UNA UNIDAD DEL PRODUCTO.
//DEVUELVO -1 SI scanf INDICA EOF ANTES DE LEER EL DATO.
int leerRecursosUnitarios(void){
    //RESERVO UNA VARIABLE PARA GUARDAR LOS RECURSOS POR UNIDAD.
    int recursosUnitariosLeidos = 0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //INTENTO LEER UN NÚMERO ENTERO Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%d", &recursosUnitariosLeidos);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI LA CANTIDAD ES NEGATIVA.
        if (lectura != 1 || recursosUnitariosLeidos < 0)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("DATOS DE RECURSOS POR UNIDAD INVALIDADOS, INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI LA CANTIDAD ES NEGATIVA.
    } while (lectura != 1 || recursosUnitariosLeidos < 0);
    //DEVUELVO LA CANTIDAD DE RECURSOS POR UNIDAD.
    return recursosUnitariosLeidos;                   
}

//CALCULO EL TIEMPO DEL PEDIDO COMPLETO SIN MODIFICAR LOS ARREGLOS RECIBIDOS. CONST = VARIABLES QUE NO SE PUEDEN MODIFICAR NI REASIGNAR UNA VEZ QUE YA SON INICIALIZADAS
float calcularTiempoTotal(const int demanda[], const float tiempoUnitario[], int productosRegistrados){
    //EMPIEZO LA SUMA EN CERO CADA VEZ QUE LLAMO A LA FUNCIÓN.
    float total = 0.0;
    //RECORRO SOLO LOS PRODUCTOS QUE SIGUEN REGISTRADOS.
    for (int i = 0; i < productosRegistrados; i++)
    {
        //MULTIPLICO LAS UNIDADES PEDIDAS POR EL TIEMPO DE UNA UNIDAD Y SUMO EL RESULTADO.
        total = total + (demanda[i] * tiempoUnitario[i]);
    }
    //DEVUELVO EL TIEMPO NECESARIO PARA FABRICAR TODO EL PEDIDO.
    return total;
}

//CALCULO CUÁNTOS RECURSOS NECESITA EL PEDIDO SIN MODIFICAR LOS ARREGLOS.
int calcularRecursosTotales(const int demanda[], const int recursosUnitarios[], int productosRegistrados){
    //EMPIEZO EN CERO PARA CALCULAR EL TOTAL CON LOS DATOS ACTUALES.
    int total = 0;
    //RECORRO LOS PRODUCTOS REGISTRADOS CON EL MISMO ÍNDICE EN AMBOS ARREGLOS.
    for (int i = 0; i < productosRegistrados; i++)
    {
        //MULTIPLICO LA DEMANDA POR LOS RECURSOS DE UNA UNIDAD Y SUMO EL RESULTADO.
        total = total + (demanda[i] * recursosUnitarios[i]);
    }
    //DEVUELVO LOS RECURSOS NECESARIOS PARA FABRICAR TODO EL PEDIDO.
    return total;
}

//MUESTRO LOS TOTALES Y LOS COMPARO CON LA CAPACIDAD DE LA FÁBRICA.
void mostrarResultadoPedido(float tiempoTotal, int recursosTotales, float tiempoDisponible, int recursosDisponibles){
    //MUESTRO EL TIEMPO TOTAL CON DOS DECIMALES.
    printf("EL PEDIDO PROPUESTO POR EL USUARIO REQUIERE DE UN TIEMPO TOTAL DE: %.2f\n", tiempoTotal);
    //MUESTRO COMO ENTERO EL TOTAL DE RECURSOS.
    printf("EL PEDIDO PROPUESTO POR EL USUARIO REQUIERE DE UNA CANTIDAD DE RECURSOS TOTALES DE: %d\n", recursosTotales);
    
    //COMPRUEBO CON && QUE ALCANCEN EL TIEMPO Y LOS RECURSOS A LA VEZ.
    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles)
    {
        //CONFIRMO QUE LA FÁBRICA PUEDE CUBRIR EL PEDIDO COMPLETO.
        printf("LA FABRICA DE COMPONENTES ELECTRONICOS PUEDE CUBRIR TODO EL PEDIDO\n");
    }
    //SI FALLA AL MENOS UNA COMPARACIÓN, LA FÁBRICA NO PUEDE CUBRIR EL PEDIDO.
    else
    {
        //AVISO QUE EL TIEMPO O LOS RECURSOS DISPONIBLES SON INSUFICIENTES.
        printf("LA FABRICA LASTIMOSAMENTE NO PUEDE CUBRIR TODO EL PEDIDO\n");
    }
}

//BUSCO UN NOMBRE ENTRE LOS PRODUCTOS REGISTRADOS.
//DEVUELVO EL ÍNDICE DE LA PRIMERA COINCIDENCIA O -1 SI NO LO ENCUENTRO.
int buscarProducto(char nombresProductos[][20], int productosRegistrados, const char nombreBuscado[]){
    //RESERVO EL ÍNDICE CON EL QUE VOY A RECORRER LOS NOMBRES.
    int i = 0;
    //RECORRO LAS FILAS OCUPADAS DESDE EL ÍNDICE 0.
    for (i = 0; i < productosRegistrados; i++)
    {
        //COMPARO LOS NOMBRES RESPETANDO MAYÚSCULAS Y MINÚSCULAS; 0 SIGNIFICA QUE SON IGUALES.
        if (strcmp(nombresProductos[i], nombreBuscado) == 0)
        {
            //DEVUELVO EL ÍNDICE EN CUANTO ENCUENTRO EL NOMBRE.
            return i;
        }
    }
    //DEVUELVO -1 DESPUÉS DE REVISAR TODA LA LISTA SIN ENCONTRAR EL NOMBRE.
    return - 1;
}

//RECIBO UN ÍNDICE VÁLIDO Y DESPLAZO LAS FILAS SIGUIENTES PARA CUBRIR SU ESPACIO.
int eliminarProducto(char nombresProductos[][20], int demanda[], float tiempoUnitario[], int recursosUnitarios[], int productosRegistrados, int posicionEliminar){
    //EMPIEZO EN LA FILA QUE QUIERO QUITAR Y SOLO COPIO SI EXISTE UNA FILA SIGUIENTE.
    for (int i = posicionEliminar; i + 1 < productosRegistrados; i++)
    {
        //COPIO LA DEMANDA DEL PRODUCTO SIGUIENTE A LA CASILLA ACTUAL.
        demanda[i] = demanda[i + 1];
        //COPIO CON strcpy EL NOMBRE COMPLETO, INCLUIDO EL FINAL DEL TEXTO.
        strcpy(nombresProductos[i], nombresProductos[i + 1]);
        //MUEVO EL TIEMPO POR UNIDAD JUNTO CON EL NOMBRE Y LA DEMANDA.
        tiempoUnitario[i] = tiempoUnitario[i + 1];
        //MUEVO LOS RECURSOS POR UNIDAD PARA MANTENER JUNTOS LOS CUATRO DATOS DEL PRODUCTO.
        recursosUnitarios[i] = recursosUnitarios[i + 1];
    }
    //DEVUELVO UN PRODUCTO MENOS, INCLUSO SI QUITÉ EL ÚLTIMO Y NO HUBO FILAS QUE MOVER.
    //main GUARDA ESTE NÚMERO PARA QUE EL SIGUIENTE CÁLCULO IGNORE LA ÚLTIMA CASILLA.
    return productosRegistrados - 1;
}

//LEO SI EL USUARIO QUIERE ELIMINAR UN PRODUCTO: 1 PARA SÍ, 0 PARA NO.
//DEVUELVO -1 SI scanf INDICA EOF ANTES DE LEER EL DATO.
int leerOpcionEliminar(void){
    //RESERVO UNA VARIABLE PARA GUARDAR LA RESPUESTA DEL USUARIO.
    int opcionLeida = 0;
    //GUARDO EL RESULTADO DE scanf; 1 INDICA QUE CONVIRTIÓ EL DATO.
    int lectura = 0;
    //USO int PARA GUARDAR LO QUE DEVUELVE getchar, INCLUIDO EOF.
    int caracter = 0;
    //HAGO AL MENOS UN INTENTO DE LECTURA Y REPITO SI EL DATO ES INVÁLIDO.
    do
    {
        //PIDO LA RESPUESTA DEL USUARIO ANTES DE CADA INTENTO.
        printf("¿DESEA ELIMINAR UN PRODUCTO DE LA LISTA? ESCOJA 1 PARA SI, 0 PARA NO\n");
        //INTENTO LEER UN NÚMERO ENTERO Y LE PASO A scanf LA DIRECCIÓN DONDE DEBE GUARDARLO.
        lectura = scanf("%d", &opcionLeida);
        //COMPRUEBO SI scanf DEVOLVIÓ EOF ANTES DE LEER EL DATO.
        if (lectura == EOF)
        {
            //AVISO QUE NO PUDE LEER EL DATO.
            printf("NO SE REGISTRO NINGUNA LECTURA. PROGRAMA FINALIZADO\n");
            //DEVUELVO -1 COMO AVISO PARA QUE main PUEDA TERMINAR.
            return -1;
        }
        //DESCARTO EL RESTO DE LA LÍNEA HASTA UN SALTO DE LÍNEA O EOF.
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            //getchar LEE Y RETIRA UN CARÁCTER EN CADA COMPROBACIÓN.
        }
        //MARCO EL DATO COMO INVÁLIDO SI FALLÓ LA CONVERSIÓN O SI LA OPCIÓN NO ES 0 NI 1.
        if (lectura != 1 || opcionLeida < 0 || opcionLeida > 1)
        {
            //MUESTRO EL ERROR Y PIDO AL USUARIO QUE INTENTE DE NUEVO.
            printf("OPCION INVALIDADA. INTENTE DE NUEVO\n");
        }
        //REPITO SI scanf NO CONVIRTIÓ EL DATO O SI LA OPCIÓN NO ES 0 NI 1.
    } while (lectura != 1 || opcionLeida < 0 || opcionLeida > 1);
    //DEVUELVO LA OPCIÓN 0 O 1 PARA QUE main DECIDA SI DEBE BORRAR.
    return opcionLeida;
}

//PUNTEROS
//RECIBO LA DIRECCIÓN DE UNA CASILLA DE DEMANDA Y LA NUEVA CANTIDAD PEDIDA.
void cambiarCantidad(int *p, int nueva){
    //USO *p PARA ESCRIBIR EL NUEVO VALOR EN LA CASILLA ORIGINAL.
    *p = nueva;
}

//RECIBO LA DIRECCIÓN DE UNA CASILLA float Y EL NUEVO TIEMPO POR UNIDAD.
void cambiarTiempo(float *p, float nueva){
    //ESCRIBO EL NUEVO TIEMPO EN LA CASILLA A LA QUE APUNTA p.
    *p = nueva;
}

//RECIBO LA DIRECCIÓN DE UNA CASILLA DE RECURSOS Y LA NUEVA CANTIDAD POR UNIDAD.
void cambiarCantidadRecursos(int *p, int nueva){
    //ESCRIBO LOS NUEVOS RECURSOS EN LA CASILLA A LA QUE APUNTA p.
    *p = nueva;
}