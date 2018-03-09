/*
** main.c for philo in /home/sebastien/Rendu/philo
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Sun Mar 12 07:05:33 2017 Sebastien Le Guischer
** Last update Thu Mar 16 14:49:50 2017 Sebastien Le Guischer
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void		*philo(void *arg)
{
  t_philosopher	*p;

  p = arg;
  if (p->id % 2 == 0)
    loop(&p->stick, &p->next->stick, p->time_eat);
  else
    loop(&p->next->stick, &p->stick, p->time_eat);
  return (NULL);
}

void		launch_lunch(t_philosopher *p)
{
  t_philosopher	*tmp;

  tmp = p;
  while (tmp->next != p)
    {
      pthread_create(&tmp->thread, NULL, philo, tmp);
      tmp = tmp->next;
    }
  pthread_create(&tmp->thread, NULL, philo, tmp);
  tmp = p;
  while (tmp->next != p)
    {
      pthread_join(tmp->thread, NULL);
      tmp = tmp->next;
    }
  pthread_join(tmp->thread, NULL);
}

int	is_number(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] != '\0')
    {
      if (nb[i] < '0' || nb[i] > '9')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	verrif_argv(char **av)
{
  if ((strcmp(av[1], "-p") != 0 && strlen(av[1]) != 2)
      || (strcmp(av[3], "-e") != 0 && strlen(av[3]) != 2))
    return (1);
  if (is_number(av[2]) == 1 || is_number(av[4]) == 1)
    return (1);
  if (atoi(av[2]) < 2 || atoi(av[4]) < 1)
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  t_philosopher	*philo;
  int		i;

  RCFStartup(ac, av);
  if (ac == 5 && verrif_argv(av) == 0)
    {
      i = 0;
      philo = NULL;
      while (i < atoi(av[2]))
	{
	  if ((philo = insert_list(philo, i, atoi(av[4]))) == NULL)
	    return (1);
	  i = i + 1;
	}
      launch_lunch(philo);
      delete_list(philo);
    }
  RCFCleanup();
  return (0);
}
