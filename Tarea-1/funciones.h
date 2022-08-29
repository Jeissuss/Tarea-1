#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_csv_field (char * , int ); 

typedef struct{
  char* nombreP[30];
  char* nombreI[30];
  char* tipo[30];
  int nivel_o_cantidad;
  List* Personajes;
  List* Item;
  int cantidad;
}Personaje;



void ImportarItems(char*,List*);
void agregarItem(char* , char* , int , char* , List*);
void mostrarnombres();