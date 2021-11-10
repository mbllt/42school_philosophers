/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:35 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 10:48:02 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		pthread_mutex_init(&(data[i].philo.l_f), NULL);
		if (i + 1 == data[0].nbr_philo)
			data[i].philo.r_f = &(data[0].philo.l_f);
		else
			data[i].philo.r_f = &(data[i + 1].philo.l_f);
		i++;
	}
}

short int	destroy_fork(t_data *data)
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