/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:34 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 17:12:12 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static short int	init_fork(int nbr_philo, t_data **data)
{
	int				i;
	pthread_mutex_t	*temp;

	temp = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!temp)
		return (FAILURE);
	i = 0;
	while (i < nbr_philo)
	{
		pthread_mutex_init(&(temp[i]), NULL);
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		(*data)[i].philo.mut_fork = temp;
		i++;
	}
	return (SUCCESS);
}

static short int	init_const(int nbr_philo, t_data **data)
{
	int				i;
	pthread_mutex_t	*temp;

	temp = malloc(sizeof(pthread_mutex_t) * 3);
	if (!temp)
		return (FAILURE);
	i = 0;
	while (i < 3)
	{
		pthread_mutex_init(&(temp[i]), NULL);
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		(*data)[i].mut_const = temp;
		i++;
	}
	return (SUCCESS);
}

short int	init_data(int nbr_philo, t_data **data)
{
	*data = malloc(sizeof(t_data) * nbr_philo);
	if (!*data)
		return (FAILURE);
	// if (!init_thread_id(nbr_philo, data))
	// 	return (FAILURE);
	if (!init_fork(nbr_philo, data))
		return (FAILURE);
	if (!init_const(nbr_philo, data))
		return (FAILURE);
	return (SUCCESS);
}
