#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
#include <map>
#include <unordered_map>
#include<ctime>
using namespace std;
struct donorinfo {
	int age;
	char gender;
	string name, mail, password, blood_type;
	tm date_of_last_donation;

};
struct BloodData {
	string type;
	int quantity;
	string receivedDate;
	string expiryDate;
};
class Donor
{
public:
	void login(unordered_map<string, donorinfo>& donors);
	void Register(unordered_map<string, donorinfo>& donors);
	void update(unordered_map<string, donorinfo>& donors);
	bool check_time(const tm& last_date);
	bool validate();
	void check_blood_type(map<string, int>& blood_tank, string, int);
	void display_info();
	void request(map<string, int>& blood_tank);
	void Delete_account(unordered_map<string, donorinfo>& donors);
	void save();
	~Donor();
};