/* XAPI by address (which address is which function: src/platform/sdl/xdk/imports.h), written from the documented
 * Win32/XAPI interfaces.
 *
 * Threads and fibers are cooperative (sched.c): one runs at a time and switches only where the game waits, sleeps or
 * switches fibers, so a run is deterministic. Kernel objects (files, threads, semaphores, events, heaps) are records
 * in the sim block, addressed by handle; a file's host stream is a cache the host reopens from the record's path and
 * position, so the game state is in linear memory. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hulk_host.h"
#include "sim.h"

/* ------------------------------------------------------------------------------------------- handles */
hulk_obj* ff_obj(uint32_t h) {
    uint32_t i = (h - HANDLE_BASE) / 4;
    if (h < HANDLE_BASE || (h & 3) || i >= MAX_OBJS || !SIM->objs[i].kind) return 0;
    return &SIM->objs[i];
}

uint32_t ff_new_obj(int kind) {
    for (uint32_t i = 0; i < MAX_OBJS; i++)
        if (!SIM->objs[i].kind) {
            memset(&SIM->objs[i], 0, sizeof SIM->objs[i]);
            SIM->objs[i].kind = kind;
            SIM->objs[i].refs = 1;
            return HANDLE_BASE + i * 4;
        }
    ff_fatal("out of kernel objects");
}

static void set_error(uint32_t e) { SIM->last_error = e; }

/* ------------------------------------------------------------------------------------------- paths */
/* D: is the disc (HULK_DATA_DIR, default isos/extracted), read-only; T:, U:, Z: are directories under HULK_SAVE_DIR
 * (default build/wasm/save). Lookups are case-insensitive, as the Xbox's file systems are. */
static const char* data_dir(void) {
    const char* d = getenv("HULK_DATA_DIR");
    return d ? d : "isos/extracted";
}
static const char* save_dir(void) {
    const char* d = getenv("HULK_SAVE_DIR");
    return d ? d : "build/wasm/save";
}

#include <dirent.h>
/* the host spelling of one path component under DIR (case-insensitive), or 0 */
static int match_name(const char* dir, const char* name, char* out, size_t cap) {
    DIR* d = opendir(dir);
    if (!d) return 0;
    struct dirent* e;
    int ok = 0;
    while ((e = readdir(d)))
        if (!strcasecmp(e->d_name, name)) {
            snprintf(out, cap, "%s", e->d_name);
            ok = 1;
            break;
        }
    closedir(d);
    return ok;
}

/* game path -> host path; components that don't exist keep their spelling (a file to create) */
int ff_host_path(const char* game, char* out, size_t cap) {
    if (!game || !isalpha((unsigned char)game[0]) || game[1] != ':') return 0;
    char drive = (char)toupper((unsigned char)game[0]);
    if (drive == 'D') snprintf(out, cap, "%s", data_dir());
    else if (drive == 'T' || drive == 'U' || drive == 'Z') {
        snprintf(out, cap, "%s/%c", save_dir(), drive);
        mkdir(save_dir(), 0777);
        mkdir(out, 0777);
    } else return 0;
    const char* p = game + 2;
    char comp[256];
    while (*p) {
        while (*p == '\\' || *p == '/') p++;
        if (!*p) break;
        size_t n = 0;
        while (p[n] && p[n] != '\\' && p[n] != '/') n++;
        if (n >= sizeof comp) return 0;
        memcpy(comp, p, n);
        comp[n] = 0;
        p += n;
        char real[256];
        size_t len = strlen(out);
        if (match_name(out, comp, real, sizeof real)) snprintf(out + len, cap - len, "/%s", real);
        else snprintf(out + len, cap - len, "/%s", comp);
    }
    return 1;
}

/* ------------------------------------------------------------------------------------------- files */
/* the host streams behind file records: a cache (reopened from the record's path when missing) */
static FILE* streams[MAX_OBJS];

static FILE* stream(uint32_t h, hulk_obj* o) {
    uint32_t i = (h - HANDLE_BASE) / 4;
    if (!streams[i]) {
        streams[i] = fopen(o->path, o->writable ? "r+b" : "rb");
        if (!streams[i]) return 0;
    }
    return streams[i];
}

static void close_stream(uint32_t h) {
    uint32_t i = (h - HANDLE_BASE) / 4;
    if (i < MAX_OBJS && streams[i]) {
        fclose(streams[i]);
        streams[i] = 0;
    }
}

#define GENERIC_WRITE 0x40000000u
#define CREATE_NEW 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#define TRUNCATE_EXISTING 5
#define INVALID_HANDLE 0xffffffffu

FFG(002109f1) {         /* CreateFileA(path, access, share, sa, disposition, flags, template) */
    UNUSED;
    const char* game = PTR(ARG(0));
    char host[sizeof SIM->objs[0].path];
    uint32_t access = ARG(1), disp = ARG(4);
    if (!ff_host_path(game, host, sizeof host)) { set_error(3); RET(INVALID_HANDLE); return; }
    int disc = (game[0] | 0x20) == 'd';
    struct stat sb;
    int exists = stat(host, &sb) == 0 && S_ISREG(sb.st_mode);
    if (getenv("HULK_FILE_TRACE")) fprintf(stderr, "hulk: CreateFile %s -> %s%s\n", game, host, exists ? "" : " (none)");
    if (disc && (access & GENERIC_WRITE)) { set_error(5); RET(INVALID_HANDLE); return; }
    if (!exists && (disp == OPEN_EXISTING || disp == TRUNCATE_EXISTING)) { set_error(2); RET(INVALID_HANDLE); return; }
    if (exists && disp == CREATE_NEW) { set_error(80); RET(INVALID_HANDLE); return; }
    if (!exists || disp == CREATE_ALWAYS || disp == TRUNCATE_EXISTING) {
        FILE* f = fopen(host, "wb");
        if (!f) { set_error(3); RET(INVALID_HANDLE); return; }
        fclose(f);
    }
    uint32_t h = ff_new_obj(OBJ_FILE);
    hulk_obj* o = ff_obj(h);
    snprintf(o->path, sizeof o->path, "%s", host);
    o->writable = (access & GENERIC_WRITE) != 0;
    o->pos = 0;
    set_error(exists && (disp == OPEN_ALWAYS || disp == CREATE_ALWAYS) ? 183 : 0);
    RET(h);
}

static uint32_t file_size(uint32_t h, hulk_obj* o) {
    FILE* f = stream(h, o);
    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    return (uint32_t)ftell(f);
}

FFG(0020ff8d) {         /* ReadFile(h, buf, n, done, overlapped) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE) { set_error(6); RET(0); return; }
    FILE* f = stream(ARG(0), o);
    uint32_t got = 0;
    if (f) {
        fseek(f, (long)o->pos, SEEK_SET);
        got = (uint32_t)fread(PTR(ARG(1)), 1, ARG(2), f);
        o->pos += got;
    }
    if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = got;
    RET(f != 0);
}

FFG(0021007a) {         /* WriteFile(h, buf, n, done, overlapped) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE || !o->writable) { set_error(5); RET(0); return; }
    FILE* f = stream(ARG(0), o);
    uint32_t put = 0;
    if (f) {
        fseek(f, (long)o->pos, SEEK_SET);
        put = (uint32_t)fwrite(PTR(ARG(1)), 1, ARG(2), f);
        fflush(f);
        o->pos += put;
    }
    if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = put;
    RET(f != 0);
}

FFG(002101d4) {         /* SetFilePointer(h, lo, hi*, method) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE) { set_error(6); RET(INVALID_HANDLE); return; }
    int64_t off = (int32_t)ARG(1);
    if (ARG(2)) off = (int64_t)(((uint64_t) * (uint32_t*)PTR(ARG(2)) << 32) | ARG(1));
    int64_t base = ARG(3) == 0 ? 0 : ARG(3) == 1 ? (int64_t)o->pos : (int64_t)file_size(ARG(0), o);
    int64_t p = base + off;
    if (p < 0) { set_error(131); RET(INVALID_HANDLE); return; }
    o->pos = (uint32_t)p;
    if (ARG(2)) *(uint32_t*)PTR(ARG(2)) = 0;
    RET(o->pos);
}

FFG(002109b6) {         /* GetFileSize(h, hi*) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE) { RET(INVALID_HANDLE); return; }
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = 0;
    RET(file_size(ARG(0), o));
}

FFG(00210150) {         /* SetEndOfFile(h) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE || !o->writable) { RET(0); return; }
    FILE* f = stream(ARG(0), o);
    RET(f && truncate(o->path, (off_t)o->pos) == 0);
}

void ff_close_obj(uint32_t h) {
    hulk_obj* o = ff_obj(h);
    if (!o) return;
    if (o->kind == OBJ_FILE) close_stream(h);
    if (--o->refs <= 0) o->kind = 0;
}

FFG(0020bbc2) {         /* CloseHandle */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o) { set_error(6); RET(0); return; }
    if (o->kind == OBJ_THREAD && !o->done) { o->refs--; RET(1); return; }    /* the thread keeps running */
    ff_close_obj(ARG(0));
    RET(1);
}

FFG(00208b9c) {         /* GetDiskFreeSpaceExA(path, avail*, total*, free*): 1 GB free of 8 GB */
    UNUSED;
    for (int k = 1; k <= 3; k++)
        if (ARG(k)) {
            uint64_t v = k == 2 ? (8ull << 30) : (1ull << 30);
            memcpy(PTR(ARG(k)), &v, 8);
        }
    RET(1);
}
FFG(00209a8e) {         /* XGetDiskSectorSizeA: the DVD's 2048 (the game stops at "TBS_STOP_PIRATING" otherwise) */
    UNUSED;
    const char* p = PTR(ARG(0));
    RET(p && (p[0] | 0x20) == 'd' ? 0x800 : 512);
}
FFG(0021257d) { UNUSED; RET(0); }                                               /* XapiOpenDirectory */
FFG(00209237) { UNUSED; RET(1); }                                               /* XFormatUtilityDrive */
FFG(00209b29) { UNUSED; RET(0x48f); }       /* XMUNameFromDriveLetter: no memory unit (ERROR_DEVICE_NOT_CONNECTED) */

/* ------------------------------------------------------------------------------------------- system */
FFG(00209d27) { UNUSED; RET(0x490); }       /* XGetLaunchInfo: no launch data (ERROR_NOT_FOUND) */
FFG(00209c04) { UNUSED; ff_fatal("XLaunchNewImageA(%s)", ARG(0) ? (char*)PTR(ARG(0)) : "dashboard"); }
FFG(00209f50) { UNUSED; RET(1); }                                               /* XGetLanguage: English */
FFG(00354c8f) { UNUSED; RET(0); }                                               /* XGetAudioFlags */
FFG(00356667) { UNUSED; RET(0); }                                               /* XGetVideoFlags */
FFG(0020a0b7) { UNUSED; RET(SIM->last_error); }                                 /* GetLastError */
FFG(00355d0d) {                                                                 /* OutputDebugStringA */
    UNUSED;
    if (getenv("HULK_LOG") && ARG(0)) fprintf(stderr, "dbg: %s", (const char*)PTR(ARG(0)));
    RET(0);
}
FFG(00209f01) {         /* GlobalMemoryStatus(MEMORYSTATUS*): 64 MB, as a retail console */
    UNUSED;
    uint32_t* m = PTR(ARG(0));
    m[0] = 32;
    m[1] = 50;
    m[2] = 64u << 20;
    m[3] = 32u << 20;
    m[4] = 64u << 20;
    m[5] = 32u << 20;
    m[6] = 2047u << 20;
    m[7] = 1024u << 20;
    RET(0);
}

/* heaps: the game arena */
FFG(0020c731) { UNUSED; RET(ff_new_obj(OBJ_HEAP)); }                            /* HeapCreate */
FFG(0020e1a1) {                                                                 /* HeapAlloc(heap, flags, n) */
    UNUSED;
    RET((uintptr_t)ff_arena_alloc(ARG(2), 16));
}
FFG(0020c79c) { UNUSED; ff_arena_free(PTR(ARG(2))); RET(1); }                   /* HeapFree */
FFG(0020d7ff) { UNUSED; RET(ff_arena_usable(PTR(ARG(2)))); }                    /* HeapSize */

/* ------------------------------------------------------------------------------------------- time */
/* the virtual clock: the timestamp counter's 733 MHz (QueryPerformanceFrequency on the console) */
FFG(00354ce2) {                                                                 /* QueryPerformanceFrequency */
    UNUSED;
    uint64_t f = HULK_TSC_HZ;
    memcpy(PTR(ARG(0)), &f, 8);
    RET(1);
}
FFG(00354cd1) {                                                                 /* QueryPerformanceCounter */
    UNUSED;
    SIM->clock += HULK_TSC_HZ / 1000000;            /* each read moves the clock on a microsecond */
    memcpy(PTR(ARG(0)), &SIM->clock, 8);
    ff_poll();
    RET(1);
}
FFG(00355364) {                                                                 /* GetLocalTime(SYSTEMTIME*) */
    UNUSED;
    uint16_t* t = PTR(ARG(0));
    uint64_t s = SIM->clock / HULK_TSC_HZ;
    t[0] = 2005; t[1] = 6; t[2] = 3; t[3] = 15;     /* a fixed date: the run doesn't depend on the host's clock */
    t[4] = (uint16_t)(12 + s / 3600 % 12); t[5] = (uint16_t)(s / 60 % 60); t[6] = (uint16_t)(s % 60);
    t[7] = (uint16_t)(SIM->clock / (HULK_TSC_HZ / 1000) % 1000);
    RET(0);
}

/* ------------------------------------------------------------------------------------------- saves, soundtracks */
FFG(003564c0) { UNUSED; set_error(18); RET(INVALID_HANDLE); }  /* XFindFirstSaveGame: none (ERROR_NO_MORE_FILES) */
FFG(003565ca) { UNUSED; set_error(18); RET(0); }                               /* XFindNextSaveGame */
FFG(00356611) { UNUSED; RET(1); }                                               /* XFindClose */
FFG(00355ab5) { UNUSED; RET(INVALID_HANDLE); }                                  /* XFindFirstSoundtrack: none */
FFG(00355791) { UNUSED; RET(0); }                                               /* XFindNextSoundtrack */
