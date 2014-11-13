/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:46:52 by asmets            #+#    #+#             */
/*   Updated: 2014/11/13 16:49:51 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 100 // AJOUTER LES SECUS

int get_next_line(int const fd, char **line);
{	
	char *tmp;
	char buf; // buffer read
	int ret; // retour de read
	int	port_sortie;

	port_sortie = open(fd, O_Rdonly);
	buff = BUFF_SIZE + 1; // +1 = '\0' ou faire une allocation dynamique de memoire !! alors mettre free
	buf[ret] = '\0';
	ret = read (fd, buf,BUFF_SIZE)
	
	close(port_sortie);
	return (0);
}

