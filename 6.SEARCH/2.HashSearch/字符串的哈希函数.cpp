/*用字符串（名字）的哈希函数求索引*/
//MAXSIZE是哈希表最大有效存储长度（从1起） 
int GetHashIndex(char* FName){
    unsigned long long index=0;
    unsigned long long a=12345,b=67891;
    //求索引值
    while(*FName){
        index=(index*a+*FName)%MAXSIZE;
        FName++; a*=b;
    }
    return index+1;
}
//可以另外用一个数组记录有效哈希索引值 
