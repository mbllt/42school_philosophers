/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_famished.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:29:23 by mballet           #+#    #+#             */
/*   Updated: 2021/11/15 14:16:48 by mballet          ###   ########.fr       */
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

short int	philo_famished(t_data *data, int nbr_philo)
{
	int	i;

	pthread_mutex_lock(&((data[0].mut_const)[data->dead]));
	i = 0;
	while (i < nbr_philo)
	{
		if ((data[i].philo.start_eat && (getting_time() \
			- data[i].philo.start_eat) > data[i].args.die) || data[i].death)
		{
			all_philo_dead(data, nbr_philo);
			if (data[0].nbr_philo != 1)
			{
				pthread_mutex_lock(&((data[0].mut_const)[data->print]));
				printf("%ld %d died\n", getting_time() \
					- data->start_time, data[i].philo.id);
			}
			return (SUCCESS);
		}
		i++;
	}
	pthread_mutex_unlock(&((data[0].mut_const)[data->dead]));
	return (FAILURE);
}
