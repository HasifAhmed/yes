#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node *lib[27];

struct library{struct song_node * tables[27];};

struct library * add_song(struct library * l, char * name,char *artist);
int indexOf(char * art);
struct song_node * find_song(char * artist, char * song);
struct song_node *  find_artist(char *artist);
void print_letter(char l);
void print_artist(char * artist);
void print_library();
void  delete_song(char *name, char *artist);
void clear_library();
void shuffle_library();
