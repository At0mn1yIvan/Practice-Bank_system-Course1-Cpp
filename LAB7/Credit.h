#pragma once

#include "ProcCenter.h"

class Credit : public ProcCenter
{
public:
	int user_;
public:
	Credit();
	void Authorization();
	void ShowTheRates();
	void TakeTheCredit();
	void IsCredit();
	void IsCreditAvailable();
	void CreditStatus();
	void RepayTheDept();
	void RepayTheDeptEarly();
	void Menu();
	void EscapeBind();
};

