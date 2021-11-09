#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


int main() {
   
    //I don't have such folder in my linux, so I can't produce ex2.txt
    char* device = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
   
    int fd = open(device, O_RDONLY);
   
    if(fd<0){
    printf("Error\n");
        return EXIT_FAILURE;
    }

    struct input_event evt;   
   
    while(1){
        ssize_t b = read(fd, &evt, sizeof(evt));
        if(evt.value!=2 && evt.code!=EV_SYN) {
            if(evt.value){
        printf("PRESSED %x (%d)\n", evt.code, evt.code);
        }else{
        printf("RELEASED %x (%d)\n", evt.code, evt.code);
        }
           
        }
    }
   
    fflush(stdout);
    return 0;
}