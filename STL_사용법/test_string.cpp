#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cstdio>
using namespace std;

/* 아래 주석한 것 중 문제 풀이 때, 사용될 수 있는 것은 주석해제를 하고 아니면 삭제.*/

#define INIT_MAX -987654321
#define INIT_MIN 987654321

// 4 방향
// int dr[] = {0,0,1,-1};
// int dc[] = {1,-1,0,0};

// 8 방향
// int dr[] = {0,0,1,-1,1,1,-1,-1};
// int dc[] = {1,-1,0,0,-1,1,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    //getline으로 한 줄 input 받기
    string input;
    getline(cin, input);

    //구분자로 string 끊어주기
    stringstream ss(input);
    string temp;

    while(getline(ss,temp,' ')){
        cout << temp << "\n";
    }
    
    /*
    string a = "I am string one!"; 
    string b = "string";
    if (a.compare(b) == 0) 
    { // 두 문자열이 같을 때 } 
    else if (a.compare(b) < 0) 
    { // a가 b보다 사전순으로 앞일 때 } 
    else if (a.compare(b) > 0) { // a가 b보다 사전순으로 뒤일 때 }

    출처: https://makerj.tistory.com/127
    */
    
    /*
    remove의 역할: '{'에 해당하는 문자를 모두 string 맨 뒤로 보내버린다.
    erase의 역할: 
    cur.erase(remove(cur.begin(), cur.end(), '{'), cur.end());
    
    출처: https://modoocode.com/266
    */
    
    // string aaa = "[aaa]1000,[bbb]2000,[ccc]3000,[ddd]";

    //[] 삭제(간편)
    // aaa.erase(remove(aaa.begin(), aaa.end(), ']'), aaa.end());
    // aaa.erase(remove(aaa.begin(), aaa.end(), '['), aaa.end());
    // cout << aaa << "\n";

    /*
    string to integer
    c_str()
    atoi()
    
    출처: https://blockdmask.tistory.com/39
    */
    
    return 0;
}
