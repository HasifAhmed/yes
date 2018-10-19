#include "tunes.h"
int main(){

  struct song_node *song1 = make_song("Hello","Hasif");
  struct song_node *song2 = make_song("Goodbye","Adil");
  struct song_node *song3 = make_song("Pakistan!","Adil");
  struct song_node *song4 = make_song("Bangladesh!","Hasif");

  printf("First Playlist:\n");

  struct song_node *first = NULL;

  first = insert_front(first,song1);
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_front(first,song2);
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_back(first,song3);
  printf("Song Added To Back. Current Song Directory:\n");
  print_list(first);

  printf("\n=================================================\n");
  printf("Looking for Hello By Hasif...\n");
  struct song_node *find = find_node(first,"Hello","Hasif");
  print_list(find);

  printf("Looking for first song by Adil...\n");
  struct song_node *lookfor = find_first(lookfor,"Adil");
  print_list(lookfor);


  free_list(first);
  



/*
  struct song_node *second = NULL;
  second = insert_order(second,"Bible","Allah");
  print_list(second);
  */


}
