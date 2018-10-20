#include "list.h"



struct song_node * make_song(char * n, char * a){
  struct song_node *new = calloc(sizeof(struct song_node), 1);
  strcpy(new->name,n);
  strcpy(new->artist,a);
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

void print_list(struct song_node *p){
  printf("\n=====================================\n");
	while(p){
		printf("|%s: %s| ", p->name, p->artist);
		p=p->next;
	}
  printf("\n=====================================\n");

}

struct song_node * insert_front(struct song_node *p, char *song, char *a){
	struct song_node *new = malloc(sizeof(struct song_node));
	strcpy(new->name, song);
	strcpy(new->artist, a);
	new->next = p;
	return new;
}

struct song_node * free_list(struct song_node *p){
	while(p){
		struct song_node *tmp = p->next;
		free(p);
		p = tmp;
	}
	return NULL;
}



struct song_node* find_node(struct song_node *p, char *n, char *a){
  while(p){
    if(strcmp(a, p->artist) == 0 && strcmp(n, p->name) == 0){
      return p;
    }
    p = p->next;
  }
}

struct song_node * find_first(struct song_node *p, char *a){
  while(p){
    if(strcmp(a, p->artist) == 0){
      return p;
    }
    p = p->next;
  }
}

struct song_node * rand_node(struct song_node *p){

  struct song_node *iter = malloc(sizeof(struct song_node));
  iter = p;
  int cnt = 0;
  while(iter){
    cnt++;
    iter = iter->next;
  }
  int i = rand() % cnt;
  for(;i>0;i--){
    p = p->next;
  }
  return p;
}

struct song_node * remove_node(struct song_node *p, struct song_node *rem){
  struct song_node *iter = malloc(sizeof(struct song_node));
  iter = p;

  struct song_node *bef = malloc(sizeof(struct song_node));
  bef = p;

  if(p == rem){
    p = rem->next;
    return p;
  }

  iter = iter->next;
  while(iter){
    if(iter == rem){
      bef->next = rem->next;
      return p;
    }
    bef = iter;
    iter = iter->next;
  }
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
