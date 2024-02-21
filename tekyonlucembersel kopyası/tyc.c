#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tyc_lib.h"

int main(){
    int i;

    while(1){
        printf("Press 1 to see the list of the movies.\n");
        printf("Press 2 to add a new movie to the list.\n");
        printf("Press 3 to remove a movie from the list.\n");
        printf("Press 4 to search a movie from the list\n.");
        printf("Press 5 to exit the program.\n");
        scanf("%d", &i);

        if(i == 1){
            list();
        }

        if(i == 2){
            add();
        }

        if(i == 3){
            removee();
        }

        if(i == 4){
            search();
        }

        if(i == 5){
            exit(1);
        }
    }

    return 0;
}