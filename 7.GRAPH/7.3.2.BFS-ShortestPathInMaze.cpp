# include <iostream>
using namespace std;
# define N 200
int maze[N][N];
int d[N][N];//ÿ���㵽�������ٲ���+1����ʼ��Ϊ0����ʾδ����� 
int dRow[4]={0,1,0,-1};//�ĸ�������в��
int dCol[4]={1,0,-1,0};//�ĸ�������в��
int q[N*N][2],f=0,r=-1;//���ÿ��������Ķ��У���Ϊ����ܴ���Թ������е㣩
int n,m;
int BFS();
int main(){//��Ҫ���·�����ٿ�һ��N*N��һά���飬��¼�������·�ϣ�ÿ�������ǰһ��������˭ 
    cin>>n>>m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) scanf("%d",&maze[i][j]);
    cout<<BFS();
}
int BFS(){
    ++r; q[0][0]=0, q[0][1]=0;//������
    d[0][0]=1;
    while(f<=r){//�����в���
        auto fX=q[f++];
        for(int i=0;i<4;++i){//��չ��ͷ�����
            int R=fX[0]+dRow[i], C= fX[1]+dCol[i];
            if(R>=0&&R<n&&C>=0&&C<m&&!maze[R][C]&&!d[R][C]){
                d[R][C]=d[fX[0]][fX[1]]+1;
                ++r; q[r][0]=R, q[r][1]=C;
            }
        }
    }
    return d[n-1][m-1]-1;
}


