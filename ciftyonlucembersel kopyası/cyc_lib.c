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
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        int a=1;
        if(head->next == NULL){
            printf("%d.%s\t%s\t%0.1f\t%d\n", a, head->name, head->director, head->imdb, head->rate);
        }
        else{
            Favfilms *tmp = head;
            while(tmp->next != head){
                printf("%d.%s\t%s\t%0.1f\t%d\n", a, tmp->name, tmp->director, tmp->imdb, tmp->rate);
                tmp = tmp->next;
                a++;
            }
            if(tmp->next == head){
                printf("%d.%s\t%s\t%0.1f\t%d\n", a, tmp->name, tmp->director, tmp->imdb, tmp->rate);
        }
        }
    }
}

void add(){
    Favfilms *newfilm = (Favfilms*)malloc(sizeof(Favfilms));
    printf("Entry informations of the movie you want to add to the list:\n");
    printf("Name: ");
    scanf("%s",  newfilm->name);
    printf("Director: ");
    scanf("%s", newfilm->director);
    printf("Imdb: ");
    scanf("%f", &newfilm->imdb);
    printf("Your rate: ");
    scanf("%d", &newfilm->rate);

    if(head == NULL){
        head = newfilm;
    }
    else if(head->next == NULL){
        head->next = newfilm;
        newfilm->next = head;
        head->prev = newfilm;
        newfilm->prev = head;
    } 
    else{
        Favfilms *tmp = head;
        while(tmp->next != head){
            tmp=tmp->next;
        }
        tmp->next = newfilm;
        newfilm->next = head;
        head->prev = newfilm;
        newfilm->prev = tmp;
    }
}

void removee(){
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        char name[40];
        printf("Entry the name of the movie you want to remove from the list: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        while(tmp->next != head){    
            Favfilms *tmpp = tmp->prev;
            Favfilms *tmpn = tmp->next;
            if(strcmp(tmp->name, name) == 0){
                free(tmp);
                tmpp->next = tmpn;
                tmpn->prev = tmpp;        
            }
            tmp = tmp->next;
        }
        if(tmp->next == head && strcmp(tmp->name, name) == 0){
            Favfilms *tmpp = tmp->prev;
            Favfilms *tmpn = tmp->next;
            free(tmp);
            tmpp->next = tmpn;
            tmpn->prev = tmpp; 
        }
    }
}

void search(){
    if(head == NULL){
        printf("This list is empty.");
    }
    else{
        char name[40];
        printf("Entry the name of the movie you want to search: ");
        scanf("%s", name);
        Favfilms *tmp = head;
        while(tmp->next != head){
            if(strcmp(tmp->name, name) == 0){
                printf("Name: %s\n", tmp->name);
                printf("Director: %s\n", tmp->director);
                printf("Imdb Score: %0.1f\n", tmp->imdb);
                printf("Rate: %d\n", tmp->rate);
            }
            tmp = tmp->next;
        }
        if(tmp->next == head && strcmp(tmp->name, name) == 0){
            printf("Name: %s\n", tmp->name);
            printf("Director: %s\n", tmp->director);
            printf("Imdb Score: %0.1f\n", tmp->imdb);
            printf("Rate: %d\n", tmp->rate);
        }
    }
}