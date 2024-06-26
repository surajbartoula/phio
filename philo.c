/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:56:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/08 15:03:39 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argc);
		data_init(&table);
		dinner_start(&table);
		clean(&table);
	}
	else
	{
		error_exit("Wrong argument, please provide the right argument\n");	
	}
}
