/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_satiated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:32:06 by mballet           #+#    #+#             */
/*   Updated: 2021/11/15 14:25:03 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	philo_satiated(t_data *data, int nbr_philo)
{
	int	i;

	pthread_mutex_lock(&((data[0].mut_const)[data->meal]));
	i = 0;
	while (i < nbr_philo)
	{
		if (!(data[i].satiated))
			break ;
		i++;
	}
	if (i == nbr_philo)
	{
		pthread_mutex_lock(&((data->mut_const)[data->print]));
		printf("%ld Philos have eaten %d times\n", getting_time() \
		- data->start_time, data->args.n_eat);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&((data[0].mut_const)[data->meal]));
	return (FAILURE);
}
