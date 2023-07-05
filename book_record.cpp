#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Book
{
	int Bid;
	char Bname[30];
	char Bauthor[30];
	int Bprice;
public:
	void getdata();
	void printdata();
	void search_by_id(Book *b,int temp,int n);
	void search_by_name(Book *b,char temp[],int n);
	void sort(Book *b,int n);		
};


void Book::getdata() 
{
	cout<<"Enter the book Record"<<endl<<"Book id: ";
	cin>>Bid;
	cout<<"Book Name: ";
	fflush(stdin);
	gets(Bname);
	cout<<"Book Author: ";
	fflush(stdin);
	gets(Bauthor);
	cout<<"Book Price: ";
	cin>>Bprice;
	
}

void Book::printdata()
{
	cout<<"book Record"<<endl<<"Book id:"<<Bid<<endl;
	cout<<"Book Name: "<<Bname<<endl;
	cout<<"Book Author: "<<Bauthor<<endl;
	cout<<"Book Price: "<<Bprice<<endl;
	
}
void Book::sort(Book *b,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i].Bprice<b[j].Bprice)
			{
				Book t;
				t=b[i];
				b[i]=b[j];
				b[j]=t;	
			}
		}
	}		
}

void Book::search_by_id(Book *b,int temp,int n)
{
		for(int i=0;i<n;i++)
			{
				if(b[i].Bid==temp)
				{
					cout<<"Record searched!";
					b[i].printdata();
				}
			}
				
}

void Book::search_by_name(Book *b,char temp[],int n)
{
	for(int i=0;i<n;i++)
			{
				if(strcmp(b[i].Bname,temp)==0)
				{
					cout<<"Record searched!";
					b[i].printdata();
				}
			}
}

int main()
{
	Book b[100];
	int n;
	int ch;
	do
	{
		cout<<" \n 1.Read\n 2.Print \n 3.Search By Book Id\n 4.Search By Book Name\n 5.Sort by price(decreasing order)\n 6.Exit\n";
		cout<<"\nENTER YOUR CHOICE\n";
		cin>>ch;
		switch(ch)
    	{
			case 1:
					cout<<"How many object you want to work: ";
    				cin>>n;
    				for(int i=0;i<n;i++)
    					b[i].getdata();
					break;
			case 2:
				    for(int i=0;i<n;i++)
    					b[i].printdata();
	    			break;	
	    	case 3:
				    cout<<"enter the id to be searched\n";
    				int temp;
					cin>>temp;
					b[0].search_by_id(b,temp,n); 
					break;
			case 4:	
					char t[30];
					cout<<"enter the name of record to be searched\n";	
					fflush(stdin);
					gets(t);	
					b[0].search_by_name(b,t,n);	
                    break;		
			case 5:	
					b[0].sort(b,n);	
					cout<<"sorted record book id descending order of price: "<<endl;
					for(int i=0;i<n;i++)
    					b[i].printdata();
					break;
			case 6:	
	    			cout<<"Exiting!!";
					break;
	    }
	}while(ch!=6);
	return 0;
}
