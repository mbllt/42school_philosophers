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

static short int	finish_meal(t_data *data, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		if (data[i].args.n_eat && data[i].n_meal >= data[i].args.n_eat)
		{
			pthread_mutex_lock(data[i].mut_dead);
			printf("%ld %d died\n", getting_time(), data[i].philo.id);
			return (SUCCESS);
		}
		i++;
	}
	return (FAILURE);
}

short int	philo_dead(t_data *data, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		if (data[i].death)
		{
			pthread_mutex_lock(data[i].mut_dead);
			printf("%ld %d died\n", getting_time(), data[i].philo.id);
			{
				return (SUCCESS);
			}
		}
		i++;
	}
	if (finish_meal(data, nbr_philo))
	{
		return (SUCCESS);
	}
	return (FAILURE);
}