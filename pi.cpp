#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>


int i;
int k;
sem_t mutex;
double calc = 0;

void *func(void *p){
	for (k = 0; k <= i; k++){
		calc = calc + pow(-1,k) / (2 * k + 1);
	}
	printf("Thread %d : %f\n",k, calc * 4);
	pthread_exit(NULL); //  saindo da thread que eu chamei
	sem_post (&mutex);
}

int main(){	
	pthread_t threads[1];
	sem_init(&mutex,0,1);
	
	for (i = 1; i <= 50; i++){
		calc = 0;
		pthread_create(&threads[0],NULL,func,(void *)1); // dando um create nas threads (criando elas)
		pthread_join(threads[0], NULL); //ira suspender a execucao do encadeamento que o chamou, a menos que o encademanto de destino termine
	}
}
