/*-----------------------------------------------
  名称：频率计
  论坛：www.doflye.net
  编写：shifang
  日期：2009.5
  修改：无
  内容：T0外部计数，T1计时1S，计算1S内外部脉冲个数，并在液晶显示
        频率：单位时间内完成振动的次数 这里用于电机测速 电机转盘
        有4个孔，所以测到的波形个数除以4才是转一周的时间
        然后换算成一分钟的转速
------------------------------------------------*/
#include<reg52.h> //包含头文件，一般情况不需要改动，头文件包含特殊功能寄存器的定义
#include<stdio.h>
#include"1602.h"
#include"delay.h"
#define HIGH (65536-10000)/256
#define LOW  (65536-10000)%256

//sbit LED=P1^2;    //定义LED端口
bit OVERFLOWFLAG;
bit TIMERFLAG;
/*------------------------------------------------
                    定时器0初始化子程序
					本程序用于计数
------------------------------------------------*/
void Init_Timer0(void)
{
 TMOD |= 0x01 | 0x04;	  //使用模式1，16位计数器，使用"|"符号可以在使用多个定时器时不受影响		     
 TH0=0x00;	      //给定初值
 TL0=0x00;         
 EA=1;            //总中断打开
 ET0=1;           //定时器中断打开
 TR0=1;           //定时器开关打开
}
/*------------------------------------------------
                    定时器1初始化子程序
					本程序用于定时
------------------------------------------------*/
void Init_Timer1(void)
{
 TMOD |= 0x10;	  //使用模式1，16位定时器，使用"|"符号可以在使用多个定时器时不受影响 
 TH1=HIGH;	      //给定初值，这里使用定时器最大值从0开始计数一直到65535溢出
 TL1=LOW;
 EA=1;            //总中断打开
 ET1=1;           //定时器中断打开
 TR1=1;           //定时器开关打开
}
/*------------------------------------------------
                    主程序
------------------------------------------------*/
main()
{
 unsigned  long int a;
 char temp[16];      //定义字符显示缓冲数组
 Init_Timer0();      //初始化定时器0
 Init_Timer1();      //初始化定时器1
 LCD_Init();         //初始化液晶屏
 DelayMs(10);        //延时用于稳定，可以去掉
 LCD_Clear();        //清屏
 LCD_Write_String(0,0,"www.doflye.net");//写入第一行信息，主循环中不再更改此信息，所以在while之前写入
 while(1)
 {
  if(OVERFLOWFLAG)//检测溢出标志，如果溢出表明频率过高，显示溢出信息
    {
	 OVERFLOWFLAG=0;//标志清零
     LCD_Write_String(0,1,"overflow >655KHz");
	}
  if(TIMERFLAG)      //定时100ms到，做数据处理
    {
	 a=TL0+TH0*256;//读取计数值
	 a=a*10;     //扩大到实际值 1秒钟转速
     a=a/4;      //按照电机转盘实际操作 转盘有4个孔
	 a=a*60;
     sprintf(temp,"%8.0f r/min",(float)a);
     LCD_Write_String(0,1,temp);//显示到液晶第二行
	 TR0=1;                     //2个定时器打开
	 TR1=1;
	 TH0=0;                     //保证计数器初值为0
	 TL0=0;
	 TIMERFLAG=0;               //打开计时计数标志
	 
	}
  }
}

/*------------------------------------------------
                 定时器0中断子程序
------------------------------------------------*/
void Timer0_isr(void) interrupt 1
{
 TH0=00;	      //重新给定初值
 TL0=00; 

 OVERFLOWFLAG=1;  //溢出标志

}
/*------------------------------------------------
                 定时器1中断子程序
------------------------------------------------*/
void Timer1_isr(void) interrupt 3
{
 static unsigned char i;
 TH1=HIGH;		 //重新赋值10ms
 TL1=LOW;

 i++;
 if(i==10)       //100ms 计数时间单位，得出100ms脉冲个数 x10就是1s中脉冲个数，即为频率 Hz 
   {
   i=0;
   TR0=0;        //2个定时器关闭
   TR1=0;
   TIMERFLAG=1;  //标志位清零
   TH1=HIGH;	 //重新赋值
   TL1=LOW;
   }
}
