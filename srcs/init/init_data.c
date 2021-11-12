/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:34 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 13:48:09 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static short int	init_thread_id(int nbr_philo, t_data **data)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		(*data)[i].philo.thread_id = malloc(sizeof(pthread_mutex_t));
		if (!((*data)[i].philo.thread_id))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// Mes philos auront tous acces au meme tableau de mutex pour les forks
static short int	init_fork(int nbr_philo, t_data **data)
{
	int				i;
	pthread_mutex_t	*temp;

	(*data)[0].philo.mut_fork = NULL;
	temp = malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!temp)
		return (FAILURE);
	i = 0;
	// printf("nbr_philo :%d\n", nbr_philo);
	while (i < nbr_philo)
	{
		pthread_mutex_init(&(temp[i]), NULL);
		// printf("add :%p\n", &(temp[i]));
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		(*data)[i].philo.mut_fork = temp;
		i++;
	}
	// printf("ca existe :%p\n", &((*data)[0].philo.mut_fork[0]));
	// pthread_mutex_lock(&((*data)[0].philo.mut_fork[0]));
	return (SUCCESS);
}

// Mes philos auront tous acces au meme tableau de mutex pour print, meal, dead
static short int	init_const(int nbr_philo, t_data **data)
{
	int				i;
	pthread_mutex_t	*temp;

	temp = malloc(sizeof(pthread_mutex_t) * 3);
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
	if (!init_thread_id(nbr_philo, data))
		return (FAILURE);
	if (!init_fork(nbr_philo, data))
		return (FAILURE);
	// printf("ca existe bis :%p\n", &((*data)[0].philo.mut_fork[0]));
	if (!init_const(nbr_philo, data))
		return (FAILURE);
	return (SUCCESS);
}