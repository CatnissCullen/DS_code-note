//�������ÿһ������� 
int lev[N];//��¼��������ڲ��
queue<int>  qu;//���򣨶��У� 
vector<vector<int>> levs;//��������������main�����а�һάresize��n+2��+1Ϊ���±�
//��1��+2Ϊ�������һ�����һ���sizeΪ0��Ϊ���в�����Ľ�����־�� 
void Set_levs(int p){
    qu.push(p);
    lev[p]=1;
    levs[1].push_back(p);
    while(qu.size()){
        int t=qu.front(); qu.pop();        
        if(lch[t]!=-1){
            lev[lch[t]]=lev[t]+1;
            levs[lev[lch[t]]].push_back(lch[t]);
            qu.push(lch[t]);
        }
        if(rch[t]!=-1){
            lev[rch[t]]=lev[t]+1;
            levs[lev[rch[t]]].push_back(rch[t]);
			qu.push(rch[t]);
        }
    }
}
