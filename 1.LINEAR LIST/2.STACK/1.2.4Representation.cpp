# include <iostream>
# include <map>
using namespace std;
# define N 5000000//尽量开多一点！！！不能只开到表达式最大长度，因为加上数值间隔符会多于表达式长度 ！ 
char post[N];//队列：后缀表达式（存字符，每个数值后用‘\0’结束）
int tmp[N];//栈：暂存符号（求后缀表达式时，存ASCII码）或数值（求表达式的值时，存整数）
int r=-1, top=-1;;//队尾指针、栈顶指针
map<char,int> pri={{'(',-1},{'+',0},{'-',0},{'*',1},{'/',1}};//优先级：乘除>加减>左括号
int Calculation(char op,int x,int y);//四则运算
int main(){//表达式求值：①将中缀表达式转化为后缀表达式；②据后缀表达式求值
    string rpt;//用字符串读入表达式
    cin>>rpt;
    int i=0, j;
    while(rpt[i]){//① 先将原数学表达式（中缀）转化为后缀表达式输入队列post
        if(rpt[i]<='9'&&rpt[i]>='0'){//数字：找到完整数值各位数字入队，以'\0'结束
            j=i;
            while(rpt[j]<='9'&&rpt[j]>='0')
                post[++r]=rpt[j++];
            post[++r]='\0'; i=j;//i更新到j
        }
        else if('('==rpt[i]) tmp[++top]=rpt[i++]; //左括号：直接入栈，等待右括号匹配
        else if(')'==rpt[i]){//右括号：栈顶出栈并入队直至左括号出栈，左括号不入队
            while('('!=tmp[top]) post[++r]=tmp[top--];  --top;//左括号出栈
            ++i;
        }
        else{ //运算符：栈顶出栈并入队直至栈顶优先级小于当前符号，然后当前符号入栈
            while(top>=0&&pri[rpt[i]]<=pri[tmp[top]]) post[++r]=tmp[top--];
            tmp[++top]=rpt[i++];//当前符号入栈
        }
    }
    while(top>=0) post[++r]=tmp[top--];//栈中残留的符号全部入队
    int x,y;
    i=0;
    while(i<=r){//② 据后缀表达式求表达式的值（初始状态：队列为后缀表达式，栈空）
        if(post[i]<='9'&&post[i]>='0'){//数字：取完整数值，直接入栈
                x=post[i]-'0'; j=i+1;
                while(post[j]) x=x*10+(post[j++]-'0');//求完整数值（遇到'\0'结束）
                tmp[++top]=x;//数值入栈
                i=j+1;//i更新到'\0'下一位
        }
        else{//运算符：栈顶出栈两数进行运算，运算结果再入栈
            y=tmp[top--]; x=tmp[top--];
            tmp[++top]=Calculation(post[i], x, y);
            ++i;
        }
    }//计算结束，栈内只有一个数，即最终结果
    cout<<tmp[top];
}
int Calculation(char op,int x,int y){
    switch (op) {
        case '+': return x+y;
        case '-': return x-y;
        case '/': return x/y;
        case '*': return x*y;
    }
}
