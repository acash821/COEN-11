#ifndef HISTORY_H_INCLUDED
typedef struct node
{
  char url[50];
  struct node* next;
}node;
void delete_url(node*);
void free_everything(node* node1);
#define HISTORY_H_INCLUDED



#endif // HISTORY_H_INCLUDED
