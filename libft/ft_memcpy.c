/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:58:33 by jfrankly          #+#    #+#             */
/*   Updated: 2018/11/29 17:08:35 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = dest;
	p2 = (unsigned char *)src;
	while (n--)
		*(p1++) = *(p2++);
	return (dest);
}
