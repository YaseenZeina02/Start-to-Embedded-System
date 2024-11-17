#define GPIO2DIR (*((volatile unsigned long *) 0x50028000))
#define GPIO2DATA (*((volatile unsigned long *) 0x50023FFC))

int main (void)
 { 
    GPIO2DIR |= 0b001111 ;
    GPIO2DATA = 0b001001;
   // Write your code here
   while (1){
      if (GPIO2DATA & 0b100000){
	 GPIO2DATA =0b001111; 
	 while(GPIO2DATA & 0b100000);
      }
      if (GPIO2DATA & 0b010000){
	 GPIO2DATA =0b000000; 
	 while(GPIO2DATA & 0b010000);
      }
   }
   return 0;
 }   

