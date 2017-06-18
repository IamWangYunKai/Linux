#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct __arg{
	int n;
	int *arr;
} arg;

void *thread(void *vargp){
	pthread_detach(pthread_self());
	arg *args = (arg *)vargp;
	int n=args->n;
	int *arr = args->arr;

	arr[0]=1;
	arr[1]=1;

	int i;
	for(i=2;i<n;++i){
		arr[i]=arr[i-1]+arr[i-2];
	}
	
	return NULL;
}

int main(void){
	int n;
	printf("请输入要计算的个数：");
	scanf("%d",&n);

	if(n<2){
		printf("Error!\n");
		exit(1);
	}

	int *arr=malloc(n*sizeof(int));
	memset(arr,0,sizeof(int)*n);
	arg *args=malloc(sizeof(arg));
	args->n=n;
	args->arr=arr;

	pthread_t tid;
	pthread_create(&tid, NULL ,thread, (void *)args);
	pthread_join(tid, NULL);
	
	int i;
	printf("斐波那契数列结果为：\n");
	for(i=0;i<n;++i){
		printf("%d\n", arr[i]);
	}
	
	return 0;
}
