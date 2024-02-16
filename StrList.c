#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <StrList.h>

//new
struct Node
{
    char *data;
    struct Node *next;
};

struct _StrList
{
    struct Node *head;
};

//new
struct Node* creat_node(char *str){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = strdup(str);
    new_node->next = NULL;

    return new_node;
}


StrList* StrList_alloc(){

}

void StrList_free(StrList* StrList){
    struct Node *current = StrList->head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

size_t StrList_size(const StrList* StrList){
    struct Node *current = StrList->head;
    size_t count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    
    return count;
}

void StrList_insertLast(StrList* StrList, const char* data){
    struct Node *current = StrList->head;
    struct Node *new_node = creat_node(data);

    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = new_node;
}

void StrList_insertAt(StrList* StrList, const char* data, int index){
    struct Node *current = StrList->head;
    int count = 0;

    if (index < 0)
    {
        printf("neggative index");
        return;
    }
    
    if (index == 0)
    {
        struct Node *new_node = creat_node(data);
        new_node->next = current;
        StrList->head = new_node;
    }
    
    else if (StrList_size(StrList) >= index)
    {
        while (count != index-1)
        {
            current = current->next;
            count++;
        }
    
        if (current->next == NULL)
        {
            struct Node *new_node = creat_node(data);
            current->next = new_node;
        }

        else
        {
            struct Node *temp = current->next;
            struct Node *new_node = creat_node(data);
            current->next = new_node;
            new_node->next = temp;
        }
    }

    else
    {
        printf("index too big");
    }
}

char* StrList_firstData(const StrList* StrList){
    return StrList->head->data;
}

void StrList_print(const StrList* StrList){
    struct Node *current = StrList->head;

    if (current != NULL)
    {
        while (current->next != NULL)
        {
            printf("%s ", current->data);
            current = current->next;
        }
    
        printf("%s\n", current->data);
    }

    else
    {
        printf("list is empty!");
    }
}

void StrList_printAt(const StrList* Strlist,int index){
    struct Node *current = Strlist->head;
    int count = 0;

    if (index < 0)
    {
        printf("neggative index");
        return;
    }
    
    if (StrList_size(Strlist) >= index)
    {
        while (count != index)
        {
            count++;
            current = current->next;
        }
    
        printf("%s\n", current->data);
    }

    else
    {
        printf("index too big");
    }
}

int StrList_printLen(const StrList* Strlist){
    
}