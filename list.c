#include "list.h"



struct song_node * make_song(char * n, char * a){
  struct song_node *new = calloc(sizeof(struct song_node), 1);
  strcpy(new->name,n);
  strcpy(new->artist,a);
  return new;
}

struct song_node * insert_front(struct song_node * p, struct song_node * new){
  new -> next = p;
  return new;
}

struct song_node * insert_back(struct song_node *p, struct song_node *new){
  struct song_node * iter = p;

  if(p == NULL){
     return new;
  }

  while(iter -> next != NULL){
    iter = iter -> next;
  }
  iter -> next = new;
  return p;
}



struct song_node * insert_order(struct song_node * p, struct song_node *new){
  struct song_node * iter = p;

  if(p == NULL){
    p = insert_front(p,new);
    return p;
  }

  if(strcmp(p -> artist ,new -> artist) > 0){
    p = insert_front(p,new);
    return p;
  }
  else{
    p = insert_back(p,new);
    return p;
  }
}

void print_list(struct song_node * p){
    struct song_node *hold = p;
    if(hold  == NULL){
      printf("END\n-----------\n");
    }
    else {

      printf("%s By %s => ", hold -> name, hold ->artist);
      print_list(hold -> next);
    }
}

struct song_node * find_node(struct song_node *p, char * n, char * a){
  struct song_node *iter = p;
  while(iter->next != NULL ){

    if(strcmp(iter->artist,a) == 0 && strcmp(iter->name,n) == 0){
      struct song_node *found = calloc(sizeof(struct song_node),1);
      iter -> next = NULL;
      found = iter;
      return found;
    }

    iter = iter -> next;

  }
  if(strcmp(iter->artist,a) == 0 && strcmp(iter->name,n) == 0 ){
    struct song_node *found = calloc(sizeof(struct song_node),1);
    iter -> next = NULL;
    found = iter;
    return found;
  }
  return NULL;

}

struct song_node * find_first(struct song_node *p, char * a){
  struct song_node *iter = p;
  while(iter -> next != NULL){
    if(strcmp(iter->artist,a)==0){
      struct song_node * found = calloc(sizeof(struct song_node),1);
      iter -> next = NULL;
      found = iter;
      return found;
    }
    iter = iter -> next;
  }
  if(strcmp(iter->artist,a) == 0){
    struct song_node * found = calloc(sizeof(struct song_node),1);
    iter -> next = NULL;
    found = iter;
    return found;
  }
  return NULL;
}

struct song_node * rand_node(struct song_node *p){
  return p;
}

struct song_node * remove_node(struct song_node * p, struct song_node * rem){
  return NULL;
}


void free_list(struct song_node * p){
  struct song_node * hold = p;
  struct song_node *temp = p;
  while(hold){

    hold = hold -> next;
    free(temp);
    temp = hold;

  }
  free(hold);
}
