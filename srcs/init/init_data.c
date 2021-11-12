/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:34 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 11:15:41 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Mes philos auront tous acces au meme tableau de mutex pour les forks
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
		(*data)[i].philo.mut_fork = temp;
		i++;
	}
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
	if (!init_fork(nbr_philo, data))
		return (FAILURE);
	if (!init_const(nbr_philo, data))
		return (FAILURE);
	return (SUCCESS);
}