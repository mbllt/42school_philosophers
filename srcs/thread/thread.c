/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/11 11:58:06 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_data *data)
{
	pthread_mutex_lock((&data->philo.l_f));
	pthread_mutex_lock(data->print);
	printf("%ld %d has taken a fork\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock(data->print);

	pthread_mutex_lock(data->philo.r_f);
	pthread_mutex_lock(data->print);
	printf("%ld %d has taken a fork\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock(data->print);

	pthread_mutex_lock(data->print);
	printf("%ld %d is eating\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock(data->print);
	data->philo.start_eat = getting_time();
	
	data->n_meal++;
	ft_usleep(data->args.eat);

	pthread_mutex_unlock(data->philo.r_f);
	pthread_mutex_unlock((&data->philo.l_f));
}

static void	sleeping(t_data *data)
{
	pthread_mutex_lock(data->print);
	printf("%ld %d is sleeping\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock(data->print);
	ft_usleep(data->args.sleep);
}

static void	thinking(t_data *data)
{
	pthread_mutex_lock(data->print);
	printf("%ld %d is thinking\n", getting_time() \
		- data->start_time, data->philo.id);
	pthread_mutex_unlock(data->print);
}

void	*thread(void *dat)
{
	t_data	*data;

	data = (t_data *)dat;
	if (!(data->philo.id % 2))
	{
		ft_usleep(20);
	}
	while (!data->death)
	{
		if (data->philo.start_eat && getting_time() \
			- data->philo.start_eat > data->args.die)
		{
			data->death = 1;
			break ;
		}
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}
