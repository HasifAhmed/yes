#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node *lib[27];

struct library{struct song_node * tables[27];};

struct library * add_song(struct library * l, char * name,char *artist);
int indexOf(char * art);
