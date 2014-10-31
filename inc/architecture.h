void addTask( void (*pf)())     // ���������� ������ �� ����������
   {
   if(tail_of_tasks==32)
      tail_of_tasks=0;
   buffer_of_tasks[tail_of_tasks]=pf;
   tail_of_tasks++;
   number_of_tasks++;
   }

void deleteTask()             // �������� ������
    {
    if(head_of_tasks==32)
        head_of_tasks=0;
    buffer_of_tasks[head_of_tasks]=0;
    head_of_tasks++;
    number_of_tasks--;
    }

void green_on()     // ������ �������� ������
    {
    GPIOC->ODR |= GPIO_ODR_ODR9;
    }
void green_off()    // ������ �������� ������
    {
    GPIOC->ODR &= (~GPIO_ODR_ODR9);
    }
void blue_on()     // ������ �������� ������
    {
    GPIOC->ODR |= GPIO_ODR_ODR8;
    }
void blue_off()     // ������ �������� ������
    {
    GPIOC->ODR &= (~GPIO_ODR_ODR8);
    }
// ������� ��� i2c_tx
void i2c1_tx(char adress, char data, char tx_or_rx);
void i2c_tx_0xA_9_0()
    {
    i2c1_tx(0xA,9,0);
    }