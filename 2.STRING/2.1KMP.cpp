# include <iostream>
using namespace std;
# define N 100010
# define M 1000010
int n,m;
char s[N],a[M];//s：模板串，a：主串 
int next_I[N];//next_I[1]=0，生成next_I的起点（next_I[j]：j=1时为0；j不为1时，为s在第j位以前最长的前后缀重复长度+1） 
int main(){
    cin>>n; scanf("%s",s+1);//从下标1开始存 
    cin>>m; scanf("%s",a+1);
    int i=1,j=0;//求next_I，与正式匹配的过程类似
	while(i<n){
        if(!j||s[i]==s[j]){
        	++i; ++j;
        	next_I[i]=j;//设置当前i的next值为j（j记录i前面最长的前后缀重复长度） 
		}
		else j=next_I[j];
    }
    i=1,j=1;//k是主串中的下标，初始时为匹配起点，j是模板串前缀的尾下标，初始时为1
    while(i<=n&&j<=m){//正式匹配 
    	if(!j||s[i]==s[j]){
    		++i; ++j;
		}
		else j=next_I[j];//i不变，j回溯到最远位置，即子串尽可能向右移动 
	}
	if(j>m) cout<<i-m;//打印匹配成功的起始位置 
	else cout<<"non";
    
    return 0;
}
//改进：求nextval 
while(i<n){
        if(!j||s[i]==s[j]){
        	++i; ++j;
//        	if(s[i]!=s[j]) nextval[i]=j;
//        	else next_I[i]=nextval[j];
		}
		else j=nextval[j];
    }

