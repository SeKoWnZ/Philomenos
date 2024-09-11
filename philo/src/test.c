# include <philo.h>

void	printtable(t_table *table)
{
	int i = -1;

	while (++i < table->philo_n)
	{
		printf("|FILO :%d  |  DIE: %d  | EAT: %d  |  SLEEP: %d  |  MEALS: %d  |\n", table->philos[i].id, table->philos[i].die, table->philos[i].eat, table->philos[i].sleep, table->philos[i].m_eaten);
		printf("-------------------------------------------------------------------\n");
	}
}

void	print_val(t_philo *philo, size_t val, char *msg)
{
	size_t	time;

	time = get_current_time();
	pthread_mutex_lock(philo->m_print);
	if (!getter(philo->m_dead, philo->dead_phil))
		printf("%ld %d VALUE: %ld %s\n", time - philo->time, philo->id, val, msg);
	pthread_mutex_unlock(philo->m_print);
}
