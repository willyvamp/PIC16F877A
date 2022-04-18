#include <main.h>

#define redL rc0 // den do
#define yellowL rc1 // den vang
#define greenL rc2 // den xanh

const unsigned char LED7SEG[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f}; // Ma hien thi so cua led 7 seg
unsigned char i, j; // Khai bao bien

// Chuong trinh con hien thi LED 7 doan
void Display(unsigned char x)
{   
    for(j = 0; j < 100; j++) // LED 7 doan sang 100 * 10ms<=>1s
    {
        portd = LED7SEG[x % 10];
        rb1 = 0;
        rb0 = 0;
        delay_ms(5);
        portb = 0xff;
        portd = 0xff;

        portd = LED7SEG[x / 10];
        rb1 = 0;
        rb0 = 1;
        delay_ms(5);
        portb = 0xff;
        portd = 0xff;
    }
}

// Chuong trinh con sang den do
void RedLight()
{
    rc0 = 1;
    rc1 = 0;
    rc2 = 0;
    
    unsigned char y = 25;

    for(i = 0; i <= 25; i++)
    {
        Display(y);
        portd = 0xff;
        y--;
    }
}

// Chuong trinh con sang den vang
void YellowLight()
{
    rc0 = 0;
    rc1 = 1;
    rc2 = 0;
    
    unsigned char y = 5;

    for(i = 0; i <= 5; i++)
    {
        Display(y);
        portd = 0xff;
        y--;
    }
}

// Chuong trinh con sang den xanh
void GreenLight()
{
    rc0 = 0;
    rc1 = 0;
    rc2 = 1;
    
    unsigned char y = 20;

    for(i = 0; i <= 20; i++)
    {
        Display(y);
        portd = 0xff;
        y--;
    }
} 

// Chuong trinh chinh
void main()
{
    trisb = 0;
    trisd = 0;
    trisc = 0;
    portd = 0x00;
    
    while (1)
    {
        RedLight();
        GreenLight();
        YellowLight();
    }
}

