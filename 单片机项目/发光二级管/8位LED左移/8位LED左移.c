#include<8052.h>
void Delay(unsigned int t);
void main()
{
		unsigned char i;
		Delay(500000);
		P1=0x7f;
		for(i=0;i<8;i++){
				Delay(500000);
				P1>>=1;
		}
		while(1){

		}
}

void Delay(unsigned int t)
{
		while(--t);
}
