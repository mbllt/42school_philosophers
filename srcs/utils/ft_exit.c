/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:29:06 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 17:12:16 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_data *data)
{
	if (data[0].philo.mut_fork)
		free (data[0].philo.mut_fork);
	if (data[0].mut_const)
		free (data[0].mut_const);
	if (data)
		free(data);
}

short int	ft_exit(int ret, char *mess_err, void(*clear)(t_data *data), \
				t_data *data)
{
	if (data)
		clear(data);
	if (mess_err)
	{
		printf("%s\n", mess_err);
	}
	return (ret);
}
