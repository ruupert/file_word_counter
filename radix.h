#ifndef WORDCOUNTER_RADIX
#define WORDCOUNTER_RADIX

typedef struct node {
  char key;
  int depth;
  struct node *next;
  struct node *childs;
  struct node *parent;
} node_t;

typedef struct head {
  int count;
  node_t *next;
} list_t;


list_t* radix_create_list(void);
node_t* radix_create_node(void);
node_t* radix_find_char(node_t *n, char c);
node_t* radix_find(node_t *n, char* str);
int radix_insert(node_t *n, char *str);
void radix_print(node_t *no, int lvl); 

#endif
