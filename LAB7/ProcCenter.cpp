#include "ProcCenter.h"
#include <fstream>
#include <iostream>

ProcCenter::ProcCenter()
{
	// Algoritm to work with file
	std::ifstream fin;
	fin.open("dataFile1.txt");
	int n_getl = -1;
	while (!fin.eof()) {
		std::string str;
		std::getline(fin, str);
		n_getl++;
		int ind = 0;
		for (int i = 0; i < str.length(); i++) {
			std::string str2;
			if (n_getl == 1) {
				while ((str[i] != ' ' || str[i + 1] != ' ') && str[i] != '\0') {
					str2 += str[i];
					i++;
				}
				if (str[i] == ' ' && str[i + 1] == ' ')
					i++;
			}
			else {
				while (str[i] != ' ' && str[i] != '\0') {
					str2 += str[i];
					i++;
				}
			}
			switch (n_getl)
			{
			case 0: data_acc[ind] = std::stoi(str2); ind++; break;
			case 1: name_sername_patro[ind] = str2; ind++; break;
			case 2: money[ind] = std::stoi(str2); ind++; break;
			case 3: password[ind] = str2; ind++; break;
			case 4: credit_info[0][ind] = std::stoi(str2); ind++; break;
			case 5: credit_info[1][ind] = std::stoi(str2); ind++; break;
			case 6: credit_info[2][ind] = std::stoi(str2); ind++; break;
			case 8: credit_info[3][ind] = std::stoi(str2); ind++; break;
			case 9: credit_info[4][ind] = std::stoi(str2); ind++; break;
			case 10: credit_info[5][ind] = std::stoi(str2); ind++; break;
			case 11: credit_info[6][ind] = std::stoi(str2); ind++; break;
			}	
		}
	}
	fin.close();
}
