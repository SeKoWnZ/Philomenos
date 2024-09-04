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
