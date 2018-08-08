#ifndef FILESUMMARY
#define FILESUMMARY

#include "filewordsummary.h"

typedef struct FileSummary {
  // hashmap probably
  
  int wcount;
  int rcount;
  char* fname;
  
  
} FileSummary_t;

FileSummary_t* fsum_create(char* fname);

#endif
