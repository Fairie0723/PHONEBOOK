/* Description:
// This program will create a phone book and do 5 things:
// 1. Create account
// 2. Update account
// 3. Show account
// 4. Delete account
// 5. Exit the program
/////////////////////////////////////////////////////////////////*/


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Declaration of the Customer structure
struct Customer
{
// string name
   string name;
// string address
   string address;
// string city
   string city;
// string state
   string state;
// int zip
   int zip;
// string phone
   string phone;
};



// Function prototypes
void getAccountInfo(Customer &acc);
void showInfo(vector<Customer> &accounts);
void updateAccount(vector<Customer> &accounts, Customer account, int pos);
void deleteAccount(vector<Customer> &accounts, int pos);


int main()
{
	
   //necessary variable declaration
	int choice;
   //Customer acc;
   int pos;
   //structure Customer type variable
   Customer account;	
   //Vector of Customer structures
   vector<Customer> accounts;   
   
   cout << "========================================\n";
   cout << "Welcome to the Phone Book Management App\n";	
   cout << "========================================\n";

   do
   {
      // Display a menu.
      cout << "Please choose from the following:\n";
      cout << "1. Enter New Account Information\n";
      cout << "2. Change Account Information\n";
      cout << "3. Display All Account Information\n";
      cout << "4. Delete An Account\n";
      cout << "5. Exit\n";
      cout << "=====================================\n";
      cout << "What is your choice (1-5)?[ ]\b\b";
      
      // Get the user's choice.
      cin >> choice;
      
      // Validate the choice.
      do
    { 
        if (! (choice >=1 && choice <=5 ))
        {
            cout << "Invalid Input. Try Again." << endl;
            cout << "Enter a number from 1 to 5: ";
            cin >> choice;
        }
    } while (! (choice >=1 && choice <=5 ));
        
      // Perform the switch case.
      switch (choice)
      {
      		//case 1: Create new account and push back to the vector
			//Enter new account information. call the function  getAccountInfo()
			//Push the account to the vector accounts. call the function push_back()
         case 1: 
            getAccountInfo(account);
            accounts.push_back(Customer(account));
            break;
      		//case 2: Change an existing account.
			//Get the customer index number
			//Get the new account information. call the function getAccountInfo()
			//Update the account in the vector. call the function updateAccount()
         case 2:

         do
         {
            cout << "Customer number: "; cin >> pos;
            if (pos > accounts.size())
            {
               cout << "Error. Invalid customer number.\n";
               cout << "Please enter customer nummber: ";
               cin >> pos;
            }
               getAccountInfo(account);
               updateAccount(accounts, account, pos);
         } while (pos > accounts.size());
         
            
            break;
	   
      		//case 3: Display all account information. 
			//display all accounts information in the vector. call the function showInfo()
         case 3: 
            showInfo(accounts);
            break;
	   
      		//case 4: Delete an customer account  
			//Get the customer index number
			//Delete the account in the vector. call the function deleteAccount()
         case 4:
              do
         {
            cout << "Customer number: "; cin >> pos;
            if (pos > accounts.size())
            {
               cout << "Error. Invalid customer number.\n";
               cout << "Please enter customer nummber: ";
               cin >> pos;
            }
            deleteAccount(accounts, pos);
               
         } while (pos > accounts.size());
               
            
            break;
			
      		//case 5: Quit the program
         case 5:
            cout << "Thank you! See you again!\n";
            break;

      }
         
   } while (choice != 5);

   return 0;
}

//********************************************************
// Function: getAccountInfo                                      
// This function gets account information from the user  
// and stores it in the parameter acc, which is a    
// structure reference variable.         
//********************************************************

void getAccountInfo(Customer &acc)
{
    //Get the customer name
       cin.ignore();
      
      //cout << "Please enter the following:\n";
      cout << "First and Last name:\n";
      getline (cin, acc.name);

      // Get the customer's address.
      cout << "Address:\n";
      getline (cin, acc.address);

   // Get the customer's city.
      cout << "City:\n";
      getline (cin, acc.city);

   // Get the customer's state.
      cout << "State:\n";
      getline (cin, acc.state);
   
   // Get the customer's ZIP code.
      cout << "Zip Code:\n";
      cin >> acc.zip;

      cin.ignore();

   // Get the customer's phone number.
      cout << "Phone Number:\n";
      getline (cin, acc.phone);

}


//************************************************************
// Function showInfo                                         
// This function displays all customer account's name, address,      
// city, state, zip code and phone number 
// The information is passed into the Customer vector 
// accounts
//************************************************************

void showInfo(vector<Customer> &accounts)
{
  
   int pos = 0;
      cout << left;
      cout << "=====================================================================================================\n";
      cout << setw(10) << "Index" << setw(20) << "Customer name" << setw(25)
        << "Customer address" << setw(10) << "City" << setw(11)
        << "  State" << setw(11)  << "ZIP code" << setw(20) << "Telephone" << endl;
      cout << "=====================================================================================================\n";

      
      for (int i = 0; i < accounts.size(); i++)
      {
         cout << left;
         cout << setw(10) << pos;
         cout << setw(20) << 
         accounts[i].name <<  setw(25) <<
         accounts[i].address << setw(12) <<  
         accounts[i].city <<   setw(9) <<
         accounts[i].state <<  setw(11) <<
         accounts[i].zip <<
         accounts[i].phone << endl;
         pos++;
      
      }

}

//************************************************************
// Function updateAccount                                       
// This function updates the  selected customer account's name, 
// address, city, state, zip code and phone number 
// The new account information is passed in parameter acc
// The index location in the vector is passed in parameter pos
//************************************************************
void updateAccount(vector<Customer> &accounts, Customer account, int pos)
{
   
       
         accounts[pos].name = account.name;
         accounts[pos].address = account.address; 
         accounts[pos].city = account.city; 
         accounts[pos].state = account.state; 
         accounts[pos].zip = account.zip; 
         accounts[pos].phone = account.phone; 
        
     


   cout << "Account has been updated successfully!\n";
	   
}


//************************************************************
// Function deleteAccount                                    
// This function delete the selected customer account from the vector 
// The index location of the selected account is passed in parameter pos
//************************************************************
void deleteAccount(vector<Customer> &accounts, int pos)
{
		accounts.erase(accounts.begin()+pos); 
      cout << "Your account was deleted successfully!\n";
}
