#include "utils.h"

static void	writer(int symbol)
{
	if (symbol != 0)
		write(1, &symbol, 1);
	else
		write(1, "\n", 1);
}

static void	par_hendler(int signum, struct __siginfo *act, void *smth)
{
	static int	counter;
	static int	symbol;
	static int	i;

	(void) act;
	(void) smth;
	if (counter == 0)
		counter = 128;
	if (signum == SIGUSR1)
	{
		symbol += counter;
		counter /= 2, i++;
	}
	else
		counter /= 2, i++;
	if (i == 8)
	{
		writer(symbol);
		counter = 128;
		symbol = 0;
		i = 0;
	}
	kill(act->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	act.sa_sigaction = par_hendler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
