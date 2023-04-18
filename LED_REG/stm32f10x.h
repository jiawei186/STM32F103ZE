#define PERIPH_BASE ((unsigned int)0x40000000)

#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE (PERIPH_BASE + 0x20000)

#define GPIOB_BASE (APB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASE (APB2PERIPH_BASE + 0X1800)

#define GPIOB_CRL *(unsigned int*) (GPIOB_BASE + 0x00)
//#define GPIOB_CRL_45 *(unsigned int*) (GPIOB_BASE + 0x00 + 0x02)
#define GPIOB_ODR *(unsigned int*) (GPIOB_BASE + 0x0C)
	
#define GPIOE_CRL *(unsigned int*) (GPIOE_BASE + 0x00)
//#define GPIOE_CRL_45 *(unsigned int*) (GPIOE_BASE + 0x00 + 0x02)
#define GPIOE_ODR *(unsigned int*) (GPIOE_BASE + 0x0C)
	
#define RCC_BASE (AHBPERIPH_BASE + 0x1000)

#define RCC_APB2ENR *(unsigned int*) (RCC_BASE + 0x18)
