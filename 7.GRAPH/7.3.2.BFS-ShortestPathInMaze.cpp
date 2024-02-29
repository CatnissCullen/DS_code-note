# include <iostream>
using namespace std;
# define N 200
int maze[N][N];
int d[N][N];//每个点到起点的最少步数+1，初始化为0（表示未求过） 
int dRow[4]={0,1,0,-1};//四个方向的行差分
int dCol[4]={1,0,-1,0};//四个方向的列差分
int q[N*N][2],f=0,r=-1;//存放每个点坐标的队列（设为最多能存放迷宫内所有点）
int n,m;
int BFS();
int main(){//若要输出路径，再开一个N*N的一维数组，记录所有最短路上，每个坐标的前一个坐标是谁 
    cin>>n>>m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) scanf("%d",&maze[i][j]);
    cout<<BFS();
}
int BFS(){
    ++r; q[0][0]=0, q[0][1]=0;//起点入队
    d[0][0]=1;
    while(f<=r){//当队列不空
        auto fX=q[f++];
        for(int i=0;i<4;++i){//扩展队头并入队
            int R=fX[0]+dRow[i], C= fX[1]+dCol[i];
            if(R>=0&&R<n&&C>=0&&C<m&&!maze[R][C]&&!d[R][C]){
                d[R][C]=d[fX[0]][fX[1]]+1;
                ++r; q[r][0]=R, q[r][1]=C;
            }
        }
    }
    return d[n-1][m-1]-1;
}


