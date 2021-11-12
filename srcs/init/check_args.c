/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:15:14 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 16:53:51 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static short int	check_size(int argc, char **argv)
{
	int			i;
	int			j;
	long int	nbr;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			j++;
		}
		if (j > 10)
			return (ft_exit(FAILURE, "Error : args too long", NULL, NULL));
		i++;
	}
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < 0 || nbr > 2147483647)
			return (ft_exit(FAILURE, "Error : args too long", NULL, NULL));
		i++;
	}
	return (SUCCESS);
}

static short int	check_neg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			return (ft_exit(FAILURE, "Error : args neg", NULL, NULL));
		i++;
	}
	return (SUCCESS);
}

static short int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (ft_exit(FAILURE, \
				"Error : args must be digit", NULL, NULL));
		}
		i++;
	}
	return (SUCCESS);
}

short int	check_args(int argc, char **argv)
{
	if (!check_digit(argc, argv))
		return (FAILURE);
	if (!check_neg(argc, argv))
		return (FAILURE);
	if (!check_size(argc, argv))
		return (FAILURE);
	return (SUCCESS);
}
