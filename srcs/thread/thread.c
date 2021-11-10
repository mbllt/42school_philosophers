/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 17:34:04 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_data *data)
{
	pthread_mutex_lock((&(*data).philo.l_f));
	printf("%ld %d has taken a fork\n", getting_time() \
		- data->start_time, data->philo.id);

	pthread_mutex_lock((*data).mut_dead);
	printf("%ld %d is eating\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock((*data).mut_dead);
	(*data).philo.start_eat = getting_time();
	(*data).n_meal++;
	ft_usleep(data->args.eat);

	pthread_mutex_unlock((&(*data).philo.l_f));
}

static void	sleeping(t_data *data)
{
	pthread_mutex_lock((*data).mut_dead);
	printf("%ld %d is sleeping\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock((*data).mut_dead);
	ft_usleep(data->args.sleep);
}

static void	thinking(t_data *data)
{
	pthread_mutex_lock((*data).mut_dead);
	printf("%ld %d is thinking\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock((*data).mut_dead);
}

void	*thread(void *dat)
{
	t_data		*data;

	data = (t_data *)dat;
	while (1)
	{
		if (data->philo.start_eat && getting_time() \
			- data->philo.start_eat > data->args.die)
		{
			data->death = 1;
			break ;
		}
		// les pairs au tout debut attendent avant de manger
		// if (!data->n_meal && !data->philo.id % 2)
		// 	ft_usleep(1);
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}
