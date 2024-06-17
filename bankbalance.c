#include <stdio.h>
#include <pthread.h>

int balance = 0;

void *deposit(void *amount) {
    int deposit_amount = *(int *)amount;
    int temp = balance; // Read current balance
    temp += deposit_amount; // Add deposit amount
    balance = temp; // Write updated balance
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int amount1 = 100;
    int amount2 = 200;
    
    pthread_create(&t1, NULL, deposit, &amount1);
    pthread_create(&t2, NULL, deposit, &amount2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Final balance: %d\n", balance);
    
    return 0;
}

