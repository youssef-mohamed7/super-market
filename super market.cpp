#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
// ------------------------{insert function }----------------------------
void insert()
{
	
	fstream myfile;
    myfile.open("supermarket.txt" , ios::app);
    cin.ignore();
    char id[25];
    char name[25];
    char quantity[25];
    char price[25];
    cout<<"id : ";
    cin.getline( id ,25);
    cout<<"name : ";
    cin.getline( name ,25);
    cout<<"quantity : ";
    cin.getline( quantity ,25);
    cout<<"price : ";
    cin.getline(price ,25);
    myfile<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
    myfile.close();
    
    
}
// -----------------------{search function }----------------------------
void search()
{
	fstream myfile;
	myfile.open("supermarket.txt" , ios::in);
	char id[25];
    char name[25];
    char quantity[25];
    char price[25];
    char z[25];
    cout<<"entre product name to search about it :";
    cin.ignore();
    cin.getline( z , 25 );
    int x=0;
    cout<<"\n \t id  \t name  \t qiantity  \t price  \n";
    while (!myfile.eof())
    {
    	myfile.getline(id , 25 ,'|');
    	myfile.getline(name , 25 ,'|');
    	myfile.getline(quantity , 25 ,'|');
    	myfile.getline(price , 25 );
    	if(strcmp(name , z)==0)
    	{
    		cout<<"\t"<<id<<"\t"<<name<<"\t \t "<<quantity<<"\t \t"<<price<<endl;
    		x=1;
    		break;
		}
		
	}
	if (x==0)
	{
	cout<<"not found";
	}
	myfile.close();
}

// -----------------------{display all function }----------------------------
void display_all()
{
//    char id[25];
//    char name[25];
//    char quantity[25];
//    char price[25];
    char id[25];
    char name[25];
    char quantity[25];
    char price[25];
    fstream myfile;
	myfile.open("supermarket.txt" , ios::in);
	cout<<"\n \t id  \t name  \t qiantity  \t price  \n";
	while (!myfile.eof())
    {
    	myfile.getline(id , 25 ,'|');
    	myfile.getline(name , 25 ,'|');
    	myfile.getline(quantity , 25 ,'|');
    	myfile.getline(price , 25 );
    	cout<<"\t"<<id<<"\t"<<name<<"\t \t "<<quantity<<"\t \t"<<price<<endl;
    }
	myfile.close();
}
// -----------------------{update function }----------------------------
void update()
{

	fstream myfile;
	fstream temp;
	myfile.open("supermarket.txt" , ios::in);
	temp.open("temp.txt" , ios::out);
	char id[25];
    char name[25];
    char quantity[25];
    char price[25];
    char x[25];
    cin.ignore();
    cout<<"entre id to update : ";
    cin.getline( x , 25);
    while (!myfile.eof())
    {
    	myfile.getline(id , 25 ,'|');
    	myfile.getline(name , 25 ,'|');
    	myfile.getline(quantity , 25 ,'|');
    	myfile.getline(price , 25 );
    	if(strcmp(id , x )==0)
    	{
    		bool l=true;
    		cout<<" product found\nentre the new data to update :  \n";
    		cout<<"id : ";
            cin.getline( id ,25);
            cout<<"name : ";
            cin.getline( name ,25);
            cout<<"quantity : ";
            cin.getline( quantity ,25);
            cout<<"price : ";
            cin.getline(price ,25);
            temp<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
            
		}
		else 
		{
			
			
			temp<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
		}
    	
	}
	
	
      temp.close();
      myfile.close();
      myfile.open("supermarket.txt" , ios::out);
      temp.open("temp.txt" , ios::in);
      while (!temp.eof())
      {
      	temp.getline(id , 25 ,'|');
    	temp.getline(name , 25 ,'|');
    	temp.getline(quantity , 25 ,'|');
    	temp.getline(price , 25 );
      	myfile<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
	  }
	  temp.close();
      myfile.close();
      remove ("temp.txt");


}
// -----------------------{delete function }----------------------------
void delete_record()
{
	fstream myfile;
	fstream temp;
	myfile.open("supermarket.txt" , ios::in);
	temp.open("temp.txt" , ios::out);
	char id[25];
    char name[25];
    char quantity[25];
    char price[25];
    char x[25];
    cin.ignore();
    cout<<"entre id to delete : ";
    cin.getline( x , 25);
    while (!myfile.eof())
    {
    	myfile.getline(id , 25 ,'|');
    	myfile.getline(name , 25 ,'|');
    	myfile.getline(quantity , 25 ,'|');
    	myfile.getline(price , 25 );
    	if(strcmp(id , x )==0)
    	{
    		
    		continue;
            
		}
		else 
		{
			temp<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
		}
    	
	}
      temp.close();
      myfile.close();
      myfile.open("supermarket.txt" , ios::out);
      temp.open("temp.txt" , ios::in);
      while (!temp.eof())
      {
      	temp.getline(id , 25 ,'|');
    	temp.getline(name , 25 ,'|');
    	temp.getline(quantity , 25 ,'|');
    	temp.getline(price , 25 );
      	myfile<< id <<'|'<< name <<'|'<< quantity <<'|'<<price<<endl;
	  }
	  temp.close();
      myfile.close();
      remove ("temp.txt");
      cout<<" \n done \n";
}
int main ()
{
	bool flag=true;
	
	while(flag){ 
	
cout<<" to insert : 1 \n to search : 2 \n to display all : 3 \n to update : 4 \n to delete : 5 \n";
int c;
cin>>c;
switch (c)
{
	case 1 : insert();
	break;
	case 2 : search();
	break;
	case 3 : display_all();
	break;
	case 4 : update();
	break;
	case 5 : delete_record();
	break;
	default : cout<<" \n entre valid number \n";
	
}
cout<<"\n to continue press 'y' \n to stop press 'n' \n ";
char f ;
cin>>f ;
if (f != 'y' ){
flag = false;
cout<<"\t \t \t \t \t ##################################### \n";
cout<<"\t \t \t \t \t # thank you for using our program # \n";
cout<<"\t \t \t \t \t #####################################";
}
}
return 0;
}

