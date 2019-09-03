#include<iostream>
#define sas 50
#define sba 50
using namespace std;
int flag=0; 
int sid=0; 
 class Lib{

			public :
		//	private :	
						
					string record[sas];
					string student[sas] = { "shafqat" , "talha" , "ata" , "tehrim" , "akash" , "null" };
					string booksnames[sba] = {"Islamiat   ", "G. Science " , "Mathematics" , "Programming" , "Physics    " , "null"};
					int token[sas] = {1 , 1 , 1 , 1 , 1};
					int collection[sba] = { 10 , 10 , 10 , 10 , 10 , 0 } ;
			void editstudent(){
				int snu;
				string editedstudentname;
				cout<<" which student's name want you to edit ?\n";
				for(int i=0;student[i]!="null";i++)
							{
								cout<<i+1<<":"<<student[i]<<endl;
							}
				cin>>snu;
				cout<<" enter new name for student : "<<student[snu-1]<<endl;
				cin>>editedstudentname;
				student[snu-1]=editedstudentname;
				cout<<"Done !\n";		
			}
			void removestudent(){
				int rs;
				cout<<" which student you want to remove \n";
				
				for(int i=0;student[i]!="null";i++)
							{
								cout<<i+1<<":"<<student[i]<<endl;
							}
				cin>>rs;
					for(int i=rs-1 ; student[i]!="null" ; i++){
						student[i]=student[i+1];
					}	
					cout<<" student name has been deleted succesfullu !\n";	
			}
			void addstudent(){
				int already=0;
				string newname;
				cout<<"enter name of new student\n";
				cin>>newname;
				for(int i=0 ; student[i]!="null" ; i++)
				{	
					if(newname==student[i]){
						already=1;
						break;
					}
				}
				if(already){
					cout<<" student is already registered\n";
				}
				else{
				for(int i=0 ; student[i]!="null" ; i++){
				
					if(student[i+1]=="null")
					{
						student[i+1]=newname;
						student[i+2]="null";
						token[i+1]=1;
						cout<<" new student : "<<newname<<" has been added succesfully\n";
						break;
					}
				}
				}
			}
			void modifystudents(){
					int cho;
					cout<<"1. for add new student \n2. for remove registered student \n3. for edit current student name \n";
					cin>>cho;
					switch(cho)
					{
						case 1: 
								addstudent();
								break;
						case 2:
								removestudent();
								break;
						case 3:
								editstudent();
								break;
						default:
								system("cls");
								cout<<" invalid choice \n";
								modifystudents();						
					}
			}
			
			void editbook(){
									int bookid;
									string newnameofbook;
									cout<<" which book you want to edit \n";
									
									for(int a=0 ; booksnames[a]!="null" ; a++)
									{
										cout<<a+1<<". "<<booksnames[a]<<endl;
									}
									cin>>bookid;
									cout<<" write new book name to replace \n";
									cin>>newnameofbook;
									booksnames[bookid-1]=newnameofbook;
									cout<<" Done !\n";
									

			}
			void removebook(){
									int bookid;
									cout<<" which book you want to remove ?\n";
									int c=0;
									while(booksnames[c]!= "null")
									
									{
										cout<<c+1<<". "<<booksnames[c]<<endl;
										c++;
									}
										cin>>bookid;
										char sure;
										cout<<" are you sure to delete the book : "<<booksnames[--bookid]<<" ? ( y/n)\n";
										cin>>sure;
										if(sure=='y' || sure=='N'){
											//booksnames[bookid]=NULL;
											int d=bookid;
											while(booksnames[d] != "null")
											{
												booksnames[d]=booksnames[d+1];
												d++;
											}
											cout<<" the book has been deleted succesfully \n";
										}	else if(sure=='n' || sure=='N'){
											cout<<" the book is not deleted \n ";
											}
										else {
											cout <<" you have selected invalid option \n";
										}	
								
									}
			void addbook(){
									string newbookname;
									int already;
									int q;
									cout<<" write name of new book to add it into the list \n";
									cin>>newbookname;
									cout<<" Quantity : ";
									cin>>q;
									for(int b=0 ; b<sba ; b++){
										if(newbookname==booksnames[b])
										{
											already=1;
											break;
										}
										else
										{
											already=0;
										}
									}		
									if(already)
									{
										cout<<" sorry book is already available so you can not add the same book more than one time \n";
									}
									else{
										for(int e=0 ; e<sba ; e++)
										{
											if(booksnames[e]=="null"){
												booksnames[e]=newbookname;
												booksnames[e+1]="null";
												collection[e]=q;
										cout<<" new book : "<<newbookname<<" hase been succesfully added \n";
												break;
											}
										}
									
										
									}
							}
			void bookmodify(){
										int opt;
										cout<<" 1. for edit book \n 2. for add new book \n 3. for remove book\n";
										cin>>opt;
										switch(opt)
							{
									case 1:
										editbook();
										break;
									case 2:
										addbook();
										break;
									case 3: 
									removebook();
									break;
							default :
										cout<<" invalid option \n";
										bookmodify();				
											
						}
			}
				
			bool isReg()
			{	int check=0;
				string user;
					cout<<"Enter Student name \n( Note : write name in lower case letters ) \n";
					cin>>user;
				for(int i=0 ; i<5 ;i++){
		
						if(user==student[i])
					{
						sid=i;
						//return sid;
						check=1;
						i=5;
						break;
					}
					else{
						check=0;
					}
				}
				if(check!=1)
				{
				cout<<"Sorry you are not a registered student \n";		
				librarianmenu();
				}
		
			}
				
				void bookissue(int sid)
					{
						int bookid;
						cout<<"Which book you want to be issued ? \n";
						viewbooks();
						cin>>bookid;
							system("cls");
							dec();
							cout<<endl<<endl<<endl;
					if(collection[--bookid]==0){
						cout<<" Sorry we have no more your desire books to issue \n";
					}
					else if(token[sid]!=1)
					{
						cout<<" Sorry you already have one book to return \n";
					}
					
					else{
						 cout<<" The book : "<<booksnames[bookid]<<" has been issued on the name of : "<<student[sid]<<endl;
						 collection[bookid]--;
						 token[sid]=0;
						 record[sid]=booksnames[bookid];
					}
						
					
					
				}
				
				void view()
				{
					char a;
					cout<<"1. View Registered Students\n2. View Books with Quantity \n";
					cin>>a;
					switch(a)
					{
						case '1':
							for(int i=0;student[i]!="null";i++)
							{
								cout<<i+1<<":"<<student[i]<<endl;
							}
							break;
							case '2':
								system("cls");
								dec();
								cout<<"Book    :  Quantity \n";
								for(int i=0;booksnames[i]!="null" ;i++)
							{
								cout<<i+1<<":"<<booksnames[i]<<"  :  "<<collection[i]<<endl;
							}
							break;
					}
					
				}
				
			void returnbook(int sid)
			
			{   int whichbook;
				if(token[sid]==1){
					cout<<"You dont have to return any book \n";
					
				}
				else
				cout<<"Thanks "<<student[sid]<<" for returning book : "<<record[sid]<<" on time \n";
				
				for(int i=0 ; booksnames[i]!="null" ; i++)
				{
					if(record[sid]==booksnames[i])
					{
						whichbook=i;
						break;
					}
				}
				
				collection[whichbook]++;
				token[sid]=1;
				record[sid]="null";
			
			}
			void viewbooks()
			{
				
								system("cls");
								dec();
								cout<<"Book    :  Quantity \n";
								for(int i=0; booksnames[i]!="null" ;i++)
							{
								cout<<i+1<<":"<<booksnames[i]<<"  :  "<<collection[i]<<endl;
							}
			}
			void dec(){
		cout<<" ******************************************************************\n";
		cout<<" ********** Welcome to Student Library Management System  *********\n";
		cout<<" ******************************************************************\n";
		}
		////////////////////////
		void librarianmenu()
		{
			int choice,bookid,A;
				
				B:	
				cout<<"\n1: for issue \n2: for return book \n3: View\n4: for modify books \n5: for modify students\n6: for logout \n7: for exit \n";
					cin>>choice;	
					system("cls");
					dec();
					switch(choice)
				{			case 1:
								isReg();
								bookissue(sid);
								goto B;
							
							case 2:
								isReg();
								returnbook(sid);
								goto B;
							case 3:
								view();
								goto B;
							case 4: 
								bookmodify();
								goto B;
							case 5: 
								modifystudents();
								goto B;	
							case 6:		
								cout<<" Succesfully Logout !\n";
								librarian_login();
							case 7:
								system("cls");
								cout<<" Thank You for using Our Software ! \n \t see you soon \n";
								exit(0);								
							default:
							cout<<"Wrong Choice\n";
							goto B;
				}
	
			}
		/////////////////
		int librarian_login()
		{	string adminuser;
		 	string adminpass;
			l:
			cout<<"\t \t \t Login \n";
			cout<<" username : ";
			cin>>adminuser;
			cout<<" password : ";
			cin>>adminpass;
			if(adminuser== "admin" && adminpass=="admin"){
				system("cls");
				dec();
				cout<<" * * *  Welcom Admin * * * \n";
				librarianmenu();
			}
			
			else {
				cout<<" user or pass or both incorrect \n";
				goto l;
			}
		}
		

};

int main()
{
	Lib obj;
	obj.dec();
	obj.librarian_login();
	system("pause");
		return 0;
		}
			
