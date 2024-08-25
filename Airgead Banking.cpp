// Kandahar Brewer

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include "InterestAccount.h"

using namespace std;

int main()
{
	//Local variable initialization
	double m_userInvestment = 0.0;
	double m_userMonthlyInvestment = 0.0;
	int m_userInterestRate = 0;
	int m_accountLength = 0;
	string userContinue;
	bool continueProgram = true;

	//Main loop that runs the program, will exit when continueProgram is false
	while (continueProgram)
	{
		//Getting the user's information to properly construct the account object
		cout << "********************************************\n";
		cout << "**************** DATA INPUT ****************" << endl;
		cout << "Initial Investment Amount:  $" << flush;
		cin >> m_userInvestment;
		cout << "Monthly Deposit:            $" << flush;
		cin >> m_userMonthlyInvestment;
		cout << "Annual Interest:            %" << flush;
		cin >> m_userInterestRate;
		cout << "Number of Years:             " << flush;
		cin >> m_accountLength;
		cout << "Press any key to continue...\n\n" << flush;
		cin.clear();
		cin.get();


		//This is just for error handling in the event that an issue occurs after getting the user's data 
		try
		{
			//Ensures that the user has entered valid account data, will throw an error otherwise
			if (m_accountLength >= 0 && m_userInterestRate >= 0 && m_userInvestment >= 0.0 && m_userMonthlyInvestment >= 0.0)
			{
				//Creates a temperary object that can be released when needed. Provides simple data protection/security
				auto userAccount = make_shared<InterestAccount>(m_userInvestment, m_userMonthlyInvestment, m_userInterestRate, m_accountLength);

				//Updates the account's balances and displays those balances without and with the monthly additions
				userAccount->calculateInterest();
				userAccount->display(false);
				userAccount->display(true);

				//Allows the user to quit the program or enter new information
				cout << "\nWould you like to calculate a new value set?  ";
				getline(cin, userContinue);
				transform(userContinue.begin(), userContinue.end(), userContinue.begin(), ::tolower);

				//checks if the user wants to exit and quits if they do
				if (userContinue.find('n') != userContinue.npos)
				{
					cout << "Exiting Program..." << endl;
					break;
				}
			}
			else if (m_accountLength < 0 || m_userInterestRate < 0 || m_userInvestment < 0.0 || m_userMonthlyInvestment < 0.0) 
			{ 
				throw ("Invalid Number Given"); 
			}
			else 
			{ 
				//Should only be sent with a catastrophic error
				throw (false); 
			}
		}
		catch (string errorType)
		{
			//This error handling ensures that we aren't calculating invalid information
			cout << errorType;
			cout << "Please check your responses and try again!" << endl;
		}
		catch (...) 
		{ 
			//Error handling for any case that we aren't able to predict/cover
			cout << "This program has encountered an error, please contact support and submit a bug request." << endl; 
			break; 
		}
	}
}

