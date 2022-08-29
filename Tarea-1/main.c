#include <stdio.h>
#include "funciones.h"
#include "list.h"

void main()
{
  List* Personajes=createList();
  List* Items=createList();
  List* ItemConsumible=createList();
  List* ItemEquipable=createList();
  List* listaGlobal = createList();
  
  char* tipo[30];
  char* nombreI[30];
  char* nombreP[30];
  int nivel_o_cantidad;
  char archivo[99];
  
  int op;
  
  while(op!=10)
  {
    printf("1.-Importar ítems desde un archivo CSV\n");
    printf("2.-Exportar ítems CSV\n");
    printf("3.-Agregar ítem\n");//!!¡¡Importante!!¡¡
    printf("4.-Mostrar ítems equipables de un personaje\n");
    printf("5.-Mostrar ítems consumibles de un personaje\n");
    printf("6.-Eliminar ítem de un personaje\n");
    printf("7.-Eliminar ítem de todos los personajes\n");
    printf("8.-Mostrar nombres de los personajes\n");//!!¡¡Importante!!¡¡
    printf("9.-Mostrar todos los ítems\n");
    printf("10.-Salir\n");
    printf("\nIndique la ocpción: ");
    scanf("%d", &op);
    
    switch(op)
    {
      case 1: printf("\nIngrese el nombre del archivo: ");
              getchar();
              scanf("%s", archivo);
              ImportarItems(archivo, listaGlobal);
              break;  
      case 2: break;
      case 3: printf("\nIngrese el tipo de Item:\n");
              getchar();
              scanf("%30[^\n]s",tipo);
        
              printf("\nIngrese el nombre del Item:\n");
              getchar();
              scanf("%30[^\n]",nombreI);
        
              printf("\nIngrese el nivel o cantidad del Item:\n");
              getchar();
              scanf("%d",&nivel_o_cantidad);
        
              printf("\nIngrese el nombre del personaje al que le va agregar el Item:\n");
              getchar();
              scanf("%30[^\n]",nombreP);
        
              agregarItem(tipo,nombreI,nivel_o_cantidad,nombreP,listaGlobal);
              break;
      case 4: break;
      case 5: break;
      case 6: break;
      case 7: break;
      case 8: mostrarnombres();
              break;
      case 9: break;
      case 10: break;
    }
    printf("\n");
  }
  
}