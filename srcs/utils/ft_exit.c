/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:29:06 by mballet           #+#    #+#             */
/*   Updated: 2021/11/12 11:47:21 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_data *data)
{
	(void)data;
	// int	i;

	// i = 0;
	// // while (i < data[0].nbr_philo)
	// // {
	// // 	if (data[i].philo.r_f)
	// // 		free (data[i].philo.r_f);
	// // 	i++;
	// // }
	// i = 0;
	// // while (i < data[0].nbr_philo)
	// // {
	// // 	if (data[i].philo.thread_id)
	// // 		free (data[i].philo.thread_id);
	// // 	i++;
	// // }
	// i = 0;
	// // while (i < 3)
	// // {
	// // 	if (data[0].mut_const[i])
	// // 		free (data[0].mut_const[i]);
	// // 	i++;
	// // }
	// if (data)
	// 	free(data);
}

short int	ft_exit(int ret, char *mess_err, void(*clear)(t_data *data), t_data *data)
{
	if (data)
		clear(data);
	if (mess_err)
	{
		printf("%s\n", mess_err);
	}
	return (ret);
}