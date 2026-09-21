#include <string>
#include <set> 
#include <iostream> 

using namespace std;

bool check_inside(int x, int y)
{
    if(x <= 5 && x >= -5 && y <= 5 && y >= -5)
        return true;
    return false;
}

int solution(string dirs) {
    int answer = 0;
 
    set<tuple<int, int, int, int>> visits;
    
    int cur_x = 0;
    int cur_y = 0;
    for(auto& e : dirs)
    {
        int next_x = cur_x;
        int next_y = cur_y;
        if(e == 'U')
        {
            if(check_inside(cur_x, cur_y + 1))
                next_y += 1;
        }
        else if (e == 'D')
        {
            if(check_inside(cur_x, cur_y - 1))
                next_y -= 1;
        }
        else if (e == 'R')
        {
            if(check_inside(cur_x + 1, cur_y))
                next_x += 1;
        }
        else if (e == 'L')
        {
            if(check_inside(cur_x - 1, cur_y))
                next_x -= 1;
        }
        
        if(next_x != cur_x || next_y != cur_y)
        {
            tuple<int, int, int, int> t1 = {cur_x, cur_y, next_x, next_y};
            tuple<int, int, int, int> t2 = {next_x, next_y, cur_x, cur_y};

            visits.insert(t1);
            
            visits.insert(t2);
            
            cur_x = next_x;
            cur_y = next_y;
        }
    }
    
    answer = visits.size() / 2;
    
    return answer;
}