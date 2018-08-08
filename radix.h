#ifndef WORDCOUNTER_RADIX
#define WORDCOUNTER_RADIX

#define STRREP_MAX_CHARS 1024
#define STRREP_INIT static char __strrep_buffer[STRREP_MAX_CHARS]
#define STRREP(str, nrep) strrep(str, nrep) ? __strrep_buffer : ""

char *strrep(const char *str, int nrep);


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
void radix_print_arr(node_t *no, int lvl, char* prefix); 

#endif
