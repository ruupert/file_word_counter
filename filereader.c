#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#include <wchar.h>
//#include <locale.h>
#include <string.h>

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

int filereader_fread(fp_obj_t* fpr, node_t* tree) {
  char c;
  char* buf = malloc(sizeof(char)*128); // BUG HERE: A word can be longer than this... :p
  char *ptr = buf;
  size_t i = 0;
  printf("filereader enaged\n");
  while ((c = getc(fpr->fp)) != EOF) {
	
	//printf("chnum: %i, ", (int) c);
	if (c == '\n') {
	  //printf("fucking linefeed and i count: %zu", i);
	  char str[i];
	  //printf("--%s--size: %zu",ptr, sizeof(str));
	  strlcpy(str, ptr, sizeof(str)+sizeof(char));
	  //	  str[i] = '\0';
	  //printf("thefucking string is '%s'", str);
	  radix_insert(tree, str);
  	  //radix_print(tree, 0);
	  i = 0;
	  //	  free(str);
	  buf = NULL;
	  free(buf);
	  char* buf = malloc(sizeof(char)*128); 
	  ptr = buf;
	} else if (c == ' ') {
	}  else {
	  //	  printf("fucking char '%c'", c);
	  ptr[i] = c;
	  i++;
	}
	//printf("\n");
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

int filereader_import(char* fname, node_t **tree) {
  node_t *node = *tree;
  printf("opening file %s\n", fname);
  fp_obj_t *fpr = filereader_fopen(fname);
  if (fpr->status == 1) {
	return 1;
  }
  if (tree == NULL) {
	return 1;
  }

  return filereader_fread(fpr, node);
  
}
