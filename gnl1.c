/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:46:52 by asmets            #+#    #+#             */
/*   Updated: 2014/11/24 03:04:09 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*      *((*tmp) + i[1]) == *(tmp[i[1]]) == tmp[0][i[1]] == **tmp      */

int			str_swaper(char **buff, char **str, size_t size, int enable)
{
	char	*stmp;

	if ((stmp = ft_strnew(size)) == NULL)
		return (0);
	if (*str)
		stmp = ft_strcpy(stmp, *str);
	if (enable)
	{
		free(*str);
		*str = NULL;
	}
	*str = stmp;
	return (1);
}

int			read_core(char **buff, char **str, int enable)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = 0;
	if (*str != NULL)
		i[1] = ft_strlen(*str);
	if (!str_swaper(buff, str, (i[1] + BUFF_SIZE), enable))
		return (-1);
	while (buff[0][i[0]] != '\0')
	{
		if (buff[0][i[0]] == '\n')
		{
			str[i[1]] = '\0';
			i[1] = 0;
			while (buff[0][++i[0]] != '\0')
				buff[0][i[1]++] = buff[0][i[0]];
			buff[0][i[1]] = '\0';
			return (RETURN_LINE);
		}
		str[0][i[1]++] = buff[0][i[0]++];
	}
	str[0][i[1]] = '\0';
	return (2);
}

int					get_next_line(int fd, char **line)
{
	static char		*buff;
	int				rcheck;

	if (buff != NULL && (read_core(&buff, line, 0) == 1))
			return (RETURN_LINE);
	else if (buff == NULL)
		buff = ft_strnew(BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{ 
		if ((rcheck = read_core(&buff, line, 1)) == 1)
			return (RETURN_LINE);
		else if (rcheck == -1)
			return (-1);
	}
	return (0);
}

int			main(int ac, char const **av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (ac == 1)
		ft_putendl("\033[91mError: file required !");
	else
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_putendl("\033[91mError: Can't open file !");
		else
			while (get_next_line(fd, &line) == 1)
			{
				//ft_putstr("\033[92m###### APPEL ");
				//ft_putnbr(++i);
				//ft_putendl(" ######\033[0m");
				ft_putendl(line);
				free(line);
				line = NULL;
			}
	return (0);
}
