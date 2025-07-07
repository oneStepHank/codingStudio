#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p_c = 0 , y_c = 0;
    for(char c : s){
        if(c == 'P' || c == 'p')
            p_c++;
        else if(c == 'y' || c == 'Y')
            y_c++;
    }
    
    return p_c==y_c;
}