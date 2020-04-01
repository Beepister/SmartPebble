#include "mbed.h"
#include "SDFileSystem.h"

SDFileSystem sd(p5, p6, p7, p8, "sd"); // the pinout on the mbed Cool Components workshop board
DigitalOut myled(LED1);
float AccVal, GyrVal, MagVal;
int BinVal;
Timer t;

int main() {
    myled = 0;
    
    mkdir("/sd/Test3", 0777);
    
    FILE *ax = fopen("/sd/Test3/AccelX.txt", "w");
    FILE *ay = fopen("/sd/Test3/AccelY.txt", "w");
    FILE *az = fopen("/sd/Test3/AccelZ.txt", "w");
    FILE *gx = fopen("/sd/Test3/GyroX.txt", "w");
    FILE *gy = fopen("/sd/Test3/GyroY.txt", "w");
    FILE *gz = fopen("/sd/Test3/GyroZ.txt", "w");
    FILE *mt = fopen("/sd/Test3/Mag.txt", "w");
    FILE *ti = fopen("/sd/Test3/Time.txt", "w");
    
    t.start();
    
    for(int i = 0; i < 10000; i++){
        BinVal = rand() % 65535 - 32768;           //Range between -32768 & 32767 inclusive
        AccVal = 0.00098 * BinVal;
        GyrVal = 0.12207 * BinVal;
        MagVal = 0.00153 * BinVal;
        fprintf(ax, "%.3f\n", AccVal);
        fprintf(ay, "%.3f\n", AccVal);
        fprintf(az, "%.3f\n", AccVal);
        fprintf(gx, "%.1f\n", GyrVal);
        fprintf(gy, "%.1f\n", GyrVal);
        fprintf(gz, "%.1f\n", GyrVal);
        fprintf(mt, "%.3f\n", MagVal);
    }
    
    t.stop();
    fprintf(ti, "%f seconds \n", t.read());
    
    fclose(ax);
    fclose(ay);
    fclose(az);
    fclose(gx);
    fclose(gy);
    fclose(gz);
    fclose(mt);
    fclose(ti);
    
    myled = 1;
}
