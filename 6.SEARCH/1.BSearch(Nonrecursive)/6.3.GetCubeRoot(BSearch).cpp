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
    if(x>=0) {//��������
        if(x>=1) high=x; //�Ǵ�С��
        else high=1/x; //��С��
        low=0;
    }
    else {//��������
        if(x<=-1) low=x; //�Ǵ�С��
        else low=1/x; //��С��
        high=0;
    }
    while(high-low>e){
        mid=(low+high)/2;
        if(mid*mid*mid>=x) high=mid;
        else low=mid;
    }
    printf("%.6lf",mid);
}
