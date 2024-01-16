/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:19:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/05 19:18:10 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

#define red "\033[31m"
#define green "\033[32m"
#define blue "\033[34m"
#define cyan "\033[36m"
#define reset "\033[0m"

class Harl{

	public:
	Harl();
	~Harl();
	void complain(std::string level);
	void setArray(void);

	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	struct Loglevel {
		std::string name;
		void(Harl::*handler)(void);
	};
	Loglevel levels[4];
};

#endif
