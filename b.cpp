#include<bits/stdc++.h>

using namespace std;
unsigned float_i2f(int x) {
 if (x==0) return 0;
 int nowx;
 unsigned sign,t,E,ans,p;
 
 sign = x>>31;
 if (sign) x=~x+1;
 x++;
 nowx =x;
 t = 0;
 if (nowx>>16) {
 	t=t+16;
	nowx=nowx>>16;
 }
 if (nowx>>8){
 	t=t+8;
	nowx=nowx>>8;
 }
 if (nowx>>4){
 	t=t+4;
	nowx=nowx>>4;
 }
 if (nowx>>2){
 	t=t+2;
	nowx=nowx>>2;
 }
 if (nowx>>1)
 {
 	t=t+1;
	nowx=nowx>>1;
 }
 printf("%d\n",t);

 E=t+127;
 nowx = x;
 ans = x+~(1<<t)+1;
 while (t>23) {
 	ans = ans>>1;
	t--;
}
while (t<23){
    ans = ans<<1;
	t++;
}
 if (sign) ans= ans + (1<<31);
 ans = ans +(E<<23);
 return ans;
}

int main()
{
    printf("%x\n",float_i2f(2139095039));
     return 0;
}
