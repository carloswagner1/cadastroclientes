#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char nome[50];
	char email[50];
	char cpfcnpj[20];
	char telefone[15];
	char logradouro[100];
	char numero[7];
	char bairro[50];
	char cep[12];
	char cidade[50];
	char estado[50];
  	
} Cadastro;

void flush_in();
Cadastro * inicializar(int cap);
void novoCliente (Cadastro *cliente, int *num);
void imprimir(Cadastro *cliente, int i);


void exibeClientes (Cadastro *cliente, int num);

void exibeClienteNome(Cadastro *agenda, int num);
void alteraCliente(Cadastro *agenda, int num);
void imprimir(Cadastro *cliente, int i);


int main(){
	Cadastro *cliente;
	int cap = 20;
	int num = 0;
	int opc, i;
	printf("***Teste Pratico Helpper - Cadastro de Clientes***\n");
	cliente = inicializar(cap);
	
	do{
		printf("\nMenu Inicial\n\n");
		printf("Escolha a opcao que deseja realizar:\n");
		printf("1) Cadastrar Cliente.\n");
		printf("2) Listar Clientes\n");
		printf("3) Excluir Cliente.\n");
		printf("4) Sair.\n");
		printf("Opcao: ");		
		
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
		        cliente = (Cadastro *) realloc(cliente, (num+1) *sizeof(Cadastro));
		        novoCliente(cliente, &num);
		        printf("Cliente cadastrado com sucesso.\n");
			break;
			
			case 2: 
				if(num == 0){
					printf("\nNenhum cliente cadastrado.\n");
				}else{
					for(i = 0; i < num; i++){
						imprimir(cliente, i);
					}
				}
			break;
			
			case 3:
				if(num == 0){
					printf("\nNenhum Cliente cadastrado.\n");
				}else{
					printf("Para apagar um cliente, necessário informar o ID.\n");
					printf("Informe o ID do cliente que deseja apagar ou digite -1 para voltar ao menu.\n");
					printf("ID: ");
					int id;
					scanf("%i", &id);
					if(id == -1) break;
					int i, k;
					for(i = 0; i < num; i++){
        	            if(id == cliente[i].id){
            	            for (k = i;k < num - 1; ++k){
                	            cliente[k] = cliente[k + 1];
                    	    }
                        	num--;
                        	cliente = (Cadastro *) realloc(cliente, (num) * sizeof(Cadastro));
                    	}
                    }
                    printf("Cliente excluido.\n");
				}
			break;
			
			case 4:
				printf("\nFechando a aplicacao.\n");
			break;
			
			default:
				printf("Opcao invalida.");
				flush_in();
		}
	}while(opc!=4);
	
	free(cliente);
	return 0;
}

void flush_in(){
	int ch;
	while((ch = fgetc(stdin)) != EOF && ch != '\n'){}
}

Cadastro *inicializar(int cap){
	Cadastro *agenda;
	
	agenda = (Cadastro *) malloc(sizeof(Cadastro) * cap);
	
	return agenda;
}

void novoCliente(Cadastro *cliente, int *num){
	printf("\nNome do cliente: ");
	flush_in();
	gets(cliente[*num].nome);
	printf("Email: ");
	scanf("%s", &cliente[*num].email);
    flush_in();
	printf("CPF/CNPJ: ");
	fgets(cliente[*num].cpfcnpj, 20, stdin);
	printf("Telefone: ");
   	scanf("%s", &cliente[*num].telefone);	
    flush_in();
	printf("Logradouro: ");
	fgets(cliente[*num].logradouro, 100, stdin); 
    printf("Numero: ");
	scanf("%s", &cliente[*num].numero);
    flush_in();
	printf("Bairro: ");    
	fgets(cliente[*num].bairro, 50, stdin);
   	printf("CEP: ");
	scanf("%s", &cliente[*num].cep);
    flush_in();
   	printf("Cidade: ");
	fgets(cliente[*num].cidade, 50, stdin); 
	printf("Estado: ");    
	fgets(cliente[*num].estado, 50, stdin); 
	cliente[*num].id = *num;
	(*num)++;

}

void imprimir(Cadastro *cliente, int i){
	printf("\nID: %d\n", cliente[i].id);
	printf("Nome: %s\n", cliente[i].nome);
	printf("E-mail: %s\n", cliente[i].email);
	printf("CPF/CNPJ: %s", cliente[i].cpfcnpj);	
	printf("Telefone: %s\n", cliente[i].telefone);	
	printf("Endereco: %sNumero %s\n", cliente[i].logradouro, cliente[i].numero);
	printf("Bairro: %sCEP: %s\n", cliente[i].bairro, cliente[i].cep);
	printf("Cidade: %sEstado: %s\n", cliente[i].cidade, cliente[i].estado);

}
