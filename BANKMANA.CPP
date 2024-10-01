#include<iostream.h>
#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
//using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
       public:
		void create_account();
		void show_account() const;
		void modify();
		void dep(int);
		void draw(int);
		void report() const;
		int retacno() const;
		int retdeposit() const;
		char rettype() const;
};
void account::create_account()
{
	//system("clear");
	cout<<"\n\t\t\tEnter the Account No.:";
	cin>>acno;
	cout<<"\n\n\t\t\tPlease Enter the Name of the Account holder Here:";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\t Enter Typeof the Account (C/S):";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\t Enter the Intial amount:";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}
void account::show_account() const
{
	cout<<"\n\t\t\tAccount No.:"<< acno;
	cout<<"\n\t\t\t Account Holder Name:";
	cout<<name;
	cout<<"\n\t\t\tType of Account:"<< type;
	cout<<"\n\t\t\tBalance Amount:"<<deposit;
}
void account::modify()
{
	cout<<"\n\t\t\tAccount No.:"<<acno;
	cout<<"\n\t\t\tModify Account Holder Name:";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account :";
	cin>>type;
	type = toupper(type);
	cout<<"\n\t\t\tModify Balance amount:";
	cin>>deposit;
}
void account::dep(int x)
{
	deposit+=x;
}
void account::draw(int x)
{
	deposit-=x;
}
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}
int account::retacno() const
{
	return acno;
}
int account::retdeposit() const
{
	return deposit;
}
char account::rettype() const
{
	return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int ,int);

int main()
{
	char ch;
	int num;
	do
	{
		//system("CLS");
		cout<<"\n\n\t\t\t\t========================\n";
		cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout<<"\n\t\t\t\t========================\n";
		cout<<"\t\t\t\t   :: MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSELECT Your Option(1-8): ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				write_account();
				break;
			case 2:
			      //	system("CLS");
				cout<<"\n\n\t\t\tEnter The Account No. : ";	cin>>num;
				deposit_withdraw(num,1);
				break;
			case 3:
			      //	system("CLS");
				cout<<"\n\n\t\t\tEnter The Account No.";        cin>>num;
				deposit_withdraw(num,2);
				break;

			case 4:
				//system("CLS");
				cout<<"\n\n\t\t\tEnter The Account No.";        cin>>num;
				display_sp(num);
				break;

			case 5:
				display_all();
				break;
			case 6:
				//system("CLS");
				cout<<"\n\n\t\t\tEnter The Account No.";        cin>>num;
				delete_account(num);
				break;
			case 7:
			       //	system("CLS");
				cout<<"\n\n\t\t\tEnter The Account No.";        cin>>num;
				modify_account(num);
				break;

			case 8:
			    //	system("CLS");
				cout<<"\n\n\t\t\tBrought To You By Ahmd And Abdul Rehman";
				break;
			     default:cout<<"\a";
		}
		cin.ignore();
		cin.get();
	     }while(ch != '8');
	     return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary || ios::app);
	ac.create_account();
       //	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n,bool))
	{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Keys...":
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS \n";
	while(inFile.read(reinterpret_cast<char*> (&ac),sizeof(account))
	{
	if(ac.retacno() == n)
	{
		ac.show_account();
		cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
		ac.modify();
		int pos=(-1)*static_cast<int>(sizeof(account));
		File.seekp(pos,ios::cur);	//fincallat1353
		File.write(reinterpret_cast<char*> (&ac),sizeof(account));
		cout<<"\n\n\t\t\tRecord Updated";
		found=true;
	}
	}
	File.close();
	if(found ==false)
	cout<<"\n\n\t\t\tRecord Not Found";
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char*> (&ac),sizeof(account)))
	{
		if(ac.retacno() !=n)
		{
			outFile.write(reinterpret_cast<char*> (&ac),sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted..";
}
void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"========================================\n";
	cout<<"A/c no.     NAME         Type Balance\n";
	while(inFile.read(reinterpret_cast<char*> (&ac),sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}
void deposit_withdraw(int n,int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary | ios::in | ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char*> (&ac),sizeof(account));
		if(ac.retacno() ==n)
		{
			ac.show_account()
			if(option ==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw:";
				cin>>amt;
				ac.dep(amt);
			}
			if(option ==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit() -amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			 }
			 int pos=(-1)*static_cast<int>(sizeof(ac));
			 File.seekp(pos,ios::cur);	//fin1353
			 File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			 cout<<"\n\n\t\t\tRecord Updated";
			 found= true;
		}
		File.close();
		if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}






