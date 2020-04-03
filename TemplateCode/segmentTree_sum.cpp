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
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
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
    cout << sum(tree, 1, 0, input.size() - 1, 0, 2) << "\n";
    cout << sum(tree, 1, 0, input.size() - 1, 1, 3) << "\n";

    //출처: https://www.acmicpc.net/blog/view/9
    return 0;
}
