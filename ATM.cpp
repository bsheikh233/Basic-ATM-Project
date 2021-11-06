#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable : 4996)
using namespace std;
void openMenu()
{
	int mainCheck = 0;
	cout << "Hi! Welcome to Mr. Bilal's ATM Machine" << endl;
	cout << "Please press 1 to go to the main menu" << endl;
	cin >> mainCheck;
	while (!cin || mainCheck != 1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Hi! Welcome to Mr. Bilal's ATM Machine" << endl;
		cout << "Error!! Please press only 1 to go to the main menu" << endl;
		cin >> mainCheck;
	}
	system("cls");
}
char mainMenu()
{
	char mainOpt = '0';
	cout << "Please select an option from the main menu below : \n1) Please press C to Create New Account\n2) Please press L to Login\n3) Please press A to get access to Admin Console\n4) Please press Q to quit" << endl;
	cin >> mainOpt;
	while (!cin || ((mainOpt != 'C') && (mainOpt != 'c') && (mainOpt != 'L') && (mainOpt != 'l') && (mainOpt != 'A') && (mainOpt != 'a') && (mainOpt != 'Q') && (mainOpt != 'q')))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Error!! Please select an option from the main menu below : \n1) Please press C to create new account\n2) Please press L to Login\n3) Please press A to get access to Admin Console\n4) Please press Q to quit" << endl;
		cin >> mainOpt;
	}
	system("cls");
	return mainOpt;
}
int createID()
{
	int createID = 0;
	cout << "Please enter your username (1-5) to create account or press '6' to go back to main menu" << endl;
	cin >> createID;
	while (!cin || !((createID >= 1) && (createID <= 6)))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Error!! Please enter only number from the given range i.e. 1-5 OR press '6' to go back to the main menu" << endl;
		cin >> createID;
	}
	system("cls");
	return createID;
}
void createPassword(char password[])
{
	char tempCh;
	cout << "Please create password" << endl;
	for (int i = 0;;)
	{
		tempCh = _getch();
		if ((int)tempCh != 13 && (int)tempCh != 8 && i < 19)
		{
			password[i] = tempCh;
			cout << "*";
			i++;
		}
		if ((int)tempCh == 13)
		{
			if (i == 0)
			{
				system("cls");
				cout << "You cannot leave the password section empty" << endl;
			}
			else
			{
				password[i] = '\0';
				break;
			}
		}
		if (tempCh == '\b' && i >= 1)
		{
			cout << "\b \b";
			i--;
		}
	}
	system("cls");
}
int loginID()
{
	system("cls");
	int loginID = 0;
	cout << "Please enter your username (1-5) or press '6' to go back to main menu" << endl;
	cin >> loginID;
	while (!cin || !((loginID >= 1) && (loginID <= 6)))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Error!! Please enter only number from the given range i.e. 1-5 OR press '6' to go back to the main menu" << endl;
		cin >> loginID;
	}
	system("cls");
	return loginID;
}
void loginPassword(char password[])
{
	char tempCh;
	cout << "Please enter correct password" << endl;
	for (int i = 0;;)
	{
		tempCh = _getch();
		if ((int)tempCh != 13 && (int)tempCh != 8 && i < 19)
		{
			password[i] = tempCh;
			cout << "*";
			i++;
		}
		if ((int)tempCh == 13)
		{
			if (i == 0)
			{
				system("cls");
				cout << "You cannot leave the password section empty" << endl;
			}
			else
			{
				password[i] = '\0';
				break;
			}
		}
		if (tempCh == '\b' && i >= 1)
		{
			cout << "\b \b";
			i--;
		}
	}
	system("cls");
}
int passConfirmation(char userPass[], char accountPass[])
{
	int passComparison = 1; //passComparison is used as a flag to show whether enter password is correct(1) or not(0)
	for (int i = 0; i < 20; i++)
	{
		if (userPass[i] != accountPass[i])
		{
			passComparison = 0;
			break;
		}
	}
	return passComparison;
}
char optMenu()
{
	system("cls");
	char optCheck = '0';
	cout << "Please select an option from the operations menu below : \n1) Please press W to withdraw money from the account\n2) Please press D to deposit money into the account\n3) Please press R to request balance\n4) Please press T to see the transaction history\n5) Please press E to see the extreme (highest and lowest) value of transactions \n6) Please press M to go back to main menu" << endl;
	cin >> optCheck;
	while (!cin || ((optCheck != 'W') && (optCheck != 'w') && (optCheck != 'D') && (optCheck != 'd') && (optCheck != 'R') && (optCheck != 'r') && (optCheck != 'T') && (optCheck != 't') && (optCheck != 'E') && (optCheck != 'e') && (optCheck != 'M') && (optCheck != 'm')))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Error!! Please select an option from the operations menu below : \n1) Please press W to withdraw money from the account\n2) Please press D to deposit money into the account\n3) Please press R to request balance\n4) Please press T to see the transaction history\n5) Please press E to see the extreme (highest and lowest) value of transactions \n6) Please press M to go back to main menu" << endl;
		cin >> optCheck;
	}
	system("cls");
	return optCheck;
}
int withDraw(float balance, int& max, int& min, float history[], int type[], time_t tt[])
{
	system("cls");
	float withDrawAmount = 0.0;
	cout << "Please enter the amount you want to withdraw from your account" << endl << "\n(please enter the amount in positive whole numbers that could be dispensible in the available currency notes)\n\nOR press 0 to go back to the operation menu" << endl;
	cin >> withDrawAmount;
	while (!cin || withDrawAmount < 0 || (withDrawAmount - (int)withDrawAmount > 0) || ((int)withDrawAmount % 10) || withDrawAmount > balance)
	{
		system("cls");
		cin.clear();
		cin.ignore(1000, '\n');
		if (withDrawAmount > balance)
		{
			cout << "your account does not have enough amount for withdrawl, please enter accordingly\n" << endl;
			cin >> withDrawAmount;
		}
		else
		{
			cout << "Error !!Please enter the amount you want to withdraw from your account \n\n (please enter the amount that could be dispensible in the available currency notes)\n OR press 0 to go back to the operation menu" << endl;
			cin >> withDrawAmount;
		}
	}
	if (withDrawAmount > max)
	{
		max = (int)withDrawAmount;
	}
	if (min == 0 || withDrawAmount < min)
	{
		min = (int)withDrawAmount;
	}
	system("cls");
	history[2] = history[1];
	history[1] = history[0];
	history[0] = withDrawAmount;
	type[2] = type[1];
	type[1] = type[0];
	type[0] = 2;
	tt[2] = tt[1];
	tt[1] = tt[0];
	tt[0] = time(NULL);
	return (int)withDrawAmount;
}
void denomination(int amount)
{
	system("cls");
	int temp = 0, count5000 = 0, count1000 = 0, count500 = 0, count100 = 0, count50 = 0, count20 = 0, count10 = 0;
	temp = amount;
	count5000 = temp / 5000;
	temp = temp % 5000;
	count1000 = temp / 1000;
	temp = temp % 1000;
	count500 = temp / 500;
	temp = temp % 500;
	count100 = temp / 100;
	temp = temp % 100;
	count50 = temp / 50;
	temp = temp % 50;
	count20 = temp / 20;
	temp = temp % 20;
	count10 = temp / 10;
	cout << "Cash withdrawl of Rs. " << amount << " is requested." << endl;
	if (count5000 > 0)
	{
		cout << "Denomination 5000s---- " << count5000 << endl;
	}
	if (count1000 > 0)
	{
		cout << "Denomination 1000s---- " << count1000 << endl;
	}
	if (count500 > 0)
	{
		cout << "Denomination 500s---- " << count500 << endl;
	}
	if (count100 > 0)
	{
		cout << "Denomination 100s---- " << count100 << endl;
	}
	if (count50 > 0)
	{
		cout << "Denomination 50s---- " << count50 << endl;
	}
	if (count20 > 0)
	{
		cout << "Denomination 20s---- " << count20 << endl;
	}
	if (count10 > 0)
	{
		cout << "Denomination 10s---- " << count10 << endl;
	}
	system("pause");
	system("cls");
}
int deposit(float& balance, float& max, float& min, float history[], int type[], time_t tt[])
{
	system("cls");
	float depositedAmount = 0.0;
	cout << "Please enter the amount of money (positive) you want to deposit into your bank account\n\nOR press 0 to go back to the operations menu" << endl;
	cin >> depositedAmount;
	while (!cin || depositedAmount < 0)
	{
		system("cls");
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error!! Please enter the amount of money (positive) you want to deposit into your bank account \nOR press 0 to go back to the operations menu" << endl;
		cin >> depositedAmount;
	}
	history[2] = history[1];
	history[1] = history[0];
	history[0] = depositedAmount;
	type[2] = type[1];
	type[1] = type[0];
	type[0] = 1;
	tt[2] = tt[1];
	tt[1] = tt[0];
	tt[0] = time(NULL);
	balance += depositedAmount;
	if (depositedAmount > max)
	{
		max = depositedAmount;
	}
	if (min == 0 || depositedAmount < min)
	{
		min = depositedAmount;
	}
	cout << "The amount has successfully been transmitted to your account" << endl;
	system("pause");
	system("cls");
	return (int)depositedAmount;
}
void extreme(float maxD, float minD, int maxW, int minW)
{
	system("cls");
	float max, min;
	if (maxD > (float)maxW)
	{
		max = maxD;
	}
	else
	{
		max = (float)maxW;
	}
	if (minD < (float)minW)
	{
		min = minD;
	}
	else
	{
		min = (float)minW;
	}
	if (max == maxD)
	{
		cout << "The highest transaction is a deposit of Rs." << max << endl;
	}
	else
	{
		cout << "The highest transaction is a withdrawl of Rs." << max << endl;
	}
	if (min == minD)
	{
		cout << "The lowest transaction is a deposit of Rs." << min << endl;
	}
	else
	{
		cout << "The lowest transaction is a withdrawl of Rs." << min << endl;
	}
	system("pause");
	system("cls");
}
int adminConsoleMenu()
{
	int mainOpt = 0;
	cout << "Please select an option from the following : \n1) Please press 1 to show REPORT on Total number of transactions (Withdraws and Deposits) from ALL accounts\n2) Please press 2 to show REPORT on ALL Account Balances in the Ascending Order\n3) Please press 3 to Go back to Main Menu" << endl;
	cin >> mainOpt;
	while (!cin || ((mainOpt != 1) && (mainOpt != 2) && (mainOpt != 3)))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		cout << "Error!! Please select an option from the  following : \n1) Please press 1 to show REPORT on Total number of transactions (Withdraws and Deposits) from ALL accounts\n2) Please press 2 to show REPORT on ALL Account Balances in the Ascending Order\n3) Please press 3 to Go back to Main Menu" << endl;
		cin >> mainOpt;
	}
	system("cls");
	return mainOpt;
}
void sorting(const float ar[], int size, float sortedAr[])
{
	for (int i = 0; i < size; i++)
	{
		sortedAr[i] = ar[i];
	}
	float min = 0, temp = 0;
	int   pos = 0;
	for (int i = 0; i < (size - 1); i++)
	{
		pos = i;
		min = sortedAr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (min > sortedAr[j])
			{
				min = sortedAr[j];
				pos = j;
			}
		}
		temp = sortedAr[i];
		sortedAr[i] = min;
		sortedAr[pos] = temp;
	}
}
int main()
{
	time_t t1[3] = { 0 }, t2[3] = { 0 }, t3[3] = { 0 }, t4[3] = { 0 }, t5[3] = { 0 }, today = 0;
	int account[5] = { 0 }, maxWithdrawl[5] = { 0 }, minWithdrawl[5] = { 0 }, breakLoop = 0, transactionType1[3] = { 0 }, transactionType2[3] = { 0 }, transactionType3[3] = { 0 }, transactionType4[3] = { 0 }, transactionType5[3] = { 0 }, totalTransactions[5] = { 0 };
	float accountBalance[5] = { 0 }, maxDeposit[5] = { 0 }, minDeposit[5] = { 0 }, transactionHistory1[3] = { 0 }, transactionHistory2[3] = { 0 }, transactionHistory3[3] = { 0 }, transactionHistory4[3] = { 0 }, transactionHistory5[3] = { 0 }, sortedBalance[5] = { 0 };
	char password1[20] = { 0 }, password2[20] = { 0 }, password3[20] = { 0 }, password4[20] = { 0 }, password5[20] = { 0 };
	while (1)//loop to start the whole process again if user quits!
	{
		openMenu();
		while (1) // loop for main menu
		{
			breakLoop = 0;
			char mainOpt = mainMenu();
			if ((mainOpt == 'C') || (mainOpt == 'c'))
			{
				while (1) //loop for creating account 
				{
					int userID = createID();
					if (userID == 6) // this if takes back to main menu if user enters 6
					{
						break;
					}
					if (account[userID - 1] == 0)
					{
						if (userID == 1)
						{
							createPassword(password1);
							account[userID - 1] = 1;
							cout << "Your account has successfully been created" << endl;
							system("pause");
						}
						else if (userID == 2)
						{
							createPassword(password2);
							account[userID - 1] = 1;
							cout << "Your account has successfully been created" << endl;
							system("pause");
						}
						else if (userID == 3)
						{
							createPassword(password3);
							account[userID - 1] = 1;
							cout << "Your account has successfully been created" << endl;
							system("pause");
						}
						else if (userID == 4)
						{
							createPassword(password4);
							account[userID - 1] = 1;
							cout << "Your account has successfully been created" << endl;
							system("pause");
						}
						else if (userID == 5)
						{
							createPassword(password5);
							account[userID - 1] = 1;
							cout << "Your account has successfully been created" << endl;
							system("pause");
						}
					}
					else if (account[userID - 1] == 1)
					{
						cout << "Account already exists" << endl;
						system("pause");
					}
					system("cls");
				} // ending bracket for loop of creating account
			}// ending bracket of check if user wants to create account
			else if ((mainOpt == 'L') || (mainOpt == 'l'))
			{
				while (1) //loop for login
				{
					if (breakLoop == 1) //this if structure is used to break the loop till we reached the main menu as user has requested
					{
						break;
					}
					int loginIDCheck = loginID(); //loginID is a function whose output is an accout number(1-5) whereas loginIDCheck is a variable which stores that output
					if (loginIDCheck == 6)
					{
						break;
					}
					if (account[loginIDCheck - 1] == 1) //works only if account exists
					{
						char passwordCheck[20] = { 0 };
						while (1) //loop for validating password and logging in 
						{
							if (breakLoop == 1) //this if structure is used to break the loop till we reached the main menu as user has requested
							{
								break;
							}
							loginPassword(passwordCheck); // passwordCheck is an string which stores the password, which, further, is used for comparison
							if (loginIDCheck == 1)
							{
								if (passConfirmation(passwordCheck, password1) == 0)
								{
									system("cls");
									cout << "The password is incorrect. ";
								}
								else
								{
									while (1) //loop for operations menu of user 1
									{
										char optCheck = optMenu(); //optCheck is a variable which stores a character, which then can be compared to select an operation from operations menu
										if (optCheck == 'W' || optCheck == 'w')
										{
											int withDrawAmount = withDraw(accountBalance[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1], transactionHistory1, transactionType1, t1);
											if (withDrawAmount != 0)
											{
												denomination(withDrawAmount);
												accountBalance[loginIDCheck - 1] -= withDrawAmount;
												totalTransactions[loginIDCheck - 1]++;
											}
										}// ending bracket for withdraw option
										else if (optCheck == 'D' || optCheck == 'd')
										{
											if (deposit(accountBalance[loginIDCheck - 1], maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], transactionHistory1, transactionType1, t1))
											{
												totalTransactions[loginIDCheck - 1]++;
											}
										}
										else if (optCheck == 'R' || optCheck == 'r')
										{
											system("cls");
											cout << "Total amount in your account is Rs. " << accountBalance[loginIDCheck - 1] << endl;
											system("pause");
										}
										else if (optCheck == 'E' || optCheck == 'e')
										{
											extreme(maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1]);
										}
										else if (optCheck == 'M' || optCheck == 'm')
										{
											breakLoop = 1;
											break;
										}
										else if (optCheck == 'T' || optCheck == 't')
										{
											system("cls");
											cout << "Account ID : " << loginIDCheck << endl;
											cout << "current Balance Amount : Rs. " << accountBalance[loginIDCheck - 1] << endl;
											cout << endl;
											cout << "#         Date/Time                        Activity Type                   Transaction Amount" << endl;
											for (int i = 0; i < 3; i++)
											{
												struct tm* local = localtime(&t1[i]);
												if (transactionType1[i] == 1)
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               deposit                          Rs. " << transactionHistory1[i] << endl;
												}
												else
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               withdrawl                        Rs. " << (transactionHistory1[i] * (-1)) << endl;
												}
											}
											system("pause");
											system("cls");
										}
									} //ending bracket of loop for operations menu of user 1
								}
							} //login menu for user 1
							else if (loginIDCheck == 2)
							{
								if (passConfirmation(passwordCheck, password2) == 0)
								{
									system("cls");
									cout << "The password is incorrect. ";
								}
								else
								{
									while (1) //loop for operations menu of user 2
									{
										char optCheck = optMenu(); //optCheck is a variable which stores a character, which then can be compared to select an operation from operations menu
										if (optCheck == 'W' || optCheck == 'w')
										{
											int withDrawAmount = withDraw(accountBalance[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1], transactionHistory2, transactionType2, t2);
											if (withDrawAmount != 0)
											{
												denomination(withDrawAmount);
												accountBalance[loginIDCheck - 1] -= withDrawAmount;
												totalTransactions[loginIDCheck - 1]++;
											}
										}// ending bracket for withdraw option
										else if (optCheck == 'D' || optCheck == 'd')
										{
											if (deposit(accountBalance[loginIDCheck - 1], maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], transactionHistory2, transactionType2, t2))
											{
												totalTransactions[loginIDCheck - 1]++;
											}
										}
										else if (optCheck == 'R' || optCheck == 'r')
										{
											system("cls");
											cout << "Total amount in your account is Rs. " << accountBalance[loginIDCheck - 1] << endl;
											system("pause");
										}
										else if (optCheck == 'E' || optCheck == 'e')
										{
											extreme(maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1]);
										}
										else if (optCheck == 'M' || optCheck == 'm')
										{
											breakLoop = 1;
											break;
										}
										else if (optCheck == 'T' || optCheck == 't')
										{
											system("cls");
											cout << "Account ID : " << loginIDCheck << endl;
											cout << "current Balance Amount : Rs. " << accountBalance[loginIDCheck - 1] << endl;
											cout << endl;
											cout << "#         Date/Time                        Activity Type                   Transaction Amount" << endl;
											for (int i = 0; i < 3; i++)
											{
												struct tm* local = localtime(&t2[i]);
												if (transactionType2[i] == 1)
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               deposit                          Rs. " << transactionHistory2[i] << endl;
												}
												else
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               withdrawl                        Rs. " << (transactionHistory2[i] * (-1)) << endl;
												}
											}
											system("pause");
											system("cls");
										}
									} //ending bracket of loop for operations menu of user 2
								}
							} //login menu for user 2
							else if (loginIDCheck == 3)
							{
								if (passConfirmation(passwordCheck, password3) == 0)
								{
									system("cls");
									cout << "The password is incorrect. ";
								}
								else
								{
									while (1) //loop for operations menu of user 3
									{
										char optCheck = optMenu(); //optCheck is a variable which stores a character, which then can be compared to select an operation from operations menu
										if (optCheck == 'W' || optCheck == 'w')
										{
											int withDrawAmount = withDraw(accountBalance[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1], transactionHistory3, transactionType3, t3);
											if (withDrawAmount != 0)
											{
												denomination(withDrawAmount);
												accountBalance[loginIDCheck - 1] -= withDrawAmount;
												totalTransactions[loginIDCheck - 1]++;
											}
										}// ending bracket for withdraw option
										else if (optCheck == 'D' || optCheck == 'd')
										{
											if (deposit(accountBalance[loginIDCheck - 1], maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], transactionHistory3, transactionType3, t3))
											{
												totalTransactions[loginIDCheck - 1]++;
											}
										}
										else if (optCheck == 'R' || optCheck == 'r')
										{
											system("cls");
											cout << "Total amount in your account is Rs. " << accountBalance[loginIDCheck - 1] << endl;
											system("pause");
										}
										else if (optCheck == 'E' || optCheck == 'e')
										{
											extreme(maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1]);
										}
										else if (optCheck == 'M' || optCheck == 'm')
										{
											breakLoop = 1;
											break;
										}
										else if (optCheck == 'T' || optCheck == 't')
										{
											system("cls");
											cout << "Account ID : " << loginIDCheck << endl;
											cout << "current Balance Amount : Rs. " << accountBalance[loginIDCheck - 1] << endl;
											cout << endl;
											cout << "#         Date/Time                        Activity Type                   Transaction Amount" << endl;
											for (int i = 0; i < 3; i++)
											{
												struct tm* local = localtime(&t3[i]);
												if (transactionType3[i] == 1)
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               deposit                          Rs. " << transactionHistory3[i] << endl;
												}
												else
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               withdrawl                        Rs. " << (transactionHistory3[i] * (-1)) << endl;
												}
											}
											system("pause");
											system("cls");
										}
									} //ending bracket of loop for operations menu of user 3
								}
							} //login menu for user 3
							else if (loginIDCheck == 4)
							{
								if (passConfirmation(passwordCheck, password4) == 0)
								{
									system("cls");
									cout << "The password is incorrect. ";
								}
								else
								{
									while (1) //loop for operations menu of user 4
									{
										char optCheck = optMenu(); //optCheck is a variable which stores a character, which then can be compared to select an operation from operations menu
										if (optCheck == 'W' || optCheck == 'w')
										{
											int withDrawAmount = withDraw(accountBalance[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1], transactionHistory4, transactionType4, t4);
											if (withDrawAmount != 0)
											{
												denomination(withDrawAmount);
												accountBalance[loginIDCheck - 1] -= withDrawAmount;
												totalTransactions[loginIDCheck - 1]++;
											}
										}// ending bracket for withdraw option
										else if (optCheck == 'D' || optCheck == 'd')
										{
											if (deposit(accountBalance[loginIDCheck - 1], maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], transactionHistory4, transactionType4, t4))
											{
												totalTransactions[loginIDCheck - 1]++;
											}
										}
										else if (optCheck == 'R' || optCheck == 'r')
										{
											system("cls");
											cout << "Total amount in your account is Rs. " << accountBalance[loginIDCheck - 1] << endl;
											system("pause");
										}
										else if (optCheck == 'E' || optCheck == 'e')
										{
											extreme(maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1]);
										}
										else if (optCheck == 'M' || optCheck == 'm')
										{
											breakLoop = 1;
											break;
										}
										else if (optCheck == 'T' || optCheck == 't')
										{
											system("cls");
											cout << "Account ID : " << loginIDCheck << endl;
											cout << "current Balance Amount : Rs. " << accountBalance[loginIDCheck - 1] << endl;
											cout << endl;
											cout << "#         Date/Time                        Activity Type                   Transaction Amount" << endl;
											for (int i = 0; i < 3; i++)
											{
												struct tm* local = localtime(&t4[i]);
												if (transactionType4[i] == 1)
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               deposit                          Rs. " << transactionHistory4[i] << endl;
												}
												else
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               withdrawl                        Rs. " << (transactionHistory4[i] * (-1)) << endl;
												}
											}
											system("pause");
											system("cls");
										}
									} //ending bracket of loop for operations menu of user 4
								}
							} //login menu for user 4
							else if (loginIDCheck == 5)
							{
								if (passConfirmation(passwordCheck, password5) == 0)
								{
									system("cls");
									cout << "The password is incorrect. ";
								}
								else
								{
									while (1) //loop for operations menu of user 5
									{
										char optCheck = optMenu(); //optCheck is a variable which stores a character, which then can be compared to select an operation from operations menu
										if (optCheck == 'W' || optCheck == 'w')
										{
											int withDrawAmount = withDraw(accountBalance[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1], transactionHistory5, transactionType5, t5);
											if (withDrawAmount != 0)
											{
												denomination(withDrawAmount);
												accountBalance[loginIDCheck - 1] -= withDrawAmount;
												totalTransactions[loginIDCheck - 1]++;
											}
										}// ending bracket for withdraw option
										else if (optCheck == 'D' || optCheck == 'd')
										{
											if (deposit(accountBalance[loginIDCheck - 1], maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], transactionHistory5, transactionType5, t5))
											{
												totalTransactions[loginIDCheck - 1]++;
											}
										}
										else if (optCheck == 'R' || optCheck == 'r')
										{
											system("cls");
											cout << "Total amount in your account is Rs. " << accountBalance[loginIDCheck - 1] << endl;
											system("pause");
										}
										else if (optCheck == 'E' || optCheck == 'e')
										{
											extreme(maxDeposit[loginIDCheck - 1], minDeposit[loginIDCheck - 1], maxWithdrawl[loginIDCheck - 1], minWithdrawl[loginIDCheck - 1]);
										}
										else if (optCheck == 'M' || optCheck == 'm')
										{
											breakLoop = 1;
											break;
										}
										else if (optCheck == 'T' || optCheck == 't')
										{
											system("cls");
											cout << "Account ID : " << loginIDCheck << endl;
											cout << "current Balance Amount : Rs. " << accountBalance[loginIDCheck - 1] << endl;
											cout << endl;
											cout << "#         Date/Time                        Activity Type                   Transaction Amount" << endl;
											for (int i = 0; i < 3; i++)
											{
												struct tm* local = localtime(&t5[i]);
												if (transactionType5[i] == 1)
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               deposit                          Rs. " << transactionHistory5[i] << endl;
												}
												else
												{
													cout << i + 1 << ")        " << local->tm_mday << ":" << local->tm_mon + 1 << ":" << local->tm_year + 1900 << "|" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << "               withdrawl                        Rs. " << (transactionHistory5[i] * (-1)) << endl;
												}
											}
											system("pause");
											system("cls");
										}
									} //ending bracket of loop for operations menu of user 5
								}
							} //login menu for user 5
						} //ending bracket of loop for validating password and logging in
					}
					else
					{
						cout << "Account does not exist" << endl;
						system("pause");
					}

				} //ending bracket foor loop of login
			} //ending bracket for checking if user wants to login
			else if ((mainOpt == 'Q') || (mainOpt == 'q'))
			{
				system("cls");
				cout << " Thanks for stopping by, Bye!" << endl;
				system("pause");
				system("cls");
				break;
			}
			else if ((mainOpt == 'A') || (mainOpt == 'a'))
			{
				while (1)
				{
					system("cls");
					int adminOpt = adminConsoleMenu();
					if (adminOpt == 1)
					{
						system("cls");
						today = time(NULL);
						struct tm* loc = localtime(&today);
						cout << "Account ID                    Total Number of Transactions" << endl;
						for (int i = 0; i < 5; i++)
						{
							cout << i + 1 << "                    " << totalTransactions[i] << endl;
						}
						cout << endl;
						cout << "Date : " << loc->tm_mday << ":" << loc->tm_mon + 1 << ":" << loc->tm_year + 1900 << endl;
						system("pause");
						system("cls");
					}
					else if (adminOpt == 2)
					{
						system("cls");
						sorting(accountBalance, 5, sortedBalance);
						cout << "Account ID                    Balance" << endl;
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 5; j++)
							{
								if (sortedBalance[i] == accountBalance[j])
								{
									cout << j + 1 << "                             " << sortedBalance[i] << endl;
									break;
								}
							}
						}
						system("pause");
						system("cls");
					}
					else if (adminOpt == 3)
					{
						break;
					}
				}
			}
		} // endling bracket for loop of main menu
	}// endling bracket for loop of repeating the whole process
	system("pause");
	return 0;
}