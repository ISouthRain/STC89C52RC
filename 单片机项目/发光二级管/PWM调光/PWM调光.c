#include <8052.h>
#define LED P1_0
void Delay(unsigned int t);
void main()
{
		unsigned int C=600,P=0;
		while(1){
				LED=1;
				Delay(6000);
				for(P=1;P<C;P++){
						LED=0;
						Delay(P);
						LED=1;
						Delay(C-P);
				}
				LED=0;
				for(P=C-1;P>0;P--){
						LED=0;
						Delay(P);
						LED=1;
						Delay(C-P);
				}
		}
}
void Delay(unsigned int t)
{
		while(--t);
}
