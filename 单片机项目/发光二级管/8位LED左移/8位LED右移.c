#include<8052.h>
#include"C:\Users\Admin\Desktop\STC89C52RC\LED.h"
#include"C:\Users\Admin\Desktop\STC89C52RC\Delay.h"
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