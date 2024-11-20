#include <string>
#include <vector>
#include <regex>
#include <random>

using namespace std ;

string to_csv(vector<string>& data){
    // Function to convert a vector of strings to a CSV string
    string result ;

    for ( auto d : data){
        result += ',';
        result += d; // Convert any type to string

    }
    return result ;
}

int generate_random_int(int mn , int mx ){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(mn, mx);
    return dis(gen);
}


string generate_unique_id() {
    string id  ;
    for (int i = 0; i < 10; i++) {
        id += to_string(generate_random_int(0, 9));
    }
}

bool is_valid_phone_number(string s){
    const regex pattern(R"(\d{3}-\d{3}-\d{4})");

    return regex_match(s, pattern);
}
