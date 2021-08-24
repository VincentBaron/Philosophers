/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:14:49 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/23 16:29:53 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_init(void *thread)
{
	long *myID;

	myID = (long *)thread;
	printf("This is my id: %ld\n", *myID);
}

int main()
{
	pthread_t thread0;

	pthread_create(&thread0, NULL, thread_init, (void *)&thread0);
	pthread_exit(NULL);
	return (0);
}