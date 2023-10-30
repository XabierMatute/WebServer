/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:19:27 by xmatute-          #+#    #+#             */
/*   Updated: 2023/10/30 11:31:31 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using	std::cerr;
using	std::cout;
using	std::endl;

#include <string>
using	std::string;

const string defaultPath = "config/default.yml";

#include "Config.hpp"


int run(const string &path)
{
	cout << " vamos a intentar correrlo con archivo de configuración " << '"' << path << '"' << endl;
	try
	{
		cout << " intentamos instanciar Config con el path " << '"' << path << '"' << endl;
		Config	config(path);
		cout << " Config instanciado!" << endl;
		cout << " Queremos " << config.getServerNum() << " servidores" << endl;
		cout << " Queremos " << config.getName(0) << " servidor" << endl;
		cout << " Queremos " << config.getRoot(0) << " raiz" << endl;
		cout << " 404 " << config.getErrorPages(0)[404] << "" << endl;
		

	}
	catch(const std::exception& e)
	{
		std::cerr << '\n' << "Error:\n" << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
	cout << " has introducido " << argc << " argumentos en " << argv[0] << endl;
	if (argc > 2)
	{
		cerr << "❌Error: demasiados argumentos de entrada, espero uno o niguno" << endl;
		return(EXIT_FAILURE);
	}
	if (argc == 2)
		return(run(argv[1]));
	cout << " vamos a usar el path por defecto " << '"' << defaultPath << '"' << endl;

	return(run(defaultPath));
}
