#include "utils.h"

int g_mess = 0;

void mess(int signum)
{
	if (signum == SIGUSR1)
		g_mess = 1;
}

static void	go_to_serv(int pid, char *get_str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(35);
			if (get_str[i] & j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j /= 2;
			while (g_mess != 1)
				usleep(1);
			g_mess = 0;
		}
		if (!get_str[i])
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*get_str;

	signal(SIGUSR1, mess);
	if (argc < 3)
	{
		ft_putstr("Error! Need more arguments\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	get_str = argv[2];
	go_to_serv(pid, get_str);
	return(0);
}
