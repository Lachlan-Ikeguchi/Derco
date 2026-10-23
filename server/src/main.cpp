#include "main.hpp"

void *print_number_function(void *ptr);

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];

    int integers[NUMBER_OF_THREADS];

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        integers[i] = i*2;
    }

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, print_number_function,
                       (int *)&integers[i]);
    }

    return 0;
}

void *print_number_function(void *ptr)
{
    int *number = (int *)ptr;
    printf("%i\n", *number);
    return NULL;
};
