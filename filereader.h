#ifndef WORD_COUNTER_FILEREADER
#define WORD_COUNTER_FILEREADER

#include <stdio.h>

#include "radix.h"

typedef struct fp_obj {
  FILE *fp;
  int status; 
} fp_obj_t;

static fp_obj_t* filereadr_fres(void);
static fp_obj_t* filereader_fopen(char* fname);
int filereader_fread(fp_obj_t* fpr, node_t* tree);
char* filereader_stat_str(int num);
int filereader_import(char* name, node_t **tree);

#endif
