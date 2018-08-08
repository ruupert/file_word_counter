#include <stdlib.h>
#include <string.h>

#include "filesummary.h"
#include "filewordsummary.h"

FileSummary_t* fsum_create(char* name) {
FileSummary_t *tmp;
tmp = malloc(sizeof(FileSummary_t));
tmp->fname = malloc(sizeof(char)*(strlen(name)));
tmp->fname = name;
tmp->wcount=0;
  tmp->rcount=0;
  return tmp;
}
