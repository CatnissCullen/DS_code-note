# include <iostream>
using namespace std;
# define N 100010
# define M 1000010
int n,m;
char s[N],a[M];//s��ģ�崮��a������ 
int next_I[N];//next_I[1]=0������next_I����㣨next_I[j]��j=1ʱΪ0��j��Ϊ1ʱ��Ϊs�ڵ�jλ��ǰ���ǰ��׺�ظ�����+1�� 
int main(){
    cin>>n; scanf("%s",s+1);//���±�1��ʼ�� 
    cin>>m; scanf("%s",a+1);
    int i=1,j=0;//��next_I������ʽƥ��Ĺ�������
	while(i<n){
        if(!j||s[i]==s[j]){
        	++i; ++j;
        	next_I[i]=j;//���õ�ǰi��nextֵΪj��j��¼iǰ�����ǰ��׺�ظ����ȣ� 
		}
		else j=next_I[j];
    }
    i=1,j=1;//k�������е��±꣬��ʼʱΪƥ����㣬j��ģ�崮ǰ׺��β�±꣬��ʼʱΪ1
    while(i<=n&&j<=m){//��ʽƥ�� 
    	if(!j||s[i]==s[j]){
    		++i; ++j;
		}
		else j=next_I[j];//i���䣬j���ݵ���Զλ�ã����Ӵ������������ƶ� 
	}
	if(j>m) cout<<i-m;//��ӡƥ��ɹ�����ʼλ�� 
	else cout<<"non";
    
    return 0;
}
//�Ľ�����nextval 
while(i<n){
        if(!j||s[i]==s[j]){
        	++i; ++j;
//        	if(s[i]!=s[j]) nextval[i]=j;
//        	else next_I[i]=nextval[j];
		}
		else j=nextval[j];
    }

