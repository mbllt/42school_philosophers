/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:28:09 by mballet           #+#    #+#             */
/*   Updated: 2021/11/09 18:41:12 by mballet          ###   ########.fr       */
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
	long int		time_eat;
	int				n_meal;
}	t_philo;

typedef struct s_data
{
	t_args		args;
	t_philo		philo;
	short int	death;
}	t_data;

// Utils
short int	check_args(int argc, char **argv);
short int	ft_exit(int ret, char *mess_err);

#endif