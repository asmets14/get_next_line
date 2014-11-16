/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:46:52 by asmets            #+#    #+#             */
/*   Updated: 2014/11/16 22:50:07 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 100 // AJOUTER LES SECUS

int get_next_line(int const fd, char **line)
{	
	int ret = 0;
	char buff[BUFF_SIZE + 1]; // faire une allocation dynamique 
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	ft_putstr(buff);

	return (0);
}

int main()
{
	char **line = malloc(100);
	int  fd;
	fd = open("texte.txt", O_RDONLY);
	get_next_line(fd, line);
	return (0);

}
