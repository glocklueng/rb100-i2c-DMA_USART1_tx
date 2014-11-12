// ------------ USART1
#define SYS_CLK 8000000UL              // частота кварца
#define BAUDRATE_USART_1 9600UL         // скорость UASRT_1
// ------------ for I2C1
#define transmit 1
#define recive 0
u8 tail_of_i2c1_tx=0;
u8 head_of_i2c1_tx=0;
u8 number_of_i2c1_tx=0;
u8 tx_data_i2c[8];
u8 tx_adress_i2c=0;
u8 buffer[200];
// ------------ architecture.h
u16 tail_of_tasks=0;              // сюда мы записываем очередную задачу и првоеряем чтобы tail не превышал буфер
u16 head_of_tasks=0;              // отсюда мы берём задачу на выполнение и првоеряем чтобы head не превышал буфер
void (*buffer_of_tasks[32])();    // сам буфер с задачами
u16 number_of_tasks=0;            // кол-во невыполненных задач
// ------------ usart_1.h
char tx_data_usart1[32];          // буфер принятых данных по usart1
u16 tail_of_usart1=0;             // позиция записываемого байта
u16 head_of_usart1=0;             // позиция считываемого байта
u16 number_of_usart1=0;           // кол-во не обработанных но принятых байт т.е. number_of_usart=tail_of_usart1-head_of_usart1;