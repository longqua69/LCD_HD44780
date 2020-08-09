#include <avr/io.h>
#include <util/delay.h>

/* Refer to page 24/59 HD44780 datasheet */
#define LCD_CLear_Display               0x01
#define LCD_Return_Home                 0x02
#define LCD_Entry_Mode_Set              0x07
#define LCD_Display_On_Off_Control      0x0F
#define LCD_Cursor_Display_Shift        0x1C
#define LCD_Function_Set                0x2C    // Configure 4-bit mode, 2 lines, 5x10 dots matrix

/* Define I/O pins according to HD44780 datasheet */
#define DB7 7
#define DB6 6
#define DB5 5
#define DB4 4
#define DB3 3
#define DB2 2
#define DB1 1
#define DB0 0
#define RW  0
#define RS  1
#define EN  2

void LCD_Command (uint8_t ins);
uint8_t LCD_Busy_Flag (void);
void LCD_Send_String(unsigned char str);

int main(void)
{
    DDRD = 0xFF; // Configure PORTD as output
    DDRB = 0xFF; // Configure PORTB as output
    return 0;
}

uint8_t LCD_Busy_Flag (void)
{
    DDRB &= ~(1 << PB7); // Configure PINB7 - DB7 as input to check busy flag bit of HD44780
    /* Refer to page 24/59 of HD44780 datasheet */
    PORTD |= 1 << RW;
    PORTD &= ~(1 << RS);
}