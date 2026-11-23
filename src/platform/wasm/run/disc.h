/* The runners' disc sources (wpkg1, D237; docs/wasm-port.md "Disc sources"): host files by path, where a path may run
 * through a disc image. The game's disc is one of
 *   - the extracted folder (default.xbe and the .rcf archives): plain host files;
 *   - an Xbox disc image (.iso), read in place: a full (Redump) image or a trimmed (xiso) one;
 *   - a disc pack (tools/disc_pack.py: zstd chunks with an index, read in place through a small chunk cache).
 * An image's files are named as if the image were a folder: <image path>/default.xbe, <image path>/art.rcf, so
 * HULK_DATA_DIR / HULK_XBE (and every reader of the disc: the module's imports in run/native.c, the app's movies and
 * far field) work unchanged. On Android a picked file is given as "fd:N" (an open descriptor, read with pread). Images
 * are read-only and their names case-insensitive, as the Xbox's file systems are. Thread-safe. */
#ifndef HULK_RUN_DISC_H
#define HULK_RUN_DISC_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

enum { HDISC_NONE = 0, HDISC_FILE = 1, HDISC_DIR = 2 };

/* a file to read: a host file, or one in an image (fd >= 0), or -1 */
int hdisc_open(const char* path);
/* up to n bytes at off (fewer at the end of the file); -1 on an error */
int64_t hdisc_pread(int fd, void* buf, size_t n, uint64_t off);
uint64_t hdisc_size(int fd);
void hdisc_close(int fd);
/* 1: fd is a file in an image (not a host descriptor) */
int hdisc_in_image(int fd);
/* what the path names: HDISC_NONE / FILE / DIR (an image itself is a directory) */
int hdisc_kind(const char* path);
/* calls fn for every name in the directory (an image's own ".hulk" files are not listed); the count, or -1 */
int hdisc_list(const char* path, void (*fn)(void* ud, const char* name), void* ud);
/* the disc source a path is: "folder" (a host directory), "iso", "pack", or 0 */
const char* hdisc_source(const char* path);

#ifdef __cplusplus
}
#endif
#endif
