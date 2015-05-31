/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colectie.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 14:46:18 by alakatos          #+#    #+#             */
/*   Updated: 2015/05/31 14:56:07 by alakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

template<class TElement>
std::ostream&	operator<<(std::ostream& out, const Colectie<TElement>& col)
{
	int		i;

	out << "Pizda matii\n";
	for (i = 0; i < col->cap; i++)
	{
		out << col->lista[i] << ' ';
	}
	return (out);
}
