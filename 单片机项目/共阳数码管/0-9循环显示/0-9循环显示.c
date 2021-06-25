#include<8052.h>
void Delay(unsigned int t);
unsigned char dofly[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,};
 // 显示数值表0-9
void main()
{
		unsigned char i;
		while(1){
				for(i=0;i<10;i++){
						P1=dofly[i];
						Delay(10000);
				}
		}
}
void Delay(unsigned int t)
{
		while(--t);
}
