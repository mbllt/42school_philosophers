/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:27:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 15:09:32 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	destroy_mut_const(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		pthread_mutex_destroy(&(data[0].mut_const[i]));
		i++;
	}
	return (SUCCESS);
}

short int	destroy_mut_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data[0].nbr_philo)
	{
		pthread_mutex_destroy(&(data[i].philo.mut_fork[i]));
		i++;
	}
	return (SUCCESS);
}
