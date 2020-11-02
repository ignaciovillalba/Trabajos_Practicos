/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void);//Crea linkedlist en memoria = constructor en MD

int ll_len(LinkedList* this);//cuenta cuantos elementos tenemos guardados en la lista, recibe LL =lista de empleados

int ll_add(LinkedList* this, void* pElement);//recibe la lista de empleados y el Puntero al empleado para agregarlo a la lista

void* ll_get(LinkedList* this, int index);//recibe la lista y la posicion del elemento (0,1,2 e i) usar getters

int ll_remove(LinkedList* this,int index);//recibe la lista, usa ll_get para obtener
void* ll_pop(LinkedList* this,int index);//muestra el elemento a ser eliminado, lo guarda, lo elimina y lo devuelve (empleados dados de baja) se almacena en un aux

int ll_clear(LinkedList* this);//limpia los elementos de la lista  pero no borra la lista
int ll_deleteLinkedList(LinkedList* this);//vacia la lista y sus elementos de la memoria

int ll_set(LinkedList* this, int index,void* pElement);//reciben indice y pisa los elementos en la posicion del indice
int ll_push(LinkedList* this, int index, void* pElement);//Abre espacio entre 2 elementos para agregar elementos a la lista

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_indexOf(LinkedList* this, void* pElement);//deveulve el indice de un elemento de la lista. recibe la lista y el elemento a buscar
int ll_isEmpty(LinkedList* this);//devuelve si la lista esta vacia, es decir si no tiene elementos

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//punteros a funciones para criterio de ordenamiento(order) se le pasa 1 a 0

int ll_contains(LinkedList* this, void* pElement);//devuelve si el elemento esta contenido dentro de la lista
int ll_containsAll(LinkedList* this,LinkedList* this2);//recibe 2 listas y compara si la lista 2 esta en la lista 1 (conjunto contenido en conjunto)

LinkedList* ll_subList(LinkedList* this,int from,int to);//obtiene una parte de una lista y sus elementos
LinkedList* ll_clone(LinkedList* this);//copia exactamente los elementos de la lista
