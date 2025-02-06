#include <string>
#include <vector>

using namespace std;

int convertTime(string time){
    int res;
    res = stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
    return res;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int runningTime = convertTime(video_len);
    int current = convertTime(pos);
    
    int opStart_time = convertTime(op_start);
    int opEnd_time = convertTime(op_end);
    for(size_t i = 0 ; i < commands.size() ; i++){
        if(current >= opStart_time && current <= opEnd_time){
            current = opEnd_time;
        }
        if(commands[i] == "prev"){
            current = current > 10 ? current-10 : 0;
        }else{
            current = current < runningTime - 10? current + 10 : runningTime;
        }
    }
    if(current >= opStart_time && current <= opEnd_time){
            return op_end;
    }else if(current == runningTime){
        return video_len;
    }else if(current == 0){
        return "00:00";
    }else{
        
        int min = current/60;
        if(min == 0)
            answer += "00:";
        else if(min < 10)
            answer += "0"+to_string(min)+":";
        else
            answer += to_string(min)+":";
        int sec = current%60;
        if (sec == 0)
            answer += "00";
        else if(sec < 10)
            answer += "0" + to_string(sec);
        else
            answer += to_string(sec);
    }    
    return answer;
}