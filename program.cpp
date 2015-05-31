/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakatos <lakatosandrei@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 13:42:02 by alakatos          #+#    #+#             */
/*   Updated: 2015/05/31 18:13:29 by alakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rentMovie(Movie* movie)
{
	int		nr;
	int		nr_copies;

	nr_copies = movie->getNrOfCopies();
	std::cout << "Scrie cate DVD-uri vrei sa inchiriezi pentru filmul sau 0 daca vrei sa iesi: \n" << movie << "\n\n";
	std::cin >> nr;
	if (nr == 0)
		return ;
	if (nr <= nr_copies)
		movie->setNrOfCopies(nr_copies - nr);
	else
		std::cout << "Nu exista " << nr << " filme de acest tip.\n\n";
}

int		main(void)
{
	Colectie<Movie>	colectie;
	Movie			*movie = new Movie(strdup("American Sniper"), strdup("Eu"), 2);
	int				opt;
	Movie*			aux;

	colectie.addElement(movie);
	while (1)
	{
		std::cout << "Selecteaza filmul pe care vrei sa-l inchiriezi sau 0 daca vrei sa iesi\n\n";
		std::cout << colectie;
		std::cin >> opt;
		if (opt == 0)
			break ;
		aux = colectie.getOpt(opt);
		if (aux != 0)
			rentMovie(aux);
	}
	delete movie;
	return (0);
}
