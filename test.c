#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
int main() {
    int sockfd, ret;
    struct ifreq *hw_addr;
    hw_addr = (struct ifreq *)malloc(sizeof(struct ifreq));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        exit(-1);
    }
    
    ret = ioctl(sockfd, SIOCGIFHWADDR, *hw_addr);
    if(ret != 0) {
        perror("ioctl");
        exit(-1);
    }
    exit(0);
}
    
