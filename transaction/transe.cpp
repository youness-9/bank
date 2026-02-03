#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <string>
using namespace std;
#include <fstream>

struct stDataOfUser
{
    string User;
    string Pass;

    int Balance;
};
struct stBalanceChecnge
{
    bool Deposit=false;
    bool withraw=false;
};
vector <string> ReadFromFile(string Namefile)
{
    vector <string> DataOfFile;
    fstream file;
    file.open(Namefile,ios::in);
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            DataOfFile.push_back(line);
        }
        
    }
    file.close();
    return DataOfFile;
}  


vector <string> LineOfVectorToSplitVector(string Sword)
{
    vector <string> DataSplited;
    string Sopritior="#//#";
    int pos=0;
    string line;
    while((pos=Sword.find(Sopritior)) != std::string::npos)
    {
        line=Sword.substr(0,pos);
        if(line!="")
        {
            DataSplited.push_back(line);
        }
        Sword.erase(0,pos+Sopritior.length());
    }
       if(line!="")
        {
            DataSplited.push_back(Sword);
        }
        return DataSplited;
}
stDataOfUser AskForUserAndPass()
{
    stDataOfUser Data;
    cout<<"----------------------------------------"<<endl;
    cout<<"             Login screen                "<<endl;
    cout<<"----------------------------------------"<<endl;

    cout<<"give me your account Number: ";
    cin>>Data.User;
    cout<<"give me your Pin Code: ";
    cin>>Data.Pass;
    return Data;
}
void UpdateFile(stDataOfUser Data)

{
    vector <string> DataOfFile;
    vector <string> DataSplited;
    DataOfFile=ReadFromFile("info.txt");
    fstream file;

    file.open("info.txt", ios::out);

    if (file.is_open())
    for(string &n:DataOfFile)
    {
        DataSplited=LineOfVectorToSplitVector(n);
        if((DataSplited[0]==Data.User)&&(DataSplited[1]==Data.Pass))
        {


                file << DataSplited[0] << "#//#" << DataSplited[1] << "#//#" << DataSplited[2] << "#//#" << DataSplited[3] << "#//#" << Data.Balance << endl;

        }
        else
        {
                    file << DataSplited[0] << "#//#" << DataSplited[1] << "#//#" << DataSplited[2] << "#//#" << DataSplited[3] << "#//#" << DataSplited[4] << endl;

        }

      
    }
    
            file.close();


}

int QuikWithraw()
{
    cout<<"[1] 20"<<endl;
    cout<<"[2] 100"<<endl;
    cout<<"[3] 400"<<endl;
    cout<<"[4] 800"<<endl;
    cout<<"[5] 600"<<endl;
    cout<<"[6] 700"<<endl;
    cout<<"[7] 1000"<<endl;
    cout<<"shose what do you want do withraw from 1 to 7:  ";
    int num;
    cin>>num;
    switch(num)
    {
        case 1:
        {
        return 20;
        }
        case 2:
        {
        return 100;
        }
        case 3:
        {
        return 400;
        }
        case 4:
        {
        return 800;
        }
        case 5:
        {
        return 600;
        }
        case 6:
        {
        return 700;
        }
        case 7:
        {
        return 1000;
        }
        

    }
    return 0;
    
}

void MainScreen()
{
    cout<<"-----------------------------------------"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"             Main menue Screen           "<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"     [1] Quick withdraw."<<endl;
    cout<<"     [2] Normal withdraw."<<endl;
    cout<<"     [3] Deposit."<<endl;
    cout<<"     [4] check Balance."<<endl;
    cout<<"     [5] logout."<<endl;
    cout<<"give me your choise: "<<endl;
}

void PrintBallnce(stDataOfUser Data,string print)
{
   cout<<print<<Data.Balance;
}
bool checkBalanceYouWillWithraw(stDataOfUser &Data,int HowMatch)
{

    if(Data.Balance<HowMatch&&(HowMatch%5)!=0)
    {
        return false;
        
    }
    
    return true;
}
void ChangeBallnce(stDataOfUser &Data,int HowMatch,stBalanceChecnge BalanceChecnge )
{
    if(BalanceChecnge.withraw)
    {
        if(checkBalanceYouWillWithraw(Data,HowMatch))
        {
            Data.Balance=Data.Balance-HowMatch;
            UpdateFile(Data);
        }
        
        else if((HowMatch%5)!=0)
        {
            cout<<"\n No give me a number in multiple of 5";
        }
        else
        {
            cout<<"\n the Amounth is exceeds your balance,make anther choise";
        } 
    }
    if(BalanceChecnge.Deposit)
    {
        if(checkBalanceYouWillWithraw(Data,HowMatch))
        {
            Data.Balance=Data.Balance+HowMatch;
            UpdateFile(Data);
            cout<<"\n has been add sucssufly";
        }
        
        else if((HowMatch%5)!=0)
        {
            cout<<"\n No give me a number in multiple of 5";
        }
    }
}
bool checkAcountNumberAndPin (stDataOfUser &Data)
{
    vector <string> DataOfFile;
    vector <string> DataSplited;
    DataOfFile=ReadFromFile("info.txt");
    for(string &n:DataOfFile)
    {
        DataSplited=LineOfVectorToSplitVector(n);
        if((DataSplited[0]==Data.User)&&(DataSplited[1]==Data.Pass))
        {
            Data.Balance=stoi(DataSplited[4]);
            return true;
        }
      
    }
    return false;

}

void Print()
{
    stDataOfUser Data;
    Data=AskForUserAndPass();
    int num;
    stBalanceChecnge BalanceChecnge;
    MainScreen();
    while(checkAcountNumberAndPin(Data))
        {
            BalanceChecnge.withraw=false;
            BalanceChecnge.Deposit=false;
            
            cout<<endl;
            cin>>num;
            if(num==4)
            {
                PrintBallnce(Data,"Your Balnce is :");
            }
            else if(num==5)
            {
                break;
            }
            else if(num==1)
            {
                BalanceChecnge.withraw=true;
                int num1=QuikWithraw();
                PrintBallnce(Data,"\n Your Balnce is :");
                ChangeBallnce(Data,num1,BalanceChecnge);
                PrintBallnce(Data,"\n Your Now Balnce is :");
            }
            else if(num==2)
            {
                int HowMatchMony;
                cout<<"how match mony do you want to withraw: ";
                cin>>HowMatchMony;
                BalanceChecnge.withraw=true;
                PrintBallnce(Data,"\n Your Balnce is :");
                ChangeBallnce(Data,HowMatchMony,BalanceChecnge);
                PrintBallnce(Data,"\n Your Now Balnce is :");
            }else if(num==3)
            {
                int HowMatchMony;
                cout<<"how match mony do you want to add: ";
                cin>>HowMatchMony;
                BalanceChecnge.withraw=false;
                BalanceChecnge.Deposit=true;
                PrintBallnce(Data,"\n Your Balnce is :");
                ChangeBallnce(Data,HowMatchMony,BalanceChecnge);
                PrintBallnce(Data,"\n Your Now Balnce is :");
            }
            

        }
}
int main()
{
Print();
    return 0;
}
