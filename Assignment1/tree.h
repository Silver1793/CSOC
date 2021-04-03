
typedef struct node
{
    char *word;
    struct node *left;
    struct node *right;
}NODE;

extern NODE *root;

void rec_insert_node(NODE *n, NODE *r);
void insert_node(char *c);
void print_tree(NODE *r);