#include <string>
#include <unordered_map>
#include <set> 
#include <iostream>

using namespace std;

bool check_alpha(char& c)
{
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    set<string> s;
    
    for(int i = 0; i < str1.size() - 1; ++i)
    {
        char c1 = str1[i];
        char c2 = str1[i + 1];
        
        if(check_alpha(c1) && check_alpha(c2))
        {
            int indent = 'a' - 'A';
            if(c1 < 'a')
                c1 += indent;
            if(c2 < 'a')
                c2 += indent;
            
            string input;
            input += char(c1);
            input += char(c2);
            
            m1[input]++;
            s.insert(input);
        }
    }
    
    for(int i = 0; i < str2.size() - 1; ++i)
    {
        char c1 = str2[i];
        char c2 = str2[i + 1];
        
        if(check_alpha(c1) && check_alpha(c2))
        {
            int indent = 'a' - 'A';
            if(c1 < 'a')
                c1 += indent;
            if(c2 < 'a')
                c2 += indent;
            
            string input;
            input += char(c1);
            input += char(c2);
            
            m2[input]++;
            s.insert(input);
        }
    }
    
    float n1 = 0;
    float n2 = 0;
    for(auto& e : s)
    {
        n1 += min(m1[e], m2[e]);
        n2 += max(m1[e], m2[e]);
    }
    
    float value = 1;
    if(n2 == 0)
        return 65536;
    
    value = (n1 / n2) * 65536;

    answer = value;
    return answer;
}