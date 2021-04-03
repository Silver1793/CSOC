/**
 * @author Richard Li
 * @email rjl9943@nyu.edu
 * @create date 2021-02-24 00:34:51
 * @modify date 2021-02-24 00:34:51
 * @desc Uses functions to put elements into a tree shaped strucutre. Is able to insert the elements recursively and then
 * print out the tree once all elements have been added.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
NODE *root = NULL;
void rec_insert_node(NODE *n, NODE *r)
{
    if(strcmp(n->word, r->word) < 0)
    {
        if(r->left == NULL)
        {
            r->left = n;
            n->right = NULL;
            n->left = NULL;
        }
        else
        {
            rec_insert_node(n, r->left);
        }
    }
    else if(strcmp(n->word, r->word) > 0)
    {
        if(r->right == NULL)
        {
            r->right = n;
            n->left = NULL;
            n->right = NULL;
        }
        else
        {
            rec_insert_node(n, r->right); 
        }
    }
}
void insert_node(char *c)
{
    NODE* insert = (NODE*)malloc(sizeof(NODE));
    insert->word = c;
    insert->left = NULL;
    insert->right = NULL;
    if(root == NULL)
    {
        root = insert;
        root->left=NULL;
        root->right = NULL;
    }
    else
    {
        rec_insert_node(insert, root);
    }
}
void print_tree(NODE *r)
{
    if(r == NULL)
    {
        return;
    }
    print_tree(r->left);
    printf("%s\n", r-> word);
    print_tree(r->right);
}