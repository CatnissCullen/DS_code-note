# include <iostream>
# include <map>
using namespace std;
# define N 10010
char s[N];
int top=-1;
char t[N];
map<char,char> m;
int main(){
	m['>']='<', m[')']='(', m['}']='{', m[']']='[';
	cin>>t;
	int flg=1,i=0;
	while(t[i]){
		if(t[i]=='<'||t[i]=='['||t[i]=='{'||t[i]=='(') s[++top]=t[i];
		else{
			if(m[t[i]]!=s[top]){
				flg=0;
				cout<<"no";
				break;
			}
			else --top; 
		}
		++i;
	}
	if(flg==1){
		if(-1!=top) cout<<"no";
		else cout<<"yes";
	}
}
