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
#define BUFF_SIZE 10000


// AJOUTER LES SECUS
//
int get_next_line(int const fd, char **line)
{	
	char *buff;
	int ret;
	char *str;
	int i = 0;
	int len = 0;

	buff = ft_strnew(BUFF_SIZE);
	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE) && (ft_strchr(buff, '\n'))))
	{
		str = ft_strncpy(str, buff, (len =(ft_strchr(buff, '\n') - buff)));
		buff = ft_strchr(buff, '\n') + 1;
	}
	while (i < len)
	{
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
	ft_putstr("LLLLOOOOLLLL\n");
	return (0);
}

int main()
{
	char *line = (char *)malloc(sizeof(char *)*  100);
	int  fd; 	

	fd = open("texte.txt", O_RDONLY);
	get_next_line(fd, &line);
	return (0);	
}
