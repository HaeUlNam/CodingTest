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
#include<cmath>
using namespace std;

#define INIT_MAX -987654321
#define INIT_MIN 987654321

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = min(init(a, tree, node*2, start, (start+end)/2),init(a, tree, node*2+1, (start+end)/2+1, end));
    }
}

long long update(vector<long long> &tree, int node, int start, int end, int index, long long num) {
    if (index < start || index > end) return tree[node];
    if (start == end){
        return tree[node] = num;
    }
    
    int left = update(tree,node*2, start, (start+end)/2, index, num);
    int right = update(tree,node*2+1, (start+end)/2+1, end, index, num);

    return tree[node] = min(left, right);
}

long long minimum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0x7f7f7f7f;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }

    return min(minimum(tree, node*2, start, (start+end)/2, left, right), minimum(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);

    vector<long long> input = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};

    //Max 세그먼트 트리 만들기
    int h = (int)ceil(log2(input.size()));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);

    //세그먼트 init
    init(input, tree, 1, 0, input.size() - 1);

    //세그먼트 update
    update(tree, 1, 0, input.size() - 1, 1, 15);

    //세그먼트 sum
    cout << minimum(tree, 1, 0, input.size() - 1, 0, 2) << "\n";
    cout << minimum(tree, 1, 0, input.size() - 1, 1, 3) << "\n";
    cout << minimum(tree, 1, 0, input.size() - 1, 2, 4) << "\n";

    //출처: 
    return 0;
}
