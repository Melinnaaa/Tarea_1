#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct
{
    int totalCanciones;
    List* canciones;
    void* numeroLista;
} listaCanciones;

typedef struct
{
    void* nombre;
    int anyo;
    List* genero;
    void* artista;
    listaCanciones* listaReproduccion;
} cancion;


//Función que lee el archivo 
const char* get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret = (char*) malloc (100*sizeof(char));
    int ini_i = 0, i = 0;
    int j = 0;

    while(tmp[i+1] !='\0')
    {
        if(tmp[i]== '\"')
        {
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ',')
        {
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ',')
        {
            if(k==j) 
            {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) 
    {
       ret[i-ini_i] = 0;
       return ret;
    }

    return NULL;
}

cancion* guardarCanciones(FILE* canciones)
{
    char linea[1024];
    //fgets (linea, 1023, canciones);
    while (fgets (linea, 1023, canciones) != NULL) // Se lee la linea
    { 
        for(int i = 0 ; i < 5 ; i = i + 1) //Lee 5 veces, ya que una musica solo tiene 5 caracteristicas
        {
            char *aux = get_csv_field(linea, i); // Se obtiene el nombre
            printf("%s ", aux);
        }
        printf("\n");
    }  
}

/*
void importarCancion(listaCancion)
{

}

void exportarCancion(listaCancion)
{

}

void buscarCancionNombre(listaCancion)
{

}

void buscarCancionGenero(listaCancion)
{

}

void buscarCancionArtista(listaCancion)
{

}

void eliminarCancion(listaCancion)
{
    
}*/

int main ()
{
    FILE* canciones = fopen ("Canciones.csv", "r");
    int opcion;
    cancion* listaCancion = guardarCanciones(canciones);
    
    while(1)
    {
        printf("1.- Importar canciones.\n");
        printf("2.- Exportar canciones.\n");
        printf("3.- Buscar canción por nombre.\n");
        printf("4.- Buscar canción por género.\n");
        printf("5.- Buscar canción por artista.\n");
        printf("6.- Eliminar una canción.\n");
        printf("Seleccione una opción.\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            //importarCancion(listaCancion);
            printf("a\n");
        }
        else if (opcion == 2)
        {
            //exportarCancion(listaCancion);
            printf("b\n");
        }
        else if (opcion == 3)
        {
            //buscarCancionNombre(listaCancion);
            printf("c\n");
        }
        else if (opcion == 4)
        {
            //buscarCancionGenero(listaCancion);
            printf("d\n");
        }
        else if (opcion == 5)
        {
            //buscarCancionArtista(listaCancion);
            printf("e\n");
        }
        else if (opcion == 6)
        {
            //eliminarCancion(listaCancion);
            printf("f\n");
        }

        printf("¿Desea continuar?\n");
        printf("1- Si. / 2- NO.\n");
        scanf("%d", &opcion);
        if (opcion == 2)
        {
            break;
        }
    }

    return (0);
}