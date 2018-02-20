#include <sys/inotify.h>
#include <stdio.h>

int main()
{
    for (int i = 0; i < 200; ++i)
    {
        if (inotify_init() < 0)
        {
            printf("%d\n", i);
            break;
        }
    }
}
