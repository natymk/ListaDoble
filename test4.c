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
} t_list;//Nombre para hacer referencia al tipo de dato de esta estructura

//----------
//Inicializacion de funciones y variables
t_list *createList();
t_node *createNode();
t_node *selectNode(t_list *list);
void insertNode(t_list *list);
void deleteNode(t_list *list);
void printList(t_list *list);
int listSize(t_list *list);
int returnMenu();
int i; //indice

//----------
//------MAIN-------
int main(){
        insert();
        return 0;
}
//---END OF MAIN---

//FUNCIONES PRINCIPALES

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
//Funcion para obtener el tamaño de la lista
int listSize(t_list *list){
        i=0;
        if(list->head!=NULL;){
                list->current=list->head;
                while(list->current!=NULL;){
                        list->current=list->head->next;
                        i++;
                }
        
        return i;
	}//else{
		//printf();
	//}
}
//FINAL FUNCION listSize();
//Función para volver al menú anterior
int returnMenu(){
	int inp2;
	printf("¿Desea hacer algo más?\n1.Volver al menú.\n2.Salir\n");
        scanf("%i",&inp2);
        return inp2;
}


//--------------------------------------------------
//Función para buscar un nodo especifico en la lista
t_node *selectNode(t_list *list){
        i=0;
        int select;
        int long = listSize(t_list *list));
        t_node *index[long];
        list->current=list->head;
        printf("Lista de datos:\n");
        
        while(list->current!=NULL){
                t_node *index[long];
                index[i]=list->current;
                printf("Nodo %i: %d\n",i+1,*list->current);
                list->current=list->head->next;
                i++;
        }
        printf("Ingrese la posición del nodo en el que se desea posicionar:\n");
        scanf("%i",&select);
        i=0;
        while(list->current!=NULL){
                if(*index[i]>long){
                        printf("El nodo indicado no existe");
                        break;
                        return NULL;
                }
                if(*index[i]==select){
                        print("Nodo seleccionado con éxito");
                        return index[i];
                        break;
                }
       
}//---FINAL FUNCION SelectNode();
	
//------------------------------------------------------
//FUNCIONES DERIVADAS

//Función para insertar un nuevo nodo a la lista
void insertNode(t_list *list){
	opt
        switch()
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
                        list->current=buscarnodo();
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
	//FINAL FUNCION insertNode();
	
	//----------------------------------------------------
	//Función para eliminar un nodo de la lista
void deleteNode(t_list *list){
	int opt;
	int r;
	int opt2;
        if(head!=NULL){             
		while(1){
			r=0;//indicador para la opciòn 3
			printf("Cual nodo desea eliminar:"\n);
                	printf("1. El último \n2. El primero \n3. Otro\n4.Salir\n");
			scanf("%d\n", &opt);
			while(1){
				switch(opt){
					case 1: //Elimina el último nodo
						list->current=list->tail; //Coloca el puntero current en el último nodo de la lista
						list->tail=list->tail->prev; //Cambia el puntero tail al nodo anterior (ahora este pasa a ser el ultimo nodo de la lista)
						list->tail->next=NULL; //Hace que el puntero next del nuevo último nodo apunte a NULL
						list->current->prev=NULL; //Hace que el puntero previo al nodo que vamos a borrar apunte a NULL
						free(list->current); //Se libera la memoria del nodo 
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 2://Elimina el primer nodo
						list->current=list->head; //Coloca el puntero current en el primer nodo de la lista
						list->head=list->head->next; //Cambia el puntero head al nodo siguiente (ahora este pasa a ser el primer nodo de la lista)
						list->head->prev=NULL; //Hace que el puntero prev del nuevo head apunte a NULL
						list->current->next=NULL; //Hace que el puntero prev del antiguo head apunte a NULL
						free(list->current); //Se libera la memoria del head antiguo 
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 3://Elimina otro nodo específico
						printf("Cual nodo desea eliminar:"\n);
						list->current=selectNode(t_list *list);
						if(list->head->prev==NULL){
							r=2;
							break;
						}
						else if(list->head->prev==NULL){
							r=1;
							break;
						}
						else{
							printf("El nodo ha sido eliminado con éxito :D\n");
							break;
						}
					case 4://Sale del menú actual
						break;
				}//END OF SWITCH
				
				//Funcion en caso de que en el caso 3 el nodo indicado sea el primero o el
				//ultimo de la lista. Entra de nuevo al switch pero en el caso correspondiente
				if(r=!0){
				opt=r;
				}
				else{
					break;
				}
				
			}//end while anidado
			opt2=menureturn();//pregunta al usuario si desea realizar otra accion
			if else(opt2!=1){// Si la opcion es diferente de uno, se saldrá del programa
				if(opt2!=2){//Si la opción seleccionada no es 2
					printf("La opción ingresada no es válida\nSaliendo del programa...");
				}
				break;
			}

		}//End while principal
        }//END OF IF(head!=NULL)
        else{
        printf("La lista se encuentra vacia :(\n ");
        }

}//----END OF deleteNode();


