# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <cstring>
using namespace std;
# define ElemType char
# define Address int
# define WghType int
typedef struct{
    Address pr, l, r;
}HTNode;
typedef struct{
    Address sf;
    WghType w;
}Weight;
typedef struct{
    ElemType c;
    string code;
}Code;
HTNode* HT;//树（只存结点链接关系，下标是结点索引）
vector<Weight> wghs;//辅助建树的排序数组（只存无父结点的结点索引和权值，下标是大小次序）
Code* codes;//最终编码结果（只存叶子字符和编码，下标是叶子结点索引）
map<ElemType,int> indexes;//字符到叶子结点索引的映射
int n;//字符（叶子）总数
Address idx;//可变索引，记录当前为占用的最小结点索引
void BuildHT();
void SetCode();
string Encode(char* s);
string Decode(char* s);
void JudgeCode();//①WPL正确；②两两编码不互为前缀（可用strncmp求，n设为str1、str2中较短的长度）；若只是检查是否为正确编码，则只用建树并求编码长度即可，不用编码
int main(){
    cin>>n;//叶子总数
    HT=new HTNode[2*n]();//树的总结点数为2*n-1，数组多一位空出0索引表示无父结点；加()初始化父结点、孩子结点索引为0
    codes=new Code[n + 1]();//编码索引与树中叶子索引一致；加()初始化编码串为空
    ElemType c; WghType w;
    for(idx=1; idx<=n; ++idx){
        scanf("%*c%c%*c%d", &c, &w);
        codes[idx].c=c; wghs.push_back({idx, w}); //初始化编码表：存入叶子字符，编码索引范围1~n；初始化排序数组：存入叶子索引和叶子权值；
        indexes[c]=idx; //初始化字符到索引的映射
    }
    BuildHT();
    SetCode();
    char str[1000];
    getchar();
    gets(str);
    cout<<Encode(str)<<endl;
    gets(str);
    cout<<Decode(str)<<endl;
}
bool CmpWeight(Weight a,Weight b){
    return a.w < b.w;
}
void BuildHT(){
    while(idx<=2*n-1){//不能用wgh不空作循环标志，可以用wgh长度大于1，因为wgh还剩一个结点时它以及是根结点，树已经建好了
        sort(wghs.begin(),wghs.end(), CmpWeight);//对无父结点的结点权值排序
        HT[idx]={0,wghs[0].sf,wghs[1].sf};//链接新的结点到权值最小的两个结点
        HT[wghs[0].sf].pr=idx; HT[wghs[1].sf].pr=idx;
        wghs.push_back({idx,wghs[0].w+wghs[1].w});//更新排序数组
        wghs.erase(wghs.begin()); wghs.erase(wghs.begin());
        ++idx;//更新可变索引
    }
}
void SetCode(){//从叶子回溯，得到逆编码，再reverse
    for(int i=1;i<=n;++i){//遍历1~n的结点，即叶子
        Address p=i;
        while(HT[p].pr){
            if(p==HT[HT[p].pr].l) codes[i].code.push_back('0');
            else codes[i].code.push_back('1');
            p=HT[p].pr;
        }
        reverse(codes[i].code.begin(),codes[i].code.end());
        cout<<"["<<codes[i].c<<"]"<<" "<<codes[i].code<<endl;
    }
}
string Encode(char* s){
    string res;
    for(int i=0;s[i];++i) res+=codes[indexes[s[i]]].code;
    return res;
}
string Decode(char* s){//从根结点开始根据各位编码找分支，直到无孩子结点，则求完一个字符，返回根结点
    string res;
    int i=0;
    while(1){
        Address p=2*n-1;//最后一个结点是根结点
        while(HT[p].l){//没有左孩子必没有右孩子
            if('0'==s[i]) p=HT[p].l;
            else p=HT[p].r;
            ++i;
        }
        res.push_back(codes[p].c);//解出一个字符
        if(!s[i]) break;//对s解码结束
    }
    return res;
}

