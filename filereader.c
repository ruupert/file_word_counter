#include <stdlib.h>
#include <stdio.h>

#include "filereader.h"


static fp_obj_t* filereader_fres(void) {
  fp_obj_t *tmp = malloc(sizeof(fp_obj_t));
  tmp->status=-1;
  return tmp;
}


fp_obj_t* filereader_fopen(char* fname) {
  fp_obj_t *result = filereader_fres();
  result->fp = fopen(fname, "r");
  
  if (result->fp == NULL) {
	  result->status=1;
  } else {
	result->status=0;
  }  
  
  return result;
}

char* filereader_stat_str(int num) {
if (num == 0) {
return "yesssss";
} else if (num == 1) {
return "noooo";
} else if (num == -1) {
return "unopened";
}

}


