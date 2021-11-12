/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 16:33:55 by mballet          ###   ########.fr       */
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

static void	check_famish(t_data *data)
{
	if (data->philo.start_eat && (getting_time() \
		- data->philo.start_eat) > data->args.die)
	{
		pthread_mutex_lock(&((data->mut_const)[data->dead]));
		data->death = 1;
		pthread_mutex_unlock(&((data->mut_const)[data->dead]));
	}
}

static void	eating(t_data *data)
{
	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.left]));
	print_mut(data, "has taken a left fork");

	if (data->nbr_philo == 1)
	{
		pthread_mutex_lock(&((data->mut_const)[data->dead]));
		data->death = 1;
		pthread_mutex_unlock(&((data->mut_const)[data->dead]));
		return ;
	}
	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.right]));
	print_mut(data, "has taken a right fork");

	check_famish(data);
	print_mut(data, "is eating");
	(*data).philo.start_eat = getting_time();
	ft_usleep(data->args.eat);
	pthread_mutex_lock(&((data->mut_const)[data->meal]));
	(*data).n_meal++;
	pthread_mutex_unlock(&((data->mut_const)[data->meal]));

	pthread_mutex_unlock(&(data->philo.mut_fork[data->philo.right]));
	pthread_mutex_unlock(&(data->philo.mut_fork[data->philo.left]));
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
	if (!(data->philo.id % 2))
		ft_usleep(10);
	while (!data->death)
	{
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}
