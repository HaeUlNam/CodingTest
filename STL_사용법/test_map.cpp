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

/*
    출처: https://gracefulprograming.tistory.com/3

    - 데이터가 많을수록 unorder_map이 map보다 좋다. (실험 그래프 상 웬만하면 unordered_map 사용하는 게 좋을 듯)
    - 해싱 overhead 때문에 문자열의 길이가 길어질수록 map의 성능이 unordered_map보다 좋아진다.
    
    -> 무조건 unordered_map 쓰고, 문자열일 경우 map으로 최적화할 수 있는지 체크하면 될 듯.
    -> 참고로 오름차순 출력이 필요할 때는 map 사용하는게 좋음.
*/

struct info{
    int idx, count;

    info(int _idx, int _count){
        idx = _idx;
        count = _count;
    }

    bool operator<(const info & aa) const {
        if(idx == aa.idx){
            return count < aa.count;
        }
        return idx < aa.idx;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> vec = {1,1,4,1,1,1,2,1,2,2,2,2,2,2,3,3,3};

    map<int, int> m;

    // 각 숫자 개수 세기    
    for(int i = 0; i < vec.size(); ++i){
        int cur = vec[i];
        if(m.find(cur) == m.end()){
            m[cur] = 1;
        }
        else{
            ++m[cur];
        }
    }
    
    //map은 오름차순, unordered_map은 순서가 없다.
    for(auto aa : m){
        cout << aa.first << " " << aa.second << "\n";
    }

    map<info, int> im;

    im.insert(make_pair(info(1,2),2));
    im.insert(make_pair(info(2,3),2));
    im.insert(make_pair(info(2,2),2));
    im[info(1,2)] = 3;

    for(auto bb: im){
        cout << bb.first.idx << "/" << bb.first.count << "/" << bb.second << "\n";
    }

    return 0;
}
