/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:44:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/10 15:16:18 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	fill_args(int argc, char **argv)
{
	t_args	args;

	args.nbr = ft_atoi(argv[1]);
	args.die = ft_atoi(argv[2]);
	args.eat = ft_atoi(argv[3]);
	args.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args.n_eat = ft_atoi(argv[5]);
	return (args);
}

t_philo	fill_philo(int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.thread_id = 0;
	philo.r_f = NULL;
	philo.start_eat = 0;
	return (philo);
}

void	fill_data(int argc, char **argv, t_data **data)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		(*data)[i].args = fill_args(argc, argv);
		(*data)[i].philo = fill_philo(i);
		(*data)[i].death = 0;
		(*data)[i].nbr_philo = ft_atoi(argv[1]);
		(*data)[i].n_meal = 0;
		i++;
	}
}