#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include "Info.h"
using namespace std;
void Action1(vector<string> Lines);
vector<string> ReadInfoFromFile(string namefile);
vector<string> VectorSplitString(string Line);
int ShowList(stUserPass UserPass);
void WaitAndClear();
bool CheckIfexit(string Line, string AccountNumber);
void UpdateAllFileForUsers(vector<string> Slines);
int checkkForUser(stUserPass &Data, string filename);
stUserPass addNewClientForUsers(string namefile);
stUserPass ExtractSireOfusers(vector<string> Lines);
void ShowUserstList(stUserPass Data);
stUserPass StringPutInStructForUsers(vector<string> Lines);
void PrintOneLineForUsers(stUserPass Data);
void vipForusers(string action);
bool FindClentForUser(stUserPass Data,string filename)
{
    cin >> Data.user;

  if (checkkForUser(Data,filename) == 0)

  {

    cout << "\n Cleint with " << "[" << Data.user << "]" << " is not exit ";

    return true;

  }

  else

  {

    stUserPass S1;

    vector<string> Slines = ReadInfoFromFile("Users.txt");

    for (string &n : Slines)

    {

      S1 = StringPutInStructForUsers(VectorSplitString(n));

      if (S1.user == Data.user)

      {

        Data=S1;

        PrintOneLineForUsers(S1);

      }

    }

    return false;

  }

}

void Action5Forusers()

{

  stUserPass Data;

  vipForusers("Find USER Info");

  FindClentForUser(Data,"Users.txt");

}
void PrintOneLineForUsers(stUserPass Data)
{

  

  cout << "|" << setw(15) << Data.user;

  cout << "|" << setw(12) << Data.pass;

  cout << "|" << setw(20) << Data.Permsion;

}
void vipForusers(string action)
{

  cout << "-----------------------------------------------";

  cout << "\n " << action << "\n";

  cout << "-----------------------------------------------\n";

  cout << "enter Account User: ";

}

bool UpdatelientForUsers(stUserPass Data)

{
    cin >> Data.user;
  if (checkkForUser(Data,"Users.txt") == 0)

  {

    cout << "\n Cleint with " << "[" << Data.user << "]" << " is not exit ";

    return true;

  }

  else

  {

    stUserPass S1;

    stUserPass NewData;

    vector<string> Slines = ReadInfoFromFile("Users.txt");

    vector<string> LineWithUpdate;
    ShowUserstList(ExtractSireOfusers(Slines));
    for (string &n : Slines)

    {

      S1 = StringPutInStructForUsers(VectorSplitString(n));

      if (S1.user == Data.user)

      {

        PrintOneLineForUsers(S1);

        string ask;

        cout << "Are tou sure Do you want update this client? y/n ? : ";

        cin >> ask;

        if (ask == "y" || ask == "Y")

        {

          NewData.user = Data.user;

          NewData = addNewClientForUsers("Users.txt");

          string S2 = NewData.user + "#//#" + NewData.pass + "#//#" + NewData.Permsion ;

          LineWithUpdate.push_back(S2);

        }

      }

      else

      {

        LineWithUpdate.push_back(n);

      }

    }

    cout << "\n the client has been Updated successufly";

    UpdateAllFileForUsers(LineWithUpdate);

    return false;

  }

}

void Action4Forusers()

{

  stUserPass Data;

  vipForusers("Update info client");

  UpdatelientForUsers(Data);

}


stUserPass StringPutInStructForUsers(vector<string> Lines)
{
    stUserPass Data;
    Data.user = Lines[0];
    Data.pass = Lines[1];
    Data.Permsion = Lines[2]; // Permsion هو string
    return Data;
}
void UpdateAllFileForUsers(vector<string> Slines)

{

  fstream file;

  file.open("Users.txt", ios::out);

  if (file.is_open())

  {

    for (string n : Slines)

    {

      file << n << endl;

    }

  }

  file.close();

}

int checkkForUser(stUserPass &Data, string filename)
{
    int counter = 0;
    for (string &n : ReadInfoFromFile(filename))
    {
        bool check = CheckIfexit(n, Data.user);
        if (check)
        {
            counter++;
        }
    }
    return counter;
}



bool DeletelientForUsers(stUserPass Data)

{

    cin >> Data.user;
  if (checkkForUser(Data,"Users.txt") == 0)

  {

    cout << "\n Cleint with " << "[" << Data.user << "]" << " is not exit ";

    return true;

  }

  else

  {

    stUserPass S1;

    vector<string> Slines = ReadInfoFromFile("Users.txt");

    vector<string> LineWithDeleted;

    for (string &n : Slines)

    {

      S1 = StringPutInStructForUsers(VectorSplitString(n));

      if (S1.user != Data.user)

      {

        LineWithDeleted.push_back(n);

      }

      else

      {

        continue;

      }

    }

    UpdateAllFileForUsers(LineWithDeleted);

    cout << "\n the client has been deleted successufly";

    return false;

  }

}

  
stPermition AskForPermition()
{
    char ans;
    int permissions = 0;
    stPermition Permition;
        cout << "do you want give him full access (y/n):";
    cin >> ans;
    if (ans == 'y')
    {
        permissions = Permition.FullAccess();
        Permition.permissions = permissions;
        return Permition;
    }
    else
    {
        cout << endl;
        cout << "do you want give access to:" << endl;
        cout << "show client list:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.SHOW_CLIENT;
        
        cout << "addNew client:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.ADD_CLIENT;
        
        cout << "delete client:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.DELETE_CLIENT;
        
        cout << "update client:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.UPDATE_CLIENT;
        
        cout << "find client:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.FIND_CLIENT;
        
        cout << "manage users:";
        cin >> ans;
        if (ans == 'y')
            permissions |= Permition.MANAGE_USERS;
            
        Permition.permissions = permissions;
        return Permition;
    }
}




void UpdateFileForUsers(stUserPass Data)
{
    fstream file;
    file.open("Users.txt", ios::app);
    if (file.is_open())
    {
        file << Data.user << "#//#" << Data.pass << "#//#" << Data.Permsion << endl;
    }
    file.close();
}

stUserPass ExtractSireOfusers(vector<string> Lines)
{
    stUserPass Data;
    Data.SizeOflist = to_string(Lines.size());
    return Data;
}

void ReturnToPageOneForUsers(stUserPass UserPass)
{
    cout << "\n\nPress ENTER to Return To First Page";
    WaitAndClear();
    ShowList(UserPass);
}



bool CheckPermition(stUserPass UserPass, int requiredPermission)
{
    vector<string> Lines = ReadInfoFromFile("Users.txt");
    stUserPass Data;
    for (string n : Lines)
    {
        Data = StringPutInStructForUsers(VectorSplitString(n));
        if (UserPass.user == Data.user)
        {
            int userPermissions = stoi(Data.Permsion);
            // التحقق من أن المستخدم لديه الصلاحية المطلوبة
            if ((userPermissions & requiredPermission) == requiredPermission)
            {
                return true;
            }
        }
    }
    return false; // لم يتم العثور على المستخدم أو لا يملك الصلاحية
}

enum enNumbreActionUser {
    Action11OfUsers = 1,
    Action21OfUsers = 2,
    Action31OfUsers = 3,
    Action41OfUsers = 4,
    Action51OfUsers = 5,
    Action61OfUsers = 6,
};

stUserPass AskUSERAndPassword(stUserPass Data)
{
    cout << "enter the password:";
    cin >> Data.pass;
    cout << endl;
    return Data;
}

void addNewUser(string action)
{
    cout << "-----------------------------------------------";
    cout << "\n" << action << "\n";
    cout << "-----------------------------------------------\n";
}

int askAdmin()
{
    cout << "-------------------------------------------------------\n";
    cout << "Manage users Menue Screen\n";
    cout << "-------------------------------------------------------\n";
    int num;
    cout << "[1] List Users." << endl;
    cout << "[2] Add New User." << endl;
    cout << "[3] Delete User." << endl;
    cout << "[4] Update User." << endl;
    cout << "[5] Find User." << endl;
    cout << "[6] Main Menu" << endl;
    cout << "choose what do you want to do [1-6]:";
    cin >> num;
    return num;
}

void ShowUserstList(stUserPass Data)
{
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << left << "UserName";
    cout << "|" << setw(12) << left << "Password";
    cout << "|" << setw(20) << left << "Permision\n";
}

void PrintUsersSpalted(vector<string> Lines)
{
    stUserPass Data;
    for (string n : Lines)
    {
        Data = StringPutInStructForUsers(VectorSplitString(n));
        cout << "|" << setw(15) << left << Data.user;
        cout << "|" << setw(12) << left << Data.pass;
        cout << "|" << setw(20) << left << Data.Permsion;
        cout << endl;
    }
}

void Action1User(vector<string> Lines)
{
    ShowUserstList(ExtractSireOfusers(Lines));
    PrintUsersSpalted(Lines);
}


stUserPass addNewClientForUsers(string namefile)
{
    stPermition Permition;
    stUserPass Data;
    addNewUser("Add New users screen");
    cout << "enter the username:";
    cin >> Data.user;
    cout << endl;
    if (checkkForUser(Data, namefile) != 0)
    {
        do
        {
            cout << "\nClient with [" << Data.user << "] already exists, enter another account User:";
            cin >> Data.user;
        } while (checkkForUser(Data, namefile) != 0);
    }
    Data = AskUSERAndPassword(Data);
    Permition = AskForPermition();
    Data.Permsion = to_string(Permition.permissions);
    return Data;
}

void Action2ForUser()
{
    stUserPass Data;
    Data = addNewClientForUsers("Users.txt");
    UpdateFileForUsers(Data);
    string ask;
    cout << "do you want add more users [y/n]:";
    cin >> ask;
    while (ask == "Y" || ask == "y")
    {
        Data = addNewClientForUsers("Users.txt");
        UpdateFileForUsers(Data);
        cout << "do you want add more users [y/n]:";
        cin >> ask;
    }
}
void Action3ForUser()
{
     stUserPass Data;
    DeletelientForUsers(Data);
}


void askLoop(enNumbreActionUser NumbreAction, stUserPass UserPass)
{
    stPermition Permition;
    switch (NumbreAction)
    {
    case enNumbreActionUser::Action11OfUsers:
    {
        if (CheckPermition(UserPass, Permition.SHOW_CLIENT))
        {
            WaitAndClear();
            Action1User(ReadInfoFromFile("Users.txt"));
        }
        else
        {
            ReturnToPageOneForUsers(UserPass);
            cout << "\nYou don't have permission to access this feature!" << endl;
        }
        
        break;
    }
    case enNumbreActionUser::Action21OfUsers:
    {
        if (CheckPermition(UserPass, Permition.ADD_CLIENT))
        {
            WaitAndClear();
            Action2ForUser();
        }
        else
        {
            ReturnToPageOneForUsers(UserPass);
        cout << "\nYou don't have permission to access this feature!" << endl;
        }
        break;
    }
        case enNumbreActionUser::Action31OfUsers:
    {
        if (CheckPermition(UserPass, Permition.DELETE_CLIENT))
        {
            WaitAndClear();
            vipForusers("delete client in file");
            Action3ForUser();
            
        }
        else
        {
            ReturnToPageOneForUsers(UserPass);
        cout << "\nYou don't have permission to access this feature!" << endl;
        }
        break;
    }
        case enNumbreActionUser::Action41OfUsers:
    {
        if (CheckPermition(UserPass, Permition.UPDATE_CLIENT))
        {
            WaitAndClear();
            Action4Forusers();
            
        }
        else
        {
            ReturnToPageOneForUsers(UserPass);
        cout << "\nYou don't have permission to access this feature!" << endl;
        }
        break;
    }

            case enNumbreActionUser::Action51OfUsers:
    {
        if (CheckPermition(UserPass, Permition.FIND_CLIENT))
        {
                        Action5Forusers();
            
        }
        else
        {
            ReturnToPageOneForUsers(UserPass);
        cout << "\nYou don't have permission to access this feature!" << endl;
        }
        break;
    }
    }
}

int ShowList(stUserPass UserPass)
{
    enNumbreActionUser NumbreAction;
    NumbreAction = (enNumbreActionUser)askAdmin();
    askLoop(NumbreAction, UserPass);
    return 0;
}