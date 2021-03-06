#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include "Mobile.h"
using namespace std;

/*
Adds the Gives mobile to cart
*/
void cartAdd(int num){
    fstream file;
    file.open("Data.txt", ios::in | ios::binary);
    Mobile m1;
    if(num == 1){
        file.read((char *)&m1, sizeof(m1));

    }else{
        for(int i = 0 ; i < num ; i++){
            file.read((char *)&m1, sizeof(m1));
        }
    }
    m1.display();
    file.close();
    file.open("Cart", ios::out | ios::binary | ios::app);
    file.write((char *)&m1, sizeof(m1));
    file.close();
}
/*
Displays The content of the cart
*/
void cartDisplay(){
    Mobile m1;
    fstream file;
    file.open("Cart", ios::in | ios::binary);
    int cnt = 1;
    while(file)
    {
        file.read((char*)&m1, sizeof(m1));

        if(file.eof() != 0)
            break;

        m1.display(cnt);
        cnt++;
        cout<<endl;
    }
    file.close();
}

/*
Creates file to store mobile database
*/
void createFile()
{
    int n;
    cout << "-------------------------" << endl;
    cout<<"\nEnter number of phones : ";
    cin>>n;

    ofstream fout;
    fout.open("Data.txt",ios::out | ios::binary);

    Mobile M;
    M.set_n(n);

    for(int i=0;i<n;i++)
    {
        M.accept();
        fout.write( (char*)&M , sizeof(M));

    }

    fout.close();
}
//-----------------------------------------------
/*
Displays the mobile database stored in file
*/
int displayFile()
{
    ifstream fin;
    Mobile M1;
    int cnt=1;

    fin.open("Data.txt",ios::in | ios::binary);

    while(fin)
    {
        fin.read((char*)&M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        //cout<<cnt<<".";
        M1.display(cnt);
        cnt++;
        cout<<endl;
    }

    fin.close();


    return cnt;
}
//----------------------------------------------------
//----------------------------------------------------
/*
Modifies the Data of the Cart by searching using name, price, memory
*/
void modifyCart(){
	fstream file;
	cout << "-----------------------" << endl;
	void Sname1();
	void Sprice1();
	void Smemory1();

	int param;
	cout << "-------------------------" << endl;
	cout<<"\nSearch by - "<<endl;
	cout<<"1. Name"<<endl;
	cout<<"2. Price"<<endl;
	cout<<"3. Memory"<<endl;
	cout<<"Enter parameter by which to search : ";
	cin>>param;

	    switch(param)
	    {
	        case 1 :    Sname1();
	                    break;
	        case 2 :    Sprice1();
	                    break;
	        case 3 :    Smemory1();
	                    break;
	    }

}
/*
Acceots the input from user to choose mobile
*/
void buyPhone(int cnt)
{
    cout<<cnt << endl;
    displayFile();
    int buy_num;
    cout << "-------------------------" << endl;
   cout<<"\n Which phone do you want to buy?(Enter the number)";
   cin>>buy_num;                //As per the number before the phone (cnt)

    if(buy_num < cnt){
        cartAdd(buy_num);
        cout << "-------------------------" << endl;
        cout<<"Success! Added to cart.";
    }
    else{
        cout << "-------------------------" << endl;
        cout<<"Phone not in store.";
    }
}
//---------------------------------------------------------------------
/*
Searc the Database  using name price or memory
*/
void search_ph()
{
    void Sname();
    void Sprice();
    void Smemory();

    int param;
    cout << "-------------------------" << endl;
    cout<<"\nSearch by - "<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. Price"<<endl;
    cout<<"3. Memory"<<endl;
    cout<<"Enter parameter by which to search : ";
    cin>>param;

    switch(param)
    {
        case 1 :    Sname();
                    break;
        case 2 :    Sprice();
                    break;
        case 3 :    Smemory();
                    break;
    }

}
//---------------------------------------------------
/*
Function to search by name
*/
void Sname()
{
    char name[50];
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter name to be searched : ";
    cin>>name;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        if(!strcmp(M1.getName(),name))
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//---------------------------------------------------------
/*
Function to search by price
*/
void Sprice()
{
    float price;
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter price of phone to be searched : ";
    cin>>price;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;


        if(M1.getPrice() == price)
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//----------------------------------------------------------------------
//---------------------------------------------------------
/*
Function to search by memory
*/
void Smemory()
{
    int memory;
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter memory of phone to be searched : ";
    cin>>memory;

    fin.open("Data.txt", ios::in | ios::binary);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;



        if(M1.getMemory() == memory)
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//---------------------------------------------------
/*
Function to search cart by name
*/
void Sname1()
{
    char name[50];
    int flag;
    fstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter name to be searched : ";
    cin>>name;

    fin.open("Cart", ios::in | ios::out | ios::binary);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        if(!strcmp(M1.getName(),name))
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            cout << "-------------------------" << endl;
            cout << "This data will be changed" << endl;
            M1.accept();
            int pos = -1 * sizeof(M1);
            fin.seekp(pos, ios::cur);
            fin.write((char *)&M1, sizeof(M1));
            cout << "-------------------------" << endl;
            cout << "Modified the data" << endl;
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//---------------------------------------------------------
/*
Function to search cart by price
*/
void Sprice1()
{
    float price;
    int flag;
    fstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter price of phone to be searched : ";
    cin>>price;

    fin.open("Cart", ios::in | ios::binary | ios::out);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;


        if(M1.getPrice() == price)
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            cout << "-------------------------" << endl;
            cout << "This data will be changed" << endl;
            M1.accept();
            int pos = -1 * sizeof(M1);
            fin.seekp(pos, ios::cur);
            fin.write((char *)&M1, sizeof(M1));
            cout << "-------------------------" << endl;
            cout << "Modified the data" << endl;
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//----------------------------------------------------------------------
//---------------------------------------------------------
/*
Function to search cart by memory
*/
void Smemory1()
{
    int memory;
    int flag;
    fstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
    cout<<"Enter memory of phone to be searched : ";
    cin>>memory;

    fin.open("Cart", ios::in | ios::binary | ios::out);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;



        if(M1.getMemory() == memory)
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            cout << "-------------------------" << endl;
            cout << "This data will be changed" << endl;
            M1.accept();
            int pos = -1 * sizeof(M1);
            fin.seekp(pos, ios::cur);
            fin.write((char *)&M1, sizeof(M1));
            cout << "-------------------------" << endl;
            cout << "Modified the data" << endl;
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
/*
Delets the files created while running the program
*/
void exitDeleteDatabase(){
    remove("Data.txt");
    remove("Cart");
}
