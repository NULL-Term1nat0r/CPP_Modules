/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:01:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/05 18:10:19 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


std::string replaceAll(const std::string& original, const std::string& search, const std::string& replace) {
    std::string result;
    size_t startPos = 0;
    size_t foundPos = original.find(search);

    while (foundPos != std::string::npos) {
        result += original.substr(startPos, foundPos - startPos) + replace;
        startPos = foundPos + search.length();
        foundPos = original.find(search, startPos);
    }

    result += original.substr(startPos);
    return result;
}

int main(int argc, char **argv ){
	if (argc != 4){
		std::cout << "Provide valid amount of arguments\n";
	}
	else{
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		std::ifstream inputFile;
		inputFile.open(argv[1], std::ios::in);
		 if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing " << std::endl;
        return 1;
    }
		std::ofstream outputFile("output.txt", std::ios::out | std::ios::app);
		if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
        return 1;
    }
		if (inputFile.is_open()) {
        	std::string line;
			std::string new_text;
       		 while (std::getline(inputFile, line)) {
				std::cout << red << "oldline: " << line << reset << std::endl;
				new_text = replaceAll(line, s1, s2);
				outputFile << new_text << "\n";
            	std::cout << green <<"new line " << new_text << "	----> successfully wrote to output.txt" << std::endl; << reset;
       		 }
		}
		inputFile.close();
		outputFile.close();
	}
	return 0;
}
