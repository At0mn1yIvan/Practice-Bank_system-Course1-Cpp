#include <stdlib.h>
#include "Credit.h"
#include "Conio.h"



Credit::Credit() : user_(0)
{
	int acc;
	std::string passw;
	std::cout << "Enter the salary account number: ";
	std::cin >> acc;
	std::cout << "\nEnter password: ";
	std::cin >> passw;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (acc == data_acc[i] && passw == password[i]) {
			user_ = i;
			flag = 1;
			Menu();
			break;
		}
	}
	if (flag == 0) {
		std::cout << "Client not found" << std::endl;
		Menu();
	}
}

void Credit::Authorization()
{
	int acc;
	std::string passw;
	std::cout << "Enter the salary account number: ";
	std::cin >> acc;
	std::cout << "\nEnter password: ";
	std::cin >> passw;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (acc == data_acc[i] && passw == password[i]) {
			user_ = i;
			flag = 1;
			Menu();
			break;
		}
	}
	if (flag == 0) {
		std::cout << "Client not found" << std::endl;
		Menu();
	}
}

void Credit::ShowTheRates()
{
	std::cout <<"Rates:\n1. Up to 100 thousand rubles (10% / 6 months)\n2. From 100 to 500 thousand rubles (8% / 12 months)\n3. From 500 thousand to 1 million rubles (6% / 20 months)\n4. From 1 to 3 million rubles (4% / 36 months)" << std::endl;
	EscapeBind();
}


void Credit::TakeTheCredit()
{
	if (credit_info[0][user_] == 0) {
		do {
			std::cout << "Enter the desired loan amount: \n";
			std::cin >> credit_info[1][user_];
		} while (credit_info[1][user_] <= 0);
			
		std::cout << "The loan is issued!" << std::endl;
		credit_info[0][user_] = 1;
		if (0 < credit_info[1][user_] && credit_info[1][user_] < 100000) {
			credit_info[4][user_] = 6;
			credit_info[6][user_] = 10;
		}
		if (100000 <= credit_info[1][user_] && credit_info[1][user_] < 500000) {
			credit_info[4][user_] = 12;
			credit_info[6][user_] = 8;

		}
		if (500000 <= credit_info[1][user_] && credit_info[1][user_] < 1000000) {
			credit_info[4][user_] = 20;
			credit_info[6][user_] = 6;

		}
		if (1000000 <= credit_info[1][user_] && credit_info[1][user_] < 3000000) {
			credit_info[4][user_] = 36;
			credit_info[6][user_] = 4;
		}
		money[user_] += credit_info[1][user_];
		credit_info[2][user_] = (credit_info[1][user_] / 100 * (100 + credit_info[6][user_])) / credit_info[4][user_];
		credit_info[3][user_] = credit_info[1][user_] / 100 * (100 + credit_info[6][user_]);
		credit_info[5][user_] = credit_info[4][user_];
		EscapeBind();
	}
	else {
		std::cout << "Loan processing is not available\n";
		EscapeBind();
	}
}

void Credit::IsCredit()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "The loan you took: ";
		if (0 < credit_info[1][user_] && credit_info[1][user_] < 100000)
			std::cout << " Up to 100 thousand rubles (10% / 6 months)" << std::endl;
		if (100000 <= credit_info[1][user_] && credit_info[1][user_] < 500000)
			std::cout << " From 100 to 500 thousand rubles (8% / 12 months)" << std::endl;
		if (500000 <= credit_info[1][user_] && credit_info[1][user_] < 1000000)
			std::cout << " From 500 thousand to 1 million rubles (6% / 20 months)" << std::endl;
		if (1000000 <= credit_info[1][user_] && credit_info[1][user_] < 3000000)
			std::cout << "  From 1 to 3 million rubles (4% / 36 months)" << std::endl;
		std::cout << "\nLoan amount: " << credit_info[1][user_] << std::endl;
		EscapeBind();
	}
	else {
		std::cout << "You don't have any issued loans" << std::endl;
		EscapeBind();
	}
	
}

void Credit::IsCreditAvailable()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "The loan has already been taken. Taking a second loan is not possible" << std::endl;
	}
	else {
		std::cout << "Loan processing is available" << std::endl;
	}
	EscapeBind();
}

void Credit::CreditStatus()
{
	std::cout << "Client: " << name_sername_patro[user_] << std::endl;
	std::cout << "Amount of money in the account: " << money[user_] << std::endl;
	if (credit_info[0][user_] == 1) {
		std::cout << "Loan amount: " << credit_info[1][user_] << std::endl;
		std::cout << "Monthly payment: " << credit_info[2][user_] << std::endl;
		std::cout << "Loan balance: " << credit_info[3][user_] << std::endl;
		std::cout << "Loan period (months): " << credit_info[4][user_] << " || ќсталось мес€цев: " << credit_info[5][user_] << std::endl;
	}
	else
		std::cout << "There are no loans taken" << std::endl;
	EscapeBind();
}

void Credit::RepayTheDept()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Client: " << name_sername_patro[user_] << std::endl;
		std::cout << "Amount of money in the account: " << money[user_] << std::endl;
		std::cout << "Months left: " << credit_info[5][user_] << std::endl;
		std::cout << "Loan balance: " << credit_info[3][user_] << std::endl;
		std::cout << "Monthly payment: " << credit_info[2][user_] << std::endl;
		std::cout << "\nPay off the loan debt for the current month?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[2][user_]) {
				money[user_] -= credit_info[2][user_];
				credit_info[3][user_] -= credit_info[2][user_];
				credit_info[5][user_]--;
				system("cls");
				if (credit_info[3][user_] == 0) {
					credit_info[0][user_] = 0;
					system("cls");
					std::cout << "\nCongratulations! You have just paid off your loan in full!" << std::endl;
					EscapeBind();
				}
				RepayTheDept();
			}
			else
				std::cout << "There are not enough funds on the account to repay the loan debt" << std::endl;
		}
		else {
			system("cls");
			Menu();
		}
	}
	else
		std::cout << "There are no loans taken" << std::endl;
	EscapeBind();
}

void Credit::RepayTheDeptEarly()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Client: " << name_sername_patro[user_] << std::endl;
		std::cout << "Amount of money in the account: " << money[user_] << std::endl;
		std::cout << "Months left: " << credit_info[5][user_] << std::endl;
		std::cout << "Loan balance: " << credit_info[3][user_] << std::endl;
		std::cout << "Monthly payment: " << credit_info[2][user_] << std::endl;
		std::cout << "\nRepay the loan ahead of schedule?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[3][user_]) {
				money[user_] -= credit_info[3][user_];
				credit_info[3][user_] = 0;
				credit_info[5][user_] = 0;
				credit_info[0][user_] = 0;
				system("cls");
				std::cout << "\nCongratulations! You have just paid off your loan ahead of schedule!" << std::endl;
			}
			else
				std::cout << "There are not enough funds on the account to repay the loan ahead of schedule" << std::endl;
		}
		else
			RepayTheDeptEarly();
	}
	else
		std::cout << "There are no loans taken" << std::endl;
	EscapeBind();
}

void Credit::Menu()
{
	std::cout << "\nSelect an option:\n" << std::endl;
	std::cout << "1) Client authorization\n2) Information about available loans\n3) Check the availability of a loan taken from the bank\n4) Check the possibility of obtaining the selected loan\n";
	std::cout << "5) Get the selected loan\n6) Show the current status of the loan\n7) Repay loan accruals\n8) Repay the loan early\n";
	switch (_getch())
	{
	case 49: system("cls"); Authorization(); break;
	case 50: system("cls"); ShowTheRates(); break;
	case 51: system("cls"); IsCredit(); break;
	case 52: system("cls"); IsCreditAvailable(); break;
	case 53: system("cls"); TakeTheCredit(); break;
	case 54: system("cls"); CreditStatus(); break;
	case 55: system("cls"); RepayTheDept(); break;
	case 56: system("cls"); RepayTheDeptEarly(); break;
	case 27: EscapeBind(); break;
	}
}

void Credit::EscapeBind()
{
	if (_getch() == 27) {
		system("cls");
		Menu();
	}
}



