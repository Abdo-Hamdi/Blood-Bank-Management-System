#include "Donor.h"
#include"Showing.h"
#include <sstream>
Showing sh;
fstream donor_file, blood_file, temp, temp_blood;
string id;
#include <ctime>
void Donor::Register(unordered_map<string, donorinfo>& donors)
{
	donorinfo newdonor;
	while (1) {
		cout << "Enter Your National Id : ";

		cin >> id;
		cout << "\n";
		bool found = 0;
		string line;
		donor_file.open("Donor Data.txt", ios::in);
		while (getline(donor_file, line))//check id
		{
			stringstream ss(line);
			string existing_id;
			ss >> existing_id;
			if (existing_id == id)
			{
				found = 1;
				donor_file.close();
				break;
			}
		}
		donor_file.close();
		if (found) {
			cout << "ID already exists. Please enter a different ID.\n";
			continue;
		}
		else {
			char sla;
			cout << "Enter Your Name : ";
			cin.ignore();
			getline(cin, newdonor.name);
			cout << "\n";

			cout << "Enter Your Age : ";
			cin >> newdonor.age;
			cout << "\n";

			cout << "Enter Your Gender (M/F) : ";
			cin >> newdonor.gender;
			cout << "\n";

			cout << "Enter Your Mail : ";
			cin >> newdonor.mail;
			cout << "\n";

			cout << "Enter Your Password : ";
			cin.ignore();
			cin >> newdonor.password;
			cout << "\n";

			cout << "Enter Your Blood Type : ";
			cin >> newdonor.blood_type;
			cout << "\n";

			cout << "Enter Your Date Of Last Donation (DD/MM/YYYY): ";
			cin >> newdonor.date_of_last_donation.tm_mday>>sla>>
				newdonor.date_of_last_donation.tm_mon >> sla >> 
				newdonor.date_of_last_donation.tm_year;
			cout << "\n";

			donors[id] = newdonor;

			donor_file.open("Donor Data.txt", ios::app);
			donor_file << id << ' ' << newdonor.name << ' ' << newdonor.password << ' ' << newdonor.blood_type << ' ' << newdonor.gender << ' ' << newdonor.age << ' ' << newdonor.mail << ' ' << 
				newdonor.date_of_last_donation.tm_mday << sla <<
				newdonor.date_of_last_donation.tm_mon << sla <<
				newdonor.date_of_last_donation.tm_year << "\n";
			donor_file.close();
			cout << "_____________________________________DONE!!_____________________________________\n";
			cout << "\n\n";
			break;
		}
		donors[id] = newdonor;
	}
}

donorinfo existdonor;
void Donor::login(unordered_map<string, donorinfo>& donors)
{

	while (1) {
		cout << "Enter Your National Id : ";
		cin >> id;
		cout << "\n";
		bool found = 0;
		string line;
		donor_file.open("Donor Data.txt", ios::in);
		while (getline(donor_file, line))
		{
			stringstream ss(line);
			string existing_id;
			ss >> existing_id;
			if (existing_id == id)
			{
				found = 1;
				// read the password from the file and store it in existdonor.password
				// read the second field and discard it
				char dummy;
				ss >> existdonor.name;
				ss >> existdonor.password; // read the third field
				ss >> existdonor.blood_type;
				ss >> existdonor.gender;
				ss >> existdonor.age;
				ss >> existdonor.mail;
				ss >> existdonor.date_of_last_donation.tm_mday;
				ss >> dummy;
				ss >> existdonor.date_of_last_donation.tm_mon;
				ss >> dummy;
				ss >> existdonor.date_of_last_donation.tm_year;

				donor_file.close();
				break;
			}
		}
		donor_file.close();
		if (!found) {
			cout << "ID is not exists. Please enter a different ID.\n";
			continue;
		}
		else {
			string password;
			cout << "Enter Your Password : ";
			cin >> password;
			cout << "\n";
			if (existdonor.password == password) {
				found = 1;
				break;
			}
			else {
				cout << "password is wrong , try again.\n";
				continue;
			}
		}
	}
	donors[id] = existdonor;

	sh.option();
}

void Donor::update(unordered_map<string, donorinfo>& donors)
{
	int ch , d,m,y;
	char sla;
	string newname, newmail, newpass;

	do {
	cout << "Enter The Number of Option : \n";
	cout << "1. Name\n";
	cout << "2. Mail\n";
	cout << "3. Password\n";
	cout << "4. Date of The Last Donation\n";
	cin >> ch;

	switch (ch)
	{
	case 1:
		cout << "Enter Your New Name : ";
		cin >> newname;
		existdonor.name = newname;
		break;
	case 2:
		cout << "Enter Your New Mail : ";
		cin >> newmail;
		existdonor.mail = newmail;
		break;
	case 3:
		cout << "Enter Your New Password : ";
		cin >> newpass;
		existdonor.password = newpass;
		break;
	case 4:
		cout << "Enter Your New Date of the last Donation (DD/MM/YYYY): ";
		cin >> d>>sla>>m>>sla>>y;
		existdonor.date_of_last_donation.tm_mday = d;
		existdonor.date_of_last_donation.tm_mon = m ;
		existdonor.date_of_last_donation.tm_year = y;
		break;
	default:
		cout << "Invalid Input , please Try again\n";
		continue;
	}
		break;
	} while (1);
	donors[id] = existdonor;
	save();
	cout << "Updated Done !!!.\n";
}

bool Donor::check_time(const tm& last_date) {
	// Get the current date
	time_t now;
	time(&now);
	tm currentDate{};
	localtime_s(&currentDate, &now);

	// Calculate the difference in months
	int monthsDiff = (currentDate.tm_year - last_date.tm_year) * 12 +
		(currentDate.tm_mon - last_date.tm_mon);

	// Check if the difference is at least three months
	return monthsDiff >= 3;
}

void Donor::display_info() {

	cout << "YOUR INFORMATIN : \n";
	cout << "ID : " << id << endl;
	cout << "Name : " << existdonor.name << endl;
	cout << "Password : " << existdonor.password << endl;
	cout << "Blood Type : " << existdonor.blood_type << endl;
	cout << "Gender : " << existdonor.gender << endl;
	cout << "Age : " << existdonor.age << endl;
	cout << "Mail : " << existdonor.mail << endl;
	cout << "Date the Last of Donation : " << existdonor.date_of_last_donation.tm_mday << '/' <<
		existdonor.date_of_last_donation.tm_mon << '/' <<
		existdonor.date_of_last_donation.tm_year << endl;
}
bool Donor::validate()
{
	char choice1, choice2;
	cout << "Do You Suffer From Any Disease \n(blood pressure ,thyroid , diabetes, cancer, heart disorders, hepatitis (Y/N): ";
	cin >> choice1;
	cout << endl;
	cout << "Do You Suffer From any other problem including other diseases or medicine (Y/N): ";
	cin >> choice2;
	cout << endl;

	// Create a tm structure with the user input
	tm lastDonationDate{};
	lastDonationDate.tm_mday = existdonor.date_of_last_donation.tm_mday;
	lastDonationDate.tm_mon = existdonor.date_of_last_donation.tm_mon - 1;  // tm_mon is zero-based
	lastDonationDate.tm_year = existdonor.date_of_last_donation.tm_year - 1900;  // tm_year is years since 1900
	bool check = check_time(lastDonationDate);

	if (existdonor.age <= 60 && existdonor.age >= 17 &&
		(choice1 == 'n' ||choice1 == 'N') &&
		( choice2 == 'N' || choice2 == 'n') && check)
	{
		return true;
	}
	else {
		return false;
	}
}

//A + , A - , B + , B - , AB + , AB - , O + , O -
void Donor::check_blood_type(map<string, int>& blood_tank, string blood_type, int blood) {

	if (blood_tank.find(blood_type) != blood_tank.end()) {
		blood_tank[blood_type] += blood;
	}
	else {
		blood_tank[blood_type] = blood;
	}

	// Open the file for reading existing blood data
	blood_file.open("Blood Quantity.txt", ios::in);
	temp_blood.open("tempy.txt", ios::out | ios::app);  // Open tempy.txt in output and append mode

	string line;
	while (getline(blood_file, line)) {
		stringstream ss(line);
		string existing_blood_type;
		int existing_blood_quantity;
		ss >> existing_blood_type;
		ss >> existing_blood_quantity;

		if (existing_blood_type == blood_type) {
			// Update the existing blood quantity
			existing_blood_quantity += blood;

			// Get the current date
			time_t now = time(nullptr);
			tm currentDate;
			localtime_s(&currentDate, &now);

			// Set the expiry date to 30 days from the current date
			tm expiryDate = currentDate;
			expiryDate.tm_mday += 30;
			mktime(&expiryDate);

			// Append Received and Expiry dates to the line
			char receivedDate[30];
			strftime(receivedDate, 30, "%c", &currentDate);
			char expiryDateStr[30];
			strftime(expiryDateStr, 30, "%c", &expiryDate);
			temp_blood << existing_blood_type << ' ' << existing_blood_quantity << ' ';
			temp_blood << "Received: " << receivedDate << ' ';
			temp_blood << "Expiry: " << expiryDateStr << '\n';
		}
		else {
			temp_blood << line << '\n';
		}
	}

	blood_file.close();
	temp_blood.close();

	remove("Blood Quantity.txt");
	rename("tempy.txt", "Blood Quantity.txt");
}

void Donor::request (map<string, int>& blood_tank)
{
	time_t now;
	time(&now);
	tm currentDate{};
	localtime_s(&currentDate, &now);
	if (validate()) {
		cout << "OKAY, sir\n";
		cout << "Your blood type is: " << existdonor.blood_type << endl;
		cout << "That is good.\n";
		cout << "What is the Quantity (in blood bags)?\n";
		int blood;
		cin >> blood;
		check_blood_type(blood_tank, existdonor.blood_type, blood);
		cout << "Thank you for your cooperation `_'\n";

		existdonor.date_of_last_donation.tm_mday = currentDate.tm_mday;
		existdonor.date_of_last_donation.tm_mon = currentDate.tm_mon + 1;
		existdonor.date_of_last_donation.tm_year = currentDate.tm_year + 1900;

		// Open the file for writing donation data
		ofstream blood_file("Blood Quantity.txt", ios::app);
		if (blood_file.is_open()) {
			// Get the current date
			char receivedDate[30];
			strftime(receivedDate, 30, "%c", &currentDate);

			// Set the expiry date to 30 days from the current date
			tm expiryDate = currentDate;
			expiryDate.tm_mday += 30;
			mktime(&expiryDate);
			char expiryDateStr[30];
			strftime(expiryDateStr, 30, "%c", &expiryDate);

			// Write the donation data to the file
			blood_file << existdonor.blood_type << ' ' << blood << ' ';
			blood_file << "Received: " << receivedDate << ' ';
			blood_file << "Expiry: " << expiryDateStr << '\n';

			blood_file.close();
		}
		else {
			cout << "Unable to open the file for writing donation data.\n";
		}
		save();
	}
	else {
		cout << "I am sorry, but there is a problem. You can't donate now.\n";
		cout << "\n";
		cout << "The Conditions for Donation: \n";
		cout << "- The age should be between 17 and 60.\n";
		cout << "- The last date of donation should be at least 3 months ago.\n";
		cout << "- The donor must not suffer from any diseases or take any medication.\n";
	}
	sh.option();
}


void Donor::Delete_account(unordered_map<string, donorinfo>& donors)
{
	char sure;
	cout << "Are You Sure?(y/n)\n";
	cin >> sure;
	if (sure == 'y' || sure == 'Y') {
		for (auto it = donors.begin(); it != donors.end(); ++it) {
			if (it->first == id) {
				donors.erase(it);
				temp.open("temp.txt", ios::app);
				donor_file.open("Donor Data.txt", ios::in);
				string line;
				while (getline(donor_file, line))//check id
				{
					stringstream ss(line);
					string existing_id;
					ss >> existing_id;
					if (existing_id == id) {
						continue;
					}
					else {
						temp << line << "\n";
					}
				}
				donor_file.close();
				temp.close();
				remove("Donor Data.txt");
				rename("temp.txt", "Donor Data.txt");
				cout << "Donor account deleted\n" << endl;
				break;
			}
			else {
				cout << "Donor account is not found " << endl;
			}
		}
	
	sh.home1();
	}
	else {
		sh.option();
	}
}

Donor::~Donor()
{
	cout << "GoodBye!\n";
}

void Donor::save() {
	temp.open("temp.txt", ios::app);
	donor_file.open("Donor Data.txt", ios::in);
	string line;
	while (getline(donor_file, line))//check id
	{
		stringstream ss(line);
		string existing_id;
		ss >> existing_id;
		if (existing_id == id) {
			temp << id << " " << existdonor.name << ' ' << existdonor.password << ' ' << existdonor.blood_type << ' ' << existdonor.gender << ' ' << existdonor.age << ' ' << existdonor.mail << ' ' <<
				existdonor.date_of_last_donation.tm_mday << '/' << existdonor.date_of_last_donation.tm_mon << '/' << existdonor.date_of_last_donation.tm_year << endl;
		}
		else {
			temp << line << "\n";
		}
	}
	donor_file.close();
	temp.close();
	remove("Donor Data.txt");
	rename("temp.txt", "Donor Data.txt");
}
