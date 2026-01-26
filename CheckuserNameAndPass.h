#include <iostream>
#include <iostream>

using namespace std;

#include <iomanip>

#include <iostream>

#include <vector>

#include <string>

#include <cctype>

#include <fstream>
#include "Info.h"
#include "MangeUsers.h"

  







bool CheckIfUserAndPass(string Line, string User,string Pass)

{

  string Spliter = "#//#";

  size_t Pos = Line.find(Spliter);

  string Username;
  string Password;
  Username = Line.substr(0, Pos);
  if (Username != User)
  {

    return false;

  }
  Line.erase(0,Pos+4);
  Pos = Line.find(Spliter);
  Password=Line.substr(0,Pos);
  if (Password==Pass)
  {

    return true;

  }
  else

  {

    return false;

  }

}

  
vector<string> ReadInfoFromFile(string namefile);

  

int CheckUserPass(Info &Data,string filename,string Username,string Password)

{

  int counter = 0;

  vector <string> lines=ReadInfoFromFile(filename);

  for (string &n :lines)

  {

    bool check = CheckIfUserAndPass(n, Username,Password);

    if (check)

    {

      counter++;

    }

  }

  return counter;

}

bool FindUserInCoorect(Info &Data,string filename,stUserPass UserPass)

{

  if (CheckUserPass(Data,filename,UserPass.user,UserPass.pass) == 0)

  {

    cout << "\n Cleint with " << "[" << Data.AccountData << "]" << " is not exit ";

    return false;

  }

  else

  {

    return true;

  }

}





bool Askpassword(string user,string pass, stUserPass &UserPass)
{
  
  vector <string> Fileusers;
  Fileusers=ReadInfoFromFile("Users.txt");
  Info Data;

  UserPass.user=user;
  UserPass.pass=pass;
  
  if(FindUserInCoorect(Data,"Users.txt",UserPass))
  {
        return true;
  }
  else
  {
    return false;
  }

}

bool CheckuserNameAndPass(string user,string pass,stUserPass& UserPass)
{
    if(Askpassword(user,pass, UserPass))
  {
  return true;
  }
  else
  {
    return false;
  }
  return 0;

}