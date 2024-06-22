
#include <18F4550.H>
#use delay(clock=4Mhz)
#fuses XT, NOPROTECT, NOPUT, NOWDT, NOBROWNOUT, NOLVP, NOCPD
#include "Mi_LCD.c"


void main()
{
  int8 i,j;
  lcd_init();

  //pacman con la boca abierta avanzando

  lcd_send_byte(0,0x40); // escribe en la cgram (0), direccion 0x40
  lcd_send_byte(1,0x0F); // | |x|x|x|x|
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x1E); // |x|x|x|x| |
  lcd_send_byte(1,0x1C); // |x|x|x| | |
  lcd_send_byte(1,0x18); // |x|x| | | |
  lcd_send_byte(1,0x11); // |x| | | |x|
  lcd_send_byte(1,0x1B); // |x|x| |x|x|
  lcd_send_byte(1,0x0E); // | |x|x|x| |

  //pacman con la boca cerrada avanzando

  lcd_send_byte(0,0x48); //escribe en la cgram (1), direccion 0x48
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0E); // | |x|x|x|x|
  lcd_send_byte(1,0x1F); // |x| |x|x| |
  lcd_send_byte(1,0x1F); // |x|x|x| | |
  lcd_send_byte(1,0x1C); // |x| |x|x| |
  lcd_send_byte(1,0x19); // |x|x|x|x| |
  lcd_send_byte(1,0x1B); // | |x|x|x|x|
  lcd_send_byte(1,0x0E); // | | | | | |

  //pacman con la boca abierta devolviendose

  lcd_send_byte(0,0x50); // escribe en la cgram (2), direccion 0x50
  lcd_send_byte(1,0x1E); // | | | | | |
  lcd_send_byte(1,0x1F); // | |x|x|x|x|
  lcd_send_byte(1,0x0F); // |x| |x|x| |
  lcd_send_byte(1,0x07); // |x|x|x| | |
  lcd_send_byte(1,0x03); // |x| |x|x| |
  lcd_send_byte(1,0x11); // |x|x|x|x| |
  lcd_send_byte(1,0x1B); // | |x|x|x|x|
  lcd_send_byte(1,0x0E); // | | | | | |

  //pacman con la boca cerrada devolviendose

  lcd_send_byte(0,0x58); // escribe en la cgram (3), direccion 0x58
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0E); // | |x|x|x|x|
  lcd_send_byte(1,0x1F); // |x| |x|x| |
  lcd_send_byte(1,0x1F); // |x|x|x| | |
  lcd_send_byte(1,0x07); // |x| |x|x| |
  lcd_send_byte(1,0x13); // |x|x|x|x| |
  lcd_send_byte(1,0x1B); // | |x|x|x|x|
  lcd_send_byte(1,0x0E); // | | | | | |

  //pacman con la boca hacia abajo

  lcd_send_byte(0,0x60); // escribe en la cgram (4), direccion 0x60
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0A); // | |x|x|x|x|
  lcd_send_byte(1,0x11); // |x| |x|x| |
  lcd_send_byte(1,0x11); // |x|x|x| | |
  lcd_send_byte(1,0x1B); // |x| |x|x| |
  lcd_send_byte(1,0x1F); // |x|x|x|x| |
  lcd_send_byte(1,0x0E); // | |x|x|x|x|
  lcd_send_byte(1,0x00); // | | | | | |

  //pacman con la boca hacia arriba

  lcd_send_byte(0,0x68); // escribe en la cgram (5), direccion 0x68
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0E); // | |x|x|x|x|
  lcd_send_byte(1,0x1F); // |x| |x|x| |
  lcd_send_byte(1,0x1B); // |x|x|x| | |
  lcd_send_byte(1,0x11); // |x| |x|x| |
  lcd_send_byte(1,0x11); // |x|x|x|x| |
  lcd_send_byte(1,0x1A); // | |x|x|x|x|
  lcd_send_byte(1,0x00); // | | | | | |

  while(1)
  {
    lcd_gotoxy(4,1);
    printf(lcd_putc,"Univalle");  
    lcd_gotoxy(6,2);
    printf(lcd_putc,"<3");   
    delay_ms(150);
  
    for(i=1,j=2;i<=20;i++,j++)
    {
      lcd_gotoxy(i,1);
      lcd_send_byte(1,0);  //imprime boca abierta
      delay_ms(100);
      lcd_gotoxy(i,1);
      printf(lcd_putc," ");
    
      lcd_gotoxy(j,1);
      lcd_send_byte(1,1);  //imprime boca cerrada
      delay_ms(100); 
      lcd_gotoxy(i,1);
      printf(lcd_putc," ");
    }
  
    lcd_gotoxy(20,1);
    lcd_send_byte(1,5);  //imprime boca hacia abajo
    delay_ms(100);
    lcd_gotoxy(20,1);
    printf(lcd_putc," ");
  
    lcd_gotoxy(20,2);
    lcd_send_byte(1,5);  //imprime boca hacia abajo
    delay_ms(100);
    lcd_gotoxy(20,2);
    printf(lcd_putc," ");
  
    for(i=20,j=19;i>=1;i--,j--)
    {
      lcd_gotoxy(i,2);
      lcd_send_byte(1,2);  //imprime boca abierta devolviendose
      delay_ms(100);
      lcd_gotoxy(i,2);
      printf(lcd_putc," ");
    
      lcd_gotoxy(j,2);
      lcd_send_byte(1,3);  //imprime boca cerrada devolviendose
      delay_ms(100); 
      lcd_gotoxy(i,2);
      printf(lcd_putc," ");
    }
  
    lcd_gotoxy(1,2);
    lcd_send_byte(1,4);  //imprime boca hacia arriba
    delay_ms(100);
    lcd_gotoxy(1,2);
    printf(lcd_putc," ");
  
    lcd_gotoxy(1,1);
    lcd_send_byte(1,4);  //imprime boca hacia arriba
    delay_ms(100);
  }
}
