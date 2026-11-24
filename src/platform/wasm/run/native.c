/* Runs the standalone wasm module compiled ahead of time: wasm2c's C of build/wasm/hulk.wasm (module name `game`)
 * plus this file and wabt's wasm-rt, built by `tools/wasm_port.py aot` (docs/wasm-port.md "The standalone module").
 *   build/wasm/hulk-aot isos/extracted/default.xbe
 * It defines the module's imports: the WASI calls its C library makes (stdio, arguments, environment, the clock,
 * exit) and the `hulk` host files (src/platform/wasm/host/hulk_io.h), relative to the working directory; files read
 * may be inside a disc image (an .iso or a disc pack named as a folder: run/disc.h). */
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <time.h>
#include <unistd.h>

#include "disc.h"
#include "game.h"
#include "wasm-rt-exceptions.h"
#include "wasm-rt-impl.h"

struct w2c_hulk { int unused; };
struct w2c_wasi__snapshot__preview1 { int argc; char** argv; };

static w2c_game g;
static uint8_t* mem(u32 a) { return g.w2c_memory.data + a; }
uint8_t* hulk_run_memory(void) { return g.w2c_memory.data; }     /* (the app's imports: run/app/app.cpp) */
uint64_t hulk_run_memory_size(void) { return g.w2c_memory.size; }
#ifdef HULK_APP
void hulk_app_start(int* argc, char** argv);    /* run/app/start.cpp: the app's defaults and the game, before the module's env */
void hulk_app_quit(int code);                   /* run/app/start.cpp: the movies, the audio and SDL closed */
#endif
static const char* cstr(u32 a) { return (const char*)mem(a); }
static void put32(u32 a, u32 v) { memcpy(mem(a), &v, 4); }
static void put64(u32 a, u64 v) { memcpy(mem(a), &v, 8); }
extern char** environ;

/* the module sees only the HULK_* variables, sorted (as under node.mjs: the C library's heap holds the same bytes
 * under every runner, and host pointers can reach the game's stacks as dead bytes the state hash covers) */
static char* envs[256];
static int nenv;
static int by_name(const void* a, const void* b) {     /* by the name before '=' (node.mjs sorts the names) */
    const char *x = *(char* const*)a, *y = *(char* const*)b;
    size_t m = strcspn(x, "="), n = strcspn(y, "=");
    int c = strncmp(x, y, m < n ? m : n);
    return c ? c : (m > n) - (m < n);
}
static void pick_env(void) {
    for (char** e = environ; *e && nenv < 255; e++)
        if (!strncmp(*e, "HULK_", 5)) envs[nenv++] = *e;
    qsort(envs, nenv, sizeof *envs, by_name);
}

/* ------------------------------------------------------------------------------------------- hulk (files) */
u32 w2c_hulk_open(struct w2c_hulk* h, u32 path, u32 mode) {
    (void)h;
    if (mode == 0) return (u32)hdisc_open(cstr(path));     /* (a host file, or one in a disc image: run/disc.h) */
    int fl = mode == 1 ? O_RDWR : O_RDWR | O_CREAT | O_TRUNC;
    return (u32)open(cstr(path), fl, 0666);
}
u32 w2c_hulk_read(struct w2c_hulk* h, u32 fd, u32 buf, u32 n, u32 off) {
    (void)h;
    if (hdisc_in_image((int)fd)) return (u32)hdisc_pread((int)fd, mem(buf), n, off);
    u32 done = 0;
    while (done < n) {
        ssize_t r = pread((int)fd, mem(buf + done), n - done, (off_t)off + done);
        if (r < 0) return done ? done : (u32)-1;
        if (r == 0) break;
        done += (u32)r;
    }
    return done;
}
u32 w2c_hulk_write(struct w2c_hulk* h, u32 fd, u32 buf, u32 n, u32 off) {
    (void)h;
    ssize_t r = pwrite((int)fd, mem(buf), n, (off_t)off);
    return (u32)r;
}
u32 w2c_hulk_size(struct w2c_hulk* h, u32 fd) {
    (void)h;
    if (hdisc_in_image((int)fd)) return (u32)hdisc_size((int)fd);
    struct stat sb;
    return fstat((int)fd, &sb) ? 0 : (u32)sb.st_size;
}
u32 w2c_hulk_truncate(struct w2c_hulk* h, u32 fd, u32 n) { (void)h; return (u32)ftruncate((int)fd, n); }
void w2c_hulk_close(struct w2c_hulk* h, u32 fd) { (void)h; hdisc_close((int)fd); }
u32 w2c_hulk_kind(struct w2c_hulk* h, u32 path) {
    (void)h;
    return (u32)hdisc_kind(cstr(path));
}
u32 w2c_hulk_mkdir(struct w2c_hulk* h, u32 path) { (void)h; return (u32)mkdir(cstr(path), 0777); }
struct list_to { u32 buf, cap, need; };
static void list_one(void* ud, const char* name) {
    struct list_to* l = ud;
    u32 n = (u32)strlen(name) + 1;
    if (l->need + n <= l->cap) memcpy(mem(l->buf + l->need), name, n);
    l->need += n;
}
u32 w2c_hulk_list(struct w2c_hulk* h, u32 path, u32 buf, u32 cap) {
    (void)h;
    struct list_to l = {buf, cap, 0};
    hdisc_list(cstr(path), list_one, &l);
    return l.need;
}

/* ------------------------------------------------------------------------------------------- WASI (preview 1) */
#define W(name) w2c_wasi__snapshot__preview1_##name
typedef struct w2c_wasi__snapshot__preview1 wasi;
u32 W(args_sizes_get)(wasi* w, u32 argc, u32 size) {
    u32 n = 0;
    for (int i = 0; i < w->argc; i++) n += (u32)strlen(w->argv[i]) + 1;
    put32(argc, (u32)w->argc);
    put32(size, n);
    return 0;
}
u32 W(args_get)(wasi* w, u32 argv, u32 buf) {
    for (int i = 0; i < w->argc; i++) {
        u32 n = (u32)strlen(w->argv[i]) + 1;
        memcpy(mem(buf), w->argv[i], n);
        put32(argv + 4 * i, buf);
        buf += n;
    }
    return 0;
}
u32 W(environ_sizes_get)(wasi* w, u32 count, u32 size) {
    (void)w;
    u32 c = 0, n = 0;
    for (char** e = envs; *e; e++) c++, n += (u32)strlen(*e) + 1;
    put32(count, c);
    put32(size, n);
    return 0;
}
u32 W(environ_get)(wasi* w, u32 envp, u32 buf) {
    (void)w;
    u32 i = 0;
    for (char** e = envs; *e; e++, i++) {
        u32 n = (u32)strlen(*e) + 1;
        memcpy(mem(buf), *e, n);
        put32(envp + 4 * i, buf);
        buf += n;
    }
    return 0;
}
u32 W(clock_time_get)(wasi* w, u32 id, u64 precision, u32 out) {
    (void)w, (void)precision;
    struct timespec ts;
    clock_gettime(id == 0 ? CLOCK_REALTIME : CLOCK_MONOTONIC, &ts);
    put64(out, (u64)ts.tv_sec * 1000000000ull + (u64)ts.tv_nsec);
    return 0;
}
u32 W(fd_write)(wasi* w, u32 fd, u32 iovs, u32 n, u32 written) {
    (void)w;
    u32 total = 0;
    for (u32 i = 0; i < n; i++) {
        u32 p, len;
        memcpy(&p, mem(iovs + 8 * i), 4);
        memcpy(&len, mem(iovs + 8 * i + 4), 4);
        if (len && write((int)fd, mem(p), len) < 0) return 8;     /* EBADF */
        total += len;
    }
    put32(written, total);
    return 0;
}
u32 W(fd_seek)(wasi* w, u32 fd, u64 off, u32 whence, u32 out) { (void)w, (void)fd, (void)off, (void)whence, (void)out; return 70; }   /* ESPIPE */
u32 W(fd_close)(wasi* w, u32 fd) { (void)w, (void)fd; return 0; }
void W(proc_exit)(wasi* w, u32 code) {
    (void)w;
    fflush(stdout);
#ifdef HULK_APP
    hulk_app_quit((int)code);
#if defined(__linux__) && !defined(__ANDROID__)
    /* (the Linux app: glibc's exit runs the static destructors, and destroying a std::condition_variable that the
       runner's worker threads still wait on (grass.cpp, texpack.cpp) blocks forever: the window closed but the process
       never ended, so Steam's Game Mode showed black until the game was stopped; wlinux2) */
    fflush(NULL);
    _exit((int)code);
#endif
#endif
    exit((int)code);
}

int main(int argc, char** argv) {
    struct w2c_hulk host = {0};
#ifdef HULK_APP
    hulk_app_start(&argc, argv);    /* (may take `--choose-game` off argv) */
#endif
    wasi wa = {argc, argv};
    argv[0] = "hulk";
    pick_env();
    wasm_rt_init();
    wasm2c_game_instantiate(&g, &host, &wa);
    wasm_rt_trap_t trap = wasm_rt_impl_try();
    if (trap) {
        fprintf(stderr, "hulk-aot: trap: %s\n", wasm_rt_strerror(trap));
        return 3;
    }
    w2c_game_0x5Fstart(&g);
    wasm2c_game_free(&g);
    wasm_rt_free();
    return 0;
}
