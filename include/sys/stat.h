
#ifndef _WASIX_SYS_STAT_H
#define _WASIX_SYS_STAT_H

#include_next <sys/stat.h>

#include <pwd.h>

typedef unsigned int mode_t;
typedef unsigned long long dev_t;

int chmod(const char* path, mode_t mode);
int fchmod(int path, mode_t mode);

int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);

mode_t umask(mode_t mask);

int mknod(const char *pathname, mode_t mode, dev_t dev);
int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev);
int mkfifo(const char *pathname, mode_t mode);

dev_t makedev(unsigned int maj, unsigned int min);

#endif
