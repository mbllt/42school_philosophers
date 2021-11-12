/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:44:48 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 13:47:26 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_args	fill_args(int argc, char **argv)
{
	t_args	args;

	args.nbr = ft_atoi(argv[1]);
	args.die = ft_atoi(argv[2]);
	args.eat = ft_atoi(argv[3]);
	args.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args.n_eat = ft_atoi(argv[5]);
	else
		args.n_eat = 0;
	return (args);
}

static void	fill_philo(t_data **data, int i, int nbr_philo)
{
	(*data)[i].philo.id = i + 1;
	(*data)[i].philo.thread_id = 0;
	(*data)[i].philo.start_eat = 0;
	if ((*data)[i].philo.id == nbr_philo)
	{
		(*data)[i].philo.left = i;
		(*data)[i].philo.right = 0;
	}
	else
	{
		(*data)[i].philo.left = i;
		(*data)[i].philo.right = i + 1;
	}
}

void	fill_data(int argc, char **argv, t_data **data)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		(*data)[i].args = fill_args(argc, argv);
		fill_philo(data, i, ft_atoi(argv[1]));
		(*data)[i].death = 0;
		(*data)[i].nbr_philo = ft_atoi(argv[1]);
		(*data)[i].n_meal = 0;
		(*data)[i].print = 0;
		(*data)[i].meal = 1;
		(*data)[i].dead = 2;
		i++;
	}
}