#include <iostream>
#include <string>
#include <cstdlib> // clear the screen
#include <windows.h> // for windows os
#include <fstream> // file handling
#include <sstream> 
#include <conio.h> // wait for any key signal


using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // use font color 

int userOption = 0;
string adminUserName = "1"; // default admin username
string adminPassword = "1"; // default admin password
int borrowingLimit   = 5; // default borrowing limit
float fineRate       = 10.00; // default fine-rate

void loginPanel(int userOption);
void adminMenu();
void createLibLogin();

int main(){
	
	
	
	
	do
	{
	cout << "\n";
	
	SetConsoleTextAttribute(hConsole, 15);
	
	cout << " /$$       /$$$$$$ /$$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$  /$$     /$$\n";                     
	cout << "| $$      |_  $$_/| $$__  $$| $$__  $$ /$$__  $$| $$__  $$|  $$   /$$/\n";                      
	cout << "| $$        | $$  | $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$ \  $$ /$$/\n";                          
	cout << "| $$        | $$  | $$$$$$$ | $$$$$$$/| $$$$$$$$| $$$$$$$/  \  $$$$/\n";                           
	cout << "| $$        | $$  | $$__  $$| $$__  $$| $$__  $$| $$__  $$   \  $$/\n";                             
	cout << "| $$        | $$  | $$  \ $$| $$  \ $$| $$  | $$| $$  \ $$    | $$\n";                             
	cout << "| $$$$$$$$ /$$$$$$| $$$$$$$/| $$  | $$| $$  | $$| $$  | $$    | $$\n";                           
	cout << "|________/|______/|_______/ |__/  |__/|__/  |__/|__/  |__/    |__/\n";                              
	cout << "                                     /$$   /$$ /$$$$$$$$ /$$$$$$$  /$$   /$$ /$$        /$$$$$$\n";
	cout << "                                    | $$$ | $$| $$_____/| $$__  $$| $$  | $$| $$       /$$__  $$\n";
	cout << "                                    | $$$$| $$| $$      | $$  \ $$| $$  | $$| $$      | $$  \ $$\n";
	cout << "                                    | $$ $$ $$| $$$$$   | $$$$$$$ | $$  | $$| $$      | $$$$$$$$\n";
	cout << "                                    | $$  $$$$| $$__/   | $$__  $$| $$  | $$| $$      | $$__  $$\n";
	cout << "                                    | $$\  $$$| $$      | $$  \ $$| $$  | $$| $$      | $$  | $$\n";
	cout << "                                    | $$ \  $$| $$$$$$$$| $$$$$$$/|  $$$$$$/| $$$$$$$$| $$  | $$\n";
	cout << "                                    |__/  \__/|________/|_______/  \______/ |________/|__/  |__/\n";
		
	cout << "\n";
	
	// Display Main menue
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t============================\n";
	cout << "\t\t\t\t\t||  WELCOME - MAIN MENUE  ||\n";
	cout << "\t\t\t\t\t============================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t********************************************\n";
	cout << "\t\t\t\t--------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t\t[1] ADMIN                 **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t\t[2] LIBRARIAN             **\n";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t\t\t** \t\t[3] EXIT                  **\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t********************************************\n";	
	SetConsoleTextAttribute(hConsole, 7);
	
	for (int i = 0; i < 32; ++i) 
	{
    	std::cout << ' ';
    }
	
	SetConsoleTextAttribute(hConsole, 0x17);
	cout << "Choose an option(1-3) =>";
	SetConsoleTextAttribute(hConsole, 7);
	cout << " ";
	cin  >> userOption;
	
	cout << "\n";
	
	// Allow user choose an option
	switch(userOption){
		case 1:
		case 2:
			system("cls"); // Clear the screen before enter into login-panel
			loginPanel(userOption);
			exit(0);
		case 3:{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\t\t\t\tTHANK YOU FOR CHOOSEING LIBRARY NEBULA\n";
			cout << "\t\t\t\t\t\tGOOD BYE\n";
			SetConsoleTextAttribute(hConsole, 7);
			break;
		}
		default:{
			for (int i = 0; i < 32; ++i) 
			{
	        	std::cout << ' ';
	    	}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "[!] INVALID OPTION [!]";
			SetConsoleTextAttribute(hConsole, 7);
			
			cout << "\n";
			
			for (int i = 0; i < 32; ++i) 
			{
	        	std::cout << ' ';
	    	}
			
			SetConsoleTextAttribute(hConsole, 0x97);
			cout << "Please Enter Again.....";
			SetConsoleTextAttribute(hConsole, 7);
			Sleep(2000);
			system("cls");
			continue;
		}	
	}
	
	
	}while(userOption!=3);
	
}

// Display the login-panel according to the user-input
void loginPanel(int userOption)
{
	if(userOption == 1){
		
		string userName;
		string password;
		
		while (true)
		{
			// Display Admin login-panel
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\t\t\t\t\t============================\n";
			cout << "\t\t\t\t\t|| ADMIN |  LOGIN-PANEL   ||\n";
			cout << "\t\t\t\t\t============================\n";
			SetConsoleTextAttribute(hConsole, 7);
			
			cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n";
			cout << "\t\t\t\t\tUsername: ";
			cin  >> userName;
			cout << "\t\t\t\t\tPassword: ";
			cin  >> password;
			
			if (userName == adminUserName && password == adminPassword){
				
				for (int i = 0; i < 40; ++i) 
				{
	        		std::cout << ' ';
	    		}
	    		SetConsoleTextAttribute(hConsole, 0x2F);
	    		cout << "\n";
	    		std::cout << "\t\t\t\t\tACCESS GRANTED";
				SetConsoleTextAttribute(hConsole, 7);
				Sleep(1000);
				system("cls");
				adminMenu();
				exit(0);
			}
			else
			{
				for (int i = 0; i < 40; ++i) 
				{
	        		std::cout << ' ';
	    		}
	    		SetConsoleTextAttribute(hConsole, 0x4F);
	    		cout << "\n";
	    		std::cout << "\t\t\t\t\tACCESS DENIED\n";
				SetConsoleTextAttribute(hConsole, 7);
				
				SetConsoleTextAttribute(hConsole, 0x17);
				cout << "\t\t\t\t\tRe-Enter the Credentials";
				SetConsoleTextAttribute(hConsole, 7);
				Sleep(1500);
				system("cls");
				continue;
			}
		}
	
	}
}

void adminMenu()
{	
	do
	{
	// Display Admin Menu-panel	
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t============================\n";
	cout << "\t\t\t\t\t|| ADMIN |   MENU-PANEL   ||\n";
	cout << "\t\t\t\t\t============================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t********************************************\n";
	cout << "\t\t\t\t--------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[1] SIGN-UP LIBRARIANS            **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[2] Search Librarians             **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[3] MODIFY BORROWING LIMTS        **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[4] CHANGE FINE RATE              **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[5] CHANGE ADMIN PASSWORD         **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[6] MAIN MENU                     **\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t--------------------------------------------\n";
	cout << "\t\t\t\t********************************************\n";	
	SetConsoleTextAttribute(hConsole, 7);
	
	for (int i = 0; i < 32; ++i) 
	{
    	std::cout << ' ';
    }
	
	SetConsoleTextAttribute(hConsole, 0x17);
	cout << "Choose an option(1-6) =>";
	SetConsoleTextAttribute(hConsole, 7);
	cout << " ";
	cin  >> userOption;
	
	switch(userOption){
		case 1:{
			system("cls");
			createLibLogin();
			break;
		}
		case 6:{
			system("cls");
			main();
		}
		default:{
			for (int i = 0; i < 32; ++i) 
			{
	        	std::cout << ' ';
	    	}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "[!] INVALID OPTION [!]";
			SetConsoleTextAttribute(hConsole, 7);
			
			cout << "\n";
			
			for (int i = 0; i < 32; ++i) 
			{
	        	std::cout << ' ';
	    	}
			
			SetConsoleTextAttribute(hConsole, 0x97);
			cout << "Please Enter Again.....";
			SetConsoleTextAttribute(hConsole, 7);
			Sleep(2000);
			system("cls");
			continue;
		}
	}
	
	}while(userOption!=5);
	
}

void createLibLogin()
{
	string nationalID;
	string libID;
	string libName;
	string email;
	string phoneNumber; 
	string libUsername;
	string libPassword1;
	string libPassword2;
	
	// Create Librarian account
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t================================\n";
	cout << "\t\t\t\t\t||  Create Librarian Account  ||\n";
	cout << "\t\t\t\t\t================================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	cout << "\t\t\t\t------------------------------------------------\n";
	cout << "\t\t\t\tEnter the National ID(19xxxxxxxxx): ";
	cin >> nationalID;
	
	cout << "\n";
	
	libID = "LN#" + nationalID.substr(4, 11);
	
	fstream myFile;
	
	// open Librarian.dat to check existence of a librarian
	myFile.open("Librarian.dat", ios::in);
	
	if(myFile.is_open())
	{
		string line;
		while(getline(myFile, line))
		{
			istringstream ss(line);
			string id;
			getline(ss, id, ',');
			
			// Check enterd id equal to the Librarian ID
			if(id == libID)
			{	
				for (int i = 0; i < 38; ++i) 
				{
	        		std::cout << ' ';
	    		}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "Librarian Already Exist in the system\n";
				SetConsoleTextAttribute(hConsole, 7);
				myFile.close();
				
				myFile.open("Librarian.dat", ios::in);
				
				string line;
				while(getline(myFile, line))
				{
					istringstream ss(line);
					string id, fullName, email,phoneNumber;
					getline(ss, id, ',');
					getline(ss, fullName, ',');
					getline(ss, email, ',');
					getline(ss, phoneNumber, ',');
					
					cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
					cout << "\t\t|\tId\t|\t\tName\t\t\t|\t\tEmail\t\t\t|\tT.P Number |\n";
					cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
					
					cout << "\t\t| " << id << "\t| " << fullName << "\t\t\t|  " << email << "\t\t\t|  " << phoneNumber << "\t   |\n";
					cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
					
					myFile.close();
					
					cout << "\n";
					
					for (int i = 0; i < 32; ++i) 
					{
	        			std::cout << ' ';
	    			}
			
					SetConsoleTextAttribute(hConsole, 0x37);
					cout << "Press any key to return to the Admin Menu-Panel...";
					SetConsoleTextAttribute(hConsole, 0x7);
					getch();
					system("cls");
				}
	
			}
			// Get librarian information 
			else
			{
				for (int i = 0; i < 38; ++i) 
				{
	        		std::cout << ' ';
	    		}
				SetConsoleTextAttribute(hConsole, 0x2F); 
				cout << "Librarian Does not Exist in the system\n";
				SetConsoleTextAttribute(hConsole, 7);
				
				cout << "\t\t\t\t------------------------------------------------\n";
				cout << "\t\t\t\t\t   Librarian Registration Form\n";
				cout << "\t\t\t\t Full Name\t: ";
				getline(cin, libName);
				cin.ignore();
				cout << "\t\t\t\t Email\t\t: ";
				getline(cin, email);
				cin.ignore();
				cout << "\t\t\t\t Phone Number\t: ";
				getline(cin, phoneNumber);
				cin.ignore();
				
				cout << "\t\t\t\t------------------------------------------------\n";
				cout << "\t\t\t\t\t   Librarian Login Credentials\n";
				cout << "\t\t\t\t Enter a username\t: ";
				getline(cin, libUsername)
				cin.ignore();
				cout << "\t\t\t\t Enter a password\t: "; 
				getline(cin, libPassword1);
				cin.ignore();
				cout << "\t\t\t\t Re-Enter the password\t: ";
				getlin(cin, libPassword2);
				cin.ignore();				
			}
			
		}
	}
	else
	{
		cout << "File does not exist";
	}

}
