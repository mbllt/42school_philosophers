/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:28:09 by mballet           #+#    #+#             */
/*   Updated: 2021/11/15 14:08:46 by mballet          ###   ########.fr       */
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
	pthread_mutex_t	*mut_fork;
	int				right;
	int				left;
	long int		start_eat;
}	t_philo;

typedef struct s_data
{
	t_args			args;
	t_philo			philo;
	int				nbr_philo;
	long int		start_time;
	short int		death;
	int				n_meal;
	int				satiated;
	int				print;
	int				meal;
	int				dead;
	pthread_mutex_t	*mut_const;
}	t_data;

// Init
short int	init_data(int nbr, t_data **data);
void		fill_data(int argc, char **argv, t_data **data);

// Philo
short int	philo(t_data **data, int nbr_philo);
short int	starting_thread(t_data **data, int nbr_philo);
short int	philo_famished(t_data *data, int nbr_philo);
short int	philo_satiated(t_data *data, int nbr_philo);

// Thread
void		*thread(void *dat);
void		init_mut_const(t_data *data);
short int	destroy_mut_const(t_data *data);
void		init_mut_fork(t_data *data);
short int	destroy_mut_fork(t_data *data);

// Utils
short int	check_args(int argc, char **argv);
short int	ft_exit(int ret, char *mess_err, void(*clear)(t_data *data), \
				t_data *data);
void		clear(t_data *data);
long int	getting_time(void);
void		ft_usleep(long int time_in_ms);
void		print_mut(t_data *data, char *str);

#endif