#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rep();
int add();
int rem();
void list();

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
        
        if(*option == 0){
			add();
			printf("\nUsuario adicionado.");
		}
		else if(*option == 1){
			rem();
			printf("\nUsuario removido.");
		}
			else if(*option == 2){
			rem();
			printf("\nBusca finalizada.");
		}
			else if(*option == 3){
			rem();
			printf("\nUsuarios listados.");
		}
        
    } while(*option != 4);

}

void rep(){
    size = pBuffer;
    usersLen = pBuffer + (sizeof(int) * 1) + 1;
    option = pBuffer + (sizeof(int) * 2) + 1;
    temp = pBuffer + (sizeof(int) * 3) + 1;
    temporary = pBuffer + (sizeof(int) * 4) + 1;
}

int add(){
	pBuffer = realloc(pBuffer, *size + (sizeof(user)));
	rep();
	
	user *new = (user*)(pBuffer + *size + 1);
	
	*size = *size + sizeof(user);
	*usersLen = *usersLen + 1;
	
	printf("\nInsira o seu nome: ");
	scanf("%s", new->name); //NAO PRECISA DO & PORQUE UMA E UMA STRING
	
	printf("\nInsira a sua cidade: ");
	scanf("%s", new->city);
	
	printf("\nInsira a sua idade: ");
	scanf("%d", &new->age);
	
	return 1;
}

int rem(){
	return 1;
}

void list(){
	
}
