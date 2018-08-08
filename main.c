#include <stdio.h>
#include <stdlib.h>

#include "radix.h"
#include "filereader.h"
#include "filesummary.h"
#include "filewordsummary.h"



int main(void) {
  // word storage
  list_t *tree = radix_create_list();
  radix_insert(tree->next, "jees");
  radix_insert(tree->next, "jeesissa");
  radix_insert(tree->next, "jes");
  radix_insert(tree->next, "jesse");
  node_t *res = radix_find(tree->next, "jes");
  
  if (res != NULL) {
	char* rstring = malloc(sizeof(char)*res->depth);
	for (int i = res->depth-1; i >= 0; i--) {
	  rstring[i] = res->key;
	  res = res->parent;
	}
	printf("%s\n", rstring);
	free(rstring);
	
  }
  FileSummary_t *nfsum = fsum_create("asdf.txt");
  printf("%s\n", nfsum->fname);


  /*
  fp_obj_t *fh_obj_found = filereader_fopen("words.txt");
  printf("file opened: %s\n", filereader_stat_str(fh_obj_found->status));

  fp_obj_t *fh_obj_notfound = filereader_fopen("notfound.txt");
  printf("file opened: %s\n", filereader_stat_str(fh_obj_notfound->status));
  */
  
  filereader_import("words.txt", tree->next);

  radix_print(tree->next, 0);
  
  return 0;
}
