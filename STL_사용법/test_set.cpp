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

    vector<int> vec = {1,1,4,1,1,1,2,1,2,2,2,2,2,2,3,3,3};

    set<int> s;

    //각 숫자 중복 체크
    for(int i = 0; i < vec.size(); ++i){
        int cur = vec[i];
        if(s.find(cur) == s.end()){
            s.insert(cur);
        }
        else{
            cout << "already " << cur << "\n";
        }
    }
    
    for(auto aa : s){
        cout << aa << "\n";
    }

    return 0;
}
