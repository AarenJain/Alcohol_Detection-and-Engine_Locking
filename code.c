#include <REGX51.H>

#define THRESHOLD 300

sbit BUZZER = P2^0;
sbit SENSOR = P3^0;
sbit IGNITION = P3^1;

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

void uart_init() {
    SCON = 0x50;     
    TMOD = 0x20;     
    TH1 = 0xFD;     
    TL1 = 0xFD;
    TR1 = 1;         
}

void uart_send_char(char ch) {
    SBUF = ch;
    while (!TI);
    TI = 0;
}

void uart_send_string(char *s) {
    while (*s) {
        uart_send_char(*s++);
    }
}

void send_sms(char *message) {
    uart_send_string("AT\r");
    delay(1000);

    uart_send_string("AT+CMGF=1\r");  //SMS text mode
    delay(1000);

    uart_send_string("AT+CMGS=\"+9112345678\"\r");  //use whatever no.
    delay(1000);

    uart_send_string(message);  
    uart_send_char(0x1A);      
    delay(3000);
}

unsigned int read_alcohol_sensor() {
    return SENSOR ? 400 : 100;
}

void lock_engine() {
    P1 = 0x00;
    BUZZER = 0;
}

void unlock_engine() {
    P1 = 0xFF;
    BUZZER = 1;
}

void retry_delay() {
    unsigned char i;
    for (i = 5; i > 0; i--) {
        delay(1000);
    }
}

void main() {
    P1 = 0x00;
    BUZZER = 1;
    uart_init();

    while (1) {
        unsigned int alcohol = read_alcohol_sensor();

        if (alcohol >= THRESHOLD) {
            lock_engine();
            send_sms("Alert: Drunk driving attempt detected. Engine locked.\n");
            retry_delay();

            if (IGNITION == 1) {
                send_sms("Critical: Ignition attempted while intoxicated.\n");
            }
        } else {
            unlock_engine();
        }

        delay(500);
    }
}
