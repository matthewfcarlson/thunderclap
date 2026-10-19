// The native file backend (docs/native-files-saves.md): the game's Xbox drives on SDL3's filesystem. Typed and
// platform-neutral (Win32 error codes as the result, 32-bit handles, 64-bit offsets); the XDK-shaped stand-ins in
// src/platform/sdl/xdk/file_io.cpp and saves.cpp translate the game's calls into these.
//
// Drives (the letters the game uses, read off its call sites):
//   D:  the disc: the extracted game files (HULK_DATA_DIR), read-only
//   T:  title storage   <root>/TDATA/<title id>      (HULK_TDATA_DIR)
//   U:  user data       <root>/UDATA/<title id>      (HULK_UDATA_DIR): save games live here
//   Z:  utility/cache   <root>/cache                 (HULK_CACHE_DIR)
//   C: E: F: X: Y:      <root>/<letter>
// <root> is HULK_SAVE_DIR, else SDL_GetPrefPath("Thunderclap", "HulkUD"). A path with a leading backslash or no
// drive is relative to D:. Names are matched case-insensitively against the real directory (ASCII folding), so
// the game's `D:\Art\Foo.P3D` finds `art/foo.p3d` on a case-sensitive filesystem; a name that does not exist is
// created with the case the game gave.
#ifndef HULK_PLATFORM_SDL_FS_H
#define HULK_PLATFORM_SDL_FS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int HulkFsHandle;          // 0 is never valid; the game's INVALID_HANDLE_VALUE is 0xffffffff
typedef unsigned long long HulkU64;

// Win32 error codes the backend returns (the values the game's error translation tables test)
enum {
    HULK_ERR_OK = 0, HULK_ERR_FILE_NOT_FOUND = 2, HULK_ERR_PATH_NOT_FOUND = 3, HULK_ERR_ACCESS_DENIED = 5,
    HULK_ERR_INVALID_HANDLE = 6, HULK_ERR_NOT_ENOUGH_MEMORY = 8, HULK_ERR_NO_MORE_FILES = 18,
    HULK_ERR_SHARING_VIOLATION = 32, HULK_ERR_FILE_EXISTS = 80, HULK_ERR_INVALID_PARAMETER = 87,
    HULK_ERR_DISK_FULL = 112, HULK_ERR_NEGATIVE_SEEK = 131, HULK_ERR_DIR_NOT_EMPTY = 145,
    HULK_ERR_ALREADY_EXISTS = 183, HULK_ERR_DEVICE_NOT_CONNECTED = 1167, HULK_ERR_GEN_FAILURE = 31
};

// CreateFile dispositions / access bits / flags (public Win32 values)
enum { HULK_CREATE_NEW = 1, HULK_CREATE_ALWAYS = 2, HULK_OPEN_EXISTING = 3, HULK_OPEN_ALWAYS = 4,
       HULK_TRUNCATE_EXISTING = 5 };
enum { HULK_GENERIC_READ = 0x80000000u, HULK_GENERIC_WRITE = 0x40000000u, HULK_GENERIC_ALL = 0x10000000u,
       HULK_FILE_WRITE_DATA = 2u, HULK_FILE_APPEND_DATA = 4u };
enum { HULK_FLAG_OVERLAPPED = 0x40000000u };
enum { HULK_ATTR_READONLY = 1, HULK_ATTR_DIRECTORY = 0x10, HULK_ATTR_NORMAL = 0x80 };
enum { HULK_SEEK_BEGIN = 0, HULK_SEEK_CURRENT = 1, HULK_SEEK_END = 2 };

typedef struct HulkFsConfig {
    const char* data_dir;       // D:   (null: HULK_DATA_DIR; unset: D: does not exist)
    const char* root_dir;       // parent of T:/U:/Z:/... (null: HULK_SAVE_DIR, else the SDL pref path)
    const char* tdata_dir;      // T: (null: HULK_TDATA_DIR, else <root>/TDATA/<title id>)
    const char* udata_dir;      // U: (null: HULK_UDATA_DIR, else <root>/UDATA/<title id>)
    const char* cache_dir;      // Z: (null: HULK_CACHE_DIR, else <root>/cache)
    unsigned title_id;          // 0: 0x56550039 (the game's certificate)
    const char* title_name;     // TitleMeta.xbx's name (null: "The Incredible Hulk: Ultimate Destruction")
    long long free_bytes;       // >= 0: GetDiskFreeSpaceEx reports this on the writable drives (tests); -1: real
} HulkFsConfig;

// Optional; without it the first use configures from the environment. Calling it again closes every handle and
// drops the caches (tests use this to point the drives at temporary directories).
void hulk_fs_configure(const HulkFsConfig* cfg);
void hulk_fs_shutdown(void);

// A game path -> the host path it names (separators '/'). Returns 1 and fills `host` when the drive exists
// (whether or not the file does); *exists is 1 when the final component exists. 0: no such drive.
int hulk_fs_map_path(const char* game_path, char* host, unsigned size, int* exists);
char hulk_fs_drive_letter(const char* game_path);        // 'D', 'U', ...; 'D' for a relative path

// Files. Every call returns a Win32 error code (0 = success).
unsigned hulk_fs_open(const char* game_path, unsigned access, unsigned share, unsigned disposition, unsigned flags,
                      HulkFsHandle* out);
int hulk_fs_is_handle(HulkFsHandle h);                    // one of ours (a file, a find or a save find)
unsigned hulk_fs_read(HulkFsHandle h, void* buf, unsigned n, unsigned* got);         // at the file pointer
unsigned hulk_fs_write(HulkFsHandle h, const void* buf, unsigned n, unsigned* put);
unsigned hulk_fs_read_at(HulkFsHandle h, HulkU64 offset, void* buf, unsigned n, unsigned* got);  // overlapped
unsigned hulk_fs_write_at(HulkFsHandle h, HulkU64 offset, const void* buf, unsigned n, unsigned* put);
int hulk_fs_is_overlapped(HulkFsHandle h);
unsigned hulk_fs_seek(HulkFsHandle h, long long offset, unsigned method, HulkU64* new_pos);
unsigned hulk_fs_size(HulkFsHandle h, HulkU64* size);
unsigned hulk_fs_set_end(HulkFsHandle h);                 // truncate / extend at the file pointer
unsigned hulk_fs_close(HulkFsHandle h);                   // files and finds alike (CloseHandle, FindClose)

// Free space of the drive a path names (the disc reports a fixed 1 GB free / 8 GB total) and its sector size
// (2048 for D:, 512 elsewhere).
unsigned hulk_fs_disk_free(const char* game_path, HulkU64* avail, HulkU64* total, HulkU64* free_bytes);
unsigned hulk_fs_sector_size(const char* game_path);

unsigned hulk_fs_create_dir(const char* game_path);       // parents are made; ALREADY_EXISTS if the last exists
unsigned hulk_fs_remove_dir(const char* game_path);       // empty directories only
unsigned hulk_fs_delete_file(const char* game_path);
unsigned hulk_fs_clear_drive(char letter);                // XFormatUtilityDrive: empties Z: (only writable drives)

// Directory enumeration: the last path component may hold * and ? (case-insensitive); "." and ".." are not
// listed; entries come sorted by name.
typedef struct HulkFindEntry {
    unsigned attributes;
    HulkU64 create_time, access_time, write_time;          // FILETIME: 100 ns since 1601
    HulkU64 size;
    char name[260];
} HulkFindEntry;
unsigned hulk_fs_find_first(const char* game_pattern, HulkFindEntry* e, HulkFsHandle* h);
unsigned hulk_fs_find_next(HulkFsHandle h, HulkFindEntry* e);

// Internal (hulk_saves.cpp): handles of other kinds share the table and are closed by hulk_fs_close.
unsigned hulk_fs_handle_new(int kind, void* object, void (*destroy)(void*), HulkFsHandle* out);
void* hulk_fs_handle_get(HulkFsHandle h, int kind);
enum { HULK_KIND_FILE = 1, HULK_KIND_FIND = 2, HULK_KIND_SAVE_FIND = 3, HULK_KIND_SIGNATURE = 4 };

// Helpers shared with hulk_saves.cpp
const char* hulk_fs_title_name(void);
unsigned hulk_fs_title_id(void);
HulkU64 hulk_fs_filetime(long long sdl_ns);               // SDL_Time (ns since 1970) -> FILETIME

#ifdef __cplusplus
}
#endif

#endif
