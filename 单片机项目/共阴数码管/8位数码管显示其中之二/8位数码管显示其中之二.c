#include<8052.h>
#define CH2 P2_2
#define CH3 P2_3
#define Port P0
main()
{
		while(1){
				Port=0x7e;
				CH3=1;
				CH3=0;

				Port=0x4F;
				CH2=1;
				CH2=0;
		}
}