/*
** decide.c for philo in /home/dorian.voravong/rendu/PSU_2016_philo
**
** Made by Dorian Voravong
** Login   <dorian.voravong@epitech.net>
**
** Started on  Thu Mar 16 12:23:54 2017 Dorian Voravong
** Last update Fri Mar 17 16:22:59 2017 Dorian Voravong
*/

#include "philo.h"

int	g_exit = 0;

void	think_or_eat(t_loop *infos, pthread_mutex_t *one,
		     pthread_mutex_t *two)
{
  if (infos->last_action == THINK)
    {
      infos->eat += 1;
      infos->last_action = EAT;
      p_eat(one, two);
    }
  else
    {
      infos->last_action = THINK;
      p_think(one);
    }
}

void		loop(pthread_mutex_t *one, pthread_mutex_t *two,
		     int time_eat)
{
  t_loop	infos;

  infos.last_action = THINK;
  infos.eat = 0;
  while (infos.eat < time_eat)
    {
      if (g_exit > 0)
	pthread_exit(NULL);
      if (infos.last_action == EAT)
	{
	  p_sleep();
	  infos.last_action = SLEEP;
	}
      else if (pthread_mutex_trylock(one) == 0)
	  think_or_eat(&infos, one, two);
      else if (pthread_mutex_trylock(two) == 0)
	{
	  infos.last_action = THINK;
	  p_think(two);
	}
    }
  g_exit += 1;
}
