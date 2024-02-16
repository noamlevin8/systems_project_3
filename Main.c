#include <stdio.h>
#include "StrList.h"

int main(){
    char c;
    char *str;
    int index;
    int num;
    struct StrList *strlist = StrList_alloc();

    printf("1 - Insert string to the list\n");
    printf("2 - Insert string at a disired index\n");
    printf("3 - Print the list\n");
    printf("4 - Print the list length\n");
    printf("5 - Print string at desired index\n");
    printf("6 - Print the number of chars in the list\n");
    printf("7 - Insert a string and print how many times it is found on the list\n");
    printf("8 - Insert a string and remove all appearances from the list\n");
    printf("9 - Remove string at a given index\n");
    printf("10 - Reversing the list\n");
    printf("11 - Deleting the list\n");
    printf("12 - Sort the list in lexicographical order\n");
    printf("13 - Check if the list sorted lexicographically\n");
    printf("0 - Exit\n");

    scanf("%c", &c);

    while (c != '0')
    {
        if (c == '1')
        {
            scanf("%d", &num);
            scanf("%s", &str);
            buildList(strlist, num, str);
        }
        
        if (c == '2')
        {
            scanf("%d", &index);
            scanf("%s", &str);
            StrList_insertAt(strlist, str, index);
        }

        if (c == '3')
        {
            StrList_print(strlist);
        }

        if (c == '4')
        {
            printf(StrList_size(strlist));
        }

        if (c == '5')
        {
            scanf("%d", &index);
            StrList_printAt(strlist, index);
        }

        if (c == '6')
        {
            printf(StrList_printLen(strlist));
        }

        if (c == '7')
        {
           scanf("%s", &str);
           printf(StrList_count(strlist, str)); 
        }

        if (c == '8')
        {
            scanf("%s", &str);
            StrList_remove(strlist, str);
        }

        if (c == '9')
        {
            scanf("%d", &index);
            StrList_removeAt(strlist, index);
        }

        if (c == '10')
        {
            StrList_reverse(strlist);
        }

        if (c == '11')
        {
            StrList_free(strlist);
        }

        if (c == '12')
        {
            StrList_sort(strlist);
        }

        if (c == '13')
        {
            printf(StrList_isSorted(strlist));
        }
    }
    
}