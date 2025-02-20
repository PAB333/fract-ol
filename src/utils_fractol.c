/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:37:17 by pibreiss          #+#    #+#             */
/*   Updated: 2025/02/20 19:38:42 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}
