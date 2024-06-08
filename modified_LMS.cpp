#include <iostream>
#include <string>
#include <cstdlib> // clear the screen
#include <windows.h> // for windows os  / Sleep 
#include <fstream> // file handling
#include <sstream> // read a single line
#include <conio.h> // wait for any key signal
#include <cctype> // use to convert to lowercase
#include <algorithm> // to get the transform function
#include <ctime> // to access time related functions    

// lnb#9780446310789 bookid   //bid#2872772  borrower id  // LN#2872772 libID

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // use font color 
string adminPassword = "1";
int userOption = 0;
string bookAvailability = "yes";

// prototyping
void loginPanel(int userOption);
void adminMenu();
void librarianMenu();
void createLibLogin(); 
void searchLib();
void modifyBrLimit();
void changeFineRate();
void changeAdminPassworrd();
void addAndDeleteBooksMenu();
void addBooks();
void deleteBooks();
void searchAndUpdateBooksMenu();
void searchBooks();
void updateBooks();
void addAndDeleteBorrowersMenu();
void addBorrowers();
void deleteBorrowers();
void searchAndUpdateBorrowersMenu();
void searchBorrowers();
void updateBorrowers();
void issuseAndReturnBooks();
void showAllBookDetails(); // new function
void issueBooks(string bookID, string borrowerID, int currentBorrowLimit);
void acceptReturnedBooks(string bookID, string borrowerID, int currentBorrowLimit);


int main(){
		
	do
	{
	cout << "\n";
	
	SetConsoleTextAttribute(hConsole, 15);
	
	cout << " /$$       /$$$$$$ /$$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$  /$$     /$$ \n";                     
	cout << "| $$      |_  $$_/| $$__  $$| $$__  $$ /$$__  $$| $$__  $$|  $$   /$$/ \n";                      
	cout << "| $$        | $$  | $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$ \  $$ /$$/ \n";                          
	cout << "| $$        | $$  | $$$$$$$ | $$$$$$$/| $$$$$$$$| $$$$$$$/  \  $$$$/ \n";                           
	cout << "| $$        | $$  | $$__  $$| $$__  $$| $$__  $$| $$__  $$   \  $$/ \n";                             
	cout << "| $$        | $$  | $$  \ $$| $$  \ $$| $$  | $$| $$  \ $$    | $$ \n";                             
	cout << "| $$$$$$$$ /$$$$$$| $$$$$$$/| $$  | $$| $$  | $$| $$  | $$    | $$ \n";                           
	cout << "|________/|______/|_______/ |__/  |__/|__/  |__/|__/  |__/    |__/ \n";                              
	cout << "                                     /$$   /$$ /$$$$$$$$ /$$$$$$$  /$$   /$$ /$$        /$$$$$$ \n";
	cout << "                                    | $$$ | $$| $$_____/| $$__  $$| $$  | $$| $$       /$$__  $$ \n";
	cout << "                                    | $$$$| $$| $$      | $$  \ $$| $$  | $$| $$      | $$  \ $$ \n";
	cout << "                                    | $$ $$ $$| $$$$$   | $$$$$$$ | $$  | $$| $$      | $$$$$$$$ \n";
	cout << "                                    | $$  $$$$| $$__/   | $$__  $$| $$  | $$| $$      | $$__  $$ \n";
	cout << "                                    | $$\  $$$| $$      | $$  \ $$| $$  | $$| $$      | $$  | $$ \n";
	cout << "                                    | $$ \  $$| $$$$$$$$| $$$$$$$/|  $$$$$$/| $$$$$$$$| $$  | $$ \n";
	cout << "                                    |__/  \__/|________/|_______/  \______/ |________/|__/  |__/ \n";
		
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
			exit(0);
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
			cout << "PLEASE ENTER AGAIN.....";
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
	if(userOption == 1)
	{
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
			
			fstream adminPassFile;
			adminPassFile.open("admin.dat", ios::in);
			
			if(!adminPassFile)
			{
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE MAIN MENU PANEL.....\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				main();
			}
			
		 	// Get the username and password from the file
			string line;
			getline(adminPassFile, line);
			string adminUserName, adminPassword;
			istringstream ss(line);
			
			getline(ss, adminUserName, '|');
			getline(ss, adminPassword, '|');
			
			adminPassFile.close();
			
			
			// Check the username and password are both correct
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
				char option = '0';
				
				
				for (int i = 0; i < 40; ++i) 
				{
	        		std::cout << ' ';
	    		}
	    		SetConsoleTextAttribute(hConsole, 0x4F);
	    		cout << "\n";
	    		std::cout << "\t\t\t\t\tACCESS DENIED\n";
				SetConsoleTextAttribute(hConsole, 7); 
				
				SetConsoleTextAttribute(hConsole, 0x17);
				cout << "\t\t\t\t\tDo you want to try again?(y/n)";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";
				cin >> option;
				
				if (option == 'Y' || option == 'y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					main();
				}
				
			}
		}
	
	}
	else if(userOption == 2)
	{
		string userName;
		string password;
		
		while(true)
		{
			// Display librarian login-panel
			SetConsoleTextAttribute(hConsole, 14);
			cout << "\t\t\t\t\t================================\n";
			cout << "\t\t\t\t\t||  Librarian |  LOGIN-PANEL  ||\n";
			cout << "\t\t\t\t\t================================\n";
			SetConsoleTextAttribute(hConsole, 7);
			
			cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n";
			cout << "\t\t\t\t\tUsername: ";
			cin  >> userName;
			cout << "\t\t\t\t\tPassword: ";
			cin  >> password;
			
			fstream libFile;
			
			libFile.open("Librarian.dat", ios::in);
			
			if(libFile.is_open())
			{
				string line;
				while(getline(libFile, line))
				{
					istringstream ss(line);
					string id, fullName, email,phoneNumber,libUserName, libPassword;
					getline(ss, id, '|');
					getline(ss, fullName, '|');
					getline(ss, email, '|');
					getline(ss, phoneNumber, '|');
					getline(ss, libUserName, '|');
					getline(ss, libPassword, '|');
					
					if(userName == libUserName && password == libPassword)
					{
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
						librarianMenu();
						exit(0);
					}	
				}
				char option = '0';
				
				for (int i = 0; i < 40; ++i) 
				{
	        		std::cout << ' ';
	    		}
	    		SetConsoleTextAttribute(hConsole, 0x4F);
	    		cout << "\n";
	    		std::cout << "\t\t\t\t\tACCESS DENIED\n";
				SetConsoleTextAttribute(hConsole, 7);
				
				SetConsoleTextAttribute(hConsole, 0x17);
				cout << "\t\t\t\t\tDo you want to try again?(y/n)";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";
				cin >> option;
				
				if (option == 'Y' || option == 'y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					main();
				}
				
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
	cout << "\t\t\t\t** \t[2] FIND LIBRARIANS               **\n";
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
	
	// Get user inputs
	SetConsoleTextAttribute(hConsole, 0x17);
	cout << "Choose an option(1-6) =>";
	SetConsoleTextAttribute(hConsole, 7);
	cout << " ";
	cin  >> userOption;
	
	switch(userOption){
		case 1:{
			system("cls");
			createLibLogin();
		}
		case 2:{
			system("cls");
			searchLib();
			main();
		}
		case 3:{
			system("cls");
			modifyBrLimit();
		}
		case 4:{
			system("cls");
			changeFineRate();
		}
		case 5:{
			system("cls");
			changeAdminPassworrd();
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
			cout << "PLEASE ENTER AGAIN.....";
			SetConsoleTextAttribute(hConsole, 7);
			Sleep(2000);
			system("cls");
			continue;
		}
	}
	
	}while(userOption!=6);
	
}

void librarianMenu()
{	
	do
	{
	// Display Admin Menu-panel	
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t================================\n";
	cout << "\t\t\t\t\t|| Librarian |   MENU-PANEL   ||\n";
	cout << "\t\t\t\t\t================================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t************************************************\n";
	cout << "\t\t\t\t------------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[1] ADD AND DELETE BOOKS              **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[2] SEARCH AND UPDATE BOOKS           **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[3] ISSUSE AND RETURN BOOKS           **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[4] ADD AND DELETE BORROWERS          **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[5] SEARCH AND UPDATE BORROWERS       **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[6] SHOW ALL BOOK DETAILS             **\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t** \t[7] MAIN MENU                         **\n";
	SetConsoleTextAttribute(hConsole, 15); 
	cout << "\t\t\t\t------------------------------------------------\n";
	cout << "\t\t\t\t************************************************\n";	
	SetConsoleTextAttribute(hConsole, 7);
	
	for (int i = 0; i < 32; ++i) 
	{
    	std::cout << ' ';
    }
	
	// Get user inputs
	SetConsoleTextAttribute(hConsole, 0x17);
	cout << "Choose an option(1-7) =>";
	SetConsoleTextAttribute(hConsole, 7);
	cout << " ";
	cin  >> userOption;
	
	switch(userOption){
		case 1:{
			system("cls");
			addAndDeleteBooksMenu();
		}
		case 2:{
			system("cls");
			searchAndUpdateBooksMenu();
		}
		case 3:{
			system("cls");
			issuseAndReturnBooks();
		}
		case 4:{
			system("cls");
			addAndDeleteBorrowersMenu();
		}
		case 5:{
			system("cls");
			searchAndUpdateBorrowersMenu();
		}
		case 6:{
			system("cls");
			showAllBookDetails();
		}
		case 7:{
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
			cout << "PLEASE ENTER AGAIN.....";
			SetConsoleTextAttribute(hConsole, 7);
			Sleep(2000);
			system("cls");
			continue;
		}
	}
	
	}while(userOption!=6);
}

void searchLib()
{
	string libID;
	
	// 
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t==========================\n";
	cout << "\t\t\t\t\t|| FIND |  LIBRARIANCE  ||\n";
	cout << "\t\t\t\t\t==========================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	cout << "\t\t\t\t------------------------------------------\n";
	cout << "\t\t\t\tEnter the librarian ID: ";
	cin  >> libID;
	cout << "\t\t\t\t------------------------------------------\n";
	
	fstream myFile;
	
	myFile.open("Librarian.dat", ios::in);
	
	if(myFile.is_open())
	{
		string line;
		while(getline(myFile, line))
		{
			istringstream ss(line);
			string ID, fullName, email, phoneNumber;
			getline(ss, ID, '|');
			getline(ss, fullName, '|');
			getline(ss, email, '|');
			getline(ss, phoneNumber, '|');
			
			if (libID == ID)
			{
				for (int i = 0; i < 38; ++i) 
				{  
		        	std::cout << ' ';
		    	}
				SetConsoleTextAttribute(hConsole, 0x2F); 
				cout << "LIBRARIAN FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				
				cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t\t|\tId\t|\t\tName\t\t\t|\t\tEmail\t\t\t|\tT.P Number |\n";
				cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
							
				cout << "\t\t| " << ID << "\t| " << fullName << "\t\t\t|  " << email << "\t\t\t|  " << phoneNumber << "\t   |\n";
				cout << "\t\t--------------------------------------------------------------------------------------------------------------------\n";
							
				myFile.close();
							
				cout << "\n";
							
				for (int i = 0; i < 32; ++i) 
				{
			        std::cout << ' ';
			    }
					
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "PRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL.....";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				adminMenu();
			}
			
		}
		
		cout << "\n";
		
		for (int i = 0; i < 38; ++i) 
		{
		    std::cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, 0x4F); 
		cout << "LIBRARIAN NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL.....";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		adminMenu();
		
	}
	
}

void modifyBrLimit()
{
	char opt;
	int borrowingLimit = 0;
	
	while(true)
	{
		
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t================================\n";
		cout << "\t\t\t\t\t|| MODIFY |  BORROWING LIMITS ||\n";
		cout << "\t\t\t\t\t================================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		fstream borrowFile;
		borrowFile.open("borrowlimt.dat", ios::in);
		
		if(borrowFile.is_open())
		{
			borrowFile >> borrowingLimit;
			borrowFile.close();
			
		}
		
		else
		{
			cout << "File does not found";
		}
		
		
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tCurrent Borrowing Limt: " << borrowingLimit << "\n";
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tDo you want to change the current limit(y/n)? ";
		cin  >> opt;
		
		cout << "\t\t\t\t------------------------------------------------\n";
		
		if(opt == 'Y' || opt == 'y')
		{
			borrowFile.open("borrowlimt.dat", ios::out);
			
			int brLimit = 0;
			
			cout << "\t\t\t\tEnter new borrowing limit: ";
			cin  >> brLimit;
			
			if(brLimit < 1)
			{
				for (int i = 0; i < 32; ++i) 
				{
		        	std::cout << ' ';
		    	}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "[!] INVALID LIMIT [!]\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY RE-ENTER\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				continue;
			}
			
			
			if(borrowFile.is_open())
			{
				borrowFile << brLimit;
				borrowFile.close();
			}
			
			else
			{
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL.....\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				adminMenu();
			}
			
			cout << "\n";
			
			cout << "\t\t\t\tPRESS ANY KEY SAVE UPDATE....";
			getch();
			system("cls");
			continue;
		}
		else{
			system("cls");
			adminMenu();
		}
	}
	
}

void changeFineRate()
{
	char opt;
	float fineRate = 0.0;
	
	while(true)
	{
		
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t=========================\n";
		cout << "\t\t\t\t\t|| MODIFY |  FINE RATE ||\n";
		cout << "\t\t\t\t\t=========================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		fstream bookFineRate;
		bookFineRate.open("finerate.dat", ios::in);
		
		if(bookFineRate.is_open())
		{
			bookFineRate >> fineRate;
			bookFineRate.close();
			
		}
		else
		{
			cout << "File does not found";
		}
		
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tCurrent Fine Rate(Rs): " << fineRate << "\n";
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tDo you want to change the current fine(y/n)? ";
		cin  >> opt;
		
		cout << "\t\t\t\t------------------------------------------------\n";
		
		if(opt == 'Y' || opt == 'y')
		{
			float fRate = 0.0;
			
			cout << "\t\t\t\tEnter new fine rate(Rs): ";
			cin  >> fRate;
			
			if(fRate < 0)
			{
				for (int i = 0; i < 32; ++i) 
				{
		        	std::cout << ' ';
		    	}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "[!] INVALID FINE RATE [!]\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY RE-ENTER...\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				continue;
			}
			
			
			bookFineRate.open("finerate.dat", ios::out);
			
			if(bookFineRate.is_open())
			{
				bookFineRate << fRate;
				bookFineRate.close();
			}
			
			else
			{
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL.....\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				adminMenu();
				
			}
		
			
			cout << "\n";
			
			cout << "\t\t\t\tPRESS ANY KEY SAVE UPDATE";
			getch();
			system("cls");
			continue;
		}
		else{
			system("cls");
			adminMenu();
		}
	}
}

void changeAdminPassworrd()
{
	string currentPassword;
	string newPassword;
	string confirmNewPassword;
	string username;
	
	while(true)
	{
		
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t==============================\n";
		cout << "\t\t\t\t\t|| CHANGE |  ADMIN PASSWORD ||\n";
		cout << "\t\t\t\t\t==============================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tEnter your current password\t: ";
		cin  >> currentPassword;
		
		cout << "\n";
		
		
		// First read the admin.dat file to get the current password
		fstream adminPassFile;
			adminPassFile.open("admin.dat", ios::in);
			
			if(!adminPassFile)
			{
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE MAIN MENU PANEL.....\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				main();
			}
			
		 	// Get the username and password from the file
			string line;
			getline(adminPassFile, line);
			string adminUserName, adminPassword;
			istringstream ss(line);
			
			getline(ss, adminUserName, '|');
			getline(ss, adminPassword, '|');
			
			username = adminUserName;
		
			adminPassFile.close();
		
		if(adminPassword != currentPassword)
		{
			char opt = '0';
			
			for (int i = 0; i < 32; ++i) 
			{
	        	std::cout << ' ';
	    	}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "[!] INVALID PASSWORD [!]\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tDO YOU WANT TO CHAGE THE PASSWORD AGAIN(y/n)? \n";
			SetConsoleTextAttribute(hConsole, 0x7);
			
			if(opt == 'y' || opt == 'Y')
			{
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				adminMenu();
			}
			getch();
			system("cls");
			continue;
		}
		
		cout << "\t\t\t\tEnter new password\t\t: ";
		cin  >> newPassword;
		cout << "\t\t\t\tRe enter the password\t\t: ";
		cin  >> confirmNewPassword;
		
		if(newPassword == confirmNewPassword)
		{
			
			fstream adminPassFile;
			adminPassFile.open("admin.dat", ios::out);
			
			//write new password with the original username;
			adminPassFile << username << "|" << newPassword;
			adminPassFile.close();
				
			for (int i = 0; i < 40; ++i) 
			{
        		std::cout << ' ';
    		}
    		SetConsoleTextAttribute(hConsole, 0x2F);
    		cout << "\n";
    		std::cout << "\t\t\t\t\tPASSWORD UPDATED SUCESSFULLY!\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL......\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			adminMenu();
			
		}
	}
	
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
	
	while(true)
	{
		
		// Create Librarian account
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t================================\n";
		cout << "\t\t\t\t\t||  Create Librarian Account  ||\n";
		cout << "\t\t\t\t\t================================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get user inputs for NIC
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\tEnter the National ID: ";
		cin >> nationalID;
		cout << "\n";
		
		// Check the NIC has valid number of digits
		if(nationalID.length() == 9 || nationalID.length() == 12) 
		{
			break;
		}
		else
		{
			for (int i = 0; i < 38; ++i) 
			{
		        std::cout << ' ';
		    }
			SetConsoleTextAttribute(hConsole, 0x4F); 
			cout << "Invalid NIC Number\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO RE-ENTER THE PASSWORD...";
			SetConsoleTextAttribute(hConsole, 0x7);	
			getch();
			system("cls");
			continue;	
		}
	}
	
	if(nationalID.length() == 9)
	{
		nationalID = "19" + nationalID;
		libID = "LN#" + nationalID.substr(4, 10);
	}
	
	else if(nationalID.length() == 12)
	{
		libID = "LN#" + nationalID.substr(4, 10);	
	}
	
	fstream myFile;
	
	myFile.open("Librarian.dat", ios::in);
	
	// open Librarian.dat to check existence of a librarian
	
	if(myFile.is_open())
	{	
		string line;
		//getline(myFile, line); 
		
		while(getline(myFile, line))
		{
			istringstream ss(line);
			string id;
			getline(ss, id, '|'); 
				
			// Check enterd id equal to the Librarian ID
			if(id == libID)
			{	
				for (int i = 0; i < 38; ++i) 
				{
		        	std::cout << ' ';
		    	}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "LIBRARIAN ALREADY EXIST IN THE SYSTEM\n";
				SetConsoleTextAttribute(hConsole, 7);
				myFile.close();
					
				myFile.open("Librarian.dat", ios::in);
					
				string line;
				//getline(myFile, line); // to skip the first line in file
				
				while(getline(myFile, line))
				{
					istringstream ss(line);
					string id, fullName, email,phoneNumber;
					getline(ss, id, '|');
					getline(ss, fullName, '|');
					getline(ss, email, '|');
					getline(ss, phoneNumber, '|');
						
					if (id == libID)
					{
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
						cout << "PRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL...";
						SetConsoleTextAttribute(hConsole, 0x7);
						getch();
						system("cls");
						adminMenu();
						
					}
				}
		
			}
		}
		// Get librarian information 
				
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
	    cin.ignore();
		getline(cin, libName);
		
		cout << "\t\t\t\t Email\t\t: ";
		cin  >> email;
	
	    // Modified part
	
		while(true)
		{
			cout << "\t\t\t\t Phone Number\t: ";
			cin  >> phoneNumber;
			
			if(phoneNumber.length() != 10)
			{
				for (int i = 0; i < 32; ++i) 
				{
		        	std::cout << ' ';
		    	}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "PHONE NUMBER MUST HAVE 10 DIGITS\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO RE-ENTER THE PHONE NUMBER...";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				cout << "\t\t\t\t------------------------------------------------\n";
				cout << "\t\t\t\t\t   Librarian Registration Form\n";
				cout << "\t\t\t\t Full Name\t: " << libName << endl;
				cout << "\t\t\t\t Email\t\t: " << email << endl;
				
				continue;
			}
			break;
			
		}
					
					
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\t\t   Librarian Login Credentials\n";
		cout << "\t\t\t\t Enter a username\t: ";
		cin  >> libUsername;
					
		while(true)
		{
			cout << "\t\t\t\t Enter a password\t: ";
			cin  >> libPassword1;
						
			cout << "\t\t\t\t Re-Enter the password\t: ";
			cin  >> libPassword2;
										
			if(libPassword1 == libPassword2)
			{
				break;
			}
			else
			{	
				cout << "\n";
				
				for (int i = 0; i < 32; ++i) 
				{
		        	std::cout << ' ';
		    	}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "ENTER PASSWORD DOES NOT MATCHED\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO RE-ENTER THE PASSWORD...\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				continue;
			}
		}
			
			fstream myFile_lib;
			myFile_lib.open("Librarian.dat", ios::app);
					
			myFile_lib << "\n";
					
			if(myFile_lib.is_open())
			{
				myFile_lib << libID << "|";
				myFile_lib << libName << "|";
				myFile_lib << email << "|"; 
				myFile_lib << phoneNumber << "|";
				myFile_lib << libUsername << "|";
				myFile_lib << libPassword1;
						
				myFile_lib.close();
			}
			else
			{
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL...\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				adminMenu();
			}
			
			cout << "\n";
			
			for (int i = 0; i < 20; ++i) 
			{
		        	std::cout << ' ';
		    }
						
			SetConsoleTextAttribute(hConsole, 0x2F);
			cout << "\t\tSuccess! A NEW LIBRARIAN HAS BEEN ADDED TO THE SYSTEM\n\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADMIN MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			adminMenu();	
											
	}
	else
	{
		cout << "File does not exist";
	}
	
	

}

void addAndDeleteBooksMenu()
{
	int option = 0;
	
	do{
		
		// Add and Delete books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t===========================\n";
		cout << "\t\t\t\t\t|| ADD OR DELETE | BOOKS ||\n";
		cout << "\t\t\t\t\t===========================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t********************************************\n";
		cout << "\t\t\t\t--------------------------------------------\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[1]ADD BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[2]DELETE BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[3]LIBRARIAN MENU\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t--------------------------------------------\n";
		cout << "\t\t\t\t********************************************\n";	
		SetConsoleTextAttribute(hConsole, 7);
		
		for (int i = 0; i < 32; ++i) 
		{
    	std::cout << ' ';
    	}	
	
		// Get user inputs
		SetConsoleTextAttribute(hConsole, 0x17);
		cout << "Please choose an option";
		SetConsoleTextAttribute(hConsole, 0x7);
		cout << " ";
		cin  >> option;
		
		switch(option)
		{
			case 1:{
				system("cls");
				addBooks();
			}
			case 2:{
				system("cls");
				deleteBooks();
			}
			case 3:{
				system("cls");
				librarianMenu();
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
				cout << "PRESS ANY KEY TO RETURN TO TRY AGAIN";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				continue;
			}
		}
		
	}while(option!=3);

}

void addBooks()
{
	string isbnNum;
	string title;
	string author;
	string price;
	string publisher;
	string genre;
	
	// Add books 
	
	while(true)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t=================\n";
		cout << "\t\t\t\t\t\t|| ADD | BOOKS ||\n";
		cout << "\t\t\t\t\t\t=================\n";
		SetConsoleTextAttribute(hConsole, 7);	
		
		// Get the ISBN number from the user
		cout << "\t\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t\tEnter the ISBN: ";
		cin  >> isbnNum;
		cout << "\n";
		
		// Check the ISBN is valid
		if (isbnNum.length() != 13 && isbnNum.length() != 10 )
		{
			char opt = '0';
			for (int i = 0; i < 38; ++i) 
			{
		        std::cout << ' ';
		    }
			SetConsoleTextAttribute(hConsole, 0x4F); 
			cout << "INVALID ISBN NUMBER\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tDo you want to re-enter the ISBN(y/n)? ";
			cin  >> opt;
			SetConsoleTextAttribute(hConsole, 0x7);	
			if(opt == 'y' || opt == 'Y')
			{
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				librarianMenu();
			}
			
		}
		else
		{
			break;
		}
	}
	string bookID = "LNB#" + isbnNum;
		
	fstream bookFile;
	bookFile.open("book.dat", ios::in);
		
		// Open book.dat file 
	if(bookFile.is_open())
	{
		string line;
		while(getline(bookFile, line))
		{
			string bID,title,author,publisher,genre,price,availability;
			istringstream ss(line);
			getline(ss, bID, '|');
			getline(ss, title, '|');
			getline(ss, author, '|');
			getline(ss, publisher, '|');
			getline(ss, genre, '|');
			getline(ss, price, '|');
			getline(ss, availability, '|');
			
			if(bookID == bID)
			{
				for (int i = 0; i < 38; ++i) 
				{
	        	std::cout << ' ';
	    		}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "\tBook Already Exist In The System\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				cout << "\t\t\t\t-------------------------------------------------\n";
				cout << "\t\t\t\tBook ID\t\t: " << bID << "\n";
				cout << "\t\t\t\tTitle\t\t: " << title << "\n";
				cout << "\t\t\t\tAuthor\t\t: " << author << "\n";
				cout << "\t\t\t\tPublisher\t: " << publisher << "\n";
				cout << "\t\t\t\tGenre\t\t: " << genre << "\n";
				cout << "\t\t\t\tPrice\t\t: " << price << "\n";
				cout << "\t\t\t\tAvailability\t: " << bookAvailability << "\n";
				
				bookFile.close();
					
				cout << "\n";
					
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
			
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "PRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				librarianMenu();
				
			}
		} 
		// Get book information 	
		for (int i = 0; i < 38; ++i) 
		{
		    std::cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, 0x2F); 
		cout << "Book Does not Exist in the system\n";
		SetConsoleTextAttribute(hConsole, 7);
					
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\t\t   Book Registration Form\n";
		cout << "\t\t\t\tBook Title\t: ";
		 cin.ignore();
		getline(cin, title);
		cout << "\t\t\t\tBook Author\t: ";
		getline(cin, author);
		cout << "\t\t\t\tBook Publisher\t: ";
		getline(cin, publisher);
		cout << "\t\t\t\tBook Genre\t: ";
		getline(cin, genre);
		cout << "\t\t\t\tBook Price\t: ";
		cin  >> price;
			
		//Write book information to the book.dat file
		fstream bookFile;
		
		bookFile.open("book.dat", ios::app);
				
		if(bookFile.is_open())
		{			
			bookFile << bookID << "|"; 
			bookFile << title << "|";
			bookFile << author << "|"; 
			bookFile << publisher << "|";
			bookFile << genre << "|"; 
			bookFile << price << "|";
			bookFile << bookAvailability;
						
			bookFile.close();
		}
		else
		{
			cout << "File does not found";
		}
		 
		
		for (int i = 0; i < 20; ++i) 
		{
	        	std::cout << ' ';
	    }
					
		SetConsoleTextAttribute(hConsole, 0x2F);
		cout << "\t\tSUCESS! A NEW BOOK HAS BEEN ADDED TO THE SYSTEM\n\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu();
		
	}
	else
	{
		for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADD & DELETE MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		addAndDeleteBooksMenu();
	}
	
}

void deleteBooks()
{
	string deleteCriteria;
	char option = '0';
	bool found = false;
	
	while(true)
	{
		// Delete books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t====================\n";
		cout << "\t\t\t\t\t\t|| DELETE | BOOKS ||\n";
		cout << "\t\t\t\t\t\t====================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get the BOOKID or TITLE number from the user
		cout << "\t\t\t\t---------------------------------------------------\n";
		cout << "\t\t\t\tEnter the (BOOKID/TITLE): ";
		cin.ignore();
		getline(cin, deleteCriteria);
		cout << "\n";
		
		// Convert to lowercase
		transform(deleteCriteria.begin(), deleteCriteria.end(), deleteCriteria.begin(), ::tolower);

		fstream deleteFile, tempFile;
		
		deleteFile.open("book.dat", ios::in);
		tempFile.open("temp.dat", ios::app);
	
		if(deleteFile.is_open() && tempFile.is_open())
		{
			string line;
			while(getline(deleteFile, line))
			{
				string bookID, title;
				istringstream ss(line);
				getline(ss, bookID, '|');
				getline(ss, title, '|');
								
				// to convert bookID and author to lowercase
				transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
				transform(title.begin(), title.end(), title.begin(), ::tolower); 
								
				// First need to check whether a book is available or not before delete			
				if(deleteCriteria == bookID || deleteCriteria == title)
				{
					found = true;
					continue;					
				}	
				
				tempFile << line;
				tempFile << "\n";
			}
			
			// Check found is false
			if(found!=true)
			{
				for (int i = 0; i < 40; ++i) 
				{
			        std::cout << ' ';
			    }
			
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "DELETE CRITERIA DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tDo you want to enter again(y/n)?";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";
				cin  >> option;
				if(option == 'y' || option == 'Y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					librarianMenu();
				}
			}
			
			// If found doesn't false below one execute
			deleteFile.close();
			tempFile.close();
							
			remove("book.dat");
			rename("temp.dat", "book.dat");
							
			for (int i = 0; i < 20; ++i) 
			{
				std::cout << ' ';
			}
			SetConsoleTextAttribute(hConsole, 0x2F);
			cout << "\t\tSuccess! BOOK HAS BEEN DELETED FROM THE SYSTEM\n\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			librarianMenu();	
		}
		else
		{
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "FILE DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADD & DELETE MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			addAndDeleteBooksMenu();
		}
	}

}

void searchAndUpdateBooksMenu()
{
	int option = 0;
	do{
		
		// Search and Update books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t==============================\n";
		cout << "\t\t\t\t\t|| SEARCH OR UPDATE | BOOKS ||\n";
		cout << "\t\t\t\t\t==============================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t********************************************\n";
		cout << "\t\t\t\t--------------------------------------------\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[1]SEARCH BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[2]UPDATE BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[3]LIBRARIAN MENU\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t--------------------------------------------\n";
		cout << "\t\t\t\t********************************************\n";	
		SetConsoleTextAttribute(hConsole, 7);
		
		for (int i = 0; i < 32; ++i) 
		{
    	std::cout << ' ';
    	}	
	
		// Get user inputs
		SetConsoleTextAttribute(hConsole, 0x17);
		cout << "Please choose an option:";
		SetConsoleTextAttribute(hConsole, 7);
		cout << " ";
		cin  >> option;
		
		switch(option)
		{
			case 1:{
				system("cls");
				searchBooks();
			}
			case 2:{
				system("cls");
				updateBooks();
			}
			case 3:{
				system("cls");
				librarianMenu();
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
				cout << "Please enter any key to try again.....";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				continue;
			}
		}
		
	}while(option!=3);
}

void searchBooks()
{
	string searchCriteria;
	bool found = false;
	
	while(true)
	{
		// Search books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t====================\n";
		cout << "\t\t\t\t\t\t|| SEARCH | BOOKS ||\n";
		cout << "\t\t\t\t\t\t====================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get the ISBN number from the user
		cout << "\t\t\t\t----------------------------------------------------\n";
		cout << "\t\t\t\tEnter the (BOOKID/TITLE/AUTHOR/PUBLISHER/GENRE): ";
		cin.ignore();
		getline(cin, searchCriteria);
		cout << "\n";
		
		transform(searchCriteria.begin(), searchCriteria.end(), searchCriteria.begin(), ::tolower);
		
		// Open book.dat file put into the read mode
		fstream searchBookFile;
		searchBookFile.open("book.dat", ios::in);
		
		if(searchBookFile.is_open())
		{
			string line;
			while(getline(searchBookFile, line))
			{
				istringstream ss(line);
				string bookID, title, author, publisher, genre, price, bookAvailability;
				getline(ss, bookID, '|');
				getline(ss, title, '|');
				getline(ss, author, '|');
				getline(ss, publisher, '|');
				getline(ss, genre, '|');
				getline(ss, price, '|');
				getline(ss, bookAvailability, '|');
				
				// Convert information in the file to lowercase
				transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
				transform(title.begin(), title.end(), title.begin(), ::tolower);
				transform(author.begin(), author.end(), author.begin(), ::tolower);
				transform(publisher.begin(), publisher.end(), publisher.begin(), ::tolower);
				transform(genre.begin(), genre.end(), genre.begin(), ::tolower);
				
				// Search the book using the bookID
				if(searchCriteria == bookID)
				{
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\t\tBook ID\t\t: " << bookID << "\n";
					cout << "\t\t\t\t\tTitle\t\t: " << title << "\n";
					cout << "\t\t\t\t\tAuthor\t\t: " << author << "\n";
					cout << "\t\t\t\t\tPublisher\t: " << publisher << "\n";
					cout << "\t\t\t\t\tGenre\t\t: " << genre << "\n";
					cout << "\t\t\t\t\tPrice\t\t: " << price << "\n";
					cout << "\t\t\t\t\tAvailability\t: " << bookAvailability << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";
					
					searchBookFile.close();
						
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
					searchAndUpdateBooksMenu();
					
				}
				
				// Search the book using the title
				else if(searchCriteria == title)
				{
					found = true;
					
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\t\tBook ID\t\t: " << bookID << "\n";
					cout << "\t\t\t\t\tTitle\t\t: " << title << "\n";
					cout << "\t\t\t\t\tAuthor\t\t: " << author << "\n";
					cout << "\t\t\t\t\tPublisher\t: " << publisher << "\n";
					cout << "\t\t\t\t\tGenre\t\t: " << genre << "\n";
					cout << "\t\t\t\t\tPrice\t\t: " << price << "\n";
					cout << "\t\t\t\t\tAvailability\t: " << bookAvailability << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";
				}
				
				// Search the book using the author
				else if(searchCriteria == author)
				{
					found = true;
					
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\t\tBook ID\t\t: " << bookID << "\n";
					cout << "\t\t\t\t\tTitle\t\t: " << title << "\n";
					cout << "\t\t\t\t\tAuthor\t\t: " << author << "\n";
					cout << "\t\t\t\t\tPublisher\t: " << publisher << "\n";
					cout << "\t\t\t\t\tGenre\t\t: " << genre << "\n";
					cout << "\t\t\t\t\tPrice\t\t: " << price << "\n";
					cout << "\t\t\t\t\tAvailability\t: " << bookAvailability << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";
					
				}
				
				// Search the book using the publisher
				else if(searchCriteria == publisher)
				{
					found = true;
					
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\t\tBook ID\t\t: " << bookID << "\n";
					cout << "\t\t\t\t\tTitle\t\t: " << title << "\n";
					cout << "\t\t\t\t\tAuthor\t\t: " << author << "\n";
					cout << "\t\t\t\t\tPublisher\t: " << publisher << "\n";
					cout << "\t\t\t\t\tGenre\t\t: " << genre << "\n";
					cout << "\t\t\t\t\tPrice\t\t: " << price << "\n";
					cout << "\t\t\t\t\tAvailability\t: " << bookAvailability << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";
				}
				
				// Search the book using the genre
				else if(searchCriteria == genre)
				{
					found = true;
					
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\t\tBook ID\t\t: " << bookID << "\n";
					cout << "\t\t\t\t\tTitle\t\t: " << title << "\n";
					cout << "\t\t\t\t\tAuthor\t\t: " << author << "\n";
					cout << "\t\t\t\t\tPublisher\t: " << publisher << "\n";
					cout << "\t\t\t\t\tGenre\t\t: " << genre << "\n";
					cout << "\t\t\t\t\tPrice\t\t: " << price << "\n";
					cout << "\t\t\t\t\tAvailability\t: " << bookAvailability << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";

				}
			}
			 
			if(found!=true)
			{	
				char option = '0';
				
				for (int i = 0; i < 40; ++i) 
				{
				    std::cout << ' ';
				}
				
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "Search criteria does not found\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tDo you want to enter again(y/n)? ";
				SetConsoleTextAttribute(hConsole, 7);
				cin  >> option;
				if(option == 'y' || option == 'Y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					librarianMenu();
				}
			}
			
			searchBookFile.close();
			for (int i = 0; i < 32; ++i) 
			{
			    std::cout << ' ';
			}
				
			SetConsoleTextAttribute(hConsole, 0x97);
			cout << "PRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 7);
			getch();
			system("cls");
			searchAndUpdateBooksMenu();
			
		}
		
		else
		{
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "FILE DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			searchAndUpdateBooksMenu();
		}
		
	}
	
}

void updateBooks()
{
	string bookID;
	bool found = false;
	
	// Update books 
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t\t====================\n";
	cout << "\t\t\t\t\t\t|| UPDATE | BOOKS ||\n";
	cout << "\t\t\t\t\t\t====================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	// Get the bookID from the user
	cout << "\t\t\t\t---------------------------------------------------\n";
	cout << "\t\t\t\tEnter the BOOKID: ";
	cin  >> bookID;
	cout << "\t\t\t\t---------------------------------------------------\n";
	
	// to lovwercase the entered book id
	transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
	
	// Open the book.dat to check the availability of a particular book
	fstream updateBookFile;
	fstream tempFile;
	
	updateBookFile.open("book.dat", ios::in);
	tempFile.open("temp.dat", ios::out);
	
	if(updateBookFile.is_open() && tempFile.is_open())
	{
		string line;
		while(getline(updateBookFile, line))
		{
			istringstream ss(line);
			string bookid, title, author, publisher, genre, price, bookAvailability;
			getline(ss, bookid, '|');
			getline(ss, title, '|');
			getline(ss, author, '|');
			getline(ss, publisher, '|');
			getline(ss, genre, '|');
			getline(ss, price, '|');
			getline(ss, bookAvailability, '|');
			
			// to lovwercase the read book id
			transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);
			
			if(bookID == bookid)
			{
				int option = 0;
				found = true;
				string newCriteria = " ";
				
				do
				{
					cout << "\t\t\t\t---------------------------------------------------\n";
					SetConsoleTextAttribute(hConsole, 11);
					cout << "\t\t\t\t\t\t[1] Title\n";
					cout << "\t\t\t\t\t\t[2] Author\n";
					cout << "\t\t\t\t\t\t[3] Publisher\n";
					cout << "\t\t\t\t\t\t[4] Genre\n";
					cout << "\t\t\t\t\t\t[5] Availability\n";
					cout << "\t\t\t\t\t\t[6] Search and Upadate Menu\n";
					SetConsoleTextAttribute(hConsole, 7);
					cout << "\t\t\t\t---------------------------------------------------\n";
					
					cout << "\t\t\t\tChoose your option: ";
					cin  >> option;
					
					cout << "\t\t\t\t---------------------------------------------------\n";
					
					switch(option)
					{
						case 1:{
							cout << "\t\t\t\tCurrent Name: " << title << "\n";
							cout << "\t\t\t\t---------------------------------------------------\n";
							
							cout << "\t\t\t\tEnter New Title: ";
							cin.ignore();
							getline(cin, newCriteria);
							
							tempFile << bookID << "|" << newCriteria << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << bookAvailability;
							tempFile << "\n";
							break;
						}
						case 2:{
							cout << "\t\t\t\tCurrent Name: " << author << "\n";
							cout << "\t\t\t\t---------------------------------------------------\n";
							
							cout << "\t\t\t\tEnter New Author: ";
							cin.ignore();
							getline(cin, newCriteria);
							
							tempFile << bookID << "|" << title << "|" << newCriteria << "|" << publisher << "|" << genre << "|" << price << "|" << bookAvailability;
							tempFile << "\n";
							break;
						}
						case 3:{
							cout << "\t\t\t\tCurrent Name: " << publisher << "\n";
							cout << "\t\t\t\t---------------------------------------------------\n";
							
							cout << "\t\t\t\tEnter New Publisher: ";
							cin.ignore();
							getline(cin, newCriteria);
							
							tempFile << bookID << "|" << title << "|" << author << "|" << newCriteria << "|" << genre << "|" << price << "|" << bookAvailability;
							tempFile << "\n";
							break;
						}
						case 4:{
							cout << "\t\t\t\tCurrent Name: " << genre << "\n";
							cout << "\t\t\t\t---------------------------------------------------\n";
							
							cout << "\t\t\t\tEnter New Genre: ";
							cin.ignore();
							getline(cin, newCriteria);
							
							tempFile << bookID << "|" << title << "|" << author << "|" << publisher << "|" << newCriteria << "|" << price << "|" << bookAvailability;
							tempFile << "\n";
							break;
						}
						case 5:{
							cout << "\t\t\t\tCurrent Name: " << bookAvailability << "\n";
							cout << "\t\t\t\t---------------------------------------------------\n";
							
							cout << "\t\t\t\tEnter New Availability State: ";
							cin.ignore();
							getline(cin, newCriteria);
							
							tempFile << bookID << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << newCriteria;
							tempFile << "\n";
							break;
						}
						case 6:{
							system("cls");
							searchAndUpdateBooksMenu();
						}
						default:{
							for (int i = 0; i < 32; ++i) 
							{
	        					std::cout << ' ';
	    					}
	    	
							SetConsoleTextAttribute(hConsole, 0x4F);
							cout << "[!] INVALID UPDATE CRITERIA [!]";
							SetConsoleTextAttribute(hConsole, 0x97);
							cout << "PLEASE ENTER ANY KEY RE-ENTER.....";
							SetConsoleTextAttribute(hConsole, 7);
							getch();
							system("cls");
							continue;
						}
					}
					break;
					 
				}while(option!=6);
				
			}
			else
			{
				tempFile << line << "\n";
			}
			
		}
		updateBookFile.flush();
		updateBookFile.close();
		
		tempFile.flush();
		tempFile.close();
		
		remove("book.dat");
		rename("temp.dat", "book.dat");
		
		if(found!=true)
		{
			for (int i = 0; i < 40; ++i) 
			{
		        std::cout << ' ';
		    }
		
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "Book does not found\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\tPRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 7);
			getch();
			system("cls");
			searchAndUpdateBooksMenu();
		}
		
		for (int i = 0; i < 20; ++i) 
		{
			std::cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, 0x2F);
		cout << "\t\tSuccess! Book has been updated\n\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		searchAndUpdateBooksMenu();	
	}
	else
	{
		for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		searchAndUpdateBooksMenu();
	}
	
}

void addAndDeleteBorrowersMenu()
{
	int option = 0;
	
	do{
		// Add and Delete borrowerss 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t===============================\n";
		cout << "\t\t\t\t\t|| ADD OR DELETE | BORROWERS ||\n";
		cout << "\t\t\t\t\t===============================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t********************************************\n";
		cout << "\t\t\t\t--------------------------------------------\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[1]ADD BORROWERS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[2]DELETE BORROWERS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[3]LIBRARIAN MENU\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t--------------------------------------------\n";
		cout << "\t\t\t\t********************************************\n";	
		SetConsoleTextAttribute(hConsole, 7);
		
		for (int i = 0; i < 32; ++i) 
		{
    	std::cout << ' ';
    	}	
	
		// Get user inputs
		SetConsoleTextAttribute(hConsole, 0x17);
		cout << "Please choose an option";
		SetConsoleTextAttribute(hConsole, 0x7);
		cout << " ";
		cin  >> option;
		
		switch(option)
		{
			case 1:{
				system("cls");
				addBorrowers();
			}
			case 2:{
				system("cls");
				deleteBorrowers();
			}
			case 3:{
				system("cls");
				librarianMenu();
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
				cout << "Please enter any key to try again.....";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				continue;
			}
		}
		
	}while(option!=3);
}


void addBorrowers()
{
	string borrowerID;
	string nationalID;
	string name;
	string phone;
	string address;
	string joinDate;
	
	
	while(true)
	{
		// Add books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t=====================\n";
		cout << "\t\t\t\t\t\t|| ADD | BORROWERS ||\n";
		cout << "\t\t\t\t\t\t=====================\n";
		SetConsoleTextAttribute(hConsole, 7);	
		
		
		// Get the ISBN number from the user
		cout << "\t\t\t\t-------------------------------------------------\n";
		cout << "\t\t\t\tEnter the NIC: ";
		cin  >> nationalID;
		cout << "\n";
		
		// Check the ISBN is 
		
		if(nationalID.length() == 9 || nationalID.length() == 12)
		{
			break;
		}
		
		else
		{
			char opt = '0';
			for (int i = 0; i < 38; ++i) 
			{
		        std::cout << ' ';
		    }
			SetConsoleTextAttribute(hConsole, 0x4F); 
			cout << "Invalid NIC Number\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\t Do you want to re-enter the NIC\n";
			SetConsoleTextAttribute(hConsole, 0x7);	
			if(opt == 'y' || opt == 'Y')
			{
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				librarianMenu();
			}
			
		}

	}
	
	if(nationalID.length() == 9)
	{
		nationalID = "19" + nationalID;
		borrowerID = "BID#" + nationalID.substr(4, 10);
	}
	
	else if(nationalID.length() == 12)
	{
		borrowerID = "BID#" + nationalID.substr(4, 10);	
	}
	
		
	fstream borrowersFile;
	borrowersFile.open("borrowers.dat", ios::in);
		
	// Open book.dat file 
	if(borrowersFile.is_open())
	{
		string line;
		while(getline(borrowersFile, line))
		{
			string borrID,brrName,brrPhone,brrAddress,brrJoinDate, brrCount;
			istringstream ss(line);
			getline(ss, borrID, '|');
			getline(ss, brrName, '|');
			getline(ss, brrPhone, '|');
			getline(ss, brrAddress, '|');
			getline(ss, brrJoinDate, '|');
			getline(ss, brrCount, '|');
						
			if(borrowerID == borrID)
			{
				for (int i = 0; i < 38; ++i) 
				{
	        	std::cout << ' ';
	    		}
				SetConsoleTextAttribute(hConsole, 0x4F); 
				cout << "\tBorrower Already Exist In The System\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				cout << "\t\t\t\t-------------------------------------------------\n";
				cout << "\t\t\t\tBorrower ID\t\t: " << borrID << "\n";
				cout << "\t\t\t\tFull Name\t\t: " << brrName << "\n";
				cout << "\t\t\t\tPhone Number\t\t: " << brrPhone << "\n";
				cout << "\t\t\t\tAddress\t\t\t: " << brrAddress << "\n";
				cout << "\t\t\t\tJoin Date\t\t: " << brrJoinDate << "\n";
				cout << "\t\t\t\tBorrowed Count\t: " << brrCount << "\n";
				
				borrowersFile.close();
					
				cout << "\n";
					
				for (int i = 0; i < 32; ++i) 
				{
	        		std::cout << ' ';
	    		}
			
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "PRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				librarianMenu();
				
			}
		} 
		// Get book information 	
		for (int i = 0; i < 38; ++i) 
		{
		    std::cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, 0x2F); 
		cout << "Borrower Does not Exist in the system\n";
		SetConsoleTextAttribute(hConsole, 7);
					
		cout << "\t\t\t\t------------------------------------------------\n";
		cout << "\t\t\t\t\t   Borrower Registration Form\n";
		cout << "\t\t\t\tFull Name\t: ";
		cin.ignore();
		getline(cin, name);
		cout << "\t\t\t\tPhone Number\t: ";
		getline(cin, phone);
		cout << "\t\t\t\tAddress\t\t: ";
		getline(cin, address);
		
			
		//Write book information to the book.dat file
		fstream borrowersFile;
		
		borrowersFile.open("borrowers.dat", ios::app);
				
		if(borrowersFile.is_open())
		{		
			time_t now = time(0);
			tm *ltm = localtime(&now);
						
			int year = 1900 + ltm->tm_year; 
			int month = 1 + ltm->tm_mon; 
			int mDate = ltm->tm_mday;
					
			borrowersFile << borrowerID << "|"; 
			borrowersFile << name << "|";
			borrowersFile << phone << "|"; 
			borrowersFile << address << "|";
			borrowersFile << year << "-" << month << "-" << mDate; 
			borrowersFile << 0;
			borrowersFile.close();
		}
		else
		{
			cout << "File does not found";
		}
		 
		
		for (int i = 0; i < 20; ++i) 
		{
	        	std::cout << ' ';
	    }
					
		SetConsoleTextAttribute(hConsole, 0x2F);
		cout << "\t\tSuccess! NEW BORROWER HAS BEEN ADDED TO THE SYSTEM\n\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu();
		
	}
	else
	{
		for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADD & DELETE MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		addAndDeleteBorrowersMenu();
	}
	
}

void deleteBorrowers()
{
	string deleteCriteria;
	char option = '0';
	bool found = false;
	
	while(true)
	{
		// Delete books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t========================\n";
		cout << "\t\t\t\t\t\t|| DELETE | BORROWERS ||\n";
		cout << "\t\t\t\t\t\t========================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get the BOOKID or TITLE number from the user
		cout << "\t\t\t\t---------------------------------------------------\n";
		cout << "\t\t\t\tEnter the BORROWERID: ";
		cin.ignore();
		getline(cin, deleteCriteria);
		cout << "\n";
		
		// Convert to lowercase
		transform(deleteCriteria.begin(), deleteCriteria.end(), deleteCriteria.begin(), ::tolower);

		fstream deleteFile, tempFile;
		
		deleteFile.open("borrowers.dat", ios::in);
		tempFile.open("temp.dat", ios::app);
	
		if(deleteFile.is_open() && tempFile.is_open())
		{
			string line;
			while(getline(deleteFile, line))
			{
				string brrID;
				istringstream ss(line);
				getline(ss, brrID, '|');
								
				// to convert borrowerID and author to lowercase
				transform(brrID.begin(), brrID.end(), brrID.begin(), ::tolower);

								
				// First need to check whether a borrower is available or not before delete			
				if(deleteCriteria == brrID)
				{
					found = true;
					continue;					
				}	
				
				tempFile << line;
				tempFile << "\n";
			}
			
			// Check found is false
			if(found!=true)
			{
				for (int i = 0; i < 40; ++i) 
				{
			        std::cout << ' ';
			    }
			
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "DELETE CRITERIA DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tDo you want to enter again(y/n)?";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";
				cin  >> option;
				if(option == 'y' || option == 'Y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					librarianMenu();
				}
			}
			
			// If found doesn't false below one execute
			deleteFile.close();
			tempFile.close();
							
			remove("borrowers.dat");
			rename("temp.dat", "borrowers.dat");
							
			for (int i = 0; i < 20; ++i) 
			{
				std::cout << ' ';
			}
			SetConsoleTextAttribute(hConsole, 0x2F);
			cout << "\t\tSuccess! Borrower has been deleted from the system\n\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			librarianMenu();	
		}
		else
		{
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "FILE DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ADD AND DELETE MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			addAndDeleteBorrowersMenu();
		}
	}
}

void searchAndUpdateBorrowersMenu()
{
	int option = 0;
	do{
		
		// Search and Update borrowers 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t==================================\n";
		cout << "\t\t\t\t\t|| SEARCH OR UPDATE | BORROWERS ||\n";
		cout << "\t\t\t\t\t==================================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t********************************************\n";
		cout << "\t\t\t\t--------------------------------------------\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[1]SEARCH BORROWERS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[2]UPDATE BORROWERS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[3]LIBRARIAN MENU\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t--------------------------------------------\n";
		cout << "\t\t\t\t********************************************\n";	
		SetConsoleTextAttribute(hConsole, 7);
		
		for (int i = 0; i < 32; ++i) 
		{
    	std::cout << ' ';
    	}	
	
		// Get user inputs
		SetConsoleTextAttribute(hConsole, 0x17);
		cout << "Please choose an option:";
		SetConsoleTextAttribute(hConsole, 7);
		cout << " ";
		cin  >> option;
		
		switch(option)
		{
			case 1:{
				system("cls");
				searchBorrowers();
			}
			case 2:{
				system("cls");
				updateBorrowers();
			}
			case 3:{
				system("cls");
				librarianMenu();
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
				cout << "PRESS ANY KEY TO TRY AGAIN....";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				continue;
			}
		}
		
	}while(option!=3);
}

void searchBorrowers()
{
	string searchCriteria;
	bool found = false;
	
	while(true)
	{
		// Search books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t========================\n";
		cout << "\t\t\t\t\t\t|| SEARCH | BORROWERS ||\n";
		cout << "\t\t\t\t\t\t========================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get the ISBN number from the user
		cout << "\t\t\t\t----------------------------------------------------\n";
		cout << "\t\t\t\tEnter the (BORROWERID/NAME/PHONE NUMBER/ADDRESS): ";
		cin.ignore();
		getline(cin, searchCriteria);
		cout << "\n";
		
		transform(searchCriteria.begin(), searchCriteria.end(), searchCriteria.begin(), ::tolower);
		
		// Open borrower.dat file put into the read mode
		fstream searchBorrowerFile;
		searchBorrowerFile.open("borrowers.dat", ios::in);
		
		if(searchBorrowerFile.is_open())
		{
			string line;
			while(getline(searchBorrowerFile, line))
			{
				istringstream ss(line);
				string brrID, brrName, brrPhoneNumber, brrAddress, brrJoinDate, brrCount;
				getline(ss, brrID, '|');
				getline(ss, brrName, '|');
				getline(ss, brrPhoneNumber, '|');
				getline(ss, brrAddress, '|');
				getline(ss, brrJoinDate, '|');
				getline(ss, brrCount, '|');
			
				// Convert information in the file to lowercase
				transform(brrID.begin(), brrID.end(), brrID.begin(), ::tolower);
				transform(brrName.begin(), brrName.end(), brrName.begin(), ::tolower);
				transform(brrAddress.begin(), brrAddress.end(), brrAddress.begin(), ::tolower);

				// Search the book using the bookID
				if(searchCriteria == brrID)
				{
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\tBorrower ID\t\t: " << brrID << "\n";
					cout << "\t\t\t\tFull Name\t\t: " << brrName << "\n";
					cout << "\t\t\t\tPhone Number\t\t: " << brrPhoneNumber << "\n";
					cout << "\t\t\t\tAddress\t\t\t: " << brrAddress << "\n";
					cout << "\t\t\t\tJoin Date\t\t: " << brrJoinDate << "\n";
					cout << "\t\t\t\tBorrowed Count\t\t: " << brrCount << "\n";
					cout << "\t\t\t\t----------------------------------------------------\n";
					
					searchBorrowerFile.close();
						
					cout << "\n";
						
					for (int i = 0; i < 32; ++i) 
					{
		        		std::cout << ' ';
		    		}
				
					SetConsoleTextAttribute(hConsole, 0x37);
					cout << "PRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
					SetConsoleTextAttribute(hConsole, 0x7);
					getch();
					system("cls");
					librarianMenu();
					
				}
				
				// Search the book using the title
				else if(searchCriteria == brrName || searchCriteria == brrPhoneNumber|| searchCriteria == brrAddress)
				{
					found = true;
					
					cout << "\t\t\t\t----------------------------------------------------\n";
					cout << "\t\t\t\tBorrower ID\t\t: " << brrID << "\n";
					cout << "\t\t\t\tFull Name\t\t: " << brrName << "\n";
					cout << "\t\t\t\tPhone Number\t\t: " << brrPhoneNumber << "\n";
					cout << "\t\t\t\tAddress\t\t\t: " << brrAddress << "\n";
					cout << "\t\t\t\tJoin Date\t\t: " << brrJoinDate << "\n";
					cout << "\t\t\t\tBorrowed Count\t\t: " << brrCount << "\n"; 
					
				}
			
			}
			
			if(found!=true)
			{	
				char option = '0';
				
				for (int i = 0; i < 40; ++i) 
				{
				    std::cout << ' ';
				}
				
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "SEARCH CRITERIA DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tDo you want to enter again(y/n)? ";
				SetConsoleTextAttribute(hConsole, 7);
				cin  >> option;
				if(option == 'y' || option == 'Y')
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					librarianMenu();
				}
			}
			
			searchBorrowerFile.close();
			for (int i = 0; i < 32; ++i) 
			{
			    std::cout << ' ';
			}
				
			SetConsoleTextAttribute(hConsole, 0x97);
			cout << "PRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...";
			SetConsoleTextAttribute(hConsole, 7);
			getch();
			system("cls");
			librarianMenu();
			
		}
		
		else
		{
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "FILE DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE SEARCH & UPDATE MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			searchAndUpdateBorrowersMenu();
		}
		
	}
	
}

void updateBorrowers()
{
	string borrowerID;
	
	while(true)
	{
		
		// Update books 
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t\t========================\n";
		cout << "\t\t\t\t\t\t|| UPDATE | BORROWERS ||\n";
		cout << "\t\t\t\t\t\t========================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		// Get the bookID from the user
		cout << "\t\t\t\t---------------------------------------------------\n";
		cout << "\t\t\t\tEnter the BORROWERSID: ";
		cin  >> borrowerID;
		cout << "\t\t\t\t---------------------------------------------------\n";

		// Open the book.dat to check the availability of a particular book
		fstream updateBorrowersFile;
		fstream tempFile;
		
		updateBorrowersFile.open("borrowers.dat", ios::in);
		
		if(updateBorrowersFile.is_open())
		{
			string line;
			while(getline(updateBorrowersFile, line))
			{
				string borrowerid;
				istringstream ss(line);
				getline(ss, borrowerid, '|');
				
				// Check wether a enterd bookID is similer to the one in the boo.dat
				if(borrowerID == borrowerid)
				{
					updateBorrowersFile.close();
					
					int option = 0;
					string newCriteria = " ";
					while(true)
					{
						cout << "\t\t\t\t---------------------------------------------------\n";
						SetConsoleTextAttribute(hConsole, 11);
						cout << "\t\t\t\t\t\t[1] Name\n";
						cout << "\t\t\t\t\t\t[2] Phone Number\n";
						cout << "\t\t\t\t\t\t[3] Address\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "\t\t\t\t---------------------------------------------------\n";
						
						cout << "\t\t\t\tChoose your update criteria: ";
						cin  >> option;
						
						cout << "\t\t\t\t---------------------------------------------------\n";
						
						if(option < 1 || option > 4)
						{
							char option = '0';
				
							for (int i = 0; i < 40; ++i) 
							{
							    std::cout << ' ';
							}
				
							SetConsoleTextAttribute(hConsole, 0x4F);
							cout << "Update criteria does not found\n";
							SetConsoleTextAttribute(hConsole, 0x37);
							cout << "\t\t\t\t\tDo you want to enter again(y/n)?";
							SetConsoleTextAttribute(hConsole, 7);
							cout << ": ";
							
							cin  >> option;
							if(option == 'y' || option == 'Y')
							{
								system("cls");
								cout << "\n";
								continue;
							}
							else
							{
								system("cls");
								librarianMenu();
							}
						}	
						
						// Enter new value to update a information in a particular book
												
						updateBorrowersFile.open("borrowers.dat", ios::in);
						tempFile.open("temp.dat", ios::out);
						
						if(updateBorrowersFile.is_open() && tempFile.is_open())
						{
							string line;
							while(getline(updateBorrowersFile, line))
							{
								istringstream ss(line);
								string borrowerid, brrName, brrPhoneNumber, brrAddress, brrJoinDate, brrCount;
								getline(ss, borrowerid, '|');
								getline(ss, brrName, '|');
								getline(ss, brrPhoneNumber, '|');
								getline(ss, brrAddress, '|');
								getline(ss, brrJoinDate, '|');
							
								
								if(borrowerID == borrowerid)
								{
									if(option == 1)
									{	
										cout << "\t\t\t\tCurrent Name: " << brrName << "\n";
										cout << "\t\t\t\t---------------------------------------------------\n";
										
										cout << "\t\t\t\tEnter New Name: ";
										cin.ignore();
										getline(cin, newCriteria);
										
										tempFile << borrowerID << "|" << newCriteria << "|" << brrPhoneNumber << "|" << brrAddress << "|" << brrJoinDate << "|" << brrCount;
										tempFile << "\n";
										continue;
									}
									else if(option == 2)
									{
										cout << "\t\t\t\tCurrent Phone Number: " << brrPhoneNumber << "\n";
										cout << "\t\t\t\t---------------------------------------------------\n";
										
										cout << "\t\t\t\tEnter New Phone Number: ";
										cin.ignore();
										getline(cin, newCriteria);
										
										tempFile << borrowerID << "|" << brrName << "|" << newCriteria << "|" << brrAddress << "|" << brrJoinDate << "|" << brrCount;
										tempFile << "\n";
										continue;
									}
									else if(option == 3)
									{
										cout << "\t\t\t\tCurrent Address: " << brrAddress << "\n";
										cout << "\t\t\t\t---------------------------------------------------\n";
										
										cout << "\t\t\t\tEnter New Address: ";
										cin.ignore();
										getline(cin, newCriteria);
										
										tempFile << borrowerID << "|" << brrName << "|" << brrPhoneNumber << "|" << newCriteria << "|" << brrJoinDate << "|" << brrCount;
										tempFile << "\n";
										continue;
									}
									
								}
								tempFile << line;
								tempFile << "\n";
							}
							updateBorrowersFile.close();
							updateBorrowersFile.flush();
							
							tempFile.close();
							tempFile.flush();
											
							remove("borrowers.dat");
							rename("temp.dat", "borrowers.dat");
											
							for (int i = 0; i < 20; ++i) 
							{
								std::cout << ' ';
							}
							SetConsoleTextAttribute(hConsole, 0x2F);
							cout << "\t\tSUCESS! BORROWER HAS BEEN UPDATED\n\n";
							SetConsoleTextAttribute(hConsole, 0x7);
							SetConsoleTextAttribute(hConsole, 0x37);
							
							char opt = '0';
							
							cout << "\t\t\t\tDo you want to update again(Y/N)? ";
							SetConsoleTextAttribute(hConsole, 0x7);
							cin  >> opt;
							
							if(opt == 'y' || opt == 'Y')
							{
								system("cls");
								continue;
							}
							else
							{
								system("cls");
								librarianMenu();
							}
							
								
						}
						else
						{
							cout << "File does not found";
						}
						
					}
					
				}
				
			}
			
			char option = '0';
			
			for (int i = 0; i < 40; ++i) 
			{
			    std::cout << ' ';
			}
			
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "Borrower does not found\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\t\tDo you want to enter again(y/n)? ";
			SetConsoleTextAttribute(hConsole, 7);
			cin  >> option;
			if(option == 'y' || option == 'Y')
			{
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				librarianMenu();
			}					
		}
		else
		{
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "FILE DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			searchAndUpdateBorrowersMenu();
		}
	}
	
}

void issuseAndReturnBooks()
{
	int option = 0;
	string bookID, borrowerID;
	bool bookFound = false;
	bool borrowerFound = false;
	bool borrowLimtSatisfy = false;
	bool borrowLimtNotSatisfy = false;
	int borrowingLimit = 0;
	int currentBorrowLimit = 0;
	
	do
	{
		// Issuse and Accept books menu
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\t\t\t\t\t=============================\n";
		cout << "\t\t\t\t\t|| ISSUE OR ACCEPT | BOOKS ||\n";
		cout << "\t\t\t\t\t=============================\n";
		SetConsoleTextAttribute(hConsole, 7);
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t********************************************\n";
		cout << "\t\t\t\t--------------------------------------------\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[1]ISSUE BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[2]RETURN BOOKS\n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\t\t\t\t\t\t[3]LIBRARIAN MENU\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\t\t--------------------------------------------\n";
		cout << "\t\t\t\t********************************************\n";	
		SetConsoleTextAttribute(hConsole, 7);
		
		for (int i = 0; i < 32; ++i) 
		{
    	std::cout << ' ';
    	}	
	
		// Get user inputs
		SetConsoleTextAttribute(hConsole, 0x17);
		cout << "Please choose an option:";
		SetConsoleTextAttribute(hConsole, 7);
		cout << " ";
		cin  >> option;
		
		if(option == 3)
		{
			system("cls");
			librarianMenu();
		}
		
		if(option > 3)
		{
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
			cout << "PLEASE ENTER ANY KEY TO TRY AGAIN.....";
			SetConsoleTextAttribute(hConsole, 7);
			getch();
			system("cls");
			continue;
		}
		
		cout << "\t\t\t\t---------------------------------------------------\n";
		cout << "\t\t\t\tEnter BOOKID\t\t: ";
		cin  >> bookID;
		cout << "\t\t\t\tEnter BORROWERID\t: ";
		cin  >> borrowerID;
		
		cout << "\t\t\t\t---------------------------------------------------\n";
		
		transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
		transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
		
		// First check the both book and borrow id already exist in the system
		fstream bookFile, borrowerFile;
		
		bookFile.open("book.dat", ios::in);
		borrowerFile.open("borrowers.dat", ios::in);
		
		// Check the available status of a book (available or unavailable)
		if(bookFile.is_open() && borrowerFile.is_open())
		{
			string lineBook;
			while(getline(bookFile, lineBook))
			{
				istringstream ss(lineBook);
				string bookid; 
				getline(ss, bookid, '|');

				transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);				
				
				// Use, when book is available
				if(bookID == bookid)
				{	
					bookFound = true;
					break; 
				}
			}
			
			if(bookFound != true)
			{
				for (int i = 0; i < 40; ++i) 
				{
				    std::cout << ' ';
				}
				
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "BOOK DOES NOT FOUND OR ALREADY ISSUSED\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tPRESS ANY KEY TO RE-TRY";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				continue;
			} 
			
			
			// Read the borrowing limt and store it in a variable
			fstream brrowLimtFile;
			brrowLimtFile.open("borrowlimt.dat", ios::in);
			
			if(brrowLimtFile.is_open())
			{
				brrowLimtFile >> borrowingLimit;
				brrowLimtFile.close();	
			}
			else
			{
				for (int i = 0; i < 32; ++i) 
				{
		    		std::cout << ' ';
				}
		    	
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "FILE DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 7);
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
				SetConsoleTextAttribute(hConsole, 0x7);
				getch();
				system("cls");
				librarianMenu();
			}
			
			
			
			string lineBorr;
			while(getline(borrowerFile, lineBorr))
			{
				istringstream ss(lineBorr);
				string borrowerid, brrName, brrPhoneNumber, brrAddress, brrJoinDate, brrCount;
				getline(ss, borrowerid, '|');
				getline(ss, brrName, '|');
				getline(ss, brrPhoneNumber, '|');
				getline(ss, brrAddress, '|');
				getline(ss, brrJoinDate, '|');
				getline(ss, brrCount, '|');
				
				transform(borrowerid.begin(), borrowerid.end(), borrowerid.begin(), ::tolower);

				istringstream newValue(brrCount);
				newValue >> currentBorrowLimit;
				
				if(borrowerID == borrowerid, option == 2,  borrowingLimit-1 < currentBorrowLimit)
				{
					borrowerFound = true;
					borrowLimtSatisfy = true;
					break;
				}
				
				if(borrowerID == borrowerid )
				{
					borrowerFound = true; 
					if(currentBorrowLimit <= borrowingLimit-1)
					{	
						borrowLimtSatisfy = true;
						break;
					}
				}
			}
			
			if(borrowerFound != true)
			{
				for (int i = 0; i < 40; ++i) 
				{
				    std::cout << ' ';
				}
				
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "BORROWER DOES NOT FOUND\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tPRESS ANY KEY TO RETURN LIBRARIAN MENU";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				librarianMenu();
			} 
			
			if(borrowLimtSatisfy != true)
			{
				for (int i = 0; i < 40; ++i) 
				{
				    std::cout << ' ';
				}
				
				SetConsoleTextAttribute(hConsole, 0x4F);
				cout << "BORROWING LIMIT EXCEEDED, PLEASE RETURN SOME BOOKS!!\n";
				SetConsoleTextAttribute(hConsole, 0x37);
				cout << "\t\t\t\t\tPRESS ANY KEY TO RE-TRY";
				SetConsoleTextAttribute(hConsole, 7);
				getch();
				system("cls");
				librarianMenu();
			} 
			
		}
		else
		{
			
			for (int i = 0; i < 32; ++i) 
			{
	    		std::cout << ' ';
			}
	    	
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "BOOK OR BORROWER FILE DOES NOT FOUND!!!";
			SetConsoleTextAttribute(hConsole, 7);
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
			SetConsoleTextAttribute(hConsole, 0x7);
			getch();
			system("cls");
			continue;
		}
		
		bookFile.close();
		borrowerFile.close();
		
		// if both exist, then check wether to issue or accept a book
		if(bookFound && borrowerFound && borrowLimtSatisfy|| borrowLimtNotSatisfy)
		{ 
			switch(option)
			{
				case 1:{
					system("cls");
					issueBooks(bookID, borrowerID, currentBorrowLimit);			
				}
				case 2:{
					system("cls");
					acceptReturnedBooks(bookID, borrowerID, currentBorrowLimit);
				}
				
			}
			
		}
		else
		{
			char option = '0';
			
			for (int i = 0; i < 40; ++i) 
			{
			    std::cout << ' ';
			}
			
			SetConsoleTextAttribute(hConsole, 0x4F);
			cout << "BOOK ID OR BORROWER ID DOES NOT FOUND\n";
			SetConsoleTextAttribute(hConsole, 0x37);
			cout << "\t\t\t\t\tDO YOU WANT TO ENTER AGAIN(y/n)? ";
			SetConsoleTextAttribute(hConsole, 7);
			cin  >> option;
			if(option == 'y' || option == 'Y')
			{
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				librarianMenu();
			}
		}
			
		
	}while(option!=3);
		
}

void issueBooks(string bookid, string borrowerid, int currentBorrowLimit) 
{
	string bookTitle;
	float fine = 0.0;
	
	
	transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);
	transform(borrowerid.begin(), borrowerid.end(), borrowerid.begin(), ::tolower);
		
	// Issue books 
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t\t===================\n";
	cout << "\t\t\t\t\t\t|| ISSUE | BOOKS ||\n";
	cout << "\t\t\t\t\t\t===================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	 int year, month, day;

	 cout << "\t\t\t\t---------------------------------------------------\n";

     // Get the issue date from user
     cout << "\t\t\t\tEnter Issue Date (YYYY MM DD): ";
     cin >> year >> month >> day;
	 
	 tm issueDate = {};
	 issueDate.tm_year = year - 1900;
     issueDate.tm_mon = month - 1;
     issueDate.tm_mday = day;
     
     // Calculate the  due date
	 tm dueDate = issueDate;
	 dueDate.tm_mday += 14;
	 mktime(&dueDate);
	
	 //Open book.dat file put into the read mode
	 fstream readBookFile, tempFile1;
	 readBookFile.open("book.dat", ios::in);
	 tempFile1.open("temp.dat", ios::out);
	 
	 if(readBookFile.is_open() && tempFile1.is_open())
	 {
	 	string line;
	 	while(getline(readBookFile, line))
	 	{
			istringstream ss(line);
			string bookID, title, author, publisher, genre, price, bookAvailability;
			getline(ss, bookID, '|');
			getline(ss, title, '|');
			getline(ss, author, '|');
			getline(ss, publisher, '|');
			getline(ss, genre, '|');
			getline(ss, price, '|');
			getline(ss, bookAvailability, '|');
			
			transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);

			if(bookid == bookID)
			{  
				bookTitle = title;
				tempFile1 << bookID << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << "no";
				tempFile1 << "\n";	
				getch();		
					
			}
			else
			{
				tempFile1 << line;
				tempFile1 << "\n";
			} 
			  
		}

		readBookFile.close();
		
		tempFile1.close();
		
		remove("book.dat");
		rename("temp.dat", "book.dat");
		
	 }
	 else
	 {
	 	for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu(); 
	 }
	 
	 fstream updateBorrowerFile, tempFile2;
	 updateBorrowerFile.open("borrowers.dat", ios::in);
	 tempFile2.open("temp.dat", ios::out);
	 
	 if(updateBorrowerFile.is_open() && tempFile2.is_open())
	 {
	 	string line;
	 	while(getline(updateBorrowerFile, line))
	 	{
	 		istringstream ss(line);
			string borrowerID, brrName, brrPhoneNumber, brrAddress, brrJoinDate, brrCount;
			getline(ss, borrowerID, '|');
			getline(ss, brrName, '|');
			getline(ss, brrPhoneNumber, '|');
			getline(ss, brrAddress, '|');
			getline(ss, brrJoinDate, '|');
			
			transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
			
			if(borrowerid == borrowerID)
			{
				tempFile2 << borrowerID << "|" << brrName << "|" << brrPhoneNumber << "|" << brrAddress << "|" << brrJoinDate << "|" << (currentBorrowLimit+1);
				tempFile2 << "\n";
			}
			else
			{
				tempFile2 << line;
				tempFile2 << "\n";
			}
	    }
	    updateBorrowerFile.close();
		
		tempFile2.close();
		
		remove("borrowers.dat");
		rename("temp.dat", "borrowers.dat");
	    
	 }
	 else
	 {
	 	for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu(); 
	 }
	 
	 	 
	 fstream borrowRecord;
	 borrowRecord.open("borrowrecords.dat", ios::app);
	 
	 if(borrowRecord.is_open())
	 {
	 	borrowRecord << borrowerid << "|" << bookTitle << "|" << (1900 + issueDate.tm_year) << "-"  << (1 + issueDate.tm_mon) << "-" << (issueDate.tm_mday) << "|" << (1900 + dueDate.tm_year) << "-" <<  (1 + dueDate.tm_mon) << "-" <<  dueDate.tm_mday << "|" << fine << "|" << "-";
	 	borrowRecord << "\n";
	 	borrowRecord.close();
	 }
	 else
	 {
	 	for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu();
	 }
	 
	 cout << "\t\t\t\t---------------------------------------------------\n";
	 cout << "\t\t\t\t\tBorrower ID\t: " << borrowerid << "\n";
	 cout << "\t\t\t\t\tBook Title\t: " << bookTitle << "\n";
	 cout << "\t\t\t\t\tIssue Date\t: " << (1900 + issueDate.tm_year) << "-"  << (1 + issueDate.tm_mon) << "-" << issueDate.tm_mday << "\n";
	 cout << "\t\t\t\t\tDue Date\t: "  << (1900 + dueDate.tm_year) << "-" <<  (1 + dueDate.tm_mon) << "-" <<  dueDate.tm_mday << "\n";
	 cout << "\t\t\t\t\tFine\t\t: " << "-" << "\n";
	 cout << "\t\t\t\t\tReturn Date\t: " << "-" << "\n";
	 cout << "\t\t\t\t---------------------------------------------------\n";
	
	 for (int i = 0; i < 20; ++i) 
	 {
		std::cout << ' ';
	 }
	 
	 Sleep(4000);
	 
	 SetConsoleTextAttribute(hConsole, 0x2F);
	 cout << "\t\t\t\tBOOK ISSUED SUCESSFULY!!\n";
	 SetConsoleTextAttribute(hConsole, 0x7);
	 SetConsoleTextAttribute(hConsole, 0x37);
	 cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ISSUE AND RETURN MENU PANEL...";
	 SetConsoleTextAttribute(hConsole, 0x7);
	 getch();
	 system("cls");
	 issuseAndReturnBooks();
	 
	 
	
}
void acceptReturnedBooks(string bookID, string borrowerid, int currentBorrowLimit)
{
	float fineRate = 0.0;
	string bookTitle;
	float newFine;
	string bookIssueDate;
	string bookDueDate;
	
	// Return books 
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t\t===================\n";
	cout << "\t\t\t\t\t\t|| RETURN | BOOKS ||\n";
	cout << "\t\t\t\t\t\t===================\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	// Calculate the return date;
	time_t returnDate_time = time(0);
	
	// Get the return date from user
	int year, month, day;
    cout << "\t\t\t\tEnter Return Date (YYYY MM DD): ";
    cin >> year >> month >> day;
	
	// Get the return date
	tm returnDate = {};
	returnDate.tm_year = year - 1900;
    returnDate.tm_mon = month - 1;
    returnDate.tm_mday = day;
	
	// Read the fine rate file
	fstream readFineRate;
	readFineRate.open("finerate.dat", ios::in);
	
	if(readFineRate.is_open())
	{
		readFineRate >> fineRate;
	}
	else
	{
		for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu();
	}
		
	// Read the borrowin record file
	fstream borrowRecord, tempFile1;
	borrowRecord.open("borrowrecords.dat", ios::in);
	tempFile1.open("temp.dat", ios::out);
	
	if(borrowRecord.is_open() && tempFile1.is_open())
	{
		string line;
		while(getline(borrowRecord, line))
		{
			istringstream ss(line);
			string borrowerID, bookTitle, issueDate, dueDate, fine;
			getline(ss, borrowerID, '|');
			getline(ss, bookTitle, '|');
			getline(ss, issueDate, '|');
			getline(ss, dueDate, '|');
			getline(ss, fine, '|');
			
			transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
			
			// Get the issueDate and dueDate
			bookIssueDate = issueDate;
			bookDueDate = dueDate;

			
			if(borrowerid == borrowerID)
			{
				// Format the due date into tm format
				istringstream caldueDate(dueDate);
				tm dueDate_time = {};
				char discard;
				int year, month, day;
				
				caldueDate >> year >> discard >> month >> discard >> day;
				
				dueDate_time.tm_year = year - 1900;
				dueDate_time.tm_mon = month - 1;
				dueDate_time.tm_mday = day;
				
				//Normalize the due date using mktime
				time_t dueDate_time_t = mktime(&dueDate_time);
				
				// calculate the time difference
				double timeDifferece = difftime(dueDate_time_t, returnDate_time);
				int days = (int)timeDifferece / (60*60*24);
				
				if(days > 0)
				{
					newFine = days*fineRate;
					tempFile1 << borrowerid << "|" << bookTitle << "|" << issueDate << "|" << dueDate << "|" << newFine << "|" << (1900 + returnDate.tm_year) << "-"  << (1 + returnDate.tm_mon) << "-" << returnDate.tm_mday;
					tempFile1 << "\n";
				}
			
			}
			tempFile1 << borrowerid << "|" << bookTitle << "|" << issueDate << "|" << dueDate << "|" << 0 << "|" << (1900 + returnDate.tm_year) << "-"  << (1 + returnDate.tm_mon) << "-" << returnDate.tm_mday;
			tempFile1 << "\n";
			
		}
		borrowRecord.close();
		
		tempFile1.close();
		
		remove("borrowrecords.dat");
		rename("temp.dat", "borrowrecords.dat");
		
		
	}
	
	else
	{
		for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu();
	}
	
	fstream updateBorrowerFile, tempFile2;
	 updateBorrowerFile.open("borrowers.dat", ios::in);
	 tempFile2.open("temp.dat", ios::out);
	 
	 if(updateBorrowerFile.is_open() && tempFile2.is_open())
	 {
	 	string line;
	 	while(getline(updateBorrowerFile, line))
	 	{
	 		istringstream ss(line);
			string borrowerID, brrName, brrPhoneNumber, brrAddress, brrJoinDate, brrCount;
			getline(ss, borrowerID, '|');
			getline(ss, brrName, '|');
			getline(ss, brrPhoneNumber, '|');
			getline(ss, brrAddress, '|');
			getline(ss, brrJoinDate, '|');
			
			transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
			
			if(borrowerid == borrowerID)
			{
				tempFile2 << borrowerID << "|" << brrName << "|" << brrPhoneNumber << "|" << brrAddress << "|" << brrJoinDate << "|" << (currentBorrowLimit-1);
				tempFile2 << "\n";
			}
			else
			{
				tempFile2 << line;
				tempFile2 << "\n";
			}
	    }
	    updateBorrowerFile.close();
		
		tempFile2.close();
		
		remove("borrowers.dat");
		rename("temp.dat", "borrowers.dat");
	    
	 }
	 else
	 {
	 	for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu(); 
	 }
	
	
	//Open book.dat file put into the read mode to update the availability of the book
	 fstream readBookFile, tempFile3;
	 readBookFile.open("book.dat", ios::in);
	 tempFile3.open("temp.dat", ios::out);
	 
	 if(readBookFile.is_open() && tempFile3.is_open())
	 {
	 	string line;
	 	while(getline(readBookFile, line))
	 	{
			istringstream ss(line);
			string bookid, title, author, publisher, genre, price, bookAvailability;
			getline(ss, bookid, '|');
			getline(ss, title, '|');
			getline(ss, author, '|');
			getline(ss, publisher, '|');
			getline(ss, genre, '|');
			getline(ss, price, '|');
			getline(ss, bookAvailability, '|');
			
			transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);

			if(bookID == bookid)
			{  
			
				bookTitle = title;
				tempFile3 << bookID << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << "yes";
				tempFile3 << "\n";				
			}
			else
			{
				tempFile3 << line;
				tempFile3 << "\n";
			} 
			  
		}

		readBookFile.close();
		
		tempFile3.close();
		
		remove("book.dat");
		rename("temp.dat", "book.dat");
		
	 }
	 else
	 {
	 	for (int i = 0; i < 32; ++i) 
		{
    		std::cout << ' ';
		}
    	
		SetConsoleTextAttribute(hConsole, 0x4F);
		cout << "FILE DOES NOT FOUND\n";
		SetConsoleTextAttribute(hConsole, 7);
		SetConsoleTextAttribute(hConsole, 0x37);
		cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE LIBRARIAN MENU PANEL...\n";
		SetConsoleTextAttribute(hConsole, 0x7);
		getch();
		system("cls");
		librarianMenu(); 
	 }
	
	
	 // Display the borrowing records 
	cout << "\t\t\t\t---------------------------------------------------\n";
	cout << "\t\t\t\t\tBorrower ID\t: " << borrowerid << "\n";
	cout << "\t\t\t\t\tBook Title\t: " << bookTitle << "\n";
	cout << "\t\t\t\t\tIssue Date\t: " << bookIssueDate << "\n";
	cout << "\t\t\t\t\tDue Date\t: "  << bookDueDate << "\n";
	cout << "\t\t\t\t\tFine(Rs.)\t: " << newFine << "\n";
	cout << "\t\t\t\t\tReturn Date\t: " << (1900 + returnDate.tm_year) << "-"  << (1 + returnDate.tm_mon) << "-" << returnDate.tm_mday << "\n";
	cout << "\t\t\t\t---------------------------------------------------\n";   
	
	for (int i = 0; i < 20; ++i) 
	{
	std::cout << ' ';
	}
	
	Sleep(4000);
	
	SetConsoleTextAttribute(hConsole, 0x2F);
	cout << "\t\t\t\tBOOK RETURNED SUCESSFULY!!\n";
	SetConsoleTextAttribute(hConsole, 0x7);
	SetConsoleTextAttribute(hConsole, 0x37);
	cout << "\t\t\t\tPRESS ANY KEY TO RETURN TO THE ISSUE AND RETURN MENU PANEL...";
	SetConsoleTextAttribute(hConsole, 0x7);
	getch(); 
	system("cls");
	issuseAndReturnBooks();	
}

// modified part

void showAllBookDetails()
{
	int bookCount = 0;
	// Return books 
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t======================\n";
	cout << "\t\t\t\t\t|| VIEW | ALL BOOKS ||\n";
	cout << "\t\t\t\t\t======================\n";
	SetConsoleTextAttribute(hConsole, 7);


	fstream showBook;
	showBook.open("book.dat", ios::in);
	
	string line;
	while(getline(showBook, line))
	{
		istringstream ss(line);
		string bID,title,author,publisher,genre,price,availability;
		getline(ss, bID, '|');
		getline(ss, title, '|');
		getline(ss, author, '|');
		getline(ss, publisher, '|');
		getline(ss, genre, '|');
		getline(ss, price, '|');
		getline(ss, availability, '|');
		
		cout << "\t\t\t\tBook ID\t\t: " << bID << endl;
		cout << "\t\t\t\tTitle\t\t: " << title << endl;
		cout << "\t\t\t\tAuthor\t\t: " << author << endl;
		cout << "\t\t\t\tPublisher\t: " << publisher << endl;
		cout << "\t\t\t\tGenre\t\t: " << genre << endl;
		cout << "\t\t\t\tPrice\t\t: " << price << endl;
		cout << "\t\t\t\tAvailability\t: " << availability << endl;
		cout << "\t\t\t\t----------------------------------------------" << endl;
		
		bookCount += 1;
			
	}
	
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\tTotla Book Count: " << bookCount << endl;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	
	for (int i = 0; i < 32; ++i) 
	{
    	std::cout << ' ';
	}
	
	SetConsoleTextAttribute(hConsole, 0x2F);
	std::cout << "SEARCH COMPLETED";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n";
	SetConsoleTextAttribute(hConsole, 0x97);
	cout << "\t\t\t\tPLEASE ENTER ANY KEY TO RETUNRN TO LIBRARIN MENU.....";
	SetConsoleTextAttribute(hConsole, 7);
	getch();
	system("cls");
	librarianMenu();
	
}
