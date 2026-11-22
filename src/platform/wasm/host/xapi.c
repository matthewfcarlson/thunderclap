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
#include <strings.h>
#include "hulk_host.h"
#include "hulk_io.h"
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

/* the host spelling of one path component under DIR (case-insensitive), or 0 */
static int match_name(const char* dir, const char* name, char* out, size_t cap) {
    static char* names;
    static uint32_t room;
    uint32_t need = hio_list(dir, names, room);
    if (need > room) {
        free(names);
        room = need + 4096;
        names = malloc(room);
        need = hio_list(dir, names, room);
    }
    for (uint32_t k = 0; k < need && k < room;) {
        const char* e = names + k;
        if (!strcasecmp(e, name)) {
            snprintf(out, cap, "%s", e);
            return 1;
        }
        k += (uint32_t)strlen(e) + 1;
    }
    return 0;
}

/* game path -> host path; components that don't exist keep their spelling (a file to create) */
int ff_host_path(const char* game, char* out, size_t cap) {
    if (!game || !isalpha((unsigned char)game[0]) || game[1] != ':') return 0;
    char drive = (char)toupper((unsigned char)game[0]);
    if (drive == 'D') snprintf(out, cap, "%s", data_dir());
    else if (drive == 'T' || drive == 'U' || drive == 'Z') {
        snprintf(out, cap, "%s/%c", save_dir(), drive);
        hio_mkdir(save_dir());
        hio_mkdir(out);
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
/* the host files behind file records: a cache (reopened from the record's path when missing); fd + 1, 0 = none */
static int32_t streams[MAX_OBJS];

static int32_t stream(uint32_t h, hulk_obj* o) {
    uint32_t i = (h - HANDLE_BASE) / 4;
    if (!streams[i]) streams[i] = hio_open(o->path, o->writable ? HIO_RDWR : HIO_READ) + 1;
    return streams[i] - 1;
}

static void close_stream(uint32_t h) {
    uint32_t i = (h - HANDLE_BASE) / 4;
    if (i < MAX_OBJS && streams[i]) {
        hio_close(streams[i] - 1);
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
    int exists = hio_kind(host) == HIO_FILE;
    if (getenv("HULK_FILE_TRACE")) fprintf(stderr, "hulk: CreateFile %s -> %s%s\n", game, host, exists ? "" : " (none)");
    if (disc && (access & GENERIC_WRITE)) { set_error(5); RET(INVALID_HANDLE); return; }
    if (!exists && (disp == OPEN_EXISTING || disp == TRUNCATE_EXISTING)) { set_error(2); RET(INVALID_HANDLE); return; }
    if (exists && disp == CREATE_NEW) { set_error(80); RET(INVALID_HANDLE); return; }
    if (!exists || disp == CREATE_ALWAYS || disp == TRUNCATE_EXISTING) {
        int32_t f = hio_open(host, HIO_CREATE);
        if (f < 0) { set_error(3); RET(INVALID_HANDLE); return; }
        hio_close(f);
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
    int32_t f = stream(h, o);
    return f < 0 ? 0 : hio_size(f);
}

FFG(0020ff8d) {         /* ReadFile(h, buf, n, done, overlapped) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE) { set_error(6); RET(0); return; }
    int32_t f = stream(ARG(0), o);
    int32_t got = f < 0 ? -1 : hio_read(f, PTR(ARG(1)), ARG(2), o->pos);
    if (got > 0) o->pos += (uint32_t)got;
    if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = got > 0 ? (uint32_t)got : 0;
    RET(got >= 0);
}

FFG(0021007a) {         /* WriteFile(h, buf, n, done, overlapped) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_FILE || !o->writable) { set_error(5); RET(0); return; }
    int32_t f = stream(ARG(0), o);
    int32_t put = f < 0 ? -1 : hio_write(f, PTR(ARG(1)), ARG(2), o->pos);
    if (put > 0) o->pos += (uint32_t)put;
    if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = put > 0 ? (uint32_t)put : 0;
    RET(put >= 0);
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
    int32_t f = stream(ARG(0), o);
    RET(f >= 0 && hio_truncate(f, o->pos) == 0);
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
    uint64_t v;                                     /* (a recording's virtual clock: replay.cpp) */
    memcpy(PTR(ARG(0)), ff_replay_qpc(&v) ? &v : &SIM->clock, 8);
    ff_poll();
    RET(1);
}
FFG(00355364) {                                                                 /* GetLocalTime(SYSTEMTIME*) */
    UNUSED;
    uint16_t* t = PTR(ARG(0));
    if (ff_replay_local_time(t)) { RET(0); return; }
    uint64_t s = SIM->clock / HULK_TSC_HZ;
    t[0] = 2005; t[1] = 6; t[2] = 3; t[3] = 15;     /* a fixed date: the run doesn't depend on the host's clock */
    t[4] = (uint16_t)(12 + s / 3600 % 12); t[5] = (uint16_t)(s / 60 % 60); t[6] = (uint16_t)(s % 60);
    t[7] = (uint16_t)(SIM->clock / (HULK_TSC_HZ / 1000) % 1000);
    RET(0);
}

/* ------------------------------------------------------------------------------------------- saves, soundtracks */
/* A save game is a directory U:\<12 hex digits> named by an FNV-1a hash of its UTF-16 name (probing on), holding
 * SaveMeta.xbx ("Name=<name>", UTF-16 with a BOM), as the SDL layer lays them out (src/platform/sdl/fs/hulk_saves.cpp,
 * docs/native-files-saves.md): the game writes its files into the path it gets back. */
#define SAVE_NAME_CHARS 64
static uint64_t save_hash(const uint16_t* n) {
    uint64_t h = 0xcbf29ce484222325ull;
    for (; *n; n++) {
        h ^= *n & 0xff; h *= 0x100000001b3ull;
        h ^= *n >> 8; h *= 0x100000001b3ull;
    }
    return h;
}
static uint32_t wlen16(const uint16_t* n) { uint32_t k = 0; while (n[k]) k++; return k; }
static void save_dir_path(char letter, uint64_t hash, int probe, char* out, size_t cap) {
    uint64_t v = (hash + (uint64_t)probe * 0x9e3779b97f4a7c15ull) & 0xffffffffffffull;
    snprintf(out, cap, "%c:\\%012llX", letter, (unsigned long long)v);
}
/* the save's name in DIR's SaveMeta.xbx equals NAME */
static int save_named(const char* host_dir, const uint16_t* name) {
    char meta[sizeof SIM->objs[0].path + 16];
    snprintf(meta, sizeof meta, "%s/SaveMeta.xbx", host_dir);
    int32_t f = hio_open(meta, HIO_READ);
    if (f < 0) return 0;
    uint16_t buf[512];
    int32_t got = hio_read(f, buf, sizeof buf - 2, 0);
    hio_close(f);
    if (got < 2) return 0;
    uint32_t n = (uint32_t)got / 2, k = buf[0] == 0xfeff ? 1 : 0;
    static const char key[] = "Name=";
    for (int i = 0; key[i]; i++, k++)
        if (k >= n || buf[k] != (uint16_t)key[i]) return 0;
    uint32_t i = 0;
    for (; k < n && buf[k] != '\r' && buf[k] != '\n'; k++, i++)
        if (buf[k] != name[i]) return 0;
    return name[i] == 0;
}
static int save_root(uint32_t root, char* letter) {
    const char* r = root ? PTR(root) : 0;
    if (!r || !isalpha((unsigned char)r[0]) || r[1] != ':') return 0;
    *letter = (char)toupper((unsigned char)r[0]);
    return *letter == 'U' || *letter == 'T';
}
/* -> the probe holding NAME (*found = 1) or the first free one; -1 when none is free */
static int save_find(char letter, const uint16_t* name, int* found) {
    uint64_t h = save_hash(name);
    int free_probe = -1;
    *found = 0;
    for (int p = 0; p < 16; p++) {
        char game[32], host[sizeof SIM->objs[0].path];
        save_dir_path(letter, h, p, game, sizeof game);
        if (!ff_host_path(game, host, sizeof host)) return -1;
        if (hio_kind(host) != HIO_DIR) { if (free_probe < 0) free_probe = p; continue; }
        if (save_named(host, name)) { *found = 1; return p; }
    }
    return free_probe;
}
static void save_clear(const char* host_dir) {
    char names[4096], f[sizeof SIM->objs[0].path + 64];
    uint32_t need = hio_list(host_dir, names, sizeof names);
    for (uint32_t k = 0; k < need && k < sizeof names;) {
        snprintf(f, sizeof f, "%s/%s", host_dir, names + k);
        int32_t h = hio_open(f, HIO_CREATE);       /* no unlink import: an emptied file */
        if (h >= 0) hio_close(h);
        k += (uint32_t)strlen(names + k) + 1;
    }
}
FFG(0035618d) {         /* XCreateSaveGame(root, name UTF-16, disposition, 0, path out, size) -> error code */
    UNUSED;
    char letter;
    const uint16_t* name = ARG(1) ? PTR(ARG(1)) : 0;
    uint32_t disp = ARG(2);
    if (!save_root(ARG(0), &letter) || !name || !name[0] || wlen16(name) >= SAVE_NAME_CHARS || disp < CREATE_NEW ||
        disp > TRUNCATE_EXISTING || disp == TRUNCATE_EXISTING) { set_error(87); RET(87); return; }
    int found, p = save_find(letter, name, &found);
    if (p < 0) { set_error(112); RET(112); return; }
    if (disp == CREATE_NEW && found) { set_error(183); RET(183); return; }
    if (disp == OPEN_EXISTING && !found) { set_error(3); RET(3); return; }
    char game[32], host[sizeof SIM->objs[0].path];
    save_dir_path(letter, save_hash(name), p, game, sizeof game);
    ff_host_path(game, host, sizeof host);
    if (found && disp == CREATE_ALWAYS) save_clear(host);
    if (!found || disp == CREATE_ALWAYS) {
        if (!found) hio_mkdir(host);
        char meta[sizeof host + 16];
        snprintf(meta, sizeof meta, "%s/SaveMeta.xbx", host);
        uint16_t buf[8 + SAVE_NAME_CHARS];
        uint32_t n = 0;
        buf[n++] = 0xfeff;
        for (const char* k = "Name="; *k; k++) buf[n++] = (uint16_t)*k;
        for (uint32_t i = 0; name[i]; i++) buf[n++] = name[i];
        buf[n++] = '\r'; buf[n++] = '\n';
        int32_t f = hio_open(meta, HIO_CREATE);
        if (f < 0) { set_error(3); RET(3); return; }
        hio_write(f, buf, n * 2, 0);
        hio_close(f);
    }
    if (ARG(4)) {
        if (strlen(game) + 2 > ARG(5)) { set_error(87); RET(87); return; }
        snprintf(PTR(ARG(4)), ARG(5), "%s\\", game);
    }
    RET(0);
}
FFG(003563f0) {         /* XDeleteSaveGame(root, name UTF-16) -> error code: the save's files emptied, its name freed */
    UNUSED;
    char letter;
    const uint16_t* name = ARG(1) ? PTR(ARG(1)) : 0;
    if (!save_root(ARG(0), &letter) || !name || !name[0]) { set_error(87); RET(87); return; }
    int found, p = save_find(letter, name, &found);
    if (!found) { set_error(3); RET(3); return; }
    char game[32], host[sizeof SIM->objs[0].path];
    save_dir_path(letter, save_hash(name), p, game, sizeof game);
    ff_host_path(game, host, sizeof host);
    save_clear(host);       /* SaveMeta.xbx emptied: the probe no longer matches the name */
    RET(0);
}
/* XCalculateSignatureBegin/Update/End: HMAC-SHA1 under a key derived from the title, as the SDL layer signs
 * (src/platform/sdl/fs/hulk_saves.cpp sig_key), so a save signs the same on every build. The context lives in the
 * arena (game state); the handle is its address. */
typedef struct { uint32_t h[5]; uint64_t len; uint8_t buf[64]; uint32_t used; } sha1_t;
typedef struct { sha1_t inner; uint8_t opad[64]; } sig_t;
#define ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
static void sha1_block(sha1_t* c, const uint8_t* b) {
    uint32_t w[80], a = c->h[0], bb = c->h[1], cc = c->h[2], d = c->h[3], e = c->h[4];
    for (int i = 0; i < 16; i++) w[i] = (uint32_t)b[4 * i] << 24 | (uint32_t)b[4 * i + 1] << 16 | (uint32_t)b[4 * i + 2] << 8 | b[4 * i + 3];
    for (int i = 16; i < 80; i++) w[i] = ROL(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    for (int i = 0; i < 80; i++) {
        uint32_t f, k;
        if (i < 20) { f = (bb & cc) | (~bb & d); k = 0x5a827999u; }
        else if (i < 40) { f = bb ^ cc ^ d; k = 0x6ed9eba1u; }
        else if (i < 60) { f = (bb & cc) | (bb & d) | (cc & d); k = 0x8f1bbcdcu; }
        else { f = bb ^ cc ^ d; k = 0xca62c1d6u; }
        uint32_t t = ROL(a, 5) + f + e + k + w[i];
        e = d; d = cc; cc = ROL(bb, 30); bb = a; a = t;
    }
    c->h[0] += a; c->h[1] += bb; c->h[2] += cc; c->h[3] += d; c->h[4] += e;
}
static void sha1_init(sha1_t* c) {
    static const uint32_t iv[5] = {0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u, 0xc3d2e1f0u};
    memcpy(c->h, iv, sizeof iv); c->len = 0; c->used = 0;
}
static void sha1_update(sha1_t* c, const void* data, uint32_t n) {
    const uint8_t* p = data;
    c->len += n;
    while (n) {
        uint32_t k = 64 - c->used < n ? 64 - c->used : n;
        memcpy(c->buf + c->used, p, k); c->used += k; p += k; n -= k;
        if (c->used == 64) { sha1_block(c, c->buf); c->used = 0; }
    }
}
static void sha1_final(sha1_t* c, uint8_t out[20]) {
    uint64_t bits = c->len * 8;
    uint8_t pad = 0x80, z = 0, l[8];
    sha1_update(c, &pad, 1);
    while (c->used != 56) sha1_update(c, &z, 1);
    for (int i = 0; i < 8; i++) l[i] = (uint8_t)(bits >> (56 - 8 * i));
    sha1_update(c, l, 8);
    for (int i = 0; i < 20; i++) out[i] = (uint8_t)(c->h[i / 4] >> (24 - 8 * (i % 4)));
}
FFG(002120e1) {         /* XCalculateSignatureBegin(flags) -> handle */
    UNUSED;
    static const char label[] = "Thunderclap/HulkUD save signature v1";
    uint32_t id = 0x56550039u, flags = ARG(0);      /* the title id (hulk_fs.cpp g_title_id) */
    uint8_t w[8], key[20], ipad[64];
    for (int i = 0; i < 4; i++) { w[i] = (uint8_t)(id >> (8 * i)); w[4 + i] = (uint8_t)(flags >> (8 * i)); }
    sha1_t s;
    sha1_init(&s); sha1_update(&s, label, sizeof label - 1); sha1_update(&s, w, 8); sha1_final(&s, key);
    sig_t* g = ff_arena_alloc(sizeof(sig_t), 16);
    if (!g) { set_error(8); RET(INVALID_HANDLE); return; }
    memset(ipad, 0x36, 64); memset(g->opad, 0x5c, 64);
    for (int i = 0; i < 20; i++) { ipad[i] ^= key[i]; g->opad[i] ^= key[i]; }
    sha1_init(&g->inner); sha1_update(&g->inner, ipad, 64);
    RET((uintptr_t)g);
}
FFG(002120f5) {         /* XCalculateSignatureUpdate(handle, data, size) -> error code */
    UNUSED;
    sig_t* g = ARG(0) && ARG(0) != INVALID_HANDLE ? PTR(ARG(0)) : 0;
    if (!g) { RET(6); return; }
    sha1_update(&g->inner, PTR(ARG(1)), ARG(2));
    RET(0);
}
FFG(00212143) {         /* XCalculateSignatureEnd(handle, 20 bytes out) -> error code */
    UNUSED;
    sig_t* g = ARG(0) && ARG(0) != INVALID_HANDLE ? PTR(ARG(0)) : 0;
    if (!g) { RET(6); return; }
    uint8_t in[20], out[20];
    sha1_final(&g->inner, in);
    sha1_t o;
    sha1_init(&o); sha1_update(&o, g->opad, 64); sha1_update(&o, in, 20); sha1_final(&o, out);
    if (ARG(1)) memcpy(PTR(ARG(1)), out, 20);
    ff_arena_free(g);
    RET(0);
}
FFG(003564c0) { UNUSED; set_error(18); RET(INVALID_HANDLE); }  /* XFindFirstSaveGame: none (ERROR_NO_MORE_FILES) */
FFG(003565ca) { UNUSED; set_error(18); RET(0); }                               /* XFindNextSaveGame */
FFG(00356611) { UNUSED; RET(1); }                                               /* XFindClose */
FFG(00355ab5) { UNUSED; RET(INVALID_HANDLE); }                                  /* XFindFirstSoundtrack: none */
FFG(00355791) { UNUSED; RET(0); }                                               /* XFindNextSoundtrack */
