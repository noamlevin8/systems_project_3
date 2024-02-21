#include <stdio.h>
#include <string.h>
#include "StrList.h"

#define Max_Size_Str 100

int main(){
    int length;
    char *str;
    int index;
    int num;
    struct _StrList *strlist = StrList_alloc();

    // printf("1 - Insert string to the list\n");
    // printf("2 - Insert string at a disired index\n");
    // printf("3 - Print the list\n");
    // printf("4 - Print the list length\n");
    // printf("5 - Print string at desired index\n");
    // printf("6 - Print the number of chars in the list\n");
    // printf("7 - Insert a string and print how many times it is found on the list\n");
    // printf("8 - Insert a string and remove all appearances from the list\n");
    // printf("9 - Remove string at a given index\n");
    // printf("10 - Reversing the list\n");
    // printf("11 - Deleting the list\n");
    // printf("12 - Sort the list in lexicographical order\n");
    // printf("13 - Check if the list sorted lexicographically\n");
    // printf("0 - Exit\n");

    scanf("%d", &num);

    while (num != 0)
    {
        if (num == 1)
        {
            scanf(" %d", &length);
            str = (char*)malloc(Max_Size_Str*length);
            scanf(" %[^\n]s", str);
            printf("%s", str);
            str = realloc(str, strlen(str));
            buildList(strlist, length, str);
            free(str);
        }
        
        if (num == 2)
        {
            str = (char*)malloc(Max_Size_Str);
            scanf(" %d", &index);
            scanf(" %s", str);
            StrList_insertAt(strlist, str, index);
            free(str);
        }

        if (num == 3)
        {
            StrList_print(strlist);

        }

        if (num == 4)
        {
            printf("%zu\n", StrList_size(strlist));
        }

        if (num == 5)
        {
            scanf(" %d", &index);
            StrList_printAt(strlist, index);
        }

        if (num == 6)
        {
            printf("%d\n", StrList_printLen(strlist));
        }

        if (num == 7)
        {
            str = (char*)malloc(Max_Size_Str);
            scanf(" %s", str);
            printf("%d\n", StrList_count(strlist, str));
            free(str); 
        }

        if (num == 8)
        {
            str = (char*)malloc(Max_Size_Str);
            scanf(" %s", str);
            StrList_remove(strlist, str);
            free(str);
        }

        if (num == 9)
        {
            scanf(" %d", &index);
            StrList_removeAt(strlist, index);
        }

        if (num == 10)
        {
            StrList_reverse(strlist);
        }

        if (num == 11)
        {
            StrList_free(strlist);
        }

        if (num == 12)
        {
            StrList_sort(strlist);
        }

        if (num == 13)
        {
            if (StrList_isSorted(strlist))
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
        
        scanf(" %d", &num);
    }
    StrList_free(strlist);
    free(strlist);
}