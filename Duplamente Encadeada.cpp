#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Lista{ // Estrutura 
       int valor;
       Lista *ant,*prox; 
};

void Inserir(Lista **lis, int val){
	Lista *vari1;
			
		vari1 = ((Lista*)malloc (sizeof(Lista)));
			vari1->prox = (*lis)->prox; // recendo list como proximo 
			vari1->ant = *lis; // anterior recebendo a list
			vari1-> ant -> prox = vari1; // ant e prox recebendo a vari1
			vari1->prox->ant = vari1; // já aqui o prox e ant recebendo vari1, como ordem inversa
			vari1-> valor = val; // valor da lista recebendo val desta struct como parametro
			
		(*lis = vari1);	
}


void InserirNulo(Lista **lis, int val){ // Funçao para inserir se a Lista estiver vazia
	Lista *vari2;
	
	vari2 = ((Lista*)malloc (sizeof(Lista)));
		vari2->prox = vari2;// variavel2 que está apontando para prox recebe variavel 2 pois variavel2 está vazio
		vari2->ant = vari2;	// variavel2 que está apontando para ant recebe variavel 2 pois variavel2 está vazio
		vari2->valor = val; // atual no aponta para o novo no
		
	*lis = vari2; // o novo no passa a ser o primeiro da lista
}


void Deletar(Lista **lis){
	Lista *ListaB; // apontando na struct como ListaB
		
	(*lis)->prox->ant = (*lis)->ant; // fazendo a amarração 
	(*lis)->ant->prox = (*lis)-> prox; // fazendo amarração
	
	ListaB = (*lis)->ant; // quando excluir apontar para o ultimo valor colocado
	free(*lis); // liberando a memoria
	
	*lis = ListaB;
		
}

void Iniciar(Lista **lis){
	*lis = NULL;
}



int main (){
	int valorM = 0;
	struct Lista *listaD;
	
		Iniciar(&listaD);
			
		while(1){
				
		
		printf("\nEscolha uma opcao:\n\n1 - Inserir\n2 - Proximo\n3 - Anterior\n4 - Deletar\n5 - Sair\n\n");
		scanf("%i",&valorM);
		fflush(stdin);

		
		if ((valorM == 1) && (listaD != NULL)){
			printf("\nDigite um valor: ");
			scanf("%i", &valorM);
			Inserir(&listaD, valorM);
		} 
		
		else if ((valorM == 1) && (listaD == NULL)){
			printf("\nDigite um valor: ");
			scanf("%i", &valorM);
			InserirNulo(&listaD, valorM);
		}
		
		else if((valorM == 2) && (listaD != NULL)){
			listaD = listaD->prox;	

		}
		
		else if ((valorM == 3) && (listaD != NULL)){
			listaD = listaD->ant;
		
		}
		
		else if ((valorM == 4) && (listaD->prox != listaD)){
			Deletar(&listaD);
	
		}
		
		else if((valorM == 4) && (listaD != NULL)){
				Deletar(&listaD);
				Iniciar(&listaD);
		}
		
				
		else if (valorM == 5){
			break;
		}else if (valorM <0 || valorM > 5){
			printf("\n\nFormato invalido!!\n\n\n");
			system("pause");
		}
		
		system("cls");

		
		if(listaD != NULL ){
			printf("Numero: %i\n", listaD->valor);	
		}
		
		
	}
		
}
