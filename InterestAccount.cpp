//Kandahar Brewer

#include "InterestAccount.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Constructor method
InterestAccount::InterestAccount(double t_initial, double t_monthly, int t_interest, int t_years)
{
	//Sets up the objects variables based on the constructor arguments
	m_initialInvestment = t_initial;
	m_monthlyDeposit = t_monthly;
	m_interest = t_interest / 100.0;
	m_numYears = t_years;
	m_numMonths = t_years * 12;

	//Resizes the vectors that hold the account balances and monthly interest balances to the total number of months.
	m_accountTotal.resize(m_numMonths);
	m_totalInterest.resize(m_numMonths);
	m_accountTotalPlusMonthly.resize(m_numMonths);
	m_totalInterestPlusMonthly.resize(m_numMonths);
}

//Displays the account balances and interest balance by year and with or without the monthly account investments.
void InterestAccount::display(bool t_monthlyPayment)
{
	//Sets the locale to the US so the put_money method outputs the balances in dollars
	//Then creates a temperary variable to store the interest of the year
	cout.imbue(locale("en_US.UTF-8"));
	double tempInterest = 0.0;

	//determines if the method is being used to calculate with the monthly investment or not
	if (t_monthlyPayment)
	{
		cout << "                Investment Amount with Monthly Deposits               \n";
		cout << "|--------------------------------------------------------------------|\n";
		cout << "|    YEAR    |     YEAR EARNED INTEREST     |     YEAR END TOTAL     |\n";
		cout << "|------------|------------------------------|------------------------|\n";
		cout << "|            |                              |                        |" << endl;

		//For each loop that prints out the yearly balance that includes the monthly investment
		for (int i = 0; i < m_numMonths; i++)
		{
			//Makes sure only the year balances are printed
			if ((i + 1) % 12 == 0)
			{
				//put_money converts a int/double/float into a currency based on the locale
				cout << "| " << setw(10) << ((i + 1) / 12) << " | "
					<< setw(28) << showbase << put_money((tempInterest + m_totalInterestPlusMonthly[i]) * 100) << " | "
					<< setw(22) << showbase << put_money(m_accountTotalPlusMonthly[i] * 100) << " |\n";
				cout << "|            |                              |                        |" << endl;
				
				tempInterest = 0.0;
			}
			else
			{
				//Adds the monthly interest together since it is compounded monthly
				tempInterest += m_totalInterest[i];
			}
		}

		cout << "^------------^------------------------------^------------------------^\n" << endl;
	}
	else
	{
		cout << "             Investment Amount without Monthly Deposits               \n";
		cout << "|--------------------------------------------------------------------|\n";
		cout << "|    YEAR    |     YEAR EARNED INTEREST     |     YEAR END TOTAL     |\n";
		cout << "|------------|------------------------------|------------------------|\n";
		cout << "|            |                              |                        |" << endl;

		//For each loop that prints out the yearly balance, but without the monthly monetary addition
		for (int i = 0; i < m_numMonths; i++)
		{
			if ((i + 1) % 12 == 0)
			{
				cout << "| " << setw(10) << ((i + 1) / 12) << " | "
					<< setw(28) << showbase << put_money((tempInterest + m_totalInterest[i]) * 100) << " | "
					<< setw(22) << showbase << put_money(m_accountTotal[i] * 100) << " |\n";
				cout << "|            |                              |                        |" << endl;

				tempInterest = 0.0;
			}
			else
			{
				//Adds the monthly interest together since it is compounded monthly
				tempInterest += m_totalInterest[i];
			}
		}

		cout << "^------------^------------------------------^------------------------^\n" << endl;
	}
}

//Calculates the account's balance and interest based on the user's account information
void InterestAccount::calculateInterest()
{
	//For each loop that goes month-by-month to ensure it is compounded and saved monthly
	for (int i = 0; i < m_numMonths; i++)
	{
		//Setting up the initial account balances
		if (i == 0)
		{
			//Calculating the interest and balance without the monthly addition. Uses the constructor variables to set it up properly.
			m_totalInterest[i] = m_initialInvestment * (m_interest / 12);
			m_accountTotal[i] = m_initialInvestment + m_totalInterest[i];

			//Calulating the initial account interest and account balance including the monthly additions.
			m_totalInterestPlusMonthly[i] = (m_initialInvestment + 50) * (m_interest / 12);
			m_accountTotalPlusMonthly[i] = m_initialInvestment + m_totalInterestPlusMonthly[i] + 50;
		}
		else
		{
			//Starting at the second month, interest and account balance is calculated using the previous month's data. This is for both data sets.
			m_totalInterest[i] = m_accountTotal[i - 1] * (m_interest / 12);
			m_accountTotal[i] = m_accountTotal[i - 1] + m_totalInterest[i];

			m_totalInterestPlusMonthly[i] = (m_accountTotalPlusMonthly[i - 1] + m_monthlyDeposit) * (m_interest / 12);
			m_accountTotalPlusMonthly[i] = m_accountTotalPlusMonthly[i - 1] + m_totalInterestPlusMonthly[i] + 50;
		}
	}
}


//Mutator and accessor methods for the main variables
void InterestAccount::setInitialInvestment(double t_newInitialInvestment)
{
	m_initialInvestment = t_newInitialInvestment;
}

double InterestAccount::getInitialInvestment()
{
	return m_initialInvestment;
}

void InterestAccount::setMonthlyDeposit(double t_newMonthlyDeposit)
{
	m_monthlyDeposit = t_newMonthlyDeposit;
}

double InterestAccount::getMonthlyDeposit()
{
	return m_monthlyDeposit;
}

void InterestAccount::setInterestRate(int t_newInterestRate)
{
	m_interest = t_newInterestRate;
}

int InterestAccount::getInterestRate()
{
	return int(m_interest*100);
}

void InterestAccount::setTotalYears(int t_newTimeFrame)
{
	m_numYears = t_newTimeFrame;
}

int InterestAccount::getTotalYears()
{
	return m_numYears;
}
