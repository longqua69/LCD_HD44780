#include <avr/io.h>

/* Refer to page 24/59 HD44780 datasheet */
#define LCD_CLear_Display               0x01
#define LCD_Return_Home                 0x02
#define LCD_Entry_Mode_Set              0x07
#define LCD_Display_On_Off_Control      0x0F
#define LCD_Cursor_Display_Shift        0x1C
#define LCD_Function_Set                0x2C    // Configure 4-bit mode, 2 lines, 5x10 dots matrix

void LCD_Command (uint8_t ins);
uint8_t LCD_Busy_Flag (void);
void LCD_Send_String(unsigned char str);

int main(void)
{

    return 0;
}