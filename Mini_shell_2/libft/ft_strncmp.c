/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:08:36 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/15 14:11:14 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strncmp(char *s1, const char *s2, unsigned int n)
{
	unsigned int	i ;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
