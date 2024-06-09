/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:29:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/08 23:39:21 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_errno_t.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef struct  s_fork
{
    t_mtx  fork;
    int     fork_id;
}   t_fork;

typedef struct  s_philo
{
    int         id;
    long	meals_counter;
    bool        full;
    t_fork      *first_fork;
    t_fork      *second_fork;
    pthread_t   thread_id;
    t_table     *table;
}   t_philo;

typedef struct  s_table
{
    long    philo_nbr;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    nbr_limit_meals;
    long    start_simulation;
    bool    end_simulation;
    t_fork  *forks;
    t_philo *philo;
}   t_table;

void		error_exit(const char *error);
void		parse_input(t_table *table, char **argv);
void		safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
static void	handle_mutex_error(int status, t_opcode opcode);

#endif
