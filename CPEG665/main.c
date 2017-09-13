//
//  main.c
//  CPEG665
//
//  Created by Hao Wang on 9/13/17.
//  Copyright © 2017 Hao Wang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    clock_t start, end;
    int i;
    int * data = malloc(sizeof(int) * 8000000);
    
    printf("Now trying method 1:\n");
    start = clock();
    for (i = 1; i <= 4000000; i++){
        data[2*i - 1] = data[2*i - 1] * 2;
        data[2*i - 2] = data[2*i - 2] * 3;
    }
    end = clock();
    printf("Finished! It took %lu CPU cycles.\n", (end - start));
    
    printf("\nNow trying method 2:\n");
    start = clock();
    for (i = 1; i <= 4000000; i++){
        data[2*i - 2] = data[2*i - 2] * 3;
        data[2*i - 1] = data[2*i - 1] * 2;
    }
    end = clock();
    printf("Finished! It took %lu CPU cycles.\n", (end - start));
    
    printf("\nNow trying method 3:\n");
    start = clock();
    for (i = 1; i <= 1000000; i++){
        for (int y = 0; y < 4; y++) {
            data[2*i - 1 + y*1000000] = data[2*i - 1 + y*1000000] * 2;
            data[2*i - 2 + y*1000000] = data[2*i - 2 + y*1000000] * 3;
            
        }
    }
    end = clock();
    printf("Finished! It took %lu CPU cycles.\n", (end - start));
    
    free(data);
    return 0;
}
