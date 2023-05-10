#include <iostream>
#include <fstream>           /*LIBRARY FOR FILE READ & WRITE*/
#include <string.h>
#include <stdio.h>           /*LIBRARY FOR FILES*/
#include <iomanip>           //LIBRARY FOR MANIPULATORS
using namespace std;
struct account               //Structure for user's account information   
{
	char account_number[15];
	char name[20];
	char city[20];
	char state[20];
	int zip = 0;
	char phone_number[15];
	double account_balance = 0.0;
	char date[10];
};
void enter_Record(account);              //PROTOTYPES
void search_Record(account);
void modify_Record(account);
void delete_Account(account);
void view_All_Customers(account);
void balance_Inquiry(account);
void deposit_Amount(account);
void withdraw_Amount(account);
void transfer_Amount(account);
int main()
{
	account members;
	int choice;        //VARIABLE TO STORE USER INPUT FROM (1-10)
	bool resp = true;    //VARIABLE TO CONTROL WHILE LOOP
	do
	{
		cout << "\t\tMAIN MENU" << endl << endl;
		cout << "[1] Enter New Record :" << endl;
		cout << "[2] Search Record :" << endl;
		cout << "[3] Modify Record :" << endl;
		cout << "[4] Delete Record :" << endl;
		cout << "[5] View All Costumers List :" << endl;
		cout << "[6] Balance Inquiry :" << endl;
		cout << "[7] Depsoit Amount :" << endl;
		cout << "[8] Withdraw Amount :" << endl;
		cout << "[9] Transfer Amount To Other Account :" << endl;
		cout << "[0] Exit :" << endl << endl;
		cout << "Enter your choice :"; 
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			enter_Record(members);
			break;
		case 2:
			system("cls");
			search_Record(members);
			break;
		case 3:
			system("cls");
			modify_Record(members);
			break;
		case 4:
			system("cls");
			delete_Account(members);
			break;
		case 5:
			system("cls");
			view_All_Customers(members);
			break;
		case 6:
			system("cls");
			balance_Inquiry(members);
			break;
		case 7:
			system("cls");
			deposit_Amount(members);
			break;
		case 8:
			system("cls");
			withdraw_Amount(members);
			break;
		case 9:
			system("cls");
			transfer_Amount(members);
			break;
		case 0:
			resp = false;
			break;
		default:
			cout << "You Entered Invalid Input" << endl;
		}
	} while (resp);
	cout << "T H A N K   Y O U !" << endl;
	system("pause");
	return 0;
}
void enter_Record(account A)
{
	ofstream fout;
	fout.open("abc.dat", ios::binary | ios::app);
	cout << "Enter Account Number: ";
	cin.ignore();
	cin.getline(A.account_number, 15);
	cout << "Enter Name: ";
	cin.getline(A.name, 20);
	cout << "Enter City: ";
	cin.getline(A.city, 20);
	cout << "Enter State: ";
	cin.getline(A.state, 20);
	cout << "Enter Zip: ";
	cin >> A.zip;
	cout << "Enter Phone Number: ";
	cin.ignore();
	cin.getline(A.phone_number, 15);
	cout << "Enter Account Balance: ";
	cin >> A.account_balance;
	cout << "Enter Date: ";
	cin.ignore();
	cin.getline(A.date, 10);
	fout.write((char*)&A, sizeof(A));
	cout << "\n\n DATA HAS BEEN SAVED TO FILE...!\n" << endl;
	fout.close();
}
void view_All_Customers(account E)
{
	ifstream fileread("abc.dat", ios::binary);
	if (!fileread)
	{
		cout << "Error in opening file" << endl;
		exit(1);
	}
	cout <<
		"----------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	cout << left << setw(18) << "ACCOUNT NUMBER" << left << setw(18) << "NAME"
		<< left << setw(18) << "CITY" << left << setw(18) << "STATE" << left <<
		setw(18) << "ZIP" << left << setw(18) << "PHONE NUMBER" << left <<
		setw(18) << "BALANCE" << left << setw(18) << "DATE" << endl;
	cout <<
		"----------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	while (fileread.read((char*)&E, sizeof(E)))
	{
		cout << left << setw(18) << E.
			account_number << left << setw(18) << E.name << left << setw(18) <<
			E.city << left << setw(18) << E.state << left << setw(18) << E.
			zip << left << setw(18) << E.phone_number << left << setw(18) <<
			E.account_balance << left << setw(18) << E.date << endl;
	}
	fileread.close();
}
void search_Record(account B)
{
	char a;
	bool found = 0;
	char acc_num[15];
	ifstream fileread("abc.dat", ios::binary);
	if (!fileread)
	{
		cout << "Error in opening file!!!" << endl;
	}
label1:
	cout << "Enter Account Number ";
	cin.ignore();
	cin.getline(acc_num, 15);
	while (!fileread.eof())
	{
		fileread.read((char*)&B, sizeof(B));
		if (strcmp(acc_num, B.account_number) == 0)
		{
			cout <<
				"----------------------------------------------------------------------------------------------------------------------------------------"
				<< endl;
			cout << left << setw(18) << "ACCOUNT NUMBER" << left << setw(18)
				<< "NAME" << left << setw(18) << "CITY" << left << setw(18) <<
				"STATE" << left << setw(18) << "ZIP" << left << setw(18) <<
				"PHONE NUMBER" << left << setw(18) << "BALANCE" << left <<
				setw(18) << "DATE" << endl;
			cout <<
				"----------------------------------------------------------------------------------------------------------------------------------------"
				<< endl;
			cout << left << setw(18) << B.account_number << left << setw(18)
				<< B.name << left << setw(18) << B.
				city << left << setw(18) << B.state << left << setw(18) << B.
				zip << left << setw(18) << B.phone_number << left << setw(18) <<
				B.account_balance << left << setw(18) << B.date << endl;
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		cout << "Sorry Record Not Found!!!!" << endl;
		cout << "Want To Re-Enter Account Number? (y/n)";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto label1;
		}
	}
	fileread.close();
}
void modify_Record(account E)
{
	char a;
	bool found = 0;
	char accnum[15];
	account D;
	fstream freadwrite("abc.dat", ios::binary | ios::in | ios::out);
	if (!freadwrite)
	{
		cout << "error" << endl;
	}
	else
	{
	label1:
		cout << "Enter Account Number : ";
		cin.ignore();
		cin.getline(accnum, 15);
		while (!freadwrite.eof())
		{
			freadwrite.read((char*)&E, sizeof(E));
			if (strcmp(accnum, E.account_number) == 0)
			{
				cout << "Enter Name : ";
				cin.getline(D.name, 20);
				cout << "Enter City : ";
				cin.getline(D.city, 20);
				cout << "Enter State : ";
				cin.getline(D.state, 20);
				cout << "Enter Zip : ";
				cin >> D.zip;
				cout << "Enter Phone Number : ";
				cin.ignore();
				cin.getline(D.phone_number, 15);
				cout << "Enter Balance : ";
				cin >> D.account_balance;
				cout << "Enter Date : ";
				cin.ignore();
				cin.getline(D.date, 10);
				freadwrite.seekp(-120, ios::cur);
				freadwrite.write((char*)&D, sizeof(D));
				freadwrite.close();
				found = 1;
				cout << "YOUR RECORD HAS MODIFIED SUCCESSFULLY" << endl;
				break;
			}
		}
		if (found == 0)
		{
			cout << "Sorry Record Not found!!!" << endl;
			cout << "Want To Re-Enter Account Number? (y/n)?" << endl;
			cin >> a;
			if (a == 'y' || a == 'Y')
			{
				goto label1;
			}
		}
	}
}
void balance_Inquiry(account F)
{
	char a;
	bool found = 0;
	char acc_num[15];
	ifstream fileread("abc.dat", ios::binary);
	if (!fileread)
	{
		cout << "Error in opening file!!!" << endl;
	}
label1:
	cout << "Enter Account Number ";
	cin.ignore();
	cin.getline(acc_num, 15);
	while (!fileread.eof())
	{
		fileread.read((char*)&F, sizeof(F));
		if (strcmp(acc_num, F.account_number) == 0)
		{
			cout << "Account Balance = PKR ";
			cout << F.account_balance << endl;
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		cout << "Sorry Record Not Found!!!!" << endl;
		cout << "Want To Re-Enter Account Number? (y/n)";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto label1;
		}
	}
	fileread.close();
}
void delete_Account(account D)
{
	char a;
	bool found = 0;
	char acc_num[15];
label1:
	ifstream fileread("abc.dat", ios::binary);
	ofstream filewrite("temp.dat", ios::binary);
	if (!fileread || !filewrite)
	{
		cout << "Error in opening file!!!" << endl;
	}
	cout << "Enter Account Number ";
	cin.ignore();
	cin.getline(acc_num, 15);
	while (!fileread.eof())
	{
		fileread.read((char*)&D, sizeof(D));
		if (strcmp(acc_num, D.account_number) != 0)
		{
			filewrite.write((char*)&D, sizeof(D));
		}
		else
		{
			found = 1;
		}
	}
	if (found == 0)
	{
		cout << "Sorry Record Not Found!!!!" << endl;
		cout << "Want To Re-Enter Account Number? (y/n)";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto label1;
		}
	}
	filewrite.close();
	fileread.close();
	remove("abcd.dat");
	rename("abcd.dat","temp.dat" );
	cout << "RECORD DELETED SUCCESSFULLY" << endl;

}
void deposit_Amount(account G)
{
	double amount = 0;
	char a;
	bool found = 0;
	char acc_num[15];
	fstream fileread("abc.dat", ios::binary | ios::in | ios::out);
	if (!fileread)
	{
		cout << "Error in opening file!!!" << endl;
	}
label1:
	cout << "Enter Account Number ";
	cin.ignore();
	cin.getline(acc_num, 15);
	while (!fileread.eof())
	{
		fileread.read((char*)&G, sizeof(G));
		if (strcmp(acc_num, G.account_number) == 0)
		{
			cout << "Enter Amount: ";
			cin >> amount;
			G.account_balance += amount;
			fileread.seekp(-24, ios::cur);
			fileread.write((char*)&G.account_balance,
				sizeof(G.account_balance));
			found = 1;
		}
	}
	if (found == 0)
	{
		cout << "Sorry Record Not Found!!!!" << endl;
		cout << "Want To Re-Enter Account Number? (y/n)";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto label1;
		}
	}
	cout << "AMOUNT DEPOSITED SUCCESSFULLY" << endl;
	fileread.close();
}
void withdraw_Amount(account H)
{
	double amount = 0;
	char a;
	bool found = 0;
	char acc_num[15];
	fstream fileread("abc.dat", ios::binary | ios::in | ios::out);
	if (!fileread)
	{
		cout << "Error in opening file!!!" << endl;
	}
label1:
	cout << "Enter Account Number ";
	cin.ignore();
	cin.getline(acc_num, 15);
	while (!fileread.eof())
	{
		fileread.read((char*)&H, sizeof(H));
		if (strcmp(acc_num, H.account_number) == 0)
		{
			do
			{
				cout << "Enter Amount:" << endl;
				cout << "PRK ";
				cin >> amount;
			} while (amount > H.account_balance);
			H.account_balance -= amount;
			fileread.seekp(-24, ios::cur);
			fileread.write((char*)&H.account_balance,
				sizeof(H.account_balance));
			found = 1;
		}
	}
	if (found == 0)
	{
		cout << "Sorry Record Not Found!!!!" << endl;
		cout << "Want To Re-Enter Account Number? (y/n)";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto label1;
		}
	}
	cout << "AMOUNT WITHDRAWED SUCCESSFULLY" << endl;
	fileread.close();
}
void transfer_Amount(account E)
{
	double Amount = 0, Temp, Temp2;
	char Acc_Num[15], Acc_Num1[15];
	bool Found = 0, Find = 0;
	char a, b;
	fstream freadwrite("abc.dat", ios::binary | ios::in | ios::out);
	if (!freadwrite)
	{
		cout << "Error in opening file" << endl;
	}
	else
	{
	label1:
		cout << "Enter Your Account Number : ";
		cin.ignore();
		cin.getline(Acc_Num, 15);
		while (!freadwrite.eof())
		{
			freadwrite.read((char*)&E, sizeof(E));
			if (strcmp(Acc_Num, E.account_number) == 0)
			{
				do
				{
					cout << "Enter Amount To Transfer : " << endl;
					cout << "PRK ";
					cin >> Amount;
				} while (Amount > E.account_balance);
				Temp = E.account_balance;
				Temp -= Amount;
				freadwrite.seekp(-24, ios::cur);
				freadwrite.write((char*)&Temp, sizeof(Temp));
				cout << "AMOUNT DEDUCTED FROM YOUR ACCOUNT" << endl;
				Found = 1;
				break;
			}
		}
		if (Found == 0)
		{
			cout << "SORRY RECORD NOT FOUND!!!!" << endl;
			cout << "Want To Re-Enter Account Numebr? (y/n)?";
			cin >> a;
			if (a == 'y' || a == 'Y')
			{
				goto label1;
			}
		}
	label2:
		cout << "Enter Account Number To Which You Want To Transfer Amount : ";
		cin.ignore();
		cin.getline(Acc_Num1, 15);
		freadwrite.seekg(0);
		while (!freadwrite.eof())
		{
			freadwrite.read((char*)&E, sizeof(E));
			if (strcmp(Acc_Num1, E.account_number) == 0)
			{
				Temp2 = E.account_balance;
				Temp2 += Amount;
				freadwrite.seekp(-24, ios::cur);
				freadwrite.write((char*)&Temp2, sizeof(Temp2));
				cout << "AMOUNT TRANSFERRED SUCCESSFULLY" << endl;
				Find = 1;
				break;
			}
		}
		if (Find == 0)
		{
			cout << "SORRY RECORD NOT FOUND!!!!" << endl;
			cout << "Want To Re-Enter Account Numebr? (y/n)?";
			cin >> b;
			if (b == 'y' || b == 'Y')
			{
				goto label2;
			}
		}
	}
	freadwrite.close();
}
//End