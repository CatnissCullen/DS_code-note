# include <iostream>
using namespace std;
# define N 60
typedef struct{
	int num;
	int nxt;
}Player;
int T;
int n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		Player a[N];
		
		for(int i=1;i<=n;++i){
			a[i].num=i; a[i].nxt=i+1;
		}
		a[n].nxt=1;
		
		int p=1;
		while(n--){
			p=a[p].nxt;
			cout<<a[a[p].nxt].num<<" ";
			a[p].nxt=a[a[p].nxt].nxt;
			p=a[p].nxt;
		}
		
		cout<<endl;
	}
	return 0;
}

