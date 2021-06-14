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
void deleteList(t_list *list);
//------MAIN-------
int main(){
	int opt;
	int opt2;
	t_list *list;
	int opt3;
bis:
	list=createList();//Se crea la lista;
	do{
		//Inicialización opciones de menú
		opt=0;
		opt2=0;
		opt3=0;
		//Interfaz menú
		printf(" ______________________________________________________________________ \n");
		printf("|                                                                      |\n");
		printf("|------------------------ Creador de listas ---------------------------|\n");
		printf("|______________________________________________________________________|\n");
		printf("|                                                                      |\n");
		printf("| 1.        Insertar un nuevo nodo en la lista de datos                |\n");
		printf("|_________________________________ ____________________________________|\n");
		printf("|                                 |                                    |\n");
		printf("| 2. Eliminar nodo de la lista    | 3. Imprimir lista                  |\n");
		printf("|_________________________________|____________________________________|\n");
		printf("|                                 |                                    |\n");
		printf("| 4. Eliminar lista               | 5. Salir                           |\n");
		printf("|_________________________________|____________________________________|\n");
		printf("Ingrese una opcion: ");
		scanf("%i", &opt);
			switch(opt){
				case 1:
					insertNode(list);
					break;
				case 2:
					deleteNode(list);
					break;
				case 3:
					printList(list);
					break;
				case 4:
					deleteList(list);
					printf("¿Desea crear una nueva Lista?\n");
					printf(" 1. Sí\n 2.No(Salir del programa)\n");
					scanf("%i", &opt3);
					if(opt3==1){
						goto bis;
					}
					break;

				case 5:
					printf("Saliendo del programa (...)\n");
					break;
				default:
					printf("Opción inválida\n");
			}//END OF SWITCH
				if (opt!=5 && opt3!=2){
				printf("¿Desea hacer algo más?\n1.Volver al menú principal.\n2.Salir\n");
					scanf("%i",&opt2);
					if(opt2!=1){
						if(opt2!=2){
							printf("Opción inválida\n");
						}
						else{
							break;
						}
					}
				}else{break;}
			//END OF IF

	} while(opt!=5 && opt2!=2);//Mientras la opción seleccionada por el usuario no sea 5, seguira entrando al menú
	//END OF DO WHILE
if(list->head!=NULL){
deleteList(list);
		}
free(list);

}//----END OF MAIN-----

//FUNCIONES PRINCIPALES

//Funcion para crear un nuevo nodo
t_node *createNode(){
	t_node* newNode = (t_node*)malloc(sizeof(t_node));
        //Inicialicion de punteros del nodo
        newNode->data=0;
        newNode->next=NULL;
        newNode->prev=NULL;
	//Se le solocita al usuario que ingrese eldato que contendrá el nodo
	printf("Ingrese el dato que contendrá el nuevo nodo:");
        scanf("%i", &newNode->data);
        //La funcion me devuelve el nuevo nodo
        return newNode;
}//------END OF FUNCTION------

//Función para crear una lista
t_list *createList(){
        t_list *newList = (t_list *)malloc(sizeof(t_list));//Se reserva la memoria
//Inicialización de punteros
        newList->current=NULL;
        newList->head=NULL;
        newList->tail=NULL;
        //La funcion me devuelve la nueva lista
        return newList;
}//------END OF FUNCTION------

//Función para obtener el tamaño de la lista
int listSize(t_list *list){
        int i=0;
        if(list->head!=NULL){
                list->current=list->head;
                while(list->current!=NULL){
                        list->current=list->current->next;
                        i++;
                }
        
        return i;
	}else{
		printf("La lista está vacía D:");
		return 0;
	}
}//------END OF FUNCTION------

//Función para buscar un nodo especifico en la lista
t_node *selectNode(t_list *list){
        int i=0;//indice 
	t_node *r= NULL;
        int select;
        int l = listSize(list);//Longitud de la lista
        list->current=list->head;//Posiciona el puntero current sobre el head
        printf("Lista de datos:\n");
        if(list->current!=NULL){
		while(list->current!=NULL){
			printf("Nodo (%i) -> dato contenido: |  %i  |\n",i+1, list->current->data);
			list->current=list->current->next;//Ahora current es el nodo siguiente
			i++;
		}//--END OF WHILE 1
		printf("¿En cuál nodo desea posicionarse?\n Ej: Si desea seleccionar el primero nodo, escriba  1  \n ");
		scanf("%i",&select);
		i=0;
		list->current=list->head;
		while(list->current!=NULL){
			if(select>l){//Si el numero de nodo indicado es más grande que l 
				printf("El nodo indicado no existe D:\n");
				break;
			}//END OF IF 2
			if(i==select){
				printf("Nodo seleccionado con éxito :D\n");
				r = list->current;
				break;
			}// END OF IF 3

			list->current=list->current->next;
			i++;
		}//---END OF WHILE 2
	}//--END OF IF 1
        else{
		printf("La lista está vacía, no hay nada que imprmir :( \n" );
	}
	if(r==NULL){
		printf("Error al seleccionar nodo :(\n");
	}
	return r;

}//------END OF FUNCTION------

//Función para imprimir la lista actual
void printList(t_list *list){
	int i=0;
        list->current=list->head;
	if(list->current!=NULL){
		printf("Lista de datos:\n");
        	while(list->current!=NULL){
                	printf("Nodo %i:|  %d  |\n",i+1,list->current->data);
                	list->current=list->current->next;
                	i++;
		}//--END OF WHILE
	}//--END OF IF
	else{
		printf("La lista está vacía, no hay nada que imprmir :'(\n");
	}
}//------END OF FUNCTION------
//------------------------------------------------------
//FUNCIONES DERIVADAS

//Función para insertar un nuevo nodo a la lista
void insertNode(t_list *list){
	int opt=0;
	int opt2=0;
	t_node *node=createNode();//Se crea un nuevo nodo y se le pide al usuario que ingrese el dato que contendrá.
	if(list->head == NULL){//Si el head está vacio quiere decir que la lista está vacía, por lo que el nuevo no
			       //_do será el primer y único elemento de la lista.
		list->head =node;
		list->head->next = NULL;
		list->tail = list->head;
		list->tail->next=NULL;
		printf("El nodo ha sido insertado con éxito :D\n");

	}	
	else{// En caso de que la lista ya contenga nodos, se le preguntara al usuario en que parte de la lista de_
		//sea insertar el nuevo nodo.
		
		//Submenú para insertar nodo.
		printf("En que parte de la lista desea insertar el nuevo nodo:\n");
                printf("1. Al inicio \n2. Al final \n3. Despues/Antes de un nodo específico\n4. Salir\n");
		printf("Inserte una opción:");
		scanf("%i", &opt);
		switch(opt){
			case 1://Insertar nodo al inicio de la lista
				list->head->prev = node;
				node->prev = NULL;
				node->next = list->head;
				list->head = node;
				printf("El nodo ha sido insertado con éxito :D\n");
				break;
			case 2://Insertar nodo al final de la lista
				list->tail->next = node;
				node->next = NULL;
				node->prev = list->tail;
				list->tail = node;
				printf("El nodo ha sido insertado con éxito :D\n");
				break;
			case 3://Insertar nodo en otro lugar de la lista
				printf("En cual nodo desea posicionarse?\n");
				list->current=selectNode(list);//Se le pide al usuario que seleccione un nodo actual de la lista
				if(list->current!=NULL){//Se ejecuta solo si el nodo seleccionado es diferente de NULL
					//Submenú
					printf("Insertar nodo:\n1.Antes del nodo seleccionado\n2.Después del nodo seleccionado\n3.Salir\n");
							scanf("%i",&opt2);
					switch(opt2){
						case 1://caso 3.1: antes del nodo
							if(list->current==list->head){//Si el nodo seleccionado es el primero,entonces 
							//en realidad se insertará el nuevo nodo al inicio de la lista, como en el caso 1
								list->head->prev = node;
								node->prev = NULL;
								node->next = list->head;
								list->head = node;
							}//---END OF IF
							else{
							node->prev = list->current->prev;
							node->next = list->current;
							list->current->prev->next = node;
							list->current->prev = node;
							}//END OF ELSE
							printf("El nodo ha sido insertado con éxito :D\n");
							break;
						case 2://Caso 3.2: después del nodo
							if(list->current==list->tail){//Si el nodo seleccionado es el último,entonces 
							//en realidad se insertará el nuevo nodo al final de la lista, como en el caso 2
								list->head->prev = node;
								node->prev = NULL;
								node->next = list->head;
								list->head = node;
							}//---END OF IF
							else{
								node->prev = list->current;
								node->next = list->current->next;
								list->current->next->prev = node;
								list->current->next = node;			
							}
							printf("El nodo ha sido insertado con éxito :D\n");
							break;
						default://Caso 3.1: Salir del menú actual
							break;//final caso 3.1		
					}//END SWITCH 21
				}//END IF
				break;//final caso 3
			default: 
				printf("Opción inválida\n");
        	}//END OF SWITCH 1
}//END OF ELSE

}//------END OF FUNCTION------
//----------------------------------------------------

//Función para eliminar un nodo de la lista
void deleteNode(t_list *list){
	int opt;
	int r;
        if(list->head!=NULL){             
			r=0;//indicador para la opción 3
			printf("Cual nodo desea eliminar:\n");
                	printf("1. El último \n2. El primero \n3. Otro\n4.Salir\n");
			scanf("%i", &opt);
			while(1){
				switch(opt){
					case 1: //Elimina el último nodo
						list->current=list->tail; //Coloca el puntero current en el último nodo de la lista
						list->tail=list->tail->prev; //Cambia el puntero tail al nodo anterior (ahora este pasa a ser el ultimo nodo de la lista)
						list->tail->next=NULL; //Hace que el puntero next del nuevo último nodo apunte a NULL
						list->current->prev=NULL; //Hace que el puntero previo al nodo que vamos a borrar apunte a NULL
						free(list->current); //Se libera la memoria del nodo
					       	list->current=NULL;	
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 2://Elimina el primer nodo
						list->current=list->head; //Coloca el puntero current en el primer nodo de la lista
						list->head=list->head->next; //Cambia el puntero head al nodo siguiente (ahora este pasa a ser el primer nodo de la lista)
						list->head->prev=NULL; //Hace que el puntero prev del nuevo head apunte a NULL
						list->current->next=NULL; //Hace que el puntero next del antiguo head apunte a NULL
						free(list->current); //Se libera la memoria del head antiguo 
						list->current=NULL;
						printf("El nodo ha sido eliminado con éxito :D\n");
						break;
					case 3://Elimina otro nodo específico
						printf("Cual nodo desea eliminar:\n");
						list->current=selectNode(list);//Posiciona el puntero current en el head de la lista
						if(list->current->prev==NULL){//Se ejecuta si el nodo seleccionado es el primero de la lista
							r=2;
						}
						if(list->current->next==NULL){//Se ejecuta si el nodo seleccionado es el último de la lista
							r=1;
						}
						else{
							list->current->prev->next=list->current->next; //Coloca el puntero current en el primer nodo de la lista
							list->current->next->prev=list->current->prev; //Cambia el puntero head al nodo siguiente (ahora este pasa a ser el primer nodo de la lista)
							list->current->prev=NULL; //Hace que el puntero prev del nuevo head apunte a NULL
							list->current->next=NULL; //Hace que el puntero prev del antiguo head apunte a NULL
							free(list->current); //Se libera la memoria del head antiguo
							list->current=NULL;
							printf("El nodo ha sido eliminado con éxito :D\n");
						}
						break;
					case 4:
						printf("Volviendo la menú principal...\n");
						break;
					default:
						printf("Opción inválida\n");
				}//END OF SWITCH
				//Funcion en caso de que en el caso tres el nodo indicado sea el primero o el
				//ultimo de la lista. Entra de nuevo al switch pero en el caso correspondiente
				if((r)!=0){
					opt=r;
				}
				else{
					break;
				}
			}//END  WHILE
        }//END OF IF
        else{
        	printf("La lista se encuentra vacia :(\n ");
        }//END OF ELSE
}//------END OF FUNCTION------

void deleteList(t_list *list){
	
	if(list->head!=NULL){ //Solo eliminará la lista si no está vacía
		list->current=list->head;//Posiciona el puntero current en el head de la lista
		if(list->head->next!=NULL){//Solo se ejecutará si la lista tiene más de un elemento
			list->current=list->head->next;
			while(list->current!=NULL){
				list->head->next=NULL;
				list->current->prev=NULL;
				free(list->head);
				list->head=list->current;
				list->current=list->head->next;
			}//END OF WHILE
		}//END OF IF 2
	free(list->head);
	//Se apuntan a NULL todos los punteros de control de la lista
	list->head=NULL;
	list->current=NULL;
	list->tail=NULL;
	//Se libera la lista
	printf("Lista liberada exitosamente!\n");
	}//END OF IF 1
	else{
		printf("No hay nada que eliminar, la lista está vacía :(\n");
	}
}//------END OF FUNCTION------


