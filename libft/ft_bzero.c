/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:47 by macote            #+#    #+#             */
/*   Updated: 2023/03/24 14:47:33 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(unsigned char **s, size_t n)
{
	int				i;
	unsigned char	*set_str;

	if (!s)
		return ;
	i = 0;
	set_str = *s;
	while (n > 0)
	{
		set_str[i++] = '\0';
		n--;
	}
}
