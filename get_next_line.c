/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalGNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 02:02:09 by asmets            #+#    #+#             */
/*   Updated: 2014/11/26 02:40:56 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		liberation(char **str, int size, int truc)
{
	char *tmp;

	if ((tmp = ft_strnew(size)) == NULL)
		return (0);
	if (*str)
		tmp = ft_strcpy(tmp, *str);
	if (*str && truc)
	{
		free (*str);
		*str = NULL;
	}
	*str = tmp;
	return (1);
}

int		corps(char **buff, char **str, int truc)
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	if (*str != NULL)
		i[1] = ft_strlen(*str);
	if (!(liberation(str, (i[1] + BUFF_SIZE), truc)))
		return (-1);
	while (buff[0][i[0]] != '\0')
	{
		if (buff[0][i[0]] == '\n')
		{
			str[0][i[1]] = '\0';
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

int		get_next_line(int const fd, char **line)
{
	static char *buff;
	int			ret;
	int			rread;

	rread = 0;
	if (buff != NULL && (ret = corps(&buff, line, 0)) == 1)
		return (RETURN_LINE);
	else if (ret == -1)
		return (ret);
	if (buff == NULL)
		buff = ft_strnew(BUFF_SIZE);
	while ((rread = read(fd, buff, BUFF_SIZE)) > 0)
		if ((ret = corps(&buff, line, 1)) == 1)
			return (RETURN_LINE);
	if (rread == -1 || ret == -1)
		return (-1);
	return (0);
}
