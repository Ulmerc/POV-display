#ifndef USART
#define USART

void config_usart();
unsigned char usart_recieve(void);
void usart_transmit(unsigned char data);
void flush_reciever();

#endif // USART