#ifndef WORD_COUNTER_FILEREADER
#define WORD_COUNTER_FILEREADER

#include <stdio.h>

typedef struct fp_obj {
  FILE *fp;
  int status; 
} fp_obj_t;

static fp_obj_t* filereadr_fres(void);
fp_obj_t* filereader_fopen(char* fname);
char* filereader_stat_str(int num);

#endif
