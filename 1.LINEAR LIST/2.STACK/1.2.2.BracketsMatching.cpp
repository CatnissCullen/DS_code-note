# include <iostream>
# include <map>
# include <cstring>
using namespace std;
# define N 10010
char s[N];
char t[N];
int flag=1,top=-1;
int n;
int main(){
    map<char,char> m;
    m[')']='('; m[']']='[';
    cin>>n;
    while(n--){
        flag=1,top=-1;
        memset(s,0,sizeof(s));
        getchar();
        scanf("%s",t);
        int i=0;
        while(t[i]!='\0'){
            if(t[i]=='('||t[i]=='[') s[++top]=t[i];
            else{
                if(s[top]==m[t[i]]) --top;
                else{
                    printf("No\n");
                    flag=0;
                    break;
                }
            }
            ++i;
        }
        if(flag==1){
            if(top==-1) printf("Yes\n");
            else printf("No\n");
        }
    }
}
