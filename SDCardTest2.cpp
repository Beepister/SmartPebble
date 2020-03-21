#include "mbed.h"
#include "SDFileSystem.h"

SDFileSystem sd(p5, p6, p7, p8, "sd"); // the pinout on the mbed Cool Components workshop board
DigitalOut myled(LED1);
int Accel[1000];
int Gyro[1000];
int Mag[1000];

int main() {
    myled = 0;
    
    mkdir("/sd/mydata", 0777);
    
    for (int j = 0; j < 1000; j++){
        Accel[j] = rand() % 10000 + 30000;         //Range between 30k-40k
        Gyro[j] = rand() % 10000 + 40000;          //Range between 40k-50k
        Mag[j] = rand() % 10000 + 50000;           //Range between 50k-60k
    }
    
    FILE *at = fopen("/sd/mydata/AccelTest.txt", "w");
    FILE *gt = fopen("/sd/mydata/GyroTest.txt", "w");
    FILE *mt = fopen("/sd/mydata/MagTest.txt", "w");
    
    for(int i = 0; i < 1000; i++){
        fprintf(at, "%i \n", Accel[i]);
        fprintf(gt, "%i \n", Gyro[i]);
        fprintf(mt, "%i \n", Mag[i]);
    }
    
    fclose(at);
    fclose(gt);
    fclose(mt);
    
    myled = 1;
}
