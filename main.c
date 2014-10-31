#include <stm32f10x.h>
#include <parameters.h>
#include <architecture.h>
#include <usart_1.h>
#include <i2c_1.h>
#include <init_gpio.h>
// --------------- i2c1
// PB6 - SCL
// PB7 - SDA
// ---------------- usart1
// PA9   tx
// PA10  rx

void USART1_Send(char chr)
    {
    while(!(USART1->SR & USART_SR_TC));
    USART1->DR = chr;
    }

void TIM2_IRQHandler()
    {
    if(time==2)
      start=0;
    if(start)
        time++;
    TIM2->SR &= ~TIM_SR_UIF;
    }

void USART1_IRQHandler(void)
    {
    char data;
    data=USART1->DR;
    add_data_usart1(data);
    if(number_of_usart1==2)     // при приёме 2 байтов запускаем сканер задач
        analysis_usart1();
    if(number_of_usart1>2)      // исли пришло больше байт или предыдущие не распознаны, то очищаем буфер
        {
        head_of_usart1=tail_of_usart1;
        number_of_usart1=0;
        }
    USART1->SR&=~USART_SR_RXNE; // флаги
    USART1->SR&=~USART_SR_ORE;
    }

// project by stm32f100RB
int main()
{
initGpio();
init_usart_1();
init_i2c();
__enable_irq();     // global interrupts

char adress=0xA;    // adress L-discovery
char data=0x9;      // data for L-discovery
while(1)
    {
    while(!number_of_tasks)
        {
        }
    (*buffer_of_tasks[head_of_tasks])();
    deleteTask();
    }
}

// errors interrupts
void NMI_Handler( void )
    {
    while(1);
    }
void HardFault_Handler( void )
    {
    while(1);
    }
void MemManage_Handler( void )
    {
    while(1);
    }
void BusFault_Handler( void )
    {
    while(1);
    }
void UsageFault_Handler( void )
    {
    while(1);
    }