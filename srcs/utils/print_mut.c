/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:58:00 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 16:59:27 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mut(t_data *data, char *str)
{
	pthread_mutex_lock(&((data->mut_const)[data->print]));
	printf("%ld %d %s\n", getting_time() \
		- data->start_time, data->philo.id, str);
	pthread_mutex_unlock(&((data->mut_const)[data->print]));
}
