/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:48:26 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 12:17:16 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	eating(t_data *data)
{
	printf("%ld %d is eating\n", getting_time(), data->philo.id);
	data->philo.start_eat = getting_time();
	usleep(data->args.eat);
}

static	void	sleeping(t_data *data)
{
	printf("%ld %d is sleeping\n", getting_time(), data->philo.id);
	usleep(data->args.sleep);
}

static	void	thinking(t_data *data)
{
	printf("%ld %d is thinking\n", getting_time(), data->philo.id);
}

void	*thread(void *dat)
{
	t_data	*data;

	data = (t_data *)dat;
	// printf("philo_id :%d\n", data->philo.id);
	while (1)
	{
		if (data->philo.start_eat && getting_time() \
			- data->philo.start_eat > data->args.die)
				data->death = 1;
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}