#include <stdlib.h>
#include <stdio.h>

#include "filereader.h"
#include "radix.h"

static fp_obj_t* filereader_fres(void) {
  fp_obj_t *tmp = malloc(sizeof(fp_obj_t));
  tmp->status=-1;
  return tmp;
}


static fp_obj_t* filereader_fopen(char* fname) {
  fp_obj_t *result = filereader_fres();
  result->fp = fopen(fname, "r");
  
  if (result->fp == NULL) {
	  result->status=1;
  } else {
	result->status=0;
  }  
  
  return result;
}

static int filereader_fread(fp_obj_t* fpr, node_t* tree) {
  char* buf = malloc(sizeof(char)*128); // BUG HERE: A word can be longer than this... :p
  char c;
  int i = 0;
  while ((c = getc(fpr->fp)) != EOF) {

	if (c == '\n') {
	  char* str = malloc(sizeof(char)*(i));

	  for (size_t j = 0; j < i-1; j++) {
		str[j] = buf[j];
	  }
	  
	  str[i] = '\0';
	  free(buf);
	  char* buf = malloc(sizeof(char)*128);
	  
	  radix_insert(tree->next, str);
	  i = 0;
	} else {
	  buf[i] = c;
	  i++;
	}
	
  }
  fclose(fpr->fp);
  return 0;
}

char* filereader_stat_str(int num) {
  if (num == 0) {
	return "yesssss";
  } else if (num == 1) {
	return "noooo";
  } else if (num == -1) {
	return "unopened";
  } else {
	return "undefined";
  }
}

int filereader_import(char* fname, node_t *tree) {
  printf("opening file %s\n", fname);
  fp_obj_t *fpr = filereader_fopen(fname);
  if (fpr->status == 1) {
	return 1;
  }
  if (tree == NULL) {
	return 1;
  }

  return filereader_fread(fpr, tree);
  
}
