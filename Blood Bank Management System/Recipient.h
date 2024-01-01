#include <iostream>
#include <unordered_map>
#include <string>
#include<fstream>
#include<iterator>
#include <sstream>
#include<map>
#include"Donor.h"
using namespace std;

struct RecipientArg {
    string name;
    string mail;
    string password;
    string age;    // Updated data type to string
    string gender; // Updated data type to string
    string blood_type;
    string hospital;
    string doctor;
};

class Recipient {
public:
    void registerRecipient(unordered_map<string, RecipientArg>& recipients);

    void loginRecipient(unordered_map<string, RecipientArg>& recipients);

    void updateRecipient(unordered_map<string, RecipientArg>& recipients);
    void requestBlood(map<string, int>& bloodData);
    void check_blood_availability(unordered_map<string, int>& recipients);
    void home3();
    void displayAllBloodData();
    void Delete_account(unordered_map<string, RecipientArg>& recipients);

};
