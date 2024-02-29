//求二叉树每一层的序列 
int lev[N];//记录各结点所在层号
queue<int>  qu;//层序（队列） 
vector<vector<int>> levs;//各层结点索引，在main函数中把一维resize成n+2（+1为了下标
//从1起，+2为了以最后一层的下一层的size为0作为所有层输出的结束标志） 
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
