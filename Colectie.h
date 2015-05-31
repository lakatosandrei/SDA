/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colectie.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakatos <lakatosandrei@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 13:48:08 by alakatos          #+#    #+#             */
/*   Updated: 2015/05/31 18:13:15 by alakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLECTIE_H
# define COLECTIE_H

# include "Movie.h"
template<class TElement>
class	Colectie
{
	private:
		TElement**	lista;
		int*		urm;
		int*		prec;
		int			cap;
		int			prim;
		int			ultim;
		int			primliber;

	public:
		Colectie(void);
		Colectie(int cap);
		~Colectie(void);
		void					getCapacity(void);
		void					addElement(TElement* elem);
		int						alocate(void);
		int						createNode(TElement* elem);
		Movie*					getOpt(int opt);
		friend std::ostream&	operator<<(std::ostream& out,
				const Colectie<TElement>& col)
		{
			int		i;
			int		j;

			j = 1;
			out << "Ordinea informatiilor: Numele filmului, autorul filmului, numarul de copii.\n\n";
			out << "Filmele actuale:\n";
			for (i = col.prim; i != 0; i = col.urm[i])
				out << j++ << '\n' << *(col.lista[i]) << '\n';
			return (out);
		}
};

template<class TElement>
Colectie<TElement>::Colectie(void)
{
	int		i;

	this->lista = (TElement **)malloc(sizeof(TElement *) * 100);
	this->urm = (int *)malloc(sizeof(int) * 100);
	this->prec = (int *)malloc(sizeof(int) * 100);
	this->cap = 100;
	for (i = this->cap; i > 0; i--)
	{
		this->urm[i] = i - 1;
		if (i != 1)
			this->prec[i - 1] = i;
	}
	this->prec[this->cap] = 0;
	this->primliber = this->cap;
}

template<class TElement>
Colectie<TElement>::Colectie(int cap)
{
	int		i;

	this->lista = (TElement **)malloc(sizeof(TElement *) * cap);
	this->urm = (int *)malloc(sizeof(int) * cap);
	this->prec = (int *)malloc(sizeof(int) * cap);
	this->cap = cap;
	for (i = this->cap; i > 0; i--)
	{
		this->urm[i] = i - 1;
		if (i != 1)
			this->prec[i - 1] = i;
	}
	this->prec[this->cap] = 0;
	this->primliber = this->cap;
}

template<class TElement>
Colectie<TElement>::~Colectie(void)
{
	int		i;

	for (i = this->prim; i != 0; i = this->urm[i])
		free(this->lista[i]);
	free(this->lista);
	free(this->urm);
	free(this->prec);
}

template<class TElement>
void	Colectie<TElement>::getCapacity(void)
{
	return (this->cap);
}

template<class TElement>
int		Colectie<TElement>::alocate(void)
{
	int		i;

	i = this->primliber;
	if (i == 0)
	{
		this->cap *= 2;
		this->lista = (TElement **)realloc(this->lista, sizeof(TElement *) * this->cap);
		this->urm = (int *)realloc(this->urm, sizeof(int) * this->cap);
		this->prec = (int *)realloc(this->prec, sizeof(int) * this->cap);
	}
	this->primliber = this->urm[i];
	return (i);
}

template<class TElement>
int		Colectie<TElement>::createNode(TElement* elem)
{
	int		i;

	i = alocate();
	this->lista[i] = (TElement*)malloc(sizeof(TElement));
	*(this->lista[i]) = *(elem);
	this->urm[i] = 0;
	this->prec[i] = i;
	return (i);
}

template<class TElement>
void	Colectie<TElement>::addElement(TElement* elem)
{
	int		i;

	i = createNode(elem);
	this->urm[i] = this->prim;
	if (this->prim == 0)
		this->ultim = i;
	else
		this->prec[this->prim] = i;
	this->prim = i;
}

template<class TElement>
Movie*	Colectie<TElement>::getOpt(int opt)
{
	int		i;
	int		j;

	j = 1;
	for (i = this->prim; i != 0 && j != opt; i = this->urm[i], j++);
	return (this->lista[i]);
}

#endif
