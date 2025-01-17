/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:41:30 by vejurick          #+#    #+#             */
/*   Updated: 2024/11/28 20:30:42 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("Default"){}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery)
{
	*this = shrubbery;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubbery)
{
	(void)shrubbery;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &Bureaucrat) const
{
	int	shrubbery;
	std::ofstream	file;

	this->AForm::executeCheck(Bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	 file << "                                                  .\n";
    file << "                                              .         ;  \n";
    file << "                 .              .              ;%     ;;   \n";
    file << "                   ,           ,                :;%  %;   \n";
    file << "                    :         ;                   :;%;'     .,   \n";
    file << "           ,.        %;     %;            ;        %;'    ,;\n";
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
    file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
    file << "                    `:%;.  :;bd%;          %;@%;'\n";
    file << "                      `@%:.  :;%.         ;@@%;'   \n";
    file << "                        `@%.  `;@%.      ;@@%;         \n";
    file << "                          `@%%. `@%%    ;@@%;        \n";
    file << "                            ;@%. :@%%  %@@%;       \n";
    file << "                              %@bd%%%bd%%:;     \n";
    file << "                                #@%%%%%:;;\n";
    file << "                                %@@%%%::;\n";
    file << "                                %@@@%(o);  . '         \n";
    file << "                                %@@@o%;:(.,'         \n";
    file << "                            `.. %@@@o%::;         \n";
    file << "                               `)@@@o%::;         \n";
    file << "                                %@@(o)::;        \n";
    file << "                               .%@@@@%::;         \n";
    file << "                               ;%@@@@%::;.          \n";
    file << "                              ;%@@@@%%:;;;. \n";
    file << "                          ...;%@@@@@%%:;;;;,..    \n";
	file.close();
}