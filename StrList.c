#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <StrList.h>

struct Node
{
    char *str;
    struct Node *next;
};

struct StrList
{
    struct Node *head;
};

struct Node* creat_node(char *str){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->str = strdup(str);
    new_node->next = NULL;

    return new_node;
}


StrList* StrList_alloc(){

}

void StrList_free(StrList* StrList){

}