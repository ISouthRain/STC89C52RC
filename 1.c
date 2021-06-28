#include "8052.h"
#include "C:\Users\Admin\Desktop\STC89C52RC\h_file\LED\ALotOfLed.h"
#include "C:\Users\Admin\Desktop\STC89C52RC\h_file\LED\OneLed.h"
#include "C:\Users\Admin\Desktop\STC89C52RC\h_file\Delay.h"
void main()
{
		unsigned char i;
		Delay(500000);
		MoreLed_P1(0x7f);
		for(i=0;i<8;i++){
				Delay(500000);
				P1>>=1;
		}
		while(1){
            Delay(500000);
            MoreLed_P1(0xf7);
		for(i=0;i<8;i++){
				Delay(500000);
				P1>>=1;
		}
		}
}