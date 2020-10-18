#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* fun1()
{
    int n = 1000;
    while(n)
    {
        sleep(1);
        printf("Hello World Thread1-%d\n", n);
        n--;
    }
}

void* fun2()
{
    int n = 1000;
    while(n)
    {
        sleep(1);
        printf("Hello World Thread2-%d\n", n);
        n--;
    }
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    //pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);
    int n;
    scanf("%d", &n);
    return 0;
}
