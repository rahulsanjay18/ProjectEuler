#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long brute_force();
long memoization();
int check_if_prime(int n);
int check_if_prime_memo(int n);

int primes_below = 2000000;
int* primes;
int j = -1;

int main(int argc, char *argv[]){
    clock_t begin = clock();

    long ans = brute_force();

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Answer: %ld\n", ans);
    printf("Time (brute_force): %lf\n", time_spent);

    begin = clock();

    // ans = memoization();

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Answer: %ld\n", ans);
    printf("Time (ordered_pair): %lf\n", time_spent);

    return 0;
}

long brute_force(){
    long sum = 0;
    for (int i = 2; i <= primes_below; i++){
        sum += check_if_prime(i) * i;
    }
    return sum;
}

long memoization(){
    
    long sum = 0;
    for(int i = 2; i <= primes_below; i++){
        if(check_if_prime_memo(i)){
            j++;
            printf("%i\n",j);
            primes = realloc(primes, j * sizeof(int));
            primes[j] = i;
            sum += i;
        }
    }

    return sum;

}

int check_if_prime_memo(int n){
    for(int i = 0; i <= j; i++){
        if (!(n % primes[i])){
            return 0;
        }
    }
    return 1;
}

int check_if_prime(int n){
    for (int i = 2; i * i <= n; i++){
        if (!(n % i)){
            return 0;
        }
    }
    
    return 1;
}