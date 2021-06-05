typedef unsigned int uint32_t;
void SystemInit()
{
	
}
void delay()
{
	for(int i = 0; i < 1000000; i++)
	{
		__asm("NOP");
	}
}
  uint32_t *APB2ENR = (uint32_t*)0x40021018;
  uint32_t* CRH = (uint32_t*)0x40010804;
  uint32_t* BRR = (uint32_t*)0x40013808;
  uint32_t* CR3 = (uint32_t*)0x40013814;
  uint32_t* CR1 = (uint32_t*)0x4001380c;
  uint32_t* DR = (uint32_t*)0x40013804;
  uint32_t* SR = (uint32_t*)0x40013800;
int main()
{
	uint32_t* RCC_CR = (uint32_t*)0x40021000;
	*RCC_CR = (*RCC_CR & ~(uint32_t)(1))|1;

	uint32_t* RCC_CFGR = (uint32_t*)(0x40021000 + 0x04);
	*RCC_CFGR = (*RCC_CFGR & ~(uint32_t)3);

	uint32_t* RCC_APB2ENR = (uint32_t*)(0x40021000 + 0x18);
	uint32_t* RCC_AHBENR = (uint32_t*)(0x40021014);
	*RCC_APB2ENR = (*RCC_APB2ENR & ~(uint32_t)0x08) | 0x08;
	*RCC_APB2ENR = (*RCC_APB2ENR & ~(uint32_t)0x04) | 0x04;
	
	
  *APB2ENR |= (1<<1);
  *APB2ENR |= (1<<14);  
  
  /* set PA9 is output alternate push-pull */
  *CRH &= ~(0b1111<<4);
  *CRH |= (0b10<<6) | (0b11 << 4);

  /* set pa10 is input alternate floating */
  *CRH &= ~(0b1111<<8);
  *CRH |= (0b01<<10) | (0b00 << 8);
  
  *BRR = 52<<4 | 1;

  *CR3 |= (1<<6);

  *CR1 &= ~(1<<12);
  *CR1 &= ~(1<<10);

  *CR1 |= (1<<13);
  *CR1 |= (1<<2);
  *CR1 |= (1<<3);
  
  while(1)
  {
	  *DR = 'o';
		while(((*SR >> 6) & 1) !=1);
		delay();
  }
  return 0;
}