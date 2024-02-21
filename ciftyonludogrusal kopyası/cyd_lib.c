#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LIB_H_
#define LIB_H_
#endif

struct favfilms{
    char name[40];
    char director[40];
    float imdb;
    int rate;
    struct favfilms *next;
    struct favfilms *prev;
};

struct favfilms *head = NULL;
typedef struct favfilms Favfilms;

void list(){
    int a=1;
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        Favfilms *tmp = head;
        while(tmp != NULL){
            printf("%d.%s\t%s\t%0.1f\t%d\n", a, tmp->name, tmp->director, tmp->imdb, tmp->rate);
            tmp = tmp->next;
            a++;
        }
    }
}

void add(){
    Favfilms *newfilm = (Favfilms*)malloc(sizeof(Favfilms));
    printf("Entry the informations of the film you want to add to the list:\n");
    printf("Name: ");
    scanf("%s", newfilm->name);
    printf("Director: ");
    scanf("%s", newfilm->director);
    printf("Imdb: ");
    scanf("%f", &newfilm->imdb);
    printf("Your rate:");
    scanf("%d", &newfilm->rate);

    if(head == NULL){
        head = newfilm;
    }

    else{
        Favfilms *tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newfilm;
        newfilm->prev = tmp;
        newfilm->next = NULL;
    }
}

void removee(){
    char name[40];
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        printf("Entry name of the film you want to remove from the list: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        Favfilms *tmp2 = head->next;
        Favfilms *tmp3 = head->prev;
        while(tmp->next != NULL){
            if(strcmp(tmp->name, name) == 0){
                tmp3->next = tmp->next;
                tmp2->prev = tmp->prev;
                free(tmp);
                tmp->next = NULL;
                tmp->prev = NULL;
                printf("You removed the film.\n");
                list(head);
            }
            tmp = tmp2;
            tmp2 = tmp->next;
            tmp3 = tmp->prev;
        }
        if(tmp->next == NULL && strcmp(tmp->name, name) == 0){
            tmp3->next = NULL;
            free(tmp);
            tmp->next = NULL;
            tmp->prev = NULL;
        }
    }
}

void search(){
    char name[40];
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        printf("Entry the name of the movie you want to search: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        while(tmp->next != NULL){
            if(strcmp(tmp->name, name) == 0){
                printf("Informations of the movie you've searched:\n");
                printf("Name: %s", tmp->name);
                printf("Director: ", tmp->director);
                printf("Imdb: %0.1f", tmp->imdb);
                printf("Rate: %d", tmp->rate);
            }
            tmp = tmp->next;
        }
        if(tmp->next == NULL && strcmp(tmp->name, name) == 0){
            printf("Informations of the movie you've searched:\n");
            printf("Name: %s\n", tmp->name);
            printf("Director: %s\n", tmp->director);
            printf("Imdb: %0.1f\n", tmp->imdb);
            printf("Rate: %d\n", tmp->rate);
        }
    }
}