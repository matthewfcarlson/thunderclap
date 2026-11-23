/* The runners' disc sources: the extracted folder, an Xbox .iso read in place, a disc pack (run/disc.h; wpkg1).
 *
 * An image is mounted the first time a path runs through it (`<image>/default.xbe`, or the image itself asked for as a
 * directory) and stays mounted. Its files get descriptors from HDISC_FD_BASE up; host descriptors pass through.
 *
 * Xbox disc images (XDVDFS, written from the format's public description): the volume descriptor is sector 32 (2 KiB
 * sectors) of the game partition, "MICROSOFT*XBOX*MEDIA" at 0 and at 0x7EC, the root directory table's sector and size
 * at 0x14 / 0x18. A directory table is a binary tree of entries {u16 left, u16 right (4-byte units from the table's
 * start; 0: none), u32 sector, u32 size, u8 attributes (0x10: a directory), u8 name length, name}, 4-aligned; a
 * sector's unused tail is 0xFF. The partition starts at 0 in a trimmed image and at 0x18300000 in a full (Redump) one.
 *
 * Disc packs (tools/disc_pack.py has the format): a header, chunks (each file in fixed-size chunks: zstd frames, stored
 * bytes, or zeros) and a zstd index. A read covering a whole chunk decompresses straight into the caller's buffer;
 * partial reads go through a 16-chunk cache. HULK_DISC_TRACE=1 logs every read of an image's file (name, offset,
 * size) to stderr. */
#include "disc.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <unistd.h>

#include "zstd.h"

#define HDISC_FD_BASE 0x40000000
#define MAX_IMGS 8
#define MAX_HANDLES 512
#define CACHE_SLOTS 16
#define SECTOR 2048ull
#define PACK_HDR 0x40
enum { IMG_ISO = 1, IMG_PACK = 2 };
enum { K_ZSTD = 0, K_RAW = 1, K_ZERO = 2 };

typedef struct {
    char* name;                 /* relative, '/'-separated ("" is the root) */
    uint64_t size, loc;         /* iso: the byte offset in the image; pack: the first chunk */
    int dir, hidden;
} dent;

typedef struct img {
    char* path;
    size_t plen;
    int fd, type;
    uint64_t base;              /* iso: the partition's offset */
    uint32_t chunk, nchunks;    /* pack */
    uint64_t* coff;
    uint32_t* csz;
    uint8_t* ckind;
    dent* ents;
    int nents, cap;
} img;

static pthread_mutex_t s_mu = PTHREAD_MUTEX_INITIALIZER;
static img* s_imgs[MAX_IMGS];
static int s_nimgs;
static struct { img* im; dent* e; } s_h[MAX_HANDLES];
static struct { img* im; uint32_t c; uint8_t* data; uint64_t stamp; } s_cache[CACHE_SLOTS];
static uint64_t s_tick;
static int s_trace = -1;
static char s_not[32][512];     /* host files probed and found not to be images (a ring) */
static int s_nnot;

static void dlog(const char* fmt, const char* a, const char* b) {
    fprintf(stderr, "disc: ");
    fprintf(stderr, fmt, a, b);
    fputc('\n', stderr);
}

static int64_t full_pread(int fd, void* buf, size_t n, uint64_t off) {
    size_t done = 0;
    while (done < n) {
        ssize_t r = pread(fd, (char*)buf + done, n - done, (off_t)(off + done));
        if (r < 0) {
            if (errno == EINTR) continue;
            return done ? (int64_t)done : -1;
        }
        if (r == 0) break;
        done += (size_t)r;
    }
    return (int64_t)done;
}

static uint32_t le32(const uint8_t* p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }
static uint64_t le64(const uint8_t* p) { return le32(p) | (uint64_t)le32(p + 4) << 32; }

/* ------------------------------------------------------------------------------------------- the tree */
static dent* add_ent(img* im, const char* name, uint64_t size, uint64_t loc, int dir) {
    if (im->nents == im->cap) {
        im->cap = im->cap ? im->cap * 2 : 64;
        im->ents = realloc(im->ents, im->cap * sizeof *im->ents);
    }
    dent* e = &im->ents[im->nents++];
    e->name = strdup(name);
    e->size = size, e->loc = loc, e->dir = dir;
    e->hidden = !strncmp(name, ".hulk", 5) && (name[5] == 0 || name[5] == '/');
    return e;
}

static dent* find_ent(img* im, const char* name) {
    for (int i = 0; i < im->nents; i++)
        if (!strcasecmp(im->ents[i].name, name)) return &im->ents[i];
    return 0;
}

/* a pack names files only: their folders are made here */
static void add_parents(img* im, const char* name) {
    char p[1024];
    snprintf(p, sizeof p, "%s", name);
    for (char* s = strrchr(p, '/'); s; s = strrchr(p, '/')) {
        *s = 0;
        if (find_ent(im, p)) break;
        add_ent(im, p, 0, 0, 1);
    }
}

/* ------------------------------------------------------------------------------------------- XDVDFS */
static void iso_walk(img* im, uint64_t sector, uint32_t size, const char* prefix, int depth) {
    if (depth > 32 || !size || size > (64u << 20)) return;
    uint8_t* d = malloc(size);
    if (!d || full_pread(im->fd, d, size, im->base + sector * SECTOR) != (int64_t)size) { free(d); return; }
    /* an explicit stack of entry offsets (in-order: left, self, right) */
    uint32_t stack[256];
    int sp = 0, visits = 0;
    uint32_t o = 0;
    for (;;) {
        while (o != 0xFFFFFFFFu && o + 14 <= size && sp < 256 && visits++ < 65536) {
            uint16_t l = d[o] | d[o + 1] << 8, r = d[o + 2] | d[o + 3] << 8;
            if (l == 0xFFFF && r == 0xFFFF) break;
            stack[sp++] = o;
            o = l ? (uint32_t)l * 4 : 0xFFFFFFFFu;
        }
        if (!sp) break;
        o = stack[--sp];
        uint16_t r = d[o + 2] | d[o + 3] << 8;
        uint32_t sec = le32(d + o + 4), sz = le32(d + o + 8);
        uint8_t attr = d[o + 12], len = d[o + 13];
        if (o + 14 + len <= size) {
            char name[1024];
            snprintf(name, sizeof name, "%s%s%.*s", prefix, *prefix ? "/" : "", (int)len, (const char*)d + o + 14);
            if (attr & 0x10) {
                add_ent(im, name, 0, 0, 1);
                iso_walk(im, sec, sz, name, depth + 1);
            } else {
                add_ent(im, name, sz, im->base + sec * SECTOR, 0);
            }
        }
        o = r ? (uint32_t)r * 4 : 0xFFFFFFFFu;
    }
    free(d);
}

static int iso_mount(img* im) {
    static const uint64_t offs[] = {0, 0x18300000ull};
    uint8_t v[SECTOR];
    for (unsigned i = 0; i < sizeof offs / sizeof offs[0]; i++) {
        if (full_pread(im->fd, v, sizeof v, offs[i] + 32 * SECTOR) != (int64_t)sizeof v) continue;
        if (memcmp(v, "MICROSOFT*XBOX*MEDIA", 20) || memcmp(v + 0x7EC, "MICROSOFT*XBOX*MEDIA", 20)) continue;
        im->type = IMG_ISO;
        im->base = offs[i];
        add_ent(im, "", 0, 0, 1);
        iso_walk(im, le32(v + 0x14), le32(v + 0x18), "", 0);
        return 1;
    }
    return 0;
}

/* ------------------------------------------------------------------------------------------- packs */
static int pack_mount(img* im, const uint8_t* h) {
    uint32_t version = le32(h + 8), chunk = le32(h + 12);
    uint64_t ioff = le64(h + 16);
    uint32_t isz = le32(h + 24), iraw = le32(h + 28), nf = le32(h + 40), nc = le32(h + 44);
    if (version != 1 || !chunk || isz > (256u << 20) || iraw > (256u << 20)) {
        dlog("%s: a disc pack of another version (or damaged)%s", im->path, "");
        return 0;
    }
    uint8_t* z = malloc(isz ? isz : 1);
    uint8_t* ix = malloc(iraw ? iraw : 1);
    int ok = z && ix && full_pread(im->fd, z, isz, ioff) == (int64_t)isz &&
             ZSTD_decompress(ix, iraw, z, isz) == iraw && iraw >= 16 && le32(ix) == nf && le32(ix + 4) == nc;
    free(z);
    if (ok) {
        uint32_t nsz = le32(ix + 8);
        uint64_t fo = 16, co = fo + 24ull * nf, no = co + 16ull * nc;
        ok = no + nsz <= iraw;
        if (ok) {
            im->type = IMG_PACK;
            im->chunk = chunk, im->nchunks = nc;
            im->coff = malloc(nc * sizeof *im->coff);
            im->csz = malloc(nc * sizeof *im->csz);
            im->ckind = malloc(nc ? nc : 1);
            for (uint32_t i = 0; i < nc; i++) {
                const uint8_t* c = ix + co + 16ull * i;
                im->coff[i] = le64(c), im->csz[i] = le32(c + 8), im->ckind[i] = (uint8_t)le32(c + 12);
            }
            add_ent(im, "", 0, 0, 1);
            const char* names = (const char*)ix + no;
            for (uint32_t i = 0; i < nf && ok; i++) {
                const uint8_t* f = ix + fo + 24ull * i;
                uint32_t noff = le32(f), flags = le32(f + 4);
                uint64_t size = le64(f + 8);
                uint32_t first = le32(f + 16);
                if (noff >= nsz || !memchr(names + noff, 0, nsz - noff) ||
                    first + (size + chunk - 1) / chunk > nc) { ok = 0; break; }
                add_parents(im, names + noff);
                if (!(flags & 2)) add_ent(im, names + noff, size, first, 0);
                else if (!find_ent(im, names + noff)) add_ent(im, names + noff, 0, 0, 1);     /* (a folder) */
            }
        }
    }
    free(ix);
    if (!ok) dlog("%s: a damaged disc pack (its index)%s", im->path, "");
    return ok;
}

static __thread ZSTD_DCtx* t_dctx;
static __thread uint8_t* t_zbuf;
static __thread size_t t_zcap;

/* chunk c (raw bytes) into out; 0 when it failed */
static int pack_chunk(img* im, uint32_t c, uint32_t raw, uint8_t* out) {
    if (im->ckind[c] == K_ZERO) { memset(out, 0, raw); return 1; }
    if (im->ckind[c] == K_RAW) return im->csz[c] == raw && full_pread(im->fd, out, raw, im->coff[c]) == raw;
    uint32_t n = im->csz[c];
    if (n > t_zcap) {
        free(t_zbuf);
        t_zcap = n + 65536;
        t_zbuf = malloc(t_zcap);
        if (!t_zbuf) { t_zcap = 0; return 0; }
    }
    if (full_pread(im->fd, t_zbuf, n, im->coff[c]) != n) return 0;
    if (!t_dctx) t_dctx = ZSTD_createDCtx();
    size_t r = ZSTD_decompressDCtx(t_dctx, out, raw, t_zbuf, n);
    if (ZSTD_isError(r) || r != raw) {
        dlog("%s: a damaged chunk (%s)", im->path, ZSTD_isError(r) ? ZSTD_getErrorName(r) : "size");
        return 0;
    }
    return 1;
}

/* bytes [co, co + n) of chunk c through the cache */
static int pack_cached(img* im, uint32_t c, uint32_t raw, uint32_t co, size_t n, uint8_t* out) {
    pthread_mutex_lock(&s_mu);
    for (int i = 0; i < CACHE_SLOTS; i++)
        if (s_cache[i].data && s_cache[i].im == im && s_cache[i].c == c) {
            s_cache[i].stamp = ++s_tick;
            memcpy(out, s_cache[i].data + co, n);
            pthread_mutex_unlock(&s_mu);
            return 1;
        }
    pthread_mutex_unlock(&s_mu);
    uint8_t* d = malloc(raw ? raw : 1);
    if (!d || !pack_chunk(im, c, raw, d)) { free(d); return 0; }
    memcpy(out, d + co, n);
    pthread_mutex_lock(&s_mu);
    int v = 0;
    for (int i = 1; i < CACHE_SLOTS; i++)
        if (s_cache[i].stamp < s_cache[v].stamp) v = i;
    free(s_cache[v].data);
    s_cache[v].im = im, s_cache[v].c = c, s_cache[v].data = d, s_cache[v].stamp = ++s_tick;
    pthread_mutex_unlock(&s_mu);
    return 1;
}

static int64_t pack_read(img* im, const dent* e, uint8_t* buf, size_t n, uint64_t off) {
    size_t done = 0;
    while (done < n) {
        uint64_t pos = off + done;
        uint32_t ci = (uint32_t)(pos / im->chunk), co = (uint32_t)(pos % im->chunk);
        uint64_t left = e->size - (uint64_t)ci * im->chunk;
        uint32_t raw = left < im->chunk ? (uint32_t)left : im->chunk;
        size_t take = n - done < (size_t)(raw - co) ? n - done : (size_t)(raw - co);
        uint32_t c = (uint32_t)e->loc + ci;
        int ok;
        if (im->ckind[c] == K_RAW) ok = full_pread(im->fd, buf + done, take, im->coff[c] + co) == (int64_t)take;
        else if (im->ckind[c] == K_ZERO) memset(buf + done, 0, take), ok = 1;
        else if (!co && take == raw) ok = pack_chunk(im, c, raw, buf + done);
        else ok = pack_cached(im, c, raw, co, take, buf + done);
        if (!ok) return done ? (int64_t)done : -1;
        done += take;
    }
    return (int64_t)done;
}

/* ------------------------------------------------------------------------------------------- mounting */
/* path is a host file (or "fd:N"): mount it if it is an image */
static img* try_mount(const char* path) {
    for (int i = 0; i < s_nnot && i < 32; i++)
        if (!strcmp(s_not[i], path)) return 0;
    int fd;
    if (!strncmp(path, "fd:", 3)) {
        char* end;
        long n = strtol(path + 3, &end, 10);
        fd = *end || n < 0 ? -1 : dup((int)n);
    } else {
        fd = open(path, O_RDONLY);
    }
    if (fd < 0) return 0;
    img* im = calloc(1, sizeof *im);
    im->path = strdup(path);
    im->plen = strlen(path);
    im->fd = fd;
    uint8_t h[PACK_HDR];
    int ok = 0;
    if (full_pread(fd, h, sizeof h, 0) == (int64_t)sizeof h && !memcmp(h, "HULKDISC", 8)) ok = pack_mount(im, h);
    else ok = iso_mount(im);
    if (!ok || s_nimgs >= MAX_IMGS) {
        for (int i = 0; i < im->nents; i++) free(im->ents[i].name);
        free(im->ents), free(im->coff), free(im->csz), free(im->ckind), free(im->path), free(im);
        close(fd);
        snprintf(s_not[s_nnot++ % 32], sizeof s_not[0], "%s", path);
        return 0;
    }
    s_imgs[s_nimgs++] = im;
    if (getenv("HULK_DISC_LOG") || s_trace > 0)
        dlog("%s: %s mounted", path, im->type == IMG_ISO ? (im->base ? "a full Xbox disc image" : "an Xbox disc image")
                                                       : "a disc pack");
    return im;
}

/* the image a path runs through (*inner: the path inside it, "" for its root), or 0: a host path. `self`: the path
 * itself may be an image (a directory's question: kind, list); an open of an existing host file never mounts it */
static img* resolve(const char* path, const char** inner, int self) {
    if (!path || !*path) return 0;
    if (s_trace < 0) s_trace = getenv("HULK_DISC_TRACE") && getenv("HULK_DISC_TRACE")[0] == '1';
    pthread_mutex_lock(&s_mu);
    img* hit = 0;
    for (int i = 0; i < s_nimgs && !hit; i++) {
        img* im = s_imgs[i];
        if (!strncmp(path, im->path, im->plen) && (path[im->plen] == 0 || path[im->plen] == '/')) hit = im;
    }
    if (!hit) {
        /* the longest prefix that exists on the host: an image when it is a file that is one */
        char p[1024];
        snprintf(p, sizeof p, "%s", path);
        size_t n = strlen(p);
        while (n > 0) {
            struct stat st;
            int fdpath = !strncmp(p, "fd:", 3) && !strchr(p, '/');
            if (fdpath || !stat(p, &st)) {
                /* (a regular file under 1 MB is never an image: a save file) */
                int whole = n == strlen(path);
                if (fdpath || ((self || !whole) && S_ISREG(st.st_mode) && st.st_size >= (1 << 20))) hit = try_mount(p);
                break;
            }
            char* s = strrchr(p, '/');
            if (!s || s == p) break;
            *s = 0;
            n = (size_t)(s - p);
        }
    }
    pthread_mutex_unlock(&s_mu);
    if (hit) {
        const char* q = path + hit->plen;
        while (*q == '/') q++;
        *inner = q;
    }
    return hit;
}

/* ------------------------------------------------------------------------------------------- the API */
int hdisc_open(const char* path) {
    const char* in;
    img* im = resolve(path, &in, 0);
    if (!im) return open(path, O_RDONLY);
    dent* e = find_ent(im, in);
    if (!e || e->dir) return -1;
    pthread_mutex_lock(&s_mu);
    int fd = -1;
    for (int i = 0; i < MAX_HANDLES; i++)
        if (!s_h[i].im) {
            s_h[i].im = im, s_h[i].e = e;
            fd = HDISC_FD_BASE + i;
            break;
        }
    pthread_mutex_unlock(&s_mu);
    return fd;
}

int hdisc_in_image(int fd) { return fd >= HDISC_FD_BASE && fd < HDISC_FD_BASE + MAX_HANDLES; }

int64_t hdisc_pread(int fd, void* buf, size_t n, uint64_t off) {
    if (!hdisc_in_image(fd)) return full_pread(fd, buf, n, off);
    img* im = s_h[fd - HDISC_FD_BASE].im;
    const dent* e = s_h[fd - HDISC_FD_BASE].e;
    if (!im) return -1;
    if (off >= e->size) return 0;
    if (n > e->size - off) n = (size_t)(e->size - off);
    if (s_trace > 0) {
        char a[64];
        snprintf(a, sizeof a, "%llu +%zu", (unsigned long long)off, n);
        dlog("read %s %s", e->name, a);
    }
    if (im->type == IMG_ISO) return full_pread(im->fd, buf, n, e->loc + off);
    return pack_read(im, e, buf, n, off);
}

uint64_t hdisc_size(int fd) {
    if (hdisc_in_image(fd)) return s_h[fd - HDISC_FD_BASE].im ? s_h[fd - HDISC_FD_BASE].e->size : 0;
    struct stat st;
    return fstat(fd, &st) ? 0 : (uint64_t)st.st_size;
}

void hdisc_close(int fd) {
    if (!hdisc_in_image(fd)) {
        if (fd >= 0) close(fd);
        return;
    }
    pthread_mutex_lock(&s_mu);
    s_h[fd - HDISC_FD_BASE].im = 0;
    pthread_mutex_unlock(&s_mu);
}

int hdisc_kind(const char* path) {
    const char* in;
    img* im = resolve(path, &in, 1);
    if (!im) {
        struct stat st;
        if (stat(path, &st)) return HDISC_NONE;
        return S_ISREG(st.st_mode) ? HDISC_FILE : S_ISDIR(st.st_mode) ? HDISC_DIR : HDISC_NONE;
    }
    const dent* e = find_ent(im, in);
    return !e ? HDISC_NONE : e->dir ? HDISC_DIR : HDISC_FILE;
}

#include <dirent.h>
int hdisc_list(const char* path, void (*fn)(void* ud, const char* name), void* ud) {
    const char* in;
    img* im = resolve(path, &in, 1);
    int n = 0;
    if (!im) {
        DIR* d = opendir(path);
        if (!d) return -1;
        struct dirent* e;
        while ((e = readdir(d)))
            if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) fn(ud, e->d_name), n++;
        closedir(d);
        return n;
    }
    const dent* dir = find_ent(im, in);
    if (!dir || !dir->dir) return -1;
    size_t len = strlen(dir->name);
    for (int i = 0; i < im->nents; i++) {
        const dent* e = &im->ents[i];
        if (e->hidden || !*e->name) continue;
        const char* rest = e->name;
        if (len) {
            if (strncasecmp(rest, dir->name, len) || rest[len] != '/') continue;
            rest += len + 1;
        }
        if (strchr(rest, '/')) continue;
        fn(ud, rest);
        n++;
    }
    return n;
}

const char* hdisc_source(const char* path) {
    const char* in;
    img* im = resolve(path, &in, 1);
    if (im) return *in ? 0 : im->type == IMG_ISO ? "iso" : "pack";
    struct stat st;
    return !stat(path, &st) && S_ISDIR(st.st_mode) ? "folder" : 0;
}
