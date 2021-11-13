/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/13 19:46:12 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	check_satiated(t_data *data)
{
	pthread_mutex_lock(&((data[0].mut_const)[data->meal]));
	if (data->args.n_eat && data->n_meal >= data->args.n_eat)
	{
		data->satiated = 1;
	}
	pthread_mutex_unlock(&((data[0].mut_const)[data->meal]));
}

static void	eating(t_data *data)
{
	check_famish(data);
	check_satiated(data);
	pthread_mutex_lock(&(data->philo.mut_fork[data->philo.left]));
	print_mut(data, "has taken a left fork");
	if (data->nbr_philo == 1)
	{
		print_mut(data, "has died");
		pthread_mutex_lock(&((data->mut_const)[data->print]));
		pthread_mutex_lock(&((data->mut_const)[data->dead]));
		data->death = 1;
		pthread_mutex_unlock(&((data->mut_const)[data->dead]));
		return ;
	}
	check_famish(data);
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
	while (1)
	{
		pthread_mutex_lock(&((data->mut_const)[data->dead]));
		pthread_mutex_lock(&((data->mut_const)[data->meal]));
		if (data->death || data->satiated)
		{
			pthread_mutex_unlock(&((data->mut_const)[data->meal]));
			pthread_mutex_unlock(&((data->mut_const)[data->dead]));
			break ;
		}
		pthread_mutex_unlock(&((data->mut_const)[data->meal]));
		pthread_mutex_unlock(&((data->mut_const)[data->dead]));
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}
