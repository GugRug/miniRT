#include "minirt.h"

void	message_and_exit(t_error code, char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno && code == E_SYS)
		perror("");
	else if (code > 0)
	{
		ft_putstr_fd(g_error[code], STDERR_FILENO);
		if (str)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(str, STDERR_FILENO);
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else
		ft_putstr_fd("Fatal Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
