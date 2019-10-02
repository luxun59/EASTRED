#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "step.h"
#include "tim_6.h"

int main(void)
{
    int a = -1;
    delay_init();	    	 //延时函数初始化
    uart_init(115200);	 //串口初始化为115200
    TIM2_Int_Init(12,10);
    tim_6_time_Init(999,719);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	delay_ms(1000);
//	delay_ms(1000);
//	delay_ms(1000);
//	delay_ms(1000);
    printf("%d",a);

    while(1)
    {
        speed_up(1,16000);
        step_wait();
        //speed_down(1,360);
        speed_up(1,16000);
        step_wait();
        //speed_down(0,360);
    }
}

