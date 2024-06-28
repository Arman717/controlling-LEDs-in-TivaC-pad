#define RCGCGPIO (*((unsigned int *)0x400FE608U)) //clock gating controll
#define GPIO_BASE 0x40025000U
#define GPIO_DIR  (*((unsigned int *)(GPIO_BASE + 0x400U)))
#define GPIO_DEN  (*((unsigned int *)(GPIO_BASE + 0x51CU)))
#define GPIO_DATA  (*((unsigned int *)(GPIO_BASE + 0x3FCU)))
void delay()
{
  volatile int i; //delay function
  for (i = 0; i < 1000000; i++); 
}
int main()
{
  RCGCGPIO = 0x20 ;  //enable clovk for GPIO_F
  
  GPIO_DIR = 0x0EU ; // set pins 1,2 , 3 as outputs 
   
  GPIO_DEN = 0x0EU; // Enable digital function for pins 1, 2, and 3
  while (1){
    
  GPIO_DATA = 0x02U ; // red 
  delay();

  GPIO_DATA = 0x08U ; //green
  delay() ;
  
  GPIO_DATA = 0x0cU ; //blue
  delay() ;
  
  };
  return 0;
}
