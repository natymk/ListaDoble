#include<stdio.h>
#include<stdlib.h>

//int *ptr1=NULL;
//int *ptr2=NULL;
//int *ptr3=NULL;
//int *ptr4=NULL;

void main(){

int *ptr1 = (int *)malloc(sizeof(int));
int *ptr2 = (int *)malloc(sizeof(int));
int *ptr3 = (int *)malloc(sizeof(int));
int *ptr4 = (int *)malloc(sizeof(int));

*ptr1=15;
*ptr2=64;
*ptr3=70;
*ptr4=30;

//int *ptrarray[]=NULL;
//ptrarray[1]=ptr1;

//printf("array[1]: %d\n", ptrarray[1]);

}

