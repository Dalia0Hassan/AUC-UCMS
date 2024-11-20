#include "utils.cpp"
using namespace  std ;
class Email
{
    string email ;

public:
    static bool is_valid_email (string s){
        const regex pattern(R"((\w+)(\.{0,1}(\w+))*@(\w+)(\.\w+)+)");

        return regex_match(s, pattern);
    }
    Email(){email="";};
    explicit Email(string s ){
        set_email(s);
    }
    string get_email(){
        return email ;
    }
    void set_email(string s){
        if ( !is_valid_email(s)){
            throw invalid_argument("Invalid email");
        }
        email = s;
    }

    bool operator==(Email e){
        return email == e.get_email();
    }


};


