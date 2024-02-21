#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LIB_H_
#define LIB_H_
#endif

struct favfilms{//listenin dugumlerini temsil etmek icin kullanilan yapinin 4 tanesi deger 1 tanesi gosterici olan 5 alani var
    char name[40];
    char director[40];
    float imdb;
    int rate;
    struct favfilms *next;
};

struct favfilms *head = NULL; //listenin ilk deger atamasini yapar
typedef struct favfilms Favfilms; 


void list(){//listedeki butun filmleri ekrana bastirir
    if(head == NULL){
        printf("This list is empty.");
    }
    else {
        int a=1;
        Favfilms *tmp = head;
        while(tmp != NULL){
            printf("%d.%s\t%s\t%0.1f\t%d\n",a, tmp->name, tmp->director, tmp->imdb, tmp->rate);
            tmp = tmp->next;
            a++;
        }
    }
}

void add(){//listeye yeni bir eleman ekler
    Favfilms *newfilm = (Favfilms*)malloc(sizeof(Favfilms));//ekleyeceğim eleman icin hafizada yer acar
    printf("Entry the informations of the film you want to add to the list(Use '-' instead of space please:D)\n");
    printf("Name: ");
    scanf("%s", newfilm->name);
    printf("Director: ");
    scanf("%s", newfilm->director);
    printf("Imdb: ");
    scanf("%f", &newfilm->imdb);
    printf("Your rate: ");
    scanf("%d", &newfilm->rate);

    if(head == NULL){//listedeki eleman sayisi sifir ise
        head = newfilm;
    }

    else{
        Favfilms *tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp-> next = newfilm;
        newfilm->next = NULL;
    }
}

void removee(){//listeden eleman siler(ilk elemani silemiyor :( )
    char name[40];
    if(head == NULL){
        printf("This list is empty\n");
    }
    else{
        int a=0;
        printf("Entry the name of the film you want to remove from the list: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        Favfilms *tmp2 = head->next;
        while(tmp2 != NULL){
            if(strcmp(tmp2->name, name) == 0){
                tmp->next = tmp2->next;
                free(tmp2);
                tmp2->next = NULL;
                a=1;
            }
            tmp = tmp2;
            tmp2 = tmp->next;
        }
        if(a==0){
            printf("This film is not added to the list.\n");
        }
    }
}

void search(){//listeden bulmak istediginiz elemani arar
    char name[40];
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        printf("Entry the name of the film you want to search: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        while(tmp != NULL){
            if(strcmp(tmp->name, name) == 0){
                printf("Name: %s\n", tmp->name);
                printf("Director: %s\n", tmp->director);
                printf("Imdb: %0.1f\n", tmp->imdb);
                printf("Rate: %d\n", tmp->rate);
            }
            tmp = tmp->next;
        }
    }
}