#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
static int n=100;
class book
{char mov[20];
 char name[20];
 int nos;
 int movt;
 long double bookid;
 float price;
 public:
	void booka();
	void cancel();
	void view();
	friend void modify();
	double retbookid()
		{
			return bookid;
		}
	int retnos()
		{
			return nos;
		}
	char*retmov()
		{
			return mov;
		}
	void display()
		{
			cout<<"Movie name  ="<<mov<<"\n";
			cout<<"Name        ="<<name<<"\n";
			cout<<"no of seats ="<<nos<<"\n";
			cout<<"Movie time  ="<<movt<<"\n";
			cout<<"Booking ID  ="<<bookid<<"\n";
			cout<<"Total Amount="<<price<<"\n";
		}
 }b,cee,s;
void mainmenu();
void main()
	{
		clrscr();
		mainmenu();
		getch();
	}
void mainmenu()

	{
		int choice;
		do
		       {
			cout<<"Welcome to enigma"<<"\n";
			cout<<"................."<<"\n";
			cout<<"1:book "<<"\n";
			cout<<"2:cancel ticket\n";
			cout<<"3:view booking \n";
			cout<<"4:modify booking\n";
			cin>>choice;
			switch(choice)
				{
					case 1:b.booka();
						break;
					case 2:b.cancel();
						break;
					case 3:b.view();
						break;
					case 4:modify();
						break;
					case 5:cout<<"thank you for choosing enigma.goodbye\n";
					       exit(0);
				}
			}while(choice<5);
	}
int seat()
	{       int c2=0;
		fstream book;
		book.open("book.dat",ios::app|ios::binary);
		if(!book)
			{
				cout<<"our servers are currently down.sorry for the inconvienience\n";
				exit(0);
			}
		while(book.read((char*)&cee,sizeof(cee)))
			{
				if((strcmp(cee.retmov(),b.retmov())==0))
					{
						c2+=cee.retnos();
					}
			}
		book.close();
		return(c2);
	}
void write()
	{
			fstream book;
			book.open("book.dat",ios::app|ios::binary);
			if(!book)
				{
					cout<<"our servers are currently down.sorry for the inconvienience\n";
					exit(0);
				}
			book.write((char*)&b,sizeof(b));
			book.close();
	}
void book::booka()
	{       clrscr();
		cout<<"booking menu\n";
		cout<<"1:book a movie\n";
		cout<<"2:go back to menu\n";
			ifstream en;
		en.open("enigma.txt",ios::in);

			char ch;
		while(en)
			{
				en.get(ch);
				cout<<ch;
			}
		int c;
		cout<<"\nenter choice\n";
		cin>>c;
		switch(c)
			{
				case 1:break;
				case 2:mainmenu();
			}

		ifstream f;
		f.open("movie.txt",ios::in);
		cout<<"\n\n\n\n\n";
		while(f)
			{
				f.get(ch);
				cout<<ch;
			}
		cout<<"\n\n\n";
		cout<<"Enter movie name\n";
		gets(mov);
		cout<<"enter movie time\n";
		cin>>movt;int co=0;

		cout<<"enter name,no of seats\n";
		gets(name);
		cin>>nos;
		co=seat();
		if((80-co)>=nos)
			{      	price=nos*200;
				cout<<"price:"<<price<<"\n";
				cout<<"pay by\n";
				cout<<"1:cash\n";
				cout<<"2:CC/DC cards\n";
				int c1=0;
				cin>>c1;
				if(c1==1)
				cout<<"pay the money at the theatre\n";
				else
				cout<<"redirecting to Gotham city bank authorisation page";
				int sa;
				for(long int i=0;i<90000000;i++)
				sa=sa*sa;
				cout<<"\nbooking successful.Thank you for choosing enigma\n";
				bookid=10000+random(200)+n;
				n=n+100;
				cout<<"\n booking id :"<<bookid<<"\n\n";
				write();
				mainmenu();
		      }

		else
			{
				cout<<"insuffiecient seats";
			}
		f.close();
		en.close();
	}
void delrec()
	{
		double temp;
		cout<<"enter bookid\n";
		cin>>temp;
		ifstream f;
		f.open("book.dat",ios::in|ios::binary);
		ofstream fo;
		fo.open("temp.dat",ios::out|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
			{
				if(s.retbookid()!=temp)
				fo.write((char*)&s,sizeof(s));
			}
		f.close();
		fo.close();
		remove("book.dat");
		rename("temp.dat","book.dat");
	}
void book::cancel()
	{       clrscr();
		double  temp;
		cout<<"welcome to ticket cancellation\n";
		cout<<"1:cancel ticket\n";
		cout<<"2:go back to main menu\n";
		int c;
		cout<<"\nenter choice\n";
		cin>>c;
		switch(c)
			{
				case 1:delrec();
				case 2:mainmenu();
			}

		cout<<"cancellation succesful\n";
	}
void search()
	{       double temp;
		cout<<"enter bookid\n";
		cin>>temp;
		ifstream f;
		f.open("book.dat",ios::in|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
			{
				if(s.retbookid()==temp)
					{
						s.display();
					}
			}
		f.close();
	}
void book::view()
	{       clrscr();
		book s;
		long int temp;
		cout<<"1:view booking\n";
		cout<<"2:go back to main menu";
		int c;
		cout<<"\nenter choice\n";
		cin>>c;
		switch(c)
			{
				case 1:search();
				case 2:mainmenu();
			}

	}
void modify()
	{
		clrscr();
		fstream f;
		f.open("book.dat",ios::binary|ios::app);
		int found=0;
		f.seekp(0);
		f.seekg(0);
		cout<<"1:modify booking\n";
		cout<<"2:go back to main menu\n";
		int ch;
		cin>>ch;
		switch(ch)
			{
				case 1:break;
				case 2:mainmenu();
					break;
			}
		cout<<"enter booking id\n";
		long int temp;
		cin>>temp;
		while(f.read((char*)&s,sizeof(s)))

			{
				if(s.bookid==temp)
					{
						cout<<"enter new details\n";
						gets(s.mov);
						cin>>s.movt;
						gets(s.name);
						cin>>s.movt>>s.nos;
						found=1;
						f.seekp(f.tellp()-sizeof(s));
						f.write((char*)&s,sizeof(s));
						found=1;
					}
			}
		if(found==0)
			{
				cout<<"no such record found\n";
		f.close();
	}
}