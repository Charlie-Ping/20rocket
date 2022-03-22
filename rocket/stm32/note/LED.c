// 第一个程序!终于要点灯辣!

#include "stm32f103xb.h"
#include "sys.h"
#include "led.h"

int main(void) {
    RCC_Configuration(); // 时钟设置
    LED_Init();
    while (1)
    {
        GPIO_WriteBit(LEDPORT, LED1, (BitAction)(0)); // led1接口输出高电平
    }
    
}

void LED_Init(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;
    // 启动APB2总线上的这些功能
    // 这三种GPIO在时钟上启动后才能使用
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE)

    
}