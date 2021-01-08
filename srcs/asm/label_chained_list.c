#include "../../includes/asm.h"

add_label_link(t_label new, t_label *head)
{
  if (head == NULL)
  {
    //make head new link
  }
  else
  {
    //add at start of list
  }
}


void init_link(t_label new, t_label *head)
{
  if(!(head = malloc(sizeof(t_label *))))
    {
      printf("malloc error \n");
      exit(0);
    }
  head->name = new.name;
  head->pos = new.pos;
  head->next = NULL;

}















t_liste *liste;
t_tetro *tetro;

if (!(liste = malloc(sizeof(*liste))) ||
    !(tetro = malloc(sizeof(*tetro))))
  return (NULL);
tetro->lettre = 'A';
put_in_tab(single_tetro, tetro);
tetro->next = NULL;
liste->head_tetro = tetro;
return (liste);
