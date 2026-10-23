#include "main.hpp"

void *print_message_function(void *ptr);

int main(int argc, char *argv[])
{
    pthread_t Thread1, Thread2;

    char *message1 = "hello";
    char *message2 = "world";

    int thread1, thread2;

    thread1 = pthread_create(&Thread1, NULL, print_message_function,
                             (void *)message1);
    thread2 = pthread_create(&Thread2, NULL, print_message_function,
                             (void *)message2);

    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);

    printf("Thread 1 returns: %d\n", thread1);
    printf("Thread 2 returns: %d\n", thread2);

    return 0;
}

void *print_message_function(void *ptr)
{
    char *message = (char *)ptr;
    printf("%s\n", message);
    return NULL;
};
