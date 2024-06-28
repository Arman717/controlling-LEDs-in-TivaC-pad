#define RCGCGPIO (*((unsigned int *)0x400FE608U))
#define GPIO_BASE 0x40025000U
#define GPIO_DIR  (*((unsigned int *)RCGCGPIO + 0x400U))
#define GPIO_DEN  (*((unsigned int *)RCGCGPIO + 0x51CU))
#define GPIO_DATA  (*((unsigned int *)RCGCGPIO + 0x3FCU))
void delay()
{
  volatile int i;
  for (i = 0; i < 1000000; i++); 
}
int main()
{
  RCGCGPIO = 0x20 ;
  
  GPIO_DIR = 0x0EU ;
   
  GPIO_DEN = 0x0EU;
  while (1){
    
  GPIO_DATA = 0x02U ; 
  delay();

  GPIO_DATA = 0x08U ;
  delay() ;
  
  GPIO_DATA = 0x0cU ;
  delay() ;
  
  };
  return 0;
}
