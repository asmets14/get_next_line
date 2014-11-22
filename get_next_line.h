/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 21:40:38 by asmets            #+#    #+#             */
/*   Updated: 2014/11/19 21:40:45 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"

# define RETURN_ERROR -1
# define RETURN_EOF 0
# define RETURN_LINE 1
# define RETURN_CONCAT 2

# define BUFF_SIZE 1

typedef struct s_gnlist
{
	int		index;
	int		bufi;
	int		j;
	char	*str;
	int		len;
	char	*save;
	int		retour;
	int		goodreturn;
	int		ret;
}				t_gnlist;

#endif