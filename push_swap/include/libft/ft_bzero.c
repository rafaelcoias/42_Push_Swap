/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:59:22 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/28 18:41:01 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int main(void)
{
	char	str[12] = "rafael coias";
	ft_bzero(str, 3);
	printf("%s\n", str + 3);
}*/
