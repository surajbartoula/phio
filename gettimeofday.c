/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:06:54 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/07 06:53:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main()
{
    struct  timespec start_ts, end_ts;
    double  elapsed_usleep_us, elapsed_usleep_ns;
    double  elapsed_gettimeofday_us, elapsed_gettimeofday_ns;
    double  elapsed_foo_us, elapsed_foo_ns;

    clock_gettime(CLOCK_MONOTONIC, &start_ts);
    for (int i = 0; i < NUM_CALLS; i++)
        usleep(0);
    clock_gettime(CLOCK_MONOTONIC, &end_ts);
    elapsed_usleep_ns = (end_ts.tv_sec - start_ts.tv_sec) * 1e9 + (end_ts.tv_nsec - start_ts.tv_nsec);
    elapsed_usleep_us = elapsed_usleep_ns / 1e3;
}