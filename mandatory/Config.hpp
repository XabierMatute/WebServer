/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:32:06 by xmatute-          #+#    #+#             */
/*   Updated: 2023/10/30 16:51:06 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Config_HPP
# define Config_HPP

#include <fstream>
using	std::ifstream;

#include <iostream>
using	std::cerr;
using	std::cout;
using	std::endl;

#include <string>
using	std::string;

#include <vector>
#include <map>

// #include "templates.h"

typedef std::vector<int> intVector;//ta feo k este aqui
typedef std::map<int, std::string> intCharMap;
#include "Location.hpp"
typedef std::vector<Location> locationVector;



class Config : protected ifstream
{
	private:
		string	path;
		string	line;
		size_t	ServerNum;
		size_t	lineNum;

		std::vector<string>		server_name;
		std::vector<string>		root;
		std::vector<intVector>	ports;
		std::vector<intCharMap>	error_pages;
		std::vector<locationVector>	locations;

		void		init();
		string		&nextline();
		string		&skipLine(const std::string &expected);
		void		lineException(const std::string &problem);
		string		getToken(const std::string &pre);
		intVector	parsePorts(const char *s);
		intCharMap	parseErrorPages();
		locationVector	parseLocations();
		
	public:
		Config(const std::string &path);
		~Config();

		size_t 			getServerNum();
		string			getName(size_t index);
		string			getRoot(size_t index);
		intVector		getPorts(size_t index);
		intCharMap		getErrorPages(size_t index);


};


#endif