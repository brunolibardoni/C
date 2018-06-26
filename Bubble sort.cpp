#include <stdio.h>


int main (){
	int vetor[5];
	int i=0;
	int j=0;
	int op=0;
	int flag = 0;
	int flag2=0;
	int f=0;
	
	while(2>1){
	
	printf("\n1-Adicionar numero no vetor: ");
	printf("\n2-Mostrar o vetor:");
	printf("\n3-Organizar: ");
	printf("\n4-Sair: ");
	scanf("%i", &op);
	
	if(op==1){
		if(flag2==0){
			for (i=0; i<5; i++){
				printf("\nDigite um numero: ");
				scanf("%i", &vetor[i]);
				}
				flag2++;
			}else{
				printf("\nVetor cheio\n");
			}
		}
	
		if(op==2){
				printf("\n");
				for(i=0; i<=sizeof(i); i++){
					printf("%i ", vetor[i]);
				}
				printf("\n");
			}
			
		if(op==3){
			if(f>4){
				printf("\nTodos os elementos estao organizado!\n");
			}else{
				for(j=0; j<sizeof(j); j++){
					if (vetor[j] > vetor[j+1]){
						flag = vetor[j];
						vetor[j] = vetor[j+1];
						vetor[j+1] = flag;
					}
				}
				f++;
				printf("\nOrganizando\n");
			}
		}
		if(op==4){
			break;
		}
	}	
}
