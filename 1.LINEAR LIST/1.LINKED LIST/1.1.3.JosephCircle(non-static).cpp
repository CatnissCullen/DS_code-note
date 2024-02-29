# include <iostream>
using namespace std;
typedef struct man{
    int num;
    struct man* next_man;
}Man;
int main(){
    int m;
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        Man* head=new Man[1];//Í·½áµã
        head->next_man=NULL;
        Man* p=head; Man* q;
        for(int i=1;i<=n;++i){
            q=new Man[1];
            q->num=i; q->next_man=p->next_man; p->next_man=q;
            p=p->next_man;
        }
        p->next_man=head->next_man;
        p=head->next_man;
        int k=1; int cnt=n;
        while(cnt>1){
            ++k;
            if(k!=3) p=p->next_man;
            else{
                printf("%d ",p->next_man->num);
                q=p->next_man; p->next_man=p->next_man->next_man; delete(q);
                k=1; p=p->next_man;
                --cnt;
            }
        }
        printf("%d \n",p->num);
    }
}

