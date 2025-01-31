#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define TOTAL_NUMBERS 100 // Total numbers to print
#define ODD_COUNT 5       // Number of odd numbers to print in a sequence
#define EVEN_COUNT 4      // Number of even numbers to print in a sequence
sem_t sem_odd;
sem_t sem_even;

void *print_odd_numbers(void *arg) {
    int odd_number = 1;
    int printed_count = 0;

    while (printed_count < TOTAL_NUMBERS) {
        sem_wait(&sem_odd); // Wait for the odd semaphore

        // Print ODD_COUNT odd numbers in sequence
        for (int i = 0; i < ODD_COUNT && printed_count < TOTAL_NUMBERS; i++) {
            printf("%d ", odd_number);
            odd_number += 2; // Move to the next odd number
            printed_count++;
        }
        printf("\n");
        sem_post(&sem_even); // Signal the even semaphore
    }
    return NULL;
}

void *print_even_numbers(void *arg) {
    int even_number = 2;
    int printed_count = 0;

    while (printed_count < TOTAL_NUMBERS) {
        sem_wait(&sem_even); // Wait for the even semaphore

        // Print EVEN_COUNT even numbers in sequence
        for (int i = 0; i < EVEN_COUNT && printed_count < TOTAL_NUMBERS; i++) {
            printf("%d ", even_number);
            even_number += 2; // Move to the next even number
            printed_count++;
        }
        printf("\n");

        sem_post(&sem_odd); // Signal the odd semaphore
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize semaphores
    sem_init(&sem_odd, 0, 1);  // Start with odd semaphore available
    sem_init(&sem_even, 0, 0); // Start with even semaphore blocked

    // Create threads
    pthread_create(&thread1, NULL, print_odd_numbers, NULL);
    pthread_create(&thread2, NULL, print_even_numbers, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Clean up semaphores
    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);

    return 0;
}