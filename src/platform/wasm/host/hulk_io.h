/* The wasm module's only imports besides WASI's stdio, arguments, environment, clock and exit: host files, by path
 * (docs/wasm-port.md "The standalone module"). The runners define them: src/platform/wasm/run/node.mjs under node and
 * src/platform/wasm/run/native.c for the wasm2c build. Offsets and sizes are 32-bit (the disc's files are). */
#ifndef HULK_WASM_IO_H
#define HULK_WASM_IO_H
#include <stdint.h>

#define HIO(name) __attribute__((import_module("hulk"), import_name(#name)))
enum { HIO_READ = 0, HIO_RDWR = 1, HIO_CREATE = 2 };    /* open modes (HIO_CREATE: create or truncate, then RDWR) */
enum { HIO_NONE = 0, HIO_FILE = 1, HIO_DIR = 2 };       /* path kinds */
HIO(open) int32_t hio_open(const char* path, int32_t mode);                     /* -> fd >= 0, or -1 */
HIO(read) int32_t hio_read(int32_t fd, void* buf, uint32_t n, uint32_t off);    /* -> bytes read, or -1 */
HIO(write) int32_t hio_write(int32_t fd, const void* buf, uint32_t n, uint32_t off);
HIO(size) uint32_t hio_size(int32_t fd);
HIO(truncate) int32_t hio_truncate(int32_t fd, uint32_t n);                     /* -> 0 when done */
HIO(close) void hio_close(int32_t fd);
HIO(kind) int32_t hio_kind(const char* path);
HIO(mkdir) int32_t hio_mkdir(const char* path);
/* the names in a directory, each NUL-terminated, into buf: the bytes they need (call again with more room) */
HIO(list) uint32_t hio_list(const char* path, char* buf, uint32_t cap);
#endif
