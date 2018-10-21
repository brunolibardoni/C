#include <stdio.h>
#include <stdlib.h>


	struct valor{ // Struct "Valor"
		valor *pdireita;
		valor *pesquerda;
		valor *pcima;


		int val;
	};
	
	void iniciarArvore(valor **v){ // Iniciando a arvore
   		*v = NULL;
	}

void insertNull(valor **v, int vari){ // Funcao para inserir na arvore quando NULL
	valor *pont;
    	pont = ((valor *)malloc(sizeof(valor)));
    	pont -> val = vari;
    	pont -> pdireita = NULL;
    	pont -> pesquerda = NULL;
    	pont -> pcima = NULL;
    	*v = pont;
}

void insertDireita(valor **v, int vari){ // Funcao para inserir a Direita da arvore
  	valor *pont;
    	pont = ((valor *)malloc(sizeof(valor)));
    	pont -> val = vari;
    	pont -> pcima = *v;
    	pont -> pdireita = NULL;
    	pont -> pesquerda = NULL;
    	(*v) -> pdireita = pont;
    	*v = pont;
}

void insertEsquerda(valor **va, int vari){ // Funcao para inserir a Esquerda da arvore
  		valor *pont;
    	pont = ((valor *)malloc(sizeof(valor)));
    	pont -> val = vari;
    	pont -> pcima = *va;
    	pont -> pdireita = NULL;
    	pont -> pesquerda = NULL;
    	(*va) -> pesquerda = pont;
    	*va = pont;
}

void deletFolha(valor **v){ // Deletar uma Folha da arvore
		valor *pont;
		pont = *v;
	
	if(pont->val > pont->pcima->val){
			pont->pcima->pdireita = NULL;
		}else{
			pont->pcima->pesquerda = NULL;
		}	
	
	*v = pont->pcima;
	free(pont);
}



void deletGalho(valor **v){ // Deletar um galho da arvore
	valor *pont;
	pont = *v;
	
	if(pont->pdireita == NULL){
		
		pont->pcima->pesquerda = pont->pesquerda;
		pont->pesquerda->pcima = pont->pcima;
		
	}else{
		
		pont->pcima->pdireita = pont->pdireita;
		pont->pdireita->pcima = pont->pcima;
		
	}
	
	*v = pont->pcima;
	free(pont);
}

void deletNo(valor **v, int raiz){ // Deletar um NO da arvore
	valor *pont;
	valor *a;
	pont = *v; // declaração das variaveis
	a = *v;
	int valTrocar;
	
	if(pont->val >= raiz){ // Verificação se o pont apontando para val da struct é maior ou igual a raiz 
		pont = pont->pdireita; // se for o ponto vai receber ponto apontando para o ponteiro da direita
		
		while(2>1){
			if(pont->pesquerda == NULL){ // caso o pont apontando para o valor da esquerda for NULL
				valTrocar = pont->val;// vou receber pont apontando pro valor com a  variavel valTrocar
				break;
			}else{
				pont = pont->pesquerda; // caso nao for null recebo na variavel pont; pont apontando para a esquerda 
			}
		}
		
		if(pont->pdireita != NULL){ // se a direita nao for null
			pont = pont->pdireita; // recebo pont da direita
			
			if(pont->pdireita == NULL && pont->pesquerda == NULL){ // Faço uma verificação se pont apontado para a direita é igual a NULL e pont esquerda tambem
				
				if(pont->val > pont->pcima->val){ // se for verdade aqui faço uma verificação se o val é maior que o ponteiro de cima apontando para o valor que ira receber
					pont->pcima->pdireita = NULL; // se for o pont cima e direita serao setados como null
					
				}else{
					pont->pcima->pesquerda = NULL;//senao pont de cima e esquerda serão setados como null
				}
				
				*v = pont->pcima; // valor apontado para o v recebera o valor pcima
				free(pont);// e o pont sera liberado da memoria
				
			}
				else if(pont->pdireita != NULL & pont->pesquerda == NULL){ // caso o ultimo if nao for null, entao o pont direita sera diferente e esquerda nulo
				deletGalho(&pont); // entao terei que deletar o galho colocando como parametro o pont
				
				}
					else if(pont->pdireita == NULL & pont->pesquerda != NULL){// se nenhuma das duas verificações forem true, o direita sera nulo e esquerda diferente de nulo
					deletGalho(&pont);// entao terei que deletar o galho colocando como parametro o pont
				
					}
						else if(pont->pdireita != NULL & pont->pesquerda != NULL){ // se nenuma verificação for true, os dois serao diferentes de null
						deletNo(&pont, raiz);// apenas deleto o no colocando como patrametro pont e a raiz
				
						}
		}
			else if(pont->pdireita == NULL){// caso direita igual null 
				deletFolha(&pont);//deleto a folha com o parametro pont
		}
		
		a->val = valTrocar; // e no fim a variavel A que é ponteiro da struct valor recebe valTrocar
		
	}else{ // se o vall de recebimento for menor que a raiz 
		pont = pont->pesquerda; // aponto para esquerda para que o pont receba
		
		while(2>1){ // e faço um while até acontecer um break fazendo com que alguma condição seja verdade
			if(pont->pdireita == NULL){ 
				valTrocar = pont->val;
				break;
			}else{
				pont = pont->pdireita;
			}
		}
		
		if(pont->pesquerda != NULL){// apos o while verifico se o pont apontando pra esquerda é diferente de null
			
			pont = pont->pesquerda; // se for difrente de null, seto de cara o pont recebendo pont esquerda
			
			if(pont->pdireita == NULL && pont->pesquerda == NULL){// esta verificaçao ira ver se a direita é nulo e esquerda nulo 
				
				if(pont->val > pont->pcima->val){// se for entao verifica se o val é maior que é pponto apontando pra cima e apontaodo pro valor
					pont->pcima->pdireita = NULL; // entao o pdireita apotado pro cima e pont vai ser nulo
					
				}else{
					pont->pcima->pesquerda = NULL;//caso contrario é o pesquerda que seta como nulo
				}
				
				*v = pont->pcima; // apos disso o ponteiro do v do valor recebe pont apontando para cima 
				free(pont); // e o pont é liberado da memoria
				
			}else if(pont->pdireita != NULL & pont->pesquerda == NULL){ // aqui sera posto 4 condições para que haja o delet, e no qual a arvore se encaixar ira fazer o delet recebendo os parametros
				deletGalho(&pont);
				
			}else if(pont->pdireita == NULL & pont->pesquerda != NULL){
				deletGalho(&pont);
				
			}else if(pont->pdireita != NULL & pont->pesquerda != NULL){
				deletNo(&pont, raiz);
				
			}
		}else if(pont->pesquerda == NULL){
			deletFolha(&pont);
		}
		
		a->val = valTrocar; // e a variavel a que recebeu o pontamento do valor ira apontar para o val e receber o valTrocar
		
	}
}

 int as[999];
 int lista = 0;
 int j = 0;

void preOrdem(struct valor **lis){
	struct valor *pN;
	pN = *lis;
    if(pN != NULL){
    	printf("%i ",pN->val);
        preOrdem(&pN->pesquerda);
        preOrdem(&pN->pdireita);
    }
}

void emOrdem(struct valor **lis){
	struct valor *pN;
	pN = *lis;
    if(pN != NULL){
    	emOrdem(&pN->pesquerda);
    	printf("%i ",pN->val);
        emOrdem(&pN->pdireita);
    }
}

void posOrdem(struct valor **lis){
	struct valor *pN;
	pN = *lis;
	
    if(pN != NULL){
    	posOrdem(&pN->pesquerda);
    	posOrdem(&pN->pdireita);
    	printf("%i ",pN->val);
    }
}

 int profundidade(valor **lis){
 	struct valor *pro;
 	pro = *lis;
 	
 	int e,d; 
 	
	 if(pro == NULL){
		return -1;
	}else{
	 	 e = profundidade(&pro->pesquerda);
	 	 d = profundidade (&pro->pdireita);
	 			 
	 	if(e > d){
	 		return e+1;
		 }else{
			return d+1;
		}
	}
}
 
 int Desbalanceamento(valor **lis){
 	struct valor *pro;
 	pro = *lis;
 	
 	int e,d; 
 	
	 if(pro == NULL){
		return -1;
	}else{
	 	 e = profundidade(&pro->pesquerda);
	 	 d = profundidade (&pro->pdireita);

			int temp = 0 ;	 	
	 		temp = e - d;
	
		 	return temp; 		
		}
	}

int main(){
	valor *vall;
	int op = 0;
	int numero;
	int valormeio;
	
	iniciarArvore(&vall);
	
	
	while(1){
		
		system("cls");
		
		if(vall != NULL){
			printf("  %d\n", vall->val);
		}
		
		printf("\n Escolha uma opcao:\n 1 - Esquerda\n 2 - Direita\n 3 - Cima\n 4 - Inserir\n 5 - Deletar\n 6 - Profundidade\n 7 - Pre-Ordem\n 8 - Em Ordem\n 9 - Pos Ordem\n 10 - Desbalanceamento\n 0 - Sair\n\n");
		scanf("%d", &op);
		
		if(op == 1){
			if(vall != NULL && vall->pesquerda != NULL){
				vall = vall->pesquerda;
			}
		}else if(op==2){
			if(vall != NULL && vall->pdireita != NULL){
				vall = vall ->pdireita;
			}
		}else if(op==3){
			if(vall != NULL && vall->pcima != NULL){
				vall = vall->pcima;
			}
		}else if(op==4){
			printf("\nDigite um numero: ");
            scanf("%d", &numero);
            
            if(vall != NULL){
            	
            	while(2 > 1){
            		
            		if(vall->pcima != NULL){
            			vall = vall->pcima;
					}else{
						break;
						}
					}
					
            	while(2>1){
            		if(numero > vall -> val){
            			if(vall->pdireita != NULL){
            				vall = vall->pdireita;
						}else{
							insertDireita(&vall, numero);
							break;
						}
					}
					if(numero < vall -> val){
            			if(vall->pesquerda != NULL){
            				vall = vall->pesquerda;
						}else{
							insertEsquerda(&vall, numero);
							break;
						}
					}		
				}
        	}else {
        		insertNull(&vall, numero);
        		valormeio = numero;
			}
		}
		else if(op==5){
			if(vall->pesquerda == NULL && vall->pdireita == NULL && vall->pcima != NULL){
				deletFolha(&vall);
				
					}
					else if(vall->pesquerda == NULL && vall->pdireita != NULL){
					deletGalho(&vall);
					
						}
						else if(vall->pesquerda != NULL && vall->pdireita == NULL){
						deletGalho(&vall);
						
							}
							else if(vall->pesquerda != NULL && vall->pdireita != NULL){
							deletNo(&vall, valormeio);
							
								}	
		}
		
		else if(op == 6){
			if(vall == NULL){
				printf("\nArvore vazia!\n");
				system("pause");
			}else{
				while(vall->pcima != NULL){
					vall = vall->pcima;
				}
			printf("Nivel: %i\n",profundidade(&vall));
			
			system("pause");
			}
		}
		
		else if (op == 7){
			int o = 0;
			preOrdem(&vall);
			printf("\n\nArvore Pre-Ordem:\n ");

		
			printf("\n");
			system("pause");
		}
		
		else if(op == 8){	
			int o = 0;
			emOrdem(&vall);
			printf("\n\nArvore Em Ordem:\n ");
			printf("\n");
			system("pause");

		}
		else if(op == 9){
			int o = 0;
			posOrdem(&vall);
			printf("\n\n Arvore em Pos Ordem");	
			printf("\n");
			system("pause");
		}
		
		else if(op == 10){
			if(vall == NULL){
				printf("\nArvore vazia!\n");
				system("pause");
			}else{
				while(vall->pcima != NULL){
					vall = vall->pcima;
				}
			printf("Desbalanceamento: %i\n",Desbalanceamento(&vall));
			
			 if(Desbalanceamento(&vall) < 0){
			 	printf("\n\nDesbalanceada para Direita\n");
			 }
			 
			 else if (Desbalanceamento(&vall) > 0){
			 	printf("\n\nDesbalanceada para Esquerda\n");
			 }
			 
			 else if (Desbalanceamento(&vall) == 0){
			 	printf("\n\nAltura das subarvores sao IGUAIS\n");
			 }
			
			system("pause");
			}
		}
		
		else if (op == 0){
			break;
		}
		
		else{
			printf("\nOpcao inexistente!!!\n");
			system("pause");
		}
	}
}

