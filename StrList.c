#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

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
struct Node* creat_node(const char *str){
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
    struct _StrList *new_list = (struct _StrList*)malloc(sizeof(struct _StrList));
    //new_list->head = creat_node("");
    return new_list;
}

void StrList_free(StrList* StrList){
    struct Node *current = StrList->head;
    struct Node *next = NULL;
    
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(StrList);
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
    if (StrList->head == NULL)
    {
        StrList->head = creat_node(data);
    }
    
    else
    {
        struct Node *current = StrList->head;
        struct Node *new_node = creat_node(data);

        while (current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = new_node;
    }
}

void StrList_insertAt(StrList* StrList, const char* data, int index){
    if (StrList->head == NULL)
    {
        if (index == 0)
        {
            struct Node *new_node = creat_node(data);
            StrList->head = new_node;
        }
        
        else
        {
            return;

            // struct Node *new_node = creat_node(data);
            // StrList->head->next = StrList->head;
            // StrList->head = new_node;
        }
    }

    struct Node *current = StrList->head;
    int count = 0;

    if (index < 0)
    {
        printf("neggative index");
        return;
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
    struct Node *current = Strlist->head;
    int count = 0;

    if (current != NULL)
    {
        while (current != NULL)
        {
            count += strlen(current->data);
            current = current->next;
        }
    }

    else
    {
        printf("list is empty!");
    }

    return count;
}

int StrList_count(StrList* StrList, const char* data){
    struct Node *current = StrList->head;
    int count = 0;

    if (current != NULL)
    {
        while (current != NULL)
        {
            if (strcmp(current->data, data) == 0)
            {
                count++;
            }
            
            current = current->next;
        }
    }

    else
    {
        printf("list is empty!");
    }

    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    struct Node *current = StrList->head;
    int count = StrList_count(StrList, data);

    if (count == 0)
    {
        struct Node *last = current;
        while (count != 0)
        {
            if (strcmp(current->data, data) == 0)
            {
                if (last == current)
                {
                    StrList->head = current->next;

                    free(current->data);
                    free(current);

                    last = StrList->head;
                    current = StrList->head;
                }
                else
                {
                    last->next = current->next;

                    free(current->data);
                    free(current);

                    current = last->next;
                }

                count--;
            }
            
            last = current;
            current = current->next;
        }
    }

    else
    {
        printf("given string is not on the list!");
    }
}

void StrList_removeAt(StrList* StrList, int index){
    struct Node *current = StrList->head;
    int count = 0;

    if (index < 0)
    {
        printf("neggative index");
        return;
    }
    
    if (index == 0)
    {
        StrList->head = current->next;
        free(current->data);
        free(current);
    }
    
    else if (StrList_size(StrList) > index)
    {
        while (count != index-1)
        {
            current = current->next;
            count++;
        }

        struct Node *temp = current->next;
        current->next = temp->next;

        free(temp->data);
        free(temp);
    }

    else
    {
        printf("index too big");
    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (StrList_size(StrList1) != StrList_size(StrList2))
    {
        return 0;
    }

    struct Node *c1 = StrList1->head;
    struct Node *c2 = StrList2->head;

    while (c1 != NULL && c2 !=NULL)
    {
        if (!strcmp(c1->data, c2->data))
        {
            return 0;
        }
        
        c1 = c1->next;
        c2 = c2->next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList){
    if (StrList_size(StrList) <= 0)
    {
        return NULL;
    }

    struct _StrList *StrList_new = StrList_alloc();

    StrList_new->head->data = StrList->head->data;

    struct Node *c1 = StrList->head->next;
    struct Node *c2 = StrList_new->head->next;

    while (c1 != NULL)
    {
        c2->next = creat_node(c1->next->data);
        c2 = c2->next;
        c1 = c1->next;
    }
    return StrList_new;
}

void StrList_reverse( StrList* StrList){
    if (StrList_size(StrList) <= 0)
    {
        return;
    }
    
    struct _StrList *StrList_new = StrList_alloc();
    struct Node *current = StrList->head;
    struct Node *current_new = StrList_new->head;

    while (current != NULL)
    {
        struct Node *temp = creat_node(current->data);
        StrList_new->head = temp;
        StrList_new->head->next = current_new;
        current_new = StrList_new->head;
        current = current->next;
    }

    current_new = StrList_new->head;
    current = StrList->head;
    struct Node *temp;

    while (current_new != NULL)
    {
        temp = current_new;
        current->data = current_new->data;
        current_new = current_new->next;
        free(temp->data);
        free(temp);
    }
    
}

void StrList_sort( StrList* StrList){
    struct Node *sorted = NULL;
    struct Node *temp = NULL;
    struct Node *current = NULL;

    while (current != NULL)
    {
        current = StrList->head;
        StrList->head = StrList->head->next;

        if (sorted == NULL || strcmp(current->data, sorted->data) <= 0)
        {
            current->next = sorted;
            sorted = current;
        }
        
        else
        {
            temp = sorted;

            while (temp->next != NULL && strcmp(current->data, temp->next->data) > 0)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
        
    }
    StrList->head = sorted;
}

int StrList_isSorted(StrList* StrList){
    struct Node *current = StrList->head;

    while (current->next != NULL)
    {
        if (strcmp(current->data, current->next->data) > 0)
        {
            return 0;
        }
        
        current = current->next;
    }
    return 1;
}

void buildList(StrList* StrList, int length, char* str){
    int count = 0;
    int j = 0;
    char* substring;

    for (int i = 0; i < length; i++)
    {
        while (str[j] != ' ' && j < strlen(str))
        {
            count++;
            j++;
        }
        
        substring = (char*)malloc(count+1);
        strncpy(substring, str, count);
        
        StrList_insertLast(StrList, substring);
        
        j++;
        count = 0;
        str += j;
        j = 0;
        free(substring);
    }
    
}