/*
 * fibonacci.c
 *
 *  Created on: 30th March 2020
 *      Author: M.Marconi
 */

#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include <unistd.h>;

unsigned long * copy_reverse(unsigned long ** array, unsigned int n){
    unsigned long arr[n+1];
    unsigned int j = n;
    for(unsigned int i = 0; i < n+1; i++){
        arr[i] = *array[j];
        j--;
    }
    for(int i = 0; i < n+1; i++){
        *array[i] = arr[i];
    }
    return *array;
}

void bubblesort(unsigned long * array, unsigned int n){
    unsigned int k = n;
    while(k > 0){
        int ultimoCambio = 0;
        for(int i = 0; i < k; i++){
            if(array[i] > array[i+1]){
                swap_int(&array[i], &array[i+1]);
                ultimoCambio = i;
            }
        }
        k = ultimoCambio;
    }
}

unsigned long fibonacci(unsigned int n){
    unsigned long arr[n+1];
    if(n == 0){
        return n;
    }else if(n == 1){
        return n;
    }else if(n > 1){
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i < n+1; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
}

unsigned long * fibonacci_array(unsigned int n){
    unsigned long arr[n+1];
    for(unsigned int i = 0; i < n+1; i++){
        arr[i] = fibonacci(i);
    }
    return arr;
}

int main(int argc, char * argv[]){
    unsigned long fibonacci_result[40];
    fibonacci_result = fibonacci_array(39);
    unsigned long fibonacci_result_copy[40];
    fibonacci_result_copy = copy_reverse(&fibonacci_result, 40);
    bubblesort(fibonacci_result_copy);
    int result = memcmp(fibonacci_result, fibonacci_result_copy, 40 * sizeof(unsigned long));
    if(result == 0){
        printf("Tutto ha funzionato correttamente\n");
    } else{
        printf("Qualcosa è andato storto, il risultato di memcmp è %d.\n", result);
    }
    return 0;
}


