#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "radix.h"                                                                                         


node_t* radix_create_node(void) {
  node_t *tmp = malloc(sizeof(node_t));
  tmp->next = NULL;
  tmp->childs = NULL;
  tmp->parent = NULL;
  tmp->key = '\0';
  //  tmp->key = c;
  return tmp;

}

list_t* radix_create_list(void) {
  list_t *tmp = malloc(sizeof(list_t));
  tmp->count = 0;
  tmp->next = malloc(sizeof(node_t));
  return tmp;
}

node_t* radix_find_char(node_t *n, char c) {
  printf("\t enter find_char() %c\n", c);
  if (n == NULL) {
	printf("\t - node null\n");
	return NULL;
  }
  node_t* tmp = n;
  do {
	if (tmp->key == c) {
	  return tmp;
	} 
	if (tmp->next != NULL) {
	  tmp = tmp->next;
	}
  } while (tmp->next != NULL);

  
  return NULL;
}

node_t* radix_find(node_t *n, char* str) {
  int len = strlen(str);
  node_t *ptr = n;
  int found;
  for (int i = 0; i < len; i++) {
	found = 0;
	while(ptr->next != NULL) {
	  printf("%c == %c\n", ptr->key, str[i]);
	  if (ptr->key == str[i]) {
		ptr = ptr->childs;
		found = 1;
		break;
	  } else {
		ptr = ptr->next;
	  }
	}
	if (found == 0) {
	  return NULL;
	}
  }
  return ptr;
}


int radix_insert(node_t *n, char *str) {
  node_t *ptr = n;
  node_t *last = NULL; // since we are in the "head"
  int found;
  for (int i=0; i < strlen(str); i++) {
	found = 0;
	//   	printf("%d,%c, ",i, str[i]);
	if (ptr->key == '\0') {
	  ptr->key = str[i];
	  ptr->depth = i;
	  ptr->next = radix_create_node();
	  ptr->childs = radix_create_node();
	  ptr->childs->parent = ptr;
	  last = ptr;
	  ptr = ptr->childs;
	} else {
	  while (ptr->next != NULL) {
		if (ptr->key == str[i]) {
		  last = ptr;
		  ptr = ptr->childs;
		  found = 1;
		  break; // while loop
		} else {
		  ptr = ptr->next;
		}
	  }
	  if (found == 0) {
		ptr->next = radix_create_node();
		ptr->key = str[i];
		ptr->depth = i;
		ptr->childs = radix_create_node();
		ptr->childs->parent = last;
		last = ptr;
		ptr = ptr->childs;
	  } 
	}
	
  }
  // printf("\n");
  return 0;
}

void radix_print(node_t *no, int lvl) {
  node_t *ptr = no;
  node_t *tmp;
  while (ptr->next != NULL) {
	printf(" %c ",  ptr->key);
	if (ptr->childs != NULL) {
	  tmp = ptr->childs;
	  if (tmp->key != '\0') {
		printf(" (" );
		radix_print(tmp, lvl+1);
		printf(") ");
	  }
	}
	ptr = ptr->next;
  }
}


