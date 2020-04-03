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
    int idx;
    int count;
};

bool cmp(info & a, info & b){
    if(a.idx == b.idx){ //idx가 같으면, count가 작은 순
        return a.count < b.count;
    }                   //idx가 다르면, idx 작은 순
    return a.idx < b.idx;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    vector<info> vec = {{2,2}, {1,2}, {2,1}, {3,3}, {3,1}};

    //첫번째 요소 오름차순, 그 다음 같다면 두번쨰 요소 오름차순
    sort(vec.begin(), vec.end(), cmp);


    vector<int> v1 = {9,8,7,6,5,4,3,2,1};

    //오름차순! 결과: 1 2 3 4 5 6 7 8 9
    sort(v1.begin(), v1.end());

    //내림차순! 결과: 9 8 7 6 5 4 3 2 1 
    sort(v1.begin(), v1.end(), greater<int>());

    return 0;
}
