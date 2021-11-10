/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:55:36 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 12:22:26 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// Si j'envoie une cpy malloce, si je change la valaur de ma struct dehors, dans les threads j'aurais
// acces a la copie et donc ca changera pas toutes les deux secondes
// static cpy_data(t_data data)
// {
// 	t_data	new;

	
// 	return (new);
// }

short int	philo(t_data *data)
{
	int		i;
	t_data	data_cpy;

	// init_fork(data);
	i = 0;
	while (i < data[0].nbr_philo)
	{
		// data_cpy = cpy_data(data[i]);
		if (pthread_create(&(data[i].philo.thread_id), NULL, &thread, data))
			return (FAILURE);
		i++;
	}
	// if (!destroy_fork(data))
		return (FAILURE);
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
		if (!philo(data))
			return (ft_exit(EXIT_FAILURE, NULL, clear, data));
//
		printf("death :%d\n", data[0].death);
		while (1)
		{
			if (data[0].death)
				break ;
		}
	}
	else
	{
		printf("Error : wrong number of arg\n");
	}
	return (ft_exit(EXIT_SUCCESS, NULL, clear, data));
}