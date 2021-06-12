#include<stdio.h>
#include<string.h>
struct user
{
char name[20];
char id[20];
char state[20];
};

int main(){
char r[20];
char r2[20];
char r3[20];
char name2[20];
char namenew[20];
char* token;
int i;
int j;
int m;
int value;
int opt;
int inp;
int inp2;
FILE *fp;
fp = fopen("user_list.txt", "r");
	if( fp == NULL){
		printf("No se ha podido abrir el fichero.\n");
	}
//Crear funcion leer base de datos
//...Recuperando informaciòn de la base de datos
i=1;
struct user num[20];
while ( !feof(fp) ){
	fgets(r, 20, fp);
	strcpy(num[i].name, r);	
//---------
        fgets(r2, 20, fp);
	strcpy(num[i].id, r2);	
//--------
	fgets(r3, 20, fp);
	strcpy(num[i].state, r3);
i++;
}
fclose(fp);
//----Imprimir nombre
//For que imprime la lista de usuarios enumerados. Desde i=0 hasta i igual al tamaño de arreglo 
//de structs
while(1){
printf("Opciones:\n1.Imprimir la lista de usuarios.\n2.Imprimir la lista de usuarios y su ID.\n3.Editar datos\n");
int menureturn(){
        printf("¿Desea hacer algo más?\n1.Volver al menú.\n2.Salir\n");
        scanf("%i",&inp2);
        return inp2;
}
scanf("%i", &inp);
for (j=1; j< i; j++){
	switch(inp){
		case 1:
			printf("%i.%s", j, num[j].name);
			break;	
		case 2:
			printf("%i.%s ID:%s", j, num[j].name, num[j].id);
			break;		
		case 3:
                	printf("Porfavor introduzca el nombre del usuario\n");
                        scanf("%s", name2);
			for(m=0; m<i; m++){
				token = strtok(num[m].name, "\n");
				value=strcmp(name2, token);
				if(value==0){
					printf("Ingrese el nuevo nombre\n");
					scanf("%s", namenew);
					strcpy(num[m].name, namenew);	
					m=100;;
				}
			}
			j=100;

			break;
			
		}

}
		printf("\n");
		value=menureturn();
		if(value==2){
			break;
		}

}

}
