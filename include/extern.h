/*
** extern.h for philo in /home/dorian.voravong/rendu/PSU_2016_philo
** 
** Made by Dorian Voravong
** Login   <dorian.voravong@epitech.net>
** 
** Started on  Sun Mar 19 12:33:46 2017 Dorian Voravong
** Last update Sun Mar 19 12:35:45 2017 Dorian Voravong
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

# include <pthread.h>

int	RCFStartup(int ac, char **av);
void	RCFCleanup();
int	lphilo_eat();
int	lphilo_sleep();
int	lphilo_think();
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* !__LIBRICEFEREE_EXTERN__ */
