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
HTNode* HT;//����ֻ�������ӹ�ϵ���±��ǽ��������
vector<Weight> wghs;//�����������������飨ֻ���޸����Ľ��������Ȩֵ���±��Ǵ�С����
Code* codes;//���ձ�������ֻ��Ҷ���ַ��ͱ��룬�±���Ҷ�ӽ��������
map<ElemType,int> indexes;//�ַ���Ҷ�ӽ��������ӳ��
int n;//�ַ���Ҷ�ӣ�����
Address idx;//�ɱ���������¼��ǰΪռ�õ���С�������
void BuildHT();
void SetCode();
string Encode(char* s);
string Decode(char* s);
void JudgeCode();//��WPL��ȷ�����������벻��Ϊǰ׺������strncmp��n��Ϊstr1��str2�н϶̵ĳ��ȣ�����ֻ�Ǽ���Ƿ�Ϊ��ȷ���룬��ֻ�ý���������볤�ȼ��ɣ����ñ���
int main(){
    cin>>n;//Ҷ������
    HT=new HTNode[2*n]();//�����ܽ����Ϊ2*n-1�������һλ�ճ�0������ʾ�޸���㣻��()��ʼ������㡢���ӽ������Ϊ0
    codes=new Code[n + 1]();//��������������Ҷ������һ�£���()��ʼ�����봮Ϊ��
    ElemType c; WghType w;
    for(idx=1; idx<=n; ++idx){
        scanf("%*c%c%*c%d", &c, &w);
        codes[idx].c=c; wghs.push_back({idx, w}); //��ʼ�����������Ҷ���ַ�������������Χ1~n����ʼ���������飺����Ҷ��������Ҷ��Ȩֵ��
        indexes[c]=idx; //��ʼ���ַ���������ӳ��
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
    while(idx<=2*n-1){//������wgh������ѭ����־��������wgh���ȴ���1����Ϊwgh��ʣһ�����ʱ���Լ��Ǹ���㣬���Ѿ�������
        sort(wghs.begin(),wghs.end(), CmpWeight);//���޸����Ľ��Ȩֵ����
        HT[idx]={0,wghs[0].sf,wghs[1].sf};//�����µĽ�㵽Ȩֵ��С���������
        HT[wghs[0].sf].pr=idx; HT[wghs[1].sf].pr=idx;
        wghs.push_back({idx,wghs[0].w+wghs[1].w});//������������
        wghs.erase(wghs.begin()); wghs.erase(wghs.begin());
        ++idx;//���¿ɱ�����
    }
}
void SetCode(){//��Ҷ�ӻ��ݣ��õ�����룬��reverse
    for(int i=1;i<=n;++i){//����1~n�Ľ�㣬��Ҷ��
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
string Decode(char* s){//�Ӹ���㿪ʼ���ݸ�λ�����ҷ�֧��ֱ���޺��ӽ�㣬������һ���ַ������ظ����
    string res;
    int i=0;
    while(1){
        Address p=2*n-1;//���һ������Ǹ����
        while(HT[p].l){//û�����ӱ�û���Һ���
            if('0'==s[i]) p=HT[p].l;
            else p=HT[p].r;
            ++i;
        }
        res.push_back(codes[p].c);//���һ���ַ�
        if(!s[i]) break;//��s�������
    }
    return res;
}

