# include <stdio.h>
# define e 1e-8
void GetSquareRoot_BSearch(double x);
int main(){
    double x;
    printf("Enter a number to get its square root: ");
    scanf("%lf",&x);
    if(x<0){
    	printf("error - the number shouldn't be less than 0"); return 1;
	}
    GetSquareRoot_BSearch(x);
    return 0;
}
void GetSquareRoot_BSearch(double x) {
    double low,mid,high;
    low=0; 
	if(x>=1) high=x;//非纯小数开根 
	else high=1.0/x;//纯小数开根 
    while(high-low>e){
        mid=(low+high)/2;
        if(mid*mid>=x) high=mid;
        else low=mid;
    }
    printf("%.6lf",mid);
}
