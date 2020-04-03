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

#define INIT_MAX -987654321
#define INIT_MIN 987654321

int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = max(init(a, tree, node*2, start, (start+end)/2),init(a, tree, node*2+1, (start+end)/2+1, end));
    }
}

void update(vector<int> &tree, int node, int start, int end, int index, int num) {
    if (index < start || index > end) return;
    tree[node] = max(tree[node], num);
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, num);
        update(tree,node*2+1, (start+end)/2+1, end, index, num);
    }
}

int maximum(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return max(maximum(tree, node*2, start, (start+end)/2, left, right), maximum(tree, node*2+1, (start+end)/2+1, end, left, right));
}

//stones이 원 데이터
int solution(vector<int> stones, int k) {
    //Max 세그먼트 트리 만들기
    int h = (int)ceil(log2(stones.size()));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);

    //세그먼트 init
    init(stones, tree, 1, 0, stones.size() - 1);

    //세그먼트 update
    update(tree, 1, 0, stones.size() - 1, 1, 15);

    int ssize = k - 1;
    int mmin = INIT_MIN;
    
    //3개씩 max 구간쿼리
    for(int i = 0; i <= stones.size() - k; ++i){
        mmin = min(mmin, maximum(tree, 1, 0, stones.size() - 1, i, i + ssize));
    }

    return mmin;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    cout << solution(stones, 3);   

    return 0;
}
