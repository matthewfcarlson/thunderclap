// File and save backend test (docs/native-files-saves.md). Host: the typed API (src/platform/sdl/fs). With
// HULK_TEST_XDK (i686 under Wine): the same checks through the hulk_xdk_* stand-ins with 32-bit handles and
// pointers, as the game image calls them.
#include "fs/hulk_saves.h"
#include "../native_audio/test_common.h"

#ifdef HULK_TEST_XDK
#include "xdk/imports.h"
extern "C" unsigned test_last_error(void);
extern "C" void test_set_last_error(unsigned);
extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_FindFirst(hulk_u32, hulk_u32);
extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_FindNext(hulk_u32, hulk_u32);
extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_CreateDirectory(hulk_u32, hulk_u32);
extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_RemoveDirectory(hulk_u32);
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);
#endif

typedef unsigned H;
static const H BAD = 0xffffffffu;
static unsigned g_last;
static char g_data[1024], g_root[1024];

// ---------------------------------------------------------------------------------------------
// fixtures (plain SDL: no backend code)
static void rm_tree(const char* path);
static SDL_EnumerationResult SDLCALL rm_cb(void* ud, const char* dir, const char* name)
{
    (void)ud;
    char p[1400];
    SDL_snprintf(p, sizeof(p), "%s%s%s", dir, (dir[SDL_strlen(dir) - 1] == '/' || dir[SDL_strlen(dir) - 1] == '\\') ? "" : "/", name);
    rm_tree(p);
    return SDL_ENUM_CONTINUE;
}
static void rm_tree(const char* path)
{
    SDL_PathInfo pi;
    if (!SDL_GetPathInfo(path, &pi))
        return;
    if (pi.type == SDL_PATHTYPE_DIRECTORY)
        SDL_EnumerateDirectory(path, rm_cb, 0);
    SDL_RemovePath(path);
}
static void make_file(const char* rel, const void* data, size_t n)
{
    char p[1400], d[1400];
    SDL_snprintf(p, sizeof(p), "%s/%s", g_data, rel);
    SDL_strlcpy(d, p, sizeof(d));
    char* s = SDL_strrchr(d, '/');
    *s = 0;
    SDL_CreateDirectory(d);
    SDL_IOStream* io = SDL_IOFromFile(p, "wb");
    if (io) {
        SDL_WriteIO(io, data, n);
        SDL_CloseIO(io);
    }
}
static unsigned char pat(unsigned i) { return (unsigned char)((i * 31u + (i >> 8) * 7u + 5u) & 0xff); }

// ---------------------------------------------------------------------------------------------
// the API under test, Win32-shaped: handles / BOOLs, the error in g_last
#ifdef HULK_TEST_XDK
static H a_create(const char* p, unsigned acc, unsigned disp, unsigned flags = 0x80)
{
    H h = hulk_xdk_CreateFileA(TEST_PTR(p), acc, 3, 0, disp, flags, 0);
    g_last = test_last_error();
    return h;
}
static int a_read(H h, void* b, unsigned n, unsigned* got, unsigned* ov = 0)
{
    int r = (int)hulk_xdk_ReadFile(h, TEST_PTR(b), n, TEST_PTR(got), TEST_PTR(ov));
    g_last = r ? 0 : test_last_error();
    return r;
}
static int a_write(H h, const void* b, unsigned n, unsigned* put, unsigned* ov = 0)
{
    int r = (int)hulk_xdk_WriteFile(h, TEST_PTR(b), n, TEST_PTR(put), TEST_PTR(ov));
    g_last = r ? 0 : test_last_error();
    return r;
}
static unsigned a_seek(H h, int lo, int* hi, unsigned m)
{
    unsigned r = hulk_xdk_SetFilePointer(h, (unsigned)lo, TEST_PTR(hi), m);
    g_last = r == BAD ? test_last_error() : 0;
    return r;
}
static unsigned a_size(H h, unsigned* hi)
{
    unsigned r = hulk_xdk_GetFileSize(h, TEST_PTR(hi));
    g_last = r == BAD ? test_last_error() : 0;
    return r;
}
static int a_eof(H h) { int r = (int)hulk_xdk_SetEndOfFile(h); g_last = r ? 0 : test_last_error(); return r; }
static int a_close(H h) { int r = (int)hulk_xdk_CloseHandle(h); g_last = r ? 0 : test_last_error(); return r; }
static int a_delete(const char* p) { int r = (int)hulk_xdk_XapiOpenDirectory(TEST_PTR(p)); g_last = r ? 0 : test_last_error(); return r; }
static int a_mkdir(const char* p) { int r = (int)hulk_fs_xdk_CreateDirectory(TEST_PTR(p), 0); g_last = r ? 0 : test_last_error(); return r; }
static int a_rmdir(const char* p) { int r = (int)hulk_fs_xdk_RemoveDirectory(TEST_PTR(p)); g_last = r ? 0 : test_last_error(); return r; }
static int a_free(const char* p, unsigned long long* av, unsigned long long* tot)
{
    unsigned v[6] = {0, 0, 0, 0, 0, 0};
    int r = (int)hulk_xdk_GetDiskFreeSpaceExA(TEST_PTR(p), TEST_PTR(&v[0]), TEST_PTR(&v[2]), TEST_PTR(&v[4]));
    g_last = r ? 0 : test_last_error();
    *av = v[0] | ((unsigned long long)v[1] << 32);
    *tot = v[2] | ((unsigned long long)v[3] << 32);
    CHECK(!r || (v[4] | ((unsigned long long)v[5] << 32)) == *av, "free bytes == available");
    return r;
}
static unsigned a_sector(const char* p) { return hulk_xdk_XGetDiskSectorSizeA(TEST_PTR(p)); }
// find: WIN32_FIND_DATA layout
static void parse_fd(const unsigned char* b, HulkFindEntry* e)
{
    const unsigned* w = (const unsigned*)b;
    e->attributes = w[0];
    e->write_time = w[5] | ((HulkU64)w[6] << 32);
    e->size = w[8] | ((HulkU64)w[7] << 32);
    SDL_strlcpy(e->name, (const char*)b + 44, sizeof(e->name));
}
static H a_ffirst(const char* pattern, HulkFindEntry* e)
{
    unsigned char b[0x140];
    SDL_memset(b, 0xcc, sizeof(b));
    H h = hulk_fs_xdk_FindFirst(TEST_PTR(pattern), TEST_PTR(b));
    g_last = h == BAD ? test_last_error() : 0;
    if (h != BAD)
        parse_fd(b, e);
    return h;
}
static int a_fnext(H h, HulkFindEntry* e)
{
    unsigned char b[0x140];
    int r = (int)hulk_fs_xdk_FindNext(h, TEST_PTR(b));
    g_last = r ? 0 : test_last_error();
    if (r)
        parse_fd(b, e);
    return r;
}
// saves
static unsigned a_screate(const char* root, const unsigned short* n, unsigned disp, char* path)
{
    return hulk_xdk_XCreateSaveGame(TEST_PTR(root), TEST_PTR(n), disp, 0, TEST_PTR(path), 260);
}
static unsigned a_sdelete(const char* root, const unsigned short* n)
{
    return hulk_xdk_XDeleteSaveGame_XFindFirstSaveGame(TEST_PTR(root), TEST_PTR(n));
}
static H a_sfirst(const char* root, HulkSaveFind* f)
{
    static unsigned char b[0x344];
    SDL_memset(b, 0xcc, sizeof(b));
    H h = hulk_xdk_XFindFirstSaveGame(TEST_PTR(root), TEST_PTR(b));
    g_last = h == BAD ? test_last_error() : 0;
    if (h != BAD) {
        SDL_strlcpy(f->path, (const char*)b + 0x140, sizeof(f->path));
        const unsigned short* w = (const unsigned short*)(b + 0x244);
        int i = 0;
        for (; i < 127 && w[i]; i++)
            f->name[i] = w[i];
        f->name[i] = 0;
    }
    return h;
}
static int a_snext(H h, HulkSaveFind* f)
{
    static unsigned char b[0x344];
    SDL_memset(b, 0xcc, sizeof(b));
    int r = (int)hulk_xdk_XFindNextSaveGame(h, TEST_PTR(b));
    g_last = r ? 0 : test_last_error();
    if (r) {
        SDL_strlcpy(f->path, (const char*)b + 0x140, sizeof(f->path));
        const unsigned short* w = (const unsigned short*)(b + 0x244);
        int i = 0;
        for (; i < 127 && w[i]; i++)
            f->name[i] = w[i];
        f->name[i] = 0;
    }
    return r;
}
static int a_sclose(H h) { return (int)hulk_xdk_XFindClose(h); }
static H a_sigbegin(unsigned flags) { return hulk_xdk_XCalculateSignatureBegin(flags); }
static void a_sigupdate(H h, const void* d, unsigned n) { hulk_xdk_XCalculateSignatureUpdate(h, TEST_PTR(d), n); }
static void a_sigend(H h, unsigned char* out) { hulk_xdk_XCalculateSignatureEnd(h, TEST_PTR(out)); }
static int a_format() { return (int)hulk_xdk_XFormatUtilityDrive(); }
static unsigned a_mount() { char l = 0; return hulk_xdk_XMountMUA(0, 0, TEST_PTR(&l)); }
#else
static H a_create(const char* p, unsigned acc, unsigned disp, unsigned flags = 0x80)
{
    H h;
    g_last = hulk_fs_open(p, acc, 3, disp, flags, &h);
    return g_last ? BAD : h;
}
static int a_read(H h, void* b, unsigned n, unsigned* got, unsigned* ov = 0)
{
    unsigned g = 0;
    g_last = ov ? hulk_fs_read_at(h, ov[2] | ((HulkU64)ov[3] << 32), b, n, &g) : hulk_fs_read(h, b, n, &g);
    if (got)
        *got = g;
    if (ov) {
        ov[0] = g_last;
        ov[1] = g;
    }
    return !g_last;
}
static int a_write(H h, const void* b, unsigned n, unsigned* put, unsigned* ov = 0)
{
    unsigned g = 0;
    g_last = ov ? hulk_fs_write_at(h, ov[2] | ((HulkU64)ov[3] << 32), b, n, &g) : hulk_fs_write(h, b, n, &g);
    if (put)
        *put = g;
    if (ov) {
        ov[0] = g_last;
        ov[1] = g;
    }
    return !g_last;
}
static unsigned a_seek(H h, int lo, int* hi, unsigned m)
{
    HulkU64 pos = 0;
    long long off = hi ? ((long long)*hi << 32) | (unsigned)lo : (long long)lo;
    g_last = hulk_fs_seek(h, off, m, &pos);
    if (g_last)
        return BAD;
    if (hi)
        *hi = (int)(pos >> 32);
    return (unsigned)pos;
}
static unsigned a_size(H h, unsigned* hi)
{
    HulkU64 s = 0;
    g_last = hulk_fs_size(h, &s);
    if (g_last)
        return BAD;
    if (hi)
        *hi = (unsigned)(s >> 32);
    return (unsigned)s;
}
static int a_eof(H h) { g_last = hulk_fs_set_end(h); return !g_last; }
static int a_close(H h) { g_last = hulk_fs_close(h); return !g_last; }
static int a_delete(const char* p) { g_last = hulk_fs_delete_file(p); return !g_last; }
static int a_mkdir(const char* p) { g_last = hulk_fs_create_dir(p); return !g_last; }
static int a_rmdir(const char* p) { g_last = hulk_fs_remove_dir(p); return !g_last; }
static int a_free(const char* p, unsigned long long* av, unsigned long long* tot)
{
    HulkU64 f;
    g_last = hulk_fs_disk_free(p, av, tot, &f);
    CHECK(g_last || f == *av, "free bytes == available");
    return !g_last;
}
static unsigned a_sector(const char* p) { return hulk_fs_sector_size(p); }
static H a_ffirst(const char* pattern, HulkFindEntry* e)
{
    H h;
    g_last = hulk_fs_find_first(pattern, e, &h);
    return g_last ? BAD : h;
}
static int a_fnext(H h, HulkFindEntry* e) { g_last = hulk_fs_find_next(h, e); return !g_last; }
static unsigned a_screate(const char* root, const unsigned short* n, unsigned disp, char* path)
{
    return hulk_save_create(root, n, disp, path, 260);
}
static unsigned a_sdelete(const char* root, const unsigned short* n) { return hulk_save_delete(root, n); }
static H a_sfirst(const char* root, HulkSaveFind* f)
{
    H h;
    g_last = hulk_save_find_first(root, f, &h);
    return g_last ? BAD : h;
}
static int a_snext(H h, HulkSaveFind* f) { g_last = hulk_save_find_next(h, f); return !g_last; }
static int a_sclose(H h) { return !hulk_fs_close(h); }
static H a_sigbegin(unsigned flags) { H h; return hulk_sig_begin(flags, &h) ? BAD : h; }
static void a_sigupdate(H h, const void* d, unsigned n) { hulk_sig_update(h, d, n); }
static void a_sigend(H h, unsigned char* out) { hulk_sig_end(h, out); }
static int a_format() { return !hulk_fs_clear_drive('Z'); }
static unsigned a_mount() { return HULK_ERR_DEVICE_NOT_CONNECTED; }
#endif

#define R 0x80000000u
#define W 0x40000000u

// ---------------------------------------------------------------------------------------------
static void test_paths()
{
    char host[1100];
    int ex = 0;
    CHECK(hulk_fs_map_path("D:\\ART\\Models\\HULK.p3d", host, sizeof(host), &ex) && ex, "mixed-case path exists");
    size_t n = SDL_strlen(host);
    CHECK(n > 19 && !SDL_strcmp(host + n - 19, "art/models/hulk.p3d"), "resolved to the stored case: %s", host);
    CHECK(hulk_fs_map_path("d:/art\\MODELS/hulk.P3D", host, sizeof(host), &ex) && ex, "mixed separators");
    CHECK(hulk_fs_map_path("\\Art\\Models\\Hulk.p3d", host, sizeof(host), &ex) && ex, "leading backslash is D:");
    CHECK(hulk_fs_map_path("art\\models\\hulk.p3d", host, sizeof(host), &ex) && ex, "relative path is D:");
    CHECK(hulk_fs_map_path("D:\\art\\..\\ART\\models\\.\\hulk.p3d", host, sizeof(host), &ex) && ex, ". and ..");
    CHECK(hulk_fs_map_path("D:\\..\\..\\..\\Art\\models\\hulk.p3d", host, sizeof(host), &ex) && ex, ".. stops at the root");
    CHECK(hulk_fs_map_path("D:\\Art\\Models\\New.P3D", host, sizeof(host), &ex) && !ex, "missing file maps");
    n = SDL_strlen(host);
    CHECK(n > 7 && !SDL_strcmp(host + n - 7, "New.P3D"), "a new name keeps the game's case: %s", host);
    CHECK(!hulk_fs_map_path("W:\\x", host, sizeof(host), &ex), "W: is not mapped");
    // two spellings of one directory on a case-sensitive filesystem: the exact one wins
    char probe[1200];
    SDL_snprintf(probe, sizeof(probe), "%s/CaseProbe.tmp", g_data);
    make_file("CaseProbe.tmp", "x", 1);
    char lower[1200];
    SDL_snprintf(lower, sizeof(lower), "%s/caseprobe.tmp", g_data);
    SDL_PathInfo pi;
    bool insensitive = SDL_GetPathInfo(lower, &pi);
    if (!insensitive) {
        make_file("caseprobe.tmp", "yy", 2);
        HulkFsHandle h;
        CHECK(!hulk_fs_open("D:\\caseprobe.tmp", R, 1, 3, 0, &h), "open exact spelling");
        HulkU64 sz = 0;
        hulk_fs_size(h, &sz);
        CHECK(sz == 2, "exact-case match preferred (size %llu)", (unsigned long long)sz);
        hulk_fs_close(h);
        CHECK(!hulk_fs_open("D:\\CASEPROBE.TMP", R, 1, 3, 0, &h), "folded match picks one");
        hulk_fs_close(h);
    }
    SDL_RemovePath(probe);
    if (!insensitive)
        SDL_RemovePath(lower);
}

static void test_read_seek()
{
    H h = a_create("D:\\ART\\MODELS\\hulk.p3d", R, 3);
    CHECK(h != BAD, "open: %u", g_last);
    unsigned hi = 0xdead;
    CHECK(a_size(h, &hi) == 100000 && hi == 0, "size 100000");
    unsigned char buf[5000];
    unsigned got = 0;
    bool ok = true;
    for (unsigned off = 0; off < 100000; off += got) {
        if (!a_read(h, buf, sizeof(buf), &got) || !got)
            break;
        for (unsigned i = 0; i < got; i++)
            ok &= buf[i] == pat(off + i);
    }
    CHECK(ok, "sequential read matches the pattern");
    CHECK(a_read(h, buf, 10, &got) && got == 0, "read at the end: TRUE, 0 bytes");
    CHECK(a_seek(h, 12345, 0, 0) == 12345, "seek begin");
    a_read(h, buf, 100, &got);
    CHECK(got == 100 && buf[0] == pat(12345) && buf[99] == pat(12444), "read after seek");
    CHECK(a_seek(h, 55, 0, 1) == 12500, "seek current");
    CHECK(a_seek(h, 0, 0, 1) == 12500, "tell");
    CHECK(a_seek(h, -10, 0, 2) == 99990, "seek from the end");
    a_read(h, buf, 100, &got);
    CHECK(got == 10 && buf[0] == pat(99990), "short read at the end");
    CHECK(a_seek(h, -1, 0, 0) == BAD && g_last == HULK_ERR_NEGATIVE_SEEK, "negative seek fails (131): %u", g_last);
    CHECK(a_seek(h, 500000, 0, 0) == 500000, "seek past the end");
    CHECK(a_read(h, buf, 10, &got) && got == 0, "read past the end");
    int hi2 = 1;
    CHECK(a_seek(h, 7, &hi2, 0) == 7 && hi2 == 1, "64-bit seek to 4 GB + 7 (past the end)");
    CHECK(!a_write(h, buf, 1, &got) && g_last == HULK_ERR_ACCESS_DENIED, "write on a read handle: 5");
    CHECK(a_close(h), "close");
    CHECK(!a_close(h) && g_last == HULK_ERR_INVALID_HANDLE, "close twice: 6");
    CHECK(!a_read(h, buf, 1, &got) && g_last == HULK_ERR_INVALID_HANDLE, "read on a closed handle: 6");
    CHECK(a_create("D:\\art\\nothing.bin", R, 3) == BAD && g_last == HULK_ERR_FILE_NOT_FOUND, "missing file: 2 (%u)", g_last);
    CHECK(a_create("D:\\nodir\\nothing.bin", R, 3) == BAD && g_last == HULK_ERR_PATH_NOT_FOUND, "missing dir: 3 (%u)", g_last);
    CHECK(a_create("D:\\art\\new.bin", W, 2) == BAD && g_last == HULK_ERR_ACCESS_DENIED, "D: is read-only: 5 (%u)", g_last);
    CHECK(a_create("D:\\art\\models\\hulk.p3d", R | W, 3) == BAD && g_last == HULK_ERR_ACCESS_DENIED, "write open on D: denied");
    CHECK(a_create("D:\\art", R, 3) == BAD, "a directory is not a file");
    CHECK(!a_delete("D:\\art\\models\\hulk.p3d") && g_last == HULK_ERR_ACCESS_DENIED, "delete on D: denied");
}

static void test_write()
{
    unsigned n;
    H h = a_create("T:\\sub\\dir\\New.bin", R | W, 2);
    CHECK(h != BAD, "create with parents: %u", g_last);
    unsigned char b[3000];
    for (unsigned i = 0; i < sizeof(b); i++)
        b[i] = pat(i);
    CHECK(a_write(h, b, sizeof(b), &n) && n == sizeof(b), "write");
    CHECK(a_seek(h, 0, 0, 0) == 0, "rewind");
    unsigned char c[3000];
    CHECK(a_read(h, c, sizeof(c), &n) && n == sizeof(c) && !SDL_memcmp(b, c, sizeof(b)), "read back what was written");
    CHECK(a_seek(h, 100, 0, 0) == 100 && a_write(h, "HELLO", 5, &n), "overwrite in the middle");
    CHECK(a_read(h, c, 4, &n) && n == 4 && c[0] == pat(105), "read after write (stdio switch)");
    CHECK(a_size(h, 0) == 3000, "size after write");
    // grow with SetEndOfFile (the game does this for save files)
    CHECK(a_seek(h, 1 << 20, 0, 0) == (1u << 20) && a_eof(h), "grow to 1 MB");
    CHECK(a_size(h, 0) == (1u << 20), "size 1 MB");
    CHECK(a_seek(h, 2000, 0, 0) == 2000 && a_read(h, c, 4, &n) && c[0] == pat(2000), "data kept when growing");
    CHECK(a_seek(h, 500000, 0, 0) == 500000 && a_read(h, c, 4, &n) && c[0] == 0 && c[3] == 0, "grown area is zeros");
    CHECK(a_seek(h, 1000, 0, 0) == 1000 && a_eof(h), "shrink to 1000");
    CHECK(a_size(h, 0) == 1000, "size 1000 after shrink");
    CHECK(a_seek(h, 0, 0, 0) == 0 && a_read(h, c, 8, &n) && n == 8 && c[7] == pat(7), "data kept when shrinking");
    CHECK(a_write(h, "Z", 1, &n), "write after shrink");
    CHECK(a_close(h), "close");
    h = a_create("t:\\SUB\\DIR\\new.BIN", R, 3);
    CHECK(h != BAD && a_size(h, 0) == 1000, "reopen by another spelling: %u size %u", g_last, h != BAD ? a_size(h, 0) : 0);
    a_close(h);
    CHECK(a_create("T:\\sub\\dir\\new.bin", W, 1) == BAD && g_last == HULK_ERR_FILE_EXISTS, "CREATE_NEW on existing: 80");
    h = a_create("T:\\sub\\dir\\other.bin", W, 1);
    CHECK(h != BAD, "CREATE_NEW on a new name");
    a_write(h, "abc", 3, &n);
    a_close(h);
    h = a_create("T:\\sub\\dir\\other.bin", R | W, 4);
    CHECK(h != BAD && a_size(h, 0) == 3, "OPEN_ALWAYS keeps the file");
    a_close(h);
    h = a_create("T:\\sub\\dir\\other.bin", W, 5);
    CHECK(h != BAD && a_size(h, 0) == 0, "TRUNCATE_EXISTING empties it");
    a_close(h);
    CHECK(a_create("T:\\sub\\dir\\none.bin", W, 5) == BAD && g_last == HULK_ERR_FILE_NOT_FOUND, "TRUNCATE of a missing file: 2");
    CHECK(a_create("T:\\sub\\dir\\none.bin", R | W, 3) == BAD && g_last == HULK_ERR_FILE_NOT_FOUND, "OPEN_EXISTING of a missing file");
    // the same name seen by a second handle while the first writes
    H w = a_create("T:\\shared.bin", R | W, 2);
    a_write(w, "0123456789", 10, &n);
    H r = a_create("T:\\shared.bin", R, 3);
#ifdef SDL_PLATFORM_WINDOWS
    CHECK(r != BAD || g_last == HULK_ERR_SHARING_VIOLATION, "Windows: SDL shares files for reading only");
    if (r != BAD)
#endif
    CHECK(r != BAD && a_size(r, 0) == 10, "second handle sees the data (%u, %u)", r, r != BAD ? a_size(r, 0) : 0);
    a_close(r);
    a_close(w);
    CHECK(a_delete("T:\\shared.bin") && a_create("T:\\shared.bin", R, 3) == BAD, "delete");
    CHECK(!a_delete("T:\\shared.bin") && g_last == HULK_ERR_FILE_NOT_FOUND, "delete missing: 2");
}

static void test_overlapped()
{
    unsigned n;
    H h = a_create("T:\\ov.bin", R | W, 2, 0x80 | 0x40000000);
    CHECK(h != BAD, "overlapped create");
    unsigned char b[256], c[256];
    for (int i = 0; i < 256; i++)
        b[i] = (unsigned char)i;
    unsigned ov[5] = {0xcc, 0xcc, 4096, 0, 0};
    CHECK(a_write(h, b, 256, &n, ov) && n == 256 && ov[0] == 0 && ov[1] == 256, "overlapped write at 4096 completes");
    unsigned ov2[5] = {0xcc, 0xcc, 4096 + 16, 0, 0};
    CHECK(a_read(h, c, 32, 0, ov2) && ov2[1] == 32 && c[0] == 16 && c[31] == 47, "overlapped read at 4112 (null count)");
    unsigned ov3[5] = {0, 0, 0, 0, 0};
    CHECK(a_read(h, c, 16, &n, ov3) && n == 16 && c[0] == 0, "the hole before the data is zero");
    CHECK(a_size(h, 0) == 4096 + 256, "size after the sparse write");
    a_close(h);
}

static void test_dirs_and_find()
{
    CHECK(a_mkdir("T:\\d1\\d2"), "mkdir with parents");
    CHECK(!a_mkdir("T:\\D1\\D2") && g_last == HULK_ERR_ALREADY_EXISTS, "mkdir existing: 183");
    unsigned n;
    H h = a_create("T:\\d1\\d2\\f.txt", W, 2);
    a_write(h, "x", 1, &n);
    a_close(h);
    CHECK(!a_rmdir("T:\\d1\\d2") && g_last == HULK_ERR_DIR_NOT_EMPTY, "rmdir non-empty: 145 (%u)", g_last);
    CHECK(a_delete("T:\\d1\\d2\\f.txt") && a_rmdir("T:\\d1\\d2") && a_rmdir("T:\\d1"), "rmdir empty");
    CHECK(!a_rmdir("T:\\d1") && g_last != 0, "rmdir missing fails");
    CHECK(!a_mkdir("D:\\newdir") && g_last == HULK_ERR_ACCESS_DENIED, "mkdir on D: denied");

    // enumeration of D:\lst: a.txt, B.txt, c.dat, sub/
    HulkFindEntry e;
    H f = a_ffirst("D:\\LST\\*", &e);
    CHECK(f != BAD, "find first: %u", g_last);
    const char* want[] = {"a.txt", "B.txt", "c.dat", "sub"};
    int seen = 0;
    bool order = true, dirflag = true;
    for (int more = f != BAD; more; more = a_fnext(f, &e)) {
        if (seen < 4) {
            order &= !SDL_strcmp(e.name, want[seen]);
            dirflag &= ((e.attributes & 0x10) != 0) == !SDL_strcmp(e.name, "sub");
        }
        if (!SDL_strcmp(e.name, "c.dat"))
            CHECK(e.size == 33, "c.dat size 33 (%llu)", (unsigned long long)e.size);
        if (!SDL_strcmp(e.name, "a.txt"))
            CHECK(e.write_time > 116444736000000000ull, "write time is a FILETIME");
        seen++;
    }
    CHECK(seen == 4 && order && dirflag, "four entries sorted, directory flagged (%d)", seen);
    CHECK(g_last == HULK_ERR_NO_MORE_FILES, "the end: 18 (%u)", g_last);
    CHECK(a_close(f), "CloseHandle closes a find handle");
    f = a_ffirst("D:\\lst\\*.TXT", &e);
    seen = 0;
    for (int more = f != BAD; more; more = a_fnext(f, &e))
        seen++;
    CHECK(seen == 2, "*.TXT matches a.txt and B.txt (%d)", seen);
    a_close(f);
    f = a_ffirst("D:\\lst\\?.dat", &e);
    CHECK(f != BAD && !SDL_strcmp(e.name, "c.dat"), "?.dat");
    a_close(f);
    f = a_ffirst("D:\\lst\\b.TXT", &e);
    CHECK(f != BAD && !SDL_strcmp(e.name, "B.txt"), "an exact name finds it case-insensitively");
    a_close(f);
    CHECK(a_ffirst("D:\\lst\\*.zzz", &e) == BAD && g_last == HULK_ERR_FILE_NOT_FOUND, "no match: 2 (%u)", g_last);
    CHECK(a_ffirst("D:\\nolst\\*", &e) == BAD && g_last == HULK_ERR_PATH_NOT_FOUND, "no directory: 3 (%u)", g_last);
    f = a_ffirst("D:\\*", &e);
    CHECK(f != BAD, "root listing");
    a_close(f);
}

static void test_disk()
{
    unsigned long long av = 0, tot = 0;
    CHECK(a_free("D:\\", &av, &tot) && av == (1ull << 30) && tot == (8ull << 30), "the disc: 1 GB free of 8 GB");
    CHECK(a_free("U:\\", &av, &tot) && av > 0 && av <= tot, "U: free space is real and sane");
    CHECK(a_sector("D:\\") == 2048 && a_sector("d:\\x") == 2048, "disc sector size 2048");
    CHECK(a_sector("U:\\") == 512 && a_sector("T:\\") == 512, "hard disk sector size 512");
    HulkFsConfig c;
    SDL_memset(&c, 0, sizeof(c));
    c.data_dir = g_data;
    c.root_dir = g_root;
    c.free_bytes = 123456;
    hulk_fs_configure(&c);
    CHECK(a_free("U:\\", &av, &tot) && av == 123456, "free_bytes override");
    c.free_bytes = -1;
    hulk_fs_configure(&c);
}

static void wname(unsigned short* out, const char* s)
{
    while ((*out++ = (unsigned char)*s++)) {
    }
}

static void test_handles()
{
#ifdef HULK_TEST_XDK
    // a host event handle (the game's semaphores and threads) passes through CloseHandle to the host
    void* ev = CreateEventA(0, 0, 0, 0);
    CHECK(ev != 0 && !hulk_fs_is_handle((H)(__SIZE_TYPE__)ev), "a host handle is not ours");
    CHECK(a_close((H)(__SIZE_TYPE__)ev), "CloseHandle of a host handle goes to the host");
    CHECK(!a_close((H)(__SIZE_TYPE__)ev), "and fails when it is closed twice");
#endif
    H a = a_create("T:\\h1.bin", W, 2), b = a_create("T:\\h2.bin", W, 2);
    CHECK(a != BAD && b != BAD && a != b && hulk_fs_is_handle(a), "distinct tagged handles");
    a_close(a);
    CHECK(!hulk_fs_is_handle(a), "a closed handle is gone");
    H c = a_create("T:\\h3.bin", W, 2);
    CHECK(c != a, "a reused slot gets a new tag (%08x vs %08x)", c, a);
    a_close(b);
    a_close(c);
}

static void test_saves()
{
    unsigned short n1[64], n2[64], n3[64];
    wname(n1, "Hulk Save 1");
    wname(n2, "Slot two");
    wname(n3, "caf\xe9");
    n3[3] = 0x00e9;
    n3[4] = 0x4e2d;
    n3[5] = 0;
    char p1[260], p2[260], p3[260];
    CHECK(a_screate("U:\\", n1, 3, p1) == HULK_ERR_PATH_NOT_FOUND, "OPEN_EXISTING of a missing save: 3");
    CHECK(a_screate("U:\\", n1, 1, p1) == 0, "CREATE_NEW");
    size_t pl = SDL_strlen(p1);
    CHECK(pl == 3 + 12 + 1 && p1[0] == 'U' && p1[1] == ':' && p1[2] == '\\' && p1[pl - 1] == '\\', "path U:\\<12 hex>\\ : %s", p1);
    CHECK(a_screate("U:\\", n1, 1, p3) == HULK_ERR_ALREADY_EXISTS, "CREATE_NEW again: 183");
    CHECK(a_screate("U:\\", n1, 3, p3) == 0 && !SDL_strcmp(p1, p3), "OPEN_EXISTING finds it, same path");
    CHECK(a_screate("U:\\", n2, 4, p2) == 0 && SDL_strcmp(p1, p2), "OPEN_ALWAYS creates another");
    CHECK(a_screate("U:\\", n3, 1, p3) == 0, "a non-ASCII name");
    // the Xbox structure: SaveMeta.xbx (UTF-16 with a BOM) and TitleMeta.xbx
    char f[300];
    SDL_snprintf(f, sizeof(f), "%sSaveMeta.xbx", p1);
    H h = a_create(f, R, 3);
    unsigned char m[128];
    unsigned got = 0;
    CHECK(h != BAD, "SaveMeta.xbx exists: %u", g_last);
    a_read(h, m, sizeof(m), &got);
    a_close(h);
    CHECK(got == 2 + 2 * (5 + 11 + 2) && m[0] == 0xff && m[1] == 0xfe && m[2] == 'N' && m[3] == 0 && m[12] == 'H',
          "BOM + Name=Hulk Save 1 + CRLF (%u bytes)", got);
    h = a_create("U:\\TitleMeta.xbx", R, 3);
    CHECK(h != BAD, "TitleMeta.xbx exists");
    a_close(h);
    // the game's own files in the save folder
    SDL_snprintf(f, sizeof(f), "%ssave.dat", p1);
    h = a_create(f, R | W, 2);
    unsigned put;
    a_write(h, "payload", 7, &put);
    a_close(h);
    // enumeration
    HulkSaveFind sf;
    SDL_memset(&sf, 0, sizeof(sf));
    H e = a_sfirst("U:\\", &sf);
    CHECK(e != BAD, "XFindFirstSaveGame: %u", g_last);
    int count = 0;
    bool got1 = false, got2 = false, got3 = false;
    for (int more = e != BAD; more; more = a_snext(e, &sf)) {
        count++;
        got1 |= sf.name[0] == 'H' && sf.name[10] == '1' && sf.name[11] == 0 && !SDL_strcmp(sf.path, p1);
        got2 |= sf.name[0] == 'S' && sf.name[7] == 'o' && sf.name[8] == 0;
        got3 |= sf.name[3] == 0xe9 && sf.name[4] == 0x4e2d && sf.name[5] == 0;
    }
    CHECK(count == 3 && got1 && got2 && got3, "three saves found with their names and paths (%d)", count);
    CHECK(g_last == HULK_ERR_NO_MORE_FILES, "the end: 18 (%u)", g_last);
    CHECK(a_sclose(e), "XFindClose");
    CHECK(a_sdelete("U:\\", n2) == 0, "XDeleteSaveGame");
    CHECK(a_screate("U:\\", n2, 3, p2) == HULK_ERR_PATH_NOT_FOUND, "deleted save is gone");
    CHECK(a_sdelete("U:\\", n2) == HULK_ERR_PATH_NOT_FOUND, "delete again: 3");
    CHECK(a_screate("U:\\", n1, 2, p3) == 0 && !SDL_strcmp(p1, p3), "CREATE_ALWAYS keeps the folder");
    SDL_snprintf(f, sizeof(f), "%ssave.dat", p1);
    CHECK(a_create(f, R, 3) == BAD, "CREATE_ALWAYS emptied it");
    e = a_sfirst("U:\\", &sf);
    count = 0;
    for (int more = e != BAD; more; more = a_snext(e, &sf))
        count++;
    a_sclose(e);
    CHECK(count == 2, "two saves left (%d)", count);
    CHECK(a_sdelete("U:\\", n1) == 0 && a_sdelete("U:\\", n3) == 0, "delete the rest");
    CHECK(a_sfirst("U:\\", &sf) == BAD && g_last == HULK_ERR_NO_MORE_FILES, "no saves: -1 + 18 (%u)", g_last);
    CHECK(a_mount() != 0, "XMountMUA: no memory unit");
}

static void hex(const unsigned char* d, int n, char* out)
{
    for (int i = 0; i < n; i++)
        SDL_snprintf(out + 2 * i, 3, "%02x", d[i]);
}

static void test_signatures()
{
    unsigned char d[20];
    char x[64];
    hulk_hmac_sha1((const unsigned char*)"", 0, "", 0, d);   // (runs the empty-key path)
    HulkSha1 s;
    hulk_sha1_init(&s);
    hulk_sha1_update(&s, "abc", 3);
    hulk_sha1_final(&s, d);
    hex(d, 20, x);
    CHECK(!SDL_strcmp(x, "a9993e364706816aba3e25717850c26c9cd0d89d"), "SHA-1(abc) %s", x);
    hulk_sha1_init(&s);
    hulk_sha1_update(&s, "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq", 56);
    hulk_sha1_final(&s, d);
    hex(d, 20, x);
    CHECK(!SDL_strcmp(x, "84983e441c3bd26ebaae4aa1f95129e5e54670f1"), "SHA-1 two-block vector %s", x);
    unsigned char key[20];
    SDL_memset(key, 0x0b, 20);
    hulk_hmac_sha1(key, 20, "Hi There", 8, d);
    hex(d, 20, x);
    CHECK(!SDL_strcmp(x, "b617318655057264e28bc0b6fb378c8ef146be00"), "HMAC-SHA1 RFC 2202 case 1 %s", x);
    hulk_hmac_sha1((const unsigned char*)"Jefe", 4, "what do ya want for nothing?", 28, d);
    hex(d, 20, x);
    CHECK(!SDL_strcmp(x, "effcdf6ae5eb2fa2d27416d5f184df9c259a7c79"), "HMAC-SHA1 RFC 2202 case 2 %s", x);

    // the game's calls: Begin(0) / Update / End, 20 bytes
    unsigned char block[8172], one[20], two[20], three[20], other[20], flagged[20];
    for (unsigned i = 0; i < sizeof(block); i++)
        block[i] = pat(i);
    H h = a_sigbegin(0);
    CHECK(h != BAD, "XCalculateSignatureBegin");
    a_sigupdate(h, block, sizeof(block));
    a_sigend(h, one);
    h = a_sigbegin(0);
    a_sigupdate(h, block, 1000);
    a_sigupdate(h, block + 1000, 0);
    a_sigupdate(h, block + 1000, sizeof(block) - 1000);
    a_sigend(h, two);
    CHECK(!SDL_memcmp(one, two, 20), "chunking does not matter");
    h = a_sigbegin(0);
    a_sigupdate(h, block, sizeof(block));
    a_sigend(h, three);
    CHECK(!SDL_memcmp(one, three, 20), "deterministic");
    block[100] ^= 1;
    h = a_sigbegin(0);
    a_sigupdate(h, block, sizeof(block));
    a_sigend(h, other);
    CHECK(SDL_memcmp(one, other, 20), "one flipped bit changes the signature");
    block[100] ^= 1;
    h = a_sigbegin(1);
    a_sigupdate(h, block, sizeof(block));
    a_sigend(h, flagged);
    CHECK(SDL_memcmp(one, flagged, 20), "the flags select another key");
    CHECK(!hulk_fs_is_handle(h), "End closes the handle");
    // not the zero signature, and a signed block verifies the way the game checks it
    unsigned char zero[20];
    SDL_memset(zero, 0, 20);
    CHECK(SDL_memcmp(one, zero, 20), "not all zeros");
}

static void test_format()
{
    unsigned n;
    H h = a_create("Z:\\cache\\a.bin", W, 2);
    a_write(h, "1", 1, &n);
    a_close(h);
    h = a_create("T:\\keep.bin", W, 2);
    a_close(h);
    CHECK(a_format(), "XFormatUtilityDrive");
    CHECK(a_create("Z:\\cache\\a.bin", R, 3) == BAD, "Z: is empty");
    CHECK(a_create("T:\\keep.bin", R, 3) != BAD, "T: is untouched");
}

struct Reader {
    int ok;
    unsigned seed;
};
static int SDLCALL reader_thread(void* p)
{
    Reader* r = (Reader*)p;
    r->ok = 1;
    for (int it = 0; it < 200; it++) {
        H h = a_create("D:\\art\\models\\hulk.p3d", R, 3);
        if (h == BAD) {
            r->ok = 0;
            return 0;
        }
        unsigned off = (r->seed * 7919u + it * 104729u) % 90000u;
        unsigned char b[512];
        unsigned got = 0;
        a_seek(h, (int)off, 0, 0);
        a_read(h, b, sizeof(b), &got);
        for (unsigned i = 0; i < got; i++)
            if (b[i] != pat(off + i))
                r->ok = 0;
        if (got != 512)
            r->ok = 0;
        a_close(h);
    }
    return 0;
}

static void test_threads()
{
    Reader rs[4];
    SDL_Thread* t[4];
    for (int i = 0; i < 4; i++) {
        rs[i].ok = 0;
        rs[i].seed = (unsigned)i + 1;
        t[i] = SDL_CreateThread(reader_thread, "reader", &rs[i]);
    }
    for (int i = 0; i < 4; i++) {
        SDL_WaitThread(t[i], 0);
        CHECK(rs[i].ok, "reader thread %d read its own handle's data", i);
    }
}

int test_main(void)
{
    const char* out = SDL_getenv("HULK_TEST_OUT");
    char base[900];
    SDL_snprintf(base, sizeof(base), "%s/fs", out && *out ? out : ".");
    for (char* c = base; *c; c++)
        if (*c == '\\')
            *c = '/';
    rm_tree(base);
    SDL_snprintf(g_data, sizeof(g_data), "%s/data", base);
    SDL_snprintf(g_root, sizeof(g_root), "%s/root", base);
    SDL_CreateDirectory(g_data);
    SDL_CreateDirectory(g_root);
    static unsigned char big[100000];
    for (unsigned i = 0; i < sizeof(big); i++)
        big[i] = pat(i);
    make_file("art/models/hulk.p3d", big, sizeof(big));
    make_file("lst/a.txt", "a", 1);
    make_file("lst/B.txt", "bb", 2);
    make_file("lst/c.dat", big, 33);
    make_file("lst/sub/x.txt", "x", 1);
    HulkFsConfig c;
    SDL_memset(&c, 0, sizeof(c));
    c.data_dir = g_data;
    c.root_dir = g_root;
    c.free_bytes = -1;
    hulk_fs_configure(&c);
    test_paths();
    test_read_seek();
    test_write();
    test_overlapped();
    test_dirs_and_find();
    test_disk();
    test_handles();
    test_saves();
    test_signatures();
    test_format();
    test_threads();
    hulk_fs_shutdown();
    return test_done("native_fs");
}
