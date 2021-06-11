#include<stdio.h>
#include<stdlib.h>

//Estructura del nodo
typedef struct node{
        int data;//Dato contenido en el nodo
        struct node* next;//Puntero  al siguiente nodo de la lista
        struct node* prev;//Puntero al siguiente nodo de la lista
} t_node;//Nombre para hacer referencia al tipo de dato de esta estructura.

//Estructura de control
typedef struct control{
        t_node* current;//Puntero al nodo actual
        t_node* head;//Puntero al primero nodo
        t_node* tail;//Puntero al ùltimo nodo
} t_list;//Nombre para hacer referencia al tipo de dato de esta estructura.
//----------
//Inicializacion de funciones y variables
t_list *createList();
t_node *createNode();
void insertNode(t_list *list);
void deleteNode(t_list *list);
void

//int *data;
//----------
//---MAIN---
int main(){
        insert();
        return 0;
}
//Funciones principales

//Funcion para crear un nuevo nodo
t_node *createNode(){
        t_node* newNode = (t_node*)malloc(sizeof(t_node));
        //Inicialicion de punteros del nodo
        newNode->data=NULL;
        newNode->next=NULL;
        newNode->prev=NULL;
        //La funcion me devuelve el nuevo nodo
        return newNode;
}

//Funcion para crear una lista
t_list *createList(){
        t_list *newList = (t_list *)malloc(sizeof(list));
//Inicializacion de punteros
        newList->current=NULL;
        newList->head=NULL;
        newList->tail=NULL;
        //La funcion me devuelve la nueva lista
        return newList
}
void insertNode(t_list *list){
        //Switch
        //Desea insertar el nuevo nodo:
        //1. Al principio de la lista 2. Al final 3. En otro lugar
        //Caso 1: Al final
        //Se crea el nuevo nodo
        t_node *node=createNode();
        //Se le pide al usuario por medio que ingrese el nuevo dato
        //mediante consola
        printf("Ingrese el dato que contendrá el nuevo nodo:");
        scanf("%d", &node->data);
        //------Se agrega el nodo a la lista
        //CONDICIONES
        //1.Si el head está vacio, quiere decir que la lista está vacía
        //y nuestro nodo será el el primero o el 'head' de la misma
         if(list->head == NULL){
                list->head =node;
                list->head->next = NULL;
                list->tail = list->head;
        }//Si el head NO está vacio, entonces nuestro nodo será el siguiente
         //elemento de la la lista
        else{
                list->tail->next = node;
                node->next = NULL;
                node->prev = list->tail;
                list->tail = node;
        }
//       -----
        //Caso 2: Al inicio
  else{
                list->head->prev = node;
                node->prev = NULL;
                node->next = list->head;
                list->head = node;
        }       //Caso 3: En otro lugar
                else{
                        imprimirlista();
                        printf("En cual nodo desea posicionarse?");
                        scanf("%i", &num);
                        current=buscarnodo();
                        //switch nuevo
                        //caso 3.1: antes del nodo
                        node->prev = list->current->prev;
                        node->next = list->current;
                        list->current->prev->next=node;
                        list->current->prev=node;
                        //list->current=node;
                        //Caso 3.2: despues del nodo
                        node->prev = list->current;
                        node->next = list->current->next;
                        list->current->next->prev = node;
                        list->current->next = node;
                        //list->current=node;
        }
                }
void deleteNode(t_list *list){
        //if(head!=NULL){
        //Switch
        printf("Cual nodo desea eliminar:"\n);
        //1. El primero 2. El ultimo 3. Otro
        //Caso 1: El ultimo

        list->current=list->tail;
        list->tail->prev->next = NULL;
        free(list->tail);

//      list->tail = list->tail->prev;

        printf("El nodo ha sido eliminado con éxito :D");
        //Caso 2: El primero
        list->




        printf("El nodo ha sido eliminado con éxito :D");
        //Caso 3: En otro lugar





        printf("El nodo ha sido eliminado con éxito :D");
} else{
        printf("La lista se encuentra vacia\n");

}



//} END OF IF(head!=NULL)





}//----END OF deleteNode();


