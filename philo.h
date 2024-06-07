/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:29:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/07 12:06:44 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef struct  s_fork
{
    t_mtxt  fork;
    int     fork_id;
}   t_fork;

typedef struct  s_philo
{
    int         id;
    long meals  counter;
    bool        full;
    t_fork      *left_fork;
    t_fork      *right_fork;
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

