/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:34 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 12:11:56 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	init_data(int nbr_philo, t_data **data)
{
	int	i;

	*data = malloc(sizeof(t_data) * nbr_philo);
	if (!*data)
		return (FAILURE);
	i = 0;
	while (i < nbr_philo)
	{
		(*data)[i].philo.r_f = malloc(sizeof(pthread_mutex_t *));
		if (!((*data)[i].philo.r_f))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}