/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:27:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 11:07:02 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mut_const(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		pthread_mutex_init(&(data[0].mut_const[i]), NULL);
		i++;
	}
}

short int	destroy_mut_const(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (pthread_mutex_destroy(&(data[0].mut_const[i])))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	init_mut_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		pthread_mutex_init(&(data[i].philo.mut_fork[i]), NULL);
		i++;
	}
}

short int	destroy_mut_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		if (pthread_mutex_destroy(&(data[i].philo.mut_fork[i])))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
