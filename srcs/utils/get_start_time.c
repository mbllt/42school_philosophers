/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:31:45 by mballet           #+#    #+#             */
/*   Updated: 2021/11/11 11:32:29 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_start_time(t_data **data, int nbr_philo)
{
	int	i;

	(*data)[0].start_time = getting_time();
	i = 0;
	while (++i < nbr_philo)
		(*data)[i].start_time = (*data)[0].start_time;
}