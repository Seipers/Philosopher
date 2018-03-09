/*
** list.c for philo in /home/sebastien/Rendu/philo
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Sun Mar 12 07:49:21 2017 Sebastien Le Guischer
** Last update Fri Mar 17 13:42:54 2017 Dorian Voravong
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

t_philosopher	*create_list(int id, int to_eat)
{
  t_philosopher	*new;

  if ((new = malloc(sizeof(t_philosopher))) == NULL)
    return (NULL);
  pthread_mutex_init(&new->stick, NULL);
  new->time_eat = to_eat;
  new->id = id;
  new->next = new;
  return (new);
}

t_philosopher	*insert_list(t_philosopher *p, int id, int to_eat)
{
  t_philosopher	*tmp;
  t_philosopher	*new;

  if (p == NULL)
    return (create_list(id, to_eat));
  tmp = p;
  while (tmp->next != p)
    tmp = tmp->next;
  if ((new = malloc(sizeof(t_philosopher))) == NULL)
    return (NULL);
  pthread_mutex_init(&new->stick, NULL);
  new->time_eat = to_eat;
  new->id = id;
  new->next = tmp->next;
  tmp->next = new;
  return (p);
}

void		delete_list(t_philosopher *p)
{
  t_philosopher	*tmp;
  t_philosopher	*next;

  tmp = p;
  while (tmp->next != p)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  free(tmp);
}
