/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:06:21 by nseon             #+#    #+#             */
/*   Updated: 2025/12/19 09:30:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &m);
		Intern &operator=(Intern const &m);
		~Intern();
		
		AForm *makeForm(std::string name, std::string target);
};
