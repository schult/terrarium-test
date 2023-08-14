#include <errno.h>
#include <sys/stat.h>

#include <stm32h750xx.h>

//=============================================================================
int _close(int file)
{
    (void)file;
    return -1;
}

//=============================================================================
int _fstat(int file, struct stat* st)
{
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

//=============================================================================
int _getpid(void)
{
    return 1;
}

//=============================================================================
int _isatty(int file)
{
    (void)file;
    return 1;
}

//=============================================================================
int _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

//=============================================================================
int _lseek(int file, int ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

//=============================================================================
int _read(int file, char* ptr, int len)
{
    (void)file;
    (void)ptr;
    (void)len;
    errno = ENOSYS;
    return -1;
}

//=============================================================================
int _write(int file, char *ptr, int len)
{
    (void)file;
    for (int i = 0; i < len; ++i)
    {
        ITM_SendChar(*ptr++);
    }
    return len;
}
