/* The runners' disc layer (src/platform/wasm/run/disc.c; wpkg1) against a reference folder: every file and folder of
 * FOLDER must be in IMAGE (an .iso or a disc pack) with the same kind, size and bytes, read whole and at random
 * offsets and lengths (chunk edges, the cache), and nothing else may be listed. Takes the player's own files as
 * arguments; holds nothing of the game.
 *   tests/wasm_disc/run.sh FOLDER IMAGE [READS] */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "disc.h"

static int s_bad, s_files;
static unsigned long long s_bytes;
static unsigned s_seed = 12345;
static unsigned rnd(void) { s_seed = s_seed * 1103515245u + 12345u; return s_seed >> 1; }

typedef struct { char names[512][256]; int n; } names;
static void add(void* ud, const char* name) {
    names* l = ud;
    if (l->n < 512) snprintf(l->names[l->n++], 256, "%s", name);
}
static int has(const names* l, const char* n) {
    for (int i = 0; i < l->n; i++)
        if (!strcmp(l->names[i], n)) return 1;
    return 0;
}

static void cmp_file(const char* a, const char* b, int reads) {
    int fa = hdisc_open(a), fb = hdisc_open(b);
    if (fa < 0 || fb < 0) { printf("FAIL open %s (%d) / %s (%d)\n", a, fa, b, fb); s_bad++; return; }
    uint64_t sa = hdisc_size(fa), sb = hdisc_size(fb);
    if (sa != sb) { printf("FAIL size %s %llu vs %llu\n", b, (unsigned long long)sa, (unsigned long long)sb); s_bad++; }
    size_t step = 4 << 20;
    char *x = malloc(step), *y = malloc(step);
    for (uint64_t off = 0; off < sa; off += step) {
        int64_t ra = hdisc_pread(fa, x, step, off), rb = hdisc_pread(fb, y, step, off);
        if (ra != rb || ra < 0 || memcmp(x, y, (size_t)ra)) {
            printf("FAIL bytes %s at %llu\n", b, (unsigned long long)off);
            s_bad++;
            break;
        }
        s_bytes += (uint64_t)ra;
    }
    for (int i = 0; i < reads && sa; i++) {
        uint64_t off = ((uint64_t)rnd() << 16 ^ rnd()) % (sa + 16);
        size_t n = rnd() % 3 == 0 ? rnd() % 64 : rnd() % 2 == 0 ? rnd() % 70000 : rnd() % (3 << 20);
        int64_t ra = hdisc_pread(fa, x, n, off), rb = hdisc_pread(fb, y, n, off);
        if (ra != rb || (ra > 0 && memcmp(x, y, (size_t)ra))) {
            printf("FAIL random read %s at %llu +%zu: %lld vs %lld\n", b, (unsigned long long)off, n, (long long)ra,
                   (long long)rb);
            s_bad++;
            break;
        }
    }
    free(x), free(y);
    hdisc_close(fa), hdisc_close(fb);
    s_files++;
}

static void walk(const char* a, const char* b, int reads, int depth) {
    names* la = calloc(1, sizeof *la);
    names* lb = calloc(1, sizeof *lb);
    hdisc_list(a, add, la);
    hdisc_list(b, add, lb);
    for (int i = 0; i < la->n; i++) {
        if (la->names[i][0] == '.') continue;
        if (!has(lb, la->names[i])) { printf("FAIL %s/%s not listed in the image\n", b, la->names[i]); s_bad++; continue; }
        char pa[1024], pb[1024];
        snprintf(pa, sizeof pa, "%s/%s", a, la->names[i]);
        snprintf(pb, sizeof pb, "%s/%s", b, la->names[i]);
        int ka = hdisc_kind(pa), kb = hdisc_kind(pb);
        if (ka != kb) { printf("FAIL kind %s %d vs %d\n", pb, ka, kb); s_bad++; continue; }
        if (ka == HDISC_DIR && depth < 16) walk(pa, pb, reads, depth + 1);
        else if (ka == HDISC_FILE) cmp_file(pa, pb, reads);
    }
    for (int i = 0; i < lb->n; i++)
        if (!has(la, lb->names[i])) { printf("FAIL %s/%s only in the image\n", b, lb->names[i]); s_bad++; }
    free(la), free(lb);
}

int main(int argc, char** argv) {
    if (argc < 3) { fprintf(stderr, "usage: disc_cmp FOLDER IMAGE [READS]\n"); return 2; }
    int reads = argc > 3 ? atoi(argv[3]) : 200;
    clock_t t = clock();
    printf("%s is %s, %s is %s\n", argv[1], hdisc_source(argv[1]) ? hdisc_source(argv[1]) : "nothing", argv[2],
           hdisc_source(argv[2]) ? hdisc_source(argv[2]) : "nothing");
    if (hdisc_kind(argv[2]) != HDISC_DIR) { printf("FAIL %s is not a disc\n", argv[2]); return 1; }
    char upper[1024];   /* names are case-insensitive in an image */
    snprintf(upper, sizeof upper, "%s/DEFAULT.XBE", argv[2]);
    if (hdisc_kind(upper) != HDISC_FILE) { printf("FAIL %s: not found case-insensitively\n", upper); s_bad++; }
    walk(argv[1], argv[2], reads, 0);
    printf("%s: %d files, %.2f GB compared, %d random reads each, %.1f s CPU\n", s_bad ? "FAIL" : "ok", s_files,
           s_bytes / 1e9, reads, (double)(clock() - t) / CLOCKS_PER_SEC);
    return s_bad ? 1 : 0;
}
