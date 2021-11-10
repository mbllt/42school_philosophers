/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:28:09 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 11:10:30 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include <pthread.h>
# include <sys/time.h>

# define FAILURE 0
# define SUCCESS 1

typedef struct s_args
{
	int	nbr;
	int	die;
	int	eat;
	int	sleep;
	int	n_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	l_f;
	long int		start_eat;
	int				n_meal;
}	t_philo;

typedef struct s_data
{
	t_args		args;
	t_philo		philo;
	short int	death;
	int			nbr_philo;
}	t_data;

// Utils
short int	check_args(int argc, char **argv);
short int	ft_exit(int ret, char *mess_err, void(*clear)(t_data *data), t_data *data);
void		clear(t_data *data);
long int	getting_time();

// Init
short int	init_data(int nbr, t_data **data);
void		fill_data(int argc, char **argv, t_data **data);

// Philo
short int	philo(t_data *data);
void		*thread(void *dat);

// Fork
void		init_fork(t_data *data);
short int	destroy_fork(t_data *data);

#endif