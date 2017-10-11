/**
* Infinite Memory Engine - Native interface
*
* Copyright (c) 2017 DataDirect Networks, Inc. All rights reserved.
******************************************************************************/
#ifndef _IME_NATIVE_H
#define _IME_NATIVE_H

#include <stdbool.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define DEFAULT_IME_FILE_PREFIX     "ime://"
#define DEFAULT_IME_PREFIX_NO_FWD_SLASH "ime:"
#define DEFAULT_IME_FILE_PREFIX_LEN (sizeof(DEFAULT_IME_FILE_PREFIX) - 1)
#define IME_FILE_PREFIX_LEN_NO_FWD_SLASH (sizeof(DEFAULT_IME_PREFIX_NO_FWD_SLASH) - 1)

void    ime_native_init(void);
int     ime_native_access(const char *pathname, int mode);
int     ime_native_open(const char *pathname, int, mode_t mode);
int     ime_native_close(int fd);
ssize_t ime_native_write(int fd, const char *buf, size_t count);
ssize_t ime_native_read(int fd, char *buf, size_t count);
ssize_t ime_native_pwrite(int fd, const char *buf, size_t count, off_t offest);
ssize_t ime_native_pread(int fd, char *buf, size_t count, off_t offset);
int     ime_native_dup2(int oldfd, int newfd);
off_t   ime_native_lseek(int fd, off_t offset, int whence);
int     ime_native_finalize(void);
int     ime_native_stat(const char *pathname, struct stat *buf);
int     ime_native_unlink(const char *pathname);
int     ime_native_fsync(int fd);
int     ime_native_ftruncate(int fd, off_t offset);

#endif /* _IME_NATIVE_H */

