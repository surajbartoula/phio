/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:45:52 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/10 08:20:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		;
	else
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philo[i].thread_id, dinner_simulation,
		      		&table->philo[i], CREATE);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philo[i].thread_id, NULL, NULL, JOIN);
}
