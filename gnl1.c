/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:46:52 by asmets            #+#    #+#             */
/*   Updated: 2014/11/20 01:31:43 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*      *((*tmp) + i[1]) == *(tmp[i[1]]) == tmp[0][i[1]] == **tmp      */

int			string_swaper(char **buff, char **str)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	
	if (*str != NULL)
		i[1] = ft_strlen(*str);	
	while (buff[0][i[0]] != '\0')
	{
		if (buff[0][i[0]] == '\n')
		{
			i[1] = 0;
			while (buff[0][++i[0]] != '\0')
				buff[0][i[1]++] = buff[0][i[0]];
			buff[0][i[1]] = '\0';
			ft_putendl(*buff);
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

	if (buff != NULL && (string_swaper(&buff, line) == RETURN_LINE))
	{
			return (RETURN_LINE);
	}
	else if (buff == NULL)
	{
		buff = ft_strnew(BUFF_SIZE + 1);
		*line = ft_strnew(BUFF_SIZE + 1);
	}
	while (read(fd, buff, BUFF_SIZE) > 0)
	{ 
		if (string_swaper(&buff, line) == RETURN_LINE)
			return (RETURN_LINE);
	}
	return (0);
}

int			main(int ac, char const **av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (ac == 1)
		ft_putendl("\033[91mError: file required !");
	else
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_putendl("\033[91mError: Can't open file !");
		else
			while (get_next_line(fd, &line) == 1)
			{
				ft_putstr("\033[94m####### APPEL ");
				ft_putnbr(++i);
				ft_putendl(" #######");
				ft_putstr("\033[92m");
				ft_putendl(line);

				
			}
	return (0);
}