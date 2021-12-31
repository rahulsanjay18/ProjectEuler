#include <stdio.h>
#include <time.h>

long brute_force();
void print_ans(int ans[3]);

int main(int argc, char *argv[]){
    clock_t begin = clock();

    long ans = brute_force();

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Answer: %ld\n", ans);
    printf("Time: %lf\n", time_spent);

    return 0;
}

// got generator alg here: https://www.cuemath.com/geometry/pythagorean-triples/
long brute_force(){
    int add_up_to = 1000;

    // assune m > n
    int m = 2;
    int n = 1;

    // there is a cleaner way to do this, this gives me pain
    for(m = 2; 1; ++m){
        for(n = 1; n < m; ++n){
            if(2 * m * (m + n) == add_up_to){
                // if you're curious, these are the values for a, b, and c
                // printf("a: %i, b: %i, c: %i\n", (m*m - n*n), 2*m*n, (m*m + n*n));
                return (m*m - n*n) * 2*m*n * (m*m + n*n);
            }
        }
    }
    
    return -1;
    
}