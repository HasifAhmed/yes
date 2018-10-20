#include "tunes.h"

int main(){
  //srand(time(NULL));

  struct song_node *song1 = make_song("Hello","Hasif");
  struct song_node *song2 = make_song("Goodbye","Adil");
  struct song_node *song3 = make_song("Pakistan","Adil");
  struct song_node *song4 = make_song("Bangladesh","Hasif");
  struct song_node *song5 = make_song("India","Neither");

  printf("Testing Linked List Functionality:\n");

  struct song_node *first = NULL;

  printf("\n=================================================\n");
  first = insert_order(first,"Hello","Hasif");
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_order(first,"Goodbye","Adil");
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_order(first,"Pakistan","Adil");
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_order(first, "Bangladesh", "Hasif");
  printf("Song Added. Current Song Directory:\n");
  print_list(first);

  first = insert_order(first,"India", "Neither");
  printf("Song Added. Current Song Directory:\n");
  print_list(first);
  printf("\n=================================================\n");

  printf("\n=================================================\n");
  printf("Random Song:\n");
  struct song_node *r1 = rand_node(first);
  print_list(r1);
  printf("Another Random Song:\n");
  struct song_node *r2 = rand_node(first);
  print_list(r2);
  printf("\n=================================================\n");

  printf("\n=================================================\n");
  printf("Looking for Hello By Hasif...\n");
  struct song_node *found1 = find_node(first,"Hello","Hasif");
  print_list(found1);

  printf("Looking for first song by Adil...\n");
  struct song_node *found2 = find_first(first,"Adil");
  print_list(found2);

  printf("Looking for first song by Hasif...\n");
  struct song_node *found3 = find_first(first,"Hasif");
  print_list(found3);
  printf("\n=================================================\n");



  printf("\n=================================================\n");
  printf("Current Song Directory:\n");

  print_list(first);

  printf("Removing Hello By Hasif...\n");
  struct song_node *rm1 = remove_node(first,song1);
  print_list(rm1);

  printf("Removing Pakistan By Adil...\n");
  struct song_node *rm2 = remove_node(first,song3);
  print_list(rm2);
  printf("\n=================================================\n");


  free_list(first);




/*
  struct song_node *second = NULL;
  second = insert_order(second,"Bible","Allah");
  print_list(second);
  */


}
