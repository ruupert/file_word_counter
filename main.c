#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radix.h"
#include "filereader.h"
#include "filesummary.h"
#include "filewordsummary.h"


void clear() {
    char c;
    while ((c = getchar() != '\n') && (c != EOF));
}



int main(void) {
  // word storage
  list_t *tree = radix_create_list();
  char choise;
  char name[64];

  while(1) {
	printf("\nActions: (i)mport file, (f)ind word, (p)rint tree, (q)uit\n");
	choise = (char) getchar();
	switch (choise) {
	case 'i': case 'I':
	  scanf("%64s", name);
	  //	  printf("strlen %d\n", strlen(name));
	  char *fname = malloc(sizeof(char)*(strlen(name)));
	  for (int i = 0; i < strlen(name); i++) {
		fname[i] = name[i];
	  }
	  //	  fname[9] = '\0';
	  //printf("%s length is %d\n", fname, strlen(fname));
	  filereader_import(fname, &tree->next);
	  break;
	case 'f': case 'F':
	  break;
	case 'p': case 'P':
	  radix_print(tree->next, 0);
	  break;
	case 'q': case 'Q':
	  return 0;
	default:
	  printf("Illegal action\n");
	  break;
	}
	clear();
  }
  
  //  filereader_import("words.txt", tree->next);

  //  radix_print(tree->next, 0);
  
  return 0;
}


/*
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


  fp_obj_t *fh_obj_found = filereader_fopen("words.txt");
  printf("file opened: %s\n", filereader_stat_str(fh_obj_found->status));

  fp_obj_t *fh_obj_notfound = filereader_fopen("notfound.txt");
  printf("file opened: %s\n", filereader_stat_str(fh_obj_notfound->status));
  */

