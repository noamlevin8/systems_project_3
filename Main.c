#include <stdio.h>
#include <string.h>
#include "StrList.h"

char *get_word() 
{ 
    int capacity = 10; 
    char* word = (char*)malloc(capacity * sizeof(char)); 
    int i = 0; char c; 
    while (1) 
    { 
        c = getchar(); 
        if (c == ' ' || c == '\n') 
        { 
            if (i == 0) 
            { 
                continue; 
            } 
            word[i] = '\0'; 
            break;
        } 
        word[i] = c; i++; 
        if (i >= capacity) 
        { 
            capacity *= 2; 
            word = realloc(word, capacity * sizeof(char));
        }
    }
    return word; 
}

int main()
{
    int length;
    char *str;
    int index;
    int num;
    struct _StrList *strlist = StrList_alloc();

    scanf("%d", &num);

    while (num != 0)
    {   
        if (num == 1)
        {
            scanf(" %d", &length);

            for (int i = 0; i < length; i++)
            {
                str = get_word();
                StrList_insertLast(strlist, str);
                free(str);
            }
        }
        if (num == 2)
        {
            scanf(" %d", &index);
            str = get_word();
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
            str = get_word();
            printf("%d\n", StrList_count(strlist, str));
            free(str); 
        }

        if (num == 8)
        {
            str = get_word();
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