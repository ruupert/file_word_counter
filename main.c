#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radix.h"
#include "filereader.h"
#include "filesummary.h"
#include "filewordsummary.h"


void clear() {
  while (getchar() != '\n');
  //  char c;
  //  while ((c = getchar() != '\n') && (c != EOF));
}

int mainloop(list_t *tree) {

  char choise;
  char name[64];
  char ch;
  char *fname = malloc(sizeof(char)*64);
  char *sname = malloc(sizeof(char)*64);

  node_t *res;
  int index;
  while(1) {
	printf("\nActions: (i)mport file, (f)ind word, (p)rint tree, (q)uit\n");
	choise = (char) getchar();
	switch (choise) {
	case 'i': case 'I':
	  //	  scanf("%64s", str);
	  fname = malloc(sizeof(char)*64);
	   index = 0;
	 
	  while ((ch = getc(stdin)) != EOF) {
		if (ch == '\n') {
		  break; 
		}
		fname[index] = ch;
		index++;
	  }
	  filereader_import(fname, &tree->next);
	  
	  free(fname);
	  free(name);
	  break;
	case 'f': case 'F':
	  while (getchar() != '\n');
	  for (int j = 0; j < 64; j++) {
		sname[j] = '\0'; 
	  }
	  index = 0;
	  
	  while ((ch = getc(stdin)) != '\n') {
		sname[index] = ch;
		index++;
	  }
	  
	  res = radix_find(tree->next, sname);
	  printf("depth: %d and last char: %c", res->depth, res->key);
	  /*	  for (int i = res->depth-1; i > 0; i--) {
			  printf("%c", res->key);
			  res = res->parent;
			  }*/
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

}

int main(void) {
  // word storage
  list_t *tree = radix_create_list();

  //  mainloop(tree);
  
  filereader_import("w", &tree->next);

  radix_print(tree->next, 0);

  node_t *res = radix_find(tree->next, "beer");
  printf("node: %i key: %c\n", res->depth, res->key);
  res = radix_find(tree->next, "camel");
  printf("node: %i key: %c\n", res->depth, res->key);
  res = radix_find(tree->next, "boat");
  printf("node: %i key: %c\n", res->depth, res->key);
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

