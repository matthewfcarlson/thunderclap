// Our own pieces of the native image's C runtime (host_crt.h): what msvcrt.dll doesn't export or what has to know
// about the game (its /GS cookie, its stdio objects, its paths). Native builds only: tools/native_link.py compiles
// this directory and binds the tree's references to these functions and data by XBE address or name
// (host_crt_table.h).
#include "host_crt.h"

extern "C" {

// ---------------------------------------------------------------------------------------------------------------
// /GS: the game's lifted code reads the cookie (XBE 0x004d9968) itself and passes `cookie ^ ebp` back to
// __security_check_cookie (ecx: fastcall, or a thiscall member in one source). Any constant works as long as both
// sides read this one word; a mismatch means the frame's copy was overwritten.
hulk_u32 hulk_crt_security_cookie = 0xbb40e64eu;
int _fltused = 0x9875;  // the symbol clang (MS ABI) references from every TU that uses floating point

void hulk_native_missing(const char* name);
void __fastcall hulk_crt_security_check_cookie(hulk_u32 cookie) {
    if (cookie != hulk_crt_security_cookie)
        hulk_native_missing("__security_check_cookie: stack cookie overwritten");
}

// ---------------------------------------------------------------------------------------------------------------
// atexit: the game's dynamic initializers register their destructors here; they run in reverse when main returns
// (startup.cpp). On the Xbox they never ran (main doesn't return).
typedef void(HULK_HOST_CDECL* hulk_exit_fn)(void);
static hulk_exit_fn hulk_crt_exit_fns_[2048];
static hulk_u32 hulk_crt_exit_n_;

int HULK_HOST_CDECL hulk_crt_atexit(hulk_exit_fn fn) {
    if (hulk_crt_exit_n_ >= sizeof(hulk_crt_exit_fns_) / sizeof(hulk_crt_exit_fns_[0]))
        return -1;
    hulk_crt_exit_fns_[hulk_crt_exit_n_++] = fn;
    return 0;
}

void HULK_HOST_CDECL hulk_crt_run_atexit(void) {
    while (hulk_crt_exit_n_)
        hulk_crt_exit_fns_[--hulk_crt_exit_n_]();
}

// ---------------------------------------------------------------------------------------------------------------
// stdio: the game names the Xbox CRT's stdin / stdout / stderr by address (the `_iob` array at XBE 0x004d99f0,
// 32 bytes per FILE). Those three words are this proxy; the FILE* functions below map it to the host's streams and
// pass every other stream (from fopen) through.
unsigned char hulk_crt_iob_proxy[96];

static hulk_host_file* hulk_stream(void* f) {
    unsigned char* p = (unsigned char*)f;
    if (p >= hulk_crt_iob_proxy && p < hulk_crt_iob_proxy + sizeof(hulk_crt_iob_proxy))
        return (hulk_host_file*)((unsigned char*)hulk_host___iob_func() + (p - hulk_crt_iob_proxy));
    return (hulk_host_file*)f;
}

static int hulk_starts(const char* s, const char* prefix) {
    while (*prefix) {
        char a = *s++, b = *prefix++;
        if (a >= 'A' && a <= 'Z')
            a += 'a' - 'A';
        if (a != b)
            return 0;
    }
    return 1;
}

// `D:\x\y` (the game disc: the extracted game files, HULK_DATA_DIR), `T:\` (title storage: HULK_TDATA_DIR, else
// HULK_SAVE_DIR) and `U:\` / `Z:\` (user / cache storage: HULK_SAVE_DIR) -> host paths; anything else is left alone (0).
char* hulk_crt_host_path(const char* p, char* buf, hulk_u32 size) {
    const char* root = 0;
    const char* rest = 0;
    if (hulk_starts(p, "d:\\") || hulk_starts(p, "d:/")) {
        root = hulk_host_getenv("HULK_DATA_DIR");
        rest = p + 3;
    } else if (hulk_starts(p, "t:\\") && (root = hulk_host_getenv("HULK_TDATA_DIR")) != 0 && *root) {
        rest = p + 3;      // title storage: a writable directory of its own (HULK_TDATA_DIR)
    } else if (hulk_starts(p, "t:\\") || hulk_starts(p, "u:\\") || hulk_starts(p, "z:\\")) {
        root = hulk_host_getenv("HULK_SAVE_DIR");
        rest = p + 3;
    } else if (p[0] == '\\' && !hulk_starts(p, "\\\\")) {
        root = hulk_host_getenv("HULK_DATA_DIR");
        rest = p + 1;
    }
    if (!root || !*root)
        return 0;
    int n = hulk_host__snprintf(buf, size, "%s\\%s", root, rest);
    if (n < 0 || (hulk_u32)n >= size)
        return 0;
    for (char* c = buf; *c; c++)
        if (*c == '/')
            *c = '\\';
    return buf;
}

void* HULK_HOST_CDECL hulk_crt_fopen(const char* path, const char* mode) {
    char buf[520];
    const char* host = hulk_crt_host_path(path, buf, sizeof(buf));
    return hulk_host_fopen(host ? host : path, mode);
}

int HULK_HOST_CDECL hulk_crt_fclose(void* f) {
    hulk_host_file* h = hulk_stream(f);
    return h == (hulk_host_file*)f ? hulk_host_fclose(h) : 0;
}

hulk_u32 HULK_HOST_CDECL hulk_crt_fread(void* p, hulk_u32 size, hulk_u32 n, void* f) {
    return hulk_host_fread(p, size, n, hulk_stream(f));
}

int HULK_HOST_CDECL hulk_crt_getc(void* f) { return hulk_host_getc(hulk_stream(f)); }
int HULK_HOST_CDECL hulk_crt_ungetc(int c, void* f) { return hulk_host_ungetc(c, hulk_stream(f)); }
char* HULK_HOST_CDECL hulk_crt_fgets(char* s, int n, void* f) { return hulk_host_fgets(s, n, hulk_stream(f)); }

int HULK_HOST_CDECL hulk_crt_fprintf(void* f, const char* fmt, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    int r = hulk_host_vfprintf(hulk_stream(f), fmt, (char*)ap);
    __builtin_va_end(ap);
    return r;
}

}  // extern "C"

// ---------------------------------------------------------------------------------------------------------------
// C++ runtime pieces msvcrt.dll doesn't export. (type_info's vftable, which clang's RTTI descriptors and the game's,
// XBE 0x00439de8, point at, is in tools/native_link.py's startup.s: one slot, a deleting destructor that deletes
// nothing, since nothing deletes a type descriptor.)
// The sized delete clang calls (-fsized-deallocation, C++14) is the game's own operator delete: MSVC 7.1 had none.
void operator delete(void* p) noexcept;
void operator delete(void* p, unsigned int) noexcept { ::operator delete(p); }
