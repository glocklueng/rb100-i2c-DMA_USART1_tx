void init_dma()
	{
	RCC->AHBENR|=RCC_AHBENR_DMA1EN;
	DMA1_Channel4->CPAR = (uint32_t)&(USART1->DR);
	DMA1_Channel4->CMAR = (uint32_t)(buffer[0]);
	DMA1_Channel4->CNDTR=200;
	DMA1_Channel4->CCR|=DMA_CCR4_PL_1  | DMA_CCR4_CIRC | DMA_CCR4_DIR;
	DMA1_Channel4->CCR|= DMA_CCR4_MINC;
	DMA1_Channel4->CCR|= DMA_CCR4_EN;
	}