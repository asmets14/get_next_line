/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:46:52 by asmets            #+#    #+#             */
/*   Updated: 2014/11/18 01:28:07 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "Libft/libft.h"
#define BUFF_SIZE 1000


//Check mes ligne;
// Realloc 


int get_next_lineTEST(int const fd, char **line)
{
	char static buf[BUFF_SIZE];
	int ret;
	int len;
	int index;
	char *save;
	char *str;
	*line = ft_strnew(BUFF_SIZE);

	while((ret = read(fd, buf, BUFF_SIZE)) && (ft_strchr(buf, '\n')))
	{
		len = ((ft_strchr(buf, '\n')) - (&buf[0]));
		str = ft_strnew(len);
		

		ft_putstr(buf);
		index = 0;
		while(index < len)
		{
			str[index] = buf[index];
			index++;
		}
		str[index] ='\0';
		//ft_putstr(str);
		save = ft_strcpy(buf, buf + index);
		
		ft_putstr("\n");
		ft_putstr(buf);

	}
	// SI RET != 0 + Condition si la fin de str est = /0
	if(buf[0] == '\n')
	{
			
		index = 0;
		save = save + 1;

			while(save[index] != '\n')
				index++;
			if(save[index] == '\0')
				return (0);
			
			str = ft_strnew(index + 1);
			index = 0;
			while(save[index] != '\n')
			{
				str[index] = save[index];
				index++;
			}
			str[index] = '\0';
			//ft_putstr(str);
}	
	return (0);
}

int main()
{
	char *line;
	int fd;

	fd = open("texte.txt", O_RDONLY);
	get_next_lineTEST(fd, &line);
	

	
	return (0);
}