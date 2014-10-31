// ---------------- usart1
// PA9   tx
// PA10  rx
void init_usart_1()
    {
    RCC->APB2ENR|=RCC_APB2ENR_USART1EN;   	    // тактирование USART1
    RCC->APB2ENR|=RCC_APB2ENR_AFIOEN;     		// тактирование альтернативных функций портов
    GPIOA->CRH &= !GPIO_CRH_CNF10;
    GPIOA->CRH &= !GPIO_CRH_MODE10;
    GPIOA->CRH  |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_CNF10_0;

    USART1->BRR =(SYS_CLK+BAUDRATE_USART_1/16)/BAUDRATE_USART_1;    // делитель на 9600
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;     				//
    // прерывание по приёму
    // Запускаем модуль USART
    USART1->CR1 |= USART_CR1_UE;
    USART1->CR1 |= USART_CR1_RXNEIE;
    }

void add_data_usart1(char c)
    {
    if(tail_of_usart1==32)
      tail_of_usart1=0;
    tx_data_usart1[tail_of_usart1]=c;
    tail_of_usart1++;
    number_of_usart1++;
    }
void iterator_head_of_usart1()
	{
	head_of_usart1++;
	if(head_of_usart1==32)
         head_of_usart1=0;
	number_of_usart1--;
	}
void analysis_usart1()
    {
    switch(tx_data_usart1[head_of_usart1])
    	{
    	case '1':
	    	{
	    	iterator_head_of_usart1();
	    	switch(tx_data_usart1[head_of_usart1])
		    	{
		    	case '3':
		    		{
		    		iterator_head_of_usart1();
		    		addTask(green_on);
		    		addTask(blue_on);
		    		}
		    	break;
				case '9':
				    {
					iterator_head_of_usart1();
					addTask(i2c_tx_0xA_9_0);
					}
				break;
		    	}
	    	}
    	break;
		case '2':
	    	{
	    	iterator_head_of_usart1();
	    	switch(tx_data_usart1[head_of_usart1])
		    	{
		    	case 'b':
		    		{
		    		iterator_head_of_usart1();
		    		addTask(green_off);
		    		addTask(blue_off);
		    		}
		    	break;
		    	}
	    	}
    	break;
    	default:
    		iterator_head_of_usart1();
    	break;
    	}
    }
