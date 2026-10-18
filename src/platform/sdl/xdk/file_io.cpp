// Stand-ins for file I/O (xdk_shim.h counts and logs each call). XAPI's file functions have the Win32 shapes
// (public documentation); the game's paths are Xbox drive paths, which hulk_crt_host_path (crt_glue.cpp) maps:
// `D:\` (the disc) -> HULK_DATA_DIR (the extracted game files, read-only by convention), `T:\` (title storage) ->
// HULK_TDATA_DIR, `U:\` / `Z:\` -> HULK_SAVE_DIR. On Windows / Wine the host's kernel32 does the rest (handles are
// host handles); an SDL3 backend (SDL_IOStream) replaces this file elsewhere. Native builds only.
#include "imports.h"
#include "../crt/host_crt.h"

static const hulk_u32 hulk_invalid_handle = 0xffffffffu;

// Make every directory of a mapped writable path (T:, U:, Z:), as the Xbox's title storage has them on demand.
static void hulk_make_dirs(char* host) {
    for (char* c = host + 3; *c; c++) {
        if (*c != '\\')
            continue;
        *c = 0;
        hulk_host_CreateDirectoryA(host, 0);
        *c = '\\';
    }
}

static int hulk_writable_drive(const char* p) {
    char d = p[0] | 0x20;
    return (d == 't' || d == 'u' || d == 'z') && p[1] == ':';
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateFileA(hulk_u32 path, hulk_u32 access, hulk_u32 share, hulk_u32 sa,
                                                     hulk_u32 disposition, hulk_u32 flags, hulk_u32 templ) {
    HULK_XDK_TRACE("CreateFileA");
    (void)sa;
    (void)templ;
    const char* p = (const char*)path;
    char buf[520];
    char* host = p ? hulk_crt_host_path(p, buf, sizeof(buf)) : 0;
    if (!host) {
        hulk_host_SetLastError(3);  // ERROR_PATH_NOT_FOUND
        return hulk_invalid_handle;
    }
    if (hulk_writable_drive(p) && (access & 0x40000000u))  // GENERIC_WRITE
        hulk_make_dirs(host);
    // (FILE_FLAG_NO_BUFFERING 0x20000000 would demand sector-aligned reads on the host: dropped; the Xbox's
    // overlapped flag too, since the game waits for each read)
    flags &= ~(0x20000000u | 0x40000000u);
    return (hulk_u32)hulk_host_CreateFileA(host, access, share | 1 /* FILE_SHARE_READ */, 0, disposition, flags, 0);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ReadFile(hulk_u32 h, hulk_u32 buf, hulk_u32 n, hulk_u32 done, hulk_u32 ov) {
    HULK_XDK_TRACE("ReadFile");
    (void)ov;
    hulk_u32 got = 0;
    int ok = hulk_host_ReadFile((void*)h, (void*)buf, n, &got, 0);
    if (done)
        *(hulk_u32*)done = got;
    return (hulk_u32)ok;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_WriteFile(hulk_u32 h, hulk_u32 buf, hulk_u32 n, hulk_u32 done, hulk_u32 ov) {
    HULK_XDK_TRACE("WriteFile");
    (void)ov;
    hulk_u32 put = 0;
    int ok = hulk_host_WriteFile((void*)h, (const void*)buf, n, &put, 0);
    if (done)
        *(hulk_u32*)done = put;
    return (hulk_u32)ok;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetFilePointer(hulk_u32 h, hulk_u32 lo, hulk_u32 hi, hulk_u32 method) {
    HULK_XDK_TRACE("SetFilePointer");
    return hulk_host_SetFilePointer((void*)h, (int)lo, (int*)hi, method);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetFileSize(hulk_u32 h, hulk_u32 hi) {
    HULK_XDK_TRACE("GetFileSize");
    return hulk_host_GetFileSize((void*)h, (hulk_u32*)hi);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetEndOfFile(hulk_u32 h) {
    HULK_XDK_TRACE("SetEndOfFile");
    return (hulk_u32)hulk_host_SetEndOfFile((void*)h);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CloseHandle(hulk_u32 h) {
    HULK_XDK_TRACE("CloseHandle");
    return (hulk_u32)hulk_host_CloseHandle((void*)h);
}

// ULARGE_INTEGER outputs: a fixed 1 GB free / 8 GB total for the writable drives (the Xbox hard disk's partitions
// are about that size), the disc's real numbers don't matter (nothing is written there).
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetDiskFreeSpaceExA(hulk_u32 path, hulk_u32 avail, hulk_u32 total, hulk_u32 free_) {
    HULK_XDK_TRACE("GetDiskFreeSpaceExA");
    (void)path;
    hulk_u32* outs[3] = {(hulk_u32*)avail, (hulk_u32*)total, (hulk_u32*)free_};
    for (int i = 0; i < 3; i++)
        if (outs[i]) {
            outs[i][0] = 0;
            outs[i][1] = i == 1 ? 2 : 0;    // total: 8 GB (0x2_0000_0000)
            if (i != 1)
                outs[i][0] = 0x40000000u;   // free: 1 GB
        }
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDiskSectorSizeA(hulk_u32 path) {
    HULK_XDK_TRACE("XGetDiskSectorSizeA");
    const char* p = (const char*)path;
    return p && (p[0] | 0x20) == 'd' ? 2048 : 512;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XapiOpenDirectory(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XapiOpenDirectory");
    return 0;
}
