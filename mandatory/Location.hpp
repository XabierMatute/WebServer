#ifndef LOCATION_HPP

# define LOCATION_HPP

#include <iostream>

class Location
{
	private://mejor const
		std::string path;
		std::string	root;
		std::string	index;
		bool	GET;
		bool	POST;
		bool	DELETE;
		bool	autoindex;
		size_t		max_body_size;
		std::string	redirection;
		std::string	destination;
		std::string	cgi_destinaation;

		Location();

	public:
		Location(\
				const std::string	path, \
				const std::string	root, \
				const std::string	index, \
				const bool			GET, \
				const bool			POST, \
				const bool			DELETE, \
				const bool			autoindex, \
				size_t				max_body_size,\
				std::string			redirection, \
				std::string			destination, \
				std::string			cgi_destinaation \
		);
		Location(\
				const std::string	&path, \
				const std::string	&root, \
				const std::string	&index, \
				const std::string	&allowed_methods, \
				const std::string	&autoindex, \
				const std::string	&max_body_size, \
				const std::string	&redirection, \
				const std::string	&destination, \
				const std::string	&cgi_destinaation \
		);
		/* Location(const Location& toCopy); */
		~Location();

		Location& operator=(const Location& toCopy);
};

#endif
