#ifndef __TERMIOS_H
#define __TERMIOS_H

#include <features.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <linux/termios.h>

__BEGIN_DECLS

__BEGIN_DECLS

extern speed_t cfgetispeed __P ((struct termios *__termios_p));
extern speed_t cfgetospeed __P ((struct termios *__termios_p));
extern int cfsetispeed __P ((struct termios *__termios_p, speed_t __speed));
extern int cfsetospeed __P ((struct termios *__termios_p, speed_t __speed));

extern int tcspeed_to_number __P ((speed_t __speed));
extern speed_t tcspeed_from_number __P ((int number));

extern int cfgetispeedn __P ((struct termios *__termios_p));
extern int cfgetospeedn __P ((struct termios *__termios_p));
extern int cfsetispeedn __P ((struct termios *__termios_p, int __speed));
extern int cfsetospeedn __P ((struct termios *__termios_p, int __speed));

extern void cfmakeraw  __P ((struct termios *__t));

extern int tcsetattr __P ((int __fd, int __opt, struct termios *__termios_p));
extern int tcgetattr __P ((int __fildes, struct termios *__termios_p));
extern int tcdrain __P ((int __fildes));
extern int tcflow __P ((int __fildes, int __action));
extern int tcflush __P ((int __fildes, int __queue_selector));
extern int tcsendbreak __P ((int __fildes, int __duration));

__END_DECLS
extern pid_t tcgetpgrp __P ((int __fildes));
extern int tcsetpgrp __P ((int __fildes, pid_t __pgrp_id));

__END_DECLS

#endif
