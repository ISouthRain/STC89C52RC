/*-----------------------------------------------
  名称：抢答器
  名称：单个独立按键控制
  论坛：www.doflye.net
  编写：shifang
  日期：2009.5
  修改：无
  内容： 1、试验目的：了解按键的扫描原理
         2、实现现象：同时按键抢答，先按的键有效，其他按键锁死 复位后重新开始抢答
         3、硬件要求：按键 LED灯 
         原理：最先按下按键者有效，其他均无效
------------------------------------------------*/
#include<8052.h>     //包含头文件，一般情况不需要改动，头文件包含特殊功能寄存器的定义


#define key1 P3_0//定义按键位置 独立按键模式 
#define key2 P3_1
#define key3 P3_2
#define key4 P3_3
/*-----------------------------------------------
                    主函数
------------------------------------------------*/
main()
{
int Flag;
while(!Flag)//执行一次就停止了 先检测到的相应 复位后有效
      {
      if(!key1)     {P1=0xFE;Flag=1;}//
	  else if(!key2){P1=0xFD;Flag=1;}//
	  else if(!key3){P1=0xFB;Flag=1;}//
	  else if(!key4){P1=0xF7;Flag=1;}//
      }
while(Flag);
}