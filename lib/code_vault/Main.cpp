#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

enum RequestType
{
   ZERO_BALANCE = 1,
   CREDIT_BALANCE,
   DEBIT_BALANCE,
   END
};

int getRequest(); 
bool shouldDisplay(int, double);
void outputLine(int, const string &, double); 

int main() 

{
   // ifstream constructor opens the file
   ifstream inClientFile("clients.txt", ios::in);

   // exit program if ifstream could not open file
   if (!inClientFile)
   {
      cerr << "File could not be opened" << endl;
      exit(EXIT_FAILURE);
   } // end if

   int account;    // the account number
   string name;    // the account owner's name
   double balance; // the account balance

   // get user's request (e.g., zero, credit or debit balance)
   int request = getRequest();

   // process user's request
   while (request != END) 
   {
      switch (request)
      {
      case ZERO_BALANCE:
         cout << "\nAccounts with zero balances:\n";
         break;
      case CREDIT_BALANCE:
         cout << "\nAccounts with credit balances:\n";
         break;
      case DEBIT_BALANCE:
         cout << "\nAccounts with debit balances:\n";
         break;
      } // end switch

      // read account, name and balance from file
      inClientFile >> account >> name >> balance;

      // display file contents (until eof)
      while (!inClientFile.eof())
      {
         // display record
         if (shouldDisplay(request, balance))
            outputLine(account, name, balance);
            
         // read account, name and balance from file
         inClientFile >> account >> name >> balance;
      } // end inner while

      inClientFile.clear();   // reset eof for next input
      inClientFile.seekg(0);  // reposition to beginning of file
      request = getRequest(); // get additional request from user
   }                          // end outer while

   cout << "End of run." << endl;
} // end main

// obtain request from user
int getRequest()
{
   int request; // request from user

   // display request options
   cout << "\nEnter request" << endl
        << " 1 - list accounts with zero balances" << endl
        << " 2 - list accounts with credit balances" << endl
        << " 3 - list accounts with debit balances" << endl
        << " 4 - end of run" << fixed << showpoint;

   do // input user request
   {
      cout << "\n? ";
      cin >> request;
   } while (request < ZERO_BALANCE && request > END);

   return request;
} // end function getRequest

// determine whether to display given record
bool shouldDisplay(int type, double balance)
{
   // determine whether to display zero balances
   if (type == ZERO_BALANCE && balance == 0)
      return true;

   // determine whether to display credit balances
   if (type == CREDIT_BALANCE && balance < 0)
      return true;

   // determine whether to display debit balances
   if (type == DEBIT_BALANCE && balance > 0)
      return true;

   return false;
} // end function shouldDisplay

// display single record from file
void outputLine(int account, const string &name, double balance)
{
   cout << left << setw(10) << account << setw(13) << name
        << setw(7) << setprecision(2) << right << balance << endl;
} // end function outputLine