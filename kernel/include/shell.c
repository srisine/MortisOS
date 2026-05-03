#include <shell.h>

int lineNo = 0;

void addLine(){
    lineNo++;
}

void execCmd(){
    addLine();
    
    char cmd_part[64];
    int i = 0;

    while (i < index && command[i] != ' ' && i < 63) {
        cmd_part[i] = command[i];
        i++;
    }
    cmd_part[i] = '\0';

    if (strcmp(cmd_part, "PRINT") == 0) {
        if (i < index && command[i] == ' ') {
            i++; 
        }

        char arg_part[128];
        int j = 0;
        while (i < index && j < 127) {
            arg_part[j] = command[i];
            i++;
            j++;
        }
        arg_part[j] = '\0';

        printf(arg_part, 10, 16 * lineNo);
    }
    else if (strcmp(cmd_part, "BEEP") == 0){
        if (i < index && command[i] == ' ') {
            i++; 
        }

        char arg_part[128];
        int j = 0;
        while (i < index && j < 127) {
            arg_part[j] = command[i];
            i++;
            j++;
        }
        arg_part[j] = '\0';

        int frequency = atoi(arg_part);

        if (frequency > 0) {
            beep(frequency, 1000);
        } else {
            beep(750, 1000); 
        }
    } 
    else if (strcmp(command, "DATE") == 0) {
        print_date(); 
    }
    else if ((strcmp(command, "SYSTIKS") == 0)){
        char buf[10];
        itoa(system_ticks, buf);
        printf(buf, 10, 16*lineNo);
    }
    else if ((strcmp(command, "CLR") == 0)){
        clrScr(0, 0, 0);
        lineNo = 0;
    }
    else {
        printf("Unknown Command", 10, 16 * lineNo);
        play_error_sound();
    }
}
