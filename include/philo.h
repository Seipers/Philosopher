/*
** philo.h for philo in /home/sebastien/Rendu/philo
**
ne** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Sun Mar 12 07:13:33 2017 Sebastien Le Guischer
** Last update Fri Mar 17 16:18:55 2017 Dorian Voravong
*/

#ifndef PHILO_H_
# define PHILO_H_

# include "extern.h"

# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct		s_philosopher
{
  pthread_t		thread;
  pthread_mutex_t	stick;
  int			time_eat;
  int			id;
  struct s_philosopher	*next;
}			t_philosopher;

typedef struct	s_loop
{
  int		eat;
  int		last_action;
}		t_loop;

t_philosopher	*insert_list(t_philosopher *p, int id, int to_eat);
void		p_eat(pthread_mutex_t *one, pthread_mutex_t *two);
void		p_think(pthread_mutex_t *stick);
void		p_sleep();
void		loop(pthread_mutex_t *one,
		     pthread_mutex_t *two, int time_eat);
void		delete_list(t_philosopher *p);

#endif /* !PHILO_H_ */
