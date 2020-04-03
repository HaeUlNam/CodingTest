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

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> vec = {1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,5,5,5,5};

    //3이 가장 처음 나오는 idx. iterator 반환이라 begin을 빼주면 Idx가 나온다.
    cout << lower_bound(vec.begin(), vec.end(), 3) - vec.begin() << "\n";

    //3인 값이 마지막 나오는 부분의 idx를 return
    cout << lower_bound(vec.begin(), vec.end(), 4) - vec.begin() << "\n";
    
    //3인 값이 마지막 나오는 부분의 idx를 return
    cout << upper_bound(vec.begin(), vec.end(), 3) - vec.begin() << "\n";

    //3인 값이 마지막 나오는 부분의 idx를 return
    cout << upper_bound(vec.begin(), vec.end(), 4) - vec.begin() << "\n";
    

    vector<int> vec2 = {5,5,5,6,6};

    //4를 검색했을 때, 0이 나온다.
    cout << lower_bound(vec2.begin(), vec2.end(), 4) - vec2.begin() << "\n";

    return 0;
}
