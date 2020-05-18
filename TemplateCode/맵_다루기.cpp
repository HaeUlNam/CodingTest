#include<iostream>​
#include<vector>
#include<queue>         //queue(front), priority_queue(top)
#include<functional>    //greater, less
#include<algorithm>     //sort
#include<climits>       //INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN
#include<map>
#include<sstream>
#include<string>
using namespace std;

int Map[4][4] = {{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};

//시계 방향
void rotate1(int map[4][4]){
    int tmp[4][4] = {0};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            tmp[j][3 - i] = map[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            map[i][j] = tmp[i][j];
        }
    }
}


//반시계방향
void rotate2(int map[4][4]){
    int tmp[4][4] = {0};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            tmp[3 - j][i] = map[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            map[i][j] = tmp[i][j];
        }
    }
}

//세로 뒤집기 
void flip1(int map[4][4]){
    int tmp[4][4] = {0};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            tmp[3 - i][j] = map[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            map[i][j] = tmp[i][j];
        }
    }
}

//가로 뒤집기
void flip2(int map[4][4]){
    int tmp[4][4] = {0};

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            tmp[i][3 - j] = map[i][j];
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            map[i][j] = tmp[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    
    rotate1(Map);
    //rotate2(Map);
    //flip1(Map);
    //flip2(Map);

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
