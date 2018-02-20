#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int test(int fd, int n)
{
    char path[60];
    bzero(path, sizeof(path));
    sprintf(path, "/tmp/inotify/%d", n);
    close(open(path, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU));
    return inotify_add_watch(fd, path, IN_MODIFY);
}

int main()
{
    int fd = inotify_init();

    for (int i = 0; i < 10000; ++i)
    {
        if (test(fd, i) < 0)
        {
            printf("%d\n", i);
            break;
        }
    }
}
