// PIC16F877A Configuration Bit Settings
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000

#define arriba RB0
#define abajo RB1
#define escape RB2
#define enter RB3
int p;

void main(void) {
    ADCON1 = 0XFF;
    TRISB = 0XFF; //Botones
    TRISD = 0; //LCD
    PORTB = PORTD = 0; //Limpieza de puerto

    LCD_inicio();
    LCD_CLR();
    LCD_STR("Tabla de");
    LCD_NL();
    LCD_STR("Laplace        >");
    __delay_ms(800);
    LCD_CLR();

    p = 2;

    LCD_STR("F(t)     1      ");

    while (1) {
        switch (p) {

            case 2:
                __delay_ms(200);
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     1/s    ");
                    p = 15;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     k      ");
                    p = 3;
                }
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  cos(at+b) ");
                    p = 14;
                }
                break;

            case 3:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     1      ");
                    p = 2;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     k/s    ");
                    p = 16;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    t^n     ");
                    p = 4;
                }
                break;

            case 4:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     k      ");
                    p = 3;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) n!/s^(n+1) ");
                    p = 17;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   cos(at)  ");
                    p = 5;
                }
                break;

            case 5:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    t^n     ");
                    p = 4;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2+a^2 ");
                    p = 18;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   sin(at)  ");
                    p = 6;
                }
                break;

            case 6:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   cos(at)  ");
                    p = 5;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2+a^2 ");
                    p = 19;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   ch(at)");
                    p = 7;
                }
                break;

            case 7:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  sin(at)   ");
                    p = 6;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2-a^2 ");
                    p = 20;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   sh(at)");
                    p = 8;
                }
                break;

            case 8:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   ch(at)");
                    p = 7;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2-a^2");
                    p = 21;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    e^at    ");
                    p = 9;
                }
                break;

            case 9:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   sh(at)   "); //
                    p = 8;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    1/s-a   ");
                    p = 22;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.sin(bt)");
                    p = 10;
                }
                break;

            case 10:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    e^at    ");
                    p = 9;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)      b     ");
                    LCD_NL();
                    LCD_STR("     (s-a)^2+b^2");
                    p = 23;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.cos(bt)");
                    p = 11;
                }
                break;

            case 11:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.sin(bt)");
                    p = 10;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    s-a  ");
                    LCD_NL();
                    LCD_STR("    (s-a)^2+b^2");
                    p = 24;
                }

                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  t^n.e^at  ");
                    p = 12;
                }
                break;

            case 12:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.cos(bt)");
                    p = 11;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    n!");
                    LCD_NL();
                    LCD_STR("    (s-a)^n+1");
                    p = 25;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t) sin(at+b)  ");
                    p = 13;
                }
                break;

            case 13:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  t^n.e^at  ");
                    p = 12;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)+a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 26;
                }
                if (abajo = 1) {
                    LCD_CLR();
                    LCD_STR("F(t) cos(at+b)  ");
                    p = 14;
                }
                break;

            case 14:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(t) sin(at+b)  ");
                    p = 13;
                }
                if (enter == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)-a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 27;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     1      ");
                    p = 2;
                }
                break;


                
            case 15:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)-a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 27;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     1      ");
                    p = 2;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     k/s    ");
                    p = 16;
                }
                break;

            case 16:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     1/s    ");
                    p = 15;
                }
                if (escape == 1) {
                    LCD_CLR();
                    LCD_STR("F(t)     k      ");
                    p = 3;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) n!/s^(n+1) ");
                    p = 17;
                }
                break;

            case 17:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     k/s    ");
                    p = 16;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    t^n     ");
                    p = 4;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2+a^2 ");
                    p = 18;
                }
                break;

            case 18:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) n!/s^(n+1) ");
                    p = 17;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   cos(at)  ");
                    p = 5;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2+a^2 ");
                    p = 19;
                }
                break;

            case 19:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2+a^2 ");
                    p = 18;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  sin(at)   ");
                    p = 6;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2-a^2 ");
                    p = 20;
                }
                break;

            case 20:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2+a^2 ");
                    p = 19;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)   ch(at)   ");
                    p = 7;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2-a^2 ");
                    p = 21;
                }
                break;

            case 21:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  s/s^2-a^2 ");
                    p = 20;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  sh(at)    ");
                    p = 8;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    1/s-a   ");
                    p = 22;
                }
                break;

            case 22:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)  a/s^2-a^2 ");
                    p = 21;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)    e^at    ");
                    p = 9;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)      b     ");
                    LCD_NL();
                    LCD_STR("     (s-a)^2+b^2");
                    p = 23;
                }
                break;

            case 23:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    1/s-a   ");
                    p = 22;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.sin(bt)");
                    p = 10;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    s-a  ");
                    LCD_NL();
                    LCD_STR("    (s-a)^2+b^2");
                    p = 24;
                }
                break;

            case 24:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)      b     ");
                    LCD_NL();
                    LCD_STR("     (s-a)^2+b^2");
                    p = 23;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)");
                    LCD_NL();
                    LCD_STR("  e^at.cos(bt)");
                    ;
                    p = 11;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    n!");
                    LCD_NL();
                    LCD_STR("    (s-a)^n+1");
                    p = 25;
                }
                break;

            case 25:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    s-a  ");
                    LCD_NL();
                    LCD_STR("    (s-a)^2+b^2");
                    p = 24;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  t^n.e^at  ");
                    p = 12;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)+a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 26;
                }
                break;

            case 26:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)    n!");
                    LCD_NL();
                    LCD_STR("    (s-a)^n+1");
                    p = 25;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t) sin(at+b)  ");
                    p = 13;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)-a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 27;
                }
                break;

            case 27:
                __delay_ms(200);
                if (arriba == 1) {
                    LCD_CLR();
                    LCD_STR("F(s) s.sin(b)+a.");
                    LCD_NL();
                    LCD_STR("cos(b)/(s)^2+a^2");
                    p = 26;
                }
                if (escape = 1) {
                    LCD_CLR();
                    LCD_STR("F(t)  cos(at+b) ");
                    p = 14;
                }
                if (abajo == 1) {
                    LCD_CLR();
                    LCD_STR("F(s)     1/s    ");
                    p = 15;
                }
                break;
        }
    }
}