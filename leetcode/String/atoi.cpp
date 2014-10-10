#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        bool negative = false;
        long long result;
        
        while (*str && isspace(*str)) {
            ++str;
        }
        
        if (!*str) {
            return 0;
        }
        
        if (*str == '+' || *str == '-') {
            negative = (*str == '-' ? true : false);
            str++;
        }
        
        bool success = getNext(str, result);
        if (!success) {
            return 0;
        }
        
        if (result > INT_MAX) {
            return INT_MAX;
        }
        
        if (result < INT_MIN) {
            return INT_MIN;
        }
        return (negative ? -result : result);
    }
    
    bool getNext(const char *str, long long &result) {
        
        string s = "0123456789";
        
        if (!isalnum(*str)) {
            return false; 
        }
        result = 0;
        
        while (*str) {
            if (s.find(*str) != string::npos){
                result = result * 10 + (*str - '0');
            } else {
                break;
            }
            
            str++;
        }
        
        return true;
    }
};

int main() {
	cout << atoi("-2147483648") << endl;
	return 0;
} 
