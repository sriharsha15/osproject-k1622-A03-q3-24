#include<stdio.h>
#include<pthread.h>
void *function1();
int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,function1,NULL);
	pthread_join(thread1,NULL);
}

void *function1()
{
	int l,i,temp=0,p,t;
    printf("Enter the limit:");    
    scanf("%d",&l);    
    int list[l];    
    for(i=2;i<=l;i++){
        list[temp]=i;
        temp++;
    }    
    for(i=0;i<temp;i++){
        if(list[i]!=0){
            t=i;
            p=list[i];
            while((t+p)<temp){
                t=t+p;
                list[t]=0;
            }
        }
    }
    for(i=0;i<temp;i++){
        if(list[i]!=0)
            printf("%d, ",list[i]);
}
}
