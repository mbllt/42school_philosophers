/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:55:36 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 11:52:34 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	starting_thread(t_data **data, int nbr_philo)
{
	int	i;

	(*data)[0].start_time = getting_time();
	i = 1;
	while (i < nbr_philo)
	{
		(*data)[i].start_time = (*data)[0].start_time;
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		printf("thread add :%p, data add :%p, thread :%p\n", \
			&((*data)[i].philo.thread_id), &((*data)[i]), &thread);
		if (pthread_create(&((*data)[i].philo.thread_id), \
			NULL, &thread, &((*data)[i])))
		{
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

short int	philo(t_data **data, int nbr_philo)
{
	if (!starting_thread(data, nbr_philo))
	{
		return (FAILURE);
	}
	while (1)
	{
		if (philo_dead((*data), nbr_philo))
		{
			if (!destroy_mut_const(*data) || !destroy_mut_fork(*data))
				return (FAILURE);
			break ;
		}
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 5 || argc == 6)
	{
		if (!check_args(argc, argv))
			return (ft_exit(EXIT_FAILURE, NULL, clear, data));
		if (!init_data(ft_atoi(argv[1]), &data))
			return (ft_exit(EXIT_FAILURE, NULL, clear, data));
		fill_data(argc, argv, &data);
		if (!philo(&data, ft_atoi(argv[1])))
			return (ft_exit(EXIT_FAILURE, NULL, clear, data));
	}
	else
	{
		printf("Error : wrong number of arg\n");
	}
	return (ft_exit(EXIT_SUCCESS, NULL, clear, data));
}