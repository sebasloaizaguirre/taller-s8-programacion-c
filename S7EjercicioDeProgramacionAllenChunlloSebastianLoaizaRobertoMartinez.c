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

//INCLUYO stdio.h PARA UTILIZAR printf Y scanf y getchar.
#include <stdio.h>
//INCLUYO string.h PARA DISPONER DE FUNCIONES QUE TRABAJAN CON TEXTOS Y COMPARAR CADENAS DE CARACTERES
#include <string.h>
//INCLUYO LOS PROTOTIPOS PARA LLAMAR A LAS FUNCIONES DESDE main.
#include "ArchivoCabeceraPrototiposFuncionesS7AllenChunlloSebastianLoaizaRobertoMartinez.h"

//ORGANIZO EL REGISTRO, LA EDICIÓN Y LA ELIMINACIÓN DE PRODUCTOS. INICIO DE PROGRAMA
int main (void){
    //RESERVO CINCO FILAS DE 20 CASILLAS PARA LOS NOMBRES.
    //USO EL MISMO ÍNDICE EN LOS CUATRO ARREGLOS PARA RELACIONAR LOS DATOS DE CADA PRODUCTO.
    char nombresProductos[5][20];
    //GUARDO CUÁNTAS UNIDADES SE PIDEN DE CADA PRODUCTO.
    int demanda[5];
    //GUARDO EL TIEMPO QUE TARDA EN FABRICARSE UNA UNIDAD DE CADA PRODUCTO.
    float tiempoUnitario[5];
    //GUARDO CUÁNTOS RECURSOS USA UNA UNIDAD DE CADA PRODUCTO.
    int recursosUnitarios[5];
    //CUENTO CUÁNTOS PRODUCTOS TIENEN TODOS SUS DATOS REGISTRADOS.
    int productosRegistrados = 0;
    //GUARDO EL TIEMPO QUE TIENE DISPONIBLE LA FÁBRICA.
    float tiempoDisponible = 0.0;
    //GUARDO LOS RECURSOS QUE TIENE DISPONIBLES LA FÁBRICA.
    int recursosDisponibles = 0;
    //GUARDO LA OPCIÓN DEL MENÚ: 1 PARA REGISTRAR, 2 PARA SALIR.
    int seleccionUsuario = 0;
    //GUARDO EL TIEMPO NECESARIO PARA FABRICAR EL PEDIDO COMPLETO.
    float tiempoTotal = 0.0;
    //GUARDO LOS RECURSOS NECESARIOS PARA FABRICAR EL PEDIDO COMPLETO.
    int recursosTotales = 0;
    //RESERVO ESPACIO PARA EL NOMBRE QUE QUIERO BUSCAR PARA EDITAR.
    char nombreBuscado[20]; 
    //GUARDO EL ÍNDICE DEL PRODUCTO QUE VOY A EDITAR; -1 INDICA QUE NO LO ENCONTRÉ.
    int posicion = -1;
    //GUARDO LA NUEVA DEMANDA ANTES DE ACTUALIZAR SU CASILLA.
    int nuevaDemanda = 0;
    //GUARDO EL NUEVO TIEMPO POR UNIDAD ANTES DE ACTUALIZAR SU CASILLA.
    float nuevoTiempo = 0.0;
    //GUARDO LOS NUEVOS RECURSOS POR UNIDAD ANTES DE ACTUALIZAR SU CASILLA.
    int cantidadNuevaRecursos = 0;
    //GUARDO LA RESPUESTA SOBRE EL BORRADO: 1 PARA SÍ, 0 PARA NO.
    int opcionUsuarioEliminarLista = 0;
    //RESERVO ESPACIO PARA EL NOMBRE DEL PRODUCTO QUE QUIERO ELIMINAR.
    char nombreProductoEliminar[20];
    //GUARDO EL ÍNDICE DEL PRODUCTO QUE VOY A ELIMINAR.
    int posicionEliminar = -1;

    //VUELVO AL MENÚ DESPUÉS DE PROCESAR UN PEDIDO, HASTA QUE EL USUARIO ELIJA SALIR.
    do
    {
        //RECORRO LAS CINCO CASILLAS DE DEMANDA PARA LIMPIAR LOS DATOS DEL PEDIDO ANTERIOR.
        for (int i = 0; i < 5; i++)
        {
            //DEJO EN CERO LA DEMANDA DE ESTA CASILLA.
            demanda[i] = 0;
        }
        //RECORRO LAS CINCO CASILLAS DE TIEMPO POR UNIDAD.
        for (int i = 0; i < 5; i++)
        {
            //DEJO EN CERO EL TIEMPO POR UNIDAD DE ESTA CASILLA.
            tiempoUnitario[i]= 0.0;
        }
        //RECORRO LAS CINCO CASILLAS DE RECURSOS POR UNIDAD.
        for (int i = 0; i < 5; i++)
        {
            //DEJO EN CERO LOS RECURSOS POR UNIDAD DE ESTA CASILLA.
            recursosUnitarios[i] = 0;
        }
        //REINICIO EL CONTADOR ANTES DE REGISTRAR OTRO PEDIDO.
        productosRegistrados = 0;
        //REINICIO EL TIEMPO DISPONIBLE ANTES DE PEDIRLO DE NUEVO.
        tiempoDisponible = 0.0;
        //REINICIO LOS RECURSOS DISPONIBLES ANTES DE PEDIRLOS DE NUEVO.
        recursosDisponibles = 0;
        //DEJO LA OPCIÓN EN CERO ANTES DE LEER LA RESPUESTA DEL MENÚ.
        seleccionUsuario = 0;
        //REINICIO EL TIEMPO TOTAL DEL PEDIDO.
        tiempoTotal = 0.0;
        //REINICIO LOS RECURSOS TOTALES DEL PEDIDO.
        recursosTotales = 0;
        //DEJO LA BÚSQUEDA PARA EDITAR SIN UN ÍNDICE ASIGNADO.
        posicion = -1;
        //LIMPIO LA DEMANDA DE LA EDICIÓN ANTERIOR.
        nuevaDemanda = 0;
        //LIMPIO EL TIEMPO DE LA EDICIÓN ANTERIOR.
        nuevoTiempo = 0.0;
        //LIMPIO LOS RECURSOS DE LA EDICIÓN ANTERIOR.
        cantidadNuevaRecursos = 0;
        //REINICIO LA RESPUESTA DE BORRADO.
        opcionUsuarioEliminarLista = 0;
        //DEJO LA BÚSQUEDA PARA BORRAR SIN UN ÍNDICE ASIGNADO.
        posicionEliminar = -1;
        
        //LLAMO A LA FUNCIÓN QUE MUESTRA EL TÍTULO Y LAS OPCIONES DEL MENÚ.
        mostrarMenu();

        //LEO LA OPCIÓN QUE EL USUARIO ELIGE EN EL MENÚ.
        seleccionUsuario = leerOpcionMenu();

        //COMPRUEBO SI LA FUNCIÓN DEVOLVIÓ 0 PORQUE SE ACABÓ LA ENTRADA.
        if (seleccionUsuario == 0)
        {
            //TERMINO EL PROGRAMA SI NO PUDE LEER UNA OPCIÓN.
            return 0;
        }
        
        //INICIO EL REGISTRO CUANDO EL USUARIO ESCOGE LA OPCIÓN 1.
        if (seleccionUsuario == 1)
        {
            //PIDO Y GUARDO EL TIEMPO QUE TIENE DISPONIBLE LA FÁBRICA.
            tiempoDisponible = leerTiempoDisponible();
            //COMPRUEBO SI LA LECTURA DEL TIEMPO TERMINÓ SIN UN DATO.
            if (tiempoDisponible == -1.0)
            {
                //TERMINO ANTES DE USAR UN TIEMPO QUE NO SE LEYÓ.
                return 0;
            }
            
            //PIDO Y GUARDO LOS RECURSOS QUE TIENE DISPONIBLES LA FÁBRICA.
            recursosDisponibles = leerRecursosDisponibles();
            //COMPRUEBO SI LA LECTURA DE RECURSOS TERMINÓ SIN UN DATO.
            if (recursosDisponibles == -1)
            {
                //TERMINO ANTES DE REGISTRAR PRODUCTOS CON DATOS INCOMPLETOS.
                return 0;
            }
            
            //SEPARO LOS DATOS DE LA FÁBRICA DEL REGISTRO DE PRODUCTOS.
            printf("\n==================================================================================\n");
            
            //REGISTRO LOS CUATRO DATOS DE UN PRODUCTO EN CADA VUELTA DEL for.
            for (int i = 0; i < 5; i++)
            {
                //MUESTRO EL NÚMERO DEL PRODUCTO DESDE 1 PARA EL USUARIO.
                printf("INGRESE EL NOMBRE DEL PRODUCTO %d\n", i + 1);
                //PASO LA FILA nombresProductos[i] PARA QUE LA FUNCIÓN ESCRIBA EL NOMBRE AHÍ.
                //COMPRUEBO SI DEVOLVIÓ -1 PORQUE NO PUDO LEER EL NOMBRE.
                if (leerNombreProducto(nombresProductos[i]) == -1)
                {
                    //TERMINO SI NO PUDE LEER EL NOMBRE DEL PRODUCTO.
                    return 0;
                }
                
                //PIDO LA DEMANDA MOSTRANDO EL NOMBRE QUE ACABO DE GUARDAR.
                printf("INGRESE LA DEMANDA DE %s\n", nombresProductos[i]);
                //GUARDO LA DEMANDA LEÍDA EN LA CASILLA DEL PRODUCTO ACTUAL.
                demanda[i] = leerDemanda();
                //COMPRUEBO SI -1 INDICA QUE SE ACABÓ LA ENTRADA.
                if (demanda[i] == -1)
                {
                    //TERMINO ANTES DE PEDIR OTRO DATO DEL PRODUCTO.
                    return 0;
                }
                
                //PIDO EL TIEMPO NECESARIO PARA FABRICAR UNA UNIDAD DEL PRODUCTO.
                printf("INGRESE LA CANTIDAD DE TIEMPO QUE SE REQUIERA PARA LA FABRICACION DEL PRODUCTO %s\n", nombresProductos[i]);
                //GUARDO EL TIEMPO POR UNIDAD EN LA MISMA POSICIÓN QUE SU DEMANDA.
                tiempoUnitario[i] = leerTiempoUnitario();
                //COMPRUEBO SI LA FUNCIÓN AVISÓ QUE NO HAY MÁS DATOS DE ENTRADA.
                if (tiempoUnitario[i] == -1)
                {
                    //TERMINO ANTES DE PEDIR LOS RECURSOS POR UNIDAD.
                    return 0;
                }
                
                //PIDO CUÁNTOS RECURSOS USA UNA UNIDAD DEL PRODUCTO ACTUAL.
                printf("INGRESE LA CANTIDAD DE RECURSOS POR UNIDAD DEL PRODUCTO %s\n", nombresProductos[i]);
                //GUARDO LOS RECURSOS POR UNIDAD EN LA CASILLA CORRESPONDIENTE.
                recursosUnitarios[i] = leerRecursosUnitarios();
                //COMPRUEBO SI LA LECTURA SE INTERRUMPIÓ ANTES DE COMPLETAR EL PRODUCTO.
                if (recursosUnitarios[i] == -1)
                {
                    //TERMINO SIN CONTAR UN PRODUCTO INCOMPLETO.
                    return 0;
                }
                //SUMO UNO AL CONTADOR PORQUE YA GUARDÉ LOS CUATRO DATOS.
                productosRegistrados = productosRegistrados + 1;
            }

            //CALCULO EL TIEMPO TOTAL USANDO LAS DEMANDAS Y LOS TIEMPOS POR UNIDAD.
            tiempoTotal = calcularTiempoTotal(demanda, tiempoUnitario, productosRegistrados);

            //CALCULO LOS RECURSOS TOTALES USANDO LAS DEMANDAS Y LOS RECURSOS POR UNIDAD.
            recursosTotales = calcularRecursosTotales(demanda, recursosUnitarios, productosRegistrados);

            //MUESTRO LOS TOTALES Y SI LA FÁBRICA PUEDE CUBRIR EL PEDIDO.
            mostrarResultadoPedido(tiempoTotal, recursosTotales, tiempoDisponible, recursosDisponibles);

            //SEPARO EL RESULTADO INICIAL DE LA BÚSQUEDA PARA EDITAR.
            printf("\n==================================================================================\n");
            
            //PIDO EL NOMBRE DEL PRODUCTO QUE EL USUARIO QUIERE EDITAR.
            printf("INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA BUSCAR\n");
            //GUARDO EL TEXTO EN nombreBuscado; -1 AVISA QUE NO SE PUDO LEER.
            if (leerNombreProducto(nombreBuscado) == -1)
            {
                //TERMINO SI NO TENGO UN NOMBRE PARA BUSCAR.
                return 0;
            }
            
            //GUARDO EN posicion EL ÍNDICE QUE DEVUELVE LA BÚSQUEDA.
            posicion = buscarProducto(nombresProductos, productosRegistrados, nombreBuscado);
            //COMPRUEBO SI SE REVISÓ LA LISTA SIN ENCONTRAR EL NOMBRE.
            if (posicion == -1)
            {
                //AVISO QUE EL PRODUCTO NO EXISTE EN EL PEDIDO ACTUAL.
                printf("PRODUCTO NO HALLADO\n");
            }

            //SI ENCUENTRO EL PRODUCTO, USO SU MISMO ÍNDICE PARA CAMBIAR SUS CUATRO DATOS.
            else
            {
                //MUESTRO EL NOMBRE Y SUMO UNO AL ÍNDICE PARA MOSTRAR EL LUGAR EN LA LISTA.
                printf("NOMBRE PRODUCTO HALLADO CON IDENTIFICADOR: %s, EN LA POSICION: %d\n", nombresProductos[posicion], posicion + 1);

                //PIDO LA NUEVA CANTIDAD DE UNIDADES DEL PRODUCTO ENCONTRADO.
                printf("INGRESE LA CANTIDAD DE LA NUEVA DEMANDA DEL PRODUCTO %s:\n", nombresProductos[posicion]);

                //LEO LA NUEVA DEMANDA CON LA MISMA FUNCIÓN DEL REGISTRO.
                nuevaDemanda = leerDemanda();

                //COMPRUEBO SI LA LECTURA TERMINÓ SIN UNA NUEVA DEMANDA.
                if (nuevaDemanda == -1)
                {
                    //TERMINO ANTES DE GUARDAR UN VALOR DE AVISO COMO DEMANDA.
                    return 0;
                }
                
                //PASO LA DIRECCIÓN DE demanda[posicion] PARA CAMBIAR SOLO ESA CASILLA.
                cambiarCantidad(&demanda[posicion], nuevaDemanda);

                //PIDO EL NUEVO TIEMPO QUE TARDA EN FABRICARSE UNA UNIDAD.
                printf("INGRESE LA CANTIDAD NUEVA DE TIEMPO QUE SE REQUIERA PARA LA FABRICACION DEL PRODUCTO %s\n", nombresProductos[posicion]);

                //LEO EL NUEVO TIEMPO POR UNIDAD CON LA VALIDACIÓN DEL REGISTRO.
                nuevoTiempo = leerTiempoUnitario();

                //COMPRUEBO SI LA FUNCIÓN DEVOLVIÓ EL AVISO DE FIN DE ENTRADA.
                if (nuevoTiempo == -1.0)
                {
                    //TERMINO SI NO PUDE LEER EL NUEVO TIEMPO.
                    return 0;
                }
                
                //PASO LA DIRECCIÓN DE tiempoUnitario[posicion] PARA GUARDAR EL NUEVO TIEMPO.
                cambiarTiempo(&tiempoUnitario[posicion], nuevoTiempo);

                //PIDO LOS NUEVOS RECURSOS QUE USA CADA UNIDAD DEL PRODUCTO.
                printf("INGRESE LA CANTIDAD NUEVA DE RECURSOS POR UNIDAD DEL PRODUCTO %s\n", nombresProductos[posicion]);

                //LEO LOS NUEVOS RECURSOS POR UNIDAD Y CONSERVO EL DATO HASTA VALIDAR LA LECTURA.
                cantidadNuevaRecursos = leerRecursosUnitarios();
                //COMPRUEBO SI LA FUNCIÓN DEVOLVIÓ -1 PORQUE NO PUDO LEER EL DATO.
                if (cantidadNuevaRecursos == -1)
                {
                    //TERMINO ANTES DE GUARDAR UN VALOR DE AVISO COMO RECURSOS.
                    return 0;
                }
                
                //PASO LA DIRECCIÓN DE recursosUnitarios[posicion] PARA CAMBIAR ESA CASILLA.
                cambiarCantidadRecursos(&recursosUnitarios[posicion], cantidadNuevaRecursos);

                //PIDO EL NUEVO NOMBRE DEL PRODUCTO.
                printf("INGRESE EL NUEVO NOMBRE DEL PRODUCTO\n");
                //PASO LA FILA DEL PRODUCTO ENCONTRADO PARA REESCRIBIR SU NOMBRE.
                //LA FUNCIÓN GUARDA EL TEXTO EN ESA FILA Y DEVUELVE UN NÚMERO PARA AVISAR CÓMO SALIÓ LA LECTURA.
                if (leerNombreProducto(nombresProductos[posicion]) == -1)
                {
                    //TERMINO SI NO PUDE LEER EL NUEVO NOMBRE.
                    return 0;
                }
                
                //RECALCULO EL TIEMPO CON LOS DATOS EDITADOS Y LA MISMA CANTIDAD DE PRODUCTOS.
                tiempoTotal = calcularTiempoTotal(demanda, tiempoUnitario, productosRegistrados);
                //RECALCULO LOS RECURSOS CON LAS NUEVAS CANTIDADES.
                recursosTotales = calcularRecursosTotales(demanda, recursosUnitarios, productosRegistrados);
                //MUESTRO EL RESULTADO ACTUALIZADO ANTES DE PREGUNTAR POR EL BORRADO.
                mostrarResultadoPedido(tiempoTotal, recursosTotales, tiempoDisponible, recursosDisponibles);
            }
            
            //SEPARO LA EDICIÓN DE LA OPCIÓN PARA ELIMINAR UN PRODUCTO.
            printf("\n==================================================================================\n");

            //PIDO AL USUARIO QUE ELIJA SI QUIERE ELIMINAR UN PRODUCTO.
            opcionUsuarioEliminarLista = leerOpcionEliminar();
            //COMPRUEBO SI SE ACABÓ LA ENTRADA ANTES DE LEER LA RESPUESTA.
            if (opcionUsuarioEliminarLista == -1)
            {
                //TERMINO SI NO HAY UNA RESPUESTA SOBRE EL BORRADO.
                return 0;
            }
            
            //PIDO EL NOMBRE PARA BORRAR SOLO SI EL USUARIO ELIGIÓ 1.
            if (opcionUsuarioEliminarLista == 1)
            {
                //SOLICITO EL NOMBRE DEL PRODUCTO QUE QUIERO RETIRAR DEL PEDIDO.
                printf("INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA ELIMINAR\n");
                //GUARDO EL NOMBRE EN nombreProductoEliminar PARA USARLO EN LA BÚSQUEDA.
                if ((leerNombreProducto(nombreProductoEliminar)) == -1)
                {
                    //TERMINO SI NO PUDE LEER EL NOMBRE PARA ELIMINAR.
                    return 0;
                }
                
                //BUSCO LA POSICIÓN DEL PRODUCTO QUE EL USUARIO ELIGIÓ PARA BORRAR.
                posicionEliminar = buscarProducto(nombresProductos, productosRegistrados, nombreProductoEliminar);
                
                //COMPRUEBO SI EL NOMBRE NO COINCIDE CON NINGÚN PRODUCTO REGISTRADO.
                if (posicionEliminar == -1)
                {
                    //AVISO QUE NO ENCONTRÉ EL PRODUCTO QUE SE QUERÍA ELIMINAR.
                    printf("PRODUCTO NO HALLADO\n");
                }
                //SI ENCUENTRO EL PRODUCTO, RETIRO SUS DATOS DEL PEDIDO.
                else
                {
                    //DESPLAZO LOS DATOS Y GUARDO LA NUEVA CANTIDAD DE PRODUCTOS QUE QUEDAN.
                    productosRegistrados = eliminarProducto(nombresProductos, demanda, tiempoUnitario, recursosUnitarios, productosRegistrados, posicionEliminar);

                    //RECALCULO EL TIEMPO USANDO SOLO LAS POSICIONES QUE SIGUEN EN EL PEDIDO.
                    tiempoTotal = calcularTiempoTotal(demanda, tiempoUnitario, productosRegistrados);
                    //RECALCULO LOS RECURSOS SIN INCLUIR EL PRODUCTO ELIMINADO.
                    recursosTotales = calcularRecursosTotales(demanda, recursosUnitarios, productosRegistrados);
                    //MUESTRO LOS TOTALES Y COMPRUEBO SI ALCANZA LA CAPACIDAD DISPONIBLE.
                    mostrarResultadoPedido(tiempoTotal, recursosTotales, tiempoDisponible, recursosDisponibles);
                }    
            }
        }
    //REPITO EL MENÚ MIENTRAS EL USUARIO NO ELIJA LA OPCIÓN 2.
    } while (seleccionUsuario != 2);
    //SEPARO EL MENSAJE DE CIERRE DEL RESTO DE LA SALIDA.
    printf("\n==================================================================================\n");
    //AVISO QUE EL USUARIO SALIÓ DEL SISTEMA.
    printf("SISTEMA FINALIZADO.\n");
}