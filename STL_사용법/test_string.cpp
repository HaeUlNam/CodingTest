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
    
    return 0;
}
