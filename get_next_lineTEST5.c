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

// FONCTION MANIPULATION DE BUF ET SAVE if(!nom)
	void copy_buf_in_save(char *buf, t_gnlist *var)
	{
		var->bufi = 0;
		var->len = 0;
		var->save = ft_strnew(BUFF_SIZE + 1);
		while (buf[var->bufi] != '\0')
		{
			(var->save)[var->len] = (buf)[var->bufi];
			(var->len)++;
			(var->bufi)++;
		}
		(var->save)[var->len] = '\0';
	}

// FONCTION POUR LA PREMIERE FOIS if(!nom)
	int manip_first(t_gnlist *var)
	{
		var->str = ft_strnew(BUFF_SIZE + 1);
		var->index = 0;
		while ((var->save)[var->index] != '\n')
		{
			(var->str)[var->j++] = (var->save)[var->index++];
		}
		ft_putstr(var->str);
			if ((var->save)[var->index] != '\0')
			return (1);
		return (0);
	}

//FONCTION POUR LE RESTE if(nom == 1)
	int good_line(t_gnlist *var)
	{
		if ((var->save)[var->index] == '\n')
		{
			(var->index)++;
			free(var->str);
			var->str = ft_strnew(BUFF_SIZE + 1);	
			var->len = 0;
			while ((var->save)[var->index] != '\n' || (var->save)[var->index] != '\0' )
				(var->str)[var->len++] = (var->save)[var->index++];	
			(var->str)[var->len++] = '\0';
			//t_putstr(var->str);
		}
		if((var->save)[var->index] != '\0')
			return (1);
		return (0);
	}

	void sauvegarde(t_gnlist *var, char **tmp)
	{
		var->j = 0;
		tmp[0] = ft_memalloc(BUFF_SIZE);
		var->index++;
		if ((var->save)[var->index] != '\0')
		{
			while((var->save)[var->index])
			{
				tmp[0][var->j] = (var->save)[var->index];
				(var->save)[var->index++];
				var->j++;
			}
		
			free(var->save);
			var->save = NULL;
		}
	}

int get_next_lineTEST(int const fd, char **line)
{
	t_gnlist var;
	static char buf[BUFF_SIZE];
	static char *tmp;

	*line = ft_strnew(BUFF_SIZE);
	var.retour = 0;
	var.goodreturn = 0;

	while((var.ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if(tmp == NULL)
		{
			if(!(var.save)) // copy
				copy_buf_in_save(buf, &var);
			if(var.retour == 0 && var.save) // premiere fois
				var.retour = manip_first(&var);
			if(var.retour == 1)
				sauvegarde(&var, &tmp);
			ft_putstr(tmp);
		}
		
		else if(tmp) // autre
		{
			ft_putstr("XXX");
			var.j = 0;
			 while(tmp)
			 {
			 	(*(var.save)++) = *(tmp)++;
			 }
			 free(tmp);
			 (var.save)[var.j++] = '\0';
			 good_line(&var);
			 if(var.goodreturn == 1)
			 	sauvegarde(&var, &tmp);
		}
	}
	return (0);
}

void main()
{
	char *line;
	int fd;
	fd = open("texte.txt", O_RDONLY);
	get_next_lineTEST(fd, &line);
	ft_putstr("\n seconde \n");
	get_next_lineTEST(fd, &line);

}
