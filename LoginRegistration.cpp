#include<iostream>
#include<fstream>
using namespace std;

class LoginRegistration
{
    string username, email,Password;
    string searchname,searchpassword,searchemail;
    fstream file;
public:
    void login ();
    void signUp ();
    void forgetPassword ();
};

void LoginRegistration::forgetPassword()
{
    cout<<"Enter your Username :"<<endl;
    getline(cin,searchname);
    cout<<"Enter your Email-id :"<<endl;
    getline(cin,searchemail);

    file.open("loginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,Password,'*');
    while (!file.eof())
    {
        if (username==searchname || email==searchemail)
        {
            cout<<"\n------Account Found-------"<<endl;
            cout<<"\nYour Password is :"<<Password<<endl;
        }
        else
        {
            cout<<"\n-------------Incorrect Details-------------"<<endl;
        }
        getline(file,username,'*');
        getline(file,email,'*');
        getline(file,Password,'*');
    }
    file.close();
}

void LoginRegistration::login()
{
    string searchname,searchpassword;
    cout<<"----------------Login-----------------"<<endl;
    cout<<"\nEnter Your username :"<<endl;
    getline(cin,searchname);
    cout<<"\nEnter Your Password :"<<endl;
    getline(cin,searchpassword);

    file.open("loginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if(username==searchname)
        {
            if(Password==searchpassword)
            {
                cout<<"-------------Login Successful------------"<<endl;
                cout<<"\nUsername:: "<<username<<endl;
                cout<<"\nEmail:: "<<email<<endl;
                cout<<"\nPassword:: "<<Password<<endl;
            }
            else
            {
                cout<<"---------Incorrect Password----------"<<endl;
                cout<<"\n!!Lodin Failed!!";
            }
        }
        else{
            cout<<"---------Incorrect Username----------"<<endl;
            cout<<"\n!!Lodin Failed!!";
        }

        getline(file,username,'*');
        getline(file,email,'*');
        getline(file,Password,'\n');
    }
    file.close();
}

void LoginRegistration::signUp()
{
    cout<<"\nEnter your username :";
    getline(cin,username);
    cout<<"\nEnter Your Email-id :";
    getline(cin,email);
    cout<<"\nEnter your Password :";
    getline(cin,Password);

    file.open("loginData.txt",ios :: out | ios :: app);         
    file<<username<<"*"<<email<<"*"<<Password<<endl;
    file.close();
}


int main ()
{
    LoginRegistration obj;
    int choice;
    cout<<"---------Welcome-----------"<<endl;
    cout<<"\n1. Login";
    cout<<"\n2. Sign-Up";
    cout<<"\n3. forgot-Password";
    cout<<"\n4. Exit";
    cout<<"\nEnter your choice :";
    cin>>choice;

    switch (choice)
    {
    case 1:
        obj.login();
        break;

    case 2:
        obj.signUp();
        break;

    case 3:
        obj.forgetPassword();
        break;

    case 4:
        cout<<"-------Thanking You---------\n!!--Exit--!!"<<endl;
        return 0;
        break;
    
    default:
        cout<<"Invalid Selection...";
        
    }
    return 0;
}
