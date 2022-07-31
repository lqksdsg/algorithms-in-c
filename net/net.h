/* 网络 */

typedef struct Addr
{
    char *ip;
    int port;
} Addr;

int listen(int fd, int num);
int accept(int fd);
int connect(Addr target);
int read(int fd, char *buffer);
int write(int fd, char *buffer);
