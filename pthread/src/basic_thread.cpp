#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>//Thu vien da luong

#define THREADS_NUM 8

void* func_thread_1(void *ptr);//Khai bao ham luong 1
void* func_thread_2(void *ptr);//Khai bao ham luong 2

pthread_mutex_t lock;

int count = 0;


int main(void){

	pthread_t *thread = (pthread_t*) malloc(THREADS_NUM *sizeof(pthread_t)); //Con tro luong
	int iret;
	for(int i = 0; i < THREADS_NUM; i++){
		int arg = i;	

		iret = pthread_create(&thread[arg], NULL, func_thread_1, &arg);//khoi tao luong 1
		//printf("Ket qua tao luong %d: %d\n",arg, iret);
	}

	for(int i = 0; i < THREADS_NUM; i++){
		pthread_join(thread[i], NULL);//join that ca vao luong main
	}
		
	printf("value count: %d \n",count);
	free(thread);

	exit(0);//Ket thuc luong main
}

/*Ham thuc thi luong 1*/
void* func_thread_1(void* _arg){
	int i = 0;
	int value = *(int*)_arg;
	while(i < 1e4){
		i++;
		pthread_mutex_lock(&lock);
		//printf("[Luong %d] Dem = %d\n", value , count);
		++count;
		pthread_mutex_unlock(&lock);
		//sleep(1);//delay 2 giay
	}
	return NULL;	
}

/*Ham thuc thi luong 2*/
void *func_thread_2(void *ptr){
        while(count){
                printf("[Luong 2] Dem = %d\n",count);
		count++;
                sleep(0.5);//delay 2 giay
        }
	return NULL;
}
