/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mut_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:29:23 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 15:54:05 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	all_philo_dead(t_data *data, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		data[i].death = 1;
		i++;
	}
}

static short int	finish_meal(t_data *data, int nbr_philo)
{
	int	i;

	pthread_mutex_lock(&((data[0].mut_const)[data->dead]));
	pthread_mutex_lock(&((data[0].mut_const)[data->meal]));
	i = 0;
	while (i < nbr_philo)
	{
		if (data[i].args.n_eat && data[i].n_meal >= data[i].args.n_eat)
		{
			all_philo_dead(data, nbr_philo);
			pthread_mutex_lock(&((data[0].mut_const)[data->print]));
			printf("%ld %d died\n", getting_time() \
				- data->start_time, data[i].philo.id);
			{
				pthread_mutex_unlock(&((data[0].mut_const)[data->meal]));
				return (SUCCESS);
			}
		}
		i++;
	}
	pthread_mutex_unlock(&((data[0].mut_const)[data->dead]));
	pthread_mutex_unlock(&((data[0].mut_const)[data->meal]));
	return (FAILURE);
}

short int	philo_dead(t_data *data, int nbr_philo)
{
	int	i;

	pthread_mutex_lock(&((data[0].mut_const)[data->dead]));
	i = 0;
	while (i < nbr_philo)
	{
		if (data[i].death)
		{
			all_philo_dead(data, nbr_philo);
			pthread_mutex_lock(&((data[0].mut_const)[data->print]));
			printf("%ld %d died\n", getting_time() \
				- data->start_time, data[i].philo.id);
			{
				pthread_mutex_unlock(&((data[0].mut_const)[data->dead]));
				return (SUCCESS);
			}
		}
		i++;
	}
	pthread_mutex_unlock(&((data[0].mut_const)[data->dead]));
	if (finish_meal(data, nbr_philo))
	{
		return (SUCCESS);
	}
	return (FAILURE);
}