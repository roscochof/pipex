/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:14:19 by amarzana          #+#    #+#             */
/*   Updated: 2022/06/29 18:33:06 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int	ft_get_fd(char *file, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			ft_putstr_fd("Invalid or missing input file\n", 2);
			exit(0);
		}
		return (fd);
	}
	else
	{
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		return (fd);
	}
}

void	ft_check_cmd(int argc, char **argv, char **envp)
{
	char	*path;
	char	**argv_sp;
	int		i;

	i = 2;
	while (i <= (argc - 2))
	{
		argv_sp = ft_split(argv[i], ' ');
		path = ft_get_path(argv_sp, envp);
		if (!path)
		{
			ft_putstr_fd("invalid CMD: ", 2);
			ft_putendl_fd(argv_sp[0], 2);
			ft_free(argv_sp);
			free(path);
			exit(0);
		}
		i++;
	}
}
