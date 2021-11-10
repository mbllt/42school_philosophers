/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:27:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 16:11:19 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mut_fork(pthread_mutex_t *mutex, t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		pthread_mutex_init(mutex, NULL);
		if (i == data[0].nbr_philo - 1)
			data[i].philo.r_f = &(data[0].philo.l_f);
		else
			data[i].philo.r_f = &(data[i + 1].philo.l_f);
		i++;
	}
}

short int	destroy_mut_fork(pthread_mutex_t *mutex, t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		if (pthread_mutex_destroy(mutex))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}