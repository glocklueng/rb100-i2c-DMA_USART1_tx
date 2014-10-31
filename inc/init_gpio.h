void initGpio()
    {
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;     // ������������ ���� �
    RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;     // ������������ ���� �


    RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;     // ������������ �������_2

    GPIOC->CRH|=GPIO_CRH_MODE8_1 | GPIO_CRH_MODE9_1;
    GPIOC->CRH&=~(GPIO_CRH_CNF8_0 | GPIO_CRH_CNF9_0);

// ------------------ ������ ------------------
    TIM2->CR1 |= TIM_CR1_CEN | TIM_CR1_ARPE;//
    TIM2->DIER |= TIM_DIER_UIE; //

    TIM2->CR1 |= TIM_CR1_CEN;
    TIM2->PSC = 200;//8000 - 1;
    TIM2->ARR = 1000 ;

    __enable_irq();                       // ���������� ��������� ����������
    NVIC_EnableIRQ (USART1_IRQn);         // ��������� ���������� �� USART1
    NVIC_EnableIRQ (TIM2_IRQn);
    }
