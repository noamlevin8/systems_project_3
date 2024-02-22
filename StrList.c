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
    size_t size;
};

//new
struct Node* create_node(const char *str){
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

    if (new_list == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return new_list;
}

void StrList_free(StrList* StrList){
    if (StrList == NULL)
    {
        return;
    }
    
    struct Node *current = StrList->head;
    struct Node *next = NULL;
    StrList->head = NULL;
    
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    StrList->size = 0;
}

size_t StrList_size(const StrList* StrList){
    return StrList->size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    if (StrList == NULL)
    {
        return;
    }
    
    if (StrList->head == NULL)
    {
        StrList->head = create_node(data);
    }
    
    else
    {
        struct Node *current = StrList->head;
        struct Node *new_node = create_node(data);

        while (current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = new_node;
    }
    StrList->size++;
}

void StrList_insertAt(StrList* StrList, const char* data, int index){
    if (StrList == NULL)
    {
        return;
    }

    if (StrList->head == NULL)
    {
        if (index == 0)
        {
            struct Node *new_node = create_node(data);
            StrList->head = new_node;
        }
        
        else
        {
            return;
        }
    }
    else
    {
        struct Node *current = StrList->head;
        int count = 0;

        if (index < 0)
        {
            // neggative index
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
                struct Node *new_node = create_node(data);
                current->next = new_node;
            }

            else
            {
                struct Node *temp = current->next;
                struct Node *new_node = create_node(data);
                current->next = new_node;
                new_node->next = temp;
            }
        }

        else
        {
            // index too big
            return;
        }
    }
    StrList->size++;
}

char* StrList_firstData(const StrList* StrList){
    if (StrList == NULL)
    {
        return NULL;
    }
    
    return StrList->head->data;
}

void StrList_print(const StrList* StrList){
    if (StrList == NULL)
    {
        printf("\n");
        return;
    }
    
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
}

void StrList_printAt(const StrList* Strlist,int index){
    if (Strlist == NULL)
    {
        printf("\n");
        return;
    }
    
    struct Node *current = Strlist->head;
    int count = 0;

    if (index < 0)
    {
        // neggative index
        return;
    }
    
    if (StrList_size(Strlist) > index)
    {
        while (count != index)
        {
            count++;
            current = current->next;
        }
    
        printf("%s\n", current->data);
    }
}

int StrList_printLen(const StrList* Strlist){
    if (Strlist == NULL)
    {
        return 0;
    }

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

    return count;
}

int StrList_count(StrList* StrList, const char* data){
    if (StrList == NULL)
    {
        return 0;
    }

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

    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    if (StrList == NULL)
    {
        return;
    }

    struct Node *current = StrList->head;
    int count = StrList_count(StrList, data);

    if (count != 0)
    {
        struct Node *last = current;
        struct Node *temp;
        while (count != 0)
        {
            if (strcmp(current->data, data) == 0)
            {
                if (last == current)
                {
                    StrList->head = current->next;
                    last = StrList->head;
                    temp = current;
                    current = StrList->head;

                    free(temp->data);
                    free(temp);
                }
                else
                {
                    last->next = current->next;
                    temp = current;
                    current = last->next;

                    free(temp->data);
                    free(temp);
                }

                count--;
            }
            else
            {
                last = current;
                current = current->next;
            }
        }
        StrList->size--;
    }
}

void StrList_removeAt(StrList* StrList, int index){
    if (StrList == NULL || StrList->head == NULL)
    {
        return;
    }

    struct Node *current = StrList->head;
    int count = 0;

    if (index < 0)
    {
        // neggative index
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
        // index too big
        return;
    }
    StrList->size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (StrList1 == NULL || StrList2 == NULL)
    {
        return 0;
    }
    
    if (StrList_size(StrList1) != StrList_size(StrList2))
    {
        return 0;
    }

    struct Node *c1 = StrList1->head;
    struct Node *c2 = StrList2->head;

    while (c1 != NULL && c2 != NULL)
    {
        if (strcmp(c1->data, c2->data) != 0)
        {
            return 0;
        }
        
        c1 = c1->next;
        c2 = c2->next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList){
    if (StrList == NULL || StrList_size(StrList) <= 0)
    {
        return NULL;
    }

    char* str;
    struct _StrList *StrList_new = StrList_alloc();

    str = (char*)malloc(strlen(StrList->head->data));
    strcpy(str, StrList->head->data);
    StrList_new->head = create_node(str);
    free(str);

    struct Node *c1 = StrList->head;
    struct Node *c2 = StrList_new->head;

    while (c1->next != NULL)
    {
        str = (char*)malloc(strlen(c1->next->data));
        strcpy(str, c1->next->data);
        c2->next = create_node(str);
        free(str);
        c2 = c2->next;
        c1 = c1->next;
    }

    StrList_new->size = StrList_size(StrList);
    return StrList_new;
}

void StrList_reverse( StrList* StrList){
    if (StrList == NULL || StrList_size(StrList) <= 1)
    {
        return;
    }
    
    struct Node *last = NULL;
    struct Node *current = StrList->head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = last;
        last = current;
        current = next;
    }

    StrList->head = last;
}

void StrList_sort( StrList* StrList){
    if (StrList == NULL || StrList_size(StrList) <= 1)
    {
        return;
    }
    
    struct Node *sorted = NULL;
    struct Node *temp = NULL;
    struct Node *current = NULL;

    while (StrList->head != NULL)
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
    if (StrList == NULL)
    {
        return 0;
    }
    
    struct _StrList* strlist_c = StrList_clone(StrList);
    StrList_sort(strlist_c);
    int result =  StrList_isEqual(StrList, strlist_c);

    StrList_free(strlist_c);
    free(strlist_c);

    return result;
}

void buildList(StrList* StrList, int length, char* str){
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        char* substring;
        while (str[j] != ' ' && j < strlen(str))
        {
            j++;
        }
        
        substring = (char*)malloc(j+1);
        strncpy(substring, str, j);
        substring[j] = '\0';
        
        StrList_insertLast(StrList, substring);
        
        j++;
        str += j;
        j = 0;
        free(substring);
    }
}