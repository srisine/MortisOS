#include<rtc.h>



uint8_t read_cmos(uint8_t reg) {
    port_byte_out(0x70, reg);
    return port_byte_in(0x71);
}

uint8_t bcd_to_bin(uint8_t bcd) {
    return ((bcd / 16) * 10) + (bcd % 16); //straight up black magic
}

void print_date() {
    uint8_t second = bcd_to_bin(read_cmos(0x00));
    uint8_t minute = bcd_to_bin(read_cmos(0x02));
    uint8_t hour   = bcd_to_bin(read_cmos(0x04)); 
    uint8_t day   = bcd_to_bin(read_cmos(0x07));
    uint8_t month = bcd_to_bin(read_cmos(0x08));
    uint8_t year  = bcd_to_bin(read_cmos(0x09));

    char buf[10];

    itoa(day, buf);
    printf(buf, 10, lineNo*16);
    printf("/", 26, lineNo*16); 

    itoa(month, buf);
    printf(buf, 42, lineNo*16);
    printf("/", 58, lineNo*16);

    printf("20", 74, lineNo*16);
    itoa(year, buf);
    printf(buf, 90, lineNo*16);
}
