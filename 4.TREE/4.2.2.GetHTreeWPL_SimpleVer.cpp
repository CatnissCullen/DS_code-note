# include <iostream>
# include <algorithm>
using namespace std;
# define N 10000
int w[N];
int main(){
	int n,WPL=0;
	cin>>n;
	for(int i=0;i<n;++i) cin>>w[i];
	sort(w,w+n);
	for(int i=0;i<n-1;++i){
		w[i+1]+=w[i];
		WPL+=w[i+1];
		sort(w+i+1,w+n);
	}
	cout<<WPL;
}
