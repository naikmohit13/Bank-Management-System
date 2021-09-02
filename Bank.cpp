#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class Bank{
	private:
		int total;
		int id;
		typedef struct person_data
		{
			string name,address;
			string contact_no;
			long int cash,ID ;	
		}person_data;
		
		person_data person[100];
	
	public:
		Bank()
		{
			total = 0;
			id = 0;
		}
		
		void choice();
		void new_personal_data();
		void show_list();
		void show_person_data(int);
		void update_info();
		void delete_info();
		void search_info();
		void validate_id(int);
		void transactions();
		long int validate_amount(long int);
};
int main(){
	Bank bank1;	
	cout<<"\n\n\n\t\t\t\t----------Welcome to the Bank Management System----------\t\t\t\n\n\n";
	bank1.choice();
	return 0;
}

void Bank :: choice(){
	while(1){
		Sleep(2000);
		cout<<"\n\nChoose one option...\n"<<endl;
		cout<<"1. Create new account"<<endl;
		cout<<"2. View account holders' list"<<endl;
		cout<<"3. Update info of existing account"<<endl;
		cout<<"4. Check the details of existing account"<<endl;
		cout<<"5. Deleting existing account"<<endl;
		cout<<"6. For transactions"<<endl;
		cout<<"7. Exit"<<endl;
		
		char ch;
		cin>>ch;
		
		switch(ch){
			case '1':
				cout<<"Enter the data of person "<<endl;
				Bank :: new_personal_data();
				cout<<"\nAccount created successfully.";
				break;
			
			case '2':
				Bank :: show_list();
				break;
			
			case '3':
				Bank::update_info();
				break;
				
			case '4':
				Bank::search_info();
				break;
				
			case '5':
				Bank::delete_info();
				break;
			
			case '6':
				Bank::transactions();
				break;
				
			case '7':
				cout<<"Exiting...";
				Sleep(2000);
				exit(0);
				
			default:
				cout<<"Invalid Input"<<endl;
				
		}
	}
}

//Create new account
void Bank::new_personal_data(){
	cin.ignore();
	cout<<"Enter name: ";
	getline(cin,person[total].name);
//	cin.ignore();
//	cin>>person[total].name;
	cout<<"\nEnter address: ";
	getline(cin,person[total].address);
//	cin>>person[total].address;
	cout<<"\nEnter contact no. ";
	cin>>person[total].contact_no;
	cout<<"\nTotal cash to deposit: ";
	cin>>person[total].cash;
	person[total].ID = total+1;
//	cout<<"\nID for this acount is: "<<person[total].ID;
//	//	person[total].ID = total; id yet to set.
	total++;
		
}

//Check the details of existing account
void Bank::show_person_data(int num){
	cout<<"Name: "<<person[num].name<<endl;
//	cin>>person[total].name;
	cout<<"ID: "<<person[num].ID<<endl;
	cout<<"Address: "<<person[num].address<<endl;
	//cin<<person[total].address;
	cout<<"Contact no. "<<person[num].contact_no<<endl<<endl;
//	cin<<person[total].contact_no;
	cout<<"Cash balance: "<<person[num].cash<<endl;
//	cin<<person[total].cash;
}

//View account holders' list
void Bank::show_list(){
	cout<<"List of account holders:\n\n";
	cout<<"ID\tNAME"<<endl;
	for(int i=0;i<total;i++)
	{
//		cout<<"Data of a person\n"<<i+1<<endl;
//		single_person_data(i);
		cout<<person[i].ID<<"\t"<<person[i].name<<endl;		
	}
}

//Update info of existing account
void Bank::update_info(){
	
	cout<<"Enter the ID of the Account to update the info."<<endl;
	cin>>id;

	validate_id(id);
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
			cout<<"Previous data"<<endl;
			show_person_data(i);
			cout<<"\n\nEnter new data"<<endl;
			new_personal_data();
			break;
		}
	}
	cout<<"No record found for this ID"<<endl;
	
}

//Deleting existing account
void Bank::delete_info(){
	char ch;
	cout<<"Enter the ID of the Account to delete the info."<<endl;
	cin>>id;

	validate_id(id);
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
			cout<<"Previous data"<<endl;
			show_person_data(i);
			back:
			cout<<"\nAre you sure you want to delete this record?\nPress Y/N: ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
				{
					for(int j=i;j<total;j++){
						person[j].name=person[j+1].name;
						person[j].ID=person[j+1].ID;
						person[j].address=person[j+1].address;
						person[j].contact_no=person[j+1].contact_no;
					}
					total--;
					break;
				}
			else if(ch=='n' || ch=='N')
				break;
			else
			{
				cout<<"Invalid input!"<<endl;
				goto back;
			}
			
			
		}
		else{
			cout<<"No record found for this ID"<<endl;
		}
	}
	
}

void Bank::search_info(){
	cout<<"Enter ID of the Account to search"<<endl;
	cin>>id;
	validate_id(id);
	if(id>total)
		cout<<"No records found for this ID"<<endl;
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
			show_person_data(i);
			break;
		}	
	}
}

void Bank::validate_id(int id){
	while(id<=0)
	{
		cout<<"Invalid id! Please try again.\nID must be non-negative."<<endl;
		cin>>id;
	}
}

//For transactions
void Bank::transactions(){
	
	long int deposit,withdraw;
	char ch;
	cout<<"Enter the ID of the account holder to check trasactions."<<endl;
	cin>>id;
	
	validate_id(id);
	for(int i=0;i<total;i++)
	{
		if(id==person[i].ID)
		{
			show_person_data(i);
			cout<<"Press 1 to Deposit\n";
			cout<<"Press 2 to Withdraw\n";
			cin>>ch;
			switch(ch){
				
				case '1':
					cout<<"Enter the Amount to Deposit: ";
					cin>>deposit;
					deposit=validate_amount(deposit);
					person[i].cash+=deposit;
					cout<<"Cash deposited successfully.\nNew Account Balance is: "<<person[i].cash<<endl;
					break;
					
				case '2':
					cout<<"Enter the Amount to Withdraw: ";
					cin>>withdraw;
					withdraw=validate_amount(withdraw);
					while(withdraw>person[i].cash && withdraw>0){
						cout<<"Entered amount exceeds your account balance!\nYour Account balance is: "<<person[i].cash;
						Sleep(3000);
						cout<<"Enter new Amount: ";
						cin>>withdraw;
					}
					person[i].cash-=withdraw;
					cout<<"Cash withdrawn successfully.\nNew Account Balance is: "<<person[i].cash<<endl;
					break;
					
				default:
					cout<<"Invalid Input"<<endl;
					break;		
			}
		}
	}
	cout<<"No records corresponding to this ID found"<<endl;
}

long int Bank::validate_amount(long int amt){
	while(amt<=0){
		cout<<"Amount must be greater than 0. Try Again.\nRenter the Amount: ";
		cin>>amt;
	}
	return amt;
}

