#pragma once

#include <iostream>
#include <string>


class ProcCenter
{
public:
	ProcCenter();
	uint16_t data_acc[5];
	std::string name_sername_patro[5];
	int money[5];
	std::string password[5];
	int credit_info[7][5];
};

