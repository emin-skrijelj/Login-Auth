#include <iostream>
//#include <conio.h>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

/*string passwdInput()
{
    string ipt = "";
    char ipt_ch;
    while (true) {
        ipt_ch = getch();

        if (ipt_ch < 32) {
            cout << endl;
            return ipt;
        }
        ipt.push_back(ipt_ch);
    }
}*/

void logingIn(string user_file,string password_file){
    fstream username;
    fstream password;
    string line;
    string linep;
    string user;
    string pass;
    username.open(user_file,ios::in);
    password.open(password_file,ios::in);
    if(!username){
        cout << "File did not open!";
        exit(1);
    };

    if(!password){
        cout << "Password file did not open!";
        exit(1);
    };
    cout << "Enter your login credentials\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;
    cout << "\nChecking database if your credentials are valid/..%" << endl;
    while(!username.eof()){
        while(getline(username,line)){
            if(line == user){
                while(!username.eof())
                    while(getline(password,linep)){
                        if(linep == pass){
                            cout << "\nCongrats, login successfull." << endl;
                            cout << "Have a nice day " << user << ":)"  << endl;
                            username.close();
                            password.close();
                            exit(1);
                        };
                };
            }else if(username.eof()){
                cout << "Sorry your password or user is not found..\n";
                exit(1);
            };
        };
    };
    cout << "\nWRONG PASSWORD OR USERNAME!" << endl;
};

void registering(string user_file,string password_file){
    hash<string> hasher;
    size_t hash;
    fstream username;
    fstream password;
    string user;
    string pass;    
    username.open(user_file,ios::app);
    password.open(password_file,ios::app);
    if(!username){
        cout << "File did not open!";
        exit(1);
    };

    if(!password){
        cout << "Password file did not open!";
        exit(1);
    };

    cout << "--Register your new account--" << endl;
    cout << "Your username (no symbols!): ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;  
    username << user;
    username << '\n';
    password << pass;
    password << '\n';
    cout << "Account created successfully. You can login now with this credentials" << endl;
    username.close();
    password.close();
};


int main(){
    string option;
    string cmd;
    cout << "Do you want to log in with an existing account or register a new one?" << endl;
    cout << "Type register or login here: ";
    cin >> option;
    cout << "===========================================\n";
    
    if(option == "login"){
        logingIn("usernames.txt","passwords.txt");
    }else if(option == "register"){
        registering("usernames.txt","passwords.txt");
    };
    return 0;
}
