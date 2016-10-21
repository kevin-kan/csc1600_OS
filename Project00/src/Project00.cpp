// Kevin Kan
// CSC 1600-100: Operating Systems
// Professor McGeary
// September 6, 2016

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>

using namespace std;

// --- Taking username input ---
void getUser(char *username){
	char temp[120];
	do {
		cout << "Username:";
		cin >> temp;
	}while (strlen(temp) > 20); //will keep asking to input until shorter than 20
	strcpy(username, temp);
//	cout << "Your username is:" << username << endl; //for testing input
	return;
}

// --- Taking password input ---
void getPass(char *password){
	char temp[120];
	do {
		cout << "Password:";
		cin >> temp;
	}while (strlen(temp) > 20); //will keep asking to input until shorter than 20
	strcpy(password, temp);
//	cout << "Your password is:" << password << endl; //for testing input
	return;
}

// --- User/pass file manipulation ---
bool testCombo(char *password, char *username){
	FILE *combinations;
	char buff1[255];
	char buff2[255];
	combinations = fopen("passwd.txt", "r");

	while (fscanf(combinations, "%s %s", buff1, buff2) > 0){
//		cout << "buffs: " << buff1 << " " << buff2 << endl;
		if (strcmp(buff1,username) == 0 && strcmp(buff2,password) == 0){
			cout << "Access Granted!" << endl;
			return true;
		}
	}
	cout << "Invalid Username and Password Combination. Try Again." << endl;
	return false;
}


int main(){
	char username[20]; //Will hold User input for username
	char password[20]; //Will hold User input for password
//	char temp[100]; // Temp storage for user input

//	getUser();
//	getPass();
//	cout << *username << endl;
//	cout << *password << endl;

	bool access = false;
//	char combo[40] = ""; // User/pass input combination
	while (!access){
		getUser(username);
		getPass(password);
		access = testCombo(username,password);
//		cout << "access: " << access << endl;
	}
	return 0;
}
