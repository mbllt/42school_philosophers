/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 11:12:44 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_mut(t_data *data, char *str)
{
	pthread_mutex_lock(&((data->mut_const)[data->print]));
	printf("%ld %d %s\n", getting_time() \
		- data->start_time, data->philo.id, str);
	pthread_mutex_unlock(&((data->mut_const)[data->print]));
}

static void	eating(t_data *data)
{
	pthread_mutex_lock(&((data->philo.mut_fork)[data->philo.left]));
	print_mut(data, "has taken a left fork");

	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.right]));
	print_mut(data, "has taken a right fork");

	print_mut(data, "is eating");
	(*data).philo.start_eat = getting_time();
	ft_usleep(data->args.eat);
	pthread_mutex_lock(&((data->mut_const)[data->meal]));
	(*data).n_meal++;
	pthread_mutex_unlock(&((data->mut_const)[data->meal]));

	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.right]));
	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.left]));
}

static void	sleeping(t_data *data)
{
	print_mut(data, "is sleeping");
	ft_usleep(data->args.sleep);
}

static void	thinking(t_data *data)
{
	print_mut(data, "is thinking");
}

void	*thread(void *dat)
{
	t_data	*data;

	data = (t_data *)dat;
	
	if (!data->philo.id % 2)
		ft_usleep(data->args.eat / 2);
	while (!data->death)
	{
		if (data->philo.start_eat && getting_time() \
			- data->philo.start_eat > data->args.die)
		{
			pthread_mutex_lock(&((data->mut_const)[data->dead]));
			data->death = 1;
			pthread_mutex_unlock(&((data->mut_const)[data->dead]));
			break ;
		}
		
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}
