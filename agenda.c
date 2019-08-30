#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char city[20];
    int age;
} user;

void rep();
int add();
int rem();
void list();
user *buscar();

void *pBuffer;
int *size, *usersLen, *option, *temp, *temporary;

int main(){
    pBuffer = malloc(sizeof(int) * 5);

    rep();
    *size = (sizeof(int) * 5);

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
			
			pBuffer = realloc(pBuffer, *size);
			rep();
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
	scanf("%s", new->name); //NAO PRECISA DO & PORQUE E UMA STRING
	
	printf("\nInsira a sua cidade: ");
	scanf("%s", new->city);
	
	printf("\nInsira a sua idade: ");
	scanf("%d", &new->age);
	
	return 1;
}

int rem(){
	buscar();
	
	while(*temp < *usersLen){
	
		user *current = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
		*temp = *temp + 1;
		user *next = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
		
		*current = *next;
		
		if(*temp + 1 >= *usersLen){
			printf("\nUsuario removido.");
			pBuffer = realloc(pBuffer, *size - sizeof(user));
			rep();
			*size = *size - sizeof(user);
			*usersLen = *usersLen - 1;
		}
	
	}
	return 0;
}

void list(){
	
	*temp = 0;
	
	if(usersLen <= 0)
		printf("\n Nenhum usuario cadastrado.");
	else{
		while(*temp < *usersLen){
			user *User = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
			
			printf("\n Usuario: %s", User->name);
			*temp = *temp + 1;
		}
	}
}

user *buscar(){
	pBuffer = realloc(pBuffer, *size + (sizeof(char) * 20));
	rep();
	
	char *search = (char *)(&pBuffer + *size + 1);
	user *UserSearch = (user*)(&pBuffer + (sizeof(int) * 5) + 1);
	
	printf("\n Insira o nome que deseja buscar: ");
	scanf("%s", &(*search));
	
	*temp = 0;
	
	if(usersLen <= 0)
		printf("\n Nenhum usuario cadastrado.");
	else{
		while(*temp < *usersLen){
			if(strcmp(&(*search), UserSearch->name) == 0){
				printf("\n Usuario encontrado: ");
				printf("\n Nome: %s, cidade: %s, idade: %d", UserSearch->name, UserSearch->city, UserSearch->age);
				
				return UserSearch;
			}
			else if (*temp + 1 == *usersLen){
				printf("\n Usuario nao existe.");
				return 0;
			}
			
			*temp = *temp + 1;
			UserSearch = (user*)(&pBuffer + (sizeof(int) * 5) + 1 + (sizeof(user) * *temp));
		}
	}
	printf("\n Erro.");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char city[20];
    int age;
} user;

void rep();
int add();
int rem();
void list();
user *buscar();

void *pBuffer;
int *size, *usersLen, *option, *temp, *temporary;

int main(){
    pBuffer = malloc(sizeof(int) * 5);

    rep();
    *size = (sizeof(int) * 5);

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
			
			pBuffer = realloc(pBuffer, *size);
			rep();
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
	scanf("%s", new->name); //NAO PRECISA DO & PORQUE E UMA STRING
	
	printf("\nInsira a sua cidade: ");
	scanf("%s", new->city);
	
	printf("\nInsira a sua idade: ");
	scanf("%d", &new->age);
	
	return 1;
}

int rem(){
	buscar();
	
	while(*temp < *usersLen){
	
		user *current = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
		*temp = *temp + 1;
		user *next = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
		
		*current = *next;
		
		if(*temp + 1 >= *usersLen){
			printf("\nUsuario removido.");
			pBuffer = realloc(pBuffer, *size - sizeof(user));
			rep();
			*size = *size - sizeof(user);
			*usersLen = *usersLen - 1;
		}
	
	}
	return 0;
}

void list(){
	
	*temp = 0;
	
	if(usersLen <= 0)
		printf("\n Nenhum usuario cadastrado.");
	else{
		while(*temp < *usersLen){
			user *User = (user*)((&pBuffer + (sizeof(int) * 5) + 1) + (sizeof(user) * *temp));
			
			printf("\n Usuario: %s", User->name);
			*temp = *temp + 1;
		}
	}
}

user *buscar(){
	pBuffer = realloc(pBuffer, *size + (sizeof(char) * 20));
	rep();
	
	char *search = (char *)(&pBuffer + *size + 1);
	user *UserSearch = (user*)(&pBuffer + (sizeof(int) * 5) + 1);
	
	printf("\n Insira o nome que deseja buscar: ");
	scanf("%s", &(*search));
	
	*temp = 0;
	
	if(usersLen <= 0)
		printf("\n Nenhum usuario cadastrado.");
	else{
		while(*temp < *usersLen){
			if(strcmp(&(*search), UserSearch->name) == 0){
				printf("\n Usuario encontrado: ");
				printf("\n Nome: %s, cidade: %s, idade: %d", UserSearch->name, UserSearch->city, UserSearch->age);
				
				return UserSearch;
			}
			else if (*temp + 1 == *usersLen){
				printf("\n Usuario nao existe.");
				return 0;
			}
			
			*temp = *temp + 1;
			UserSearch = (user*)(&pBuffer + (sizeof(int) * 5) + 1 + (sizeof(user) * *temp));
		}
	}
	printf("\n Erro.");
	return 0;
}
