#include <iostream>
#include "Showing.h"
#include "Donor.h"
#include"Recipient.h"

Donor donor;
Recipient rp;
unordered_map<string, donorinfo> donors;
map<string, int> blood_tank = {};
void Showing::home1()
{

	cout << "###################################################\n";
	cout << "###################################################\n";
	cout << "#####                 WELCOME                 #####\n";
	cout << "###################################################\n";
	cout << "###################################################\n";
	cout << "\n\n\n";
	while (1) {
		cout << "1. Donor : \n" << "2. Recipient : \n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			home2();
			break;
		}
		else if (choice == 2) {
			rp.home3();
			break;
		}
		else {
			cout << "Invalid Input , please Try again\n";
			continue;
		}
	}
}
void Showing::home2()
{

	while (1) {
		cout << "Do You Have An Account?(y/n)\n";
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			donor.login(donors);
			break;
		}
		else if (choice == 'n' || choice == 'N') {
			donor.Register(donors);
			donor.login(donors);
			break;
		}
		else {
			cout << "Invalid Input , please Try again\n";
			continue;
		}
	}
}
void Showing::option()
{
	int choice;
	while (1) {
		cout << "\n";
		cout << "Enter The Number Of Your Operation : \n";
		cout << "1. Home Page\n";
		cout << "2. Display My Information\n";
		cout << "3. Request\n";
		cout << "4. Update\n";
		cout << "5. Delete\n";
		cout << "6. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			home1();
			break;
		case 2:
			donor.display_info();
			break;
		case 3:
			donor.request(blood_tank);
			break;
		case 4:
			donor.update(donors);
			break;
		case 5:
			donor.Delete_account(donors);
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Invalid Input , please Try again\n";
			continue;
		}
	}
}
