// BankApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class BankAccount
{
protected:
	int accountNumber;
	float interestRate;
	float balance;
	int termYr;
public:
	BankAccount()
	{
		accountNumber = 0;
		interestRate = .0;
		balance = 0;
	}
	virtual void withdraw() = 0;
	virtual void deposit() = 0;
	virtual void display() = 0;
	virtual void getInfo() = 0;
	virtual void savingsBalance() = 0;
};

class Savings : public BankAccount
{
	void getInfo()
	{
		cout << "what is your account number?" << endl;
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
	}
	void savingsBalance()
	{
		float preBalance;
		if (balance < 10000)
		{
			interestRate = .1;
		}
		else
		{
			interestRate = .2;
		}
		preBalance = balance * interestRate;
		balance = balance + preBalance;
	}
	void withdraw()
	{
		char answer[2];
		cout << "do you want to make a withdraw? you will be charged $2" << endl;
		gets_s(answer);
		if (answer == "y" || answer == "Y")
		{
			balance = balance - 2;
			int value;
			cout << "what amount do you want withdrawn?" << endl;
			cin >> value;
			cin.clear();
			cin.ignore();
			if (value >= 0)
				balance = balance - value;
		}
	}
};

class Checking : public BankAccount
{
	void getInfo()
	{
		cout << "what is your account number?" << endl;
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
	}
	void checkingFee()
	{
		if (balance < 500)
		{
			balance = balance - 5;
		}
	}
	void orderChecks()
	{
		balance = balance - 15;
	}

};

class CertificateOfDeposit : public BankAccount
{
	void getInfo()
	{
		cout << "what is your account number?" << endl;
		cin >> accountNumber;
		cin.clear();
		cin.ignore();
	}
	void cdBalance()
	{
		float beforeInterest;
		if (termYr >= 5)
		{
			beforeInterest = balance * .1;
			balance = balance + beforeInterest;
		}
		else if (termYr < 5)
		{
			beforeInterest = balance * .05;
			balance = balance + beforeInterest;
		}
	}
	void withdraw()
	{
		int withdraw;
		int withdrawAmount;
		if (withdraw < termYr)
		{
			withdrawAmount = balance * .1;
			balance = balance - withdrawAmount;
		}
		else if (withdraw < 0)
		{
			cout << "You cannot withdraw a negative amount " << endl;
		}
	}
};

int main()
{
	//	Create a new savings account  and deposit $10k
	//		Create a new checking account and deposit $600
	//	Create a new CD account  with a 3 year term and deposit $10K

	//Get and display the attributes for  each account
	//	Calculate monthly interest for the savings account
	//	Calculate  the monthly interest for the CD account
	//	Get and display the attributes for  each account
	//	Order checks
	//	Withdraw $200 from checking
	//	Withdraw $1000 from Savings
	//	Perform an early withdrawal of $2000 from the CD account
	//	Get and display the account attributes for  each account
	BankAccount **bptr;
	int accountType = 0;
	char answer[2];

	bptr = new BankAccount *[accountType];
	for (int i = 0; i < accountType; i++)
	{
		cout << "What kind of account are you opening? If savings use S, Checking use C, certificate use D ";
		gets_s(answer);
		if (strcmp(answer, "S") == 0)
		{
			bptr[i] = new Savings();
			bptr[i]->deposit();
		}
		else if (strcmp(answer, "C") == 0)
		{
			bptr[i] = new Checking();
			bptr[i]->deposit();
		}
		else if (strcmp(answer, "D") == 0)
		{
			bptr[i] = new CertificateOfDeposit();
			bptr[i]->deposit();
		}
		else
		{
			cout << "try again" << endl;
			--i;
		}
	}

	return 0;
}

