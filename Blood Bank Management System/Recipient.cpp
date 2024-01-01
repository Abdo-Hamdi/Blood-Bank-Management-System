#include "Recipient.h"
#include"Showing.h"
#include<fstream>
Showing s;
fstream blood,tem, tempy, fin;
void Recipient::registerRecipient(unordered_map<string, RecipientArg>& recipients) {
    cout << "Enter recipient information:\n";
    string id;
    RecipientArg recipient;
    cout << "ID: ";
    cin >> id;

    // Check if ID already exists in the file
    ifstream fin("recipients.txt");
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string existing_id;
        ss >> existing_id;
        if (existing_id == id)
        {
            cout << "ID already exists. Please enter a different ID: ";
            cin >> id;
            // Reset the file pointer to check the ID again
            fin.clear();
            fin.seekg(0, ios::beg);
        }
    }
    fin.close();

    cout << "Name: ";
    cin >> recipient.name;
    cout << "Mail: ";
    cin >> recipient.mail;
    cout << "Password: ";
    cin >> recipient.password;
    cout << "Age: ";
    cin >> recipient.age;
    cout << "Gender (M/F): ";
    cin >> recipient.gender;
    cout << "Blood type: ";
    cin >> recipient.blood_type;
    cout << "Hospital: ";
    cin >> recipient.hospital;
    cout << "Doctor: ";
    cin >> recipient.doctor;
    recipients[id] = recipient;

    // Append the new recipient to the file
    ofstream fout("recipients.txt", ios::app);
    fout << id << " " << recipient.name << " " << recipient.mail << " " << recipient.password << " " << recipient.age << " " << recipient.gender << " " << recipient.blood_type << " " << recipient.hospital << " " << recipient.doctor << "\n";
    fout.close();

    cout << "Recipient registered successfully.\n";
}

void Recipient::loginRecipient(unordered_map<string, RecipientArg>& recipients) {
    string id, password;
    bool found = false;

    do {
        cout << "Enter recipient ID: ";
        cin >> id;

        // Search for the ID in the file
        ifstream fin("recipients.txt");
        if (!fin) {
            cout << "Error opening file.\n";
            return;
        }

        string fileID, name, mail, filePassword, age, gender, blood_type, hospital, doctor;
        while (fin >> fileID >> name >> mail >> filePassword >> age >> gender >> blood_type >> hospital >> doctor) {
            if (fileID == id) {
                found = true;

                bool passwordMatched = false;
                while (!passwordMatched) {
                    cout << "Enter password: ";
                    cin >> password;
                    if (filePassword == password) {
                        passwordMatched = true;
                        cout << "Recipient information:\n";
                        cout << "Name: " << name << "\n";
                        cout << "Mail: " << mail << "\n";
                        cout << "Password: " << filePassword << "\n";
                        cout << "Age: " << age << "\n";
                        cout << "Gender: " << gender << "\n";
                        cout << "Blood type: " << blood_type << "\n";
                        cout << "Hospital: " << hospital << "\n";
                        cout << "Doctor: " << doctor << "\n";
                    }
                    else {
                        cout << "Incorrect password.\n";
                    }
                }
                break;
            }
        }

        fin.close();

        if (!found) {
            cout << "Recipient not found.\n";
            cout << "Please try again.\n";
        }
    } while (!found);
}


void Recipient::updateRecipient(unordered_map<string, RecipientArg>& recipients) {
    string id, password;
    cout << "Enter recipient ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;

    // Check if recipient exists in the file
    ifstream fin("recipients.txt");
    string line;
    bool recipientExists = false;
    while (getline(fin, line)) {
        stringstream ss(line);
        string existing_id;
        ss >> existing_id;
        if (existing_id == id) {
            recipientExists = true;
            break;
        }
    }
    fin.close();

    if (!recipientExists) {
        cout << "Recipient with ID " << id << " not found.\n";
        return;
    }

    // Clear the existing data in the unordered map
    recipients.clear();

    // Read the recipient data from the file and populate the unordered map
    fin.open("recipients.txt");
    while (getline(fin, line)) {
        stringstream ss(line);
        string existing_id, name, mail, password, age, gender, blood_type, hospital, doctor;
        ss >> existing_id >> name >> mail >> password >> age >> gender >> blood_type >> hospital >> doctor;

        RecipientArg recipientArg;
        recipientArg.name = name;
        recipientArg.mail = mail;
        recipientArg.password = password;
        recipientArg.age = age;
        recipientArg.gender = gender;
        recipientArg.blood_type = blood_type;
        recipientArg.hospital = hospital;
        recipientArg.doctor = doctor;

        recipients[existing_id] = recipientArg;
    }
    fin.close();

    // Search for the recipient in the unordered map
    auto it = recipients.find(id);
    if (it != recipients.end()) {
        RecipientArg& recipient = it->second;
        if (recipient.password == password) {
            cout << "Select the information to update:\n";
            cout << "1. Name\n";
            cout << "2. Mail\n";
            cout << "3. Password\n";
            cout << "4. Age\n";
            cout << "5. Gender\n";
            cout << "6. Blood type\n";
            cout << "7. Hospital\n";
            cout << "8. Doctor\n";
            cout << "9. All Information\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            // Update the selected information
            bool updated = false;
            switch (choice) {
            case 1: {
                string updatedName;
                cout << "Enter updated name: ";
                cin >> updatedName;
                recipient.name = updatedName;
                updated = true;
                break;
            }
            case 2: {
                string updatedMail;
                cout << "Enter updated mail: ";
                cin >> updatedMail;
                recipient.mail = updatedMail;
                updated = true;
                break;
            }
            case 3: {
                string updatedPassword;
                cout << "Enter updated password: ";
                cin >> updatedPassword;
                recipient.password = updatedPassword;
                updated = true;
                break;
            }
            case 4: {
                int updatedAge;
                cout << "Enter updated age: ";
                cin >> updatedAge;
                recipient.age = updatedAge;
                updated = true;
                break;
            }
            case 5: {
                string updatedGender;
                cout << "Enter updated gender: ";
                cin >> updatedGender;
                recipient.gender = updatedGender;
                updated = true;
                break;
            }
            case 6: {
                string updatedBloodType;
                cout << "Enter updated blood type: ";
                cin >> updatedBloodType;
                recipient.blood_type = updatedBloodType;
                updated = true;
                break;
            }
            case 7: {
                string updatedHospital;
                cout << "Enter updated hospital: ";
                cin >> updatedHospital;
                recipient.hospital = updatedHospital;
                updated = true;
                break;
            }
            case 8: {
                string updatedDoctor;
                cout << "Enter updated doctor: ";
                cin >> updatedDoctor;
                recipient.doctor = updatedDoctor;
                updated = true;
                break;
            }
            case 9:
                cout << "Enter updated information:\n";
                cout << "Name: ";
                cin >> recipient.name;
                cout << "Mail: ";
                cin >> recipient.mail;
                cout << "Password: ";
                cin >> recipient.password;
                cout << "Age: ";
                cin >> recipient.age;
                cout << "Gender (M/F): ";
                cin >> recipient.gender;
                cout << "Blood type: ";
                cin >> recipient.blood_type;
                cout << "Hospital: ";
                cin >> recipient.hospital;
                cout << "Doctor: ";
                cin >> recipient.doctor;
                updated = true;
                break;
            default:
                cout << "Invalid choice.\n";
            }

            if (updated) {
                // Update recipient information in the file
                ofstream fout("recipients_temp.txt");
                for (const auto&
                    entry : recipients) {
                    const string& existing_id = entry.first;
                    const RecipientArg& recipient = entry.second;
                    fout << existing_id << " " << recipient.name << " " << recipient.mail << " " << recipient.password << " " << recipient.age << " " << recipient.gender << " " << recipient.blood_type << " " << recipient.hospital << " " << recipient.doctor << "\n";
                }
                fout.close();
                // Remove the original file and rename the temporary file
                remove("recipients.txt");
                rename("recipients_temp.txt", "recipients.txt");

                cout << "Recipient with ID " << id << " has been updated.\n";
            }
        }
        else {
            cout << "Incorrect password. Update unsuccessful.\n";
        }
    }
    else {
        cout << "Recipient with ID " << id << " not found.\n";
    }
}

void Recipient::check_blood_availability(unordered_map<string, int>& blood_bank) {

    RecipientArg recipient;
    string blood_type;
    cout << "enter blood_type" << endl;

    cin >> blood_type;
    
    blood.open("Blood Quantity.txt", ios::in);
    string line;
    BloodData bloodData;
    while (getline(blood, line)) {
        stringstream ss(line);
        string existing_blood_type;
        int existing_blood_quantity;
        string ex, last;
        ss >> existing_blood_type;
        ss >> existing_blood_quantity;
        getline(ss, bloodData.receivedDate, ':');
        getline(ss, bloodData.receivedDate, ' ');
        getline(ss, bloodData.receivedDate, ' ');
        getline(ss, bloodData.receivedDate);
        getline(ss, bloodData.expiryDate, ':');
        getline(ss, bloodData.expiryDate, ' ');
        getline(ss, bloodData.expiryDate, ' ');
        getline(ss, bloodData.expiryDate);
        
        if (existing_blood_type == blood_type && existing_blood_quantity >= 0) {
            cout << "Blood type " << blood_type << " is available in the blood bank with " 
                << existing_blood_quantity << " units." << endl;
            cout << "Received Date : " << bloodData.receivedDate << bloodData.expiryDate <<"\n";
        }
        else if(existing_blood_type == blood_type && existing_blood_quantity == 0){
            cout << "Blood type " << blood_type << " is not available in the blood bank." << endl;
        }
    }
    blood.close();
    home3();
}

void Recipient::requestBlood(map<string, int>& bloodData) {
    BloodData bloodDt;
    RecipientArg recipient;
    string bloodType;
    int quantity;
    string hospital;
    cout << "please enter blood type " << endl;
    cin >> bloodType;
    cout << "please enter qauntity " << endl;
    cin >> quantity;
    cout << "please enter name of hosipital " << endl;
    cin >> hospital;
    
    blood.open("Blood Quantity.txt", ios::in);
    tem.open("tem.txt", ios::app);
    string line;
    while (getline(blood, line)) {
        stringstream ss(line);
        string existing_blood_type;
        int existing_blood_quantity;
        ss >> existing_blood_type;
        ss >> existing_blood_quantity;
        getline(ss, bloodDt.receivedDate, ':');
        getline(ss, bloodDt.receivedDate, ' ');
        getline(ss, bloodDt.receivedDate, ' ');
        getline(ss, bloodDt.receivedDate);
        getline(ss, bloodDt.expiryDate, ':');
        getline(ss, bloodDt.expiryDate, ' ');
        getline(ss, bloodDt.expiryDate, ' ');
        getline(ss, bloodDt.expiryDate);
        int q = quantity;
        int k = 0;
        if (existing_blood_type == bloodType){
            k += existing_blood_quantity;
            if (existing_blood_quantity - quantity == 0) {
                
                k -= quantity;
                cout << quantity << " units  " << bloodType << " requested for " << hospital << endl;
                cout << "remaining" << "  :" << k << endl;
                cout << "Request completed successfully!" << endl;
                break;
            }
            else if (existing_blood_quantity - quantity > 0) {
                k -= quantity;
                cout << quantity << " units  " << bloodType << " requested for " << hospital << endl;
                cout << "remaining" << "  :" << k << endl;
                cout << "Request completed successfully!" << endl;
                tem << existing_blood_type << ' ' << k << ' ' << bloodDt.receivedDate << ' ' << bloodDt.expiryDate << endl;
            }
        }
        
        
        else if (existing_blood_type == bloodType && existing_blood_quantity - quantity < 0) {
            cout << "Blood type not available " << endl;
        }
        else {
            tem << line << "\n";
        }
    }
    blood.close();
    tem.close();

    remove("Blood Quantity.txt");
    rename("tem.txt", "Blood Quantity.txt");
}
void Recipient::displayAllBloodData() {
    ifstream bloodDataFile("Blood Quantity.txt");
    if (!bloodDataFile) {
        std::cout << "Unable to open blood data file. Please try again later.\n";
        return;
    }

    cout << "Blood Data:\n";
    BloodData bloodData;
    string line;
    while (getline(bloodDataFile, line)) {
        istringstream iss(line);
        if (iss >> bloodData.type >> bloodData.quantity) {
            getline(iss, bloodData.receivedDate, ':');
            getline(iss, bloodData.receivedDate, ' ');
            getline(iss, bloodData.receivedDate, ' ');
            getline(iss, bloodData.receivedDate);
            getline(iss, bloodData.expiryDate, ':');
            getline(iss, bloodData.expiryDate, ' ');
            getline(iss, bloodData.expiryDate, ' ');
            getline(iss, bloodData.expiryDate);

            cout << "Blood Type: " << bloodData.type << "\n"
                << "Quantity: " << bloodData.quantity << "\n"
                << "Received Date: " << bloodData.receivedDate << "\n"
                << "Expiry Date: " << bloodData.expiryDate << "\n\n";
        }
    }
    bloodDataFile.close();
}
void Recipient::Delete_account(unordered_map<string, RecipientArg>& recipients)
{
    string id, password;
    cout << "Enter recipient ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;
    tempy.open("temp.txt", ios::app);
    fin.open("recipients.txt", ios::in);
    string line;
    while (getline(fin, line))//check id
    {
        stringstream ss(line);
        string existing_id;
        ss >> existing_id;
        if (existing_id == id) {
            continue;
        }
        else {
            tempy << line << "\n";
        }
    }
    fin.close();
    tempy.close();
    remove("recipients.txt");
    rename("temp.txt", "recipients.txt");
    cout << "Recipients account deleted\n" << endl;
    recipients.erase(id);
    s.home1();
}
void Recipient::home3() {
    unordered_map<string, RecipientArg> recipients;
    map<string, int> bloodData;
    unordered_map<string, int> blood_bank;
    int option;
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Register recipient\n";
        cout << "2. Login recipient\n";
        cout << "3. Update recipient information\n";
        cout << "4. check_blood_availability\n";
        cout << "5. requestBlood\n";
        cout << "6. Display all blood data\n";
        cout << "7. Delete Account \n";
        cout << "8. Exit\n";
        cout << "Option: ";
        cin >> option;

        switch (option) {
        case 1:
            registerRecipient(recipients);
            break;
        case 2:
            loginRecipient(recipients);
            break;
        case 3:
            updateRecipient(recipients);
            break;
        case 4:
            check_blood_availability(blood_bank);
            break;
        case 5:
            requestBlood(bloodData);
            break;
        case 6:
            displayAllBloodData();
            break;
        case 7:
            Delete_account(recipients);
            break;
        case 8:
            
            exit(0);
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (option != 4);
}