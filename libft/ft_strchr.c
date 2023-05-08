/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz < pde-souz@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:37:53 by pde-souz          #+#    #+#             */
/*   Updated: 2023/04/11 14:38:05 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (((char)c) != *s)
	{
		if (*s == 0)
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}