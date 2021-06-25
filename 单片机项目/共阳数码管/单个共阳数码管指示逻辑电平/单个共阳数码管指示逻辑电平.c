#include<8052.h>
#define ON P3_2
void main (void)
{
		while(1){
				if(ON==1)
						P1=0x89;//"H"
				else
						P1=0xc7;//"L"
		}
}
