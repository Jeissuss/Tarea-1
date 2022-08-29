#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

List* listaGlobal = NULL;

char *get_csv_field (char * tmp, int k) 
{
  int open_mark = 0;
  char* ret=(char*) malloc (100*sizeof(char));
  int ini_i=0, i=0;
  int j=0;
  while(tmp[i+1]!='\0'){
        
    if(tmp[i] == '\"'){
      open_mark = 1-open_mark;
      if(open_mark) ini_i = i+1;   
      i++;
      continue;
      
    }

    if(open_mark || tmp[i]!= ','){
      if(k==j) ret[i-ini_i] = tmp[i];
      i++;
      continue;
    }

    if(tmp[i]== ','){
      if(k==j) {
        ret[i-ini_i] = 0;
        return ret;
      }
          
      j++; ini_i = i+1;  
          
    }

    i++;
  }

  if(k==j) {
    ret[i-ini_i] = 0;
    return ret;
  }
  return NULL;
} 

void ImportarItems(char* nombre_archivo, List* listaGlobal){
  FILE *Inventario = fopen(nombre_archivo, "r"); 
  if (Inventario == NULL)
  {
    printf("\nArchivo no encontrado!\n");
    return;
  }
  else
  {
    printf("\nArchivo abierto correctamente!\n");
  }
  
  char linea[99];
  int i;
  int k = 0;
  fgets(linea,98,Inventario);
  while (fgets(linea, 98, Inventario) != NULL)
  {
    for (i = 0; i < 1; i++)
    {
      char *tipo = get_csv_field(linea, i);
      char *nombre_item = get_csv_field(linea, i+1);
      char *nivel_o_cantidad = get_csv_field(linea, i+2);
      int nivelOcantidad=atoi(nivel_o_cantidad);
      char *personaje = get_csv_field(linea, i+3);
      
      agregarItem(tipo,nombre_item,nivelOcantidad,personaje,listaGlobal);
      
    }
    k++;
  }

  fclose(Inventario);
}




void agregarItem(char* tipo, char* nombre_item, int nivel_o_cantidad, char* personaje,List* listaGlobal)
{

  if(listaGlobal==NULL){
    listaGlobal=createList();
  }

  Personaje* datos = (Personaje*) malloc (sizeof(Personaje));
  Personaje* aux=firstList(listaGlobal);
  
  strcpy(*datos->tipo,tipo);
  strcpy(*datos->nombreI,nombre_item);
  strcpy(*datos->nombreP,personaje); 
  datos->nivel_o_cantidad=nivel_o_cantidad;

  
  if(aux==NULL){
    pushBack(listaGlobal,datos);  
  }
  else
  {
    while(aux != NULL)
    {
      if(strcmp(*aux->tipo,tipo) == 0)
      {
        if(strcmp(*aux->nombreI, nombre_item) == 0)
        {
          if(*aux->nombreP==personaje)
          {
            printf("Este objeto ya se encuentra en el personaje\n");
          }
        }
        else
        {
          pushBack(listaGlobal,datos);
        }
        return;  
      }
      else
      {
        pushBack(listaGlobal,datos);          
      }
      aux=nextList(listaGlobal);
    }
  }
}

void mostrarnombres(List* list)
{
  Personaje *aux=firstList(listaGlobal);
  while(aux!=NULL)
  {
    printf("%s\n",*aux->nombreP);
    printf("%d\n",aux->nivel_o_cantidad);
    aux=nextList(list);
  }
}
