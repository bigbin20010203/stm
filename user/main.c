#include "stm32f10x.h"
#include "delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//开漏可以输出低电平
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	//GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	//GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);
	while(1)
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);//Bit_RESET = (bitaction)0
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
		Delay_ms(500);
	}
}