#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
using namespace std ;

enum ClassStanding {
    Freshman ,Sophomore  , Junior ,  Senior
};

bool is_valid_email (string s);
string to_csv(vector<string>& data);
bool is_valid_phone_number(string s);
string hash_password(string password);



#endif // UTILS_H
