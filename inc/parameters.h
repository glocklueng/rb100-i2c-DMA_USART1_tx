// ------------ USART1
#define SYS_CLK 8000000UL              // ������� ������
#define BAUDRATE_USART_1 9600UL         // �������� UASRT_1
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
u16 tail_of_tasks=0;              // ���� �� ���������� ��������� ������ � ��������� ����� tail �� �������� �����
u16 head_of_tasks=0;              // ������ �� ���� ������ �� ���������� � ��������� ����� head �� �������� �����
void (*buffer_of_tasks[32])();    // ��� ����� � ��������
u16 number_of_tasks=0;            // ���-�� ������������� �����
// ------------ usart_1.h
char tx_data_usart1[32];          // ����� �������� ������ �� usart1
u16 tail_of_usart1=0;             // ������� ������������� �����
u16 head_of_usart1=0;             // ������� ������������ �����
u16 number_of_usart1=0;           // ���-�� �� ������������ �� �������� ���� �.�. number_of_usart=tail_of_usart1-head_of_usart1;