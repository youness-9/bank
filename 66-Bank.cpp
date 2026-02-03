#include <iostream>
#include <iomanip>
#include <vector>

#include <string>

#include <cctype>

#include <fstream>
#include "CheckuserNameAndPass.h"
#include "Info.h"



void WaitAndClear()
{
    cout << "\n\nPress ENTER to continue...";
    cin.get(); // انتظر ENTERss
    cout << "\033[2J\033[1;1H"; // مسح الشاشة في Linux/macOS/Windows (ANSI escape code)
}

enum enNumbreAction

{

  Action11 = 1,

  Action21 = 2,

  Action31 = 3,

  Action41 = 4,

  Action51 = 5,

  Action61 = 6,

  Action71 = 7,

  Action81 = 8,


  

};

void askLoop(enNumbreAction NumbreAction, stUserPass UserPass);

void ReturnToPageOne(stUserPass UserPass);

void ReturnToPageBalance(stUserPass UserPass);

enum enNumberTranstactions

{

  Deposit = 1,

  Winthraw = 2,

  TotalBalance = 3,

  MainMenue = 4,

  

};



int ask()

{

  cout << "-------------------------------------------------------\n";

  cout << "          Main Menue Screen          \n";

  cout << "-------------------------------------------------------\n";

  int num;

  cout << "[1] Show Client List. " << endl;

  cout << "[2] Add New Client. " << endl;

  cout << "[3] Delete Client. " << endl;

  cout << "[4] Apdate Client info. " << endl;

  cout << "[5] Find Client. " << endl;

  cout << "[6] Transaction. " << endl;
  cout << "[7] manage Users. " << endl;
  cout << "[8] Exit. " << endl;

  cout << "choose what do you want to do [1-8]: ";

  cin >> num;

  return num;

}

int askTransactios()

{

  cout << "-------------------------------------------------------\n";

  cout << "          Transactions Menue Screen          \n";

  cout << "-------------------------------------------------------\n";

  int num;

  cout << "[1] Deposit. " << endl;

  cout << "[2] Winthraw. " << endl;

  cout << "[3] Total Balance. " << endl;

  cout << "[4] Main Menue " << endl;

  cout << "choose what do you want to do [1-4]: ";

  cin >> num;

  return num;

}

vector<string> ReadInfoFromFile(string namefile)

{

  vector<string> Lines;

  fstream file;

  file.close();

  file.open(namefile, ios::in);

  if (file.is_open())

  {

    string line;

    while (getline(file, line))

    {

      Lines.push_back(line);

    }

  }

  file.close();

  return Lines;

}

  

vector<string> VectorSplitString(string Line)

{

  vector<string> Data;

  string Spliter = "#//#";

  size_t Pos = 0;

  string Sword;

  while ((Pos = Line.find(Spliter)) != std::string::npos)

  {

    Sword = Line.substr(0, Pos);

    if (Sword != "")

    {

      Data.push_back(Sword);

    }

    Line.erase(0, Pos + Spliter.length());

  }

  if (Line != "")

    Data.push_back(Line);

  return Data;

}

  

Info ExtractSire(vector<string> Lines)

{

  Info Data;

  Data.SizeOflist = to_string(Lines.size());

  return Data;

}

  

Info StringPutInStruct(vector<string> Lines)

{

  Info Data;

  Data.AccountData = Lines[0];

  Data.Number = Lines[1];

  Data.Name = Lines[2];

  Data.Phone = Lines[3];

  Data.Balance = stod(Lines[4]);

  return Data;

}

  

void ShowClientList(Info Data)

{

  cout << "\n Client List " << Data.SizeOflist << " Client(s)" << endl;

  cout << "----------------------------------------------------------------------------------------" << endl;

  cout << "|" << setw(15) << "Account Number";

  cout << "|" << setw(12) << "Pin code";

  cout << "|" << setw(20) << "Client Name";

  cout << "|" << setw(15) << "Phone";

  cout << "|" << setw(10) << "Balance" << endl;

}

void ShowClientListBalance(Info Data)

{

  cout << "\n Balence List " << Data.SizeOflist << " Client(s)" << endl;

  cout << "----------------------------------------------------------------------------------------" << endl;

  cout << "|" << setw(15) << "Account Number";

  cout << "|" << setw(20) << "Client Name";

  cout << "|" << setw(10) << "Balance" << endl;

}

  

void PrintDataSpalted(vector<string> Lines)

{

  Info Data;

  for (string n : Lines)

  {

    Data = StringPutInStruct(VectorSplitString(n));

    cout << "|" << setw(15) << Data.AccountData;

    cout << "|" << setw(12) << Data.Number;

    cout << "|" << setw(20) << Data.Name;

    cout << "|" << setw(15) << Data.Phone;

    cout << "|" << setw(10) << Data.Balance << endl;

  }

}

void PrintDataBalnce(vector<string> Lines)

{

  Info Data;

  double counter=0;

  for (string n : Lines)

  {

    Data = StringPutInStruct(VectorSplitString(n));

    cout << "|" << setw(15) << Data.AccountData;

    cout << "|" << setw(20) << Data.Name;

    cout << "|" << setw(10) << Data.Balance << endl;

    counter+=Data.Balance;

  }

    cout<<endl<<"----------------------------------------------------------------------------------------"<<endl;

    cout<<setw(40)<<"Total Balances= "<<counter<<endl;

}

void PrintOneLine(Info Data)

{

  

  cout << "|" << setw(15) << Data.AccountData;

  cout << "|" << setw(12) << Data.Number;

  cout << "|" << setw(20) << Data.Name;

  cout << "|" << setw(15) << Data.Phone;

  cout << "|" << setw(10) << Data.Balance << endl;

}

  

void Action1(vector<string> Lines)

{

  ShowClientList(ExtractSire(Lines));

  PrintDataSpalted(Lines);

}

void Action6ShowBalance(vector<string> Lines)

{

  ShowClientListBalance(ExtractSire(Lines));

  PrintDataBalnce(Lines);

}

bool CheckIfexit(string Line, string AccountNumber)

{

  string Spliter = "#//#";

  size_t Pos = Line.find(Spliter);

  string Sword;

  Sword = Line.substr(0, Pos);

  if (Sword == AccountNumber)

  {

    return true;

  }

  else

  {

    return false;

  }

}

  

int checkk(Info &Data,string filename)

{

  int counter = 0;

  cin >> Data.AccountData;

  for (string &n : ReadInfoFromFile(filename))

  {

    bool check = CheckIfexit(n, Data.AccountData);

    if (check)

    {

      counter++;

    }

  }

  return counter;

}

void vip(string action)

{

  cout << "-----------------------------------------------";

  cout << "\n " << action << "\n";

  cout << "-----------------------------------------------\n";

  cout << "enter Account Number: ";

}

  

Info AskUSER(Info OneDATA)

{

  Info Data;

  Data.AccountData = OneDATA.AccountData;

  cout << "enter the pin code: ";

  cin >> Data.Number;

  cout << endl

    << "enter your Name: ";

  cin >> Data.Name;

  cout << endl

    << "enter your Phone: ";

  cin >> Data.Phone;

  cout << endl

    << "enter the Balance: ";

  cin >> Data.Balance;

  return Data;

}

Info addNewClient(string namefile)

{

  Info Data;

  vip("add new client screen");

  if (checkk(Data,namefile) != 0)

  {

    do

    {

      cout << "\n Cleint with " << "[" << Data.AccountData << "]" << " is allrady exit enter anther account number: ";

    } while (checkk(Data,namefile) != 0);

  }

  

  return AskUSER(Data);

}

  

void UpdateFile(Info Data)

{

  fstream file;

  file.open("info.txt", ios::app);

  if (file.is_open())

  {

    file << Data.AccountData << "#//#" << Data.Number << "#//#" << Data.Name << "#//#" << Data.Phone << "#//#" << Data.Balance << endl;

  }

  file.close();

}

  

void UpdateAllFile(vector<string> Slines)

{

  fstream file;

  file.open("info.txt", ios::out);

  if (file.is_open())

  {

    for (string n : Slines)

    {

      file << n << endl;

    }

  }

  file.close();

}

  

bool Deletelient(Info Data)

{

  if (checkk(Data,"info.txt") == 0)

  {

    cout << "\n Cleint with " << "[" << Data.AccountData << "]" << " is not exit ";

    return true;

  }

  else

  {

    Info S1;

    vector<string> Slines = ReadInfoFromFile("info.txt");

    vector<string> LineWithDeleted;

    for (string &n : Slines)

    {

      S1 = StringPutInStruct(VectorSplitString(n));

      if (S1.AccountData != Data.AccountData)

      {

        LineWithDeleted.push_back(n);

      }

      else

      {

        continue;

      }

    }

    UpdateAllFile(LineWithDeleted);

    cout << "\n the client has been deleted successufly";

    return false;

  }

}

  

bool Updatelient(Info Data)

{

  if (checkk(Data,"info.txt") == 0)

  {

    cout << "\n Cleint with " << "[" << Data.AccountData << "]" << " is not exit ";

    return true;

  }

  else

  {

    Info S1;

    Info NewData;

    vector<string> Slines = ReadInfoFromFile("info.txt");

    vector<string> LineWithUpdate;

    ShowClientList(ExtractSire(Slines));

    for (string &n : Slines)

    {

      S1 = StringPutInStruct(VectorSplitString(n));

      if (S1.AccountData == Data.AccountData)

      {

        PrintOneLine(S1);

        string ask;

        cout << "Are tou sure Do you want update this client? y/n ? : ";

        cin >> ask;

        if (ask == "y" || ask == "Y")

        {

          NewData.AccountData = Data.AccountData;

          NewData = AskUSER(NewData);

          string S2 = NewData.AccountData + "#//#" + NewData.Number + "#//#" + NewData.Name + "#//#" + NewData.Phone + "#//#" + to_string(NewData.Balance);

          LineWithUpdate.push_back(S2);

        }

      }

      else

      {

        LineWithUpdate.push_back(n);

      }

    }

    cout << "\n the client has been Updated successufly";

    UpdateAllFile(LineWithUpdate);

    return false;

  }

}

void PrintOneString(Info Data)

{

  

  cout << "the following are the client details: \n";

  cout << "-------------------------------------------------------------";

  cout << "\n account Number: " << setw(3) << Data.AccountData;

  cout << "\n Pin code: " << setw(3) << Data.Number;

  cout << "\n Name: " << setw(3) << Data.Name;

  cout << "\n Phone: " << setw(3) << Data.Phone;

  cout << "\n account Balance: " << setw(3) << Data.Balance << endl;

}

bool FindClent(Info &Data,string filename)

{

  if (checkk(Data,filename) == 0)

  {

    cout << "\n Cleint with " << "[" << Data.AccountData << "]" << " is not exit ";

    return true;

  }

  else

  {

    Info S1;

    vector<string> Slines = ReadInfoFromFile("info.txt");

    for (string &n : Slines)

    {

      S1 = StringPutInStruct(VectorSplitString(n));

      if (S1.AccountData == Data.AccountData)

      {

        Data=S1;

        PrintOneString(S1);

      }

    }

    return false;

  }

}

void Action2()

{

  Info Data;

  Data = addNewClient("info.txt");

  UpdateFile(Data);

  string ask;

  cout << "do you want add more cleint[y,Y]: ";

  cin >> ask;

  

  while (ask == "Y" || ask == "y")

  {

    Data = addNewClient("info.txt");

    UpdateFile(Data);

    cout << "do you want add more cleint[y,Y]: ";

    cin >> ask;

  }

}

  
  

void AddBalance(Info Data)

{

  double ask;

  string yes;

  cout<<"\n"<<"enter Deposit Amount? : ";

  cin>> ask;

  cout<<"\n Are you sure you want perform this transaction (y/Y): ";

  cin>>yes;

  if(yes=="y"||yes=="Y")

  {

  Data.Balance=Data.Balance+ask;

    Info S1;

    vector<string> Slines = ReadInfoFromFile("info.txt");

    vector<string> LineWithUpdate;

    for (string &n : Slines)

    {

      S1 = StringPutInStruct(VectorSplitString(n));

      if (S1.AccountData == Data.AccountData)

      {

          string S2 = Data.AccountData + "#//#" + Data.Number + "#//#" + Data.Name + "#//#" + Data.Phone + "#//#" + to_string(Data.Balance);

          LineWithUpdate.push_back(S2);

  

      }

      else

      {

        LineWithUpdate.push_back(n);

      }

    }

    cout << "\n the client has been Updated successufly";

    UpdateAllFile(LineWithUpdate);

  }

}

  

void WithrawBalance(Info Data)

{

  double ask;

  string yes;

  cout<<"\n"<<"enter Withraw Amount? : ";

  cin>> ask;

  if(Data.Balance<ask)

  {

    cout<<"\n Amount exceeds the balance you can withraw up to "<<Data.Balance;

  }

  else{

  cout<<"\n Are you sure you want perform this transaction (y/Y): ";

  cin>>yes;

  if(yes=="y"||yes=="Y")

  {

  Data.Balance=Data.Balance-ask;

    Info S1;

    vector<string> Slines = ReadInfoFromFile("info.txt");

    vector<string> LineWithUpdate;

    for (string &n : Slines)

    {

      S1 = StringPutInStruct(VectorSplitString(n));

      if (S1.AccountData == Data.AccountData)

      {

          string S2 = Data.AccountData + "#//#" + S1.Number + "#//#" + S1.Name + "#//#" + S1.Phone + "#//#" + to_string(Data.Balance);

          LineWithUpdate.push_back(S2);

  

      }

      else

      {

        LineWithUpdate.push_back(n);

      }

    }

    cout << "\n the client has been Updated successufly";

    UpdateAllFile(LineWithUpdate);

  }

}

}

  
  
  

void Action3()

{

  Info Data;

  vip("delete client in file");

  Deletelient(Data);

}

  

void Action4()

{

  Info Data;

  vip("Update info client");

  Updatelient(Data);

}

void Action5()

{

  Info Data;

  vip("Find Cleint Info");

  FindClent(Data,"info.txt");

}

void Action6Deposit(stUserPass UserPass)

{

  Info Data;

  vip("Deposit Screen");

  while(!FindClent(Data,"info.txt"))

  {

    AddBalance(Data);

    askLoop(enNumbreAction(6), UserPass);

  }

}

void Action6Widraw(stUserPass UserPass)

{

  Info Data;

  vip("Withraw Screen");

  while(!FindClent(Data,"info.txt"))

  {

    WithrawBalance(Data);

    askLoop(enNumbreAction(6), UserPass);

  }

}

stUserPass AskInfoLogin()
{
  stUserPass UserPass;
  cout << "-----------------------------------------------";

  cout << "\n Login Screen \n";

  cout << "-----------------------------------------------\n";

  cout<<"\n give me user:";
  cin>>UserPass.user;
  cout<<"\n give me Pass:";
  cin>>UserPass.pass;
  return UserPass;
}







void askLoop(enNumbreAction NumbreAction, stUserPass UserPass)

{
  switch (NumbreAction)

  {

  case enNumbreAction::Action11:

  {

    WaitAndClear();

    Action1(ReadInfoFromFile("info.txt"));

    ReturnToPageOne(UserPass);

    break;

  }

  case enNumbreAction::Action21:

  {

    WaitAndClear();

    Action2();

    ReturnToPageOne(UserPass);

    break;

  }

  case enNumbreAction::Action31:

  {

    WaitAndClear();

    Action3();

    ReturnToPageOne(UserPass);

    break;

  }

  case enNumbreAction::Action41:

  {

    WaitAndClear();

    Action4();

    ReturnToPageOne(UserPass);

    break;

  }

  case enNumbreAction::Action51:

  {

    WaitAndClear();

    Action5();

    ReturnToPageOne(UserPass);

    break;

  }

  case enNumbreAction::Action61:

  {

    WaitAndClear();

    switch(enNumberTranstactions(askTransactios()))

    {

      case enNumberTranstactions::Deposit:

        Action6Deposit(UserPass);

        ReturnToPageBalance(UserPass);

      case enNumberTranstactions::Winthraw:

        Action6Widraw(UserPass);

        ReturnToPageBalance(UserPass);

      case enNumberTranstactions::TotalBalance:

        Action6ShowBalance(ReadInfoFromFile("info.txt"));

        ReturnToPageBalance(UserPass);

      case enNumberTranstactions::MainMenue:

        askLoop(enNumbreAction(ask()), UserPass);

    }

  }

  case enNumbreAction::Action71:

  {
      WaitAndClear();
      ShowList(UserPass);


  }


  case enNumbreAction::Action81:

  {
      WaitAndClear();

      break;

  }

  }

}

void ReturnToPageBalance(stUserPass UserPass)

{

  cout << "\n \n Press ENTER to Return To First Page";

  cin.ignore();
  cin.get();
  WaitAndClear();



  askLoop(enNumbreAction(6), UserPass);

}

void ReturnToPageOne(stUserPass UserPass)

{

  cout << "\n \n Press ENTER to Return To First Page";

WaitAndClear();


  askLoop(enNumbreAction(ask()), UserPass);

}

int main()

{
    stUserPass UserPass;
    bool checkuser = false;
    while (!checkuser)
  {
        UserPass = AskInfoLogin();
        checkuser = CheckuserNameAndPass(UserPass.user, UserPass.pass,UserPass);
        if (checkuser)
        {
            askLoop(enNumbreAction(ask()), UserPass);
        }
  }
  return 0;

}