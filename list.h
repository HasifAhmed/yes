#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * table[27];

struct song_node * make_song(char * n, char * a);

struct song_node * insert_front(struct song_node * p, struct song_node * new);

struct song_node * insert_back(struct song_node *p, struct song_node *new);

struct song_node * insert_order(struct song_node * p, struct song_node *new);

void print_list(struct song_node * p);

struct song_node * find_node(struct song_node *p, char * n, char * a);

struct song_node * find_first(struct song_node *p,char * a);

struct song_node * rand_node(struct song_node *p);

struct song_node * remove_node(struct song_node * p, struct song_node * rem);

void free_list(struct song_node * p);
