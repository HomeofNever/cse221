#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/cpu_cycle_count.h"
#include "../../utils/print_message.h"

#define SRV_PORT 10800
#define SRV_IP "2602:fc52:30d:100::2"
#define SENT_BYTES 1000000 // 1M
#define TIMES 10

int main() {
    struct Timer timer;
    int sock_fd = -1;
	struct sockaddr_in6 server_addr;
	int ret;

    /* Prepare Data, sizeof(char) == 1 */
	char * ch = malloc(SENT_BYTES);

    /* Create socket for communication with server */
	sock_fd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd == -1) {
		perror("socket()");
		return EXIT_FAILURE;
	}

    /* Connect to server running on localhost */
	server_addr.sin6_family = AF_INET6;
	inet_pton(AF_INET6, SRV_IP, &server_addr.sin6_addr);
	server_addr.sin6_port = htons(SRV_PORT);

    /* Try to do TCP handshake with server */
	ret = connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (ret == -1) {
		perror("connect()");
		close(sock_fd);
		return EXIT_FAILURE;
	}
 
    /* Start Timer */
	sync_tsc();
    start_timer(&timer);

    /* Send data to server */
    for (int i = 0; i < TIMES; i++) {
        ret = send(sock_fd, ch, SENT_BYTES, 0);
        if (ret == -1) {
            perror("send");
            close(sock_fd);
            return EXIT_FAILURE;
        }
    }
    
    /* End Timer */
    end_timer(&timer);
	sync_tsc();
 
	/* DO TCP teardown */
	ret = close(sock_fd);
	if (ret == -1) {
		perror("close()");
		return EXIT_FAILURE;
	}
    
    cycle2ms(calc_diff(&timer) / TIMES);

    return 0;
}