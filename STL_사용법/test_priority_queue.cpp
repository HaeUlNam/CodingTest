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

struct info{
    int idx, count;
};

struct cmp{
    bool operator()(info a, info b){
        if(a.idx == b.idx){     //idx 같은 경우, count 큰 거 순서대로
            return a.count < b.count;
        }
        return a.idx < b.idx;   //idx 큰 거 순서대로
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    //내림차순--결과: 9 7 5 3 1
    priority_queue<int> pq;
    //위는 priority_queue<int, vector<int>, less<int>> pq;와 동일한 코드
    pq.push(1); pq.push(3); pq.push(5); pq.push(7); pq.push(9);

    //오름차순--결과: 1 3 5 7 9
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1); pq2.push(3); pq2.push(5); pq2.push(7); pq2.push(9);


    //구조체 우선순위큐
    priority_queue<info, vector<info>, cmp> pq3;
    pq3.push({1,2}); pq3.push({4,3}); pq3.push({4,4}); pq3.push({5,1}); pq3.push({1,1});

    //첫번째 요소 큰거, 두번째 요소 큰거 기준
    while(!pq3.empty()){
        cout << pq3.top().idx << "/" << pq3.top().count << "\n";
        pq3.pop();
    }

    return 0;
}
