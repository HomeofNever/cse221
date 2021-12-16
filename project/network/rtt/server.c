#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SRV_PORT 10800
#define SENT_BYTES 56

int main() {
    struct sockaddr_in6 addr;
    char buf[SENT_BYTES];
    int s,c;
    int reuseaddr = 1;

    s = socket(AF_INET6, SOCK_STREAM, 0);
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

    addr.sin6_family = AF_INET6;
    addr.sin6_port = htons(SRV_PORT);
    addr.sin6_addr = in6addr_any;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));
    listen(s, 5);

    while (1) {
        c = accept(s, NULL, NULL);
        recv(c, buf, SENT_BYTES, 0);
        send(c, buf, SENT_BYTES, 0);
        close(c);
    }
    return 0;
}