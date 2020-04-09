#include<bits/stdc++.h>
using namespace std;

/*
3 
02:10 
200 

输出：
周几
时间
*/
int main() {
    int now_day; string time; int interval;
    string tmp_hour; string tmp_minute; int comma;
    cin >> now_day >> time >> interval;
    tmp_hour = time.substr(0, 2);
    tmp_minute = time.substr(3);
    int hour = stoi(tmp_hour);
    int minute = stoi(tmp_minute);
    int cur_time = hour * 60 + minute;
    
    interval = interval % 10080;
    int i = interval / 1440;
    i = i % 7;
    interval = interval % 1440; //不处理天数
    int pre_time = cur_time - interval;
    int pre_day = now_day;
    if (pre_time < 0) {
        pre_day--;
        pre_time = 1440 - abs(pre_time);
    }
    pre_day -= i;
    if (pre_day < 0) pre_day += 8;
    int pre_hour = pre_time / 60; int pre_minute = pre_time % 60;

    cout << pre_day << endl;
    if (pre_hour < 10) cout << "0";
    cout << pre_hour << ":";
    if (pre_minute < 10) cout << "0";
    cout<< pre_minute << endl;
    return 0;
}
