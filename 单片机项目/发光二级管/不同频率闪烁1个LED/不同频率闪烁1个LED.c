#include "8052.h"
#define LEd P1_0
void Delay(unsigned int t); 
void main(void)
{
		unsigned char p;
		while (1) {
		for (p=0; p<4; p++) {
		LEd=1;
		Delay(500);
		LEd=0;
		Delay(500);
		}
		for (p=0; p<4; p++) {
		LEd = 1;
		Delay(6000);
		LEd=0;
		Delay(6000);
		}
		}
}
void Delay(unsigned int t)
{
		unsigned int i;
 while(t--){
		 for(i=0;i<100;i++){
				 ;
		 }
 }
}
