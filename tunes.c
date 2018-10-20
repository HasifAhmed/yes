#include "tunes.h"

int indexOf(char * artist){
  int i=artist[0];
  if (artist[0]>=65 && artist[0]<=90){
    i+=32;
  }
  if (i>=97 && i<=122){
    i-=97;
    return i;
  }
  return 26;
}
void add_song(char * name,char *artist){
  int i=indexOf(artist);
  struct song_node * song = make_song(name,artist);
   
}
