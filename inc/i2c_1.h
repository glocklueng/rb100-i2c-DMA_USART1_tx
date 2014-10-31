int start=0;
int time=0;
void init_i2c()
    {
    RCC->APB1ENR|=RCC_APB1ENR_I2C1EN;     // тактирование i2c_1
    RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;     // тактирование порт B

    GPIOB->CRL |= GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_0 |GPIO_CRL_CNF6_1 | GPIO_CRL_CNF7_1;
    GPIOB->CRL |= GPIO_CRL_MODE6_1 | GPIO_CRL_MODE7_1;

    I2C1->SR2|=I2C_SR2_MSL; // | I2C_SR2_TRA;       // enable Master mode // transmit bit
    I2C1->CR2 |= 8;   // 8 ћ√ц
    I2C1->CCR |= 80;  // делим 8ћгц на 80 получаем 100к√ц
    I2C1->TRISE = 9;  // задержка импульса



    I2C1->CR1    |=  I2C_CR1_PE;  // |  I2C_CR1_ACK;
    NVIC_EnableIRQ(I2C2_EV_IRQn); // interrupt I2C2 on
    while (!(I2C1->CR1 & I2C_CR1_PE)){}
    }

void i2c1_tx(char adress, char data, char tx_or_rx)
    {
    tx_adress_i2c=adress;
    tx_data_i2c[tail_of_i2c1_tx]=data;
    I2C1->CR1 |= I2C_CR1_START;

    I2C1->CR2|= I2C_CR2_ITBUFEN;        // прерывание по пустому буферу - флаг - TxE

    //I2C1->CR1 |= I2C_CR1_START;
    //while(!(I2C1->SR1 & I2C_SR1_SB));
    //(void) I2C1->SR1;
    //adress=(adress<<1);// сдвигаем адрес на 1
    //adress|=tx_or_rx;
    I2C1->DR = adress;                   //
    green_on();
    while (!(I2C1->SR1 & I2C_SR1_ADDR)); // ожидаем окончани€ передачи адреса
    (void) I2C1->SR1;  // по даташиту это надо читать...
    (void) I2C1->SR2;  //
    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_TXE))  // ждем, флаг ставитс€ если регистр DR пуст
       {}
    blue_on();
    I2C1->CR1 |= I2C_CR1_STOP;
    }