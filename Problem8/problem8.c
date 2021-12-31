#include <stdio.h>
#include <time.h>

char refStr[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
int chain = 13;

int len(char str[]);
long prod(int low, int high);
long fancy();
long brute_force();


int main(int argc, char *argv[]){
    clock_t begin = clock();

    long max = fancy();

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Answer: %ld\n", max);
    printf("Time (fancy): %lf\n", time_spent);

    begin = clock();

    max = brute_force();

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time (brute_force): %lf\n", time_spent);

    return 0;
}

long fancy(){
    int length = len(refStr);

    long max = prod(0, chain);
    long curr = max;
    int i = chain;

    if(max < 0){
        i += -max;
        max = 0;
    }

    while(i < length){
        int newNum = refStr[i] - '0';
        if(newNum == 0){
            i += chain + 1;
            curr = prod(i - chain, i);
            continue;
        }
        int oldNum = refStr[i - chain] - '0';
        if(oldNum <= 0){
            i++;
            continue;
        }
        curr = curr / oldNum;
        curr *= newNum;

        max = (curr > max) ? curr : max;

        i++;
    }

    return max;
}

// brute force
long brute_force(){
    int length = len(refStr);
    long max = prod(0, chain);

    for (int i = 1; i < length - chain; i++){
        long new = prod(i, i + chain);
        max = (new > max) ? new : max;
    }

    return max;
}

int len(char str[]){
    int i = 0;
    while(str[++i] != 0);
    return i;
}

long prod(int low, int high){
    long product = 1;

    for(int i = low; i < high; i++){
        product *= refStr[i] - '0';
        if(product == 0){
            return -i;
        }
    }
    
    return product;
}