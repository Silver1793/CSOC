/**
 * @author Richard Li
 * @email rjl9943@nyu.edu
 * @create date 2021-02-24 00:30:02
 * @modify date 2021-02-24 00:30:02
 * @desc Creates an array of hashcell pointers where each element in the array will hold a linked list.
 * Will tak an input from a file and put each line from the file into its corresponding linked list in the array.
 * Links with tree.c and creates a binary tree based on the inputs in the linked list for each element in the array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct hashcell
{
    char *word;
    struct hashcell *next;
}HASHCELL;

#define SIZE 100
HASHCELL *hashtable[SIZE] = {NULL};

int hash_string(char *c)
{
    unsigned int hash = 1;
    int i =0;
    while(c[i] != 0)
    {
        hash = (hash * 7)+c[i];
        i++;
    }
    return hash%SIZE;
}

void insert_hash_cell(char *c)
{
    HASHCELL *head = (HASHCELL*)malloc(sizeof(HASHCELL));
    head->next = NULL;
    unsigned int index = hash_string(c);

    int boolean = 1;
    HASHCELL *cell = (HASHCELL*)malloc(sizeof(HASHCELL));
    cell->word = (char*)malloc((sizeof(char))*(strlen(c)+1));
    strcpy(cell->word, c);
    cell->next = NULL;

    if(hashtable[index] == NULL)
    {
        hashtable[index] = cell;
        head = cell;
        head->next = NULL;
        hashtable[index]->next = NULL;
    }
    else if(hashtable[index]->next == NULL)
    {
        if(strcmp(hashtable[index]->word,c) != 0)
        {
            hashtable[index]->next = cell;
            cell -> next = NULL;
        }
        else
            return;
    }
    else
    {
        head = hashtable[index];
        while(hashtable[index]->next != NULL)
        {
            if(strcmp(hashtable[index]->word, c) != 0)
            {
                hashtable[index] = hashtable[index]->next;
            }
            else
            {
                boolean = 0;
                break;
            }
        }
        if(boolean != 0 && strcmp(hashtable[index]->word, c) != 0)
        {
            hashtable[index]->next = cell;
            cell->next = NULL;
        }
        hashtable[index] = head;
    }
}
void print_hash_table()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashtable[i] == NULL)
        {
            continue;
        }
        printf("%d: ", i);
        while(hashtable[i] !=NULL)
        {
            printf("%s ", hashtable[i]->word);
            hashtable[i] = hashtable[i]->next;
        }
        printf("\n");
    }
}
int main()
{
    int count = 0;
    char str[100];
    while(scanf("%s", str) != EOF)
    {
        insert_hash_cell(str);
    }
    for(int i = 0; i < SIZE; i++)
    {
        while(hashtable[i] != NULL)
        {
            insert_node(hashtable[i]->word);
            hashtable[i] = hashtable[i]->next;
        }
    }
    print_tree(root);
    //print_hash_table();
    return 0;
}