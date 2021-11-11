/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:27:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/11 12:01:18 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mut_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		pthread_mutex_init(&(data[i].philo.l_f), NULL);
		if (i == data[0].nbr_philo - 1)
			data[i].philo.r_f = &(data[0].philo.l_f);
		else
			data[i].philo.r_f = &(data[i + 1].philo.l_f);
		i++;
	}
}

short int	destroy_mut_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		if (pthread_mutex_destroy(&(data[i].philo.l_f)))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}