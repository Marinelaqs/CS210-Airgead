/*Kandahar Brewer
Duplication protection to make sure the header isn't instantiated multiple times*/
#ifndef AIRGEADBANKING_AIRGEADBANKING_INTERESTACCOUNT_H_
#define AIRGEADBANKING_AIRGEADBANKING_INTERESTACCOUNT_H_

#include <vector>;
#include <string>

class InterestAccount
{
private:
	//Variables local and accessable only to the InterestAccount objects
	std::vector<double> m_accountTotal;
	std::vector<double> m_totalInterest;
	std::vector<double> m_accountTotalPlusMonthly;
	std::vector<double> m_totalInterestPlusMonthly;
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_interest;
	int m_numYears;
	int m_numMonths;

public:
	//Overloaded constructor, just to ensure the object has it's variables properly assigned to avoid errors in the methods
	InterestAccount(double t_initial = 0.0, double t_monthly = 0.0, int t_interest = 0, int t_years = 0);

	//These two methods display the account information in a table and recalculates the interest and account balance
	void display(bool t_monthlyPayment);
	void calculateInterest();

	//Mutator and accessor methods for the main variables in the object
	void setInitialInvestment(double t_newInitialInvestment);
	double getInitialInvestment();
	void setMonthlyDeposit(double t_newMonthlyDeposit);
	double getMonthlyDeposit();
	void setInterestRate(int t_newInterestRate);
	int getInterestRate();
	void setTotalYears(int t_newTimeFrame);
	int getTotalYears();
};

#endif //AIRGEADBANKING_AIRGEADBANKING_INTERESTACCOUNT_H_

