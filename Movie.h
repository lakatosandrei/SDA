/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movie.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:41:11 by alakatos          #+#    #+#             */
/*   Updated: 2015/05/31 18:13:09 by alakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_H
# define MOVIE_H

# include "header.h"

class	Movie
{
	private:
		char*	title;
		char*	author;
		int		nr_copies;

	public:
		Movie(char* title, char* author, int nr);
		~Movie(void);
		void					setNrOfCopies(int nr) { this->nr_copies = nr; };
		char*					getTitle(void) { return (this->title); }
		char*					getAuthor(void) { return (this->author); }
		int						getNrOfCopies(void) { return (this->nr_copies); }
		friend std::ostream&	operator<<(std::ostream& out, const Movie& movie)
		{
			out << movie.title << "    " << movie.author << "    " << movie.nr_copies;
			return (out);
		}
		friend std::ostream&	operator<<(std::ostream& out, Movie* movie)
		{
			out << movie->title << "    " << movie->author << "    " << movie->nr_copies;
			return (out);
		}
};

Movie::Movie(char* title, char* author, int nr)
{
	this->title = strdup(title);
	this->author = strdup(author);
	this->nr_copies = nr;
}

Movie::~Movie(void)
{
	free(this->title);
	free(this->author);
}

#endif
