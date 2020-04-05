#include "mbed.h"
#include "SDFileSystem.h"

SDFileSystem sd(p5, p6, p7, p8, "sd");
DigitalOut myled(LED1);

int main() {
    myled = 0;
    mkdir("/sd/mydir", 0777);

    FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
    
    for(int i = 1; i < 10000; i++){
        fprintf(fp, "%i \n", i);
    }
    
    fclose(fp);
    myled = 1;
}
