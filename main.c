/*
 * GccApplication2.c
 *
 * Created: 2024-05-28 오전 9:03:56
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0x0F;
	DDRC = 0x0F;
	unsigned char FND[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	while (1) // 무한반복
	{
		PORTB=0xF7;
		if((PINC & 0x10)!=0) //DIP스위치 1번의값이 0이 아니면 즉 DIP1이 켜지면
		{  
			for (int i = 0; i < 10; i++) //10번 반복
				{
				PORTA = FND[i]; //1씩 올라가는 FND 구성
				_delay_ms(500); //0.5초 딜레이
				}
		}
		if((PINC & 0x20)!=0) //DIP스위치 2번의값이 0이 아니면 즉 DIP2가 켜지면
		{
			for (int i = 10; i >= 0; i--) //반대로 10번 반복
				{
				PORTA = FND[i]; //1씩 내려가는 FND 구성
				_delay_ms(500); //0.5초 딜레이
				}
		}
	}
}
