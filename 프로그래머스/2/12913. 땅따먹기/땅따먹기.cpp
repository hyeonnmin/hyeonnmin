#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    vector<int> record = land[0];
    
    for(int r = 1; r < land.size(); ++r)
    {
        vector<int> pre = record;
        for(int c = 0; c < 4; ++c)
        {
            int max_value = 0;            
            for(int i = 0; i < 4; ++i)
            {
                if(i != c)
                    max_value = max(max_value, pre[i]);
            }
            record[c] = max_value + land[r][c];
        }
    }
    
    for(int i = 0; i < 4; ++i)
        answer = max(answer, record[i]);

    return answer;
}