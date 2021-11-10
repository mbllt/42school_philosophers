/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:55:36 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 16:46:57 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short int	starting_thread(t_data **data, int nbr_philo)
{
	int	i;

	// init_fork(*data);
	i = 0;
	while (i < nbr_philo)
	{
		if (pthread_create(&((*data)[i].philo.thread_id), \
			NULL, &thread, &((*data)[i])))
			return (FAILURE);
		i++;
	}
	// if (!destroy_fork(*data))
		// return (FAILURE);
	return (SUCCESS);
}

short int	philo(t_data **data, int nbr_philo)
{
	pthread_mutex_init((*data)[0].mut_dead, NULL);
	if (!starting_thread(data, nbr_philo))
		return (FAILURE);
	while (1)
	{
		if (philo_dead((*data), nbr_philo))
		{
			if (pthread_mutex_destroy((*data)[0].mut_dead))
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