#ifndef INFO_H
#define INFO_H

#include <string>
using namespace std;

struct Info
{
  string AccountData;
  string Number;
  string Name;
  string Phone;
  double Balance;
  string SizeOflist;
  int checkifExitt;
};

struct stUserPass
{
  string user;
  string pass;
  string Permsion;
  string SizeOflist;
};
struct stPermition
{
    int permissions = 0;

    static const int SHOW_CLIENT   = 1 << 0;
    static const int ADD_CLIENT    = 1 << 1;
    static const int DELETE_CLIENT = 1 << 2;
    static const int UPDATE_CLIENT = 1 << 3;
    static const int FIND_CLIENT   = 1 << 4;
    static const int MANAGE_USERS  = 1 << 5;

    static int FullAccess()
    {
        return SHOW_CLIENT | ADD_CLIENT | DELETE_CLIENT |
               UPDATE_CLIENT | FIND_CLIENT | MANAGE_USERS;
    }
};

#endif
