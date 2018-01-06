// https://unix.stackexchange.com/questions/138342/how-to-read-write-to-tty-device

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    
#include <string.h>

#define BUF_SIZE 300

int main() {
    char buf[BUF_SIZE];
    int fd = open("/dev/ttyACM0", O_RDWR);
	
	int bytes_read = 0;
	while (1) {
		int n = read(fd, buf+bytes_read, 1);
		if (buf[bytes_read] == '\0')
			printf("\n");
		printf("%c", buf[bytes_read += (bytes_read%BUF_SIZE)]); // buffer circolare
    }
	
    return 0;
}
