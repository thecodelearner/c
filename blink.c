#include<stdio.h>
#include<time.h>

int main(){
        int i,j;

        write(1,"hello\n",6);
        sleep(1);
        write(0,"linger",6);
        sleep(1);
        write(1,"\33[2K\r",5); /*erase line and carriage return*/
        write(1,"\33[1A",4); /*move 1 line up*/
        write(1,"\33[2K\r",5); /*erase line and carriage return*/
        write(1,"yeah\n",5);

        return 0;

}
