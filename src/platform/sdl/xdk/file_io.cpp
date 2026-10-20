// File I/O for the native image. Two builds of the same imports:
//   HULK_NATIVE_SDL (tools/native_fs.py; the native link once build/fs1/for-native9.md is in): the SDL3 file
//   backend (src/platform/sdl/fs/hulk_fs.h, docs/native-files-saves.md). Handles are ours (a tagged index, never a
//   host handle), `D:\` is the extracted game data (read-only), T:/U:/Z: and the other letters live under the
//   user's pref path, names match case-insensitively, errors are the Win32 codes the game's translation tables
//   test (SetLastError). The stand-ins also serve the library code the game reaches by address
//   (hulk_fs_xdk_* below: find-first/next, create/remove directory).
//   Without it: the first stand-ins, host kernel32 functions of the same shape on Windows / Wine.
//
// What the verified callers use (core::XboxDrive, equivalent/0x0026f7b0, 0x0026f990, 0x00279630, ...): CreateFileA
// with FILE_ATTRIBUTE_NORMAL only (no overlapped, no buffering flags), synchronous ReadFile / WriteFile with a null
// OVERLAPPED, SetFilePointer(h, offset, 0, FILE_BEGIN), GetFileSize(h, 0), SetEndOfFile to grow a save file,
// CloseHandle also for thread handles (those go to the host). The OVERLAPPED path is implemented anyway
// (synchronous completion: the offset is honoured, Internal/InternalHigh are filled, hEvent is not signalled).
#if defined(HULK_NATIVE_SDL)
#include "imports.h"
#include "../crt/host_crt.h"
#include "../fs/hulk_fs.h"

static const hulk_u32 hulk_invalid_handle = 0xffffffffu;

// native12: HULK_TRACE_IO=1 logs every open / read / seek ("gfx io ..." trace lines: handle, offset, size, result,
// thread) to line a parser's bytes up with the file they came from
extern "C" void HULK_CDECL hulk_native_log(const char* line);
static int io_trace_on() {
    static int on = -1;
    if (on < 0) {
        const char* v = hulk_host_getenv("HULK_TRACE_IO");
        on = v && *v == '1';
    }
    return on;
}
#define IO_TRACE(...)                                          \
    do {                                                       \
        if (io_trace_on()) {                                   \
            char line_[400];                                   \
            hulk_host__snprintf(line_, sizeof(line_), __VA_ARGS__); \
            hulk_native_log(line_);                            \
        }                                                      \
    } while (0)

template <class T> static T* P(hulk_u32 a) { return (T*)(__SIZE_TYPE__)a; }

static hulk_u32 fail(unsigned err, hulk_u32 value) {
    hulk_host_SetLastError(err);
    return value;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateFileA(hulk_u32 path, hulk_u32 access, hulk_u32 share, hulk_u32 sa,
                                                     hulk_u32 disposition, hulk_u32 flags, hulk_u32 templ) {
    HULK_XDK_TRACE("CreateFileA");
    (void)sa;
    (void)templ;
    if (!path)
        return fail(HULK_ERR_PATH_NOT_FOUND, hulk_invalid_handle);
    HulkFsHandle h;
    unsigned err = hulk_fs_open(P<const char>(path), access, share, disposition, flags, &h);
    IO_TRACE("io open %s -> 0x%x err %u tid %u", P<const char>(path), err ? 0xffffffffu : h, err,
             hulk_host_GetCurrentThreadId());
    return err ? fail(err, hulk_invalid_handle) : h;
}

// An OVERLAPPED is {Internal, InternalHigh, Offset, OffsetHigh, hEvent}: 20 bytes on the Xbox
static int io_with_offset(hulk_u32 ov, HulkU64* offset) {
    if (!ov)
        return 0;
    hulk_u32* o = P<hulk_u32>(ov);
    *offset = (HulkU64)o[2] | ((HulkU64)o[3] << 32);
    return 1;
}

static hulk_u32 io_finish(unsigned err, hulk_u32 done, hulk_u32 ov, unsigned n) {
    if (done)
        *P<hulk_u32>(done) = n;
    if (ov) {
        hulk_u32* o = P<hulk_u32>(ov);
        o[0] = err;     // STATUS_SUCCESS or the failure
        o[1] = n;
    }
    return err ? fail(err, 0) : 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ReadFile(hulk_u32 h, hulk_u32 buf, hulk_u32 n, hulk_u32 done, hulk_u32 ov) {
    HULK_XDK_TRACE("ReadFile");
    unsigned got = 0;
    HulkU64 off;
    int at = io_with_offset(ov, &off);
    HulkU64 pos = 0;
    if (!at && io_trace_on())
        hulk_fs_seek(h, 0, 1 /* FILE_CURRENT */, &pos);
    unsigned err = at ? hulk_fs_read_at(h, off, P<void>(buf), n, &got) : hulk_fs_read(h, P<void>(buf), n, &got);
    IO_TRACE("io read 0x%x at 0x%x%s n 0x%x got 0x%x err %u buf 0x%08x first %08x tid %u", h,
             (unsigned)(at ? off : pos), at ? " (ov)" : "", n, got, err, buf, got >= 4 ? *P<hulk_u32>(buf) : 0,
             hulk_host_GetCurrentThreadId());
    return io_finish(err, done, ov, got);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_WriteFile(hulk_u32 h, hulk_u32 buf, hulk_u32 n, hulk_u32 done, hulk_u32 ov) {
    HULK_XDK_TRACE("WriteFile");
    unsigned put = 0;
    HulkU64 off;
    unsigned err = io_with_offset(ov, &off) ? hulk_fs_write_at(h, off, P<const void>(buf), n, &put)
                                            : hulk_fs_write(h, P<const void>(buf), n, &put);
    return io_finish(err, done, ov, put);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetFilePointer(hulk_u32 h, hulk_u32 lo, hulk_u32 hi, hulk_u32 method) {
    HULK_XDK_TRACE("SetFilePointer");
    long long off = hi ? (((long long)*P<int>(hi)) << 32) | lo : (long long)(int)lo;
    HulkU64 pos = 0;
    unsigned err = hulk_fs_seek(h, off, method, &pos);
    IO_TRACE("io seek 0x%x off 0x%x method %u -> 0x%x err %u", h, (unsigned)off, method, (unsigned)pos, err);
    if (err)
        return fail(err, 0xffffffffu);
    if (hi)
        *P<hulk_u32>(hi) = (hulk_u32)(pos >> 32);
    return (hulk_u32)pos;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetFileSize(hulk_u32 h, hulk_u32 hi) {
    HULK_XDK_TRACE("GetFileSize");
    HulkU64 size = 0;
    unsigned err = hulk_fs_size(h, &size);
    if (err)
        return fail(err, 0xffffffffu);
    if (hi)
        *P<hulk_u32>(hi) = (hulk_u32)(size >> 32);
    return (hulk_u32)size;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetEndOfFile(hulk_u32 h) {
    HULK_XDK_TRACE("SetEndOfFile");
    unsigned err = hulk_fs_set_end(h);
    return err ? fail(err, 0) : 1;
}

// CloseHandle is also what the game calls on its thread, semaphore and event handles: those are the host's.
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CloseHandle(hulk_u32 h) {
    HULK_XDK_TRACE("CloseHandle");
    if (hulk_fs_is_handle(h)) {
        unsigned err = hulk_fs_close(h);
        return err ? fail(err, 0) : 1;
    }
    return (hulk_u32)hulk_host_CloseHandle((void*)(__SIZE_TYPE__)h);
}

// ULARGE_INTEGER outputs
static void put64(hulk_u32 p, HulkU64 v) {
    if (p) {
        P<hulk_u32>(p)[0] = (hulk_u32)v;
        P<hulk_u32>(p)[1] = (hulk_u32)(v >> 32);
    }
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetDiskFreeSpaceExA(hulk_u32 path, hulk_u32 avail, hulk_u32 total, hulk_u32 free_) {
    HULK_XDK_TRACE("GetDiskFreeSpaceExA");
    HulkU64 a = 0, t = 0, f = 0;
    unsigned err = hulk_fs_disk_free(path ? P<const char>(path) : "D:\\", &a, &t, &f);
    if (err)
        return fail(err, 0);
    put64(avail, a);
    put64(total, t);
    put64(free_, f);
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDiskSectorSizeA(hulk_u32 path) {
    HULK_XDK_TRACE("XGetDiskSectorSizeA");
    return hulk_fs_sector_size(path ? P<const char>(path) : "D:\\");
}

// 0x0021257d: the drive's file-destroy call (core::XboxDrive::vfunc_17 -> DriveFileDestroyRequest): path -> BOOL.
// (the import table's name for it, XapiOpenDirectory, predates reading its call site)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XapiOpenDirectory(hulk_u32 path) {
    HULK_XDK_TRACE("XapiOpenDirectory");
    if (!path)
        return fail(HULK_ERR_PATH_NOT_FOUND, 0);
    unsigned err = hulk_fs_delete_file(P<const char>(path));
    return err ? fail(err, 0) : 1;
}

// ---------------------------------------------------------------------------------------------------------------
// The drive's directory calls: library code the game reaches by address (src/platform/sdl/xdk/library.h and
// audio_soundtracks.cpp name them historically). Their stand-ins forward here (build/fs1/for-native9.md):
//   0x00355ab5 hulk_fs_xdk_FindFirst(path with a pattern, WIN32_FIND_DATA*) -> HANDLE, -1 + GetLastError (2 / 3)
//   0x00355bc2 hulk_fs_xdk_FindNext(handle, WIN32_FIND_DATA*) -> BOOL, 0 + GetLastError 18 at the end
//   0x00355c13 hulk_fs_xdk_CreateDirectory(path, 0) -> BOOL (core::XboxDrive::vfunc_15)
//   0x00355c7f hulk_fs_xdk_RemoveDirectory(path) -> BOOL (vfunc_16)
// A find handle is closed with CloseHandle (0x0020bbc2: the game's vfunc_20 and the next FindFirst do).
// WIN32_FIND_DATA (0x140 bytes): attributes +0, creation / access / write FILETIMEs +4 / +12 / +20, size high / low
// +28 / +32, name +44 (260 bytes).
static void fill_find_data(hulk_u32 data, const HulkFindEntry& e) {
    hulk_u32* w = P<hulk_u32>(data);
    for (int i = 0; i < 0x140 / 4; i++)
        w[i] = 0;
    w[0] = e.attributes;
    HulkU64 t[3] = {e.create_time, e.access_time, e.write_time};
    for (int i = 0; i < 3; i++) {
        w[1 + i * 2] = (hulk_u32)t[i];
        w[2 + i * 2] = (hulk_u32)(t[i] >> 32);
    }
    w[7] = (hulk_u32)(e.size >> 32);
    w[8] = (hulk_u32)e.size;
    char* name = P<char>(data) + 44;
    int i = 0;
    for (; i < 259 && e.name[i]; i++)
        name[i] = e.name[i];
    name[i] = 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_FindFirst(hulk_u32 path, hulk_u32 data) {
    HULK_XDK_TRACE("fs:FindFirst");
    HulkFindEntry e;
    HulkFsHandle h;
    unsigned err = path ? hulk_fs_find_first(P<const char>(path), &e, &h) : HULK_ERR_PATH_NOT_FOUND;
    if (err)
        return fail(err, hulk_invalid_handle);
    if (data)
        fill_find_data(data, e);
    return h;
}

extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_FindNext(hulk_u32 handle, hulk_u32 data) {
    HULK_XDK_TRACE("fs:FindNext");
    HulkFindEntry e;
    unsigned err = hulk_fs_find_next(handle, &e);
    if (err)
        return fail(err, 0);
    if (data)
        fill_find_data(data, e);
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_CreateDirectory(hulk_u32 path, hulk_u32 security) {
    HULK_XDK_TRACE("fs:CreateDirectory");
    (void)security;
    unsigned err = path ? hulk_fs_create_dir(P<const char>(path)) : HULK_ERR_PATH_NOT_FOUND;
    return err ? fail(err, 0) : 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_RemoveDirectory(hulk_u32 path) {
    HULK_XDK_TRACE("fs:RemoveDirectory");
    unsigned err = path ? hulk_fs_remove_dir(P<const char>(path)) : HULK_ERR_PATH_NOT_FOUND;
    return err ? fail(err, 0) : 1;
}

#else  // !HULK_NATIVE_SDL

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

#endif  // HULK_NATIVE_SDL
