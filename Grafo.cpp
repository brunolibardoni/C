#include<stdio.h>
#include<stdlib.h>


	struct no{
		int cor = 0;
		int tam = 0;
		int inc = 0;
		int f = 0;
	};
	
	struct no gra[8][8];
	
	int qMaior(no[8][8]){
		int maior = 0;
		int i = 0 ;
		
		
		for(i = 0; i < 8; i++){
			if((gra[i][0].tam > maior) && (gra[i][0].f == 0)){
				maior = i + 1;
				gra[i][0].f = 1;
			}
		}
		
		return maior;
	}

int main(){
	int mGraf = 0;
	int mCor = 0 ;
	int cor = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			printf("\nIncidencia em no %i : %i | (0 - Nao | 1 - Sim ): ",i+1,j+1);
			scanf("%i", &gra[i][j].inc);
			
				if(gra[i][j].inc > 0){
					gra[i][0].tam++;
				}	
			}
		}
	
	printf("\nA incidencia na matriz: ");
		for(i = 0; i < 8; i++){
			printf("\nO no %i tem incidencia: ",i+1);
				for(j = 0; j < 8; j++){
					printf("%i ",gra[i][j].inc);
				}
				printf("\n");
			}

	printf("\nQUAL MAIOR GRAFO %i ",qMaior(gra));
	
	for(i = 0; i < 8; i++){
		mGraf = qMaior(gra);
		for(j = 0; j < 8; j++){
			if((gra[mGraf][0].cor == gra[j][0].cor) && (gra[mGraf][j].inc > 0)){
				cor = cor + 1;
			}
		}
		
		gra[mGraf][0].cor = cor;
		if(cor > mCor ){
			mCor = cor;
		}
		cor = 0;
	}
	
	printf("\nO numero de cores para pintar o grafo fazendo com que duas cores nao se encostem eh: %i", mCor);

	
}
