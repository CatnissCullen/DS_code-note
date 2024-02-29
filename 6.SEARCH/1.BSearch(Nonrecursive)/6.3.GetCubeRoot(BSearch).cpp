# include <stdio.h>
# define e 1e-8
void GetSquareRoot_BSearch(double x);
int main(){
    double x;
    printf("Enter a number to get its cube root: ");
    scanf("%lf",&x);
    GetSquareRoot_BSearch(x);
}
void GetCubeRoot_BSearch(double x) {
    double low,mid,high;
    if(x>=0) {//正数开根
        if(x>=1) high=x; //非纯小数
        else high=1/x; //纯小数
        low=0;
    }
    else {//负数开根
        if(x<=-1) low=x; //非纯小数
        else low=1/x; //纯小数
        high=0;
    }
    while(high-low>e){
        mid=(low+high)/2;
        if(mid*mid*mid>=x) high=mid;
        else low=mid;
    }
    printf("%.6lf",mid);
}
