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

int nom(char *buf, )
{
	int index;
	int bufi;
	//char *str;
	char *save;

	if(str)
		bufi = ft_strlen(str);
	bufi = 0;

	while (buf[bufi] != 0)
	{

		index = 0;
		str = ft_strnew(BUFF_SIZE + 1);
		/*if(buf[bufi] != '\n')
		{
			while(buf[bufi] != '\n')
			{
			str[index] = buf[bufi];
			index++;
			bufi++;
			}
		
			str[index++] = '\0';
			ft_putstr(str);
			ft_putstr("\t");
			ft_putstr("1");

		//	return (1);
		}	
		ft_putstr(buf);
		*/
		if(buf[bufi + 1] == '\n')
		{
			ft_putstr("XXX");
			index = 0;
			//str = ft_strnew(BUFF_SIZE + 1);
			//save = ft_strcpy(save, buf + bufi);
			//while(save[index] != '\n')
			//index++;
		//if(save[index] == '\0')
			//	return (0);
			//index = 0;
			while(buf[bufi] != '\0')
			{
				str[index] = save[index]; 
				index++;
				bufi++;
			}
			str[index] = '\0';
			ft_putstr(str);
			ft_putstr("\t");
			ft_putstr("2");
			return (1);
		}
		str[index++] = buf[bufi++];
		if(buf[bufi] == '\0')
			return(0);
		return (1);
	}
}

int get_next_lineTEST(int const fd, char **line)
{
	char static buf[BUFF_SIZE];
	int ret;

	*line = ft_strnew(BUFF_SIZE); // NE PAS OUBLIER DE LE CHANGER AVEC STR

	/*while((ret = read(fd, buf, BUFF_SIZE)) && (ft_strchr(buf, '\n')))
	{
		len = ((ft_strchr(buf, '\n')) - (&buf[0]));
		str = ft_strnew(len);
		index = 0;
		while(index < len)
		{
			str[index] = buf[index];
			index++;
			
		}
		str[index] ='\0';
		ft_putstr(str);
		save = ft_strcpy(buf, buf + index);

	}*/

	while((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		nom(buf);
		if(nom (buf) == 1)
			nom(buf);	
		return (0);
	}
}
int main()
{
	char *line;
	int fd;

	fd = open("texte.txt", O_RDONLY);
	get_next_lineTEST(fd, &line);
	get_next_lineTEST(fd, &line);

	
	return (0);
}