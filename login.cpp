#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

void login();
void registr();
void forgot();



int main() {

    int choice;
    cout<<"********LOGIN********\n";
    cout<<"1.Login";
    cout<<"\n2. Register";
    cout<<"\n3. Forgot credentials";
    cout<<"\nEnter your choice :";
    cin>>choice;
    switch(choice) {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thanks for using the login page";
            break;
        default: //any other choice
            cout<<"Sorry, wrong choice selecter";
            main();


    }
    return 0;
}

void registr() {

    string reguser,regpass;
    system("clear");
    cout<<"Enter the username: ";
    cin>>reguser;
    cout<<"Enter the password: ";
    cin>>regpass;


    //we want to check username whether it exists in the database already. 
    string user3,pass3;
    int existuser=0;
    ifstream checkusername("database.txt");
    while (checkusername>>user3>>pass3) {
        if (user3 == reguser) {
            existuser = 1;
            break;
        }
    }
    checkusername.close();
    if (existuser == 1) {
        cout<<"Username already exist. Press any key to return to main menu.";
        cin.get();
        cin.get();
        main();
    } else {
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<" "<<regpass<<endl;
        system("clear");
        cout<<"Registration is successfull\n";
        main();
    }


}
void login() {

    int exist = 0;
    string user,pass,u,p;
    system("clear");
    cout<<"Enter the username: ";
    cin>>user;
    cout<<"Enter the password: ";
    cin>>pass;

    //checking
    ifstream input("database.txt");
    while (input>>u>>p) {
        if(u == user && p == pass) {
            exist= 1;
            break;
        }
    }
    input.close();
    if(exist == 1) {
        cout<<"Hello, "<<user<<"\nWe are glad you are here. ";
        cin.get();
        cin.get();
        main();
    } else {
        cout<<"Sorry, Login error. ";
        cin.get();
        cin.get();
        main();

    }
}



void forgot() {
    int ch;
    system("clear");
    cout<<"1. Search your account by username ";
    cout<<"\n2. Search your account by password ";
    cout<<"\n3. Return to Main menu";
    cout<<"\n Enter your choice:  ";
    cin>>ch;

    switch(ch) {
        case 1: {
            int ex = 0;
            string searchuser,su,sp;
            cout<<"Enter your remembered username: ";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while (searchu>>su>>sp) {
                if (su== searchuser) {
                    ex = 1;
                    break;
                } 
            }
            searchu.close();
            if (ex == 1) {
                cout<<"Hurray ! account found \n";
                cout<<"Your password is "<<sp;
                cin.get();
                cin.get();
                main();
            } else {
                cout<<"Sorry, your account is not found";
                cin.get();
                cin.get();
                main();

            }
        }

        case 2: {
            int exi = 0;
            string searchpass, su2,sp2;
            cout<<"Enter the remembered password:  ";
            cin>>searchpass;
            ifstream searchp("database.txt");
            while (searchp>>su2>>sp2) {
                if (searchpass==sp2) {
                    exi = 1;
                    break;
                    
                }
            }
            searchp.close();
            if(exi==1) {
                cout<<"Hurray! the account found \n";
                cout<<"Your username is : "<<su2;
                cout<<"Your password is : "<<sp2;
                cin.get();
                cin.get();
                main();

            }
            break;
        }
        case 3: {
            main();
            break;}
        default:{
            cout<<"You have given a wrong choice. Press a key to try again";
            cin.get();
            cin.get();

            forgot();
        }





    }
}