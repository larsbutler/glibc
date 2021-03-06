#include <errno.h>
#include <time.h>

#include <irt_syscalls.h>

#define SYSDEP_GETRES                                       \
  case CLOCK_REALTIME:                                      \
  case CLOCK_MONOTONIC:                                     \
    {                                                       \
      int result = __nacl_irt_clock_getres (clock_id, res); \
      if (result != 0)                                      \
        {                                                   \
          __set_errno (result);                             \
          retval = -1;                                      \
        }                                                   \
      else                                                  \
        retval = 0;                                         \
    }                                                       \
    break;

#define HANDLED_REALTIME

#include <sysdeps/posix/clock_getres.c>
