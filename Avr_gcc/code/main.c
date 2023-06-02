#include <avr/io.h>
#include <util/delay.h>
 
int main (void)
{
  int T1,T2,T3; 
  int P,Q,R;
	
  DDRD=0b00011100;
  PORTD=0b11100000;

  T1=(PIND & (1 << PIND5) == (1 << PIND5));
  T2=(PIND & (1 << PIND6) == (1 << PIND6));
  T3=(PIND & (1 << PIND7) == (1 << PIND7));
  
  P=T1;
  Q=(!T1);
  R=(!T3);

  PORTD=(P<<2);
  PORTD=(Q<<3);
  PORTD=(R<<4);
  
  return 0;
  }

