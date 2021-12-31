#include <stdio.h>
#include <time.h>

long brute_force();
long ordered_pair();

int add_up_to = 1000;

int main(int argc, char *argv[]){
    clock_t begin = clock();

    long ans = brute_force();

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Answer: %ld\n", ans);
    printf("Time (brute_force): %lf\n", time_spent);

    begin = clock();

    ans = ordered_pair();

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time (ordered_pair): %lf\n", time_spent);

    return 0;
}

// got generator alg here: https://www.cuemath.com/geometry/pythagorean-triples/
long ordered_pair(){
    
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

long brute_force(){
    for(int c = 0; 1; c++){
        for(int b = 0; b < c; b++){
            for(int a = 0; a < b; a++){
                if(a*a + b*b == c*c){
                    if(a + b + c == 1000){
                        return a * b * c;
                    }
                }
            }
        }
    }
    return -1;
}