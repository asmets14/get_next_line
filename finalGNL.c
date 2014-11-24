/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalGNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 02:02:09 by asmets            #+#    #+#             */
/*   Updated: 2014/11/24 05:29:45 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int liberation(char **str, int size, int truc )
{
	char *tmp;

	if(!*str)
		*str = ft_strnew(size);
	if(truc)
	{
		free (*str);
		*str = NULL;
	}
	tmp = *str;
	return (1);
}

int corps(char **buff, char **str, int truc)
{
	int i;
	int j;
	
	i = 0;
	j = 0;

	if(*str != NULL)
		i = ft_strlen(*str);
	if(!(liberation(str, (i + BUFF_SIZE), truc)))
		return (-1);
	while (buff[0][i] != '\0')
	{
		ft_putchar(buff[0][i]);
		if(buff[0][i] == '\n')
		{	
			ft_putstr("XXX");
			while(buff[0][i] != '\0')
				buff[0][j++] = buff[0][i++];
			buff[0][j++] = '\0';
			return(RETURN_LINE);
		}
		str[0][i++] = buff[0][i++];
	}
	str[0][i++] = '\0';
	return (2);
}


int			get_next_line(int const fd, char ** line)
{
	static char *buff;
	int ret;
	
	if (buff == NULL)
		buff = ft_strnew(BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if((ret = corps(&buff, line, 1)) == 1)
			return(RETURN_LINE);
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
				ft_putstr("\033[92m###### APPEL ");
				ft_putnbr(++i);
				ft_putendl(" ######\033[0m");
				ft_putendl(line);
				free(line);
				line = NULL;
			}
	return (0);
}
