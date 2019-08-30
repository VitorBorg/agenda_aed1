#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rep();

typedef struct {
    char name[20];
    char city[20];
    int age;
} user;

void *pBuffer;
int *size, *usersLen, *option, *temp, *temporary;

int main(){
    pBuffer = malloc((sizeof(int) * 5) + (sizeof(char) * 40));

    rep();
    *size = (sizeof(int) * 5) + (sizeof(char) * 40);

    do{
        printf("0 para adicionar, 1 para excluir, 2 para buscar, 3 para listar, 4 para sair e 5 para ordenar por idade.\n");
        scanf("%d", &(*option));
        
        if(*option == 0)
			printf("ADD");
		else if(*option == 2)
			printf("REMOVE");
        
    } while(*option != 4);

}

void rep(){
    size = pBuffer;
    usersLen = pBuffer + (sizeof(int) * 1) + 1;
    option = pBuffer + (sizeof(int) * 2) + 1;
    temp = pBuffer + (sizeof(int) * 3) + 1;
    temporary = pBuffer + (sizeof(int) * 4) + 1;
}
