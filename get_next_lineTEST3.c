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


//
char manip(char *buf)
{
	char *str;
	char *save;
	int index;
	int j;

	index = ft_strlen(str);
	j = 0;
	while(buf[j])
	{
	if(buf[index] == '\n')
	{
		save = ft_strcpy(save, buf + index)
	}
	str = ft_strnew(BUFF_SIZE + 1);
	str[j]
}
}

int get_next_lineTEST(int const fd, char **line)
{
	char static buf[BUFF_SIZE];
//	int ret;
//	int len;


	while((ret = read(fd, buf, BUFF_SIZE) > 0) // tant que ret n as pas fini de lire tout le fichier
	{
			manip(&buf);
	}



}