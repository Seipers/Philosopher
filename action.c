/*
** action.c for philo in /home/sebastien/Rendu/PSU_2016_philo
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Mar 14 17:16:09 2017 Sebastien Le Guischer
** Last update Wed Mar 15 18:01:33 2017 Sebastien Le Guischer
*/

#include <unistd.h>
#include "philo.h"

void	p_eat(pthread_mutex_t *one, pthread_mutex_t *two)
{
  lphilo_take_chopstick(one);
  while (pthread_mutex_trylock(two) != 0);
  lphilo_take_chopstick(two);
  lphilo_eat();
  lphilo_release_chopstick(one);
  lphilo_release_chopstick(two);
  pthread_mutex_unlock(one);
  pthread_mutex_unlock(two);
}

void	p_think(pthread_mutex_t *stick)
{
  lphilo_take_chopstick(stick);
  lphilo_think();
  lphilo_release_chopstick(stick);
  pthread_mutex_unlock(stick);
  usleep(1000);
}

void	p_sleep()
{
  lphilo_sleep();
  usleep(10000);
}
