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
  struct song_node * on = p;
  if(p == NULL){
    return new;
  }

  if(strcmp(p -> artist ,new -> artist) > 0){
    new = insert_front(p,new);
    return new;
  }


  while(iter -> next != NULL){
    //printf("yes");
    if(strcmp(iter -> artist ,new -> artist) > 0){
      new = insert_front(iter,new);
      on = insert_front(new,on);
      return on;
    }
    //printf("hel");
    if(strcmp(iter -> artist ,new -> artist) == 0){
      while(iter -> next != NULL){
        if(strcmp(iter -> name ,new -> name) > 0){
          new = insert_front(iter,new);
          on = insert_front(new,on);
          return on;
        }
        on = iter;
        iter = iter -> next;
      }
      //printf("no");
      new = insert_front(iter,new);
      on = insert_front(new,on);
      return on;
    }

  on = iter;
  iter = iter -> next;
  }

  if(strcmp(iter->artist,new->artist) == 0){
    if(strcmp(iter -> name ,new -> name) > 0){
      on -> next = new;
      on = on -> next;
      on -> next = iter;

      return p;
    }
  }


  p = insert_back(p,new);


}

void print_list(struct song_node * p){
    struct song_node *hold = p;
    if(hold  == NULL){
      printf("\n----------------------------------------\n");
    }
    else {

      printf("|%s: %s| ", hold -> name, hold ->artist);
      print_list(hold -> next);
    }
}

struct song_node * find_node(struct song_node *p, char * n, char * a){
  struct song_node *iter = p;
  while(iter ){

    if(strcmp(iter->artist,a) == 0 && strcmp(iter->name,n) == 0){
      return iter;
    }
    iter = iter -> next;
  }
  return NULL;
}

struct song_node * find_first(struct song_node *p, char * a){
  struct song_node *iter = p;
  while(iter ){

    if(strcmp(iter->artist,a) == 0){
      return iter;
    }
    iter = iter -> next;
  }
  return NULL;
}

struct song_node * rand_node(struct song_node *p){
  struct song_node *iter = p;
  int count = 0;
  while(iter != NULL){
    count++;
    iter = iter -> next;
  }
  count = rand() % count;
  iter = p;
  for(;count>0;count--){
    iter = iter -> next;
  }
  printf("|%s: %s|\n",iter->name,iter->artist);

  return p;
}

struct song_node* remove_node(struct song_node * p, struct song_node * rem){
  struct song_node *iter = p;
  struct song_node *bef = NULL;
  while(iter != NULL){
    if(strcmp(iter -> name, rem -> name) == 0 && strcmp(iter-> artist, rem -> artist) ==0){
      if(bef == NULL){
        free(iter);
        return p-> next;
      }
      if(!iter -> next){
        bef -> next = NULL;
        free(iter);
        return p;
      }
      bef -> next = iter -> next;
      free(iter);
      return p;
    }
  bef = iter;
  iter = iter -> next;
  }
  return p;
}


void free_list(struct song_node * p){
  struct song_node * hold = p;
  struct song_node *temp;
  while(hold -> next){

    temp = hold -> next;
    hold -> next = hold ->next -> next;
    free(temp);

  }
}
